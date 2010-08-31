<?php /* Smarty version 2.6.20, created on 2010-06-01 16:17:48
         compiled from cart/checkout_confirmation.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'number_format', 'cart/checkout_confirmation.tpl', 14, false),array('modifier', 'escape', 'cart/checkout_confirmation.tpl', 21, false),array('modifier', 'nl2br', 'cart/checkout_confirmation.tpl', 29, false),)), $this); ?>
<table border="0" cellpadding="0" cellspacing="0" width="100%" style="padding: 10 0 10 0">
<tr><td><span class="bigtitle">Xác nhận đơn hàng</span></td><td align="right"><img width="57" height="40" border="0" title=" Thanh toán " alt="Thanh toán" src="/images/table_background_delivery.gif"></td></tr>
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
<table width="100%" cellpadding="0" cellspacing="0" class="register">
  <tr><td colspan="2" class="f13 fb">Sản phẩm đã chọn&nbsp;<a href="/giohang/xem"><span class="orderEdit">(Sửa)</span></a></td></tr>
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
</table><br>
<table width="100%" cellpadding="0" cellspacing="0" class="register">
  <tr><td colspan="2" class="f13 fb t-left">Người thanh toán&nbsp;<a href="/thanhtoan"><span class="orderEdit">(Sửa)</span></a></td></tr>
  <tr><th width="25%">Họ và Tên</th><td><?php echo ((is_array($_tmp=$_SESSION['checkout']['name'])) ? $this->_run_mod_handler('escape', true, $_tmp, 'html') : smarty_modifier_escape($_tmp, 'html')); ?>
</td></tr>
  <tr><th>Địa chỉ giao hàng</th><td><?php echo ((is_array($_tmp=$_SESSION['checkout']['address'])) ? $this->_run_mod_handler('escape', true, $_tmp, 'html') : smarty_modifier_escape($_tmp, 'html')); ?>
</td></tr>
  <tr><th>Điện thoại</th><td><?php echo ((is_array($_tmp=$_SESSION['checkout']['phone'])) ? $this->_run_mod_handler('escape', true, $_tmp, 'html') : smarty_modifier_escape($_tmp, 'html')); ?>
</td></tr>
  <tr><th>Email</th><td><?php echo ((is_array($_tmp=$_SESSION['checkout']['email'])) ? $this->_run_mod_handler('escape', true, $_tmp, 'html') : smarty_modifier_escape($_tmp, 'html')); ?>
</td></tr>
  <tr>
    <th valign="top">Phương thức<br>thanh toán</th>
    <td valign="top"><?php echo $_SESSION['checkout']['method']; ?>
</td>
  </tr>
  <tr><th valign="top">Ghi chú</th><td valign="top"><?php echo ((is_array($_tmp=((is_array($_tmp=$_SESSION['checkout']['note'])) ? $this->_run_mod_handler('escape', true, $_tmp, 'html') : smarty_modifier_escape($_tmp, 'html')))) ? $this->_run_mod_handler('nl2br', true, $_tmp) : smarty_modifier_nl2br($_tmp)); ?>
</td></tr>
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
  <tr><th><input border="0" type="image" name="btnConfirm" value="Confirm" title=" Tiếp tục " alt="Tiếp tục" src="/images/languages/vietnam/buttons/button_confirm_order.gif"></th></tr>
</table></form><br>