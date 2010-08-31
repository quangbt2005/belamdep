<?php
function P_Mail_Carrier_isJ( $Mail )
{
 $Bool = P_Mail_Carrier( $Mail );

 if( $Bool == "J" ){ return TRUE; }

 return FALSE;
}

@include_once( LIB_PATH . "P_Mail/P_Mail_Carrier_Function.inc" );

?>
