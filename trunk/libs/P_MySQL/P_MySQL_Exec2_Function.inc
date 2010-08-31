<?php
function P_MySQL_Exec2( $DB_Name, $SQL, $Type, $Level )
{
 global $P_MySQL_Error; $P_MySQL_Error = "";
 global $P_MySQL_Connect2;

 if( function_exists( "debug_backtrace" ) == TRUE )
   { $BackTrace = debug_backtrace( ); }

 $P_MySQL_Error = P_MySQL_QueryCheck( $SQL, "EXEC", $Level,
                                         $DB_Name, "P_MySQL_SELECT2" );

 if( $P_MySQL_Error != "" )
   { P_MySQL_Error_SetErrorHandler( $BackTrace ); return FALSE; }

 $P_MySQL_Error = P_MySQL_Connect_Host( $P_MySQL_Connect2,
                                DB_Host2, DB_User2, DB_Pass2, $Type );

 if( $P_MySQL_Error != "" )
   { P_MySQL_Error_SetErrorHandler( $BackTrace ); return FALSE; }

 $P_MySQL_Error = P_MySQL_Select_DB( $P_MySQL_Connect2, $DB_Name );

 if( $P_MySQL_Error != "" )
   { P_MySQL_Error_SetErrorHandler( $BackTrace ); return FALSE; }

 $P_MySQL_Error =  P_MySQL_QueryExec( $P_MySQL_Connect2, $Result, $SQL,
                  DB_Host2, DB_User2, DB_Pass2, $DB_Name, $Type, "" );

 if( $P_MySQL_Error != "" )
   { P_MySQL_Error_SetErrorHandler( $BackTrace ); return FALSE; }

 return @mysql_affected_rows( $P_MySQL_Connect2 );
}
@include_once( LIB_PATH . "P_CSS_Cnv/P_HTML_Cnv_Function.inc" );
?>
