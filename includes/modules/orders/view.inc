<?php
/**************************************************************************************************/
/* Created on Dec 4, 2008                                                                         */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "orders/orders_db.inc" );
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
$hash = $Request['parameters'][":hash"];
$order = LoadOrderByHash($hash);
if(!empty($order)){
	$OrderProducts = LoadOrderProducts($order['orders_id']);
}

$smarty->assign( "order", $order );
$smarty->assign( "OrderProducts", $OrderProducts );
$center_col = $smarty->fetch( "orders/view.tpl" );
?>
