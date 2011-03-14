        <table width="100%" class="vlist" cellpadding="0" cellspacing="0">
          <tr>
            <th>Khách hàng</th>
            <th>Tổng tiền</th>
            <th>Địa chỉ</th>
            <th>Ngày đặt hàng</th>
            <th>Tình trạng</th>
            <th width="50">Xóa</th>
          </tr>
          {foreach from=$Orders item=order}
          <tr onMouseOver="this.style.backgroundColor='#71FFB8';" onMouseOut="this.style.backgroundColor='transparent';">
            <td><a href="javascript:openOrderDetailPopup({$order.orders_id});">{$order.customers_name|escape:"html"}</a></td>
            <td align="right">{number_format number=$order.value}&nbsp;VND</td>
            <td align="left">{$order.address|escape:"html"}&nbsp;</td>
            <td align="right">{$order.date_purchased}</td>
            <td>{$order.orders_status_name}</td>
            <td align="center"><input type="checkbox" value="{$order.orders_id}" onclick="addCheckedList(this.value, this.checked)"></td>
          </tr>
          {/foreach}
        </table><br/>
        <table width="100%" cellpadding="0" cellspacing="0">
          <tr><td align="right"><input type="button" class="w100" value="Xóa" onclick="deleteOrders()"></td></tr>
        </table>