<?php
function P_SQL_Quote_FieldName( $SQL, $DBMS = "", $FLG = "", $ERR = "" )
{
 $Reg_Array = array( "[^0-9a-zA-Z\\._]" );
 $Cnv_Array = array( "" );

 $BYTE = P_SQL_Quote_Escape_String( $SQL, $Reg_Array, $Cnv_Array );

 if( strlen( $BYTE ) != strlen( $SQL ) || strlen( $SQL ) <= 0 )
   {
    if( !( defined( "SQL_Quote_GetException" ) == TRUE &&
        strtoupper( SQL_Quote_GetException )   == "ON" ) ){ return ""; }

    if( strtoupper( $FLG ) == "OFF" ){ return ""; }
    $URL     = "";
    $Message = "";

    if( defined( "SQL_Quote_Number_Error_URL" ) == TRUE &&
        mb_strlen( SQL_Quote_Number_Error_URL ) > 0 )
      { $URL = SQL_Quote_Number_Error_URL; }

    if( strlen( $ERR ) > 0 ){ $URL = $ERR; } /* P004: Add!! */

    $Message = "P_SQL\P_SQL_Quote_FieldName_Function.inc\nLine 24";

    PHP_Error_Abend( $Message, $URL );
    exit;
   }
 return $BYTE;
}

@include_once( LIB_PATH . "P_SQL/P_SQL_Private_Function.inc" );

if( defined( "SQL_Quote_GetException" )  == TRUE &&
    strtoupper( SQL_Quote_GetException ) == "ON" )
  {
   @include_once( LIB_PATH . "PHP_Error/PHP_Error_Abend_Function.inc" ); 
  }
?>
