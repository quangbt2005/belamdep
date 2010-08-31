<?php
function P_Check_DateTime( $DateTime )
{
 $DateTime = mb_ereg_replace( "\D", "", $DateTime );

 if( strlen( $DateTime ) != 14 ){ return FALSE; }

 $Year  = sprintf( "%d", substr( $DateTime, 0,  4 ) );
 $Month = sprintf( "%d", substr( $DateTime, 4,  2 ) );
 $Day   = sprintf( "%d", substr( $DateTime, 6,  2 ) );
 $Hour  = sprintf( "%d", substr( $DateTime, 8,  2 ) );
 $Min   = sprintf( "%d", substr( $DateTime, 10, 2 ) );
 $Sec   = sprintf( "%d", substr( $DateTime, 12, 2 ) );

 if( checkdate( $Month, $Day, $Year ) != TRUE ){ return FALSE; }

 if( !( ( 0 <= $Hour && $Hour <= 23 ) &&
        ( 0 <= $Min  && $Min  <= 59 ) &&
        ( 0 <= $Sec  && $Sec  <= 59 ) ) )      { return FALSE; }

 return TRUE;
}

?>
