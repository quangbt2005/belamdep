<table class="vlist" cellpadding="0" cellspacing="0" width="100%">
  <tr>
    <th width="40%">Tên Sản Phẩm</th>
    <th>Giá Gốc</th>
    <th>Giá<br />Niêm Yết</th>
    <th>Giá<br />Khuyến Mãi</th>
    <th>&nbsp;</th>
    <th>&nbsp;</th>
  </tr>
  {foreach from=$Products_List item=product}
  <tr onMouseOver="this.style.backgroundColor='#71FFB8';" onMouseOut="this.style.backgroundColor='transparent';">
    <td>{$product.products_name}</td>
    <td>100.000 VND</td>
    <td>{$product.products_price}</td>
    <td>{$product.special_price}</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
  </tr>
  {/foreach}
</table>