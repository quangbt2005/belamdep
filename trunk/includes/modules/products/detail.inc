<?php
/**************************************************************************************************/
/* Created on Dec 4, 2008                                                                         */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "products/products_db.inc" );
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
$product_id = $Request['parameters'][":productid"];
$product = LoadProduct($product_id);
// pd($product_id);
// ---------------------------------------------------------------------------------------------- //
// $current_cat_id has been loaded in leftmenu script ( leftmenu/menu1.inc )
// ---------------------------------------------------------------------------------------------- //
// $current_cat_id = Find_CategoryID_Of_Product($product_id);

$OtherProductsList = FindNewProducts($current_cat_id, 0, 1000);
// pd($OtherProductsList);
$smarty->assign( "product", $product );
$smarty->assign( "OtherProductsList", $OtherProductsList );
$center_col = $smarty->fetch( "products/detail.tpl" );
?>
