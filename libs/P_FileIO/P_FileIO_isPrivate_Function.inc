<?php
function P_FileIO_isSearch( $Target, $Flg, $Safe_Mode )
{
 if( mb_strtoupper( $Safe_Mode ) == "OFF" ){ return TRUE; }

 if( @is_file( $Target ) == TRUE || @is_dir( $Target ) == TRUE )
   {
    if( mb_strtoupper( $Safe_Mode ) != "ON" )
      { if( @is_link( $Target ) == TRUE ){ return FALSE; } }
   }

 if( mb_strlen( $Target ) !=
     mb_strlen( mb_ereg_replace( "\\.\\./", "", $Target ) ) )
    { return FALSE; }

 $WK_Target = @realpath( $Target );

 if( mb_strlen( $WK_Target ) > 0 )
   {
    $Target = $WK_Target;

    $Ichi = strpos( $Target, "/WWW/" );
    if( $Ichi !== FALSE ){ $Target = substr( $Target, $Ichi ); }

    $Ichi = strpos( $Target, "/MOBILE/" );
    if( $Ichi !== FALSE ){ $Target = substr( $Target, $Ichi ); }

    $Ichi = strpos( $Target, "/PUBDATA/" );
    if( $Ichi !== FALSE ){ $Target = substr( $Target, $Ichi ); }
   }

 if( WWW_Config_MG_ENV( ) == "MG002" )
   {
    $DIR_Array = array( );

    if( mb_strtoupper( $Safe_Mode ) == "ON" )
      {
       $DIR_Array[] = WWW_Config_Web_Dir( )."/";
       $DIR_Array[] = WWW_Config_SWeb_Dir( )."/";
      }

    $DIR_Array[] = WWW_Config_DATA_Dir_Fixed( )."/";
    $DIR_Array[] = WWW_Config_PHP_Dir( )."/";

    foreach( $DIR_Array as $TARGET_DIR )
    {
     if( $TARGET_DIR == substr( $Target, 0, strlen( $TARGET_DIR ) ) )
       { return TRUE; }
    }

    return FALSE;
   }

 $Dir         = "^/(WWW|MOBILE|PUBDATA)";
 $Web_Dir     = "^/WWW/(Web|SWeb|CGI|SCGI)";
 $Mobile_Dir1 = "^/WWW/MOBILE/(IMODE|PIMODE|SKY|PSKY|WAP|PWAP)/".
                "(Web|SWeb|CGI|SCGI)";
 $Mobile_Dir2 = "^/MOBILE/(IMODE|PIMODE|SKY|PSKY|WAP|PWAP)/".
                "(Web|SWeb|CGI|SCGI)";

    $Dir         .= "/"; $Web_Dir     .= "/";
    $Mobile_Dir1 .= "/"; $Mobile_Dir2 .= "/";

 if( mb_ereg( $Dir, $Target, $Result ) == FALSE ){ return FALSE; }

 if( mb_strtoupper( $Safe_Mode ) == "ON" ){ return TRUE; }

 if( mb_ereg( $Web_Dir,     $Target, $Result ) ||
     mb_ereg( $Mobile_Dir1, $Target, $Result ) ||
     mb_ereg( $Mobile_Dir2, $Target, $Result ) ){ return FALSE; }

 return TRUE;
}

@include_once( LIB_PATH . "WWW_Config/WWW_Config_MG_ENV_Function.inc" );
@include_once( LIB_PATH . "WWW_Config/WWW_Config_Web_Dir_Function.inc" );
@include_once( LIB_PATH . "WWW_Config/WWW_Config_SWeb_Dir_Function.inc" );
@include_once( LIB_PATH . "WWW_Config/WWW_Config_DATA_Dir_Fixed_Function.inc" );
@include_once( LIB_PATH . "WWW_Config/WWW_Config_PHP_Dir_Function.inc" );
?>
