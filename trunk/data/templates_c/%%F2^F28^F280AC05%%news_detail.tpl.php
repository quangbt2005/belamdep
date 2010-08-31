<?php /* Smarty version 2.6.20, created on 2010-06-03 10:38:59
         compiled from news/news_detail.tpl */ ?>
<?php if ($this->_tpl_vars['has_news'] == 'true'): ?>
<table width="100%" cellpadding="0" cellspacing="10">
	<tr><td align="left"><a class="news2 fb" href="/tintuc/<?php echo $this->_tpl_vars['current_news']['news_id']; ?>
/chitiet"><span class="f12 fb"><?php echo $this->_tpl_vars['current_news']['news_title']; ?>
</span></a></td></tr>
	<tr><td align="center"><img border="0" src="/images/tintuc/<?php echo $this->_tpl_vars['current_news']['icon']; ?>
"></td></tr>
	<tr><td align="left" style="font-family: verdana;font-size:10pt;"><?php echo $this->_tpl_vars['current_news']['news_content']; ?>
</td></tr>
</table>
<?php endif; ?>
<?php if ($this->_tpl_vars['new_news_count'] > 0): ?>
<div class="w100p t-left">
	<p class="fb f12">Tin mới nhất</p>
	<p>
		<ul>
			<?php $_from = $this->_tpl_vars['NewNews']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['new_news']):
?>
			<li><a class="news1" href="/tintuc/<?php echo $this->_tpl_vars['new_news']['news_id']; ?>
/chitiet"><?php echo $this->_tpl_vars['new_news']['news_title']; ?>
</a></li>
			<?php endforeach; endif; unset($_from); ?>
		</ul>
	</p>
</div>
<?php endif; ?>
<?php if ($this->_tpl_vars['older_count'] > 0): ?>
<div class="w100p t-left">
	<p class="fb">Tin cũ hơn</p>
	<p>
		<ul>
			<?php $_from = $this->_tpl_vars['OlderNews']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['older_news']):
?>
			<li><a class="news1" href="/tintuc/<?php echo $this->_tpl_vars['older_news']['news_id']; ?>
/chitiet"><?php echo $this->_tpl_vars['older_news']['news_title']; ?>
</a></li>
			<?php endforeach; endif; unset($_from); ?>
		</ul>
	</p>
</div>
<?php endif; ?>