<?php
function P_Check_SearchString( $In01, $In02 )
{
 if( $In02 == "" ){ return FALSE; }

 $Result = TRUE;
 $Count  = mb_strlen( $In01 );

 for( $XX = 0; $XX < $Count; ++$XX )
 {
  $Check = mb_substr( $In01, $XX, 1 );

 $Ichi = mb_strpos( $In02, $Check );

 if( mb_strlen( $Ichi ) <= 0 ){ $Result = FALSE; break; }

 }

 return $Result;
}

?>
