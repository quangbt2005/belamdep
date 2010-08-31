<?php /* Smarty version 2.6.20, created on 2010-06-09 20:00:35
         compiled from cart/view.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'ImageThumb', 'cart/view.tpl', 18, false),array('function', 'number_format', 'cart/view.tpl', 20, false),)), $this); ?>
<table border="0" cellpadding="0" cellspacing="0" width="100%" style="padding: 10 0 10 0">
<tr><td><span class="bigtitle">Chi tiết giỏ hàng</span></td><td align="right"><img width="57" height="40" border="0" title=" Chi tiết giỏ hàng " alt="Chi tiết giỏ hàng" src="/images/table_background_cart.gif"></td></tr>
</table>
<?php if ($this->_tpl_vars['has_product'] == TRUE): ?>
<form action="/giohang/capnhat" method="post">
<table class="list" width="100%" cellpadding="0" cellspacing="1" border="0">
  <tr>
    <th width="8%">Xóa</th>
    <th colspan="2">Sản Phẩm</th>
    <th width="15%">Đơn Giá<br>(VND)</th>
    <th width="10%">Số Lượng</th>
    <th width="10%">Thành Tiền</th>
  </tr>
  <?php $_from = $this->_tpl_vars['Cart']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['product']):
?>
  <?php if ($this->_tpl_vars['product']['id'] != ''): ?>
  <tr>
    <td class="t-center"><input type="checkbox" name="cart_delete[]" value="<?php echo $this->_tpl_vars['product']['id']; ?>
" /></td>
    <td width="10%"><?php echo smarty_image_thumb(array('src' => $this->_tpl_vars['product']['image'],'width' => 'auto','height' => $this->_tpl_vars['SMALL_IMAGE_HEIGHT'],'alt' => $this->_tpl_vars['product']['name']), $this);?>
</td>
    <td width="45%"><a href="/sanpham/<?php echo $this->_tpl_vars['product']['id']; ?>
/chitiet"><?php echo $this->_tpl_vars['product']['name']; ?>
</a>&nbsp;</td>
    <td class="t-right"><?php echo smarty_number_format(array('number' => $this->_tpl_vars['product']['price']), $this);?>
&nbsp;</td>
    <td class="t-right"><input class="w30 t-right" type="text" name="cart_quantity[]" value="<?php echo smarty_number_format(array('number' => $this->_tpl_vars['product']['quantity']), $this);?>
" /></td>
    <td class="t-right"><?php echo smarty_number_format(array('number' => $this->_tpl_vars['product']['total']), $this);?>
&nbsp;</td>
  </tr>
  <?php endif; ?>
  <?php endforeach; endif; unset($_from); ?>
  <tr>
  	<td colspan="6" class="t-right f12 fore-red fb">Tổng cộng: <?php echo smarty_number_format(array('number' => $_SESSION['cart']['total_price']), $this);?>
</td>
  </tr>
</table><br><br>
<div class="container floatLeft" style="width: 548px;padding: 8 0 8 0">
<div class="floatLeft w30p t-right"><input border="0" type="image" title=" Cập nhật Giỏ " alt="Cập nhật Giỏ" src="/images/languages/vietnam/buttons/button_update_cart.gif"></div>
<div class="floatLeft w30p t-right"><a href="/"><img border="0" width="110" title=" Tiếp tục chọn " alt="Tiếp tục chọn" src="/images/languages/vietnam/buttons/button_continue_shopping.gif"></a></div>
<div class="floatLeft w30p t-right"><a href="/thanhtoan"><img border="0" width="110" title=" Hoàn tất " alt=" Hoàn tất " src="/images/languages/vietnam/buttons/button_checkout.gif"></a></div>
</div>
</form>
<?php else: ?>
<div class="container"><p>Chưa có sản phẩm nào trong giỏ hàng</p></div><br>
<div class="container t-right"><p><a href="/"><img border="0" width="110" title=" Quay lại " alt="Quay lại" src="/images/languages/vietnam/buttons/button_back.gif"></a></p></div>
<?php endif; ?>