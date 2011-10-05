<?php
ob_start("ob_gzhandler");
include_once('data/configs/application.inc');
$valid_ext = array('js','css');

$file = $_GET['f'];
$type = $_GET['t'];

$fileinfo = pathinfo($file);
$fileext = strtolower($fileinfo['extension']);
if(in_array($fileext, $valid_ext)){
	if($type == 'js')
	  $path = SYS_ROOT . 'jscripts/';
	elseif($type == 'css')
	  $path = SYS_ROOT . 'style/';
	else $path = SYS_ROOT;

	$file = str_replace('|', '/', $file);
	$fullfile = $path . $file;

	if(is_file($fullfile) && !is_dir($fullfile)){
	  readfile($fullfile);
	} else {
	  echo 'File not found';
	}
} else {
	echo 'File not found';
}
ob_flush();
?>