<?php
function P_Check_Hira_Kata( $In, $Type, $FLG = "" )
{

/*********************************************** P002 : Change End!! */
 if( mb_strlen( $In ) <= 0 ){ return TRUE; }

 $Type = sprintf( "%d", $Type );

 switch( $Type )
 {
  case "3" :
  case "6" : { $Number = "24"; break; }
  case "2" :
  case "5" : { $Number = "23"; break; }
  default  : { $Number = "22"; break; }
 }

 $String = P_Word_Check_getString( $Number );

 $Onbiki = P_Word_Check_getString( "99" );
 $WK     = mb_substr( $Onbiki, -2 );

 if( P_Word_Check_Beta( $In, $WK ) == TRUE ){ return FALSE; }

 if( $Type > 3 )
   { $String .= $Onbiki; }
   else
 if( strtoupper( $FLG ) == "OFF" )
   { $String .= $WK; }

 if( P_Word_Check_Beta( $In, $String ) == FALSE ){ return FALSE; }

 if( $Type > 3 && strtoupper( $FLG ) != "OFF" )
   {
    if( P_Word_Check_Beta( $In, $Onbiki ) == TRUE ){ return FALSE; }
   }

 return TRUE;
}

@include_once( LIB_PATH . "P_Check/P_Word_Check_Beta_Function.inc" );
@include_once( LIB_PATH . "P_Check/P_Word_Check_getString_Function.inc" );

?>
