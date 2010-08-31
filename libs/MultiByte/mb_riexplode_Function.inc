<?php
if( @function_exists( "mb_riexplode" ) != TRUE )
  {
   function mb_riexplode( $Key, $Str )
   {
    $Array = mb_iexplode( $Key, $Str );

    if( is_array( $Array ) != TRUE ){ return $Array; }

    return array_reverse( $Array );
   }
  }

?>
