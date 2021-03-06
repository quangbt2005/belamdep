<?
/*********************************************************************/
/*      V001 �F �V�K  2004.05.01  ���`                               */
/*********************************************************************/

/*********************************************************************/
/*    �֐��� �F P_DOMXML_GetValue                                    */
/*-------------------------------------------------------------------*/
/*      �@�\ �F DOM/XML�c���[�쟍�ă��b�Z�[�W�擾                */
/*-------------------------------------------------------------------*/
/*      �� �F $XML (i)             XML�t�@�C����                   */
/*           �F $XPath (i)           XPath                           */
/*           �F $Duplicate (i)       �d���t���O                      */
/*           �F $Change_Array (i)    �u���Ώۊi�[�A�z�z��            */
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
function P_DOMXML_GetValue
          ( $XML, $XPath, $Duplicate = "ON", $Change_Array = array( ) )
{
 global $P_DOMXML_Error; $P_DOMXML_Error = ""; $Value = "";

 $Array = P_DOMXML_SearchTree( $XML, $XPath, $Change_Array );

 if( $P_DOMXML_Error != "" ){ return $Value; }

 if( is_array( $Array ) != TRUE ){ return $Value; }

 foreach( $Array as $Value_Array )
 {
  if( mb_strtoupper( $Duplicate ) != "ON" )
    { $Value[] = $Value_Array["value"]; }
    else
    { $Value   = $Value_Array["value"]; }
 }

 return $Value;
}

/*********************************************************************/
/*    �Ք���C�u�����֐��Q                                           */
/*********************************************************************/

@include_once( LIB_PATH . "P_DOMXML/P_DOMXML_SearchTree_Function.inc" );

?>
