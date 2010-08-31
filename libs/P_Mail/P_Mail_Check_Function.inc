<?php
function P_Mail_Check( $Mail )
{
	$t="^[_\\.0-9a-z-]+@([0-9a-z][-0-9a-z\.]+)\\.([a-z]{2,3}\$)";
	
 if( eregi( "^[_\\.0-9a-z-]+@([0-9a-z][-0-9a-z\.]+)\\.([a-z]{2,3}\$)",
     $Mail, $Check ) )
   { return TRUE; }
   else
   { return FALSE; }
}

?>
