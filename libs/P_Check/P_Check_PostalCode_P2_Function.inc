<?php
function P_Check_PostalCode_P2( $Zip )
{
 $Result = FALSE;
 $WK     = mb_ereg_replace( "\\D", "", $Zip );

 if( mb_strlen( $WK ) <= 0 ){ return $Result; }

 if( !( $WK              == $Zip &&
        mb_strlen( $WK ) == mb_strlen( $Zip ) ) ){ return $Result; }

 $Result = P_Check_PostalCode( $Zip );

 return $Result;
}

@include_once( LIB_PATH . "P_Check/P_Check_PostalCode_Function.inc" );

?>
