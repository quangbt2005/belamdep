<?php
function P_CSS_Cnv( $In, $Mode, $FLG = "" )
/*********************************************** P004 : Change End!! */
{
 global $P_CSS_Cnv_Array;

 if( is_array( $P_CSS_Cnv_Array ) == TRUE &&
     isset( $P_CSS_Cnv_Array )    == TRUE )
   { $Mode = $P_CSS_Cnv_Array; }

 switch( strtoupper( mb_internal_encoding( ) ) )
 {
  case "SJIS"     :
  case "SJIS-WIN" : {
                     $Cnv_Array = array( 
                     "0x09" => "20",   "0x21" => "8149",
                     "0x25" => "8193", "0x26" => "8195",
                     "0x22" => "8168", "0x27" => "8166",
                     "0x28" => "8169", "0x29" => "816A",
                     "0x2A" => "8196", "0x2C" => "8143",
                     "0x3B" => "8147", "0x3C" => "8183",
                     "0x3E" => "8184", "0x5C" => "818F",
                     "0x5F" => "8151", "0x60" => "815F",
                     "0x7C" => "8162", "0x7E" => "8160"
                     );
                     if( strtoupper( CSS_Cnv_Synchronization ) == "ON" )
                       {
                        $Cnv_Array = array( 
                        "0x26" => "8195", "0x3C" => "8183",
                        "0x3E" => "8184", "0x09" => "20",
                        "0x22" => "8168", "0x27" => "8166",
                        "0x2A" => "8196", "0x2C" => "8143",
                        "0x3F" => "8148", "0x5C" => "818F",
                        "0x60" => "815F", "0x7C" => "8162",
                        "0x7E" => "8160"
                        );
                       }
                     break;
                    }
  case "UTF8"     :
  case "UTF-8"    : {
                     $Cnv_Array = array( 
                     "0x09" => "20",     "0x21" => "EFBC81",
                     "0x25" => "EFBC85", "0x26" => "EFBC86",
                     "0x22" => "E2809D", "0x27" => "E28099",
                     "0x28" => "EFBC88", "0x29" => "EFBC89",
                     "0x2A" => "EFBC8A", "0x2C" => "EFBC8C",
                     "0x3B" => "EFBC9B", "0x3C" => "EFBC9C",
                     "0x3E" => "EFBC9E", "0x5C" => "EFBFA5",
                     "0x5F" => "EFBCBF", "0x60" => "EFBCBC",
                     "0x7C" => "EFBD9C", "0x7E" => "E3809C"
                     );
                     if( strtoupper( CSS_Cnv_Synchronization ) == "ON" )
                       {
                        $Cnv_Array = array( 
                        "0x26" => "EFBC86", "0x3C" => "EFBC9C",
                        "0x3E" => "EFBC9E", "0x09" => "20",
                        "0x22" => "E2809D", "0x27" => "E28099",
                        "0x2A" => "EFBC8A", "0x2C" => "EFBC8C",
                        "0x3F" => "EFBC9F", "0x5C" => "EFBFA5",
                        "0x60" => "EFBCBC", "0x7C" => "EFBD9C",
                        "0x7E" => "E3809C"
                        );
                       }
                     break;
                    }
  default         : {
                     $Cnv_Array = array( 
                     "0x09" => "20",   "0x21" => "A1AA",
                     "0x25" => "A1F3", "0x26" => "A1F5",
                     "0x22" => "A1C9", "0x27" => "A1C7",
                     "0x28" => "A1CA", "0x29" => "A1CB",
                     "0x2A" => "A1F6", "0x2C" => "A1A4",
                     "0x3B" => "A1A8", "0x3C" => "A1E3",
                     "0x3E" => "A1E4", "0x5C" => "A1EF",
                     "0x5F" => "A1B2", "0x60" => "A1C0",
                     "0x7C" => "A1C3", "0x7E" => "A1C1"
                     );
                     if( strtoupper( CSS_Cnv_Synchronization ) == "ON" )
                       {
                        $Cnv_Array = array( 
                        "0x26" => "A1F5", "0x3C" => "A1E3",
                        "0x3E" => "A1E4", "0x09" => "20",
                        "0x22" => "A1C9", "0x27" => "A1C7",
                        "0x2A" => "A1F6", "0x2C" => "A1A4",
                        "0x3F" => "A1A9", "0x5C" => "A1EF",
                        "0x60" => "A1C0", "0x7C" => "A1C3",
                        "0x7E" => "A1C1"
                        );
                       }
                     break;
                    }
 }
 $Reg_Array = array(
                     "0x09" => "\\\t", "0x21" => "!",    "0x25" => "%",
                     "0x26" => "&",    "0x22" => "\"",   "0x27" => "'",
                     "0x28" => "\(",   "0x29" => "\)",   "0x2A" => "\*",
                     "0x2C" => ",",    "0x3B" => ";",    "0x3C" => "<",
                     "0x3E" => ">",    "0x5C" => "\\\\", "0x5F" => "_",
                     "0x60" => "`",    "0x7C" => "\|",   "0x7E" => "~"
                   );
 if( strtoupper( CSS_Cnv_Synchronization ) == "ON" )
   {
    $Reg_Array = array(
                     "0x26" => "&",    "0x3C" => "<",  "0x3E" => ">",
                     "0x09" => "\\\t", "0x22" => "\"", "0x27" => "'",
                     "0x2A" => "\*",   "0x2C" => ",",  "0x3F" => "\\?",
                     "0x5C" => "\\\\", "0x60" => "`",  "0x7C" => "\|",
                     "0x7E" => "~"
                      );
  }

 reset( $Cnv_Array );

 $In = preg_replace( "/[\x01-\x08]|[\x0B-\x0C]|[\x0E-\x1F]/", "", $In );

 if( defined( "CSS_Cnv_DeleteNullAtack" )  == TRUE &&
     strtoupper( CSS_Cnv_DeleteNullAtack ) == "ON" )
   {
    $In = preg_replace( "/[\\x00-\\x08]|[\\x0B-\\x0C]|[\\x0E-\\x1F]/", "", $In );
    $WK = preg_replace( "/[\\x00]|[\\x09]|[\\x0D]|[\\x0A]|[\\x20]/", "", $In );

    if( strlen( $WK ) <= 0 ){ return $WK; }

    $In = preg_replace( "/[\\x09]/", " ", $In );
   }

 if( strtoupper( $FLG ) == "OFF" ){ return $In; }

 $Count = count( $Cnv_Array );

 for( $XX = 0; $XX < $Count; ++$XX )
 {
  $Key = key( $Cnv_Array );

  if( $Mode[$Key] == "OFF" ){ next( $Cnv_Array ); continue; }

  if( $Mode[$Key] == "DELETE" )
    {
     $In =
     mbereg_replace( $Reg_Array[$Key], "", $In );
     next( $Cnv_Array ); continue;
    }

  if( $Mode[$Key] != "" && gettype( $Mode ) == "array" )
    {
     $In =
     mbereg_replace( $Reg_Array[$Key], $Mode[$Key], $In );
    }
    else
    {
     $Reg = pack( "H*", $Cnv_Array[$Key] );
     $In  = mbereg_replace( $Reg_Array[$Key], $Reg, $In );
    }

  next( $Cnv_Array );
 }

 return $In;
}

?>
