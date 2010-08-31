<?php
function P_Mail_Carrier_isE( $Mail )
{
 $Bool = P_Mail_Carrier( $Mail );

 if( $Bool == "E" ){ return TRUE; }

 return FALSE;
}

@include_once( LIB_PATH . "P_Mail/P_Mail_Carrier_Function.inc" );

?>
