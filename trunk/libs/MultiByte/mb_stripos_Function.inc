<?php
if( @function_exists( "mb_stripos" ) != TRUE )
  {
   function mb_stripos( $Str, $Key )
   {
    if( strlen( $Str ) <= 0 || strlen( $Key ) <= 0 ){ return FALSE; }

    $Ichi = mb_strpos( mb_strtolower( $Str ), mb_strtolower( $Key ) );

    return $Ichi;
   }
  }

?>
