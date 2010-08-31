<?php
/**************************************************************************************************/
/* Created on Dec 7, 2008                                                                         */
/**************************************************************************************************/
require_once( LIB_PATH . "P_Mail/P_Mail_Check_Function.inc" );
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
if( empty( $_SESSION['cart']['product_count'] ) ) {
  header("Location: /giohang/xem");
  exit;
}
$errs = array();
if($_SERVER['REQUEST_METHOD'] == 'POST'){
  $name    = $_POST['txtName'];
  $address = $_POST['txtAddress'];
  $phone   = $_POST['txtPhone'];
  $email   = $_POST['txtEmail'];
  $method  = $_POST['drpMethod'];
  $note    = $_POST['txtNote'];

  if(strlen($name)<=0)    $errs[] = 'Vui lòng nhập họ và tên.';
  if(strlen($address)<=0) $errs[] = 'Vui lòng nhập địa chỉ giao hàng.';
  if(strlen($phone)<=0)   $errs[] = 'Vui lòng nhập số điện thoại liên lạc.';
  if(strlen($email)<=0)   $errs[] = 'Vui lòng nhập địa chỉ email.';
  if(strlen($email)>0)
    if(!P_Mail_Check($email)) $errs[] = 'Địa chỉ email không đúng.';

  if(count($errs)==0)
  {
    $_SESSION['checkout']['name']    = $name;
    $_SESSION['checkout']['address'] = $address;
    $_SESSION['checkout']['phone']   = $phone;
    $_SESSION['checkout']['email']   = $email;
    $_SESSION['checkout']['method']  = $method;
    $_SESSION['checkout']['note']    = $note;

    header('Location: /thanhtoan/xacnhan');
    exit;
  }

  $smarty->assign( "is_post", 'true' );
  $smarty->assign( "error_count", count($errs) );
  $smarty->assign( "errs", $errs );
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
$center_col = $smarty->fetch( "cart/checkout.tpl" );
?>
