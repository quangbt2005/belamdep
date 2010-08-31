<table border="0" cellpadding="0" cellspacing="0" width="100%" style="padding: 10 0 10 0">
<tr><td><span class="bigtitle">Thông tin tài khoản</span></td><td align="right"><img width="57" height="40" border="0" title=" Thanh toán " alt="Thanh toán" src="/images/table_background_account.gif"></td></tr>
</table>
{if $error_count > 0}
{foreach from=$errs item=error}
<div class="w100p error_field t-left">&nbsp;&nbsp;<img height="10" border="0" width="10" title=" Lỗi " alt="Lỗi" src="/images/icons/error.gif">&nbsp;{$error}</div>
{/foreach}
<br>
{/if}
<div class="floatLeft t-left w50p"><span class="f12 fb">Thông tin cá nhân</span></div>
<div class="floatLeft t-right w50p"><span class="fore-red f8">* Bắt buộc phải nhập</span></div>
<div class="clear"></div>
<form action="/taikhoan/thongtin" class="floatLeft w100p" method="post">
<table width="100%" cellpadding="0" cellspacing="0" class="register">
  {if $is_post=='true'}{assign var="gender" value=$smarty.post.radGender}{else}{assign var="gender" value=$customer.customers_gender}{/if}
  <tr><td>Giới tính</td><td><input type="radio" name="radGender" value="m" {if $gender=='m'}checked="checked"{/if} id="radGenderM">&nbsp;<label for="radGenderM">Nam&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</label><input type="radio" name="radGender" value="f" {if $gender=='f'}checked="checked"{/if} id="radGenderF">&nbsp;<label for="radGenderF">Nữ&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</label></td></tr>
  <tr><td>Họ</td><td><input type="text" name="txtFirstName" class="w300" value="{if $is_post=='true'}{$smarty.post.txtFirstName}{else}{$customer.customers_firstname}{/if}"></td></tr>
  <tr><td>Tên</td><td><input type="text" name="txtLastName" class="w300" value="{if $is_post=='true'}{$smarty.post.txtLastName}{else}{$customer.customers_lastname}{/if}">&nbsp;<span class="inputRequirement">*</span></td></tr>
  <tr><td>Ngày sinh</td><td><input type="text" name="txtDOB" class="w300" value="{if $is_post=='true'}{$smarty.post.txtDOB}{else}{$customer.dob}{/if}"><span class="smallguide">&nbsp;(Ví dụ 24/12/1983)</span></td></tr>
  <tr><td>Email</td><td>{$smarty.session.logon.email}</td></tr>
  <tr><td>Điện thoại</td><td><input type="text" name="txtPhone" class="w300" value="{if $is_post=='true'}{$smarty.post.txtPhone}{else}{$customer.customers_telephone}{/if}"></td></tr>
</table><br>
<div class="w100p t-left">
<span class="f12 fb">Địa chỉ</span>
</div>
<table width="100%" cellpadding="0" cellspacing="0" class="register">
  <tr><td>Đường phố</td><td><input type="text" name="txtStreet" class="w300" value="{if $is_post=='true'}{$smarty.post.txtStreet}{else}{$customer.entry_street_address}{/if}"></td></tr>
  <tr><td>Quận/Huyện</td><td><input type="text" name="txtDistrict" class="w300" value="{if $is_post=='true'}{$smarty.post.txtDistrict}{else}{$customer.entry_state}{/if}"></td></tr>
  <tr><td>Tỉnh/Thành</td><td><select name="drpCity" class="w180"><option value="Hồ Chí Minh">Hồ Chí Minh</option></select></td></tr>
</table><br>
<table width="100%" cellpadding="0" cellspacing="0" class="register">
  <tr>
    <td class="t-left"><a href="/taikhoan"><img border="0" title=" Quay lại " alt="Quay lại" src="/images/languages/vietnam/buttons/button_back.gif"></td>
    <td class="t-right"><input border="0" type="image" name="btnRegister" value="Register" title=" Tiếp tục " alt="Tiếp tục" src="/images/languages/vietnam/buttons/button_continue.gif"></td>
  </tr>
</table></form>