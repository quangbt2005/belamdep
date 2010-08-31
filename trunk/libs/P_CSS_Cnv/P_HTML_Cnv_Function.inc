<?php
function P_HTML_Cnv( $In, $Type )
{
 global $P_CSS_Cnv_Array;

 switch( $Type )
 {
  case  "1" : {
               $In = P_CSS_Cnv_stripslashes( $In );
               $Mode["0x22"] = "OFF";
               $Mode["0x26"] = "OFF";
               $Mode["0x27"] = "OFF";
               $Mode["0x3B"] = "OFF";
               $Mode["0x3C"] = "OFF";
               $Mode["0x3E"] = "OFF";
               $Mode["0x5C"] = "OFF";
               return P_CSS_Cnv( $In, $Mode );
               break;
              }
  case  "2" : {
               $In = P_CSS_Cnv_htmlspecialchars( $In );
               $Mode["0x22"] = "OFF";
               $Mode["0x26"] = "OFF";
               $Mode["0x27"] = "OFF";
               $Mode["0x3B"] = "OFF";
               $Mode["0x3C"] = "OFF";
               $Mode["0x3E"] = "OFF";
               $Mode["0x5C"] = "OFF";
               return P_CSS_Cnv( $In, $Mode );
               break;
              }
  case  "3" : {
               $In = P_CSS_Cnv_addslashes( $In );
               $Mode["0x22"] = "OFF";
               $Mode["0x26"] = "OFF";
               $Mode["0x27"] = "OFF";
               $Mode["0x3B"] = "OFF";
               $Mode["0x3C"] = "OFF";
               $Mode["0x3E"] = "OFF";
               $Mode["0x5C"] = "OFF";
               return P_CSS_Cnv( $In, $Mode );
               break;
              }
  case  "4" : {
               $In = P_CSS_Cnv_stripslashes( $In );
               $In = P_CSS_Cnv_htmlspecialchars( $In );
               $Mode["0x22"] = "OFF";
               $Mode["0x26"] = "OFF";
               $Mode["0x27"] = "OFF";
               $Mode["0x3B"] = "OFF";
               $Mode["0x3C"] = "OFF";
               $Mode["0x3E"] = "OFF";
               $Mode["0x5C"] = "OFF";
               return P_CSS_Cnv( $In, $Mode );
               break;
              }
  case  "5" : {
               $In = P_CSS_Cnv_strip_tags( $In );
               $Mode["0x22"] = "OFF";
               $Mode["0x26"] = "OFF";
               $Mode["0x27"] = "OFF";
               $Mode["0x3B"] = "OFF";
               $Mode["0x3C"] = "OFF";
               $Mode["0x3E"] = "OFF";
               $Mode["0x5C"] = "OFF";
               return P_CSS_Cnv( $In, $Mode );
               break;
              }
  case  "6" : {
               $In = P_CSS_Cnv_stripslashes( $In );
               $In = P_CSS_Cnv_strip_tags( $In );
               $Mode["0x22"] = "OFF";
               $Mode["0x26"] = "OFF";
               $Mode["0x27"] = "OFF";
               $Mode["0x3B"] = "OFF";
               $Mode["0x3C"] = "OFF";
               $Mode["0x3E"] = "OFF";
               $Mode["0x5C"] = "OFF";
               return P_CSS_Cnv( $In, $Mode );
               break;
              }
  case  "7" : {
               $In = htmlentities( $In );
               $Mode["0x22"] = "OFF";
               $Mode["0x26"] = "OFF";
               $Mode["0x27"] = "OFF";
               $Mode["0x3B"] = "OFF";
               $Mode["0x3C"] = "OFF";
               $Mode["0x3E"] = "OFF";
               $Mode["0x5C"] = "OFF";
               return P_CSS_Cnv( $In, $Mode );
               break;
              }
  case  "8" : {
               $In = P_CSS_Cnv_stripslashes( $In );
               $In = htmlentities( $In );
               $Mode["0x22"] = "OFF";
               $Mode["0x26"] = "OFF";
               $Mode["0x27"] = "OFF";
               $Mode["0x3B"] = "OFF";
               $Mode["0x3C"] = "OFF";
               $Mode["0x3E"] = "OFF";
               $Mode["0x5C"] = "OFF";
               return P_CSS_Cnv( $In, $Mode );
               break;
              }
  case  "9" : {
               $In = P_CSS_Cnv_stripslashes( $In );
               $In = P_CSS_Cnv_strip_tags( $In );
               $In = P_CSS_Cnv_htmlspecialchars( $In );
               $Mode["0x22"] = "OFF";
               $Mode["0x26"] = "OFF";
               $Mode["0x27"] = "OFF";
               $Mode["0x3B"] = "OFF";
               $Mode["0x3C"] = "OFF";
               $Mode["0x3E"] = "OFF";
               $Mode["0x5C"] = "OFF";
               return P_CSS_Cnv( $In, $Mode );
               break;
              }
  default   : {
               $Mode["0x22"] = "OFF";
               $Mode["0x26"] = "OFF";
               $Mode["0x27"] = "OFF";
               $Mode["0x3B"] = "OFF";
               $Mode["0x3C"] = "OFF";
               $Mode["0x3E"] = "OFF";
               $Mode["0x5C"] = "OFF";
               return P_CSS_Cnv( $In, $Mode );
               break;
              }
 }
}
@include_once( LIB_PATH . "P_CSS_Cnv/P_CSS_Cnv_Function.inc" );
@include_once( LIB_PATH . "P_CSS_Cnv/P_CSS_Cnv_Private_Function.inc" );

?>
