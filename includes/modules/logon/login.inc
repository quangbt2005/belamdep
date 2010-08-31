<?php
/**************************************************************************************************/
/* Created on May 30, 2010                                                                        */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "customers/customers_db.inc" );
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
if($_SERVER['REQUEST_METHOD'] == 'POST'){
  $email = trim($_POST['txtEmail']);
  $password = $_POST['txtPassword'];

  $cus = CustomerLogin($email, $password);
  if($cus!==FALSE)
  {
    $_SESSION['logon']['id']    = $cus['customers_id'];
    $_SESSION['logon']['name']  = $cus['customers_lastname'];
    $_SESSION['logon']['email'] = $cus['customers_email_address'];

    header('Location: /taikhoan');
    exit;
  }
  $smarty->assign('error_count', 1);
  $smarty->assign('errs', array('Email hoặc password không đúng.'));
} else {
  unset($_SESSION['logon']);
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
$center_col = $smarty->fetch( "logon/login.tpl" );
?>
