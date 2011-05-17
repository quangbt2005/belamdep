<?php
chdir('..');
echo getcwd() . "\n";
echo date('Y-m-d H:i:s') . "\n";

require_once('includes/init.inc');
require_once(FUNCTIONS_PATH . 'orders/orders_db.inc');

$pending_count = CountYMPendingOrder();

echo ('pending_count: ' . "$pending_count\n");
// $pending_count = 3;
if($pending_count > 0){
	sendYM(array('quangbt2005','thuynguyenc2','labay11180'), '[Thông báo tự động]Có ' . $pending_count . ' đơn hàng chưa được xử lý');
	// sendYM(array('quangbt2005'), 'TÉT');
}
?>