<?php
function P_FileIO_isSecureFile( $File, $Safe_Mode = "SECURE" )
{
 return P_FileIO_isSearch( $File, "1", $Safe_Mode );
}

@include_once( LIB_PATH . "P_FileIO/P_FileIO_isPrivate_Function.inc" );

?>
