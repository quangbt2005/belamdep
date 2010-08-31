<?php
if( @function_exists( "mb_rexplode" ) != TRUE )
  {
   function mb_rexplode( $Key, $Str )
   {
    $Array = mb_explode( $Key, $Str );

    if( is_array( $Array ) != TRUE ){ return $Array; }

    return array_reverse( $Array );
   }
  }

?>
