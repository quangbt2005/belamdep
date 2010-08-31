<?php
/**********************************************************************/
/* Created on Dec 7, 2008                                             */
/**********************************************************************/
require_once( FUNCTIONS_PATH . "products/products_db.inc" );
// ------------------------------------------------------------------ //
//
// ------------------------------------------------------------------ //
$Cart          = $_SESSION["cart"];
$Cart_Products = array();
$has_product   = FALSE;
unset($Cart['product_count']);
unset($Cart['total_price']);
if( empty( $Cart ) == FALSE ) {
  $has_product = TRUE;
}
// ------------------------------------------------------------------ //
//
// ------------------------------------------------------------------ //
$smarty->assign( "has_product", $has_product );
$smarty->assign( "Cart", $Cart );
$center_col = $smarty->fetch( "cart/view.tpl" );
?>
