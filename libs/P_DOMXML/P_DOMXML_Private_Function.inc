<?
/*********************************************************************/
/*      V001 ： 新規  2004.05.01  桝形                               */
/*      V002 ： 修正  2004.07.01  桝形                               */
/*********************************************************************/

/*********************************************************************/
/*    関数名 ： P_DOMXML_Private_Function                            */
/*-------------------------------------------------------------------*/
/*      機能 ： P_DOMXMLライブラリに登録されている関数群からのみ     */
/*           ： 呼び出されるプライベート関数群                       */
/*-------------------------------------------------------------------*/
/*      引数 ： 説明は割愛                                           */
/*-------------------------------------------------------------------*/
/*    戻り値 ： 説明は割愛                                           */
/*-------------------------------------------------------------------*/
/*      警告 ： 機能に書いてある通り、通常利用は避けて下さい。       */
/*-------------------------------------------------------------------*/
/* Copyright ： DNP DigitalCom CO.,LTD.                              */
/*      P001 ： 新規  2004.05.01  桝形                               */
/*      P002 ： 修正  2004.07.01  桝形                                 */
/*      P003 QuangTran  2008.09.18 Skip lib construction check       */
/*********************************************************************/
/*********************************************************************/
function P_DOMXML_ChangeText( $String )
{
 global $P_DOMXML_Change_Array;

 if( mb_strlen( $String ) <= 0 ){ return $String; }

 if( is_array( $P_DOMXML_Change_Array ) != TRUE ){ return $String; }

 foreach( $P_DOMXML_Change_Array as $Key => $Value )
 {
  $String = mb_str_replace( $Key, $Value, $String );
 }

 return $String;
}

/*********************************************************************/
function P_DOMXML_Convert_Encoding( $Value, $Flg )
{
 $Encoding = mb_strtoupper( mb_internal_encoding( ) );

 if( $Encoding == "UTF-8" || $Encoding == "UTF8" ){ return $Value; }

 if( $Flg != "2" )
   {
    $Value =
    mb_convert_encoding( $Value, mb_internal_encoding( ), "UTF-8" );
   }
   else
   {
    $Value =
    mb_convert_encoding( $Value, "UTF-8", mb_internal_encoding( ) );
   }

 return $Value;
}

/*********************************************************************/
function P_DOMXML_Create_Object( $XML )
{
 global $P_DOMXML_Management_Array;
 global $P_DOMXML_Management_XPath_Array; /* P002 : Add!! */

 $Object = @domxml_open_file( $XML );

 if( @is_object( $Object ) != TRUE )
   {
    return "XMLファイルのパースに失敗しました！\n".
           "XMLファイル[".$XML."]\n";
   }

 $P_DOMXML_Management_Array[$XML] = $Object;

/* P002 : Add Start!! ************************************************/

 $XPath = @xpath_new_context( $Object );
 $P_DOMXML_Management_XPath_Array[$XML] = $XPath;

/************************************************** P002 : Add End!! */

 return "";
}

/*********************************************************************/
function P_DOMXML_Get_Node( $XML, $Name, &$Result_Array )
{
 $Result_Array = FALSE;

 if( mb_substr( $Name, -1 ) == "/" )
   { $Name = mb_substr( $Name, 0,( mb_strlen( $Name ) - 1 ) ); }

 if( @is_file( $XML["XML"] ) == FALSE )
   {
    return "XMLファイルが存在しません！\n".
           "XMLファイル名[".$XML["XML"]."]\n";
   }
   else
   { $XML["XML"] = realpath( $XML["XML"] ); }
 /* P003 : Change Start!! ************************************************/
 // if( P_FileIO_isFile( $XML["XML"], $XML["Safe_Mode"] ) == FALSE )
 if( P_FileIO_isFile( $XML["XML"], "OFF" ) == FALSE )
 /************************************************** P003 : Change End!! */
   {
    return "XMLファイルの指定が不正です！\n".
           "XMLファイル名[".$XML["XML"]."]\n";
   }

 $Result_Array = array( );
 $Object       = P_DOMXML_Get_OepnObject( $XML["XML"] );

 if( @is_object( $Object ) != TRUE )
   {
    $Error = P_DOMXML_Create_Object( $XML["XML"] );

    if( $Error != "" ){ return $Error; }

    $Object = P_DOMXML_Get_OepnObject( $XML["XML"] );
   }

/* P002 : Change Start!! *********************************************/

// $Result_Array = P_DOMXML_Search_Node( $Object, $Name );

 $Result_Array = P_DOMXML_Search_Node( $Object, $Name, $XML["XML"] );

/*********************************************** P002 : Change End!! */

 if( count( $Result_Array ) == 0 ){ $Result_Array = FALSE; }

 return "";
}

/*********************************************************************/
function P_DOMXML_Get_OepnObject( $XML )
{
 global $P_DOMXML_Management_Array;

 return $P_DOMXML_Management_Array[$XML];
}

/* P002 : Add Start!! ************************************************/

/*********************************************************************/
function P_DOMXML_Get_XPathObject( $XML )
{
 global $P_DOMXML_Management_XPath_Array;

 return $P_DOMXML_Management_XPath_Array[$XML];
}

/************************************************** P002 : Add End!! */

/*********************************************************************/
function P_DOMXML_Search_Attribute( $Object )
{
 if( $Object->has_attributes( ) != TRUE ){ return FALSE; }

 $Attribute_Array = $Object->attributes( );
 $Array           = array( );

 foreach( $Attribute_Array as $Attribute_Object )
 {
  $Key   =
  P_DOMXML_Convert_Encoding( $Attribute_Object->name( ), "1" );
  $Value =
  P_DOMXML_Convert_Encoding( $Attribute_Object->get_content( ), "1" );

  $Array[$Key] = $Value;
 }

 if( count( $Array ) == 0 ){ $Array = FALSE; }

 return $Array;
}

/*********************************************************************/
function P_DOMXML_Search_ChildNode( $Object )
{
 if( $Object->has_child_nodes( ) != TRUE ){ return FALSE; }

 $Child_Object = $Object->child_nodes( );
 $Result_Array = array( );

 foreach( $Child_Object as $Child_Array )
 {
  $Array   = array( "name" => "", "value" => "",
                    "attribute" => FALSE, "child" => FALSE );
  $TagName =
  P_DOMXML_Convert_Encoding( $Child_Array->node_name( ), "1" );

  if( mb_substr( $TagName, 0, 1 ) == "#" ){ continue; }

  $Array["name"]      = $TagName;
  $Value              =
  P_DOMXML_Convert_Encoding( $Child_Array->get_content( ), "1" );
  $Array["value"]     = P_DOMXML_ChangeText( $Value );
  $Array["attribute"] = P_DOMXML_Search_Attribute( $Child_Array );
  $Array["child"]     = P_DOMXML_Search_ChildNode( $Child_Array );

  if( is_array( $Array["child"] ) == TRUE ){ $Array["value"] = ""; }

  $Result_Array[] = $Array;
 }

 if( count( $Result_Array ) == 0 ){ $Result_Array = FALSE; }

 return $Result_Array;
}

/*********************************************************************/
/* P002 : Change Start!! *********************************************/

//function P_DOMXML_Search_Node( $Object, $Name )

function P_DOMXML_Search_Node( $Object, $Name, $XML )

/*********************************************** P002 : Change End!! */
{
 if( strlen( $Name ) <= 0 ){ return FALSE; }

 $Result_Array = array( );
 $Name         = P_DOMXML_Convert_Encoding( $Name, "2" );
/* P002 : Change Start!! *********************************************/

// $Object_Array = $Object->get_elements_by_tagname( $Name );

 $XPath        =  P_DOMXML_Get_XPathObject( $XML );
 $XPath_Array  = $XPath->xpath_eval( $Name );
 $Object_Array = $XPath_Array->nodeset;

/*********************************************** P002 : Change End!! */

 if( is_array( $Object_Array ) != TRUE ){ return FALSE; }

 foreach( $Object_Array as $Node_Array )
 {
  $Array   = array( "name" => "", "value" => "",
                    "attribute" => FALSE, "child" => FALSE );
  $TagName =
  P_DOMXML_Convert_Encoding( $Node_Array->node_name( ), "1" );

  if( mb_substr( $TagName, 0, 1 ) == "#" ){ continue; }

  $Array["name"]      = $TagName;
  $Value              =
  P_DOMXML_Convert_Encoding( $Node_Array->get_content( ), "1" );
  $Array["value"]     = P_DOMXML_ChangeText( $Value );
  $Array["attribute"] = P_DOMXML_Search_Attribute( $Node_Array );

  $Array["child"]     = P_DOMXML_Search_ChildNode( $Node_Array );

  if( is_array( $Array["child"] ) == TRUE ){ $Array["value"] = ""; }

  $Result_Array[] = $Array;
 }

 if( count( $Result_Array ) == 0 ){ $Result_Array = FALSE; }

 return $Result_Array;
}

/*********************************************************************/
function P_DOMXML_SetErrorHandler( $BackTrace )
{
 global $P_DOMXML_Error; global $P_DOMXML_ErrorHandler;

 if( $P_DOMXML_ErrorHandler != "" )
   {
    $Array["Type"]     = "DOMXML";
    $Array["File"]     = $BackTrace[0]["file"];
    $Array["Line"]     = $BackTrace[0]["line"];
    $Array["Function"] = $BackTrace[0]["function"];
    $Array["Arg"]      = $BackTrace[0]["args"];
    $Array["Value"]    = $P_DOMXML_Error;
    $Array["All"]      = $BackTrace;

    $P_DOMXML_ErrorHandler( $Array );
   }
}

?>
