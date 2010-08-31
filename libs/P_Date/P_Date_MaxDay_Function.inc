<?php
function P_Date_MaxDay( $Year, $Month )
{
 $Year  = mb_ereg_replace( "\D", "", $Year );
 $Month = mb_ereg_replace( "\D", "", $Month );
 $Year  = sprintf( "%d", substr( $Year,  0, 4 ) );
 $Month = sprintf( "%d", substr( $Month, 0, 2 ) );

 if( $Year  == 0 ){ $Year  = sprintf( "%d", date( "Y" ) ); }

 if( $Month == 0 ){ $Month = sprintf( "%d", date( "m" ) ); }

 if( checkdate( $Month, 1, $Year ) != TRUE ){ return 0; }

 return date( "t", mktime( 0, 0, 0, $Month, 1, $Year ) );
}

?>
