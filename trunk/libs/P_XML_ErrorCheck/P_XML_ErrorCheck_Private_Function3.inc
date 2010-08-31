<?php
function P_XML_ErrorCheck_CheckValueEmail( $Array, $Email, $Type, $FLG = "" )
{
 if( mb_strlen( $FLG ) <= 0 ){ $FLG = "type"; }
    switch( $Type )
    {
     case "email_p2" :
     case "mobile_mail_p2" :
     case "mobile_mail_i_p2" :
     case "mobile_mail_e_p2" :
     case "mobile_mail_j_p2" : {
                                $Bool = P_Mail_Check_P2( $Email );
                                break;
                               }
     default                 : {
                                $Bool = P_Mail_Check_P( $Email );
                                break;
                               }
    }

 if( $Bool != TRUE )
   { return P_XML_ErrorCheck_Get_ErrorMessage( $Array, $FLG ); }

 if( $Type == "email" || $Type == "email_p2" ){ return ""; }

 $Carrier   = P_Mail_Carrier( $Email );
 $Error_Flg = "";

 switch( $Type )
 {
  case "web_mail" :
  case "web_mail_p2" :
  {
   if( $Carrier != "W" ){ $Error_Flg = "ON"; }
   break;
  }
  case "mobile_mail" :
  case "mobile_mail_p2" :
  {
   if( $Carrier != "I" && $Carrier != "E" && $Carrier != "J" )
     { $Error_Flg = "ON"; }

    break;
  }
  case "mobile_mail_i" :
  case "mobile_mail_i_p2" :
  {
   if( $Carrier != "I" ){ $Error_Flg = "ON"; }
   break;
  }
  case "mobile_mail_e" :
  case "mobile_mail_e_p2" :
  {
   if( $Carrier != "E" ){ $Error_Flg = "ON"; }
   break;
  }
  case "mobile_mail_j" :
  case "mobile_mail_j_p2" :
  {
   if( $Carrier != "J" ){ $Error_Flg = "ON"; }
   break;
  }
  default : { break; }
 }

 if( $Error_Flg != "" )
   { return P_XML_ErrorCheck_Get_ErrorMessage( $Array, $FLG ); }
 return "";
}

/*********************************************************************/
function P_XML_ErrorCheck_ConvertArray( $Array, $Key )
{
 $Loop_Array = array( "jp_name"   => "", "type"  => "",
                      "length"    => "", 
                      "null"      => "", "enum"  => "",
                      "extension" => "", "error" => "",
                      "mix"       => "" );

 $Check_Array = array( "jp_name" => "", "type"     => "",
                       "length" => "", "fixed"     => "",
                       "min"    => "", "null"      => "",
                       "enum"   => "", "extension" => "",
                       "age"    => "", "error"     => "",
                       "mix"    => "", "multibyte" => "",
                       "regex"  => "" );

 $Loop_Array["match"]  = "";
 $Loop_Array["gaiji"]  = ""; /* P005 : Add!! */
 $Loop_Array["date"]       = "";
 $Loop_Array["email"]      = "";
 $Loop_Array["tel"]        = "";
 $Loop_Array["zip"]        = "";
 $Loop_Array["error_init"] = "";
 $Loop_Array["reverse"]    = "";
 $Loop_Array["skip"]       = "";

 $Check_Array["match"] = "";
 $Check_Array["bool"]  = ""; /* P005 : Add!! */
 $Check_Array["gaiji"] = ""; /* P005 : Add!! */

 $Check_Array["date"]       = "";
 $Check_Array["email"]      = "";
 $Check_Array["tel"]        = "";
 $Check_Array["zip"]        = "";
 $Check_Array["error_init"] = "";
 $Check_Array["reverse"]    = "";
 $Check_Array["skip"]       = "";

 if( mb_strlen( $Key ) <= 0 )     { return FALSE; }
 if( is_array( $Array ) == FALSE ){ return FALSE; }

 $Value_Array = $Array[$Key];

 if( is_array( $Value_Array ) == FALSE ){ return FALSE; }

 foreach( $Loop_Array as $Key => $Value )
 {
  $WK_Array = $Value_Array[$Key];

  if( $Key == "type" )
    {
     $Check_Array["age"]   =
     P_XML_ErrorCheck_ConvertArray_GetValue( $WK_Array, "age", "1" );
/* P002 : Add Start!! ************************************************/

     $Check_Array["regex"] =
     P_XML_ErrorCheck_ConvertArray_GetValue( $WK_Array, "regex", "1" );

/************************************************** P002 : Add End!! */
    }
    else
  if( $Key == "length" )
    {
     $Check_Array["fixed"] =
     P_XML_ErrorCheck_ConvertArray_GetValue( $WK_Array, "fixed", "1" );

     $Check_Array["multibyte"] =
     P_XML_ErrorCheck_ConvertArray_GetValue( $WK_Array, "multibyte", "1" );

     $Check_Array["min"]   =
     P_XML_ErrorCheck_ConvertArray_GetValue( $WK_Array, "min", "1" );
    }
    else
  if( $Key == "mix" )
    {
     $Check_Array[$Key]["value"]     =
     P_XML_ErrorCheck_ConvertArray_GetValue( $WK_Array, "name", "2" );
/* P006 : Add Start!! ************************************************/

     $Check_Array[$Key]["attribute"] =
     P_XML_ErrorCheck_ConvertArray_GetAttributeList( $WK_Array, "name", "format" );

/************************************************** P006 : Add End!! */

     $Check_Array[$Key]["delimiter"] = $WK_Array["delimiter"];

     continue;
    }
    else
  if( $Key == "extension" )
    {
     $Check_Array[$Key] =
     P_XML_ErrorCheck_ConvertArray_GetValue( $WK_Array, "function", "2" );

     continue;
    }
/* P006 : Add Start!! ************************************************/
    else
  if( $Key == "date" )
    {
     $Check_Array[$Key] = "";
     $DATE1 = $DATE2 = $DATE3 = $DATE4 = $DATE5 = "";

     $Target_Array = $WK_Array["format"];

     if( is_array( $Target_Array ) == TRUE ){ $DATE1 = $Target_Array["value"]; }

     if( mb_strlen( $DATE1 ) <= 0 ){ continue; }

     $Target_Array = $WK_Array["compare"];

     if( is_array( $Target_Array ) == TRUE )
       {
        $DATE2           = $Target_Array["value"];
        $Attribute_Array = $Target_Array["attribute"];

        if( is_array( $Attribute_Array ) == TRUE )
          {
           $DATE3   = $Attribute_Array["operator"];
           $DATE3_1 = $Attribute_Array["skip"];
          }
       }

     $Target_Array = $WK_Array["now"];

     if( is_array( $Target_Array ) == TRUE )
       {
        $DATE4           = $Target_Array["value"];
        $Attribute_Array = $Target_Array["attribute"];

        if( is_array( $Attribute_Array ) == TRUE )
          { $DATE5 = $Attribute_Array["operator"]; }
       }

     $Date_Array = array( );
     $Date_Array["format"]       = $DATE1;
     $Date_Array["compare"]      = $DATE2;
     $Date_Array["operator"]     = $DATE3;
     $Date_Array["skip"]         = $DATE3_1;
     $Date_Array["now"]          = $DATE4;
     $Date_Array["now_operator"] = $DATE5;
     $Check_Array[$Key] = $Date_Array;

     continue;
    }
/************************************************** P006 : Add End!! */
    else
  if( $Key == "enum" )
    {
     $Check_Array[$Key] =
     P_XML_ErrorCheck_ConvertArray_GetValue( $WK_Array, "list", "2" );

     continue;
    }
/* P005 : Add Start!! ************************************************/

  if( $Key == "match" )
    {
/* P006 : Add Start!! ************************************************/

     $Check_Array["match_operator"] =
     P_XML_ErrorCheck_ConvertArray_GetValue( $WK_Array, "operator", "1" );

     $Check_Array["match_skip"] =
     P_XML_ErrorCheck_ConvertArray_GetValue( $WK_Array, "skip", "1" );

/************************************************** P006 : Add End!! */
     $Check_Array["bool"] =
     P_XML_ErrorCheck_ConvertArray_GetValue( $WK_Array, "bool", "1" );
    }

/************************************************** P005 : Add End!! */

  $Check_Array[$Key] = $WK_Array["value"];
 }

 $Check_Array["error"] = $Value_Array["error"];

 return $Check_Array;
}

?>
