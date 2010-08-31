<?php
function P_FileIO_Close( $File )
{
 global $P_FileIO_Error; $P_FileIO_Error = "";

 if( function_exists( "debug_backtrace" ) == TRUE )
   { $BackTrace = debug_backtrace( ); }

 $P_FileIO_Error = P_FileIO_CloseFile( $File );

 if( $P_FileIO_Error != "" )
   { P_FileIO_SetErrorHandler( $BackTrace ); return FALSE; }

 return TRUE;
}

@include_once( LIB_PATH . "P_FileIO/P_FileIO_Private_Function.inc" );
@include_once( LIB_PATH . "P_LockUnLock/P_FileLock_Function.inc" );
@include_once( LIB_PATH . "P_LockUnLock/P_FileLock_Serializable_Function.inc" );
@include_once( LIB_PATH . "P_LockUnLock/P_FileLock2_Function.inc" );
@include_once( LIB_PATH . "P_LockUnLock/P_FileLock2_Serializable_Function.inc" );
@include_once( LIB_PATH . "P_LockUnLock/P_FileUnLock_Function.inc" );
@include_once( LIB_PATH . "P_LockUnLock/P_FileUnLock2_Function.inc" );

?>
