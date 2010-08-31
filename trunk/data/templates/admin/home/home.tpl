<div id="bigBox">
  <div class="box">
    <div class="left"></div>
    <div class="right"></div>
    <div class="heading">
      <h1 class="bkg_dashboard">Dashboard</h1>
    </div>
    <div class="content">
      <div class="header1">Đơn hàng mới nhất</div>
      <div class="blu-container" style="padding: 10px;">
        <table width="100%" class="vlist" cellpadding="0" cellspacing="0">
          <tr>
            <th>Khách hàng</th>
            <th>Tổng tiền</th>
            <th>Ngày đặt hàng</th>
            <th>Tình trạng</th>
          </tr>
          {foreach from=$Orders item=order}
          <tr onMouseOver="this.style.backgroundColor='#71FFB8';" onMouseOut="this.style.backgroundColor='transparent';">
            <td>{$order.customers_name}</td>
            <td align="right">{number_format number=$order.value}&nbsp;VND</td>
            <td align="right">{$order.date_purchased}</td>
            <td>{$order.orders_status_name}</td>
          </tr>
          {/foreach}
        </table>
      </div>
    </div>
  </div>
</div>