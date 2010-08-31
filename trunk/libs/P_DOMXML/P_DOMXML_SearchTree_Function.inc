<?
/*********************************************************************/
/*      V001 �F �V�K  2004.05.01  ���`                               */
/*      V002 �F �ǉ�  2004.07.21  ���`                               */
/*      V003 �F �C��  2006.01.06  ���`                               */
/*********************************************************************/

/*********************************************************************/
/*    �֐��� �F P_DOMXML_SearchTree                                  */
/*-------------------------------------------------------------------*/
/*      �@�\ �F DOM/XML�c���[�쟍�                                  */
/*-------------------------------------------------------------------*/
/*      �� �F $XML (i)             XML�t�@�C����                   */
/*           �F $XPath (i)           XPath                           */
/*           �F $Change_Array (i)    �u���Ώۊi�[�A�z�z��            */
/*-------------------------------------------------------------------*/
/*    �߂�l �F DOM/XML�c���[����ʊi�[�z��                        */
/*-------------------------------------------------------------------*/
/*      �x�� �F �O���[�o���̈�ϐ����L���Ă���̂ŁA���L�̕ϐ�     */
/*           �F �ɑ΂��ĎQ�ƈȊO�̗��p�͔⯂ĉ������B               */
/*           �F                                                      */
/*           �F $P_DOMXML_Change_Array                               */
/*           �F $P_DOMXML_Error                                      */
/*           �F $P_DOMXML_ErrorHandler                               */
/*           �F $P_DOMXML_Management_Array                           */
/*           �F $P_DOMXML_Management_XPath_Array                     */
/*           �F $P_DOMXML_ResultCache_Array                          */
/*-------------------------------------------------------------------*/
/* Copyright �F DNP DigitalCom CO.,LTD.                              */
/*      P001 �F �V�K  2004.05.01  ���`                               */
/*      P002 �F �ǉ�  2004.07.21  ���`                               */
/*      P003 �F �C��  2006.01.06  ���`                               */
/*********************************************************************/
function P_DOMXML_SearchTree
             ( $XML, $XPath, $Change_Array = array( ) )
{
 global $P_DOMXML_Error; $P_DOMXML_Error = "";
 global $P_DOMXML_Change_Array; $P_DOMXML_Change_Array = $Change_Array;

 if( function_exists( "debug_backtrace" ) == TRUE )
   { $BackTrace = debug_backtrace( ); }

 if( is_array( $XML ) != TRUE )
   { $wkXML = $XML; $XML = array( ); $XML["XML"] = $wkXML; }

/* P002 : Add Start!! ************************************************/

 global $P_DOMXML_ResultCache_Array;

/* P003 : Change Start!! *********************************************/

/**********************************************************************

 $Cache = $XML["XML"].$XPath;

 if( is_array( $P_DOMXML_ResultCache_Array[$Cache] ) == TRUE )
   { return $P_DOMXML_ResultCache_Array[$Cache]; }

**********************************************************************/

 if( @is_file( $XML["XML"] ) == TRUE )
   {
    if( is_array( $Change_Array ) == TRUE && count( $Change_Array ) > 0 )
      {
       $Cache = @realpath( $XML["XML"] ).$XPath;

       if( is_array( $P_DOMXML_ResultCache_Array[$Cache] ) == TRUE )
         { return $P_DOMXML_ResultCache_Array[$Cache]; }
      }
   }

/*********************************************** P003 : Change End!! */
/************************************************** P002 : Add End!! */


 $P_DOMXML_Error = P_DOMXML_Get_Node( $XML, $XPath, $Result_Array );

 if( $P_DOMXML_Error != "" )
   { P_DOMXML_SetErrorHandler( $BackTrace ); return FALSE; }

/* P003 : Add Start!! ************************************************/

 if( is_array( $Change_Array ) == TRUE && count( $Change_Array ) > 0 )
   { return $Result_Array; }

/************************************************** P003 : Add End!! */
/* P002 : Add Start!! ************************************************/

 $P_DOMXML_ResultCache_Array[$Cache] = $Result_Array;

/************************************************** P002 : Add End!! */

 return $Result_Array;
}

/*********************************************************************/
/*    �Ք���C�u�����֐��Q                                           */
/*********************************************************************/

@include_once( LIB_PATH . "P_DOMXML/P_DOMXML_Private_Function.inc" );

/*********************************************************************/
/*    �ˑ����C�u�����֐��Q                                           */
/*********************************************************************/

@include_once( LIB_PATH . "MultiByte/mb_str_replace_Function.inc" );
@include_once( LIB_PATH . "P_FileIO/P_FileIO_isFile_Function.inc" );

?>
