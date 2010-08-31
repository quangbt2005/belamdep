<?php
function PHP_Error_SetExtra( $Name, $Value )
{
 global $PHP_Error_Extra_Array;

 $TARGET = "";

 while( function_exists( "debug_backtrace" ) == TRUE )
 {
  $BackTrace = debug_backtrace( );

  if( is_array( $BackTrace ) != TRUE ){ break; }

  if( count( $BackTrace ) <= 0 ){ break; }

  $Array  = $BackTrace[0];
  $TARGET = " [".$Array["file"]."(".$Array["line"].")]";
  break;
 }

 if( is_array( $PHP_Error_Extra_Array ) != TRUE )
   { $PHP_Error_Extra_Array = array( ); }

 if( mb_strlen( $Name ) <= 0 ){ return ; }

 $PHP_Error_Extra_Array[] = $Name." : ".$Value.$TARGET;
}

@include_once( LIB_PATH . "PHP_Error/PHP_Error_Private_Function.inc" );

?>
