<?php /* Smarty version 2.6.20, created on 2010-06-07 06:46:14
         compiled from search/search.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('modifier', 'escape', 'search/search.tpl', 18, false),array('function', 'TitleBox', 'search/search.tpl', 28, false),array('function', 'ImageThumb', 'search/search.tpl', 33, false),array('function', 'number_format', 'search/search.tpl', 36, false),array('function', 'ImageButton', 'search/search.tpl', 37, false),)), $this); ?>
<table border="0" cellpadding="0" cellspacing="0" width="100%" style="padding: 10 0 10 0">
<tr><td><span class="bigtitle">Tìm kiếm</span></td><td align="right"><img width="57" height="40" border="0" title=" Tìm kiếm " alt="Tìm kiếm" src="/images/table_background_browse.gif"></td></tr>
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
<form action="/timkiem" class="floatLeft w100p" method="post">
<table border="0" cellpadding="0" cellspacing="0" width="510" style="padding: 0" align="center">
  <tr>
    <td rowspan="2"><img src="/images/con_lua.jpg"></td>
    <td colspan="2" align="center" class="f10">Hãy nhập từ bất kỳ liên quan đến sản phẩm bạn cần tìm</td>
  </tr>
  <tr>
    <td align="center" valign="middle">
      <input name="txtKey" class="w300" value="<?php if ($_POST['txtKey'] != ''): ?><?php echo ((is_array($_tmp=$_POST['txtKey'])) ? $this->_run_mod_handler('escape', true, $_tmp) : smarty_modifier_escape($_tmp)); ?>
<?php else: ?><?php echo $this->_tpl_vars['txtKey']; ?>
<?php endif; ?>">&nbsp;
    </td>
    <td align="center" valign="middle">
      <input type="image" src="<?php echo $this->_tpl_vars['IMAGES_LANG_PATH']; ?>
<?php echo $this->_tpl_vars['LANGUAGE']; ?>
/buttons/button_search.gif">
    </td>
  </tr>
</table></form>

  <?php if ($this->_tpl_vars['total_products'] > 0): ?>
  <div class="wrapper" style="width: 547px; margin-left: 1px;">
  <?php echo smarty_title_box(array('title' => "Kết quả tìm kiếm"), $this);?>

    <?php $_from = $this->_tpl_vars['Product_List']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['product']):
?>
    <div class="product">
  <?php if ($this->_tpl_vars['product']['empty'] != 'true'): ?>
  <div style="height: 155px;padding: 5px">
    <a href="/sanpham/<?php echo $this->_tpl_vars['product']['products_id']; ?>
/chitiet"><?php echo smarty_image_thumb(array('src' => $this->_tpl_vars['product']['products_image'],'width' => 'auto','height' => $this->_tpl_vars['SMALL_IMAGE_HEIGHT'],'alt' => $this->_tpl_vars['product']['products_name']), $this);?>
<br>
    <a href="/sanpham/<?php echo $this->_tpl_vars['product']['products_id']; ?>
/chitiet"><?php echo $this->_tpl_vars['product']['products_name']; ?>
</a><br>
  </div>
  <?php if ($this->_tpl_vars['product']['special_price'] != ''): ?><s><?php echo smarty_number_format(array('number' => $this->_tpl_vars['product']['products_price']), $this);?>
</s>&nbsp;<span class="fore-red"><?php echo smarty_number_format(array('number' => $this->_tpl_vars['product']['special_price']), $this);?>
<?php else: ?><?php echo smarty_number_format(array('number' => $this->_tpl_vars['product']['products_price']), $this);?>
<?php endif; ?>&nbsp;VND</span><br>
  <a href="/sanpham/<?php echo $this->_tpl_vars['product']['products_id']; ?>
/order"><?php echo smarty_image_button(array('image' => "button_buy_now.png",'alt' => "Đặt hàng"), $this);?>
</a>
  <?php endif; ?>
</div>
    <?php endforeach; endif; unset($_from); ?>
  </div>
  <div class="clear"></div>
  <?php echo $this->_tpl_vars['pager']; ?>
<div class="clear"></div>
  <div class="t-right" style="width: 547px;"><span class="f10">Hiển thị <?php echo $this->_tpl_vars['product_count']; ?>
 sản phẩm từ <?php echo $this->_tpl_vars['product_from']; ?>
 đến <?php echo $this->_tpl_vars['product_to']; ?>
 trong tổng số <?php echo $this->_tpl_vars['total_products']; ?>
 sản phẩm</span></div>
  <?php elseif ($this->_tpl_vars['error_count'] < 0): ?>
  <h1>Không tìm thấy sản phẩm nào</h1>
  <?php endif; ?>