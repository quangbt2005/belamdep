<?php
function P_Check_Telephone_P2O( $Tel )
{
 $Result = FALSE;
 $WK     = mb_ereg_replace( "\\D", "", $Tel );

 if( mb_strlen( $WK ) <= 0 ){ return $Result; }

 if( !( $WK              == $Tel &&
        mb_strlen( $WK ) == mb_strlen( $Tel ) ) ){ return $Result; }

 $Result = P_Check_Telephone_P( $Tel );

 if( $Result != TRUE ){ return $Result; }

 $Result = FALSE;
 $Bool   = P_Check_TelephoneType( $Tel );

 if( mb_strtolower( $Bool ) == "m" ){ return $Result; }

 $Result = TRUE;

 return $Result;
}

@include_once( LIB_PATH . "P_Check/P_Check_Telephone_P_Function.inc" );
@include_once( LIB_PATH . "P_Check/P_Check_TelephoneType_Function.inc" );

?>
