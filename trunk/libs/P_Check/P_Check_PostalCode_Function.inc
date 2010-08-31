<?php
function P_Check_PostalCode( $Zip )
{
 $Result = FALSE;

 $Pattern = "^(".
            "\\d{3}|".
            "\\d{5}|".
            "\\d{7}|".
            "\\d{3}-\\d{2}|".
            "\\d{3}-\\d{4}".
            ")\$";

 if( mb_ereg( $Pattern, $Zip ) == TRUE ){ $Result = TRUE; }

 return $Result;
}

?>
