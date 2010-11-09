<?php
/**************************************************************************************************/
/* Created on Dec 4, 2008                                                                         */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "DB.inc" );
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
if(! Check_Admin_Ajax()) exit;

$product_id  = $Request['parameters'][':productid'];
$category_id = $Request['parameters'][':catid'];

if(!empty($product_id)){
  DB_Delete('products_to_categories', array(
                                            'products_id'   => $product_id,
                                            'categories_id' => $category_id
                                           )
           );
  DB_Delete('products_description', array('products_id' => $product_id));
  DB_Delete('products', array('products_id' => $product_id));
}
?>
