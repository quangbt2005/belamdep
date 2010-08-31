<?php
if( @function_exists( "mb_iexplode" ) != TRUE )
  {
   function mb_iexplode( $Key, $Str )
   {
    if( strlen( $Key ) <= 0 ){ return FALSE; }

    $Ichi = mb_stripos( $Str, $Key );

    if( $Ichi === FALSE ){ return array( $Str ); }

    unset( $Array );

    while( TRUE )
    {
     $Ichi = mb_stripos( $Str, $Key );

     if( $Ichi === FALSE ){ $Array[] = $Str; break; }

     $Array[] = mb_substr( $Str, 0, $Ichi );

     $Str = mb_substr( $Str, ( $Ichi + ( mb_strlen( $Key ) ) ) );
    }

    return $Array;
   }
  }

?>
