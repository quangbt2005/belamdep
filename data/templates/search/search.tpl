<table border="0" cellpadding="0" cellspacing="0" width="100%" style="padding: 10 0 10 0">
<tr><td><span class="bigtitle">Tìm kiếm</span></td><td align="right"><img width="57" height="40" border="0" title=" Tìm kiếm " alt="Tìm kiếm" src="/images/table_background_browse.gif"></td></tr>
</table>
{if $error_count > 0}
{foreach from=$errs item=error}
<div class="w100p error_field t-left">&nbsp;&nbsp;<img height="10" border="0" width="10" title=" Lỗi " alt="Lỗi" src="/images/icons/error.gif">&nbsp;{$error}</div>
{/foreach}
<br>
{/if}
<form action="/timkiem" class="floatLeft w100p" method="post">
<table border="0" cellpadding="0" cellspacing="0" width="510" style="padding: 0" align="center">
  <tr>
    <td rowspan="2"><img src="/images/con_lua.jpg"></td>
    <td colspan="2" align="center" class="f10">Hãy nhập từ bất kỳ liên quan đến sản phẩm bạn cần tìm</td>
  </tr>
  <tr>
    <td align="center" valign="middle">
      <input name="txtKey" class="w300" value="{if $smarty.post.txtKey != ''}{$smarty.post.txtKey|escape}{else}{$txtKey}{/if}">&nbsp;
    </td>
    <td align="center" valign="middle">
      <input type="image" src="{$IMAGES_LANG_PATH}{$LANGUAGE}/buttons/button_search.gif">
    </td>
  </tr>
</table></form>

  {if $total_products > 0}
  <div class="wrapper" style="width: 547px; margin-left: 1px;">
  {TitleBox title="Kết quả tìm kiếm"}
    {foreach from=$Product_List item=product}
    <div class="product">
  {if $product.empty != 'true'}
  <div style="height: 155px;padding: 5px">
    <a href="/sanpham/{$product.products_id}/chitiet">{ImageThumb src=$product.products_image width=auto height=$SMALL_IMAGE_HEIGHT alt=$product.products_name}<br>
    <a href="/sanpham/{$product.products_id}/chitiet">{$product.products_name}</a><br>
  </div>
  {if $product.special_price != ''}<s>{number_format number=$product.products_price}</s>&nbsp;<span class="fore-red">{number_format number=$product.special_price}{else}{number_format number=$product.products_price}{/if}&nbsp;VND</span><br>
  <a href="/sanpham/{$product.products_id}/order">{ImageButton image="button_buy_now.png" alt="Đặt hàng"}</a>
  {/if}
</div>
    {/foreach}
  </div>
  <div class="clear"></div>
  {$pager}<div class="clear"></div>
  <div class="t-right" style="width: 547px;"><span class="f10">Hiển thị {$product_count} sản phẩm từ {$product_from} đến {$product_to} trong tổng số {$total_products} sản phẩm</span></div>
  {elseif $error_count < 0}
  <h1>Không tìm thấy sản phẩm nào</h1>
  {/if}