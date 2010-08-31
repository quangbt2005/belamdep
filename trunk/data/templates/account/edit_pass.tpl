<table border="0" cellpadding="0" cellspacing="0" width="100%" style="padding: 10 0 10 0">
<tr><td><span class="bigtitle">Mật khẩu</span></td><td align="right"><img width="57" height="40" border="0" title=" Thanh toán " alt="Thanh toán" src="/images/table_background_account.gif"></td></tr>
</table>
{if $error_count > 0}
{foreach from=$errs item=error}
<div class="w100p error_field t-left">&nbsp;&nbsp;<img height="10" border="0" width="10" title=" Lỗi " alt="Lỗi" src="/images/icons/error.gif">&nbsp;{$error}</div>
{/foreach}
<br>
{/if}
<div class="floatLeft t-right w100p"><span class="fore-red f8">* Bắt buộc phải nhập</span></div>
<div class="clear"></div>
<form action="/taikhoan/matkhau" class="floatLeft w100p" method="post">
<table width="100%" cellpadding="0" cellspacing="0" class="register">
  <tr><td>Mật khẩu cũ</td><td><input type="password" name="txtOldPass" class="w300" value="">&nbsp;<span class="inputRequirement">*</span></td></tr>
  <tr><td>Mật khẩu mới</td><td><input type="password" name="txtNewPass" class="w300" value="">&nbsp;<span class="inputRequirement">*</span></td></tr>
  <tr><td>Nhập lại mật khẩu</td><td><input type="password" name="txtRetypePass" class="w300" value="">&nbsp;<span class="inputRequirement">*</span></td></tr>
</table><br>
<table width="100%" cellpadding="0" cellspacing="0" class="register">
  <tr>
    <td class="t-left"><a href="/taikhoan"><img border="0" title=" Quay lại " alt="Quay lại" src="/images/languages/vietnam/buttons/button_back.gif"></td>
    <td class="t-right"><input border="0" type="image" name="btnRegister" value="Register" title=" Tiếp tục " alt="Tiếp tục" src="/images/languages/vietnam/buttons/button_continue.gif"></td>
  </tr>
</table></form>