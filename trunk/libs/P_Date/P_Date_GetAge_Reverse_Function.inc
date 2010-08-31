<?php
function P_Date_GetAge_Reverse( $Age, $Date = "" )
{
 $Age = sprintf( "%d", $Age );
 if( $Age < 0 ){ return FALSE; }

 $Date1 = P_Date_PrevYear( $Date, $Age );
 $Date2 = P_Date_PrevYear( $Date1, 1 );
 $Date2 = P_Date_NextDay(  $Date2, 1 );

 $Date1 = mb_substr( $Date1, 0, 8 )."235959";
 $Date2 = mb_substr( $Date2, 0, 8 )."000000";

 $Out_Array = array( );
 $Out_Array["AGE"]        = $Age;
 $Out_Array["DATE"]       =  mb_substr( $Date1, 0, 8 );
 $Out_Array["START_DATE"] =  $Date2;
 $Out_Array["END_DATE"]   =  $Date1;

 return $Out_Array;
}
@include_once( LIB_PATH . "P_Date/P_Date_PrevYear_Function.inc" );
@include_once( LIB_PATH . "P_Date/P_Date_NextDay_Function.inc" );

?>
