<table border="0" cellpadding="0" cellspacing="0" width="100%" style="padding: 10 0 10 0">
<tr><td><span class="bigtitle">Liên hệ</span></td><td align="right"><img width="57" height="40" border="0" title=" Liên hệ " alt="Liên hệ" src="/images/table_background_contact_us.gif"></td></tr>
</table>
{if $error_count > 0}
{foreach from=$errs item=error}
<div class="w100p error_field t-left">&nbsp;&nbsp;<img height="10" border="0" width="10" title=" Lỗi " alt="Lỗi" src="/images/icons/error.gif">&nbsp;{$error}</div>
{/foreach}
<br>
{/if}
<div class="clear"></div>
<form action="/lienhe" class="floatLeft w100p" method="post">
<table width="100%" cellpadding="0" cellspacing="0" class="register">
  <tr><td class="fb">Họ tên khách hàng:</td></tr>
  <tr><td><input type="text" name="txtName" class="w300" value="{$smarty.post.txtName}">&nbsp;<span class="inputRequirement">*</span></td></tr>
  <tr><td class="fb">Địa chỉ email:</td></tr>
  <tr><td><input type="text" name="txtEmail" class="w300" value="{$smarty.post.txtEmail}">&nbsp;<span class="inputRequirement">*</span></td></tr>
  <tr><td class="fb">Thông tin:</td></tr>
  <tr><td><textarea name="txtContent" class="w500" rows="10">{$smarty.post.txtContent}</textarea></td></tr>
  <tr><td class="fb">Mã bảo vệ:</td></tr>
  <tr>
  	<td><table width="100%" cellpadding="0" cellspacing="0" border="0">
      <tr>
        <td rowspan="2" valign="top" style="padding: 0;" width="21%"><img border="0" src="/captcha.php?name=contact"></td>
        <td valign="top" style="padding: 0;">&nbsp;<input type="text" name="txtCode">&nbsp;<span class="inputRequirement">*</span></td>
      </tr>
      <tr><td valign="top" style="padding: 0;"><span class="smallguide">(Nhập vào ô trên chính xác những chữ và số hiển thị trong ảnh)</span></td></tr>
  	</td></table>
  </tr>
</table>
<div class="seperator"></div>
<div class="container t-right"><p><input type="image" src="{$IMAGES_LANG_PATH}{$LANGUAGE}/buttons/button_continue.gif"></p></div>
</form>