<?php
function P_Mail_Carrier2( $Mail )
{
 $Array = array(
                 "P_Mail_DoCoMo_Check",
                 "P_Mail_EzWeb_Check",
                 "P_Mail_J_Phone_Vodafone_Check",
                 "P_Mail_Tuka_Check",
                 "P_Mail_Char_Check",
                 "P_Mail_Paldio_Check",
                 "P_Mail_DDI_Check",
                 "P_Mail_Astel_Check",
                  FALSE
               );

 for( $XX = 0; $Array[$XX] != FALSE; ++$XX )
 {
  $Result = $Array[$XX]( $Mail );

  if( $Result != FALSE ){ return $Result; }
 }

 return "W";
}

@include_once( LIB_PATH . "P_Mail/P_Mail_Private_Function.inc" );

?>
