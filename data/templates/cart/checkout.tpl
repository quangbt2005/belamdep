<table border="0" cellpadding="0" cellspacing="0" width="100%" style="padding: 10 0 10 0">
<tr><td><span class="bigtitle">Thanh toán</span></td><td align="right"><img width="57" height="40" border="0" title=" Thanh toán " alt="Thanh toán" src="/images/table_background_delivery.gif"></td></tr>
</table>
{if $error_count > 0}
{foreach from=$errs item=error}
<div class="w100p error_field t-left">&nbsp;&nbsp;<img height="10" border="0" width="10" title=" Lỗi " alt="Lỗi" src="/images/icons/error.gif">&nbsp;{$error}</div>
{/foreach}
<br>
{/if}
<div class="wrapper w100p t-left">
  <span class="smallguide">&nbsp;Hãy điền đầy đủ vào đơn đặt hàng để hoàn tất sau khi bạn đã chọn được hàng trong giỏ hàng!</span><br>
  <span class="f8 fore-red">&nbsp;*&nbsp;Bắt buộc phải nhập</span>
</div>
<form action="/thanhtoan" class="floatLeft w100p" method="post">
<table width="100%" cellpadding="0" cellspacing="0" class="register">
  <tr><th width="25%">Họ và Tên</th><td><input type="text" name="txtName" class="w380" value="{if $is_post=='true'}{$smarty.post.txtName}{else}{$smarty.session.checkout.name}{/if}">&nbsp;<span class="inputRequirement">*</span></td></tr>
  <tr><th>Địa chỉ giao hàng</th><td><input type="text" name="txtAddress" class="w380" value="{if $is_post=='true'}{$smarty.post.txtAddress}{else}{$smarty.session.checkout.address}{/if}">&nbsp;<span class="inputRequirement">*</span></td></tr>
  <tr><th>Điện thoại</th><td><input type="text" name="txtPhone" class="w380" value="{if $is_post=='true'}{$smarty.post.txtPhone}{else}{$smarty.session.checkout.phone}{/if}">&nbsp;<span class="inputRequirement">*</span></td></tr>
  <tr><th>Email</th><td><input type="text" name="txtEmail" class="w380" value="{if $is_post=='true'}{$smarty.post.txtEmail}{else}{$smarty.session.checkout.email}{/if}">&nbsp;<span class="inputRequirement">*</span></td></tr>
  <tr>
    <th>Phương thức<br>thanh toán</th>
    <td>
      <select name="drpMethod" class="w180">
        <option value="Tại nơi giao hàng"{if $smarty.post.drpMethod=='Tại nơi giao hàng' || $smarty.session.checkout.method=='Tại nơi giao hàng'} selected="selected"{/if}>Tại nơi giao hàng</option>
        <option value="Chuyển khoản ngân hàng"{if $smarty.post.drpMethod=='Chuyển khoản ngân hàng' || $smarty.session.checkout.method=='Chuyển khoản ngân hàng'} selected="selected"{/if}>Chuyển khoản ngân hàng</option>
        <option value="Cổng thanh toán Bảo Kim"{if $smarty.post.drpMethod=='Cổng thanh toán Bảo Kim' || $smarty.session.checkout.method=='Cổng thanh toán Bảo Kim'} selected="selected"{/if}>Cổng thanh toán Bảo Kim</option>
        <option value="Cổng thanh toán Ngân Lượng"{if $smarty.post.drpMethod=='Cổng thanh toán Ngân Lượng' || $smarty.session.checkout.method=='Cổng thanh toán Ngân Lượng'} selected="selected"{/if}>Cổng thanh toán Ngân Lượng</option>
        <option value="Trực tiếp tại cửa hàng"{if $smarty.post.drpMethod=='Trực tiếp tại cửa hàng' || $smarty.session.checkout.method=='Trực tiếp tại cửa hàng'} selected="selected"{/if}>Trực tiếp tại cửa hàng</option>
      </select>
    </td>
  </tr>
  <tr><th valign="top">Ghi chú</th><td valign="top"><textarea name="txtNote" class="w380" rows="15">{if $is_post=='true'}{$smarty.post.txtNote}{else}{$smarty.session.checkout.note}{/if}</textarea></td></tr>
</table><br>
<table width="100%" cellpadding="0" cellspacing="0" class="register">
  <tr><th><input border="0" type="image" name="btnContinue" value="Continue" title=" Tiếp tục " alt="Tiếp tục" src="/images/languages/vietnam/buttons/button_continue.gif"></th></tr>
</table></form><br>
<table width="100%" cellpadding="0" cellspacing="0" class="register">
  <tr><td colspan="2" class="f14 fb">Sản phẩm đã chọn&nbsp;<a href="/giohang/xem"><span class="orderEdit">(Sửa)</span></a></td></tr>
  {foreach from=$smarty.session.cart item=product}
  {if $product.id != ''}
  <tr><td>&nbsp;&nbsp;&nbsp;&nbsp;{$product.quantity}&nbsp;x&nbsp;{$product.name}</td><td class="t-right">{number_format number=$product.total}&nbsp;VND</td></tr>
  {/if}
  {/foreach}
  <tr><td colspan="2" class="f12 fb t-right fore-red">Tổng cộng: {number_format number=$smarty.session.cart.total_price}&nbsp;VND</td></tr>
</table>