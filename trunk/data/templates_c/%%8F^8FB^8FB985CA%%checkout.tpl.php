<?php /* Smarty version 2.6.20, created on 2010-06-01 16:17:32
         compiled from cart/checkout.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'number_format', 'cart/checkout.tpl', 39, false),)), $this); ?>
<table border="0" cellpadding="0" cellspacing="0" width="100%" style="padding: 10 0 10 0">
<tr><td><span class="bigtitle">Thanh toán</span></td><td align="right"><img width="57" height="40" border="0" title=" Thanh toán " alt="Thanh toán" src="/images/table_background_delivery.gif"></td></tr>
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
<div class="wrapper w100p t-left">
  <span class="smallguide">&nbsp;Hãy điền đầy đủ vào đơn đặt hàng để hoàn tất sau khi bạn đã chọn được hàng trong giỏ hàng!</span><br>
  <span class="f8 fore-red">&nbsp;*&nbsp;Bắt buộc phải nhập</span>
</div>
<form action="/thanhtoan" class="floatLeft w100p" method="post">
<table width="100%" cellpadding="0" cellspacing="0" class="register">
  <tr><th width="25%">Họ và Tên</th><td><input type="text" name="txtName" class="w380" value="<?php if ($this->_tpl_vars['is_post'] == 'true'): ?><?php echo $_POST['txtName']; ?>
<?php else: ?><?php echo $_SESSION['checkout']['name']; ?>
<?php endif; ?>">&nbsp;<span class="inputRequirement">*</span></td></tr>
  <tr><th>Địa chỉ giao hàng</th><td><input type="text" name="txtAddress" class="w380" value="<?php if ($this->_tpl_vars['is_post'] == 'true'): ?><?php echo $_POST['txtAddress']; ?>
<?php else: ?><?php echo $_SESSION['checkout']['address']; ?>
<?php endif; ?>">&nbsp;<span class="inputRequirement">*</span></td></tr>
  <tr><th>Điện thoại</th><td><input type="text" name="txtPhone" class="w380" value="<?php if ($this->_tpl_vars['is_post'] == 'true'): ?><?php echo $_POST['txtPhone']; ?>
<?php else: ?><?php echo $_SESSION['checkout']['phone']; ?>
<?php endif; ?>">&nbsp;<span class="inputRequirement">*</span></td></tr>
  <tr><th>Email</th><td><input type="text" name="txtEmail" class="w380" value="<?php if ($this->_tpl_vars['is_post'] == 'true'): ?><?php echo $_POST['txtEmail']; ?>
<?php else: ?><?php echo $_SESSION['checkout']['email']; ?>
<?php endif; ?>">&nbsp;<span class="inputRequirement">*</span></td></tr>
  <tr>
    <th>Phương thức<br>thanh toán</th>
    <td>
      <select name="drpMethod" class="w180">
        <option value="Tại nơi giao hàng"<?php if ($_POST['drpMethod'] == 'Tại nơi giao hàng' || $_SESSION['checkout']['method'] == 'Tại nơi giao hàng'): ?> selected="selected"<?php endif; ?>>Tại nơi giao hàng</option>
        <option value="Chuyển khoản ngân hàng"<?php if ($_POST['drpMethod'] == 'Chuyển khoản ngân hàng' || $_SESSION['checkout']['method'] == 'Chuyển khoản ngân hàng'): ?> selected="selected"<?php endif; ?>>Chuyển khoản ngân hàng</option>
        <option value="Trực tiếp tại cửa hàng"<?php if ($_POST['drpMethod'] == 'Trực tiếp tại cửa hàng' || $_SESSION['checkout']['method'] == 'Trực tiếp tại cửa hàng'): ?> selected="selected"<?php endif; ?>>Trực tiếp tại cửa hàng</option>
      </select>
    </td>
  </tr>
  <tr><th valign="top">Ghi chú</th><td valign="top"><textarea name="txtNote" class="w380" rows="15"><?php if ($this->_tpl_vars['is_post'] == 'true'): ?><?php echo $_POST['txtNote']; ?>
<?php else: ?><?php echo $_SESSION['checkout']['note']; ?>
<?php endif; ?></textarea></td></tr>
</table><br>
<table width="100%" cellpadding="0" cellspacing="0" class="register">
  <tr><th><input border="0" type="image" name="btnContinue" value="Continue" title=" Tiếp tục " alt="Tiếp tục" src="/images/languages/vietnam/buttons/button_continue.gif"></th></tr>
</table></form><br>
<table width="100%" cellpadding="0" cellspacing="0" class="register">
  <tr><td colspan="2" class="f14 fb">Sản phẩm đã chọn&nbsp;<a href="/giohang/xem"><span class="orderEdit">(Sửa)</span></a></td></tr>
  <?php $_from = $_SESSION['cart']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['product']):
?>
  <?php if ($this->_tpl_vars['product']['id'] != ''): ?>
  <tr><td>&nbsp;&nbsp;&nbsp;&nbsp;<?php echo $this->_tpl_vars['product']['quantity']; ?>
&nbsp;x&nbsp;<?php echo $this->_tpl_vars['product']['name']; ?>
</td><td class="t-right"><?php echo smarty_number_format(array('number' => $this->_tpl_vars['product']['total']), $this);?>
&nbsp;VND</td></tr>
  <?php endif; ?>
  <?php endforeach; endif; unset($_from); ?>
  <tr><td colspan="2" class="f12 fb t-right fore-red">Tổng cộng: <?php echo smarty_number_format(array('number' => $_SESSION['cart']['total_price']), $this);?>
&nbsp;VND</td></tr>
</table>