<?php
function P_XML_ErrorCheck_ChangeArray( $Array, $Flg )
{
 $Result_Array = array( );

 if( is_array( $Array ) != TRUE ){ return FALSE; }

 foreach( $Array as $Value )
 {
  if( is_array( $Value["child"] ) != TRUE ){ continue; }

  foreach( $Value["child"] as $Value_Array )
  {
   $Attribute_Array = $Value_Array["attribute"];

   if( is_array( $Attribute_Array ) == FALSE ||
       mb_strlen( $Attribute_Array["name"] ) <= 0 ){ continue; }

   $Key = $Attribute_Array["name"];

   if( $Flg == "KEY" ){ $Result_Array[] = $Key; continue; }

   $Init_Array = P_XML_ErrorCheck_ChangeArray_Multiple( $Value_Array["child"] );

   $Work_Array = array( ); $Work_Array["value"] = $Attribute_Array["error_init"];
   $Init_Array["error_init"] = $Work_Array;

   $Work_Array = array( ); $Work_Array["value"] = $Attribute_Array["reverse"];
   $Init_Array["reverse"]    = $Work_Array;

   $Work_Array = array( ); $Work_Array["value"] = $Attribute_Array["skip"];
   $Init_Array["skip"]       = $Work_Array;

   $Result_Array[$Key]       = $Init_Array;
  }
 }

 if( count( $Result_Array ) == 0 ){  $Result_Array = FALSE; }

 return $Result_Array;
}

function P_XML_ErrorCheck_ChangeArray_Multiple( $Array )
{
 $Result_Array = array( );

 $Child_Array1 = array( "mix"    => "ON", "extension" => "ON",
                        "enum"   => "ON", "error"     => "ON",
                        "change" => "ON" );

 $Child_Array1["date"] = "ON"; /* P006 : Add!! */

 $Child_Array2 = array( "function" => "ON", "list"  => "ON",
                        "name"     => "ON", "value" => "ON" );

 if( is_array( $Array ) != TRUE ){ return FALSE; }

 foreach( $Array as $Value )
 {
  $Insert_Array = array( );
  $Key          = $Value["name"];

  if( $Child_Array1[$Key] == "ON" )
    {
     if( is_array( $Value["child"] ) == TRUE )
       {
        $Result_Array[$Key] =
        P_XML_ErrorCheck_ChangeArray_Multiple( $Value["child"] );

        if( $Key == "mix" )
          {
           $Result_Array[$Key]["delimiter"] =
           $Value["attribute"]["delimiter"];
          }
       }
       else
     if( $Key == "enum" )
       {
        $Insert_Array["value"]     = $Value["value"];
        $Insert_Array["attribute"] = $Value["attribute"];
        $Result_Array[$Key]        = $Insert_Array;
       }

     continue;
    }

  if( $Child_Array2[$Key] == "ON" )
    {
     $Insert_Array["value"]     = $Value["value"];
     $Insert_Array["attribute"] = $Value["attribute"];
     $Result_Array[$Key][]      = $Insert_Array;
    }
    else
    {
     $Insert_Array["value"]     = $Value["value"];
     $Insert_Array["attribute"] = $Value["attribute"];
     $Result_Array[$Key]        = $Insert_Array;
    }
 }

 if( count( $Result_Array ) == 0 ){ $Result_Array = FALSE; }

 return $Result_Array;
}

function P_XML_ErrorCheck_ChangeValue( $Array1, $Array2, $Array3 )
{
 if( is_array( $Array2 ) != TRUE ){ return $Array1; }

 foreach( $Array2 as $Name )
 {
  $Mix_Array = $Array3[$Name]["mix"];
  $Mix_Array = $Mix_Array["name"];

  if( is_array( $Mix_Array ) != TRUE )
    {
     $Value  = $Array1[$Name];
     $Change = $Array3[$Name]["change"]["value"];
     $Value  = P_XML_ErrorCheck_ChangeValueExchange( $Value, $Change );
     $Array1[$Name] = $Value;
     continue;
    }

  foreach( $Mix_Array as $Mix_Value )
  {
   $Mix_Att  = $Mix_Value["attribute"];

   if( is_array( $Mix_Att ) == TRUE )
     {
      if( mb_strtolower( $Mix_Att["format"] ) == "fixed" ){ continue; }
     }

   $Mix_Name = $Mix_Value["value"];
   $Value    = $Array1[$Mix_Name];
   $Change   = $Array3[$Name]["change"]["value"];
   $Value    = P_XML_ErrorCheck_ChangeValueExchange( $Value, $Change );
   $Array1[$Mix_Name] = $Value;
  }
 }

 return $Array1;
}

/*********************************************************************/
function P_XML_ErrorCheck_ChangeValueExchange( $Data, $Array )
{
 if( is_array( $Array ) != TRUE ){ return $Data; }

 foreach( $Array as $Change_Array )
 {
  $Flg = "";
  $Value = $Change_Array["value"];

  if( mb_strlen( $Value ) <= 0 ){ continue; }

  if( is_array( $Change_Array["attribute"] ) == TRUE )
    {
     $Attribute_Array = $Change_Array["attribute"];
     $Flg = $Attribute_Array["flg"];
    }

  switch( mb_strtolower( $Value ) )
  {
/* P004 : Add Start!! ************************************************/
   case "trim" :
   {
    $Data = trim( $Data );
    continue;
    break;
   }
   case "ltrim" :
   {
    $Data = ltrim( $Data );
    continue;
    break;
   }
   case "rtrim" :
   {
    $Data = rtrim( $Data );
    continue;
    break;
   }
/************************************************** P004 : Add End!! */
/* P005 : Add Start!! ************************************************/
   case "crlf" :
   {
    $Data = P_HTTP_VARS_DeleteCRLF( $Data );
    continue;
    break;
   }
/************************************************** P005 : Add End!! */
   case "upper" :
   {
    $Data = mb_strtoupper( $Data );
    continue;
    break;
   }
   case "lower" :
   {
    $Data = mb_strtolower( $Data );
    continue;
    break;
   }
   case "number" :
   case "alpha" :
   case "alpha_number" :
   case "hira_kata_onbiki" :
   case "kata_onbiki" :
   case "hira_onbiki" :
   case "hira_kata" :
   case "kata" :
   case "hira" :
   {
    break;
   }
   default :
   {
    if( mb_strtolower( $Flg ) == "function" )
      { $Data = $Value( $Data, $Value ); continue; }

/* P003 : Add Start!! ************************************************/

    if( mb_strtolower( $Flg ) == "replace" )
      { $Data = @mb_ereg_replace( $Value, "", $Data ); continue; }

    if( mb_strtolower( $Flg ) == "replace/i" )
      { $Data = @mb_eregi_replace( $Value, "", $Data ); continue; }

/************************************************** P003 : Add End!! */

    $Data = @mb_convert_kana( $Data, $Value );
    continue;
    break;
   }
  }

  switch( mb_strtolower( $Value ) )
  {
   case "number" :           { $Reg = "[^0-9]"; break; }
   case "alpha" :            { $Reg = "[^A-Z]"; break; }
   case "alpha_number" :     { $Reg = "[^0-9A-Z]"; break; }
   case "hira_kata_onbiki" :
   {
    $Reg = "[^".
           P_Word_Check_getString( "24" ).
           P_Word_Check_getString( "99" ).
           "]";
    break;
   }
   case "kata_onbiki" :
   {
    $Reg = "[^".
           P_Word_Check_getString( "23" ).
           P_Word_Check_getString( "99" ).
           "]";
    break;
   }
   case "hira_onbiki" :
   {
    $Reg = "[^".
           P_Word_Check_getString( "22" ).
           P_Word_Check_getString( "99" ).
           "]";
    break;
   }
   case "hira_kata" :
   {
    $Reg = "[^".
           P_Word_Check_getString( "24" ).
           "]";
    break;
   }
   case "kata" :
   {
    $Reg = "[^".
           P_Word_Check_getString( "23" ).
           "]";
    break;
   }
   case "hira" :
   {
    $Reg = "[^".
           P_Word_Check_getString( "22" ).
           "]";
    break;
   }
   default : { continue; break; }
  }

  if( mb_strtolower( $Flg ) == "delete" )
    { $Reg = "[".mb_substr( $Reg, 2 ); }

  $Data = @mb_eregi_replace( $Reg, "",  $Data );
 }

 return $Data;
}

/************************************************** P002 : Add End!! */

?>
