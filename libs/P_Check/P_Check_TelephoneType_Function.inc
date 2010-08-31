<?php
function P_Check_TelephoneType( $Tel )
{
 $Result  = "w";
 $Tel     = mb_ereg_replace( "\\D", "", $Tel );
 $Pattern = "^(090|080|070)";

 if( strlen( $Tel ) != 11 ){ return $Result; }

 if( mb_ereg( $Pattern, $Tel ) == TRUE ){ $Result = "m"; }

 return $Result;
}

?>
