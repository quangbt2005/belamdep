<?php /* Smarty version 2.6.20, created on 2010-06-20 18:40:55
         compiled from leftmenu/menu1.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'math', 'leftmenu/menu1.tpl', 5, false),array('function', 'TitleBox', 'leftmenu/menu1.tpl', 11, false),)), $this); ?>
<div style="background-color: #7DCCFF; width="100%">
<div class="side_container">
  <ul class="categories">
    <?php $_from = $this->_tpl_vars['Categories']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['cat']):
?>
    <li style="margin-left:<?php echo smarty_function_math(array('equation' => "x * y",'x' => $this->_tpl_vars['cat']['level'],'y' => 30), $this);?>
<?php if ($this->_tpl_vars['cat']['level'] > 0): ?>;list-style-type: square<?php endif; ?>;"><a href="/sanpham/danhsach/<?php echo $this->_tpl_vars['cat']['categories_id']; ?>
" style="<?php if ($this->_tpl_vars['cat']['level'] == 0): ?>background-image:url(/images/<?php echo $this->_tpl_vars['cat']['icon']; ?>
);<?php else: ?>padding-left:0;<?php endif; ?><?php if ($this->_tpl_vars['cat']['categories_id'] == $this->_tpl_vars['current_cat']): ?>color: red;<?php endif; ?>"><?php echo $this->_tpl_vars['cat']['categories_name']; ?>
</a></li>
    <?php endforeach; endif; unset($_from); ?>
  </ul>
</div>
</div>
<div class="seperator"></div>
<?php echo smarty_title_box(array('title' => "Bán chạy nhất"), $this);?>

<div style="background-color: #7DCCFF; width="100%">
  <div class="side_container">
    <div id="slideshow">
      <div id="controls">
        <span><a href="" id="prev">Prev</a></span>
        <span><a href="" id="next">Next</a></span>
        <span><a href="" id="pause">Pause</a></span>
        <span><a href="" id="play">Play</a></span>
      </div>
      <div id="slides" class="pics">
        <?php $_from = $this->_tpl_vars['best_seller']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['best']):
?>
        <a href="/sanpham/<?php echo $this->_tpl_vars['best']['products_id']; ?>
/chitiet" title="<?php echo $this->_tpl_vars['best']['products_name']; ?>
"><img src="/product_thumb.php?f=<?php echo $this->_tpl_vars['best']['products_image']; ?>
&w=auto&h=130&cx=198&cy=200" alt="<?php echo $this->_tpl_vars['best']['products_name']; ?>
" hspace="0" border="0" width="198" height="200"></a>
        <?php endforeach; endif; unset($_from); ?>
      </div>
    </div>
  </div>
</div>
<div class="seperator"></div>
<?php echo smarty_title_box(array('title' => "TÀI KHOẢN NGÂN HÀNG"), $this);?>

<div style="background-color: #7DCCFF; width="100%">
<div class="side_container">
<div class="t-left" style="padding-left: 5px">
  <span style="background-color: rgb(255, 255, 0);">VietcomBank(VCB): </span>
  <p>Nguyễn Thị Thanh Thủy</p>
  <p><b><font color="#ff0000">025 100 158 7962</font></b></p>
  <p><span style="background-color: rgb(255, 255, 0);">Á Châu (ACB): </span></p>
  <p>Nguyễn Thị Minh Hải </p>
  <p><font color="#ff0000"><b>4041 6931 8020 5507</b></font></p>
</div>
</div>
</div>