<?php
/**************************************************************************************************/
/* Created on Dec 7, 2008                                                                         */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "DB.inc" );
require_once( LIB_PATH . "PaymentGates/baokim/BaoKimPayment.php" );
require_once( LIB_PATH . "PaymentGates/nganluong/nganluong.php" );

$gateway = strtolower($Request['parameters'][":paymntgw"]);
$hash = $Request['parameters'][":hash"];
$smarty->assign('hash', $hash);

if($gateway == 'bk'){
  $smarty->assign('gateway', 'Bảo Kim');
  $smarty->assign('gateway_url', 'http://baokim.vn');

  $bk_pament = new BaoKimPayment();
  $check = $bk_pament->verifyResponseUrl($_GET);

  if(!$check){
    // $smarty->assign('payment_gateway_return_error', 1);
  }
} elseif($gateway == 'nl'){
  $smarty->assign('gateway', 'Ngân Lượng');
  $smarty->assign('gateway_url', 'http://nganluong.vn');

  $nl_payment = new NL_Checkout();

  $transaction_info = $_GET['transaction_info'];
  $payment_id       = $_GET['payment_id'];
  $payment_type     = $_GET['payment_type'];
  $order_code       = $_GET['order_code'];
  $price            = $_GET['price'];
  $error_text       = $_GET['error_text'];
  $secure_code      = $_GET['secure_code'];
  $check            = $nl_payment->verifyPaymentUrl($transaction_info, $order_code, $price, $payment_id, $payment_type, $error_text, $secure_code);
  // $check            = false;

  $log = sprintf('transaction_info: %s@payment_id: %s@payment_type: %s@order_code: %s@price: %s@error_text: %s@secure_code: %s@check_result: %s',
         $transaction_info, $order_code, $price, $payment_id, $payment_type, $error_text, $secure_code,(string)$check);

  DB_Insert('payment_gateway_log', array(
              'payment_gateway' => 'NL',
              'type'            => 'return',
              'content'         => $log,
              'created_date'    => date('Y-m-d H:i:s'),
            ));
  if(!$check){
  	// $smarty->assign('payment_gateway_return_error', 1);
  }
}

if(isset($_SESSION['checkout'])){
	unset($_SESSION['checkout']);
  unset($_SESSION['cart']);
}

$center_col = $smarty->fetch( "cart/checkout_success.tpl" );
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //

?>