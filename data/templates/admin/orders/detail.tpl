<form method="post">
<div class="content" style="width: 650px;margin:0 auto;">
  <div class="header1">Chi tiết đơn hàng</div>
    <div class="blu-container" style="padding: 10px;text-align: center">
      {if $errors_count > 0}
      {foreach from=$errors item=error}
      <div class="w100p error_field t-left">&nbsp;&nbsp;<img height="10" border="0" width="10" title=" Lỗi " alt="Lỗi" src="/images/icons/error.gif">&nbsp;{$error}</div>
      {/foreach}
      <br />
      {/if}
      <table cellpadding="2" cellspacing="0" width="100%">
        <tr>
          <th align="right" style="padding-right: 5px">Khách hàng</th>
          <td align="left" style="padding-left: 5px">{$order.customers_name|escape:"html"}</td>
          <th align="right" style="padding-right: 5px">Điện thoại</th>
          <td align="left" style="padding-left: 5px">{$order.phone|escape:"html"}</td>
        </tr>
        <tr>
          <th align="right" style="padding-right: 5px">Địa chỉ</th>
          <td align="left" style="padding-left: 5px" colspan="3">{$order.address|escape:"html"}</td>
        </tr>
        <tr>
          <th align="right" style="padding-right: 5px">Email</th>
          <td align="left" style="padding-left: 5px">{$order.email|escape:"html"}</td>
          <th align="right" style="padding-right: 5px">Ngày đặt hàng</th>
          <td align="left" style="padding-left: 5px">{$order.date_purchased}</td>
        </tr>
        <tr>
          <th align="right" style="padding-right: 5px">Cách thanh toán</th>
          <td align="left" style="padding-left: 5px">{$order.method}</td>
          <th align="right" style="padding-right: 5px">Hash</th>
          <td align="left" style="padding-left: 5px">{$order.hash}</td>
        </tr>
        <tr>
          <th align="right" style="padding-right: 5px" valign="top">Ghi chú</th>
          <td align="left" style="padding-left: 5px" colspan="3" valign="top">{$order.note|escape:"html"|nl2br}</td>
        </tr>
        <tr>
          <th align="right" style="padding-right: 5px">Trạng thái</th>
          <td align="left" style="padding-left: 5px" colspan="3">
            <input id="rad1" type="radio" name="orderstatus" value="1"{if $order.orders_status==1} checked="checked"{/if}>&nbsp;<label for="rad1">Chưa xử lý</label>
            <input id="rad2" type="radio" name="orderstatus" value="3"{if $order.orders_status==3} checked="checked"{/if}>&nbsp;<label for="rad2">Đã giao hàng</label>
          </td>
        </tr>
      </table><br/>
      <table cellpadding="0" cellspacing="0" width="100%" class="vlist">
        <tr>
          <th align="center" style="padding-right: 5px">Sản Phẩm</th>
          <th align="center" style="padding-right: 5px">Số luợng</th>
          <th align="center" style="padding-right: 5px">Đơn giá</th>
          <th align="center" style="padding-right: 5px">Thành tiền</th>
        </tr>
        {foreach from=$OrderProducts item=product}
        <tr>
          <td align="left" style="padding-right: 5px">{$product.products_name}</td>
          <td align="right" style="padding-right: 5px">{$product.products_quantity}</td>
          <td align="right" style="padding-right: 5px">{number_format number=$product.final_price}&nbsp;Đ</td>
          <td align="right" style="padding-right: 5px">{number_format number=$product.product_total}&nbsp;Đ</td>
        </tr>
        {/foreach}
      </table><br />
      <table cellpadding="2" cellspacing="0" width="100%">
        <tr><td align="right" style="color: red;font-weight: bold;font-size:12pt;">Tổng cộng: {number_format number=$order.value}&nbsp;Đ</td></tr>
      </table>
      <input type="submit" class="w80" value="Lưu thay đổi">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
      <input type="button" value="Đóng" onclick="window.close();">
    </div>
  </div>
</div>
</form>{if $update_order_ok==1}
<script type="text/javascript" language="javascript">
// window.opener.reloadOrdersList();
window.opener.location.reload();
alert('Đã lưu thay đổi');
// window.close();
</script>{/if}