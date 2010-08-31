<?php
function P_XML_ErrorCheck_ConvertArray_GetAttributeList( $Array, $Key, $Child )
{
 $Ot_Array = array( );
 if( is_array( $Array[$Key] ) != TRUE ){ return $Ot_Array; }

 if( mb_strlen( $Child ) <= 0 ){ return $Ot_Array; }

 $In_Array = $Array[$Key];

 foreach( $In_Array as $Get_Value )
 {
  $Out_Value = "";

  if( is_array( $Get_Value["attribute"] ) == TRUE )
    { $Out_Value = $Get_Value["attribute"][$Child]; }

  $Ot_Array[] = $Out_Value;
 }

 return $Ot_Array;
}

/************************************************** P002 : Add End!! */
/*********************************************************************/
function P_XML_ErrorCheck_ConvertArray_GetValue( $Array, $Key, $Flg )
{
 if( $Flg != "2" )
   {
    if( is_array( $Array["attribute"] ) == TRUE )
      { $String = $Array["attribute"][$Key]; }

    if( mb_strlen( $String ) <= 0 ){ $String = ""; }

    return $String;
   }

 $Get_Array = array( );

 if( is_array( $Array[$Key] ) == TRUE )
    {
     foreach( $Array[$Key] as $Get_Value )
     {
      if( mb_strlen( $Get_Value["value"] ) <= 0 ){ continue; }

      if( $Key == "list" )
        {
         $Get_Key             = $Get_Value["value"];
         $Get_Array[$Get_Key] = "ON";
        }
        else
        { $Get_Array[] = $Get_Value["value"]; }
     }
    }

 if( count( $Get_Array ) == 0 ){ $Get_Array = ""; }

 return $Get_Array;
}

/*********************************************************************/
function P_XML_ErrorCheck_Get_ErrorMessage( $Array, $Flg, $Code = "" )
{
 $String = "Error !!\nType  => : ".$Flg."\n";

 if( is_array( $Array ) != TRUE || mb_strlen( $Flg ) <= 0 )
   { return "Error!!\n"; }

 $Error_Array = $Array["error"];

 $EX_Array              = array( );
 $EX_Array["extension"] = "ON";
 $EX_Array["date"]      = "ON";

 if( mb_strlen( $EX_Array[$Flg] ) <= 0 )
   {
    if( mb_strlen( $Error_Array[$Flg]["value"] ) <= 0 ){ return $String; }

    return $Error_Array[$Flg]["value"];
   }

/*********************************************** P002 : Change End!! */

 $String = "Error !!\nType  => : ".$Flg."\nCode =>  : ".$Code."\n";

/* P002 : Add Start!! ************************************************/

 if( $Flg == "date" )
   {
    if( is_array( $Error_Array["date"] ) != TRUE ){ return $String; }

    $Date_Array = $Error_Array["date"];

    if( mb_strlen( $Date_Array[$Code]["value"] ) <= 0 ){ return $String; }

    return $Date_Array[$Code]["value"];
   }

/************************************************** P002 : Add End!! */

 if( is_array( $Error_Array["extension"] ) != TRUE ){ return $String; }

 $Extension_Array = $Error_Array["extension"];

 if( is_array( $Extension_Array["function"] ) != TRUE ){ return $String; }

 $Function_Array  = $Extension_Array["function"];

 foreach( $Function_Array as $Value )
 {
  $Attribute_Array = $Value["attribute"];

  if( $Attribute_Array["no"] === $Code ){ return $Value["value"]; }
 }

 return $String;
}

/*********************************************************************/
function P_XML_ErrorCheck_MixIn( $Array, $Value_Array, $Key )
{
 $Mix_Array = $Array["mix"]["value"];
 $Att_Array = $Array["mix"]["attribute"]; /* P002 : Add!! */
 $Delimiter = $Array["mix"]["delimiter"];

 if( is_array( $Mix_Array ) == FALSE ){ return $Value_Array[$Key]; }

 $Get_Value = "";
 $FIXED_VALUE = ""; /* P002 : Add!! */

 foreach( $Mix_Array as $XX => $Value )
 {
  $FORMAT = "";

  if( mb_strtolower( $Att_Array[$XX] ) == "fixed" )
    {
     $Get_Value .= $Value.$Delimiter;
     continue;
    }

  if( is_array( $Value_Array[$Value] ) == TRUE )
    {
     $WK_Array = $Value_Array[$Value];

     foreach( $WK_Array as $Check_Value )
     {
      if( mb_strlen( $Att_Array[$XX] ) > 0 && mb_strlen( $Check_Value ) > 0 )
        {
         if( mb_ereg( "[0-9]", $Check_Value ) == TRUE )
           {
            $FORMAT = $Att_Array[$XX];
           }
        }

      if( mb_strlen( $FORMAT ) > 0 )
        {
         $Get_Value .= @sprintf( $FORMAT, $Check_Value ).$Delimiter;
         $FIXED_VALUE = "ON";
        }
        else
        {
         if( mb_strlen( $Check_Value ) > 0 )
           {
            $Get_Value .= $Check_Value.$Delimiter;
            $FIXED_VALUE = "ON";
           }
        }
     }
     continue;
    }

   if( mb_strlen( $Att_Array[$XX] ) > 0 && mb_strlen( $Value_Array[$Value] ) > 0 )
     {
      if( mb_ereg( "[0-9]", $Value_Array[$Value] ) == TRUE )
        {
         $FORMAT = $Att_Array[$XX];
        }
     }

  if( mb_strlen( $FORMAT ) > 0 )
    {
     $Get_Value .= @sprintf( $FORMAT, $Value_Array[$Value] ).$Delimiter;
     $FIXED_VALUE = "ON";
    }
    else
    {
     if( mb_strlen( $Value_Array[$Value] ) > 0 )
       {
        $Get_Value .= $Value_Array[$Value].$Delimiter;
        $FIXED_VALUE = "ON";
       }
    }

 }

  if( mb_strlen( $Get_Value ) > 0 )
    {
     $Get_Value = mb_substr( $Get_Value, 0,
               ( mb_strlen( $Get_Value ) - mb_strlen( $Delimiter ) ) );
    }

 if( mb_strlen( $FIXED_VALUE ) <= 0 ){ return $FIXED_VALUE; }

 return $Get_Value;
}

?>
