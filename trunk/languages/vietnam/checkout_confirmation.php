<?php
/*
  $Id: checkout_confirmation.php,v 1.24 2003/02/06 17:38:16 thomasamoulton Exp $

  osCommerce, Open Source E-Commerce Solutions
  http://www.oscommerce.com

  Copyright (c) 2003 osCommerce

  Released under the GNU General Public License
*/

define('NAVBAR_TITLE_1', 'Hoàn tất');
define('NAVBAR_TITLE_2', 'Xác nhận');

define('HEADING_TITLE', 'Xác nhận đơn hàng');

define('HEADING_DELIVERY_ADDRESS', 'Địa chỉ giao hàng');
define('HEADING_SHIPPING_METHOD', 'Phương thức vận chuyển');
define('HEADING_PRODUCTS', 'Sản phẩm');
define('HEADING_TAX', 'Thuế');
define('HEADING_TOTAL', 'Tổng cộng');
define('HEADING_BILLING_INFORMATION', 'Thông tin hóa đơn');
define('HEADING_BILLING_ADDRESS', 'Địa chỉ nhận hóa đơn');
define('HEADING_PAYMENT_METHOD', 'Phương thức thanh toán');
define('HEADING_PAYMENT_INFORMATION', 'Thông tin thanh toán');
define('HEADING_ORDER_COMMENTS', 'Ghi chú cho đơn hàng của bạn');
define('ENTRY_HO_TEN', 'Họ và Tên');
define('ENTRY_DIA_CHI', 'Địa chỉ giao hàng');
define('ENTRY_DIEN_THOAI', 'Điện thoại');
define('ENTRY_EMAIL', 'Email');
define('ENTRY_GHI_CHU', 'Ghi chú');
define('ENTRY_PAYMENT_METHOD', 'Phương thức thanh toán');

define('TEXT_EDIT', 'Sửa');
define('HEADING_NGUOI_THANH_TOAN', 'Người thanh toán');
define('MA_AN_TOAN_EXPLAIN', '(Nếu tất cả thông tin trên đều đúng, xin hãy nhập mã an toàn và xác nhận)');
define('ENTRY_SECURITY_CODE_ERROR', 'Mã an toàn không đúng.');

define('ERROR_ORDER_DOES_NOT_EXIST', 'Đơn hàng không tồn tại.');
define('SUCCESS_ORDER_UPDATED', 'Đơn hàng đã được thay đổi.');
define('WARNING_ORDER_NOT_UPDATED', 'Đơn hàng không có gì thay đổi.');

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
define('EMAIL_TEXT_SEPARATOR', '------------------------------------------------------------------------------<br>');
?>
