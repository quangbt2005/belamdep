<?php
function P_MySQL_GetConnection2( $Type = "" )
{
 global $P_MySQL_Error; $P_MySQL_Error = "";
 global $P_MySQL_Connect2;

 if( function_exists( "debug_backtrace" ) == TRUE )
   { $BackTrace = debug_backtrace( ); }

 $P_MySQL_Error = P_MySQL_Connect_Host( $P_MySQL_Connect2,
                                 DB_Host2, DB_User2, DB_Pass2, $Type );

 if( $P_MySQL_Error != "" )
   { P_MySQL_Error_SetErrorHandler( $BackTrace ); return FALSE; }

 return $P_MySQL_Connect2;
}

@include_once( LIB_PATH . "P_MySQL/P_MySQL_Private_Function.inc" );

?>
