<?php
function P_MySQL_Quote_Like( $SQL )
{
 $Reg_Array = array( "\\\\", "'",   "\"",   "%",   "_" );
 $Cnv_Array = array( "\\\\", "\\'", "\\\"", "\\%", "\\_" );

 return P_MySQL_Quote_Escape_String( $SQL, $Reg_Array, $Cnv_Array );
}

@include_once( LIB_PATH . "P_MySQL/P_MySQL_Private_Function.inc" );
@include_once( LIB_PATH . "P_CSS_Cnv/P_HTML_Cnv_Function.inc" );

?>
