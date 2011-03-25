<?php
$configkey = array(
  "'EMAIL'",
  "'STORE_ADDRESS'",
  "'STORE_EMAIL'",
  "'PHONE'",
  "'CHAT'",
  "'CHATTITLE'",
);

$condition = implode(',', $configkey);
$query  = 'SELECT configuration_key,configuration_value ';
$query .= 'FROM configuration ';
$query .= "WHERE configuration_title in($condition)";

$Result = P_MySQL_Real_SELECT_GetArrayIndex( $query );

foreach($Result as $value){
	define($value['configuration_key'], $value['configuration_value']);
  $smarty->assign($value['configuration_key'], $value['configuration_value'] );
}
?>
