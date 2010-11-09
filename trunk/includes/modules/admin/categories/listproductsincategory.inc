<?php
/**************************************************************************************************/
/* Created on Dec 4, 2008                                                                         */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "categories/categories_db.inc" );
require_once( FUNCTIONS_PATH . "products/products_db.inc" );
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
if(! Check_Admin_Ajax()) exit;

$cat_id        = $Request['parameters'][':catid'];
$Products_List = List_Product_By_Category_Exactly($cat_id);
$html          = '';

if(count($Products_List) > 0)
{
  $smarty->assign( "Products_List", $Products_List );
  $html = $smarty->fetch( "admin/categories/listproductsincategory.tpl" );
}

echo $html;
?>
