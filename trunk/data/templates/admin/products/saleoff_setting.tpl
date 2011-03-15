<form method="post">
<div class="content" style="width: 650px;margin:0 auto;">
  <div class="header1">Khuyến mãi sản phẩm</div>
    <div class="blu-container" style="padding: 10px;text-align: center">
      {if $errors_count > 0}
      {foreach from=$errors item=error}
      <div class="w100p error_field t-left">&nbsp;&nbsp;<img height="10" border="0" width="10" title=" Lỗi " alt="Lỗi" src="/images/icons/error.gif">&nbsp;{$error}</div>
      {/foreach}
      <br />
      {/if}
      <table cellpadding="0" cellspacing="0" width="100%" class="vlist">
        <tr>
          <th align="right" style="padding-right: 5px">Sản Phẩm</th>
          <td align="left" style="padding-left: 5px">{$product.products_name}</td>
        </tr>
        <tr>
          <th align="right" style="padding-right: 5px">Danh Mục</th>
          <td align="left" style="padding-left: 5px">{$product.categories_name}</td>
        </tr>
        <tr>
          <th align="right" style="padding-right: 5px">Giá Gốc</th>
          <td align="left" style="padding-left: 5px">Not available</td>
        </tr>
        <tr>
          <th align="right" style="padding-right: 5px">Giá Niêm Yết</th>
          <td align="left" style="padding-left: 5px">{number_format number=$product.products_price}&nbsp;VND</td>
        </tr>
        <tr>
          <th align="right" style="padding-right: 5px">Khuyến mãi</th>
          <td align="left" style="padding-left: 5px"><input type="checkbox" id="chkSaleoff" name="chkSaleoff"{if $product.specials_id != '' && $product.status == '1'} checked="checked"{/if} onclick="SetVisibility(this.checked)"></td>
        </tr>
        <tr>
          <th align="right" style="padding-right: 5px">Giá Khuyến Mãi</th>
          <td align="left" style="padding-left: 5px"><input type="text" class="t-right" id="txtSaleoffPrice" name="txtSaleoffPrice" value="{if $smarty.post != null}{$smarty.post.txtSaleoffPrice}{else}{$product.specials_new_products_price|string_format:"%d"}{/if}">&nbsp;VND</td>
        </tr>
      </table><br />
      <input type="submit" class="w80" value="Lưu thay đổi">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
      <input type="button" value="Đóng" onclick="window.close();">
    </div>
  </div>
</div>
</form>
<script type="text/javascript" language="javascript">
{if $update_saleoff_ok==1}
window.opener.reloadProductList({$product.categories_id});
alert('Đã lưu thay đổi');
// window.close();
{/if}
{literal}
function SetVisibility(checked){
  var txt = document.getElementById('txtSaleoffPrice');
  if(txt != null){
    txt.readOnly = !checked;
    if(!checked){
      txt.style.backgroundColor = '#cccccc';
    } else {
      txt.style.backgroundColor = 'white';
    }
  }
}
{/literal}
</script>