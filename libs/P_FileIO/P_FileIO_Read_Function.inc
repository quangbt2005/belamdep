<?php
function P_FileIO_Read( $File, $Chop = "" )
{
 global $P_FileIO_Error; $P_FileIO_Error = "";

 if( function_exists( "debug_backtrace" ) == TRUE )
   { $BackTrace = debug_backtrace( ); }
 $P_FileIO_Error = P_FileIO_ReadLine( $File, $Buffer, $Chop );

 if( $P_FileIO_Error != "" )
   { P_FileIO_SetErrorHandler( $BackTrace ); return FALSE; }

 return $Buffer;
}

@include_once( LIB_PATH . "P_FileIO/P_FileIO_Private_Function.inc" );

?>
