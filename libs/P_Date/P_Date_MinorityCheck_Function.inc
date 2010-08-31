<?php
function P_Date_MinorityCheck( $Date1, $Date2, $Age )
{
 $Age = mb_ereg_replace( "\D", "", $Age );

 if( strlen( $Age ) <= 0 ){ $Age = 20; }

 $Age    = sprintf( "%d", $Age );
 $Result = P_Date_GetAge( $Date1, $Date2 );

 if( $Result >= $Age ){ return TRUE;  }
   else               { return FALSE; }
}
@include_once( LIB_PATH . "P_Date/P_Date_GetAge_Function.inc" );

?>
