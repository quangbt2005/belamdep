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
    <td>{$product.products_name}</td>
    <td align="right">100.000</td>
    <td align="right">{$product.products_price}</td>
    <td align="right">{$product.special_price}</td>
    <td><input type="button" value="Xóa"></td>
  </tr>
  {/foreach}
</table>