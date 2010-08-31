<?php
function P_SQL_Quote_Escape_String( $SQL, $Reg_Array, $Cnv_Array )
{
 $Pattern = "/[\\x00-\\x08]|[\\x0B-\\x0C]|[\\x0E-\\x1F]/";
 $SQL     = preg_replace( $Pattern, "", $SQL );

 $XX = 0;

 $Count = count( $Reg_Array );

 while( $XX < $Count )
 {
  $SQL = mb_ereg_replace( $Reg_Array[$XX], $Cnv_Array[$XX], $SQL );
  ++$XX;
 }

 return $SQL;
}

?>
