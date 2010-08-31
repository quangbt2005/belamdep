<?php
function P_Date_NextHour( $Date, $Number )
{
 P_Date_GetTimeStamp( $Date, $Number, $TimeStamp );

 if( $TimeStamp == FALSE ){ return FALSE; }

 return date( "YmdHis", ( $TimeStamp + ( 3600 * $Number ) ) );
}
@include_once( LIB_PATH . "P_Date/P_Date_Private_Function.inc" );

?>
