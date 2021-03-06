<?php
function P_MySQL_InsertID( $DB_Name, $SQL, $Dir, $Type = "MKDIR", $FLG1 = "", $FLG2 = "" )
{
 global $P_MySQL_Error; $P_MySQL_Error = "";
 global $P_MySQL_Connect;
 global $P_MySQL_InsertLock; global $P_MySQL_InsertLockType;

 $P_MySQL_InsertLockType = $Type;

 if( function_exists( "debug_backtrace" ) == TRUE )
   { $BackTrace = debug_backtrace( ); }
 
 $P_MySQL_Error = P_MySQL_Insert_GetLock( $SQL, $Dir,
    $P_MySQL_InsertLockType, $P_MySQL_InsertLock, "P_MySQL_InsertID", $FLG1 );

 if( $P_MySQL_Error != "" )
   { P_MySQL_Error_SetErrorHandler( $BackTrace ); return FALSE; }

 $Result = P_MySQL_Real_Exec( $DB_Name, $SQL );

 if( $P_MySQL_Error != "" )
   { P_MySQL_Error_SetErrorHandler( $BackTrace ); return FALSE; }


 if( strlen( $FLG2 ) > 0 )
   {
    $SQL   = "SELECT LAST_INSERT_ID( ) /* ORDER BY */";
    $Array = P_MySQL_Real_SELECT( $DB_Name, $SQL );

    if( mb_strlen( $Array[0] ) <= 0 )
      {
       $P_MySQL_Error = "P_MySQL\P_MySQL_InsertID_Function.inc\nLine 32\n";
       P_MySQL_Error_SetErrorHandler( $BackTrace );
       return FALSE;
      }

    $ID = $Array[0];
   }
   else
   {
    $ID = @mysql_insert_id( $P_MySQL_Connect );
   }

 $P_MySQL_Error = P_MySQL_Insert_GetLockFree( $Type, $P_MySQL_InsertLock, $FLG1 );

 if( $P_MySQL_Error != "" )
   { P_MySQL_Error_SetErrorHandler( $BackTrace ); return FALSE; }

 return array( "Result" => $Result, "InsertID" => $ID );
}

@include_once( LIB_PATH . "P_MySQL/P_MySQL_Private_Function.inc" );
@include_once( LIB_PATH . "P_MySQL/P_MySQL_Insert_Private_Function.inc" );
@include_once( LIB_PATH . "P_MySQL/P_MySQL_Real_Exec_Function.inc" );
include_once( "P_MySQL/P_MySQL_Real_SELECT_Function.inc" ); /*V002:Add!!*/

@include_once( LIB_PATH . "P_CSS_Cnv/P_HTML_Cnv_Function.inc" );
@include_once( LIB_PATH . "P_LockUnLock/P_FileLock_Function.inc" );
@include_once( LIB_PATH . "P_LockUnLock/P_FileLock2_Function.inc" );
@include_once( LIB_PATH . "P_LockUnLock/P_FileUnLock_Function.inc" );
@include_once( LIB_PATH . "P_LockUnLock/P_FileUnLock2_Function.inc" );

?>