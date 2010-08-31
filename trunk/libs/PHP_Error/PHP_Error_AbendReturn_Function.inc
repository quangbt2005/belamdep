<?php
function PHP_Error_AbendReturn( $Message, $Mail = "" )
{
 if( is_array( $Message ) == TRUE ){ $Message = $Message["Value"];  }

 $URL  = "";
 $File = "";

 PHP_Error_Init( $Array, $Message, "A", "CgiError", $URL, $Mail, $File );
 PHP_Error_ENV_Get( $Array );
 PHP_Error_Go_SendMail( $Array );
}

@include_once( LIB_PATH . "PHP_Error/PHP_Error_Private_Function.inc" );
@include_once( LIB_PATH . "P_FileIO/P_FileIO_isFile_Function.inc" );
@include_once( LIB_PATH . "P_Mobile/P_Carrier_Get_Function.inc" );
@include_once( LIB_PATH . "P_Mail/P_SendMail_Function.inc" );
@include_once( LIB_PATH . "P_STD/P_STD_ConvertString_Function.inc" );
@include_once( LIB_PATH . "P_STD/P_STD_DeleteComment_Function.inc" );
@include_once( LIB_PATH . "WWW_Config/WWW_Config_Include_Dir_Function.inc" );
@include_once( LIB_PATH . "WWW_Config/WWW_Config_Server_ENV_Function.inc" );

?>
