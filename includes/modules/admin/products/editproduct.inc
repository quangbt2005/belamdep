<?php
/**************************************************************************************************/
/* Created on July 2, 2010                                                                        */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "categories/categories_db.inc" );
require_once( FUNCTIONS_PATH . "categories/create_html_select_categories.inc" );
require_once( FUNCTIONS_PATH . "products/products_db.inc" );
require_once( FUNCTIONS_PATH . "DB.inc" );
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
Check_Admin();
$product_id = $Request['parameters'][':productid'];
if(!empty($product_id)){
  $product  = LoadProduct( $product_id );
}
if(!empty($product)){
  $errors = array();

  if($_SERVER['REQUEST_METHOD'] == 'POST'){
    $product_category    = $_POST['drpProductCategory'];
    $product_price       = $_POST['txtProductPrice'];
    $product_name        = $_POST['txtProductName'];
    $product_description = $_POST['txtProductDescription'];
    $product_quantity    = $_POST['txtProductQuantity'];

    if(empty($product_name)) $errors[] = 'Vui lòng nhập tên sản phẩm';
    if(empty($product_price)) $errors[] = 'Vui lòng nhập giá sản phẩm';
    else if(!Positive_Int_Check($product_price))
      $errors[] = 'Giá sản phẩm không hợp lệ';
    if(!empty($product_quantity) && !Positive_Int_Check($product_quantity))
      $errors[] = 'Số lượng sản phẩm không hợp lệ';

    if(count($errors) <= 0){
      $basefilename = basename($_FILES['txtProductImage']['name']);
      if(!empty($basefilename)){
        if(!empty($product['products_image'])){
        	$oldimage = SYS_IMAGES_PATH . $product['products_image'];
          unlink($oldimage);
        }

        $upload_dir = SYS_IMAGES_PATH . $basefilename;
        move_uploaded_file($_FILES['txtProductImage']['tmp_name'], $upload_dir);

        DB_Update('products', array('products_id' => $product_id),array(
          'products_quantity'      => $product_quantity,
          'products_price'         => $product_price,
          'products_image'         => $basefilename,
          'products_last_modified' => date('Y-m-d H:i:s'),
        ));
      } else {
      	DB_Update('products', array('products_id' => $product_id),array(
          'products_quantity'      => $product_quantity,
          'products_price'         => $product_price,
          'products_last_modified' => date('Y-m-d H:i:s'),
        ));
      }

      DB_Update('products_description', array('products_id' => $product_id), array(
        'products_name'        => $product_name,
        'products_description' => $product_description,
      ));
      DB_Update('products_to_categories', array('products_id' => $product_id), array(
        'categories_id'        => $product_category,
      ));


      $_SESSION['flash']['update_product_ok'] = '1';
      header("Location: /admin/products/edit/" . $product_id);
      exit;
    }
  } else {
    if($_SESSION['flash']['update_product_ok'] == '1'){
      $smarty->assign('update_product_ok', '1');
      unset($_SESSION['flash']['update_product_ok']);
    } else {
      $product_price       = $product['products_price'];
      $product_name        = $product['products_name'];
      $product_description = $product['products_description'];
      $product_quantity    = $product['txtProductQuantity'];
    }
  }

  $html_select_categories = create_html_select_categories($product['categories_id']);

  $smarty->assign('txtProductName', $product_name);
  $smarty->assign('txtProductPrice', (int)$product_price);
  $smarty->assign('txtProductDescription', $product_description);
  $smarty->assign('txtProductQuantity', $product_quantity);
  $smarty->assign('txtProductSPPrice', $product['special_price']);
  $smarty->assign('txtProductImage', $product['products_image']);

  $smarty->assign('showing_category', $product['categories_id']);
  $smarty->assign('errors_count', count($errors));
  $smarty->assign('errors', $errors);
  $smarty->assign('html_select_categories', $html_select_categories);
}

$center_col = $smarty->fetch( "admin/products/editproduct.tpl" );
?>
