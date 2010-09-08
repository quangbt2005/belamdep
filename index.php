<?php
error_reporting(0);
// error_reporting(E_ALL);

require_once( "includes/init.inc" );
require_once( "includes/mysql.inc" );
// ---------------------------------------------------------------------------------------------- //
$Response = Parse__URL();
// pd($Request);
if($Response['is_ajax']==FALSE) {
  $layout  = Layout( $Response["response_module"] );
  // -------------------------------------------------------------------------------------------- //
  require( $Response['header_script'] );
  require( $Response['left_script'] );
  require( $Response['center_script'] );
  require( $Response['right_script'] );
  require( $Response['footer_script'] );

  $smarty->assign( 'title',      $Response['page_title'] );
  $smarty->assign( 'header',     $header );
  $smarty->assign( 'left_col',   $left_col );
  $smarty->assign( 'center_col', $center_col );
  $smarty->assign( 'right_col',  $right_col );
  $smarty->assign( 'footer',     $footer );

  $smarty->display( $layout );
}
else {
  require( $Response['center_script'] );
}
?>