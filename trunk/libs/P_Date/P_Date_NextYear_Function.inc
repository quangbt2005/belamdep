<?php
function P_Date_NextYear( $Date, $Number )
{
 return P_Date_NextMonth( $Date, ( $Number * 12 ) );
}

@include_once( LIB_PATH . "P_Date/P_Date_NextMonth_Function.inc" );

?>
