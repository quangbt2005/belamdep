<?php
function P_Check_Time( $Time )
{
 $Time = mb_ereg_replace( "\D", "", $Time );

 if( strlen( $Time ) != 6 ){ return FALSE; }

 $Hour  = sprintf( "%d", substr( $Time, 0, 2 ) );
 $Min   = sprintf( "%d", substr( $Time, 2, 2 ) );
 $Sec   = sprintf( "%d", substr( $Time, 4, 2 ) );

 if( !( ( 0 <= $Hour && $Hour <= 23 ) &&
        ( 0 <= $Min  && $Min  <= 59 ) &&
        ( 0 <= $Sec  && $Sec  <= 59 ) ) ){ return FALSE; }

 return TRUE;
}

?>
