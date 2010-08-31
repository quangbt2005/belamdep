<?php
function P_Asc_Sjis_Check( $In, $Type )
{
 for( $XX = 0; $XX < strlen( $In ); ++$XX )
 {
  if( $Type == "1" )
    {
     if( P_Iskanji( $In[$XX] ) == TRUE ){ return FALSE; }
       else                             { ++$XX; }
    }
    else
    {
     if( P_Iskanji( $In[$XX] ) != TRUE ){ return FALSE; }
    }
 }

 return TRUE;
}

@include_once( LIB_PATH . "P_Other/P_Iskanji_Function.inc" );
?>
