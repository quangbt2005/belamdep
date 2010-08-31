<?php
if( @function_exists( "mb_strripos" ) != TRUE )
  {
   function mb_strripos( $Str, $Key )
   {
    if( strlen( $Str ) <= 0 || strlen( $Key ) <= 0 ){ return FALSE; }

    $Ichi = mb_strrpos( mb_strtolower( $Str ), mb_strtolower( $Key ) );

    return $Ichi;
   }
  }

?>
