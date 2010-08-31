<?php
function P_Check_Telephone_P2( $Tel )
{
 $Result = FALSE;
 $WK     = mb_ereg_replace( "\\D", "", $Tel );

 if( mb_strlen( $WK ) <= 0 ){ return $Result; }

 if( !( $WK              == $Tel &&
        mb_strlen( $WK ) == mb_strlen( $Tel ) ) ){ return $Result; }

 $Result = P_Check_Telephone_P( $Tel );

 return $Result;
}

@include_once( LIB_PATH . "P_Check/P_Check_Telephone_P_Function.inc" );

?>
