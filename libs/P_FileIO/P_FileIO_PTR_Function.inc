<?php
function P_FileIO_PTR( $File )
{
 global $P_FileIO_Error; $P_FileIO_Error = "";

 if( function_exists( "debug_backtrace" ) == TRUE )
   { $BackTrace = debug_backtrace( ); }

 $P_FileIO_Error = P_FileIO_Get_PTR( $File, $PTR );

 if( $P_FileIO_Error != "" )
   { P_FileIO_SetErrorHandler( $BackTrace ); return FALSE; }

 return $PTR;
}

@include_once( LIB_PATH . "P_FileIO/P_FileIO_Private_Function.inc" );

?>
