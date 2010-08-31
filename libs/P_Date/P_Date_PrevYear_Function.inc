<?php
function P_Date_PrevYear( $Date, $Number )
{
 return P_Date_PrevMonth( $Date, ( $Number * 12 ) );
}

@include_once( LIB_PATH . "P_Date/P_Date_PrevMonth_Function.inc" );

?>
