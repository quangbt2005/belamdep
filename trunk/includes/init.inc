<?php
/**************************************************************************************************/
/* Created on Nov 29, 2008                                                                        */
/**************************************************************************************************/
require_once( "data/configs/application.inc" );
require_once( "data/configs/db.inc" );
require_once( "data/configs/smarty.inc" );
require_once( "data/configs/maps.inc" );
// ---------------------------------------------------------------------------------------------- //
// Common functions
// ---------------------------------------------------------------------------------------------- //
require_once( INCLUDES_PATH  . "mysql.inc" );
include_once( FUNCTIONS_PATH . "LoadConfig.inc" );
require_once( FUNCTIONS_PATH . "General.inc" );
require_once( FUNCTIONS_PATH . "Positive_Int_Check.inc" );
require_once( FUNCTIONS_PATH . "Parse__URL.inc" );
require_once( FUNCTIONS_PATH . "Map.inc" );
require_once( FUNCTIONS_PATH . "HTML_Output.inc" );
require_once( FUNCTIONS_PATH . "Password_Functions.inc" );
require_once( FUNCTIONS_PATH . "Check_Admin.inc" );
require_once( FUNCTIONS_PATH . "Smarty.inc" );

$smarty->assign( "BROWSER_NAME", browser_detect() );

// session_cache_limiter('private');
session_cache_expire(30);
session_start();
?>
