<?php
if( @function_exists( "mb_strstr" ) != TRUE )
  {
   function mb_strstr( $Str, $Key )
   {
    if( strlen( $Key ) <= 0 ){ return FALSE; }

    $Ichi = mb_strpos( $Str, $Key );

    if( $Ichi === FALSE ){ return FALSE; }

    $Ot = mb_substr( $Str, $Ichi );

    return $Ot;
   }
  }

?>
