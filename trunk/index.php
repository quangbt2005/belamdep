<?php
error_reporting(0);
// error_reporting(E_ALL);

require_once( "includes/init.inc" );
require_once( "includes/mysql.inc" );
// ---------------------------------------------------------------------------------------------- //
$Request = Parse__URL();
// p($Request);
if($Request['is_ajax']==FALSE) {
  $layout  = Layout( $Request["response_module"] );
  // -------------------------------------------------------------------------------------------- //
  require( $Request['header_script'] );
  require( $Request['left_script'] );
  require( $Request['center_script'] );
  require( $Request['right_script'] );
  require( $Request['footer_script'] );

  $smarty->assign( 'title',      $Request['page_title'] );
  $smarty->assign( 'header',     $header );
  $smarty->assign( 'left_col',   $left_col );
  $smarty->assign( 'center_col', $center_col );
  $smarty->assign( 'right_col',  $right_col );
  $smarty->assign( 'footer',     $footer );

  $smarty->assign( 'Request',    $Request );
  $smarty->display( $layout );
}
else {
  require( $Request['center_script'] );
}
?>