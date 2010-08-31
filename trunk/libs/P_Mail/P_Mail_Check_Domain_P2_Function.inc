<?php
function P_Mail_Check_Domain_P2( $Mail )
{
 if( strlen( $Mail ) <= 0 ){ return FALSE; }

 $WK = preg_replace( "/[\\x00-\\x1F]/", "", $Mail );

 if( strlen( $Mail ) != strlen( $WK ) ){ return FALSE; }

 $ICHI = strpos( $Mail, "@" );

 if( strlen( $ICHI ) <= 0 ){ return FALSE; }

 $TARGET = "a".substr( $Mail, $ICHI );

 return P_Mail_Check_P2( $TARGET );
}

@include_once( LIB_PATH . "P_Mail/P_Mail_Check_P2_Function.inc" );

?>
