<?php /* Smarty version 2.6.20, created on 2010-06-08 05:36:53
         compiled from news/index.tpl */ ?>
<?php $_from = $this->_tpl_vars['Items']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['news']):
?>
<div class="w100p t-left" style="border-bottom: 1px solid #cccccc">
<a href="/tintuc/danhmuc/<?php echo $this->_tpl_vars['news']['cat']['news_categories_id']; ?>
"><span class="f12 fb"><?php echo $this->_tpl_vars['news']['cat']['news_categories_name']; ?>
</span></a><br>
<a href="/tintuc/<?php echo $this->_tpl_vars['news']['top_news'][0]['news_id']; ?>
/chitiet"><img border="0" class="floatLeft" width="<?php echo $this->_tpl_vars['HEADING_NEWS_IMAGE_WIDTH']; ?>
" height="<?php echo $this->_tpl_vars['HEADING_NEWS_IMAGE_HEIGHT']; ?>
" src="/images/tintuc/<?php echo $this->_tpl_vars['news']['top_news'][0]['icon']; ?>
" hspace="5" vspace="5"></a>
<a class="news2" href="/tintuc/<?php echo $this->_tpl_vars['news']['top_news'][0]['news_id']; ?>
/chitiet"><?php echo $this->_tpl_vars['news']['top_news'][0]['news_title']; ?>
</a><br>
<span class="f10"><?php echo $this->_tpl_vars['news']['summary']; ?>
 ...</span><br>
<p>
	<ul>
		<?php $_from = $this->_tpl_vars['news']['top_news']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['next_first']):
?>
		<li><a class="news1" href="/tintuc/<?php echo $this->_tpl_vars['next_first']['news_id']; ?>
/chitiet"><?php echo $this->_tpl_vars['next_first']['news_title']; ?>
</a></li>
		<?php endforeach; endif; unset($_from); ?>
	</ul>
</p>
</div>
<div class="seperator"></div>
<?php endforeach; endif; unset($_from); ?>