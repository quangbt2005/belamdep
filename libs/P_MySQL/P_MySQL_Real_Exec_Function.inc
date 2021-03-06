<?php
function P_MySQL_Real_Exec( $SQL, $DB_Name=DB_Name )
{
 global $P_MySQL_Error; $P_MySQL_Error = "";
 global $P_MySQL_Connect;

 if( function_exists( "debug_backtrace" ) == TRUE )
   { $BackTrace = debug_backtrace( ); }

 $P_MySQL_Error = P_MySQL_QueryCheck( $SQL, "EXEC", "0",
                                          $DB_Name, "P_MySQL_SELECT" );

 if( $P_MySQL_Error != "" )
   { P_MySQL_Error_SetErrorHandler( $BackTrace ); return FALSE; }

 $P_MySQL_Error = P_MySQL_Connect_Host( $P_MySQL_Connect,
                                   DB_Host, DB_User, DB_Pass, "1" );

 if( $P_MySQL_Error != "" )
   { P_MySQL_Error_SetErrorHandler( $BackTrace ); return FALSE; }

 $P_MySQL_Error = P_MySQL_Select_DB( $P_MySQL_Connect, $DB_Name );

 if( $P_MySQL_Error != "" )
   { P_MySQL_Error_SetErrorHandler( $BackTrace ); return FALSE; }

 $P_MySQL_Error = P_MySQL_QueryExec( $P_MySQL_Connect, $Result, $SQL,
                     DB_Host, DB_User, DB_Pass, $DB_Name, "1", "" );

 if( $P_MySQL_Error != "" )
   { P_MySQL_Error_SetErrorHandler( $BackTrace ); return FALSE; }

 return @mysql_affected_rows( $P_MySQL_Connect );
}
@include_once( LIB_PATH . "P_MySQL/P_MySQL_Private_Function.inc" );

?>
