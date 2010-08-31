<?php
/**************************************************************************************************/
/* Created on Dec 3, 2008                                                                         */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "products/products_db.inc" );
require_once( FUNCTIONS_PATH . "categories/categories_db.inc" );

$Specs       = FindProductsInSpecialCat();
$NewProducts = FindNewProducts();

$smarty->assign( "Specs", $Specs );
$smarty->assign( "NewProducts", $NewProducts );
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
$center_col = $smarty->fetch( "home/index.tpl" );
?>
