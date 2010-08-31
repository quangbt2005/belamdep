<?php
function P_Date_GetTimeStamp( &$Date, &$Number, &$TimeStamp )
{
 $TimeStamp = "";

 if( $Date == "" ){ $Date = date( "Y-m-d H:i:s" ); }

 $Date   = mb_ereg_replace( "\D", "", $Date );
 $Number = mb_ereg_replace( "\D", "", $Number );
 $Year   = sprintf( "%d", substr( $Date, 0,  4 ) );
 $Month  = sprintf( "%d", substr( $Date, 4,  2 ) );
 $Day    = sprintf( "%d", substr( $Date, 6,  2 ) );
 $Hour   = sprintf( "%d", substr( $Date, 8,  2 ) );
 $Min    = sprintf( "%d", substr( $Date, 10, 2 ) );
 $Sec    = sprintf( "%d", substr( $Date, 12, 2 ) );
 $Number = sprintf( "%d", $Number );

 if( $Number < 0 ){ $Number = 0; }

 if( checkdate( $Month, $Day, $Year ) != TRUE ){ return; }

 if( !( ( 0 <= $Hour && $Hour <= 23 ) &&
        ( 0 <= $Min  && $Min  <= 59 ) &&
        ( 0 <= $Sec  && $Sec  <= 59 ) ) )      { return; }

 $TimeStamp = mktime( $Hour, $Min, $Sec, $Month, $Day, $Year );
}

function P_Date_GetDate( $Date )
{
 if( $Date == "" ){ return; }

 $Date  = mb_ereg_replace( "\D", "", $Date );
 $Year  = sprintf( "%d", substr( $Date, 0,  4 ) );
 $Month = sprintf( "%d", substr( $Date, 4,  2 ) );
 $Day   = sprintf( "%d", substr( $Date, 6,  2 ) );

 if( $Year == 0 || $Month == 0 || $Day == 0 ){ return; }

 while( 1 )
 {
  if( checkdate( $Month, $Day, $Year ) == TRUE ){ break; }

  --$Day;

  if( $Day   <= 0 ){ $Day = 31;   --$Month; }

  if( $Month <= 0 ){ $Month = 12; --$Year; }
 }

 return  sprintf( "%04d", $Year  ).
         sprintf( "%02d", $Month ).
         sprintf( "%02d", $Day   ).
         substr( $Date, 8 );
}

?>
