<?php
function P_MySQL_Error_SetErrorHandler( $Backtrace )
{
 global $P_MySQL_Error; global $P_MySQL_ErrorHandler;

 if( $P_MySQL_ErrorHandler != "" )
   {
    $Array["Type"]     = "MySQL";
    $Array["File"]     = $Backtrace[0]["file"];
    $Array["Line"]     = $Backtrace[0]["line"];
    $Array["Function"] = $Backtrace[0]["function"];
    $Array["Arg"]      = $Backtrace[0]["args"];
    $Array["Value"]    = $P_MySQL_Error;
    $Array["All"]      = $Backtrace;

    $P_MySQL_ErrorHandler( $Array );
   }
}

global $P_MySQL_ErrorHandler;
$P_MySQL_ErrorHandler = "";

?>
