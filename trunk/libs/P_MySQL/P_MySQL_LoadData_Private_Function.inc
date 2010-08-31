<?php
function P_MySQL_LoadData_Exec( $Array, &$Result_Array )
{
 $Load_Data = "#!/bin/sh\n".
              "exec 2>&1\n".
              $Array["Path"]."mysql -v -v -v ".
              "-h".$Array["DB_Host"]." ".
              "-u".$Array["DB_User"]." ".
              "-p".$Array["DB_Pass"]." ".
              "-D".$Array["DB_Name"]." ".
              "--local-infile ".
              "-e\"LOAD DATA LOCAL INFILE '".$Array["File"]."' ".
              $Array["Type"]." INTO TABLE ".$Array["Table"]." ".
              "FIELDS TERMINATED BY '".$Array["Field"]."' ".
              "LINES TERMINATED BY '".$Array["Line"]."'\"\n".
              "exit\n";

 $P_PTR = @popen( $Load_Data, "r" );

 if( $P_PTR == FALSE )
   {
    $Load_Data = "#!/bin/sh\n".
                 "exec 2>&1\n".
                 $Array["Path"]."mysql -v -v -v ".
                 "-h".$Array["DB_Host"]." ".
                 "-u".$Array["DB_User"]." ".
                 "-D".$Array["DB_Name"]." ".
                 "--local-infile ".
                 "-e\"LOAD DATA LOCAL INFILE '".$Array["File"]."' ".
                 $Array["Type"]." INTO TABLE ".$Array["Table"]." ".
                 "FIELDS TERMINATED BY '".$Array["Field"]."' ".
                 "LINES TERMINATED BY '".$Array["Line"]."'\"\n".
                 "exit\n";

    return  "P_MySQL\P_MySQL_LoadData_Private_Function.inc\nLine 35\n";
   }

 $Result = "";

 while( !@feof( $P_PTR ) )
 { $Result .= @fgets( $P_PTR, 100000 ); }

  @pclose( $P_PTR );

 if( strstr( $Result, "ERROR " ) != FALSE )
   {
    $Err_Msg = strstr( $Result, "ERROR " );
    $Err_Msg = strstr( $Result, ": " );
    $Err_Msg = substr( $Err_Msg, 2, ( strlen( $Err_Msg ) - 7 ) );

    return  "P_MySQL\P_MySQL_LoadData_Private_Function.inc\nLine 51\n";
   }

 $XX = strpos( $Result, "Records" );
 $YY = strpos( $Result, "Deleted" );
 $YY = $YY - $XX;
 $Work  = substr( $Result, $XX, $YY );
 $Array = explode( ":", $Work );
 $Result_Array["Records"] = (int)sprintf( "%d", $Array[1] );

 $XX = strpos( $Result, "Deleted" );
 $YY = strpos( $Result, "Skipped" );
 $YY = $YY - $XX;
 $Work  = substr( $Result, $XX, $YY );
 $Array = explode( ":", $Work );
 $Result_Array["Changed"] = (int)sprintf( "%d", $Array[1] );

 $XX = strpos( $Result, "Skipped" );
 $YY = strpos( $Result, "Warnings" );
 $YY = $YY - $XX;
 $Work  = substr( $Result, $XX, $YY );
 $Array = explode( ":", $Work );
 $Result_Array["Skipped"] = (int)sprintf( "%d", $Array[1] );

 $Work  = substr( $Result, strpos( $Result, "Warnings" ) );
 $Array = explode( ":", $Work );
 $Result_Array["Warnings"] = (int)sprintf( "%d", $Array[1] );

 $Result_Array["Added"] = $Result_Array["Records"] -
                          $Result_Array["Skipped"] -
                          $Result_Array["Changed"];

 return "";
}

/*********************************************************************/
function P_MySQL_LoadData_Init_Check( &$Array )
{
 if( strlen( $Array["Path"] )    <= 0 ||
     strlen( $Array["DB_Host"] ) <= 0 ||
     strlen( $Array["DB_User"] ) <= 0 ||
     strlen( $Array["DB_Pass"] ) <= 0 ||
     strlen( $Array["DB_Name"] ) <= 0 ||
     strlen( $Array["Table"] )   <= 0 ||
     strlen( $Array["File"] )    <= 0 )
   {
    return "P_MySQL\P_MySQL_LoadData_Private_Function.inc\nLine 97\n";
   }

 if( substr( $Array["Path"], -1 ) != "/" ){ $Array["Path"] .= "/"; }

 if( is_file( $Array["Path"]."mysql" ) != TRUE )
   {
    return "P_MySQL\P_MySQL_LoadData_Private_Function.inc\nLine 104\n";
   }

 if( is_file( $Array["File"] ) != TRUE )
   {
    return "P_MySQL\P_MySQL_LoadData_Private_Function.inc\nLine 109\n";
   }

 if( strtoupper( $Array["Type"] ) != "REPLACE" )
   { $Array["Type"] = "IGNORE"; }

 $Array["Type"] = strtoupper( $Array["Type"] );

 if( strlen( $Array["Field"] ) <= 0 ){ $Array["Field"] = "\\\\t"; }

 if( strlen( $Array["Line"] ) <= 0 ){ $Array["Line"] = "\\\\n"; }

 return "";
}

@include_once( LIB_PATH . "P_MySQL/P_MySQL_Error_SetErrorHandler_Private_Function.inc" );

?>
