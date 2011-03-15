<?php
/**************************************************************************************************/
/* Created on March 15, 2011                                                                      */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "products/products_db.inc" );
require_once( FUNCTIONS_PATH . "DB.inc" );
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
Check_Admin();

$product_id = $Request['parameters'][':productid'];
$product    = LoadProductWithFullSaleOffInfo($product_id);
$errors     = array();
if(!empty($product)){
  if($_SERVER['REQUEST_METHOD'] == 'POST'){
    if(!Positive_Int_Check($_POST['txtSaleoffPrice']))
      $errors[] = 'Giá khuyến mãi không hợp lệ';

    if(count($errors) <= 0){
      $status = isset($_POST['chkSaleoff'])?'1':'0';
      if(!empty($product['specials_id'])){
        DB_Update(TBL_SALEOFF,
                array('specials_id'                 => $product['specials_id']),
                array('status'                      => $status,
                      'specials_new_products_price' => $_POST['txtSaleoffPrice']));
      } else {
      	DB_Insert(TBL_SALEOFF, array(
                                  'products_id'                 => $product_id,
                                  'specials_new_products_price' => $_POST['txtSaleoffPrice'],
                                  'specials_date_added'         => date('Y-m-d H:i:s'),
                                  'status'                      => $status,
        ));
      }
      $product['status'] = $status;
      $smarty->assign( "update_saleoff_ok", 1 );
    }
  }
} else {
	$errors[] = 'Không tìm thấy dữ liệu';
}

$smarty->assign( "errors_count", count($errors) );
$smarty->assign( "errors", $errors );
$smarty->assign( "product", $product );
$center_col = $smarty->fetch( "admin/products/saleoff_setting.tpl" );
?>
