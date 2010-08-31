<?php
function P_SendMail_HTML( )
{
 global $P_SendMail_Error; $P_SendMail_Error = "";

 if( @function_exists( "debug_backtrace" ) == TRUE )
   { $BackTrace = debug_backtrace( ); }
}

include_once( "P_Mail/P_SendMail_Private_Function.inc" );
include_once( "P_Mail/P_SendMail_SetErrorHandler_Private_Function.inc" );
@include_once( LIB_PATH . "P_TemplateMail/P_TemplateMail_SendMail_Function.inc" );

?>
