<?php
function P_Mail_Carrier_is3Carrier( $Mail )
{
 $Bool = P_Mail_Carrier( $Mail );

 if( $Bool == "I" ){ return TRUE; }
 if( $Bool == "E" ){ return TRUE; }
 if( $Bool == "J" ){ return TRUE; }

 return FALSE;
}

@include_once( LIB_PATH . "P_Mail/P_Mail_Carrier_Function.inc" );

?>
