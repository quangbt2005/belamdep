<?php
function P_Mail_Carrier_isI( $Mail )
{
 $Bool = P_Mail_Carrier( $Mail );

 if( $Bool == "I" ){ return TRUE; }

 return FALSE;
}
@include_once( LIB_PATH . "P_Mail/P_Mail_Carrier_Function.inc" );

?>
