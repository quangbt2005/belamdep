<?php
function P_SendMail_Attached( $In_Array, $MAC9 = "", $RFC2231 = "" )
{
 global $P_SendMail_Error; $P_SendMail_Error = "";

 if( @function_exists( "debug_backtrace" ) == TRUE )
   { $BackTrace = debug_backtrace( ); }

 $P_SendMail_Error .=
 P_SendMail_Init_Check_Attached( $In_Array, $MAC9, $RFC2231 );

 if( $P_SendMail_Error != "" )
   { P_SendMail_Error_SetErrorHandler( $BackTrace ); return FALSE; }

 $P_SendMail_Error .= P_TemplateMail_Check_Parse_Text( $In_Array );

 if( $P_SendMail_Error != "" )
   { P_SendMail_Error_SetErrorHandler( $BackTrace ); return FALSE; }

 P_SendMail_Change_Attached( $In_Array, $MAC9, $RFC2231 );

 $P_SendMail_Error .= P_TemplateMail_Go_SendMail( $In_Array );

 if( $P_SendMail_Error != "" )
   { P_SendMail_Error_SetErrorHandler( $BackTrace ); return FALSE; }

 return TRUE;
}

@include_once( LIB_PATH . "P_Mail/P_SendMail_Private_Function.inc" );
@include_once( LIB_PATH . "P_Mail/P_SendMail_SetErrorHandler_Private_Function.inc" );
@include_once( LIB_PATH . "P_Hex/P_Hex_IPtoHEX_Function.inc" );
@include_once( LIB_PATH . "P_FileIO/P_FileIO_isFile_Function.inc" );
@include_once( LIB_PATH . "P_TemplateMail/P_TemplateMail_SendMail_Function.inc" );

?>
