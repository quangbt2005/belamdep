<?php
function P_Date_GetAge( $Date1, $Date2 )
{
 $Age = 0; $Number = 0;

 P_Date_GetTimeStamp( $Date1, $Number, $TimeStamp1 );
 P_Date_GetTimeStamp( $Date2, $Number, $TimeStamp2 );

 if( $TimeStamp1 == FALSE || $TimeStamp2 == FALSE ){ return $Age; }

 $Date1 = date( "YmdHis", $TimeStamp1 );
 $Date2 = date( "YmdHis", $TimeStamp2 );

 if( $Date1 <= $Date2 ){ return $Age; }

 $Age = ( substr( $Date1, 0, 4 ) - substr( $Date2, 0, 4 ) );

 if( substr( $Date1, 4, 4 ) < substr( $Date2, 4, 4 ) ){ --$Age; }

 return $Age;
}
@include_once( LIB_PATH . "P_Date/P_Date_Private_Function.inc" );

?>
