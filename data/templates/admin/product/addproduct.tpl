<form method="post" enctype="multipart/form-data">
<div class="content" style="width: 600px;margin:0 auto;">
  <div class="header1">Thêm sản phẩm mới</div>
    <div class="blu-container" style="padding: 10px;text-align: center">
      {if $errors_count > 0}
      {foreach from=$errors item=error}
      <div class="w100p error_field t-left">&nbsp;&nbsp;<img height="10" border="0" width="10" title=" Lỗi " alt="Lỗi" src="/images/icons/error.gif">&nbsp;{$error}</div>
      {/foreach}
      <br />
      {/if}
      <table cellpadding="0" cellspacing="0" width="100%" class="vlist">
        <tr>
          <th align="right" style="padding-right: 5px">Tên Sản Phẩm</th>
          <td align="left" style="padding-left: 5px"><input name="txtProductName" type="text" class="w240" value="{$smarty.post.txtProductName}"></td>
        </tr>
        <tr>
          <th align="right" style="padding-right: 5px">Danh Mục</th>
          <td align="left" style="padding-left: 5px">{$html_select_categories}</td>
        </tr>
        <tr>
          <th align="right" style="padding-right: 5px">Giá Sản Phẩm</th>
          <td align="left" style="padding-left: 5px"><input name="txtProductPrice" type="text" class="w100 t-right" value="{$smarty.post.txtProductPrice}">&nbsp;VND</td>
        </tr>
        <tr>
          <th align="right" style="padding-right: 5px">Số Lượng</th>
          <td align="left" style="padding-left: 5px"><input name="txtProductQuantity" type="text" class="w50 t-right" value="{$smarty.post.txtProductQuantity}"></td>
        </tr>
        <tr>
          <th align="right" style="padding-right: 5px">Chi Tiết Sản Phẩm</th>
          <td align="left" style="padding-left: 5px"><textarea name="txtProductDescription" cols="40" rows="6" class="w240">{$smarty.post.txtProductDescription}</textarea></td>
        </tr>
        <tr>
          <th align="right" style="padding-right: 5px">Hình Sản Phẩm</th>
          <td align="left" style="padding-left: 5px"><input name="txtProductImage" type="file" class="w240"></td>
        </tr>
      </table><br />
      <input type="submit" class="w80" value="Thêm">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
      <input type="button" value="Đóng" onclick="window.close();">
    </div>
  </div>
</div>
</form>{if $insert_product_ok==1}
<script type="text/javascript" language="javascript">
window.opener.reloadProductList({$showing_category});
alert('Đã thêm sản phẩm thành công');
</script>{/if}