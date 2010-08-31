<?php /* Smarty version 2.6.20, created on 2010-06-10 01:16:37
         compiled from account/register.tpl */ ?>
<table border="0" cellpadding="0" cellspacing="0" width="100%" style="padding: 10 0 10 0">
<tr><td><span class="bigtitle">Đăng ký tài khoản</span></td><td align="right"><img width="57" height="40" border="0" title=" Thanh toán " alt="Thanh toán" src="/images/table_background_account.gif"></td></tr>
</table>
<?php if ($this->_tpl_vars['error_count'] > 0): ?>
<?php $_from = $this->_tpl_vars['errs']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['error']):
?>
<div class="w100p error_field t-left">&nbsp;&nbsp;<img height="10" border="0" width="10" title=" Lỗi " alt="Lỗi" src="/images/icons/error.gif">&nbsp;<?php echo $this->_tpl_vars['error']; ?>
</div>
<?php endforeach; endif; unset($_from); ?>
<br>
<?php endif; ?>
<div class="w100p t-left">
<span class="f8 fb fore-red">LƯU Ý: </span><span class="f8">&nbsp;Nếu bạn đã có tài khoản thì hãy <a href="/dangnhap">đăng nhập</a> ở đây.</span>
</div><br>
<div class="floatLeft t-left w50p"><span class="f14 fb">Thông tin cá nhân</span></div>
<div class="floatLeft t-right w50p"><span class="fore-red f8">* Bắt buộc phải nhập</span></div>
<div class="clear"></div>
<form action="/taikhoan/dangky" class="floatLeft w100p" method="post">
<table width="100%" cellpadding="0" cellspacing="0" class="register">
  <?php if ($this->_tpl_vars['is_post'] == 'true'): ?><?php $this->assign('gender', $_POST['radGender']); ?><?php else: ?><?php $this->assign('gender', 'm'); ?><?php endif; ?>
  <tr><td>Giới tính</td><td><input type="radio" name="radGender" value="m" <?php if ($this->_tpl_vars['gender'] == 'm'): ?>checked="checked"<?php endif; ?> id="radGenderM">&nbsp;<label for="radGenderM">Nam&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</label><input type="radio" name="radGender" value="f" <?php if ($this->_tpl_vars['gender'] == 'f'): ?>checked="checked"<?php endif; ?> id="radGenderF">&nbsp;<label for="radGenderF">Nữ&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</label></td></tr>
  <tr><td>Họ</td><td><input type="text" name="txtFirstName" class="w300" value="<?php echo $_POST['txtFirstName']; ?>
"></td></tr>
  <tr><td>Tên</td><td><input type="text" name="txtLastName" class="w300" value="<?php echo $_POST['txtLastName']; ?>
">&nbsp;<span class="inputRequirement">*</span></td></tr>
  <tr><td>Ngày sinh</td><td><input type="text" name="txtDOB" class="w300" value="<?php echo $_POST['txtDOB']; ?>
"><span class="smallguide">&nbsp;(Ví dụ 24/12/1983)</span></td></tr>
  <tr><td>Email</td><td><input type="text" name="txtEmail" class="w300" value="<?php echo $_POST['txtEmail']; ?>
"></td></tr>
  <tr><td>Điện thoại</td><td><input type="text" name="txtPhone" class="w300" value="<?php echo $_POST['txtPhone']; ?>
"></td></tr>
</table><br>
<div class="w100p t-left">
<span class="f14 fb">Địa chỉ</span>
</div>
<table width="100%" cellpadding="0" cellspacing="0" class="register">
  <tr><td>Đường phố</td><td><input type="text" name="txtStreet" class="w300" value="<?php echo $_POST['txtStreet']; ?>
"></td></tr>
  <tr><td>Quận/Huyện</td><td><input type="text" name="txtDistrict" class="w300" value="<?php echo $_POST['txtDistrict']; ?>
"></td></tr>
  <tr><td>Tỉnh/Thành</td><td><select name="drpCity" class="w180"><option value="Hồ Chí Minh">Hồ Chí Minh</option></select></td></tr>
</table><br>
<div class="w100p t-left">
<span class="f14 fb">Mật khẩu</span>
</div>
<table width="100%" cellpadding="0" cellspacing="0" class="register">
  <tr><td>Mật khẩu</td><td><input type="password" name="txtPassword" class="w300" value="">&nbsp;<span class="inputRequirement">*</span></td></tr>
  <tr><td>Nhập lại mật khẩu</td><td><input type="password" name="txtRetypePassword" class="w300" value="">&nbsp;<span class="inputRequirement">*</span></td></tr>
</table><br>
<div class="w100p t-left">
<span class="f14 fb">Mã bảo vệ</span>
</div>
<table width="100%" cellpadding="0" cellspacing="0">
  <tr>
    <td rowspan="2" valign="top"><img border="0" src="/captcha.php?name=account"></td>
    <td>&nbsp;<input type="text" name="txtCode">&nbsp;<span class="inputRequirement">*</span></td>
  </tr>
  <tr><td>&nbsp;<span class="smallguide">(Nhập vào ô trên chính xác những chữ và số hiển thị trong ảnh)</span></td></tr>
</table><br>
<table width="100%" cellpadding="0" cellspacing="0" class="register">
  <tr><td class="t-right"><input border="0" type="image" name="btnRegister" value="Register" title=" Tiếp tục " alt="Tiếp tục" src="/images/languages/vietnam/buttons/button_continue.gif"></td></tr>
</table></form>