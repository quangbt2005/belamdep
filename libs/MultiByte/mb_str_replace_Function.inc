<?php
if( @function_exists( "mb_str_replace" ) != TRUE )
  {
   function mb_str_replace( $Key1, $Key2, $Str )
   {
    if( strlen( $Key1 ) <= 0 ){ return $Str; }

    $Ichi = mb_strpos( $Str, $Key1 );

    if( $Ichi === FALSE ){ return $Str; }

    $Ot = "";

    while( TRUE )
    {
     $Ichi = mb_strpos( $Str, $Key1 );

     if( $Ichi === FALSE ){ $Ot .= $Str; break; }

     $Ot .= mb_substr( $Str, 0, $Ichi ).$Key2;

     $Str = mb_substr( $Str, ( $Ichi + ( mb_strlen( $Key1 ) ) ) );
    }

    return $Ot;
   }
  }

?>
