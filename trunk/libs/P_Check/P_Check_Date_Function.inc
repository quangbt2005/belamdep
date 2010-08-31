<?php
function P_Check_Date( $Date )
{
 $Date = mb_ereg_replace( "\D", "", $Date );

 if( strlen( $Date ) != 8 ){ return FALSE; }

 $Year  = sprintf( "%d", substr( $Date, 0, 4 ) );
 $Month = sprintf( "%d", substr( $Date, 4, 2 ) );
 $Day   = sprintf( "%d", substr( $Date, 6, 2 ) );

 if( checkdate( $Month, $Day, $Year ) != TRUE ){ return FALSE; }

 return TRUE;
}

?>
