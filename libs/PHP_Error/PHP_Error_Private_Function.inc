<?php
function PHP_Error_Config_Init( &$Array )
{
 if( WWW_Config_Server_ENV( ) == "DEBUG" ){ return ; } /* P005 : Add!! */

 $Conf = "/PUBDATA/".WWW_Config_Include_Dir( )."/CgiError/CgiError.conf";
/* P008 : Add Start!! ************************************************/

 global $WWW_Config;

 if( $WWW_Config["MG_WWW_ENV_FLG"] == "MG002" )
   {
    $Conf = "/WWW/".WWW_Config_Include_Dir( )."/data/CgiError/CgiError.conf";
   }

/************************************************** P008 : Add End!! */

 if( @is_file( $Conf ) == FALSE ){ return ; }

 $Buffer = @file_get_contents( $Conf );

 $Buffer = P_STD_ConvertString( $Buffer );
 $In_Array = mb_split( "\n", $Buffer );
 $In_Array = P_STD_DeleteComment( $In_Array );

 if( is_array( $In_Array ) != TRUE ){ return ; }

 foreach( $In_Array as $Value )
 {
  if( mb_substr( $Value, 0, 3 ) != "TO=" ){ continue; }

  $Array["To"] = mb_substr( $Value, 3 );
 }
}

/*********************************************************************/
function PHP_Error_Display( &$Array )
{
/* P003 : Change Start!! *********************************************/

/**********************************************************************

 if( mb_strtoupper( $Array["Cron"] ) == "ON" )
   { echo $Array["orig_Message"]; return; }

**********************************************************************/

/* P004 : Add Start!! ************************************************/

 if( WWW_Config_Server_ENV( ) != "REAL" )
   {
    global $PHP_Error_EXTRA;
    global $PHP_Error_BACKTRACE;
    global $PHP_Error_SESSION;

    if( mb_strtoupper( $Array["Cron"] ) != "ON" )
      {
       if( mb_strlen( $PHP_Error_SESSION ) > 0 )
         { $Array["orig_Message"] .= "\n".$PHP_Error_SESSION; }
      }

    if( mb_strlen( $PHP_Error_EXTRA ) > 0 )
      { $Array["orig_Message"] .= "\n".$PHP_Error_EXTRA; }

    if( mb_strlen( $PHP_Error_BACKTRACE ) > 0 )
      { $Array["orig_Message"] .= "\n".$PHP_Error_BACKTRACE; }
   }

/************************************************** P004 : Add End!! */

 if( mb_strtoupper( $Array["Cron"] ) == "ON" )
   {
    while( mb_strtoupper( PHP_Error_Batch_DISPLAY ) != "OFF" )
    {
     if( mb_strlen( $Array["orig_Message"] ) <= 0 ){ break; }
     echo $Array["orig_Message"];
     break;
    }

    return;
   }

/*********************************************** P003 : Change End!! */

 $Dir = "/PUBDATA/".WWW_Config_Include_Dir( )."/CgiError/";
/* P008 : Add Start!! ************************************************/

 global $WWW_Config;

 if( $WWW_Config["MG_WWW_ENV_FLG"] == "MG002" )
   {
    $Dir = "/WWW/".WWW_Config_Include_Dir( )."/data/CgiError/";
   }

/************************************************** P008 : Add End!! */

 switch( mb_strtoupper( $Array["Carrier"] ) )
 {
  case "IMODE" : {
                  $File = "imode_error.base";
                  break;
                 }
  case "WAP"   : {
                  $File = "ez_error.base";
                  break;
                 }
  case "SKY"   : {
/* P002 : Change Start!! *********************************************/

/**********************************************************************
                  $File = "imode_error.base";
**********************************************************************/

                  $File = "vodafone_error.base";

/*********************************************** P002 : Change End!! */
                  break;
                 }
  default      : {
                  $File = "web_error.base";
                  break;
                 }
 }

 $File = $Dir.$File;

 while( @is_file( $File ) == FALSE )
 {
  $Dir = "/WWW/PHP/phpsub/PHP4/PHP_Error/base/";
/* P008 : Add Start!! ************************************************/

  global $WWW_Config;

  if( $WWW_Config["MG_WWW_ENV_FLG"] == "MG002" )
    {
     $Dir = "/WWW/".WWW_Config_Include_Dir( )."/php/DNP/PHP4/PHP_Error/base/";
    }

/************************************************** P008 : Add End!! */

  switch( mb_strtoupper( $Array["Carrier"] ) )
  {
   case "IMODE" : {
                   $File = "error_i.base";
                   break;
                  }
   case "WAP"   : {
                   if( mb_strtoupper( XHTML_MODE ) == "ON" )
                     { $File = "error_e_xhtml.base"; }
                     else
                     { $File = "error_e_hdml.base"; }

                   break;
                  }
   case "SKY"   : {
                   $File = "error_j.base";
                   break;
                  }
   default      : {
                   $File = "error_w.base";
                   break;
                  }
  }

  $File = $Dir.$File;
  break;
 }

 if( WWW_Config_Server_ENV( ) == "REAL" ){ $Array["Message"] = ""; }
 if( WWW_Config_Server_ENV( ) == "REAL" ){ $Array["orig_Message"] = ""; } /* P004 : Add!! */

if( P_FileIO_isFile( $Array["URI"], "ON" ) == TRUE )
  { $File = $Array["URI"]; }

 $Buffer = @file_get_contents( $File );
 $Buffer = P_STD_ConvertString( $Buffer, "", "SJIS" );

 $Array["orig_Message"] = htmlspecialchars( $Array["orig_Message"], ENT_QUOTES ); /* P007 : Add!! */

 $Array["orig_Message"] =
 mb_eregi_replace( "\n", "<br>", $Array["orig_Message"] );

 if( mb_strtoupper( $Array["Carrier"] ) == "WAP" )
   {
    if( mb_strtoupper( XHTML_MODE ) == "ON" )
      {
       @header( "Content-type: text/html; charset=Shift_JIS" );
       $Array["orig_Message"] =
       mb_eregi_replace( "<br>", "<br />", $Array["orig_Message"] );
      }
      else
      { @header( "Content-type: text/x-hdml; charset=Shift_JIS" ); }
   }
   else
   { @header( "Content-type: text/html; charset=Shift_JIS" ); }

 $Buffer = mb_eregi_replace( "\\{\\{ PHP_ERROR_MESSAGE \\}\\}",
                                    $Array["orig_Message"], $Buffer );

 if( mb_strlen( WWW_Config_isConvert( "SJIS" ) ) > 0 )
   {
/* P002 : Change Start!! *********************************************/

/**********************************************************************
    $Buffer = 
    mb_convert_encoding( $Buffer, "SJIS",  mb_detect_encoding( ) );
**********************************************************************/

    $Buffer = 
    mb_convert_encoding( $Buffer, "SJIS", mb_internal_encoding( ) );

/*********************************************** P002 : Change End!! */
   }

 while( @ob_end_clean( ) ){ }
 @header( "Content-Length: ".strlen( $Buffer ) );

 echo $Buffer;
}

/*********************************************************************/
function PHP_Error_ENV_Get( &$Array )
{
 $Array["Message"] .= PHP_Error_STDIN_Get_Array( "PHP ENV" );

 $Array["Message"] .= str_repeat( "-", 78 )."\n".
                           "\tENVROMENT\n".
                           str_repeat( "-", 78 )."\n\n";

 $Array["Message"] .= PHP_Error_STDIN_Get_Array( "SERVER" ).
                      PHP_Error_STDIN_Get_Array( "ENV" );

 $Array["Command"] = "/bin/df -k";
 PHP_Error_System_Command( $Array );

 $Array["Command"] = "/usr/bin/uptime";
 PHP_Error_System_Command( $Array );

 $Array["Message"] .= str_repeat( "-", 78 )."\n".
                      "\tSTDIN DATA\n".
                      str_repeat( "-", 78 )."\n\n";

 $Array["Message"] .= PHP_Error_STDIN_Get_Array( "GET" ).
                      PHP_Error_STDIN_Get_Array( "POST" ).
                      PHP_Error_STDIN_Get_Array( "COOKIE" );

/* P004 : Add Start!! ************************************************/

 $Array["Message"] .= PHP_Error_STDIN_Get_Array( "SESSION" ).
                      PHP_Error_STDIN_Get_Array( "EXTRA" ).
                      PHP_Error_STDIN_Get_Array( "BACKTRACE" );

/************************************************** P004 : Add End!! */

 $Array["Message"] .= str_repeat( "-", 78 )."\n";
}

/*********************************************************************/
function PHP_Error_Go_SendMail( &$Array )
{
/* P006 : Change Start!! *********************************************/
/**********************************************************************
 if( WWW_Config_Server_ENV( ) != "REAL" )
   { if( mb_strtoupper( $Array["Type"] ) != "WARNING" ){ return ; } }
**********************************************************************/
 if( WWW_Config_Server_ENV( ) != "REAL" )
   {
    if( mb_strtoupper( $Array["Type"] ) != "WARNING" ){ return ; }

    $Mail_Array = array( );

    $WK_Mail_Array = mb_split( ",", $Array["To"] );

    if( is_array( $WK_Mail_Array ) != TRUE ){ return ; }

    foreach( $WK_Mail_Array as $Value )
    {
     $ICHI = mb_strpos( mb_strtolower( $Value ), "cgi_err@ml.mediagalaxy.ne.jp" );
     if( mb_strlen( $ICHI ) > 0 ){ continue; }

     $WK_Value =  mb_strtolower( $Value );
     $ICHI1    = mb_strpos( $WK_Value, "@digicom.dnp.co.jp" );
     $ICHI2    = mb_strpos( $WK_Value, "@ml.digicom.dnp.co.jp" );
     $ICHI3    = mb_strpos( $WK_Value, ".mg@ml.digicom.dnp.co.jp" );
     $ICHI4    = mb_strpos( $WK_Value, ".mbr@ml.digicom.dnp.co.jp" );

     if( mb_strlen( $ICHI1 ) <= 0 && mb_strlen( $ICHI2 ) <= 0 &&
         mb_strlen( $ICHI3 ) <= 0 && mb_strlen( $ICHI4 ) <= 0 ){ continue; }

     $Mail_Array[] = $Value;
    }

    if( count( $Mail_Array ) <= 0 ){ return ; }
    $Array["To"] = implode( ",", $Mail_Array );
   }
/*********************************************** P006 : Change End!! */

 $Link = "/usr/lib/";
 $Add_Header = $Array["Header"];
 $From1      = $Array["From"];
 $From2      = $Array["From"];
 $To         = $Array["To"];
 $Cc         = "";
 $Bcc        = "";
 $ReplyTo    = $Array["From"];
 $Subject    = $Array["Subject"];
 $Message    = $Array["Message"];

/* P006 : Change Start!! *********************************************/
/**********************************************************************
 P_SendMail( $Link, $Add_Header, $From1, $From2, $To, "", "",
                                       $ReplyTo, $Subject, $Message );
**********************************************************************/
 P_SendMail( $Link, $Add_Header, $From1, $From2, $To, "", "",
                                       $ReplyTo, $Subject, $Message, "OFF" );
/*********************************************** P006 : Change End!! */
}

/*********************************************************************/
function PHP_Error_Init( &$Array, $Message, $Level, $Type,
                                                   $URL, $Mail, $File )
{
 $Array = array( );
 $Array["Level"] = $Level;

 if( mb_strlen( $Array["Level"] ) <= 0 ){ $Array["Level"] = "A"; }

 $Array["Type"]  = $Type;
 $Array["URL"]   = $URL;
 $Array["URI"]   = $File;
 $Array["From"]  = "cgi_err@ml.mediagalaxy.ne.jp";
 $Array["To"]    = "cgi_err@ml.mediagalaxy.ne.jp";
/* P005 : Add Start!! ************************************************/

 if( WWW_Config_Server_ENV( ) == "DEBUG" )
   {
    $Array["From"]  = "PHP-Tech.cc@ml.digicom.dnp.co.jp";
    $Array["To"]    = "PHP-Tech.cc@ml.digicom.dnp.co.jp";
   }

/************************************************** P005 : Add End!! */
 $Array["Host"]  = getenv( "HTTP_HOST" );
 $Array["Cron"]  = "OFF";
 $Array["File"]  = @realpath( $_SERVER["SCRIPT_FILENAME"] );
 $Array["ToDay"] = date( "Y/m/d" );
 $Array["Time"]  = date( "H:i:s" );

 $Array["Carrier"] = P_Carrier_Get( );

 switch( mb_strtoupper( $Array["Carrier"] ) )
 {
  case "D(I)" :
  case "D(F)" : {
                 $Array["Carrier"] = "IMODE";
                 break;
                }
  case "E(1)" :
  case "E(2)" : {
                 $Array["Carrier"] = "WAP";
                 break;
                }
  case "J"    : {
                 $Array["Carrier"] = "SKY";
                 break;
                }
  default     : {
                 $Array["Carrier"] = "WWW";
                 break;
                }
 }

 if( mb_strlen( $Array["Host"] ) <= 0 )
   {
    $Array["Host"] = `/bin/hostname`;
    $Array["Host"] = chop( $Array["Host"] );
    $Array["Cron"]  = "ON";
   }

 $Array["Subject"] = "CgiError [".
                     $Array["Host"]." ".
                     $Array["File"]." ".
                     $Array["ToDay"]." ".
                     $Array["Time"]."]";

 $Array["Message"] = str_repeat( "-", 78 )."\n".
                           "\t".$Array["Subject"]."\n".
                           str_repeat( "-", 78 )."\n\n";

 $Array["Message"] .= $Message."\n\n";

 $Array["orig_Message"] = $Message;

 if( mb_strlen( $Array["orig_Message"] ) > 0 )
   { $Array["orig_Message"] .= "\n"; }

 $Array["Header"]  = "X-ERROR-TYPE: ".$Array["Type"]."\n";
 $Array["Header"] .= "X-ERROR-LEVEL: ".$Array["Level"]."\n";
 $Array["Header"] .= "X-ERROR-SERVER: ".$Array["Host"]."\n";
 $Array["Header"] .= "X-ERROR-DIR_NAME: ".WWW_Config_Include_Dir( )."\n";
 $Array["Header"] .= "X-ERROR-PATH: ".$Array["File"]."\n";
 $Array["Header"] .= "X-ERROR-DATE: ".$Array["ToDay"]."\n";
 $Array["Header"] .= "X-ERROR-TIME: ".$Array["Time"];

 PHP_Error_Config_Init( $Array );

 if( mb_strlen( $Mail ) > 0 ){ $Array["To"] = $Mail; }
}

/*********************************************************************/
function PHP_Error_LocationURL( &$Array )
{
 if( mb_strtoupper( $Array["Cron"] ) == "ON" ){ return; }

 if( mb_strlen( $Array["URL"] ) > 0 )
   { @header( "Location: ".$Array["URL"] ); exit; }
}

/*********************************************************************/
function PHP_Error_STDIN_Get_Array( $Type )
{
/* P004 : Add Start!! ************************************************/
 global $PHP_Error_EXTRA;
 global $PHP_Error_BACKTRACE;
 global $PHP_Error_SESSION;
 $SESSION_FLG = "";

 switch( mb_strtoupper( $Type ) )
 {
  case "GET"     :
  case "COOKIE"  :
  case "POST"    :
  case "SESSION" : { $SESSION_FLG = "ON"; break; }
  default        : { break; }
 }

/************************************************** P004 : Add End!! */
 $String = "";

 switch( mb_strtoupper( $Type ) )
 {
  case "GET"    : { $Array = $_GET;    break; }
  case "COOKIE" : { $Array = $_COOKIE; break; }
  case "POST"   : { $Array = $_POST;   break; }
  case "ENV"    : { $Array = $_ENV;    break; }
  case "SERVER" : { $Array = $_SERVER; break; }
/* P004 : Add Start!! ************************************************/
  case "SESSION"   : {
                      if( defined( "PHP_Error_Send_SessionData" )     == TRUE &&
                          mb_strtoupper( PHP_Error_Send_SessionData ) == "ON" )
                        {
                         global $P_httpSession_Array;
                         $Array = $P_httpSession_Array;
                        }
                        else
                        {
                         return $String;
                        }
                      break;
                     }
  case "EXTRA"     : {
                      global $PHP_Error_Extra_Array;
                      $Array = $PHP_Error_Extra_Array;

                      if( is_array( $Array ) != TRUE ){ return $String; }

                      $String .= "[".$Type."]\n\n";

                      foreach( $Array as $Value )
                      {
                       $String .= $Value."\n";
                      }

                      $String .= "\n";
                      $PHP_Error_EXTRA = $String;

                      return $String;
                      break;
                     }
  case "BACKTRACE" : {
                      if( function_exists( "debug_backtrace" ) != TRUE )
                        { return $String; }

                      $BackTrace = debug_backtrace( );

                      if( is_array( $BackTrace ) != TRUE ){ return $String; }

                      $String .= "[".$Type."]\n\n";

                      $XX = 0;
                      foreach( $BackTrace as $Value )
                      {
                       ++$XX;

                       if( $XX <= 2 )
                         {
                          if( $XX > 1 ){ $String .= $Value["file"]."\n"; }
                          continue;
                         }

                       $String .= $Value["file"].
                                  "(".$Value["line"].")".
                                  "[".$Value["function"]."]\n";
                      }

                      $String .= "\n";
                      $PHP_Error_BACKTRACE = $String;

                      return $String;
                      break;
                     }
/************************************************** P004 : Add End!! */
  default       : {
                   return str_repeat( "-", 78 )."\n".
                          "\tPerl ENV\n".
                          str_repeat( "-", 78 )."\n\n".
                          "I'm sorry.\n".
                          "PHP can't acquire the environment ".
                          "variable of Perl.\n\n";
                    break;
                  }
 }

 if( is_array( $Array ) == TRUE )
   {
    $String .= "[".$Type."]\n\n";

/* P005 : Change Start!! *********************************************/

/**********************************************************************
    foreach( $Array as $Key => $Value )
    { $String .= $Key." : ".$Value."\n"; }
**********************************************************************/

    foreach( $Array as $Key => $Value )
    {
     $T_Value = preg_replace( "/[\\x00-\\x08]|[\\x0B-\\x0C]|[\\x0E-\\x1F]/", "", $Value );

    if( mb_strtoupper( mb_internal_encoding( ) ) != "UTF-8" &&
        mb_strtoupper( mb_internal_encoding( ) ) != "UTF8" )
      {
        $T_Value = mb_convert_encoding( $T_Value,
                   mb_internal_encoding( ), mb_detect_order( ) );
      }

     $String .= $Key."      : ".$T_Value."\n";
     $String .= $Key."(HEX) : ".bin2hex($Value)."\n";
     $String .= $Key."(LEN) : ".strlen($Value)."\n"; /* P006 : Add!! */
    }
/*********************************************** P005 : Change ENd!! */

    $String .= "\n";
   }

 if( mb_strlen( $SESSION_FLG ) > 0 ){ $PHP_Error_SESSION .= $String; } /* P004 : Add!! */

 return $String;
}

/*********************************************************************/
function PHP_Error_System_Command( &$Array )
{
 if( mb_strtolower( $Array["Command"] ) == "/bin/df -k" )
   { $Flg = "df"; }
   else
   { $Flg = "uptime"; }

 switch( $Flg )
 {
  case "df" : {
               $Array["Message"] .= str_repeat( "-", 78 )."\n".
                                         "\tDISK LIST\n".
                                         str_repeat( "-", 78 )."\n\n";
               break;
              }
  default   : {
               $Array["Message"] .= str_repeat( "-", 78 )."\n".
                                         "\tUPTIME LIST\n".
                                         str_repeat( "-", 78 )."\n\n";
               break;
              }
 }

 $Command = $Array["Command"];
 $Array["Message"] .= `$Command`;
 $Array["Message"] .= "\n";
}

global $PHP_Error_Extra_Array; $PHP_Error_Extra_Array = array( ); /*V004:Add!!*/
global $PHP_Error_SESSION;     $PHP_Error_SESSION   = ""; /*V004:Add!!*/
global $PHP_Error_EXTRA;       $PHP_Error_EXTRA     = ""; /*V004:Add!!*/
global $PHP_Error_BACKTRACE;   $PHP_Error_BACKTRACE = ""; /*V004:Add!!*/

?>
