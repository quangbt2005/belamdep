<?php
function P_XML_ErrorCheck( $XML, &$Value_Array, $Name = "", $Change_Array = array( ) )

{
 $Error  = "XML Error Check Environmental Construction Error!!\n";
 $Array1 = P_DOMXML_SearchTree( $XML, "/check", $Change_Array );

 if( P_DOMXML_Error( ) != "" )
   { return array( "P_XML_ErrorCheck" => $Error ); }

 $Array2 = P_XML_ErrorCheck_ChangeArray( $Array1, "KEY" );
 $Array3 = P_XML_ErrorCheck_ChangeArray( $Array1, "" );

 if( is_array( $Array2 ) == FALSE || is_array( $Array3 ) == FALSE )
   { return array( "P_XML_ErrorCheck" => $Error ); }

 $Value_Array =
        P_XML_ErrorCheck_ChangeValue( $Value_Array, $Array2, $Array3 );

 $Array1      = array( );
 $Error_Array = array( );

 if( defined( "P_XML_ErrorCheck_Add_MixIn" )     == TRUE &&
     mb_strtoupper( P_XML_ErrorCheck_Add_MixIn ) == "ON" )
   {
    foreach( $Array2 as $Value )
    {
     $Check_Array = P_XML_ErrorCheck_ConvertArray( $Array3, $Value );

     $Check_Value = P_XML_ErrorCheck_MixIn( $Check_Array, $Value_Array, $Value );

     if( is_array( $Check_Value ) == TRUE ){ continue; }

     $Value_Array[$Value] = $Check_Value;
    }
   }

 foreach( $Array2 as $Value )
 {
  if( mb_strlen( $Name ) > 0 ){ if( $Name !== $Value ){ continue; } }

  $Check_Array = P_XML_ErrorCheck_ConvertArray( $Array3, $Value );

 if( mb_strlen( $Check_Array["skip"] ) > 0 )
   {
    $Skip_FLG = $Check_Array["skip"];
    if( mb_strlen( $Error_Array[$Skip_FLG] ) > 0 ){ continue; }
   }

 if( defined( "P_XML_ErrorCheck_Add_MixIn" )     == TRUE &&
     mb_strtoupper( P_XML_ErrorCheck_Add_MixIn ) == "ON" )
   {
    $Check_Value = $Value_Array[$Value];

    $Error = P_XML_ErrorCheck_CheckValue
                           ( $Check_Array, $Check_Value, $Value_Array );

    if( mb_strlen( $Error ) > 0 )
      {
       if( mb_strlen( $Check_Array["error_init"] ) > 0 )
         {
          $ERROR_INIT_FLG = $Check_Array["error_init"];
          $Error_Array[$ERROR_INIT_FLG] = $Error;
         }
         else
         {
          $Error_Array[$Value] = $Error;
         }
      }
    continue;
   }

  $Check_Value =
  P_XML_ErrorCheck_MixIn( $Check_Array, $Value_Array, $Value );

  if( is_array( $Check_Value ) == TRUE )
    {
     foreach( $Check_Value as $Check_Value )
     {
      $Error = P_XML_ErrorCheck_CheckValue
                           ( $Check_Array, $Check_Value, $Value_Array );

      if( mb_strlen( $Error ) > 0 )
        {
         if( mb_strlen( $Check_Array["error_init"] ) > 0 )
           {
            $ERROR_INIT_FLG = $Check_Array["error_init"];
            $Error_Array[$ERROR_INIT_FLG] = $Error;
           }
           else
           {
            $Error_Array[$Value] = $Error;
           }
        }
     }
     continue;
    }

  $Error = P_XML_ErrorCheck_CheckValue( $Check_Array, $Check_Value, $Value_Array );

  if( mb_strlen( $Error ) > 0 )
    {
     if( mb_strlen( $Check_Array["error_init"] ) > 0 )
       {
        $ERROR_INIT_FLG = $Check_Array["error_init"];
        $Error_Array[$ERROR_INIT_FLG] = $Error;
       }
       else
       {
        $Error_Array[$Value] = $Error;
       }
    }
 }

 if( count( $Error_Array ) == 0 ){ $Error_Array = FALSE; }

 return $Error_Array;
}

@include_once( LIB_PATH . "P_XML_ErrorCheck/P_XML_ErrorCheck_Private_Function1.inc" );
@include_once( LIB_PATH . "P_XML_ErrorCheck/P_XML_ErrorCheck_Private_Function2.inc" );
@include_once( LIB_PATH . "P_XML_ErrorCheck/P_XML_ErrorCheck_Private_Function3.inc" );
@include_once( LIB_PATH . "P_XML_ErrorCheck/P_XML_ErrorCheck_Private_Function4.inc" );
@include_once( LIB_PATH . "P_DOMXML/P_DOMXML_SearchTree_Function.inc" );
@include_once( LIB_PATH . "P_DOMXML/P_DOMXML_Error_Function.inc" );

if( mb_strtoupper( ErrorCheck ) == "ALL" )
  {
   @include_once( LIB_PATH . "P_Check/P_Check_Ascii_MultiByte_Function.inc" );
   @include_once( LIB_PATH . "P_Check/P_Check_DateTime_Function.inc" );
   @include_once( LIB_PATH . "P_Check/P_Check_Date_Function.inc" );
   @include_once( LIB_PATH . "P_Check/P_Check_Hira_Kata_Function.inc" );
   @include_once( LIB_PATH . "P_Check/P_Word_Check_getString_Function.inc" ); /*V002:Add!!*/
   @include_once( LIB_PATH . "P_Check/P_Check_PostalCode_Function.inc" );
   @include_once( LIB_PATH . "P_Check/P_Check_PostalCode7_Function.inc" );
   @include_once( LIB_PATH . "P_Check/P_Check_Telephone_Function.inc" );
   @include_once( LIB_PATH . "P_Check/P_Check_Time_Function.inc" );
   @include_once( LIB_PATH . "P_Check/P_Word_Check_Alpha_Function.inc" );
   @include_once( LIB_PATH . "P_Check/P_Word_Check_Beta_Function.inc" );
   @include_once( LIB_PATH . "P_Date/P_Date_MinorityCheck_Function.inc" );
   @include_once( LIB_PATH . "P_Mail/P_Mail_Check_P_Function.inc" );
   @include_once( LIB_PATH . "P_Mail/P_Mail_Carrier_Function.inc" );
/*V003:AddStart!!*****************************************************/

   @include_once( LIB_PATH . "P_HTTP_VARS/P_HTTP_VARS_DeleteCRLF_Function.inc" );
   @include_once( LIB_PATH . "P_Mail/P_Mail_Check_P2_Function.inc" );
   @include_once( LIB_PATH . "P_Check/P_Check_PostalCode_P2_Function.inc" );
   @include_once( LIB_PATH . "P_Check/P_Check_PostalCode7_P2_Function.inc" );
   @include_once( LIB_PATH . "P_Check/P_Check_Telephone_P2_Function.inc" );
   @include_once( LIB_PATH . "P_Check/P_Check_Telephone_P2M_Function.inc" );
   @include_once( LIB_PATH . "P_Check/P_Check_Telephone_P2O_Function.inc" );

/*******************************************************V003:AadEnd!!*/
  }

?>