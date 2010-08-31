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
  $gender     = $_POST['radGender'];
  $firstName  = $_POST['txtFirstName'];
  $lastName   = $_POST['txtLastName'];
  $dob        = $_POST['txtDOB'];
  $phone      = $_POST['txtPhone'];
  $street     = $_POST['txtStreet'];
  $district   = $_POST['txtDistrict'];
  $city       = $_POST['txtCity'];

  $date_parts = explode('/', $dob);

  if(strlen($lastName) <= 0) $errs[] = 'Vui lòng nhập tên của bạn.';
  if(strlen($dob) > 0){
    if(!checkdate($date_parts[1], $date_parts[0], $date_parts[2]))
      $errs[] = 'Ngày sinh không hợp lệ.';
  }

  if(count($errs) <= 0)
  {
    DB_Update(TBL_CUSTOMERS, array('customers_id' => $_SESSION['logon']['id']), array(
        'customers_gender'      =>  $gender,
        'customers_firstname'   =>  $firstName,
        'customers_lastname'    =>  $lastName,
        'customers_dob'         =>  ($date_parts[2] . str_pad($date_parts[1],2,'0',STR_PAD_LEFT) . str_pad($date_parts[0],2,'0',STR_PAD_LEFT)),
        'customers_telephone'   =>  $phone));
    DB_Update(TBL_ADDRESS, array('customers_id' => $_SESSION['logon']['id']), array(
        'entry_street_address'  =>  $street,
        'entry_state'           =>  $district));

    $_SESSION['flash']['account'][] = 'Tài khoản đã được cập nhật thành công.';
    header('Location: /taikhoan');
    exit;
  }
} else {
  $customer = LoadCustomerById($_SESSION['logon']['id']);
  $smarty->assign('customer', $customer);
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
$center_col = $smarty->fetch( "account/edit_info.tpl" );
?>
