<?php
/**************************************************************************************************/
/* Created on July 2, 2010                                                                        */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "categories/categories_db.inc" );
require_once( FUNCTIONS_PATH . "categories/create_html_select_categories.inc" );
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
$category_id = $Request['parameters'][':catid'];
$html_select_categories = create_html_select_categories($category_id);

$smarty->assign('html_select_categories', $html_select_categories);

$center_col = $smarty->fetch( "admin/products/addproduct.tpl" );
?>
