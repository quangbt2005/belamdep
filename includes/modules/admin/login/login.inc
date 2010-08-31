<?php
/**************************************************************************************************/
/* Created on June 30, 2010                                                                       */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "administrators/administrators_db.inc" );
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
if($_SERVER['REQUEST_METHOD'] == 'POST'){
  $errs = array();

  $user_name = trim($_POST['username']);
  $password  = trim($_POST['password']);

  if($user_name != '' && $password != ''){
    $user = LoadAdministrator($user_name);
    if(!empty($user)){
      $check_pass = validate_password($password, $user['user_password']);
      if($check_pass){
        $_SESSION['admin']['id']   = $user['id'];
        $_SESSION['admin']['name'] = $user['user_name'];
// pd($_SESSION);
        header('Location: /admin/dashboard');
        exit;
      } else {
        $errs[] = 'User name hoặc mật khẩu không đúng.';
      }
    } else {
      if($user_name == '') $errs[] = 'Vui lòng nhập UserName.';
      if($password == '')  $errs[] = 'Vui lòng nhập Password.';
    }
  }

  $smarty->assign( "is_post", 'true' );
  $smarty->assign( "error_count", count($errs) );
  $smarty->assign( "errs", $errs );
}
$center_col = $smarty->fetch( "admin/login/login.tpl" );
?>
