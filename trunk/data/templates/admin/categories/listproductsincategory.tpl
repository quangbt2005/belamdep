<table class="vlist" cellpadding="0" cellspacing="0" width="100%">
  <tr>
    <th width="40%">Tên Sản Phẩm</th>
    <th>Giá Gốc<br />(VND)</th>
    <th>Giá<br />Niêm Yết (VND)</th>
    <th>Giá<br />Khuyến Mãi (VND)</th>
    <th width="50px">&nbsp;</th>
  </tr>
  {foreach from=$Products_List item=product}
  <tr onMouseOver="this.style.backgroundColor='#71FFB8';" onMouseOut="this.style.backgroundColor='transparent';">
    <td><a href="javascript:openEditProductPopup({$product.products_id});">{$product.products_name}</a></td>
    <td align="right">100.000</td>
    <td align="right">{number_format number=$product.products_price}</td>
    <td align="right">{number_format number=$product.special_price}</td>
    <td><input type="button" value="Xóa" onclick="deleteProduct({$product.products_id});"></td>
  </tr>
  {/foreach}
</table>
{literal}
<script type="text/javascript" language="javascript">
function deleteProduct(product_id){
  var category_id = $("#tree").dynatree("getActiveNode").data.key;
  if(category_id != null && product_id != null && category_id != '' && product_id != ''){
    $.get("/admin/products/delete/" + product_id + "/" + category_id, function(data){
      update_sub_categories_tree(category_id);
    });
  }
}
</script>
{/literal}