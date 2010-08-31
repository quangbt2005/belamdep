<?php
function P_Date_PrevInterval( $Date1, $Date2 )
{
 $Number = 0;

 P_Date_GetTimeStamp( $Date1, $Number, $TimeStamp1 );
 P_Date_GetTimeStamp( $Date2, $Number, $TimeStamp2 );

 if( $TimeStamp1 == FALSE || $TimeStamp2 == FALSE ){ return 0; }

 if( $TimeStamp2 >= $TimeStamp1 ){ return 0; }

 if( 86400 > ( $TimeStamp1 - $TimeStamp2 ) ){ return 1; }

 return
 ( sprintf( "%d", ( ( $TimeStamp1 - $TimeStamp2 ) / 86400 ) ) + 1 );
}

@include_once( LIB_PATH . "P_Date/P_Date_Private_Function.inc" );

?>
