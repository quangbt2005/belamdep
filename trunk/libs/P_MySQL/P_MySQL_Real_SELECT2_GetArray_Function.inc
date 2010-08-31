<?php
function P_MySQL_Real_SELECT2_GetArray( $SQL )
{
 global $P_MySQL_Error; $P_MySQL_Error = "";
 global $P_MySQL_Connect2;

 if( function_exists( "debug_backtrace" ) == TRUE )
   { $BackTrace = debug_backtrace( ); }

 $P_MySQL_Error = P_MySQL_QueryCheck( $SQL, "SELECT", "0",
                                    DB_Name2, "P_MySQL_Real_SELECT2" );

 if( $P_MySQL_Error != "" )
   { P_MySQL_Error_SetErrorHandler( $BackTrace ); return FALSE; }

 $P_MySQL_Error = P_MySQL_Connect_Host( $P_MySQL_Connect2,
                                   DB_Host2, DB_User2, DB_Pass2, "1" );

 if( $P_MySQL_Error != "" )
   { P_MySQL_Error_SetErrorHandler( $BackTrace ); return FALSE; }

 $P_MySQL_Error = P_MySQL_Select_DB( $P_MySQL_Connect2, DB_Name2 );

 if( $P_MySQL_Error != "" )
   { P_MySQL_Error_SetErrorHandler( $BackTrace ); return FALSE; }

 $P_MySQL_Error = P_MySQL_QueryExec( $P_MySQL_Connect2, $Result, $SQL,
                       DB_Host2, DB_User2, DB_Pass2, DB_Name2, "1", "" );

 if( $P_MySQL_Error != "" )
   { P_MySQL_Error_SetErrorHandler( $BackTrace ); return FALSE; }

 $Line_XX = P_MySQL_Get_Num_Row( $Result );

 if( is_array( $Line_XX ) == TRUE ){ return $Line_XX; }

 $P_MySQL_Error = P_MySQL_Get_Num_Fields( $Result, $Line_YY );

 if( $P_MySQL_Error != "" )
   { P_MySQL_Error_SetErrorHandler( $BackTrace ); return FALSE; }

 unset( $Array );

 $P_MySQL_Error = P_MySQL_Get_Value( $Result, $Array,
                              $Line_XX, $Line_YY, "99", "NUMBER INDEX" );

 if( $P_MySQL_Error != "" )
   { P_MySQL_Error_SetErrorHandler( $BackTrace ); return FALSE; }

 $P_MySQL_Error = P_MySQL_MemoryFree( $Result );

 if( $P_MySQL_Error != "" )
   { P_MySQL_Error_SetErrorHandler( $BackTrace ); return FALSE; }

 return $Array;
}
@include_once( LIB_PATH . "P_MySQL/P_MySQL_Private_Function.inc" );

?>
