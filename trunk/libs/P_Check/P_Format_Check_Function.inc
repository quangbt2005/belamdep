<?php
function P_Format_Check( $In )
{
 $Key = explode( "\t", $In );

 if( $Key[0] == "" || $Key[3] == "" ){ return 1; }

 if( P_Word_Check_Beta( $Key[2], "0123456789" ) != TRUE ||
  !( $Key[4] == "Code" || $Key[4] == "<BR>" ||
      P_Word_Check_Beta( $Key[4], "rRnNaAkKhHcCV" ) == TRUE ) )
   { return 2; }

  if( $Key[2] == "" )
    {
     if( $Key[3] != "Date" && $Key[3] != "Time" &&
         $Key[3] != "DateTime" ){ return 1; }
    }

 return 0;
}

@include_once( LIB_PATH . "P_Check/P_Word_Check_Beta_Function.inc" );

?>
