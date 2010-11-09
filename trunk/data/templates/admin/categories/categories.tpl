<script languge="javascript">
{literal}
$(document).ready(function() {
  $("#tree").dynatree({
      onActivate: function(dtnode) {
        update_sub_categories_tree(dtnode.data.key);
      }
    });
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
      <h1>Categories</h1>
      <div id="tree" style="width: 30%;overflow: auto;float: left;">
        {$Tree}
      </div>
      <div style="float: left;margin-left: 1%;width: 69%;margin-top:-50px;">
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
</script>{/literal}