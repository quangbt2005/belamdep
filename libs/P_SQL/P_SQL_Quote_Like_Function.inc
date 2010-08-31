<?php
function P_SQL_Quote_Like( $SQL, $DBMS = "" )
{
 $Reg_Array = array( "\\\\", "'",   "\"",   "%",   "_" );
 $Cnv_Array = array( "\\\\", "\\'", "\\\"", "\\%", "\\_" );

 if( mb_strtoupper( $DBMS ) == "ORACLE" )
   {
    $Reg_Array = array( "\\\\", "'",  "%",   "_" );
    $Cnv_Array = array( "\\\\", "''", "\\%", "\\_" );
   }
   else
 if( mb_strtoupper( $DBMS ) == "POSTGRESQL" )
   {
    $Reg_Array = array( "\\\\",     "'",   "\"",   "%",     "_" );
    $Cnv_Array = array( "\\\\\\\\", "\\'", "\\\"", "\\\\%", "\\\\_" );
   }
 return P_SQL_Quote_Escape_String( $SQL, $Reg_Array, $Cnv_Array );
}
@include_once( LIB_PATH . "P_SQL/P_SQL_Private_Function.inc" );

?>
