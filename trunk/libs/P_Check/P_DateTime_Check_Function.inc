<?php
function P_DateTime_Check( $In, $Flg, $Type )
{
 switch( $Type )
 {
  case "Date" : {
                 $Year  = sprintf( "%d", substr( $In, 0, 4 ) );
                 $Month = sprintf( "%d", substr( $In, 4, 2 ) );
                 $Day   = sprintf( "%d", substr( $In, 6, 2 ) );
                 $Ws    = 8;
                 $Type  = "Date";
                 break;
                }
  case "Time" : {
                 $Hour   = sprintf( "%d", substr( $In, 0, 2 ) );
                 $Minute = sprintf( "%d", substr( $In, 2, 2 ) );
                 $Second = sprintf( "%d", substr( $In, 4, 2 ) );
                 $Ws     = 6;
                 $Type   = "Time";
                 break;
                }
  default     : {
                 $Year   = sprintf( "%d", substr( $In, 0, 4 ) );
                 $Month  = sprintf( "%d", substr( $In, 4, 2 ) );
                 $Day    = sprintf( "%d", substr( $In, 6, 2 ) );
                 $Hour   = sprintf( "%d", substr( $In, 8, 2 ) );
                 $Minute = sprintf( "%d", substr( $In, 10, 2 ) );
                 $Second = sprintf( "%d", substr( $In, 12, 2 ) );
                 $Ws     = 14;
                 $Type   = "DateTime";
                 $Date   = substr( $In, 0, 8 );
                 break;
                }
 }

 if( strlen( $In ) != $Ws )
   {
    if( $In == "" )
      { if( $Flg == "0" ){ return 1; } }
      else               { return 2; }
   }

 if( P_Word_Check_Beta( $In, "0123456789" ) != TRUE ){ return 3; }

 if( $Type != "Time" )
   {
    if( checkdate( $Month, $Day, $Year ) != TRUE )
      {
       if( $Flg != "0" )
         {
          if( strcmp( $Date, "00000000" ) != 0 && $Date != "" )
            { return 4; }
         }
         else{ return 4; }
      }
   }

 if( $Type != "Date" )
   {
    if( !( 0 <= $Hour   && $Hour   <= 23 &&
           0 <= $Minute && $Minute <= 59 &&
           0 <= $Second && $Second <= 59 ) )
      { return 5; }
   }

 return 0;
}

@include_once( LIB_PATH . "P_Check/P_Word_Check_Beta_Function.inc" );

?>
