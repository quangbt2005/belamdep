<?php
if( @function_exists( "mb_stristr" ) != TRUE )
  {
   function mb_stristr( $Str, $Key )
   {
    if( strlen( $Key ) <= 0 ){ return FALSE; }

    $Ichi = mb_strpos( mb_strtolower( $Str ), mb_strtolower( $Key ) );

    if( $Ichi === FALSE ){ return FALSE; }

    $Ot = mb_substr( $Str, $Ichi );

    return $Ot;
   }
  }

?>
