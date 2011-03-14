<?php
/**************************************************************************************************/
/* Created on Dec 4, 2008                                                                         */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "DB.inc" );
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
if(! Check_Admin_Ajax()) exit;

$orderid = $Request['parameters'][':orderid'];

if(!empty($orderid)){
  $OrderID = explode('_', $orderid);

  /*
  $query = 'DELETE FROM orders WHERE orders_id IN(' . implode(',', $OrderID) . ')';
  P_MySQL_Real_Exec($query);
  $query = 'DELETE FROM orders_products WHERE orders_id IN(' . implode(',', $OrderID) . ')';
  P_MySQL_Real_Exec($query);
  $query = 'DELETE FROM orders_total WHERE orders_id IN(' . implode(',', $OrderID) . ')';
  P_MySQL_Real_Exec($query);
  $query = 'DELETE FROM orders_status_history WHERE orders_id IN(' . implode(',', $OrderID) . ')';
  P_MySQL_Real_Exec($query);
  */
  $query = "UPDATE orders SET deleted='1' WHERE orders_id IN(" . implode(',', $OrderID) . ')';
  P_MySQL_Real_Exec($query);
  $query = "UPDATE orders_products SET deleted='1' WHERE orders_id IN(" . implode(',', $OrderID) . ')';
  P_MySQL_Real_Exec($query);
  $query = "UPDATE orders_total SET deleted='1' WHERE orders_id IN(" . implode(',', $OrderID) . ')';
  P_MySQL_Real_Exec($query);
  $query = "UPDATE orders_status_history SET deleted='1' WHERE orders_id IN(" . implode(',', $OrderID) . ')';
  P_MySQL_Real_Exec($query);
}
?>
