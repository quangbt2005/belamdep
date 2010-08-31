<script languge="javascript">
{literal}
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
{/literal}
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
          {foreach from=$Tree item=cat}
	      <li data="key: '{$cat.categories_id}'" class="folder">{$cat.categories_name}
	      {if $cat.childs != null}
            <ul>
              {foreach from=$cat.childs item=childcat}
              <li data="key: '{$cat.categories_id}'" class="folder">{$childcat.categories_name}</li>
              {/foreach}
            </ul>
          {/if}
          </li>
          {/foreach}
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