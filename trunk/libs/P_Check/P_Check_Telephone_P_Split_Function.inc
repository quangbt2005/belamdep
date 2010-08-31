<?php
function P_Check_Telephone_P_Split( $Tel1, $Tel2, $Tel3, $Add = "" )
{
 if( strlen( $Tel1 ) <= 0 &&
     strlen( $Tel2 ) <= 0 &&
     strlen( $Tel3 ) <= 0 ){ return ""; }

 $Tel1 = mb_ereg_replace( "\D", "", $Tel1 );
 $Tel2 = mb_ereg_replace( "\D", "", $Tel2 );
 $Tel3 = mb_ereg_replace( "\D", "", $Tel3 );

 if( P_Check_Telephone_P( $Tel1.$Tel2.$Tel3 ) != TRUE ){ return FALSE; }

 if( mb_strtoupper( $Add ) == "D" ){ $Add = ""; }
   else
 if( $Add == "" ){ $Add = "-"; }

 if( strlen( $Tel1 ) > 0 ){ $Array[] = $Tel1; }
 if( strlen( $Tel2 ) > 0 ){ $Array[] = $Tel2; }
 if( strlen( $Tel3 ) > 0 ){ $Array[] = $Tel3; }

 return implode( $Add, $Array );
}

@include_once( LIB_PATH . "P_Check/P_Check_Telephone_P_Function.inc" );

?>
