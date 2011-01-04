{if $product.products_id != ''}
<table width="100%" cellpadding="0" cellspacing="0" border="0">
  <tr><td colspan="2"><table width="100%" cellpadding="0" cellspacing="0" border="0"><tr>
    <td class="t-left v-bottom"><span class="f14">{$product.products_name}</span></td>
    <td class="t-right v-bottom">{if $product.special_price != ''}<s class="f14">{number_format number=$product.products_price}</s>&nbsp;<span class="fore-red f14">{number_format number=$product.special_price}&nbsp;VND</span>{else}<span class="f14 fore-red">{number_format number=$product.products_price}&nbsp;VND</span>{/if}</td>
  </tr></table></td></tr>
  <tr>
    <td class="v-top" style="padding-top: 20px;" width="80%">{$product.products_description}&nbsp;</td>
    <td class="v-top t-center" style="padding-top: 20px;">{ImageThumb src=$product.products_image width=auto height=$SMALL_IMAGE_HEIGHT alt=$product.products_name options="float: left"}<br /><br /><a href="/sanpham/{$product.products_id}/order">{ImageButton image="button_buy_now.png" alt="Đặt hàng"}</a><br /><br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a class="f10" style="text-decoration: underline;" href="javascript:history.back();">Trở lại</a></td>
  </tr>
</table>
{else}
<p class="f20 fb">Không tìm thấy sản phẩm !</p>
<p><img src="/product_thumb.php?f=t58677.jpg&h=80&w=auto"></p><br><br><br><br><br><br>
<div class="container t-right"><p><a href="/"><img border="0" width="110" title=" Quay lại " alt="Quay lại" src="/images/languages/vietnam/buttons/button_back.gif"></a></p></div>
{/if}
<br /><br />
<span class="bigtitle">Sản phẩm cùng danh mục</span>
<div id="makeMeScrollable">
  <div class="scrollingHotSpotLeft"></div>
  <div class="scrollingHotSpotRight"></div>
  <div class="scrollWrapper">
    <div class="scrollableArea">
      {foreach from=$OtherProductsList item=other}
      <a href="/sanpham/{$other.products_id}/chitiet" title="{$other.products_name} {number_format number=$other.products_price}VND"><img src="/product_thumb.php?f={$other.products_image}&w=auto&h=120&ma=150&cx=150&cy=150" width="150" height="150" border="0"></a>
      {/foreach}
    </div>
  </div>
</div>
