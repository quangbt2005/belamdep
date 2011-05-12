<?php
require_once( '../data/configs/application.inc' );
require_once( FUNCTIONS_PATH . 'General.inc' );

@$msg = $_GET['msg'];
@$to = $_GET['to'];

if(empty($msg)) $msg = 'test send YM message ' . date('Y-m-d H:i:m:s');
if(empty($to)) $to = 'quangbt2005';

sendYM($to, $msg);
?>
