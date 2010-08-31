<?php
function P_FileIO_Open( $File, $Mode )
{
 global $P_FileIO_Error; $P_FileIO_Error = "";

 if( function_exists( "debug_backtrace" ) == TRUE )
   { $BackTrace = debug_backtrace( ); }

 $P_FileIO_Error = P_FileIO_InitCheck( $File, $Mode );

 if( $P_FileIO_Error != "" )
   { P_FileIO_SetErrorHandler( $BackTrace ); return FALSE; }

 $P_FileIO_Error = P_FileIO_OpenManagement( $File, $Mode );

 if( $P_FileIO_Error != "" )
   { P_FileIO_SetErrorHandler( $BackTrace ); return FALSE; }

 return $File["File"];
}

@include_once( LIB_PATH . "P_FileIO/P_FileIO_isPrivate_Function.inc" );
@include_once( LIB_PATH . "P_FileIO/P_FileIO_Private_Function.inc" );
@include_once( LIB_PATH . "P_LockUnLock/P_FileLock_Function.inc" );
@include_once( LIB_PATH . "P_LockUnLock/P_FileLock_Serializable_Function.inc" );
@include_once( LIB_PATH . "P_LockUnLock/P_FileLock2_Function.inc" );
@include_once( LIB_PATH . "P_LockUnLock/P_FileLock2_Serializable_Function.inc" );
@include_once( LIB_PATH . "P_LockUnLock/P_FileUnLock_Function.inc" );
@include_once( LIB_PATH . "P_LockUnLock/P_FileUnLock2_Function.inc" );

?>
