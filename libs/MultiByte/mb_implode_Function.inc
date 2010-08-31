<?php
if( @function_exists( "mb_implode" ) != TRUE )
  {
   function mb_implode( $Key, $Array )
   {
    if( is_array( $Array ) != TRUE ){ return $Array; }

    $Ot = implode( $Key, $Array );

    return $Ot;
   }
  }

?>
