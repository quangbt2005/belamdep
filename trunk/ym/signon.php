<?php
require_once( '../data/configs/application.inc' );
require_once( LIB_PATH . 'YMAPI/jymengine.class.php' );

$engine = new JYMEngine(YM_CONSUMER_KEY, YM_CONSUMER_SECRET, YM_USER, YM_USER_PASS);

echo YM_CONSUMER_KEY . '<br>';
echo YM_CONSUMER_SECRET . '<br>';
echo YM_USER . '<br>';
echo YM_USER_PASS . '<br>';

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
