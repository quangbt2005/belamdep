<?php /* Smarty version 2.6.20, created on 2010-08-08 17:26:13
         compiled from home/index.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('modifier', 'upper', 'home/index.tpl', 4, false),array('function', 'number_format', 'home/index.tpl', 4, false),array('function', 'ImageThumb', 'home/index.tpl', 4, false),array('function', 'TitleBox', 'home/index.tpl', 58, false),array('function', 'ImageButton', 'home/index.tpl', 66, false),)), $this); ?>
  <div id="start_picture">
    <div id="box_1_1">
    <?php if ($this->_tpl_vars['Specs'][0] != ''): ?>
      <a href="/product_thumb.php?f=<?php echo $this->_tpl_vars['Specs'][0]['products_image']; ?>
&w=auto&h=500&ma=1000" ref="/sanpham/<?php echo $this->_tpl_vars['Specs'][0]['products_id']; ?>
/chitiet" class="agallery" title="<?php echo ((is_array($_tmp=$this->_tpl_vars['Specs'][0]['products_name'])) ? $this->_run_mod_handler('upper', true, $_tmp) : smarty_modifier_upper($_tmp)); ?>
&nbsp;&nbsp;<?php echo smarty_number_format(array('number' => $this->_tpl_vars['Specs'][0]['products_price']), $this);?>
&nbsp;VND"><?php echo smarty_image_thumb(array('src' => $this->_tpl_vars['Specs'][0]['products_image'],'width' => 'auto','height' => 64,'alt' => $this->_tpl_vars['Specs'][0]['products_name'],'options' => "hspace=\"5\" vspace=\"5\""), $this);?>
</a>
    <?php endif; ?>
    </div>

    <div id="box_1_2">
    <?php if ($this->_tpl_vars['Specs'][1] != ''): ?>
      <a href="/product_thumb.php?f=<?php echo $this->_tpl_vars['Specs'][1]['products_image']; ?>
&w=auto&h=500&ma=1000" ref="/sanpham/<?php echo $this->_tpl_vars['Specs'][1]['products_id']; ?>
/chitiet" class="agallery" title="<?php echo ((is_array($_tmp=$this->_tpl_vars['Specs'][1]['products_name'])) ? $this->_run_mod_handler('upper', true, $_tmp) : smarty_modifier_upper($_tmp)); ?>
&nbsp;&nbsp;<?php echo smarty_number_format(array('number' => $this->_tpl_vars['Specs'][1]['products_price']), $this);?>
&nbsp;VND"><?php echo smarty_image_thumb(array('src' => $this->_tpl_vars['Specs'][1]['products_image'],'width' => 'auto','height' => 64,'alt' => $this->_tpl_vars['Specs'][1]['products_name'],'options' => "hspace=\"5\" vspace=\"5\""), $this);?>
</a>
    <?php endif; ?>
    </div>

    <div id="box_1_3">
    <?php if ($this->_tpl_vars['Specs'][2] != ''): ?>
      <a href="/product_thumb.php?f=<?php echo $this->_tpl_vars['Specs'][2]['products_image']; ?>
&w=auto&h=500&ma=1000" ref="/sanpham/<?php echo $this->_tpl_vars['Specs'][2]['products_id']; ?>
/chitiet" class="agallery" title="<?php echo ((is_array($_tmp=$this->_tpl_vars['Specs'][2]['products_name'])) ? $this->_run_mod_handler('upper', true, $_tmp) : smarty_modifier_upper($_tmp)); ?>
&nbsp;&nbsp;<?php echo smarty_number_format(array('number' => $this->_tpl_vars['Specs'][2]['products_price']), $this);?>
&nbsp;VND"><?php echo smarty_image_thumb(array('src' => $this->_tpl_vars['Specs'][2]['products_image'],'width' => 'auto','height' => '64','alt' => $this->_tpl_vars['Specs'][2]['products_name'],'options' => "hspace=\"5\" vspace=\"5\""), $this);?>
</a>
    <?php endif; ?>
    </div>

    <div id="box_1_4">
    <?php if ($this->_tpl_vars['Specs'][3] != ''): ?>
      <a href="/product_thumb.php?f=<?php echo $this->_tpl_vars['Specs'][3]['products_image']; ?>
&w=auto&h=500&ma=1000" ref="/sanpham/<?php echo $this->_tpl_vars['Specs'][3]['products_id']; ?>
/chitiet" class="agallery" title="<?php echo ((is_array($_tmp=$this->_tpl_vars['Specs'][3]['products_name'])) ? $this->_run_mod_handler('upper', true, $_tmp) : smarty_modifier_upper($_tmp)); ?>
&nbsp;&nbsp;<?php echo smarty_number_format(array('number' => $this->_tpl_vars['Specs'][3]['products_price']), $this);?>
&nbsp;VND"><?php echo smarty_image_thumb(array('src' => $this->_tpl_vars['Specs'][3]['products_image'],'width' => 'auto','height' => '64','alt' => $this->_tpl_vars['Specs'][3]['products_name'],'options' => "hspace=\"5\" vspace=\"5\""), $this);?>
</a>
    <?php endif; ?>
    </div>

    <div id="box_2_1">
    <?php if ($this->_tpl_vars['Specs'][4] != ''): ?>
      <a href="/product_thumb.php?f=<?php echo $this->_tpl_vars['Specs'][4]['products_image']; ?>
&w=auto&h=500&ma=1000" ref="/sanpham/<?php echo $this->_tpl_vars['Specs'][4]['products_id']; ?>
/chitiet" class="agallery" title="<?php echo ((is_array($_tmp=$this->_tpl_vars['Specs'][4]['products_name'])) ? $this->_run_mod_handler('upper', true, $_tmp) : smarty_modifier_upper($_tmp)); ?>
&nbsp;&nbsp;<?php echo smarty_number_format(array('number' => $this->_tpl_vars['Specs'][4]['products_price']), $this);?>
&nbsp;VND"><?php echo smarty_image_thumb(array('src' => $this->_tpl_vars['Specs'][4]['products_image'],'width' => 'auto','height' => '135','ma' => '148','alt' => $this->_tpl_vars['Specs'][4]['products_name'],'options' => "hspace=\"5\" vspace=\"5\""), $this);?>
</a>
    <?php endif; ?>
    </div>


    <div id="box_3_1">
    <?php if ($this->_tpl_vars['Specs'][5] != ''): ?>
      <a href="/product_thumb.php?f=<?php echo $this->_tpl_vars['Specs'][5]['products_image']; ?>
&w=auto&h=500&ma=1000" ref="/sanpham/<?php echo $this->_tpl_vars['Specs'][5]['products_id']; ?>
/chitiet" class="agallery" title="<?php echo ((is_array($_tmp=$this->_tpl_vars['Specs'][5]['products_name'])) ? $this->_run_mod_handler('upper', true, $_tmp) : smarty_modifier_upper($_tmp)); ?>
&nbsp;&nbsp;<?php echo smarty_number_format(array('number' => $this->_tpl_vars['Specs'][5]['products_price']), $this);?>
&nbsp;VND"><?php echo smarty_image_thumb(array('src' => $this->_tpl_vars['Specs'][5]['products_image'],'width' => 'auto','height' => '64','alt' => $this->_tpl_vars['Specs'][5]['products_name'],'options' => "hspace=\"5\" vspace=\"5\""), $this);?>
</a>
    <?php endif; ?>
    </div>

    <div id="box_3_2">
    <?php if ($this->_tpl_vars['Specs'][6] != ''): ?>
      <a href="/product_thumb.php?f=<?php echo $this->_tpl_vars['Specs'][6]['products_image']; ?>
&w=auto&h=500&ma=1000" ref="/sanpham/<?php echo $this->_tpl_vars['Specs'][6]['products_id']; ?>
/chitiet" class="agallery" title="<?php echo ((is_array($_tmp=$this->_tpl_vars['Specs'][6]['products_name'])) ? $this->_run_mod_handler('upper', true, $_tmp) : smarty_modifier_upper($_tmp)); ?>
&nbsp;&nbsp;<?php echo smarty_number_format(array('number' => $this->_tpl_vars['Specs'][6]['products_price']), $this);?>
&nbsp;VND"><?php echo smarty_image_thumb(array('src' => $this->_tpl_vars['Specs'][6]['products_image'],'width' => 'auto','height' => '64','alt' => $this->_tpl_vars['Specs'][6]['products_name'],'options' => "hspace=\"5\" vspace=\"5\""), $this);?>
</a>
    <?php endif; ?>
    </div>


    <div id="box_2_2">
    <?php if ($this->_tpl_vars['Specs'][7] != ''): ?>
      <a href="/product_thumb.php?f=<?php echo $this->_tpl_vars['Specs'][7]['products_image']; ?>
&w=auto&h=500&ma=1000" ref="/sanpham/<?php echo $this->_tpl_vars['Specs'][7]['products_id']; ?>
/chitiet" class="agallery" title="<?php echo ((is_array($_tmp=$this->_tpl_vars['Specs'][7]['products_name'])) ? $this->_run_mod_handler('upper', true, $_tmp) : smarty_modifier_upper($_tmp)); ?>
&nbsp;&nbsp;<?php echo smarty_number_format(array('number' => $this->_tpl_vars['Specs'][7]['products_price']), $this);?>
&nbsp;VND"><?php echo smarty_image_thumb(array('src' => $this->_tpl_vars['Specs'][7]['products_image'],'width' => 'auto','height' => '135','ma' => '148','alt' => $this->_tpl_vars['Specs'][7]['products_name'],'options' => "hspace=\"5\" vspace=\"5\""), $this);?>
</a>
    <?php endif; ?>
    </div>

    <div id="maxbox">
    <a href="/sanpham/danhsach/42"><img src="/images/startbox/max_shirt.png" alt="T-Shirts" title="T-Shirts" border="0" height="326" width="179"></a>
    </div>
  </div><!-- start_picture -->
  <br>
  <div class="wrapper" style="width: 547px; margin-left: 1px;"><!-- New product -->
    <?php echo smarty_title_box(array('title' => "&nbsp;Sản phẩm mới"), $this);?>

    <?php $_from = $this->_tpl_vars['NewProducts']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['newProduct']):
?>
    <div class="product">
      <div style="height: 155px;padding-top: 5px">
        <a href="/sanpham/<?php echo $this->_tpl_vars['newProduct']['products_id']; ?>
/chitiet"><?php echo smarty_image_thumb(array('src' => $this->_tpl_vars['newProduct']['products_image'],'width' => 'auto','height' => $this->_tpl_vars['SMALL_IMAGE_HEIGHT'],'alt' => $this->_tpl_vars['newProduct']['products_name']), $this);?>
<br>
        <a href="/sanpham/<?php echo $this->_tpl_vars['newProduct']['products_id']; ?>
/chitiet"><?php echo $this->_tpl_vars['newProduct']['products_name']; ?>
</a><br>
      </div>
      <?php if ($this->_tpl_vars['newProduct']['special_price'] != ''): ?><s><?php echo smarty_number_format(array('number' => $this->_tpl_vars['newProduct']['products_price']), $this);?>
</s>&nbsp;<span class="fore-red"><?php echo smarty_number_format(array('number' => $this->_tpl_vars['newProduct']['special_price']), $this);?>
</span><?php else: ?><?php echo smarty_number_format(array('number' => $this->_tpl_vars['newProduct']['products_price']), $this);?>
<?php endif; ?>&nbsp;VND<br>
      <a href="/sanpham/<?php echo $this->_tpl_vars['newProduct']['products_id']; ?>
/order"><?php echo smarty_image_button(array('image' => "button_buy_now.png",'alt' => "Đặt hàng"), $this);?>
</a>
    </div>
    <?php endforeach; endif; unset($_from); ?>
  </div>