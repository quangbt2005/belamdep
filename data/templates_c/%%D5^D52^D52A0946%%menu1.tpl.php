<?php /* Smarty version 2.6.20, created on 2010-06-03 04:47:52
         compiled from rightmenu/menu1.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'TitleBox', 'rightmenu/menu1.tpl', 1, false),array('function', 'number_format', 'rightmenu/menu1.tpl', 12, false),)), $this); ?>
<?php echo smarty_title_box(array('title' => 'Khuyến Mãi&nbsp;&nbsp;<img src="/images/123_hot.gif" border="0">&nbsp;<img src="/images/123_hot.gif" border="0">','href' => "/sanpham/giamgia/danhsach/1",'hrefoptions' => 'class="saleofflink"'), $this);?>

<div style="background-color: #7DCCFF; width="100%">
<div class="side_container">
<div id="divSaleOff" class="t-center h150" style="padding: 10 0 10 0"></div>
</div>
</div><div class="seperator"></div>
<?php echo smarty_title_box(array('title' => "Giỏ Hàng"), $this);?>

<div style="background-color: #7DCCFF; width="100%">
<div class="side_container">
<div style="padding: 1 0 10 0;width:98%;margin: 1px;">
  <table border="0" cellpadding="0" cellspacing="0" width="100%" style="font:bold 11px/22px Tahoma;">
    <tr><td style="border-bottom: 1px solid #000000"><span class="f8 fb fore-red"><?php if ($_SESSION['cart']['product_count'] != ''): ?><?php echo $_SESSION['cart']['product_count']; ?>
<?php else: ?>0<?php endif; ?>&nbsp;Sản phẩm</span></td><td class="t-right" style="border-bottom: 1px solid #000000"><span class="f8 fb fore-red"><?php echo smarty_number_format(array('number' => $_SESSION['cart']['total_price']), $this);?>
&nbsp;VND</span></td></tr>
  </table>
  <table border="0" cellpadding="0" cellspacing="0" width="100%" style="font:bold 11px/20px Tahoma;">
    <?php $_from = $_SESSION['cart']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['product']):
?>
    <?php if ($this->_tpl_vars['product']['id'] != ''): ?>
    <tr><td valign="top"><span><?php echo $this->_tpl_vars['product']['quantity']; ?>
&nbsp;x&nbsp;</td><td><a href="/sanpham/<?php echo $this->_tpl_vars['product']['id']; ?>
/chitiet" class="side-cart"><?php echo $this->_tpl_vars['product']['name']; ?>
</a></span></td></tr>
    <?php endif; ?>
    <?php endforeach; endif; unset($_from); ?>
    <?php if ($_SESSION['cart']['product_count'] > 0): ?>
    <tr><td class="t-right" colspan="2"><a href="/giohang/xem">Cập nhật</a>&nbsp;|&nbsp<a href="/thanhtoan">Thanh toán</a></td></tr>
    <?php endif; ?>
  </table>
</div>
</div>
</div><div class="seperator"></div>
<?php echo smarty_title_box(array('title' => "Tìm kiếm"), $this);?>

<div style="background-color: #7DCCFF; width="100%">
<div class="side_container">
<form style="padding: 5 3 2 3" class="t-left" method="post" action="/timkiem">
  <input type="text" name="txtKey" />
  <input type="image" border="0" title=" Tìm nhanh " alt="Tìm nhanh" src="/images/languages/vietnam/buttons/button_quick_find.gif">
  <br><span class="f8">Dùng từ khóa để tìm nhanh sản phẩm</span>
</form>
</div>
</div><div class="seperator"></div>
<?php echo smarty_title_box(array('title' => "Hỗ trợ trực tuyến"), $this);?>

<div style="background-color: #7DCCFF; width="100%">
<div class="side_container">
  <p class="phone_contact">0909 217 130</p>
  <p class="phone_contact">0907 537 422</p>
  <a class="contact" href="ymsgr:sendIM?labay11180"><p class="yahoo_contact">labay11180</p></a>
  <a class="contact" href="ymsgr:sendIM?thuynguyenc2"><p class="yahoo_contact">thuynguyenc2</p></a>
</div>
</div>