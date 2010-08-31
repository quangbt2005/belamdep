<?php /* Smarty version 2.6.20, created on 2010-06-03 10:36:00
         compiled from news/news_in_cat.tpl */ ?>
<?php if ($this->_tpl_vars['child_count'] > 0): ?>
<?php $_from = $this->_tpl_vars['ChildCats']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['childcat']):
?>
<div class="w50p t-left floatLeft" style="padding-bottom:25px"><a href="/tintuc/danhmuc/<?php echo $this->_tpl_vars['childcat']['news_categories_id']; ?>
"><span class="f14 fb"><?php echo $this->_tpl_vars['childcat']['news_categories_name']; ?>
</span></a></div>
<?php endforeach; endif; unset($_from); ?>
<div class="seperator w100p" style="border-top:3px solid #cccccc"></div>
<?php endif; ?>
<table width="100%" cellpadding="0" cellspacing="2">
<?php $_from = $this->_tpl_vars['Items']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['news']):
?>
<tr>
	<td colspan="2"><a class="news2 fb" href="/tintuc/<?php echo $this->_tpl_vars['news']['news_id']; ?>
/chitiet"><span class="f12 fb"><?php echo $this->_tpl_vars['news']['news_title']; ?>
</span></a></td>
</tr>
<tr>
	<td width="110" valign="top"><a href="/tintuc/<?php echo $this->_tpl_vars['news']['news_id']; ?>
/chitiet"><img border="0" class="floatLeft" width="<?php echo $this->_tpl_vars['HEADING_NEWS_IMAGE_WIDTH']; ?>
" height="<?php echo $this->_tpl_vars['HEADING_NEWS_IMAGE_HEIGHT']; ?>
" src="/images/tintuc/<?php echo $this->_tpl_vars['news']['icon']; ?>
" hspace="5"></a></td>
	<td valign="top"><span class="f10"><?php echo $this->_tpl_vars['news']['summary']; ?>
</span></td>
</tr>
<tr><td colspan="2">&nbsp;</td></tr>
<?php endforeach; endif; unset($_from); ?>
</table>
<?php if ($this->_tpl_vars['older_count'] > 0): ?>
<div class="w100p t-left">
<p>
	<ul>
		<?php $_from = $this->_tpl_vars['OlderNews']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['oldnews']):
?>
		<li><a class="news1" href="/tintuc/<?php echo $this->_tpl_vars['oldnews']['news_id']; ?>
/chitiet"><?php echo $this->_tpl_vars['oldnews']['news_title']; ?>
</a></li>
		<?php endforeach; endif; unset($_from); ?>
	</ul>
</p>
</div>
<?php endif; ?>