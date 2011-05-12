<?php
chdir('..');
require_once('includes/init.inc');
require_once(FUNCTIONS_PATH . 'orders/orders_db.inc');

// $pending_count = CountPendingOrders();
$pending_count = 3;
if($pending_count > 0){
	// sendYM(array('quangbt2005'), '[Thông báo tự động]Nhắc nhở: Còn ' . $pending_count . ' đơn hàng chưa được xử lý');
	sendYM(array('quangbt2005'), 'TÉT');
}
?>