<?php /* Smarty version 2.6.20, created on 2010-06-08 20:34:31
         compiled from leftmenu/menu2.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'math', 'leftmenu/menu2.tpl', 5, false),array('function', 'TitleBox', 'leftmenu/menu2.tpl', 11, false),)), $this); ?>
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
<?php echo smarty_title_box(array('title' => "Danh mục tin"), $this);?>

<div style="background-color: #7DCCFF; width="100%">
<div class="side_container">
  <ul class="categories">
    <?php $_from = $this->_tpl_vars['NewsCategories']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['newscat']):
?>
    <li style="margin-left:<?php if ($this->_tpl_vars['newscat']['level'] > 0): ?><?php echo smarty_function_math(array('equation' => "x * y",'x' => $this->_tpl_vars['newscat']['level'],'y' => 30), $this);?>
<?php else: ?>15<?php endif; ?><?php if ($this->_tpl_vars['newscat']['level'] >= 0): ?>;list-style-type: square<?php endif; ?>;"><a href="/tintuc/danhmuc/<?php echo $this->_tpl_vars['newscat']['news_categories_id']; ?>
" style="<?php if ($this->_tpl_vars['newscat']['level'] == -1): ?>background-image:url(/images/<?php echo $this->_tpl_vars['newscat']['icon']; ?>
);<?php else: ?>padding-left:0;<?php endif; ?><?php if ($this->_tpl_vars['newscat']['news_categories_id'] == $this->_tpl_vars['current_news_cat']): ?>color: red;<?php endif; ?>"><?php echo $this->_tpl_vars['newscat']['news_categories_name']; ?>
</a></li>
    <?php endforeach; endif; unset($_from); ?>
  </ul>
</div>
</div>
<div class="seperator"></div>
