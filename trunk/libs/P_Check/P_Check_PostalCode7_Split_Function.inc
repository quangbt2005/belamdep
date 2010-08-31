<?php
function P_Check_PostalCode7_Split( $Zip1, $Zip2, $Add = "" )
{
 if( strlen( $Zip1 ) <= 0 || strlen( $Zip2 ) <= 0 ){ return ""; }

 if( mb_strtoupper( $Add ) == "D" ){ $Add = ""; }
   else
 if( $Add == "" ){ $Add = "-"; }

 if( P_Check_PostalCode7( $Zip1.$Zip2 ) != TRUE ){ return FALSE; }

 return $Zip1.$Add.$Zip2;
}

@include_once( LIB_PATH . "P_Check/P_Check_PostalCode7_Function.inc" );

?>
