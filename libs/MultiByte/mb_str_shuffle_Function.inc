<?php
if( @function_exists( "mb_str_shuffle" ) != TRUE )
  {
   function mb_str_shuffle( $Str )
   {
    if( strlen( $Str ) <= 0 ){ return ""; }

    mt_srand( (double)microtime( ) * 1000000 );
    $Count = mb_strlen( $Str );
    $Ot    = "";

    $Array = array( );

    while( TRUE )
    {
     $Hit  = mt_rand( 0, ( $Count - 1 ) );

     if( $Array[$Hit] == "" )
       {
        $Array[$Hit] = "ON";
        $Ot  .= mb_substr( $Str, $Hit, 1 );
       }

     if( mb_strlen( $Str ) == mb_strlen( $Ot ) ){ break; }
    }

    return $Ot;
   }
  }

?>
