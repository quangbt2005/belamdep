<?php
if( @function_exists( "mb_rsplit" ) != TRUE )
  {
   function mb_rsplit( $Key, $Str )
   {
    $Array = mb_split( $Key, $Str );

    if( is_array( $Array ) != TRUE ){ return $Array; }

    return array_reverse( $Array );
   }
  }

?>
