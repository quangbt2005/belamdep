<?php
/**************************************************************************************************/
/* Created on Dec 14, 2008                                                                        */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "products/products_db.inc" );
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
$product_id = $Request['parameters'][':id'];
unset($_SESSION['cart']['product_count']);
unset($_SESSION['cart']['total_price']);

if(isset($_SESSION['cart'][$product_id])) {
  $_SESSION['cart'][$product_id]['quantity'] += 1;
  $_SESSION['cart'][$product_id]['total']    += (int)$_SESSION['cart'][$product_id]['price'];
}
else {
  $product = LoadProduct($product_id);
  if(!empty($product))
  {
    $_SESSION['cart'][$product_id]['quantity'] = 1;
    $_SESSION['cart'][$product_id]['id']       = $product_id;
    $_SESSION['cart'][$product_id]['name']     = $product['products_name'];
    $_SESSION['cart'][$product_id]['price']    = empty($product['special_price']) ?
                                                 $product['products_price'] :
                                                 $product['special_price'];
    $_SESSION['cart'][$product_id]['image']    = $product['products_image'];
    $_SESSION['cart'][$product_id]['total']    = (int)$_SESSION['cart'][$product_id]['price'] *
                                                 (int)$_SESSION['cart'][$product_id]['quantity'];
  }
}

$product_count = 0;
$total_price = 0;
foreach($_SESSION['cart'] as $key => $value)
{
  $product_count += (int)$value['quantity'];
  $total_price += (int)$value['total'];
}
$_SESSION['cart']['product_count'] = $product_count;
$_SESSION['cart']['total_price'] = $total_price;

header('Location: /giohang/xem');
exit;
?>
