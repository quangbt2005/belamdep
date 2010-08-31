<?php
/**************************************************************************************************/
/* Created on May 30, 2010                                                                        */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "customers/customers_db.inc" );
require_once( FUNCTIONS_PATH . "DB.inc" );
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
if(empty($_SESSION['logon']['id'])){
  header('Location: /dangnhap');
}
if($_SERVER['REQUEST_METHOD'] == 'POST'){
  $oldpass    = $_POST['txtOldPass'];
  $newpass    = $_POST['txtNewPass'];
  $retype     = $_POST['txtRetypePass'];

  if(strlen($oldpass)<=0) $errs[] = 'Mật khẩu cũ không đúng.';

  if(count($errs)<=0){
    $dbpass = LoadCustomerPasswordById($_SESSION['logon']['id']);
    $stack = explode(':', $dbpass);

    if(sizeof($stack) != 2) $errs[] = 'Mật khẩu cũ không đúng.';
    elseif(md5($stack[1] . $oldpass) != $stack[0]) $errs[] = 'Mật khẩu cũ không đúng.';
  }

  if(count($errs)<=0)
    if(strlen($newpass)<=0) $errs[] = 'Vui lòng nhập mật khẩu mới.';
  if(count($errs)<=0)
    if($newpass != $retype) $errs[] = 'Nhập lại mật khẩu không đúng.';

  if(count($errs) <= 0)
  {
    DB_Update(TBL_CUSTOMERS, array('customers_id' => $_SESSION['logon']['id']), array(
        'customers_password'    =>  encrypt_password($newpass)));

    $_SESSION['flash']['account'][] = 'Mật khẩu đã được cập nhật thành công.';
    header('Location: /taikhoan');
    exit;
  }
  $smarty->assign( "is_post", 'true' );
  $smarty->assign( "error_count", count($errs) );
  $smarty->assign( "errs", $errs );
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
$center_col = $smarty->fetch( "account/edit_pass.tpl" );
?>
