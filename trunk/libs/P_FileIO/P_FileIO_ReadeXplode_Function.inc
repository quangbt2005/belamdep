<?php
function P_FileIO_ReadeXplode( $File, $Separator,
                                          $Igonore = "ON", $Chop = "" )

{
 global $P_FileIO_Error; $P_FileIO_Error = "";

 if( function_exists( "debug_backtrace" ) == TRUE )
   { $BackTrace = debug_backtrace( ); }

 $Buffer = P_FileIO_Read( $File, $Chop );

 if( $P_FileIO_Error != "" )
   { P_FileIO_SetErrorHandler( $BackTrace ); return FALSE; }

 if( $Buffer == "" ){ return $Buffer; }

 if( mb_strtoupper( $Igonore ) == "OFF" )
   { return mb_iexplode( $Separator, $Buffer ); }

 return mb_explode( $Separator, $Buffer );
}

@include_once( LIB_PATH . "P_FileIO/P_FileIO_Read_Function.inc" );
@include_once( LIB_PATH . "P_FileIO/P_FileIO_Private_Function.inc" );
@include_once( LIB_PATH . "MultiByte/mb_explode_Function.inc" );
@include_once( LIB_PATH . "MultiByte/mb_iexplode_Function.inc" );
@include_once( LIB_PATH . "MultiByte/mb_stripos_Function.inc" );

?>
