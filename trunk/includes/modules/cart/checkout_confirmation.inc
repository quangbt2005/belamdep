<?php
/**************************************************************************************************/
/* Created on Dec 7, 2008                                                                         */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "DB.inc" );
define('EMAIL_TEXT_SUBJECT', 'Đơn hàng tại BELAMDEP.COM');
define('EMAIL_TEXT_ORDER_TEXT', "Xin chào bạn.<br>Cảm ơn bạn đã xem và đặt hàng tại website của chúng tôi.<br><b><h1>Chi tiết đơn hàng:</h1></b>");
define('EMAIL_TEXT_DATE_ORDERED', "<span style=\"color:blue;\">Ngày đặt hàng: %s</span><br>");
define('EMAIL_TEXT_TOTAL', "<span style=\"color:red;\"><h2>Tổng cộng: %s VND</h2></span><br>");
define('EMAIL_TEXT_DELIVERY_ADDRESS', "<span style=\"color:blue;\">Địa chỉ giao hàng: %s</span><br>");
define('EMAIL_TEXT_DELIVERY_PHONE', "<span style=\"color:blue;\">Điện thoại liên hệ: %s</span><br>");
define('EMAIL_TEXT_PAYMENT_METHOD', "<span style=\"color:blue;\">Phương thức thanh toán: %s</span><br>");
define('EMAIL_TEXT_NGUOI_THANH_TOAN', "<span style=\"color:blue;\">Người thanh toán: </span><b style=\"color:red\">%s</b><br>");
define('EMAIL_TEXT_NOTE', "<span style=\"color:blue;\">Ghi chú khác: %s</span><br>");
define('EMAIL_TEXT_SUCCESS', '<br>Đơn hàng của bạn đã được chúng tôi ghi nhận. Chúng tôi sẽ liên lạc với bạn trong thời gian sớm nhất có thể để thảo luận về việc giao/nhận hàng.<br>');
define('EMAIL_TEXT_CONTACT', '<br>BELAMDEP.COM<br>' . STORE_ADDRESS . '<br>MB: ' . STORE_PHONE_1 . '<br>Email: ' . STORE_EMAIL_1);
define('DATE_FORMAT_LONG', '%A %d %B, %Y');
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
if( !isset( $_SESSION["checkout"] ) ) {
  header("Location: /giohang/xem");
  exit;
}
$errs = array();
if($_SERVER['REQUEST_METHOD'] == 'POST'){
  $code = $_POST['txtCode'];

  if(strtolower($code) == strtolower($_SESSION['checkout']['seccode'])){
    $order_id = DB_Insert(TBL_ORDERS, array(
        'customers_id'              =>	$_SESSION['logon']['id'],
        'customers_name'            =>	$_SESSION['checkout']['name'],
        'customers_street_address'  =>  $_SESSION['checkout']['address'],
        'customers_email_address'   =>  $_SESSION['checkout']['email'],
        'customers_telephone'       =>  $_SESSION['checkout']['phone'],
        'payment_method'            =>  $_SESSION['checkout']['method'],
        'note'                      =>  $_SESSION['checkout']['note'],
        'date_purchased'            =>  date('Y-m-d H:i:s'),
        'orders_status'             =>  '1',));

    DB_Insert(TBL_ORDERS_TOTAL, array(
        'orders_id'    =>  $order_id,
        'title'        =>  'Tổng cộng',
        'text'         =>  '<b>' . number_format($_SESSION['cart']['total_price']) . '&nbsp;VND</b>',
        'value'        =>  $_SESSION['cart']['total_price'],
        'class'        =>  'ot_total',
        'sort_order'   =>  '4'));

    DB_Insert(TBL_ORDERS_STATUS_HISTORY, array(
        'orders_id'         =>  $order_id,
        'orders_status_id'  =>  '1',
        'date_added'        =>  'now()',
        'customer_notified' =>  '1',
        'comments'          =>  ''));

    foreach($_SESSION['cart'] as $product)
    {
      if(!isset($product['id'])) continue;
      DB_Insert(TBL_ORDERS_PRODUCTS, array(
        'orders_id'         =>  $order_id,
        'products_id'       =>  $product['id'],
        'products_name'     =>  $product['name'],
        'products_price'    =>  $product['price'],
        'final_price'       =>  $product['price'],
        'products_tax'      =>  0,
        'products_quantity' =>  $product['quantity']));
    }

    // lets start with the email confirmation
    $email_order = EMAIL_TEXT_ORDER_TEXT;

    $table = '<table border="1" cellspacing="0" cellpadding="0"><tr style="padding: 10px; font-weight: bold; color: #000000; background-color: #cccccc;"><th style="padding: 10px; color: blue;">Sản phẩm</th><th style="padding: 10px; color: blue;">Đơn giá</th><th style="padding: 10px; color: blue;">Số lượng</th><th style="padding: 10px; color: blue;">Thành tiền</th><th style="padding: 10px; color: blue;">Tùy chọn khác</th></tr>';

    foreach($_SESSION['cart'] as $product)
    {
      if(isset($product['id'])){
        $table .= '<tr style="padding: 10px; color: blue;">';
        $table .= '<td style="padding: 10px; color: blue;">' . strip_tags($product['name']) . '</td>';
        $table .= '<td style="padding: 10px; color: blue;" align="right">' . number_format($product['price']) . ' VND</td>';
        $table .= '<td style="padding: 10px; color: blue;" align="right">' . strip_tags($product['quantity']) . '</td>';
        $table .= '<td style="padding: 10px; color: blue;" align="right">' . number_format($product['total']) . ' VND</td>';
        $table .= '<td style="padding: 10px; color: blue;">&nbsp;</td>';
        $table .= '</tr>';
      }
    }
    $table .= '</table>';
    $email_order .= $table;

    $email_order .= sprintf(EMAIL_TEXT_TOTAL, number_format($_SESSION['cart']['total_price']));
    $email_order .= sprintf(EMAIL_TEXT_DATE_ORDERED, strftime(DATE_FORMAT_LONG));
    $email_order .= sprintf(EMAIL_TEXT_NGUOI_THANH_TOAN, $_SESSION['checkout']['name']);
    $email_order .= sprintf(EMAIL_TEXT_DELIVERY_ADDRESS, $_SESSION['checkout']['address']);
    $email_order .= sprintf(EMAIL_TEXT_DELIVERY_PHONE, $_SESSION['checkout']['phone']);
    $email_order .= sprintf(EMAIL_TEXT_PAYMENT_METHOD, $_SESSION['checkout']['method']);
    $email_order .= sprintf(EMAIL_TEXT_NOTE, $_SESSION['checkout']['note']);
    $email_order .= EMAIL_TEXT_SUCCESS;
    $email_order .= EMAIL_TEXT_CONTACT;

    mailSMTP('BELAMDEP.COM', 'admin@belamdep.com', $_SESSION['checkout']['email'], NULL, NULL, 'Đơn hàng từ BELAMDEP.COM', $email_order);

    unset($_SESSION['checkout']);
    unset($_SESSION['cart']);

    header('Location: /thanhtoan/hoantat');
    exit;
  } else {
    $errs[] = 'Mã an toàn không đúng.';
  }

  $smarty->assign( "error_count", count($errs) );
  $smarty->assign( "errs", $errs );
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
$center_col = $smarty->fetch( "cart/checkout_confirmation.tpl" );
?>