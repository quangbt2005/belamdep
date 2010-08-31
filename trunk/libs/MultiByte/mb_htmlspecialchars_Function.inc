<?php
if( @function_exists( "mb_htmlspecialchars" ) != TRUE )
  {
   function mb_htmlspecialchars( $Str )
   {
    $Ot = mb_ereg_replace( "&",  "&amp;",  $Str );
    $Ot = mb_ereg_replace( "\"", "&quot;", $Ot );
    $Ot = mb_ereg_replace( "<",  "&lt;",   $Ot );
    $Ot = mb_ereg_replace( ">",  "&gt;",   $Ot );

    return $Ot;
   }
  }

?>
