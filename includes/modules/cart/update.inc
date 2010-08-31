<?php
/**********************************************************************/
/* Created on Dec 14, 2008                                            */
/**********************************************************************/
require_once( FUNCTIONS_PATH . "products/products_db.inc" );
// ------------------------------------------------------------------ //
//
// ------------------------------------------------------------------ //
$Cart = $_SESSION["cart"];
unset($Cart['product_count']);
unset($Cart['total_price']);

if($_SERVER['REQUEST_METHOD']=='POST' &&
    empty( $Cart ) == FALSE )
{
  $delete   = $_POST["cart_delete"];
  $quantity = $_POST["cart_quantity"];

  $index = 0;
  foreach($Cart as $key => $value)
  {
    if((int)$quantity[$index] != (int)$Cart[$key]['quantity']){
      $Cart[$key]['quantity'] = (int)$quantity[$index];
      if((int)$Cart[$key]['quantity'] > 0) {
        $Cart[$key]['total']  = (int)$Cart[$key]['quantity'] * (int)$Cart[$key]['price'];
      }
      else{
        $delete[] = $key;
      }
    }
    $index++;
  }
  foreach($delete as $value)
  {
    unset($Cart[$value]);
  }

  $product_count = 0;
  $total_price = 0;
  foreach($Cart as $key => $value)
  {
    $product_count += (int)$value['quantity'];
    $total_price += (int)$value['total'];
  }
  $Cart['product_count'] = $product_count;
  $Cart['total_price'] = $total_price;

  $_SESSION['cart'] = $Cart;
}
header('Location: /giohang/xem');
exit;
?>
