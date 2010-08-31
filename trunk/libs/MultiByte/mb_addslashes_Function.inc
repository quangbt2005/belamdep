<?php
if( @function_exists( "mb_addslashes" ) != TRUE )
  {
   function mb_addslashes( $Str )
   {
    $Ot = mb_ereg_replace( "\\\\", "\\\\", $Str );
    $Ot = mb_ereg_replace( "\"",   "\\\"", $Ot );
    $Ot = mb_ereg_replace( "'",    "\\'",  $Ot );

    return $Ot;
   }
  }

?>
