<?php
chdir('..');
require_once('data/configs/application.inc');
require_once( LIB_PATH . 'YMAPI/jymengine.class.php' );

$engine = new JYMEngine(YM_CONSUMER_KEY, YM_CONSUMER_SECRET, YM_USER, YM_USER_PASS);

$engine->fetch_request_token();
$engine->fetch_access_token();

$signon = $engine->signon();
if(!$signon){
  $engine->fetch_request_token();
  $engine->fetch_access_token();
  $signon = $engine->signon();
}
if($signon){
  $engine->save_current_session();
}
?>
