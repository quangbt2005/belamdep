<?php
/**************************************************************************************************/
/* Created on Dec 4, 2008                                                                         */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "orders/orders_db.inc" );
require_once( FUNCTIONS_PATH . "DB.inc" );
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
Check_Admin();

$orderid  = $Request['parameters'][":orderid"];
$order = LoadOrder($orderid);
if(!empty($order)){
  if($_SERVER['REQUEST_METHOD'] == 'POST'){
    DB_Update(TBL_ORDERS,
            array('orders_id' => $order['orders_id']),
            array('orders_status' => $_POST['orderstatus']));
    $order['orders_status'] = $_POST['orderstatus'];
    $smarty->assign( "update_order_ok", 1 );
  }
  $OrderProducts = LoadOrderProducts($order['orders_id']);
}

$smarty->assign( "order", $order );
$smarty->assign( "OrderProducts", $OrderProducts );
$center_col = $smarty->fetch( "admin/orders/detail.tpl" );
?>
