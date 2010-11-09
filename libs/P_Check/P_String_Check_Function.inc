<?php
function P_String_Check( $In, $Flg, $Ws, $Check )
{
 if( $In == "" ){ if( $Flg == "0" ){ return 1; } }

 if( strlen( $In ) > $Ws ){ return 2; }

 if( $Check != "No Check" && $Check != "E-Mail" )
   {
    if( P_Word_Check_Alpha( $Check, "1" ) == TRUE )
      {
       if( P_Word_Check_Alpha( $In, $Check ) != TRUE ){ return 3; }
      }
      else
      {
       if( P_Word_Check_Beta( $In, $Check ) != TRUE ){ return 3; }
      }
   }

 if( $Check == "E-Mail" )
   {
    if( @defined( "Mail_Syntax_Check_P2" ) == TRUE &&
        mb_strtoupper( Mail_Syntax_Check_P2 ) == "ON" &&
        @function_exists( "P_Mail_Check_P2" ) )
      {
       $Bool = P_Mail_Check_P2( $In );
      }
      else
      {
       $Bool = P_Mail_Check_P( $In );
      }

    if( $Bool != TRUE ){ return 4; }
   }

 return 0;
}
@include_once( LIB_PATH . "P_Check/P_Word_Check_Alpha_Function.inc" );
@include_once( LIB_PATH . "P_Check/P_Word_Check_Beta_Function.inc" );
@include_once( LIB_PATH . "P_Mail/P_Mail_Check_P_Function.inc" );
@include_once( "P_Mail/P_Mail_Check_P2_Function.inc" ); /*V002:Add!!*/

?>
