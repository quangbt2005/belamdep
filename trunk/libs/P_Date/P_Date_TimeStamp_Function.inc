<?php
function P_Date_TimeStamp( $DateTime )
{
 if( strlen( $DateTime ) <= 0 ){ $DateTime = date( "YmdHis" ); }

 $DateTime = mb_ereg_replace( "\D", "", $DateTime );

 if( strlen( $DateTime ) != 14 ){ return 0; }

 $Year   = sprintf( "%d", substr( $DateTime, 0,  4 ) );
 $Month  = sprintf( "%d", substr( $DateTime, 4,  2 ) );
 $Day    = sprintf( "%d", substr( $DateTime, 6,  2 ) );
 $Hour   = sprintf( "%d", substr( $DateTime, 8,  2 ) );
 $Min    = sprintf( "%d", substr( $DateTime, 10, 2 ) );
 $Sec    = sprintf( "%d", substr( $DateTime, 12, 2 ) );

 if( checkdate( $Month, $Day, $Year ) != TRUE ){ return 0; }

 if( !( ( 0 <= $Hour && $Hour <= 23 ) &&
        ( 0 <= $Min  && $Min  <= 59 ) &&
        ( 0 <= $Sec  && $Sec  <= 59 ) ) )      { return 0; }

 return mktime( $Hour, $Min, $Sec, $Month, $Day, $Year );
}

@include_once( LIB_PATH . "P_Date/P_Date_Private_Function.inc" );

?>
