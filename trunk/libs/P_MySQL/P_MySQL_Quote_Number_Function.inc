<?php
function P_MySQL_Quote_Number( $SQL, $FLG = "" )
{
 $Reg_Array = array( "[^0123456789eE\\.+-]" );
 $Cnv_Array = array( "" );

 $BYTE = P_MySQL_Quote_Escape_String( $SQL, $Reg_Array, $Cnv_Array );

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

    $Message = "P_MySQL\P_MySQL_Quote_Number_Function.inc\nLine 23\n";

    PHP_Error_Abend( $Message, $URL );
    exit;
   }

 return $BYTE;
}
@include_once( LIB_PATH . "P_MySQL/P_MySQL_Private_Function.inc" );
@include_once( LIB_PATH . "P_CSS_Cnv/P_HTML_Cnv_Function.inc" );
@include_once( LIB_PATH . "PHP_Error/PHP_Error_Abend_Function.inc" );
?>
