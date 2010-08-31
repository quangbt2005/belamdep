<?php
function P_SQL_Quote( $SQL, $DBMS = "" )
{
 $Reg_Array = array( "\\\\", "'",   "\"" );
 $Cnv_Array = array( "\\\\", "\\'", "\\\"" );

 if( mb_strtoupper( $DBMS ) == "ORACLE" )
   {
    $Reg_Array = array( "'" );
    $Cnv_Array = array( "''" );
   }

 return P_SQL_Quote_Escape_String( $SQL, $Reg_Array, $Cnv_Array );
}

@include_once( LIB_PATH . "P_SQL/P_SQL_Private_Function.inc" );

?>
