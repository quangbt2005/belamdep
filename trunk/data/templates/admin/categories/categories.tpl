{literal}
<script type="text/javascript" languge="javascript">
function _bindDragDrop(){
  // Enable document and folder nodes as drag source
  $("#tree span.ui-dynatree-document, span.ui-dynatree-folder").draggable({
      delay: 0,
      distance: 4,
      helper: 'clone',
      opacity: 0.5,
      addClasses: false,
      appendTo: 'body',
      //cursor: 'crosshair',
      revert: 'invalid',
      revertDuration: 400,
      start: function(event, ui) {
        //logMsg("draggable.start, %o, %o", event, ui);
      },
      drag: function(event, ui) {
        //logMsg("draggable.drag, %o, %o", event, ui);
      },
      stop: function(event, ui) {
        //logMsg("draggable.stop, %o, %o", event, ui);
      },
      _last: null
  });
  // Enable document and folder nodes as drop target
  $("#tree span.ui-dynatree-document, span.ui-dynatree-folder").droppable({
      accept: '.ui-dynatree-document, .ui-dynatree-folder',
      addClasses: false,
      //activeClass: '.ui-state-highlight',
      hoverClass: 'drophover',
      tolerance: 'intersect',
      activate: function(event, ui) {
        //logMsg("droppable.activate, %o, %o", event, ui);
      },
      deactivate: function(event, ui) {
        //logMsg("droppable.deactivate, %o, %o", event, ui);
      },
      over: function(event, ui) {
        //logMsg("droppable.over, %o, %o", event, ui);
      },
      out: function(event, ui) {
        //logMsg("droppable.out, %o, %o", event, ui);
      },
      drop: function(event, ui) {
        var srcnode = ui.draggable[0].dtnode;
        var destnode = event.target.dtnode;
        //logMsg("droppable.drop, %o, %o", event, ui);
        //logMsg("drop source: %o", srcnode);
        //logMsg("drop target: %o", destnode);
        var copynode = srcnode.toDict(true, function(dict){
          // dict.title = "Copy of " + dict.title;
          // delete dict.key; // Remove key, so a new one will be created
          // srcnode.remove();
        });
        destnode.addChild(copynode);
        var url = "/admin/categories/" + srcnode.data.key + "/move/" + destnode.data.key;
        $.get(url, function(data){});
        srcnode.remove();
        // Must re-binnd, so new nodes become draggable too
        _bindDragDrop();
      },
      _last: null
  });
}

$(document).ready(function() {
  $("#tree").dynatree({
      title: "Categories",
      rootVisible: true,
      onActivate: function(dtnode) {
        update_sub_categories_tree(dtnode.data.key);
      }
  });
  _bindDragDrop();
  $("#tree").dynatree("getRoot").childList[0].focus();
  update_sub_categories_tree($("#tree").dynatree("getRoot").childList[0].data.key);
});
</script>
<style type="text/css">
  .drophover{ border: 1px solid blue; }
</style>
{/literal}
<div id="bigBox">
  <div class="box">
    <div class="left"></div>
    <div class="right"></div>
    <div class="heading">
      <h1 class="bkg_dashboard">Categories</h1>
    </div>
    <div class="content">
      <div style="float: left;width: 30%;border: 0px solid #cccccc">
        <!-- <h1>Categories</h1> -->
        <div align="left">
          <input type="button" value="Thêm danh mục" onclick="">&nbsp;&nbsp;
          <input type="button" value="Sửa danh mục" onclick="">&nbsp;&nbsp;
          <input type="button" value="Xóa danh mục" onclick="">
        </div>
        <div id="tree" style="overflow: auto;float: left;">
          {$Tree}
        </div>
      </div>
      <!-- <div style="float: left;margin-left: 1%;width: 69%;margin-top:-50px;"> -->
      <div style="float: left;margin-left: 1%;width: 69%;">
        <div class="header1">
          <div style="float: left">Danh sách sản phẩm</div>
          <div align="right"><input type="Button" value="Thêm sản phẩm" onclick="openAddProductPopup();"></div>
        </div>
        <div class="blu-container" style="padding: 10px;height:450px;overflow:auto;">
          <div id="sub_cat_con"></div>
        </div>
      </div>
      <div style="clear: both">&nbsp;</div>
    </div>
  </div>
</div>{literal}
<script type="text/javascript" language="javascript">
function openAddProductPopup(){
  var url = '/admin/products/add/';
  if($("#tree").dynatree("getActiveNode") != null){
    var dtnode_id = $("#tree").dynatree("getActiveNode").data.key;
    url = url + dtnode_id;
  }
  else url = '/admin/products/add/' + $("#tree").dynatree("getRoot").childList[0].data.key;

  var topPos = 150;
  var leftPos = 310;

  var popup = window.open(url, 'Thêm sản phẩm mới',"resizable=no,menubar=no,toolbar=no,location=no,width=620,height=450,left="+leftPos+",top="+topPos);
}
function reloadProductList(category_id)
{
  if($("#tree").dynatree("getActiveNode") != null){
    var dtnode_id = $("#tree").dynatree("getActiveNode").data.key;
    if(category_id == dtnode_id){
      update_sub_categories_tree(dtnode_id);
    }
  }
}
function addCategory(){
}
function deleteCategory(){
}
function editCategory(){
}
</script>{/literal}