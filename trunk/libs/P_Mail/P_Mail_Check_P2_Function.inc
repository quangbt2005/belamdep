<?php
function P_Mail_Check_P2( $Mail )
{
 if( P_Mail_Check_P( $Mail ) == FALSE ){ return FALSE; }
 if( substr( $Mail, -1 ) == "." ){ return FALSE; }

 $REG = "[0-9a-zA-Z\\.-]";
 $WK01 = substr( $Mail, ( strpos( $Mail, "@" ) + 1 ) );
 $WK02 = ereg_replace( $REG, "", $WK01 );

 if( strlen( $WK02 ) > 0 ){ return FALSE; }

 return TRUE;
}

@include_once( LIB_PATH . "P_Mail/P_Mail_Check_P_Function.inc" );

?>
