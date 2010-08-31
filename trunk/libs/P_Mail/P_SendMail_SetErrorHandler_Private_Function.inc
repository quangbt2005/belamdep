<?php
function P_SendMail_Error_SetErrorHandler( $Backtrace )
{
 global $P_SendMail_Error; global $P_SendMail_ErrorHandler;

 if( $P_SendMail_ErrorHandler != "" )
   {
    $Array["Type"]     = "SendMail";
    $Array["File"]     = $Backtrace[0]["file"];
    $Array["Line"]     = $Backtrace[0]["line"];
    $Array["Function"] = $Backtrace[0]["function"];
    $Array["Arg"]      = $Backtrace[0]["args"];
    $Array["Value"]    = $P_SendMail_Error;
    $Array["All"]      = $Backtrace;

    $P_SendMail_ErrorHandler( $Array );
   }
}

global $P_SendMail_ErrorHandler;
$P_SendMail_ErrorHandler = "";

?>
