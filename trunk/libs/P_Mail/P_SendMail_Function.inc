<?php
function P_SendMail( $Link, $Add_Header, $From1, $From2, $To, $Cc,
                     $Bcc, $ReplyTo, $Subject, $Core_Msg, $SKIP_FLG = "" )
{
 global $P_SendMail_Error; $P_SendMail_Error = "";


 if( function_exists( "debug_backtrace" ) == TRUE )
   { $BackTrace = debug_backtrace( ); }

 if( $Link == "" || $From1   == "" || $From2     == "" ||
     $To   == "" || $Subject == "" || $Core_Msg  == "" )
   {
    $P_SendMail_Error .= "P_Mail\P_SendMail_Function.inc\nLine 14\n";
    P_SendMail_Error_SetErrorHandler( $BackTrace ); /* P002 : Add!! */
    return FALSE;
   }

if( strtoupper( SendMail_CHECK_ADDRESS_LIST ) == "ON" )
  {
   if( WWW_Config_Server_ENV( ) != "REAL" ||
       strtoupper( CHECK_ADDRESS_LIST ) == "ON" )
     {
      $Address_Array = array( );
      if( strlen( $From1 )   > 0 ){ $Address_Array["Env-From"] = $From1; }
      if( strlen( $From2 )   > 0 ){ $Address_Array["From"]     = $From2; }
      if( strlen( $To )      > 0 ){ $Address_Array["To"]       = $To; }
      if( strlen( $Cc )      > 0 ){ $Address_Array["Cc"]       = $Cc; }
      if( strlen( $Bcc )     > 0 ){ $Address_Array["Bcc"]      = $Bcc; }
      if( strlen( $ReplyTo ) > 0 ){ $Address_Array["Reply-To"] = $ReplyTo; }

      $P_SendMail_Error .= P_TemplateMail_Check_Address_List( $Address_Array );

      if( strlen( $P_SendMail_Error ) > 0 )
        {
         P_SendMail_Error_SetErrorHandler( $BackTrace );
         return FALSE;
        }
     }
  }

 if( substr( $Link, ( strlen( $Link ) - 1 ), 1 ) != "/" )
   { $Link .= "/"; }

 if( is_file( $Link."sendmail" ) == FALSE )
   {
    $P_SendMail_Error .= "P_Mail\P_SendMail_Function.inc\nLine 47\n";
    P_SendMail_Error_SetErrorHandler( $BackTrace ); /* P002 : Add!! */
    return FALSE;
   }

 $Cmd_Line = sprintf( "%s/sendmail -f %s -t -oi", $Link, $From1 );
 $Temp     = "From: ".$From2." \n";
 $Temp    .= "To: ".$To." \n";

 if( $Cc != "" )        { $Temp .= "Cc: ".$Cc." \n"; }

 if( $Bcc != "" )       { $Temp .= "Bcc: ".$Bcc." \n"; }

 if( $ReplyTo != "" )   { $Temp .= "Reply-To: ".$ReplyTo." \n"; }

 if( $Add_Header != "" ){ $Temp .= $Add_Header." \n"; }

 $Subject = "=?ISO-2022-JP?B?".
            base64_encode( mb_convert_encoding( $Subject,
            "JIS", mb_internal_encoding( ) ) )."?=";

 $Temp     .= "Subject: ".$Subject." \n";

 $Temp     .= "MIME-Version: 1.0\n".
              "Content-Type: text/plain; charset=\"ISO-2022-JP\"\n".
              "Content-Transfer-Encoding: 7bit\n\n";

 $Core_Msg  =
 mb_convert_encoding( $Core_Msg, "JIS", mb_internal_encoding( ) );

 $Temp     .= $Core_Msg." \n";
 $Array     = explode( "\n", $Temp );

 if( strlen( $SKIP_FLG ) <= 0 )
   {
    for( $XX = 0;  $XX < count( $Array ); ++$XX )
    {
     if( strlen( $Array[$XX] ) > 997 )
       {
        $P_SendMail_Error .= "P_Mail\P_SendMail_Function.inc\nLine 86\n";
        P_SendMail_Error_SetErrorHandler( $BackTrace ); /* P002 : Add!! */
        return FALSE;
       }
    }
   }

 $Fp    = @popen( $Cmd_Line, "w" );
 $Ret_P = @fputs( $Fp, $Temp );
 @pclose( $Fp );

 return( $Ret_P );
}

@include_once( LIB_PATH . "P_Mail/P_SendMail_SetErrorHandler_Private_Function.inc" );

if( strtoupper( SendMail_CHECK_ADDRESS_LIST ) == "ON" )
  {
   @include_once( LIB_PATH . "WWW_Config/WWW_Config_Server_ENV_Function.inc" );
   @include_once( LIB_PATH . "P_Mail/P_Mail_Check_P_Function.inc" );
   @include_once( LIB_PATH . "P_Mail/P_Mail_Check_P2_Function.inc" );

   if( WWW_Config_Server_ENV( ) != "REAL" ||
       strtoupper( CHECK_ADDRESS_LIST ) == "ON" )
     {
      @include_once( LIB_PATH . "WWW_Config/WWW_Config_Include_Dir_Function.inc" );
      @include_once( LIB_PATH . "P_TemplateMail/P_TemplateMail_Private_Function.inc" );
      @include_once( LIB_PATH . "P_TemplateMail/P_TemplateMail_Address_List_Private_Function.inc" );
     }
  }
?>
