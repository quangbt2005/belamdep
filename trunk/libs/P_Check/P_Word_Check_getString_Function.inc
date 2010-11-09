<?php
function P_Word_Check_getString( $Type )
{
 return P_Check_getString( $Type );
}
/*********************************************************************/
switch( strtoupper( mb_internal_encoding( ) ) )
{
 case "SJIS"     :
 case "SJIS-WIN" : {
                    @include_once( LIB_PATH . "P_Check/P_Check_getString_SJIS_Private_Function.inc" );
                    break;
                   }
 case "UTF8"     :
 case "UTF-8"    : {
                    @include_once( LIB_PATH . "P_Check/P_Check_getString_UTF8_Private_Function.inc" );
                    break;
                   }
 default         : {
                    @include_once( LIB_PATH . "P_Check/P_Check_getString_EUC_Private_Function.inc" );
                    break;
                   }
}

?>
