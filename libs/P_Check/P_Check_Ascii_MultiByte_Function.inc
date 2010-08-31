<?php
function P_Check_Ascii_MultiByte( $In, $Type )
{
 $Count = mb_strlen( $In );

 for( $XX = 0; $XX < $Count; ++$XX )
 {
  $Moji = mb_substr( $In, $XX, 1 );

  if( strlen( $Moji ) > 1 && $Type == "1" ){ return FALSE; }
    else
  if( strlen( $Moji ) < 2 && $Type == "2" ){ return FALSE; }
 }

 return TRUE;
}

?>
