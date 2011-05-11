<?php
require_once ('jymengine.class.php');

$username = 'belamdep';
$password = 'simple303';
$consumer = 'dj0yJmk9NmE3OVIwYmQyU2dZJmQ9WVdrOWRHdFVZV2hITnpBbWNHbzlNVEUyTXpFMU9USTJNZy0tJnM9Y29uc3VtZXJzZWNyZXQmeD0yNg--';
$consumer_secret = '3a0f3ac40cfea6ca52841d707565a48e6318aa51';

$engine = new JYMEngine($consumer, $consumer_secret, $username, $password);

$engine->fetch_request_token();
$engine->fetch_access_token();

$signon = $engine->signon('', -1);
if(!$signon){
$engine->fetch_request_token();
$engine->fetch_access_token();
$signon = $engine->signon('', -1);
}
if($signon){
$engine->send_message('quangbt2005', json_encode('TEST'));
$engine->signoff();
}
?>