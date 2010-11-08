<script languge="javascript">
{literal}
$(document).ready(function() {
  $("#tree").dynatree({
      onActivate: function(dtnode) {
        update_sub_categories_tree(dtnode.data.key);
      },
      onLazyRead: function(dtnode){
        alert(dtnode.data.key);
      },
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
          <div align="right"><input type="Button" value="Thêm sản phẩm"></div>
        </div>
        <div class="blu-container" style="padding: 10px;height:450px;overflow:auto;">
          <div id="sub_cat_con"></div>
        </div>
      </div>
      <div style="clear: both">&nbsp;</div>
    </div>
  </div>
</div>