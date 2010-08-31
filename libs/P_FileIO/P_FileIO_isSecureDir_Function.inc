<?php
function P_FileIO_isSecureDir( $Dir, $Safe_Mode = "SECURE" )
{
 return P_FileIO_isSearch( $Dir, "2", $Safe_Mode );
}

@include_once( LIB_PATH . "P_FileIO/P_FileIO_isPrivate_Function.inc" );

?>
