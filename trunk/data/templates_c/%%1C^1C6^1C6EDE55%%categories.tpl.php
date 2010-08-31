<?php /* Smarty version 2.6.20, created on 2010-07-08 06:01:17
         compiled from admin/categories/categories.tpl */ ?>
<script languge="javascript">
<?php echo '
/*
$(document).ready(function() {
  $("#tree").dynatree({
      onActivate: function(dtnode) {
        $("#echoActive").text(dtnode.data.title);
        if( dtnode.data.url )
          window.open(dtnode.data.url, dtnode.data.target);
      }
    });
});
*/
$(document).ready(function() {
  $("#tree").dynatree({
      onActivate: function(dtnode) {
      	update_sub_categories_tree(28);
      }
    });
});
'; ?>

</script>
<div id="bigBox">
  <div class="box">
    <div class="left"></div>
    <div class="right"></div>
    <div class="heading">
      <h1 class="bkg_dashboard">Categories</h1>
    </div>
    <div class="content">
      <h1>Categories</h1>
      <div id="tree" style="width: 40%;overflow: auto;float: left;">
        <ul>
          <?php $_from = $this->_tpl_vars['Tree']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['cat']):
?>
	      <li data="key: '<?php echo $this->_tpl_vars['cat']['categories_id']; ?>
'" class="folder"><?php echo $this->_tpl_vars['cat']['categories_name']; ?>

	      <?php if ($this->_tpl_vars['cat']['childs'] != null): ?>
            <ul>
              <?php $_from = $this->_tpl_vars['cat']['childs']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['childcat']):
?>
              <li data="key: '<?php echo $this->_tpl_vars['cat']['categories_id']; ?>
'" class="folder"><?php echo $this->_tpl_vars['childcat']['categories_name']; ?>
</li>
              <?php endforeach; endif; unset($_from); ?>
            </ul>
          <?php endif; ?>
          </li>
          <?php endforeach; endif; unset($_from); ?>
        </ul>
      </div>
      <div style="float: left;margin-left: 1%;width: 59%;margin-top:-50px;">
      	<div class="header1" id="echoActive">Danh mục con</div>
      	  <div class="blu-container" style="padding: 10px;">
      	    <div id="sub_cat_con"></div>
      	  </div>
      </div>
    </div>
  </div>
</div>