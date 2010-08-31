<?php
function P_SendMail_ErrorHandler( $Function )
{
 global $P_SendMail_ErrorHandler;

 $P_SendMail_ErrorHandler = $Function;
}

?>
