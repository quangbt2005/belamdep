<?php
chdir('..');
require_once('data/configs/application.inc');
require_once( LIB_PATH . 'YMAPI/jymengine.class.php' );

$engine = new JYMEngine(YM_CONSUMER_KEY, YM_CONSUMER_SECRET, YM_USER, YM_USER_PASS);
$engine->load_current_session();
$result = $engine->keep_alive_session();

echo $result . "\n";
echo date('Y-m-d H:i:s') . "\n";
?>