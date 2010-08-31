<?php
function P_SQL_CheckNVL( $TABLE, $FIELD, $VALUE, $DBMS = "", $FLG="", $ERR = "" )
{
 if( mb_strlen( $VALUE ) > 0 ){ return ; }

 $Message = "P_SQL\P_SQL_CheckNVL_Function\nLine 6";

 if( !( defined( "SQL_Quote_GetException" ) == TRUE &&
     strtoupper( SQL_Quote_GetException )   == "ON" ) ){ return $Message; }

 if( strtoupper( $FLG ) == "OFF" ){ return $Message; }

 $URL = "";

 if( defined( "SQL_Quote_Number_Error_URL" ) == TRUE &&
     mb_strlen( SQL_Quote_Number_Error_URL ) > 0 )
   { $URL = SQL_Quote_Number_Error_URL; }

 if( strlen( $ERR ) > 0 ){ $URL = $ERR; }

 PHP_Error_Abend( $Message, $URL );
 exit;
}
@include_once( LIB_PATH . "P_SQL/P_SQL_Private_Function.inc" );

if( defined( "SQL_Quote_GetException" )  == TRUE &&
    strtoupper( SQL_Quote_GetException ) == "ON" )
  {
   @include_once( LIB_PATH . "PHP_Error/PHP_Error_Abend_Function.inc" ); 
  }
?>
