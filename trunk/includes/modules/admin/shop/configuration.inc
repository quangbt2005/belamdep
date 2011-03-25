<?php
/**************************************************************************************************/
/* Created on May 30, 2010                                                                        */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "DB.inc" );
// ---------------------------------------------------------------------------------------------- //
if($_SERVER['REQUEST_METHOD'] == 'POST'){
  DB_Update('configuration', array('configuration_key' => 'ADMIN_EMAIL'),
                             array('configuration_value' => P_SQL_Quote($_POST['txtEmail2'])));
  DB_Update('configuration', array('configuration_key' => 'STORE_ADDRESS'),
                             array('configuration_value' => P_SQL_Quote($_POST['txtAddress'])));
  DB_Update('configuration', array('configuration_key' => 'STORE_EMAIL'),
                             array('configuration_value' => P_SQL_Quote($_POST['txtEmail1'])));
  DB_Update('configuration', array('configuration_key' => 'SUPPORT_EMAIL'),
                             array('configuration_value' => P_SQL_Quote($_POST['txtEmail3'])));
  DB_Update('configuration', array('configuration_key' => 'PHONE_1'),
                             array('configuration_value' => P_SQL_Quote($_POST['txtPhone1'])));
  DB_Update('configuration', array('configuration_key' => 'PHONE_2'),
                             array('configuration_value' => P_SQL_Quote($_POST['txtPhone2'])));
  DB_Update('configuration', array('configuration_key' => 'CHAT_1'),
                             array('configuration_value' => P_SQL_Quote($_POST['txtChat1'])));
  DB_Update('configuration', array('configuration_key' => 'CHATTITLE_1'),
                             array('configuration_value' => P_SQL_Quote($_POST['txtChat1Title'])));
  DB_Update('configuration', array('configuration_key' => 'CHAT_2'),
                             array('configuration_value' => P_SQL_Quote($_POST['txtChat2'])));
  DB_Update('configuration', array('configuration_key' => 'CHATTITLE_2'),
                             array('configuration_value' => P_SQL_Quote($_POST['txtChat2Title'])));
}
$center_col = $smarty->fetch( "admin/shop/configuration.tpl" );
?>
