<?php
function P_Check_PostalCode7( $Zip )
{
 $Result = FALSE;

 $Pattern = "^(".
            "\\d{7}|".
            "\\d{3}-\\d{4}".
            ")\$";

 if( mb_ereg( $Pattern, $Zip ) == TRUE &&
     substr( $Zip, 0, 3 ) != "000" ){ $Result = TRUE; }

 return $Result;
}

?>
