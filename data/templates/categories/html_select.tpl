<select class="w100">
{foreach from=$Categories_List item=category}
<option value="{$category.categories_id}"{if $category.categories_id==$selected_id} selected="selected"{/if}>{$category.categories_name}</option>
{/foreach}
</select>