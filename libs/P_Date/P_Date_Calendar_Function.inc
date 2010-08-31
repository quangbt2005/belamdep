<?php
function P_Date_Calendar( $Year, $Month )
{
 $Year  = mb_ereg_replace( "\D", "", $Year );
 $Month = mb_ereg_replace( "\D", "", $Month );
 $Year  = sprintf( "%d", substr( $Year,  0, 4 ) );
 $Month = sprintf( "%d", substr( $Month, 0, 2 ) );

 if( $Year  == 0 ){ $Year  = sprintf( "%d", date( "Y" ) ); }

 if( $Month == 0 ){ $Month = sprintf( "%d", date( "m" ) ); }

 if( checkdate( $Month, 1, $Year ) != TRUE )
   {
    return array( "\t\t\t\t\t\t", "\t\t\t\t\t\t", "\t\t\t\t\t\t",
                  "\t\t\t\t\t\t", "\t\t\t\t\t\t" );
   }

 $Max_Day    = date( "t", mktime( 0, 0, 0, $Month, 1,        $Year ) );
 $First_Week = date( "w", mktime( 0, 0, 0, $Month, 1,        $Year ) );
 $Last_Week  = date( "w", mktime( 0, 0, 0, $Month, $Max_Day, $Year ) );

 if( $Max_Day == 28 && $First_Week == 0 ){ $Month_Week = 4; }
 else
 if( $Max_Day >= 30 && $First_Week == 6 ){ $Month_Week = 6; }
 else
 if( $Max_Day == 31 && $First_Week >= 5 ){ $Month_Week = 6; }
 else                                    { $Month_Week = 5; }

 for( $XX = 0, $ZZ = 0; $XX < $Month_Week; ++$XX )
 {
  unset( $WK_Array ); 

  for( $YY = 0; $YY < 7; ++$YY )
  {
   if( $XX == 0 && $First_Week > $YY ){ $WK_Array[] = ""; }
     else
   if( ( ( $XX + 1 ) >= $Month_Week ) && $Last_Week < $YY )
     { $WK_Array[] = ""; }
     else
     { ++$ZZ; $WK_Array[] = $ZZ;  }
  }

  $Array[] = implode( "\t", $WK_Array );
 }

 return $Array;
}

?>
