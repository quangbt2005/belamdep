{if $order != null}
<table border="0" cellpadding="0" cellspacing="0" width="100%" style="padding: 10 0 10 0">
<tr><td><span class="bigtitle">Xem lại đơn hàng của bạn</span></td><td align="right"><img width="57" height="40" border="0" title=" Thanh toán " alt="Thanh toán" src="/images/table_background_delivery.gif"></td></tr>
</table>
<table width="100%" cellpadding="0" cellspacing="0" class="register">
  <tr><td colspan="2" class="f13 fb">Sản phẩm đã chọn</td></tr>
  {foreach from=$OrderProducts item=product}
  {if $product.products_id != ''}
  <tr><td>&nbsp;&nbsp;&nbsp;&nbsp;{$product.products_quantity}&nbsp;x&nbsp;<a href="/sanpham/{$product.products_id}/chitiet" style="color: blue">{$product.products_name}</a></td><td class="t-right">{number_format number=$product.product_total}&nbsp;VND</td></tr>
  {/if}
  {/foreach}
  <tr><td colspan="2" class="f12 fb t-right fore-red">Tổng cộng: {number_format number=$order.value}&nbsp;VND</td></tr>
</table><br>
<table width="100%" cellpadding="0" cellspacing="0" class="register">
  <tr><td colspan="2" class="f13 fb t-left">Người thanh toán</td></tr>
  <tr><th width="25%">Họ và Tên</th><td>{$order.customers_name|escape:"html"}</td></tr>
  <tr><th>Địa chỉ giao hàng</th><td>{$order.address|escape:"html"}</td></tr>
  <tr><th>Điện thoại</th><td>{$order.phone|escape:"html"}</td></tr>
  <tr><th>Email</th><td>{$order.email|escape:"html"}</td></tr>
  <tr>
    <th valign="top">Phương thức<br>thanh toán</th>
    <td valign="top">{$order.method}</td>
  </tr>
  <tr><th valign="top">Ghi chú</th><td valign="top">{$order.note|escape:"html"|nl2br}</td></tr>
</table>
{else}
<p class="f20 fb">Không tìm thấy đơn hàng !</p>
<p><img src="/images/cry.gif"></p><br><br><br><br><br><br>
{/if}