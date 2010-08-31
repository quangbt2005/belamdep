<?php
function P_Date_NextMonth( $Date, $Number )
{
 P_Date_GetTimeStamp( $Date, $Number, $TimeStamp );

 if( $TimeStamp == FALSE ){ return FALSE; }

 $Date  = date( "YmdHis", $TimeStamp );
 $Year  = sprintf( "%d", substr( $Date, 0, 4 ) );
 $Month = sprintf( "%d", substr( $Date, 4, 2 ) );

 if( $Month + $Number <= 12 )
   {
    $Date = sprintf( "%04d", $Year ).
            sprintf( "%02d", ( $Month + $Number ) ).
            substr( $Date, 6  );

    return P_Date_GetDate( $Date );
   }

 $Number1 = sprintf( "%d", ( ( $Month + $Number ) / 12 ) );
 $Number2 = sprintf( "%d", ( ( $Month + $Number ) % 12 ) );

 if( $Number2 == 0 ) { $Number2 = 12; }
 if( $Number2 == 12 ){ --$Number1; }

 $Date = sprintf( "%04d", ( $Year + $Number1 ) ).
         sprintf( "%02d", $Number2 ).
         substr( $Date, 6 );

 return P_Date_GetDate( $Date );
}

@include_once( LIB_PATH . "P_Date/P_Date_Private_Function.inc" );

?>
