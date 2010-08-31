<?php
/**************************************************************************************************/
/* Created on May 30, 2010                                                                        */
/**************************************************************************************************/
require_once( LIB_PATH . "P_Mail/P_Mail_Check_Function.inc" );
require_once( FUNCTIONS_PATH . "customers/customers_db.inc" );
require_once( FUNCTIONS_PATH . "DB.inc" );
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
if($_SERVER['REQUEST_METHOD'] == 'POST'){
  $errs = array();

  $gender     = $_POST['radGender'];
  $firstName  = trim($_POST['txtFirstName']);
  $lastName   = trim($_POST['txtLastName']);
  $dob        = trim($_POST['txtDOB']);
  $email      = trim($_POST['txtEmail']);
  $phone      = trim($_POST['txtPhone']);
  $street     = trim($_POST['txtStreet']);
  $district   = trim($_POST['txtDistrict']);
  $city       = trim($_POST['txtCity']);
  $password   = $_POST['txtPassword'];
  $repassword = $_POST['txtRetypePassword'];
  $seccode    = $_POST['txtCode'];
  $date_parts = explode('/', $dob);

  if(strlen($lastName) <= 0) $errs[] = 'Vui lòng nhập tên của bạn.';
  if(strlen($dob) > 0){
    if(!checkdate($date_parts[1], $date_parts[0], $date_parts[2]))
      $errs[] = 'Ngày sinh không hợp lệ.';
  }
  if(strlen($password) <= 0) $errs[] = 'Vui lòng nhập mật khẩu.';
  if($password != $repassword) $errs[] = 'Mật khẩu nhập lại không đúng.';
  if(strlen($email)>0)
    if(!P_Mail_Check($email)) $errs[] = 'Địa chỉ email không hợp lệ.';

  if(strtolower($seccode) != strtolower($_SESSION['account']['seccode']))
    $errs[] = 'Mã an toàn không đúng.';

  if(count($errs) <= 0){
    if(IsExistedCustomer($email)) $errs[] = 'Email này đã được đăng ký.';
  }

  if(count($errs) <= 0)
  {
    $customer_id = DB_Insert(TBL_CUSTOMERS, array(
        'customers_gender'        =>  $gender,
        'customers_firstname'     =>  $firstName,
        'customers_lastname'      =>  $lastName,
        'customers_dob'           =>  ($date_parts[2] . str_pad($date_parts[1],2,'0',STR_PAD_LEFT) . str_pad($date_parts[0],2,'0',STR_PAD_LEFT)),
        'customers_email_address' =>  $phone,
        'customers_telephone'     =>  $phone,
        'customers_password'      =>  encrypt_password($password),));
    DB_Insert(TBL_ADDRESS, array(
        'entry_street_address'  =>  $street,
        'entry_state'           =>  $district,
        'entry_city'            =>  $city,
        'customers_id'          =>  $customer_id,));

    header('Location: /taikhoan/dangky/thanhcong');
    exit;
  }

  $smarty->assign( "is_post", 'true' );
  $smarty->assign( "error_count", count($errs) );
  $smarty->assign( "errs", $errs );
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
$center_col = $smarty->fetch( "account/register.tpl" );
?>
