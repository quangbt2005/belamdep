<div id="bigBox">
  <div class="box">
    <div class="left"></div>
    <div class="right"></div>
    <div class="heading">
      <h1 class="bkg_dashboard">Đặt Hàng</h1>
    </div>
    <div class="content">
      <div class="header1">Đơn hàng mới nhất</div>
      <div class="blu-container" style="padding: 10px;" id="divList">
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
          <tr onMouseOver="this.style.backgroundColor='#71FFB8';" onMouseOut="this.style.backgroundColor='transparent';" style="cursor: hand;cursor: pointer;" ondblclick="openOrderDetailPopup({$order.orders_id})">
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
      </div>
    </div>
  </div>
</div>
{literal}
<script type="text/javascript" language="javascript">
var checkedList = '';
var popupWidth  = 800;
var popupHeight = 600;

function addCheckedList(id, checked){
  if(checked){
    checkedList += ('_' + id);
  } else {
    checkedList = checkedList.replace('_' + id, '');
  }

}
function deleteOrders(){
  checkedList = trim(checkedList, '_');
  if(checkedList != ''){
    if(confirm('Bạn có chắc muốn xóa những đơn hàng đã chọn ?')){
      var url = "/admin/orders/" + checkedList + "/detele";
      $.get(url, function(data){
        update_orders_list();
	  });
	}
  } else {alert('Không có đơn hàng nào được chọn !')}
}
function openOrderDetailPopup(order_id){
  var url = '/admin/orders/' + order_id + '/detail';

  var topPos = 150;
  var leftPos = 310;

  var popup = window.open(url, 'Chi_tiet_don_hang',"resizable=no,menubar=no,toolbar=no,location=no,width=" + popupWidth + ",height=" + popupHeight + ",left="+leftPos+",top="+topPos);
}
function reloadOrdersList(){
  $.get("/admin/orders/getlist", function(data){
    $("#divList").html(data);
  });
}
</script>
{/literal}