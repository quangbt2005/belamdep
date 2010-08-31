{TitleBox title='Khuyến Mãi&nbsp;&nbsp;<img src="/images/123_hot.gif" border="0">&nbsp;<img src="/images/123_hot.gif" border="0">' href="/sanpham/giamgia/danhsach/1" hrefoptions='class="saleofflink"'}
<div style="background-color: #7DCCFF; width="100%">
<div class="side_container">
<div id="divSaleOff" class="t-center h150" style="padding: 10 0 10 0"></div>
</div>
</div><div class="seperator"></div>
{TitleBox title="Giỏ Hàng"}
<div style="background-color: #7DCCFF; width="100%">
<div class="side_container">
<div style="padding: 1 0 10 0;width:98%;margin: 1px;">
  <table border="0" cellpadding="0" cellspacing="0" width="100%" style="font:bold 11px/22px Tahoma;">
    <tr><td style="border-bottom: 1px solid #000000"><span class="f8 fb fore-red">{if $smarty.session.cart.product_count != ''}{$smarty.session.cart.product_count}{else}0{/if}&nbsp;Sản phẩm</span></td><td class="t-right" style="border-bottom: 1px solid #000000"><span class="f8 fb fore-red">{number_format number=$smarty.session.cart.total_price}&nbsp;VND</span></td></tr>
  </table>
  <table border="0" cellpadding="0" cellspacing="0" width="100%" style="font:bold 11px/20px Tahoma;">
    {foreach from=$smarty.session.cart item=product}
    {if $product.id != ''}
    <tr><td valign="top"><span>{$product.quantity}&nbsp;x&nbsp;</td><td><a href="/sanpham/{$product.id}/chitiet" class="side-cart">{$product.name}</a></span></td></tr>
    {/if}
    {/foreach}
    {if $smarty.session.cart.product_count > 0}
    <tr><td class="t-right" colspan="2"><a href="/giohang/xem">Cập nhật</a>&nbsp;|&nbsp<a href="/thanhtoan">Thanh toán</a></td></tr>
    {/if}
  </table>
</div>
</div>
</div><div class="seperator"></div>
{TitleBox title="Tìm kiếm"}
<div style="background-color: #7DCCFF; width="100%">
<div class="side_container">
<form style="padding: 5 3 2 3" class="t-left" method="post" action="/timkiem">
  <input type="text" name="txtKey" />
  <input type="image" border="0" title=" Tìm nhanh " alt="Tìm nhanh" src="/images/languages/vietnam/buttons/button_quick_find.gif">
  <br><span class="f8">Dùng từ khóa để tìm nhanh sản phẩm</span>
</form>
</div>
</div><div class="seperator"></div>
{TitleBox title="Hỗ trợ trực tuyến"}
<div style="background-color: #7DCCFF; width="100%">
<div class="side_container">
  <p class="phone_contact">0909 217 130</p>
  <p class="phone_contact">0907 537 422</p>
  <a class="contact" href="ymsgr:sendIM?labay11180"><p class="yahoo_contact">labay11180</p></a>
  <a class="contact" href="ymsgr:sendIM?thuynguyenc2"><p class="yahoo_contact">thuynguyenc2</p></a>
</div>
</div>