<script languge="javascript">
{literal}
$(document).ready(function() {
  $("#tree").dynatree({
      onActivate: function(dtnode) {
        update_sub_categories_tree(dtnode.data.key);
      }
  });
  $("#tree").dynatree("getRoot").childList[0].focus();
  update_sub_categories_tree($("#tree").dynatree("getRoot").childList[0].data.key);
});
{/literal}
</script>
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
  else url = '/admin/products/add/' + '0';

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