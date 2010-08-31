<?php /* Smarty version 2.6.20, created on 2010-06-01 09:33:12
         compiled from products/saleoff_list.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'TitleBox', 'products/saleoff_list.tpl', 3, false),array('function', 'ImageThumb', 'products/saleoff_list.tpl', 8, false),array('function', 'number_format', 'products/saleoff_list.tpl', 11, false),array('function', 'ImageButton', 'products/saleoff_list.tpl', 12, false),)), $this); ?>
  <?php if ($this->_tpl_vars['total_products'] > 0): ?>
  <div class="wrapper" style="width: 547px; margin-left: 1px;">
  <?php echo smarty_title_box(array('title' => "Sản phẩm khuyến mãi"), $this);?>

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
  <?php else: ?>
  <h1>Không tìm thấy sản phẩm nào <?php echo $this->_tpl_vars['total_products']; ?>
</h1>
  <?php endif; ?>