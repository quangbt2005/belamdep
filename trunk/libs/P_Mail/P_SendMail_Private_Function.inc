<?php
function P_SendMail_Change_Attached( &$In_Array, $MAC9, $RFC2231 )
{
 $MULTI = "----_".
          mb_strtoupper( P_Hex_IPtoHEX( getenv( "SERVER_ADDR" ) ) ).
          time( ).
          posix_getpid( ).
          "_MULTIPART_MIXED_";

 $OLD_Content_Type         = $In_Array["Content-Type"];
 $In_Array["Content-Type"] = "multipart/mixed; boundary=\"".$MULTI."\"";

 $File_Array = $In_Array["Attached"];
 $Body       = $Out_Body = "";
 $Body       = $In_Array["Body"];
 if( mb_substr( $Body, -1 ) != "\n" ){ $Body .= "\n"; }

 $Out_Body   = "This is a multi-part message in MIME format.\n\n".
               "--".$MULTI."\n".
               "Content-Type: ".$OLD_Content_Type."\n".
               "Content-Transfer-Encoding: ".$In_Array["Content-Transfer-Encoding"]."\n\n".
               $Body;

 foreach( $File_Array as $Value )
 {
  $NAME = $Value["NAME"];
  $FILE = $Value["FILE"];

  $Buffer = @chunk_split( @base64_encode( @file_get_contents( $FILE ) ) );
  if( mb_substr( $Buffer, -1 ) != "\n" ){ $Buffer .= "\n"; }

 if( mb_strtoupper( $RFC2231 ) == "ON" )
   {
    P_SendMail_Change_Attached_Get_RFC2231( $NAME, $NAME1, $NAME2 );

    $Out_Body .= "--".$MULTI."\n".
                 "Content-Type: application/octet-stream;\n".
                 $NAME1.
                 "Content-Transfer-Encoding: base64\n".
                 "Content-Disposition: attachment;\n".
                 $NAME2."\n".
                 $Buffer;
   }
   else
   {
    if( mb_strlen( mb_ereg_replace( "[a-zA-Z0-9\\._-]", "", $NAME ) ) > 0 )
      { $NAME =  mb_encode_mimeheader( $NAME ); }

    $Out_Body .= "--".$MULTI."\n".
                 "Content-Type: application/octet-stream;\n".
                 " name=\"".$NAME."\"\n".
                 "Content-Transfer-Encoding: base64\n".
                 "Content-Disposition: attachment;\n".
                 " filename=\"".$NAME."\"\n\n".
                 $Buffer;
   }
 }

 $Out_Body        .= "--".$MULTI."--\n";
 $In_Array["Body"] = $Out_Body;
}
/*********************************************************************/
function P_SendMail_Change_Attached_Get_RFC2231( $NAME, &$NAME1, &$NAME2 )
{
 $NAME1 = "";
 $NAME2 = "";

 if( mb_strlen( mb_ereg_replace( "[a-zA-Z0-9\\._-]", "", $NAME ) ) > 0 )
   {
    $NAME       = mb_convert_encoding( $NAME, "JIS", mb_internal_encoding( ) );
    $XX         = 0;
    $YY         = 5;
    $SIZE       = mb_strlen( $NAME, "JIS" );
    $Name_Array = array( );

    while( true )
    {
     if( $XX >= $SIZE ){ break; }
     $Name_Array[] = mb_substr( $NAME, $XX, $YY, "JIS" );
     $XX += $YY;
    }

    $SET = "ISO-2022-JP'ja'";

    if( count( $Name_Array ) <= 1 )
      {
       $NAME1 = " name*=".$SET.rawurlencode( $Name_Array[0] )."\n";
       $NAME2 = " filename*=".$SET.rawurlencode( $Name_Array[0] )."\n";
      }
      else
      {
       foreach( $Name_Array as $Key => $Value )
       {
        $NAME1 .= " name*".$Key."*=".$SET.rawurlencode( $Value ).";\n";
        $NAME2 .= " filename*".$Key."*=".$SET.rawurlencode( $Value ).";\n";
        $SET    = "";
       }

       $NAME1 = mb_substr( $NAME1, 0, (  mb_strlen( $NAME1, "JIS" ) - 2 ), "JIS" )."\n";
       $NAME2 = mb_substr( $NAME2, 0, (  mb_strlen( $NAME2, "JIS" ) - 2 ), "JIS" )."\n";
      }
   }
   else
   {
    $NAME       = mb_convert_encoding( $NAME, "JIS", mb_internal_encoding( ) );
    $XX         = 0;
    $YY         = 40;
    $SIZE       = mb_strlen( $NAME, "JIS" );
    $Name_Array = array( );

    while( true )
    {
     if( $XX >= $SIZE ){ break; }
     $Name_Array[] = mb_substr( $NAME, $XX, $YY, "JIS" );
     $XX += $YY;
    }

    if( count( $Name_Array ) <= 1 )
      {
       $NAME1 = " name=\"".$Name_Array[0]."\"\n";
       $NAME2 = " filename=\"".$Name_Array[0]."\"\n";
      }
      else
      {
       foreach( $Name_Array as $Key => $Value )
       {
        $NAME1 .= " name*".$Key."=\"".$Value."\";\n";
        $NAME2 .= " filename*".$Key."=\"".$Value."\";\n";
       }

       $NAME1 = mb_substr( $NAME1, 0, (  mb_strlen( $NAME1, "JIS" ) - 2 ), "JIS" )."\n";
       $NAME2 = mb_substr( $NAME2, 0, (  mb_strlen( $NAME2, "JIS" ) - 2 ), "JIS" )."\n";
      }
   }
}

/*********************************************************************/
function P_SendMail_Init_Check_Attached( &$In_Array, $MAC9, $RFC2231 )
{
 if( mb_strlen( $In_Array["Mime-Version"] ) <= 0 )
   { $In_Array["Mime-Version"] = "1.0"; }

 if( mb_strlen( $In_Array["Content-Type"] ) <= 0 )
   { $In_Array["Content-Type"] = "text/plain; charset=\"ISO-2022-JP\""; }

 if( mb_strlen( $In_Array["Content-Transfer-Encoding"] ) <= 0 )
   { $In_Array["Content-Transfer-Encoding"] = "7bit"; }

 $File_Array = $In_Array["Attached"];

 if( is_array( $File_Array ) != TRUE )
   {
    if( mb_strlen( $File_Array ) <= 0 )
      { return "添付ファイルの指定がありません！\n"; }

    $WK_STR           = $File_Array;
    $File_Array       = array( );
    $WK_Array         = array( );
    $WK_Array["FILE"] = $WK_STR;
    $File_Array[]     = $WK_Array;
   }
   else
 if( mb_strlen( $File_Array["FILE"] ) > 0 ||
     is_array(  $File_Array["FILE"] ) == TRUE )
   {
    $WK_Array         = $File_Array;
    $File_Array       = array( );
    $File_Array[]     = $WK_Array;
   }

 if( count( $File_Array ) <= 0 )
   { return "添付ファイルの指定がありません！\n"; }

 $Out_Array = array( );

 foreach( $File_Array as $Value )
 {
  $FILE = $Value;
  $MODE = "Secure";

  if( is_array( $Value ) == TRUE )
    {
     $FILE = $Value["FILE"];
     $NAME = $Value["NAME"];
    }

  if( is_array( $FILE ) == TRUE )
    {
     $TARGET_FILE = $FILE;
     $FILE        = $TARGET_FILE["File"];
     $MODE        = $TARGET_FILE["Safe_Mode"];
     if( mb_strlen( $MODE ) <= 0 ){ $MODE = "Secure"; }
    }

  if( P_FileIO_isFile( $FILE, $MODE ) != TRUE )
    {
     return "P_Mail\P_SendMail_Private_Function.inc\nLine 197\n";
    }

  if( mb_strlen( $NAME ) <= 0 ){ $NAME = @basename( $FILE ); }

  if( mb_strtoupper( $MAC9 ) != "OFF" )
    {
     if( strlen( $NAME ) > 30 )
       {
        return "P_Mail\P_SendMail_Private_Function.inc\nLine 206\n";
       }
    }

  $WK_Array = array( );
  $WK_Array["FILE"] = $FILE;
  $WK_Array["NAME"] = $NAME;

  $Out_Array[] = $WK_Array;
 }

 $In_Array["Attached"] = $Out_Array;

 return "";
}

?>
