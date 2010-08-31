<?php
function P_MySQL_GetConnection( $Type = "" )
{
 global $P_MySQL_Error; $P_MySQL_Error = "";
 global $P_MySQL_Connect;

 if( function_exists( "debug_backtrace" ) == TRUE )
   { $BackTrace = debug_backtrace( ); }

 $P_MySQL_Error = P_MySQL_Connect_Host( $P_MySQL_Connect,
                                    DB_Host, DB_User, DB_Pass, $Type );

 if( $P_MySQL_Error != "" )
   { P_MySQL_Error_SetErrorHandler( $BackTrace ); return FALSE; }

 return $P_MySQL_Connect;
}
@include_once( LIB_PATH . "P_MySQL/P_MySQL_Private_Function.inc" );

?>
