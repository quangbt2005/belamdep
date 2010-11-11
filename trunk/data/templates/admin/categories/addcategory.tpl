<form method="post" enctype="multipart/form-data">
<div class="content" style="width: 600px;margin:0 auto;">
  <div class="header1">Thêm danh mục sản phẩm</div>
    <div class="blu-container" style="padding: 10px;text-align: center">
      {if $errors_count > 0}
      {foreach from=$errors item=error}
      <div class="w100p error_field t-left">&nbsp;&nbsp;<img height="10" border="0" width="10" title=" Lỗi " alt="Lỗi" src="/images/icons/error.gif">&nbsp;{$error}</div>
      {/foreach}
      <br />
      {/if}
      <table cellpadding="0" cellspacing="0" width="100%" class="vlist">
        <tr>
          <th align="right" style="padding-right: 5px">Tên Danh Mục</th>
          <td align="left" style="padding-left: 5px"><input name="txtCategoryName" type="text" class="w240" value="{$smarty.post.txtProductName}"></td>
        </tr>
        <tr>
          <th align="right" style="padding-right: 5px">Danh Mục Cha</th>
          <td align="left" style="padding-left: 5px">{$html_select_categories}</td>
        </tr>
        <tr>
          <th align="right" style="padding-right: 5px">Biểu tượng</th>
          <td align="left" style="padding-left: 5px"><input name="txtCategoryImage" type="file" class="w240"></td>
        </tr>
      </table><br />
      <input type="submit" class="w80" value="Thêm">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
      <input type="button" value="Đóng" onclick="window.close();">
    </div>
  </div>
</div>
</form>{if $insert_category_ok==1}
<script type="text/javascript" language="javascript">
window.opener.addTreeNewCategory({$new_category_id},'{$new_category_name}');
alert('Đã thêm danh mục thành công');
</script>{/if}