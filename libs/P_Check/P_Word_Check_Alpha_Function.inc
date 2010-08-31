<?php
function P_Word_Check_Alpha( $In01, $Type )
{
 $In02 = P_Check_getString( $Type );

 if( $In02 == FALSE ){ return FALSE; }

 return P_Check_SearchString( $In01, $In02 );
}

@include_once( LIB_PATH . "P_Check/P_Check_Private_Function.inc" );

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

@include_once( LIB_PATH . "P_Other/P_Iskanji_Function.inc" );

?>
