<?php
function P_FileIO_isDir( $Dir, $Safe_Mode = "SECURE" )
{

 if( @is_dir( $Dir ) != TRUE ){ return FALSE; }

 return P_FileIO_isSearch( $Dir, "2", $Safe_Mode );
}

@include_once( LIB_PATH . "P_FileIO/P_FileIO_isPrivate_Function.inc" );

?>
