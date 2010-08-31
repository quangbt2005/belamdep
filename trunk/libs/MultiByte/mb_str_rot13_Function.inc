<?php
if( @function_exists( "mb_str_rot13" ) != TRUE )
  {
   function mb_str_rot13( $Str )
   {
    if( strlen( $Str ) <= 0 ){ return ""; }

    $Count = mb_strlen( $Str );
    $Ot = "";

    for( $XX = 0; $XX < $Count; ++$XX )
    {
     $Value = mb_substr( $Str, $XX, 1 );

     $Key = mb_eregi_replace( "[a-z]", "", $Value );

     if( strlen( $Key ) <= 0 )
       {
        $Ot .= str_rot13( $Value );
        continue;
       }

     $Ot .= $Value;
    }

    return $Ot;
   }
  }

?>
