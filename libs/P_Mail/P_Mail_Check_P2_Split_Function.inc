<?php
function P_Mail_Check_P2_Split( $Mail1, $Mail2 )
{
 if( strlen( $Mail1 ) <= 0 || strlen( $Mail2 ) <= 0 ){ return ""; }

 $Mail = $Mail1."@".$Mail2;

 if( P_Mail_Check_P2( $Mail ) == FALSE ){ return FALSE; }

 return $Mail;
}

@include_once( LIB_PATH . "P_Mail/P_Mail_Check_P2_Function.inc" );

?>
