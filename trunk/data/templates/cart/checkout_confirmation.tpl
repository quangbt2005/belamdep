<table border="0" cellpadding="0" cellspacing="0" width="100%" style="padding: 10 0 10 0">
<tr><td><span class="bigtitle">Xác nhận đơn hàng</span></td><td align="right"><img width="57" height="40" border="0" title=" Thanh toán " alt="Thanh toán" src="/images/table_background_delivery.gif"></td></tr>
</table>
{if $error_count > 0}
{foreach from=$errs item=error}
<div class="w100p error_field t-left">&nbsp;&nbsp;<img height="10" border="0" width="10" title=" Lỗi " alt="Lỗi" src="/images/icons/error.gif">&nbsp;{$error}</div>
{/foreach}
<br>
{/if}
<table width="100%" cellpadding="0" cellspacing="0" class="register">
  <tr><td colspan="2" class="f13 fb">Sản phẩm đã chọn&nbsp;<a href="/giohang/xem"><span class="orderEdit">(Sửa)</span></a></td></tr>
  {foreach from=$smarty.session.cart item=product}
  {if $product.id != ''}
  <tr><td>&nbsp;&nbsp;&nbsp;&nbsp;{$product.quantity}&nbsp;x&nbsp;{$product.name}</td><td class="t-right">{number_format number=$product.total}&nbsp;VND</td></tr>
  {/if}
  {/foreach}
  <tr><td colspan="2" class="f12 fb t-right fore-red">Tổng cộng: {number_format number=$smarty.session.cart.total_price}&nbsp;VND</td></tr>
</table><br>
<table width="100%" cellpadding="0" cellspacing="0" class="register">
  <tr><td colspan="2" class="f13 fb t-left">Người thanh toán&nbsp;<a href="/thanhtoan"><span class="orderEdit">(Sửa)</span></a></td></tr>
  <tr><th width="25%">Họ và Tên</th><td>{$smarty.session.checkout.name|escape:"html"}</td></tr>
  <tr><th>Địa chỉ giao hàng</th><td>{$smarty.session.checkout.address|escape:"html"}</td></tr>
  <tr><th>Điện thoại</th><td>{$smarty.session.checkout.phone|escape:"html"}</td></tr>
  <tr><th>Email</th><td>{$smarty.session.checkout.email|escape:"html"}</td></tr>
  <tr>
    <th valign="top">Phương thức<br>thanh toán</th>
    <td valign="top">{$smarty.session.checkout.method}</td>
  </tr>
  <tr><th valign="top">Ghi chú</th><td valign="top">{$smarty.session.checkout.note|escape:"html"|nl2br}</td></tr>
</table><br>
<form action="/thanhtoan/xacnhan" class="floatLeft w100p" method="post">
<table width="100%" cellpadding="0" cellspacing="2">
  <tr><td colspan="2" class="f13 fb t-left">Mã bảo vệ&nbsp;<span class="smallguide">(Nếu tất cả thông tin trên đều đúng, xin hãy nhập mã an toàn và xác nhận)</span></td></tr>
  <tr>
    <td rowspan="2" width="20%" valign="top"><img border="0" src="/captcha.php?name=checkout"></td>
    <td>&nbsp;<input type="text" name="txtCode">&nbsp;<span class="inputRequirement">*</span></td>
  </tr>
  <tr><td>&nbsp;<span class="smallguide">(Nhập vào ô trên chính xác những chữ và số hiển thị trong ảnh)</span></td></tr>
</table><br>

<table width="100%" cellpadding="0" cellspacing="0" class="register">
  {if $smarty.session.checkout.method == 'Cổng thanh toán Bảo Kim'}
  <tr><th><input border="0" type="image" name="btnConfirm" value="Confirm" title=" Thanh toán qua Bảo Kim " alt="Thanh toán qua Bảo Kim" src="/images/btn_pay_now_2.png"></th></tr>
  {elseif $smarty.session.checkout.method == 'Cổng thanh toán Ngân Lượng'}
  <tr><th><input border="0" type="image" name="btnConfirm" value="Confirm" title=" Thanh toán qua Ngân Lượng " alt="Thanh toán qua Ngân Lượng" src="/images/btn_ngan_luong_3.gif"></th></tr>
  {else}
  <tr><th><input border="0" type="image" name="btnConfirm" value="Confirm" title=" Tiếp tục " alt="Tiếp tục" src="/images/languages/vietnam/buttons/button_confirm_order.gif"></th></tr>
  {/if}
</table></form><br>
