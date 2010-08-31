<?php
function P_Mail_Astel_Check( $Mail )
{
 $Array = array(
                 "A",
                 "^@phone\\.ne\\.jp\$",
                 "^@[a-z0-9]+\\.mozio\\.ne\\.jp\$",
                 FALSE
               );

 return P_Mail_Carrier_Match( $Mail, $Array );
}

/*********************************************************************/
function P_Mail_Carrier_Match( $Mail, $Array )
{
 for( $XX = 1; $Array[$XX] != FALSE; ++$XX )
 {
  if( eregi( $Array[$XX], strstr( $Mail,"@" ), $Check ) )
    { return $Array[0]; }
 }

 return FALSE;
}

/*********************************************************************/
function P_Mail_Char_Check( $Mail )
{
 $Array = array(
                 "C",
                 "^@cmchuo\\.nttpnet\\.ne\\.jp\$",
                 "^@cmhokkaido\\.nttpnet\\.ne\\.jp\$",
                 "^@cmtohoku\\.nttpnet\\.ne\\.jp\$",
                 "^@cmtokai\\.nttpnet\\.ne\\.jp\$",
                 "^@cmkansai\\.nttpnet\\.ne\\.jp\$",
                 "^@cmchugoku\\.nttpnet\\.ne\\.jp\$",
                 "^@cmshikoku\\.nttpnet\\.ne\\.jp\$",
                 "^@cmkyusyu\\.nttpnet\\.ne\\.jp\$",
                 FALSE
               );

 return P_Mail_Carrier_Match( $Mail, $Array );
}

/*********************************************************************/
function P_Mail_DDI_Check( $Mail )
{
 $Array = array(
                 "D",
                 "^@pdx\\.ne\\.jp\$",
                 "^@d[a-z0-9]\\.pdx\\.ne\\.jp\$",
                 FALSE
               );

 return P_Mail_Carrier_Match( $Mail, $Array );
}

/*********************************************************************/
function P_Mail_DoCoMo_Check( $Mail )
{
 $Array = array(
                 "I",
                 "^@docomo\\.ne\\.jp\$",
                 "\\.docomo\\.ne\\.jp\$", /* P003 : Add!! */
                 FALSE
               );

 return P_Mail_Carrier_Match( $Mail, $Array );
}

/*********************************************************************/
function P_Mail_EzWeb_Check( $Mail )
{
 $Array = array(
                 "E",
                 "^@ezweb\\.ne\\.jp\$",
                 "^@[a-z][0-9]\\.ezweb\\.ne\\.jp\$",
                 "^@ez[a-z]\\.ido\\.ne\\.jp\$",
                 "\\.ezweb\\.ne\\.jp\$", /* P003 : Add!! */
                 FALSE
               );

 return P_Mail_Carrier_Match( $Mail, $Array );
}

/*********************************************************************/
function P_Mail_J_Phone_Check( $Mail )
{
 $Array = array(
                 "J",
                 "^@jp-[a-z]\\.ne\\.jp\$",
                   FALSE
                );

 return P_Mail_Carrier_Match( $Mail, $Array );
}

/*********************************************************************/
function P_Mail_J_Phone_Vodafone_Check( $Mail )
{
 $Array = array(
                 "J",
                 "^@jp-[a-z]\\.ne\\.jp\$",
                 "^@[dhtckrnsq]\\.vodafone\\.ne\\.jp\$",
                   FALSE
                );

 return P_Mail_Carrier_Match( $Mail, $Array );
}

/*********************************************************************/
function P_Mail_Vodafone_Check( $Mail )
{
 $Array = array(
                 "J",
                 "^@[dhtckrnsq]\\.vodafone\\.ne\\.jp\$",
                   FALSE
                );

 return P_Mail_Carrier_Match( $Mail, $Array );
}

/*********************************************************************/
/* P002 : Add Start!! ************************************************/
function P_Mail_SoftBank_Check( $Mail )
{
 $Array = array(
                 "J",
                 "^@softbank\\.ne\\.jp\$",
                 "\\.softbank\\.ne\\.jp\$", /* P003 : Add!! */
                   FALSE
                );

 return P_Mail_Carrier_Match( $Mail, $Array );
}
/************************************************** P002 : Add End!! */

/*********************************************************************/
function P_Mail_Paldio_Check( $Mail )
{
 $Array = array(
                 "P",
                 "^@em\\.nttpnet\\.ne\\.jp\$",
                 "^@[a-z0-9]+\\.em\\.nttpnet\\.ne\\.jp\$",
                 FALSE
               );

 return P_Mail_Carrier_Match( $Mail, $Array );
}

/*********************************************************************/
function P_Mail_Tuka_Check( $Mail )
{
 $Array = array(
                 "T",
                 "^@sky\\.tu-ka\\.ne\\.jp\$",
                 "^@[a-z0-9]+\\.sky\\.tu-ka\\.ne\\.jp\$",
                 "^@sky\\.tkk\\.ne\\.jp\$",
                 "^@[a-z0-9]+\\.sky\\.tkk\\.ne\\.jp\$",
                 "^@sky\\.tkc\\.ne\\.jp\$",
                 "^@[a-z0-9]+\\.sky\\.tkc\\.ne\\.jp\$",
                 FALSE
               );

 return P_Mail_Carrier_Match( $Mail, $Array );
}

?>
