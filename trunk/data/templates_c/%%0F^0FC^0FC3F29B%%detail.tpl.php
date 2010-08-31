<?php /* Smarty version 2.6.20, created on 2010-08-08 20:49:59
         compiled from products/detail.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'number_format', 'products/detail.tpl', 5, false),array('function', 'ImageThumb', 'products/detail.tpl', 9, false),array('function', 'ImageButton', 'products/detail.tpl', 9, false),)), $this); ?>
<?php if ($this->_tpl_vars['product']['products_id'] != ''): ?>
<table width="100%" cellpadding="0" cellspacing="0" border="0">
  <tr><td colspan="2"><table width="100%" cellpadding="0" cellspacing="0" border="0"><tr>
    <td class="t-left v-bottom"><span class="f14"><?php echo $this->_tpl_vars['product']['products_name']; ?>
</span></td>
    <td class="t-right v-bottom"><?php if ($this->_tpl_vars['product']['special_price'] != ''): ?><s class="f14"><?php echo smarty_number_format(array('number' => $this->_tpl_vars['product']['products_price']), $this);?>
</s>&nbsp;<span class="fore-red f14"><?php echo smarty_number_format(array('number' => $this->_tpl_vars['product']['special_price']), $this);?>
&nbsp;VND</span><?php else: ?><span class="f14 fore-red"><?php echo smarty_number_format(array('number' => $this->_tpl_vars['product']['products_price']), $this);?>
&nbsp;VND</span><?php endif; ?></td>
  </tr></table></td></tr>
  <tr>
    <td class="v-top" style="padding-top: 20px;" width="80%"><?php echo $this->_tpl_vars['product']['products_description']; ?>
&nbsp;</td>
    <td class="v-top t-center" style="padding-top: 20px;"><?php echo smarty_image_thumb(array('src' => $this->_tpl_vars['product']['products_image'],'width' => 'auto','height' => $this->_tpl_vars['SMALL_IMAGE_HEIGHT'],'alt' => $this->_tpl_vars['product']['products_name'],'options' => "float: left"), $this);?>
<br /><br /><a href="/sanpham/<?php echo $this->_tpl_vars['product']['products_id']; ?>
/order"><?php echo smarty_image_button(array('image' => "button_buy_now.png",'alt' => "Đặt hàng"), $this);?>
</a><br /><br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a class="f10" style="text-decoration: underline;" href="javascript:history.back();">Trở lại</a></td>
  </tr>
</table>
<?php else: ?>
<p class="f20 fb">Không tìm thấy sản phẩm !</p>
<p><img src="/product_thumb.php?f=t58677.jpg&h=80&w=auto"></p><br><br><br><br><br><br>
<div class="container t-right"><p><a href="/"><img border="0" width="110" title=" Quay lại " alt="Quay lại" src="/images/languages/vietnam/buttons/button_back.gif"></a></p></div>
<?php endif; ?>
<br /><br />
<span class="bigtitle">Sản phẩm cùng danh mục</span>
<div id="makeMeScrollable">
  <div class="scrollingHotSpotLeft"></div>
  <div class="scrollingHotSpotRight"></div>
  <div class="scrollWrapper">
    <div class="scrollableArea">
      <?php $_from = $this->_tpl_vars['OtherProductsList']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['other']):
?>
      <a href="/sanpham/<?php echo $this->_tpl_vars['other']['products_id']; ?>
/chitiet"><img src="/product_thumb.php?f=<?php echo $this->_tpl_vars['other']['products_image']; ?>
&w=auto&h=120&ma=150&cx=150&cy=150" width="150" height="150" border="0"></a>
      <?php endforeach; endif; unset($_from); ?>
    </div>
  </div>
</div>