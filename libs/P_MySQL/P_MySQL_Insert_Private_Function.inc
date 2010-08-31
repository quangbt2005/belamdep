<?php
function P_MySQL_Insert_GetLock( $SQL, $Dir, $Type, &$Lock, $Name, $FLG = "" )
{
 if( mb_substr( mb_strtoupper( $SQL ), 0, 7 ) != "INSERT " )
   {
    return "P_MySQL\P_MySQL_Insert_Private_Function.inc\nP_MySQL_Insert_GetLock\n";
   }

 if( mb_strtoupper( $FLG ) == "OFF" ){ return ""; }

 if( @defined( "MySQL_InsertID_Lock" )    == TRUE && 
     mb_strtoupper( MySQL_InsertID_Lock ) == "OFF" ){ return ""; }

 $Dir = @realpath( $Dir );

 if( mb_strlen( $Dir ) <= 0 ){ $Dir = posix_getcwd( ); }

 if( mb_substr( $Dir, -1 ) != "/" ){ $Dir .= "/"; }

 if( mb_strtoupper( $Type ) == "SYMLINK" )
   { $Lock = P_FileLock2( $Dir.$Name ); }
   else
   { $Lock = P_FileLock( $Name, $Dir, "100" ); }

 if( $Lock != TRUE )
   {
    return "P_MySQL\P_MySQL_Insert_Private_Function.inc\nP_MySQL_Insert_GetLock\nLine 27\n";
   }

 return "";
}

function P_MySQL_Insert_GetLockFree( $Type, $Lock, $FLG = "" )
{
 if( mb_strtoupper( $FLG ) == "OFF" ){ return ""; }

 if( @defined( "MySQL_InsertID_Lock" )    == TRUE && 
     mb_strtoupper( MySQL_InsertID_Lock ) == "OFF" ){ return ""; }

 if( mb_strtoupper( $Type ) == "SYMLINK" )
   { $Bool = P_FileUnLock2( $Lock ); }
   else
   { $Bool = P_FileUnLock( $Lock ); }

 if( $Bool != TRUE )
   {
    return "P_MySQL\P_MySQL_Insert_Private_Function.inc\nLine 47\n";
   }

 return "";
}

/*********************************************************************/
function P_MySQL_Synchronized_LockFree( )
{
 global $P_MySQL_InsertLock; global $P_MySQL_InsertLock2;
 global $P_MySQL_InsertLockType; global $P_MySQL_InsertLockType2;

 if( mb_strtoupper( $P_MySQL_InsertLockType ) == "SYMLINK" )
   { $Lock = P_FileUnLock2( $P_MySQL_InsertLock ); }
   else
   { $Lock = P_FileUnLock( $P_MySQL_InsertLock ); }

 if( mb_strtoupper( $P_MySQL_InsertLockType2 ) == "SYMLINK" )
   { $Lock = P_FileUnLock2( $P_MySQL_InsertLock2 ); }
   else
   { $Lock = P_FileUnLock( $P_MySQL_InsertLock2 ); }
}

@register_shutdown_function( "P_MySQL_Synchronized_LockFree" );

?>
