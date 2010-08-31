<?php
function P_Date_PrevMonth( $Date, $Number )
{
 P_Date_GetTimeStamp( $Date, $Number, $TimeStamp );

 if( $TimeStamp == FALSE ){ return FALSE; }

 $Date  = date( "YmdHis", $TimeStamp );
 $Year  = sprintf( "%d", substr( $Date, 0, 4 ) );
 $Month = sprintf( "%d", substr( $Date, 4, 2 ) );

 if( ( $Month - $Number ) > 0 )
   {
    $Date = sprintf( "%04d", $Year ).
            sprintf( "%02d", ( $Month - $Number ) ).
            substr( $Date, 6 );

    return P_Date_GetDate( $Date );
   }

 $Number1 = ( $Year - 1 );

 if( $Number == 12 ){ $Number2 = $Month; }
   else
 if( ( $Number % 12 ) == 0 )
   {
    $Number1 -= ( ( $Number / 12 ) - 1 );
    $Number2 = $Month;
   }
   else
 if( $Number < 12 ){ $Number2 = ( 12 - ( $Number - $Month ) ); }
   else
   {
    $Number1 = ( $Year - ( sprintf( "%d", $Number / 12 ) ) );

    $XX = sprintf( "%d", $Number % 12 );

    if( $XX >= $Month )
      {
       --$Number1;
       $Number2 = ( 12 - ( $XX - $Month ) ); 
      }
      else{ $Number2 = $Month - $XX;  }
   }


 $Date = sprintf( "%04d", $Number1 ).
         sprintf( "%02d", $Number2 ).
         substr( $Date, 6 );

 return P_Date_GetDate( $Date );
}

@include_once( LIB_PATH . "P_Date/P_Date_Private_Function.inc" );

?>
