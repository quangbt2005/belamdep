<?php
function P_MySQL_LoadData2( $Array )
{
 global $P_MySQL_Error; $P_MySQL_Error = "";

 if( function_exists( "debug_backtrace" ) == TRUE )
   { $BackTrace = debug_backtrace( ); }

 $Array["DB_Host"] = DB_Host2;
 $Array["DB_User"] = DB_User2;
 $Array["DB_Pass"] = DB_Pass2;

 $P_MySQL_Error .= P_MySQL_LoadData_Init_Check( $Array );
 
 if( $P_MySQL_Error != "" )
   { P_MySQL_Error_SetErrorHandler( $BackTrace ); return FALSE; }

 $P_MySQL_Error .= P_MySQL_LoadData_Exec( $Array, $Result_Array );
 
 if( $P_MySQL_Error != "" )
   { P_MySQL_Error_SetErrorHandler( $BackTrace ); return FALSE; }

 return $Result_Array;
}

@include_once( LIB_PATH . "P_MySQL/P_MySQL_LoadData_Private_Function.inc" );

?>
