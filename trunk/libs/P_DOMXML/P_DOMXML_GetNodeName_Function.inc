<?
/*********************************************************************/
/*      V001 �F �V�K  2004.05.01  ���`                               */
/*********************************************************************/

/*********************************************************************/
/*    �֐��� �F P_DOMXML_GetNodeName                                 */
/*-------------------------------------------------------------------*/
/*      �@�\ �F DOM/XML�c���[�쟍�ăm�[�h�̖��O��擾            */
/*-------------------------------------------------------------------*/
/*      �� �F $XML (i)             XML�t�@�C����                   */
/*           �F $XPath (i)           XPath                           */
/*           �F $Duplicate (i)       �d���t���O                      */
/*-------------------------------------------------------------------*/
/*    �߂�l �F DOM/XML�c���[����ʊi�[������                      */
/*           �F ( ����ʂ��d�������ꍇ�͏㏑�������̂Œ��ӁI )   */
/*-------------------------------------------------------------------*/
/*      �x�� �F �O���[�o���̈�ϐ����L���Ă���̂ŁA���L�̕ϐ�     */
/*           �F �ɑ΂��ĎQ�ƈȊO�̗��p�͔⯂ĉ������B               */
/*           �F                                                      */
/*           �F $P_DOMXML_Error                                      */
/*-------------------------------------------------------------------*/
/* Copyright �F DNP DigitalCom CO.,LTD.                              */
/*      P001 �F �V�K  2004.05.01  ���`                               */
/*********************************************************************/
function P_DOMXML_GetNodeName( $XML, $XPath, $Duplicate = "ON" )
{
 global $P_DOMXML_Error; $P_DOMXML_Error = ""; $Node = "";

 $Array = P_DOMXML_SearchTree( $XML, $XPath, $Change_Array );

 if( $P_DOMXML_Error != "" ){ return $Node; }

 if( is_array( $Array ) != TRUE ){ return $Node; }

 foreach( $Array as $Node_Array )
 {
  if( is_array( $Node_Array["child"] ) == TRUE )
    {
     foreach( $Node_Array["child"] as $Child_Node_Array )
     {
      if( mb_strtoupper( $Duplicate ) != "ON" )
        { $Node[] = $Child_Node_Array["name"]; }
        else
        { $Node   = $Child_Node_Array["name"]; }
     }
    }
 }

 return $Node;
}

/*********************************************************************/
/*    �Ք���C�u�����֐��Q                                           */
/*********************************************************************/

@include_once( LIB_PATH . "P_DOMXML/P_DOMXML_SearchTree_Function.inc" );

?>
