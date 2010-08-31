<?php
function P_FileIO_CloseFile( $File )
{
 global $P_FileIO_Management_Array;
 $Array = P_FileIO_Get_Management_Array( $File );
 $Error = "";

 if( is_array( $Array ) != TRUE ){ return ""; }

 if( @is_resource( $Array["PTR"] ) == TRUE )
   {
    if( @fclose( $Array["PTR"] ) == FALSE )
      {
       $Error = "P_FileIO\P_FileIO_Private_Function.inc\nLine14\n";
      }
   }

 $Error .= P_FileIO_LockFree( $Array );

 $P_FileIO_Management_Array[$File] = "";

 return $Error;
}

/*********************************************************************/
function P_FileIO_ConvertEncoding( $Array, &$Buffer )
{
 $Encoding = $Array["Encoding"];
 $Mode     = $Array["Mode"];

 if( $Encoding == "auto" && $Mode != "r" )
   {
    $Encoding = P_FileIO_DetectEncoding( $Buffer );
    $WriteEncodingFlg = "auto";
   }

 if( $Encoding  == "pass" ){ return; }

 if( mb_strpos( mb_internal_encoding( ), $Encoding ) === FALSE )
   {
    if( $Encoding == "UTF" ){ $Encoding = "UTF-8"; }
    if( $Encoding == "EUC" ){ $Encoding = "EUC-JP"; }

    if( $Mode == "r" )
      {
       $From = $Encoding;
       $To   = mb_internal_encoding( );
      }
      else
      {
       $From = mb_internal_encoding( );
       $To   = $Encoding;

       if( $WriteEncodingFlg == "auto" )
         {
          $From = $Encoding;
          $To   = mb_internal_encoding( );
         }
      }

    $Buffer = mb_convert_encoding( $Buffer, $To, $From );
   }
}

/*********************************************************************/
function P_FileIO_DetectEncoding( $Buffer )
{
 $Encoding = mb_strtoupper( mb_detect_encoding( $Buffer ) );

 switch( $Encoding )
 {
  case "SJIS"        :
  case "SJIS-WIN"    : {
                        $Encoding = "SJIS";
                         break;
                        }
  case "UTF-8"       :
  case "UTF8"        : {
                        $Encoding = "UTF";
                        break;
                       }
  case "JIS"         :
  case "ISO-2022-JP" : {
                        $Encoding = "ISO-2022-JP";
                        break;
                       }
  default            : {
                        $Encoding = "EUC";
                        break;
                       }
 }

 return $Encoding;
}

/*********************************************************************/
function P_FileIO_Get_Encoding( $Encoding )
{
 if( mb_strlen( $Encoding ) <= 0 ){ return "pass"; }

 switch( mb_strtoupper( $Encoding ) )
 {
  case  "EUC-JP"      :
  case  "EUC_JP"      :
  case  "EUCJP-WIN"   : {
                         $Encoding = "EUC";
                         break;
                        }
  case  "SJIS"        :
  case  "SJIS-WIN"    : {
                         $Encoding = "SJIS";
                         break;
                        }
  case  "UTF8"        :
  case  "UTF-8"       : {
                         $Encoding = "UTF";
                         break;
                        }
  case  "ISO-2022-JP" :
  case  "JIS"         : {
                         $Encoding = "ISO-2022-JP";
                         break;
                        }
  case  "AUTO"        : {
                         $Encoding = "auto";
                         break;
                        }
  default             : {
                         $Encoding = "pass";
                         break;
                        }
 }

 return $Encoding;
}

/*********************************************************************/
function P_FileIO_Get_Management_Array( $File )
{
 global $P_FileIO_Management_Array;

 return $P_FileIO_Management_Array[$File];
}

/*********************************************************************/
function P_FileIO_Get_PTR( $File, &$PTR )
{
 $PTR   = FALSE;
 $Error = P_FileIO_isOpen( $File );

 if( $Error != "" ){ return $Error; }

 $Array  = P_FileIO_Get_Management_Array( $File );
 $PTR    = $Array["PTR"];

 return "";
}

/*********************************************************************/
function P_FileIO_InitCheck( &$File, &$Mode )
{
 $Mode = mb_strtolower( $Mode );

 switch( $Mode )
 {
  case "w" : { $Mode = "w"; break; }
  case "a" : { $Mode = "a"; break; }
  default  : { $Mode = "r"; break; }
 }

 if( is_array( $File ) != TRUE )
   {
    $wkFile = $File;
    $File = array( );
    $File["File"] = $wkFile;
   }

 $File["Mode"]         = $Mode;
 $File["Safe_Mode"]    = mb_strtoupper( $File["Safe_Mode"] );
 $File["Synchronized"] = mb_strtoupper( $File["Synchronized"] );
 $File["LockType"]     = mb_strtoupper( $File["LockType"] );
 $File["DeadLock"]     = mb_strtoupper( $File["DeadLock"] );
 $File["Encoding"]     = mb_strtoupper( $File["Encoding"] );

 if( $File["Safe_Mode"] == "" )      { $File["Safe_Mode"] = "SECURE"; }

 if( $File["Synchronized"] != "OFF" ){ $File["Synchronized"] = "ON"; }

 if( $File["DeadLock"] != "ON" )     { $File["DeadLock"] = "OFF"; }

 if( $File["Encoding"] == "" )       { $File["Encoding"] = "pass"; }

 if( mb_strtoupper( $File["LockType"] ) == "SYMLINK" )
   {
    $File["LockType"]     = "P_FileLock2";
    $File["UnLockType"]   = "P_FileUnLock2";
   }
   else
 if( mb_strtoupper( $File["LockType"] ) == "SYMLINK_S" )
   {
    $File["LockType"]     = "P_FileLock2_Serializable";
    $File["UnLockType"]   = "P_FileUnLock2";
   }
   else
 if( mb_strtoupper( $File["LockType"] ) == "MKDIR_S" )
   {
    $File["LockType"]     = "P_FileLock_Serializable";
    $File["UnLockType"]   = "P_FileUnLock";
   }
   else
   {
    $File["LockType"]     = "P_FileLock";
    $File["UnLockType"]   = "P_FileUnLock";
   }

 $File["Encoding"] = P_FileIO_Get_Encoding( $File["Encoding"] );

 if( @is_file( $File["File"] ) == TRUE )
   { $File["File"] = realpath( $File["File"] ); }
   else
   {
    if( $Mode == "r" )
      {
       return "P_FileIO\P_FileIO_Private_Function.inc\nLine 224\n";
      }
   }

 $Result = P_FileIO_isSearch( $File["File"], "1", $File["Safe_Mode"] );

 if( $Result == FALSE )
   {
    return "P_FileIO\P_FileIO_Private_Function.inc\nLine 232\n";
   }

 return "";
}

/*********************************************************************/
function P_FileIO_isEOF( $File, &$Bool )
{
 $Bool  = FALSE;
 $Array = P_FileIO_Get_Management_Array( $File );
 $Error = P_FileIO_isOpen( $File );

 if( $Error != "" ){ return $Error; }

 if( @feof( $Array["PTR"] ) == TRUE ){ $Bool = TRUE; }
}

/*********************************************************************/
function P_FileIO_isOpen( $File )
{
 if( is_array( P_FileIO_Get_Management_Array( $File ) ) != TRUE )
   {
    return "P_FileIO\P_FileIO_Private_Function.inc\nLine 255\n";
   }

 $Array = P_FileIO_Get_Management_Array( $File );

 if( @is_resource( $Array["PTR"] ) != TRUE )
   {
    return "P_FileIO\P_FileIO_Private_Function.inc\nLine 262\n";
   }

 return "";
}

/*********************************************************************/
function P_FileIO_JumpSeek( $File, $Seek, &$Bool )
{
 $Bool  = FALSE;
 $Error = P_FileIO_isOpen( $File );

 if( $Error != "" ){ return $Error; }

 $Array = P_FileIO_Get_Management_Array( $File );
 $Bool   = @fseek( $Array["PTR"], $Seek );

 return "";
}

/*********************************************************************/
function P_FileIO_LockGet( &$Array )
{
 $File = $Array["File"];

 if( $Array["Synchronized"] == "OFF" ){ return ""; }

 if( $Array["LockType"] == "P_FileLock" )
   {
    $Dir = mb_substr( $File, 0, mb_strrpos( $File, "/" ) );
    $Array["Lock"] = P_FileLock( $File, $Dir, "2" );
   }
   else
 if( $Array["LockType"] == "P_FileLock_Serializable" )
   {
    $Dir = mb_substr( $File, 0, mb_strrpos( $File, "/" ) );
    $Array["Lock"] = P_FileLock_Serializable( $File, $Dir );
   }
   else
 if( $Array["LockType"] == "P_FileLock2_Serializable" )
   { $Array["Lock"] = P_FileLock2_Serializable( $File ); }
   else
   { $Array["Lock"] = P_FileLock2( $File ); }

 if( $Array["Lock"] == FALSE )
   {
    return "P_FileIO\P_FileIO_Private_Function.inc\nLine 308\n";
   }
}

/*********************************************************************/
function P_FileIO_LockFree( &$Array )
{
 if( $Array["Synchronized"] == "OFF" ){ return ""; }

 if( $Array["UnLockType"]( $Array["Lock"] ) == FALSE )
   {
    return "P_FileIO\P_FileIO_Private_Function.inc\nLine 319\n";
   }

 return "";
}

/*********************************************************************/
function P_FileIO_OpenManagement( $File, $Mode )
{
 global $P_FileIO_Management_Array;
 $wkFile = $File["File"];

 if( is_array( P_FileIO_Get_Management_Array( $wkFile ) ) == TRUE )
   { return ""; }

 $Error = P_FileIO_LockGet( $File );

 if( $Error != "" ){ return $Error; }

 $File["PTR"] = @fopen( $File["File"], $File["Mode"] );

// if( $Mode["PTR"] == FALSE )  /* P003 : Change!! */

 if( $File["PTR"] == FALSE )    /* P003 : Change!! */
   {
    $Error = "P_FileIO\P_FileIO_Private_Function.inc\nLine 344\n";

    $Error .= P_FileIO_LockFree( $File );

    return $Error;
   }

 $P_FileIO_Management_Array[$wkFile] = $File;

 return "";
}

/*********************************************************************/
/* P002 : Change Start!! *********************************************/

//function P_FileIO_ReadLine( $File, &$Buffer )

function P_FileIO_ReadLine( $File, &$Buffer, $Chop )

/*********************************************** P002 : Change End!! */
{
 $Buffer = FALSE;
 $Error  = P_FileIO_isOpen( $File );

 if( $Error != "" ){ return $Error; }

 $Array  = P_FileIO_Get_Management_Array( $File );
/* P002 : Change Start!! *********************************************/

// $Buffer = chop( @fgets( $Array["PTR"] ) );

 if( mb_strtoupper( $Chop ) == "OFF" )
   { $Buffer = @fgets( $Array["PTR"] ); }
   else
   { $Buffer = chop( @fgets( $Array["PTR"] ) ); }

/*********************************************** P002 : Change End!! */
 P_FileIO_ConvertEncoding( $Array, $Buffer );

 return "";
}

/*********************************************************************/
function P_FileIO_SetErrorHandler( $BackTrace )
{
 global $P_FileIO_Error; global $P_FileIO_ErrorHandler;

 if( $P_FileIO_ErrorHandler != "" )
   {
    $Array["Type"]     = "FileIO";
    $Array["File"]     = $BackTrace[0]["file"];
    $Array["Line"]     = $BackTrace[0]["line"];
    $Array["Function"] = $BackTrace[0]["function"];
    $Array["Arg"]      = $BackTrace[0]["args"];
    $Array["Value"]    = $P_FileIO_Error;
    $Array["All"]      = $BackTrace;

    $P_FileIO_ErrorHandler( $Array );
   }
}

/*********************************************************************/
function P_FileIO_Synchronized_CloseLocked( )
{
 global $P_FileIO_Management_Array;

 if( @is_array( $P_FileIO_Management_Array ) != TRUE )
   { return; }

 foreach( $P_FileIO_Management_Array as $Array )
 {
  if( @is_resource( $Array["PTR"] ) == TRUE )
    { @fclose( $Array["PTR"] ); }

  if( $Array["DeadLock"] == "OFF" )
    { $Error = P_FileIO_LockFree( $Array ); }
 }
}

/*********************************************************************/
function P_FileIO_WriteLine( $File, $Buffer, &$Result )
{
 $Result = FALSE;
 $Error  = P_FileIO_isOpen( $File );

 if( $Error != "" ){ return $Error; }

 $Array  = P_FileIO_Get_Management_Array( $File );
 P_FileIO_ConvertEncoding( $Array, $Buffer );
 $Result = @fwrite( $Array["PTR"], $Buffer );
 $Bool   = @fflush( $Array["PTR"] );

 return "";
}

/*********************************************************************/
global $P_FileIO_ErrorHandler;
$P_FileIO_ErrorHandler = "";

global $P_FileIO_Management_Array;
$P_FileIO_Management_Array = array( );

@register_shutdown_function( "P_FileIO_Synchronized_CloseLocked" );

?>
