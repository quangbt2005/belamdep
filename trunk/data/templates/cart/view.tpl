<table border="0" cellpadding="0" cellspacing="0" width="100%" style="padding: 10 0 10 0">
<tr><td><span class="bigtitle">Chi tiết giỏ hàng</span></td><td align="right"><img width="57" height="40" border="0" title=" Chi tiết giỏ hàng " alt="Chi tiết giỏ hàng" src="/images/table_background_cart.gif"></td></tr>
</table>
{if $has_product == TRUE}
<form action="/giohang/capnhat" method="post">
<table class="list" width="100%" cellpadding="0" cellspacing="1" border="0">
  <tr>
    <th width="8%">Xóa</th>
    <th colspan="2">Sản Phẩm</th>
    <th width="15%">Đơn Giá<br>(VND)</th>
    <th width="10%">Số Lượng</th>
    <th width="10%">Thành Tiền</th>
  </tr>
  {foreach from=$Cart item=product}
  {if $product.id != ''}
  <tr>
    <td class="t-center"><input type="checkbox" name="cart_delete[]" value="{$product.id}" /></td>
    <td width="10%">{ImageThumb src=$product.image width=auto height=$SMALL_IMAGE_HEIGHT alt=$product.name}</td>
    <td width="45%"><a href="/sanpham/{$product.id}/chitiet">{$product.name}</a>&nbsp;</td>
    <td class="t-right">{number_format number=$product.price}&nbsp;</td>
    <td class="t-right"><input class="w30 t-right" type="text" name="cart_quantity[]" value="{number_format number=$product.quantity}" /></td>
    <td class="t-right">{number_format number=$product.total}&nbsp;</td>
  </tr>
  {/if}
  {/foreach}
  <tr>
  	<td colspan="6" class="t-right f12 fore-red fb">Tổng cộng: {number_format number=$smarty.session.cart.total_price}</td>
  </tr>
</table><br><br>
<div class="container floatLeft" style="width: 548px;padding: 8 0 8 0">
<div class="floatLeft w30p t-right"><input border="0" type="image" title=" Cập nhật Giỏ " alt="Cập nhật Giỏ" src="/images/languages/vietnam/buttons/button_update_cart.gif"></div>
<div class="floatLeft w30p t-right"><a href="/"><img border="0" width="110" title=" Tiếp tục chọn " alt="Tiếp tục chọn" src="/images/languages/vietnam/buttons/button_continue_shopping.gif"></a></div>
<div class="floatLeft w30p t-right"><a href="/thanhtoan"><img border="0" width="110" title=" Hoàn tất " alt=" Hoàn tất " src="/images/languages/vietnam/buttons/button_checkout.gif"></a></div>
</div>
</form>
{else}
<div class="container"><p>Chưa có sản phẩm nào trong giỏ hàng</p></div><br>
<div class="container t-right"><p><a href="/"><img border="0" width="110" title=" Quay lại " alt="Quay lại" src="/images/languages/vietnam/buttons/button_back.gif"></a></p></div>
{/if}