<?php
function P_CSS_Cnv_ArraySet( $Array )
{
 global $P_CSS_Cnv_Array;

 if( is_array( $Array ) != TRUE ){ return; }

 foreach( $Array as $Key => $Value )
 {
  $P_CSS_Cnv_Array[$Key] = $Value;
 }
}

?>
