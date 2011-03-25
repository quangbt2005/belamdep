<?php
/**************************************************************************************************/
/* Created on Nov 29, 2008                                                                        */
/**************************************************************************************************/
require_once( LIB_PATH . "smarty/Smarty.class.php" );
$smarty = new Smarty();

$smarty->template_dir = TEMPLATES_PATH;
$smarty->compile_dir  = TEMPLATES_C_PATH;
$smarty->cache_dir    = SMARTY_CACHE;
$smarty->config_dir   = SMARTY_CONFIG;
?>
