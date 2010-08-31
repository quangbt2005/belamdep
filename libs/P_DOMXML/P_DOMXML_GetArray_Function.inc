<?
/*********************************************************************/
/*      V001 �F �V�K  2006.01.05  ���`                               */
/*********************************************************************/

/*********************************************************************/
/*    �֐��� �F P_DOMXML_GetArray                                    */
/*-------------------------------------------------------------------*/
/*      �@�\ �F DOM/XML�c���[�쟍�Ĕz��Ń��b�Z�[�W��擾        */
/*-------------------------------------------------------------------*/
/*      �� �F $XML          (i)    XML�t�@�C����                   */
/*           �F $XPath        (i)    XPath                           */
/*           �F $FLG          (i)    �����l�̎w��                    */
/*           �F $Change_Array (i)    �u���Ώۊi�[�A�z�z��            */
/*-------------------------------------------------------------------*/
/*    �߂�l �F DOM/XML�c���[����ʊi�[�z��                        */
/*           �F ( ����ʂ��d�������ꍇ�͏㏑�������̂Œ��ӁI )   */
/*-------------------------------------------------------------------*/
/*      �x�� �F �O���[�o���̈�ϐ����L���Ă���̂ŁA���L�̕ϐ�     */
/*           �F �ɑ΂��ĎQ�ƈȊO�̗��p�͔⯂ĉ������B               */
/*           �F                                                      */
/*           �F $P_DOMXML_Error                                      */
/*-------------------------------------------------------------------*/
/* Copyright �F DNP DigitalCom CO.,LTD.                              */
/*      P001 �F �V�K  2006.01.05  ���`                               */
/*********************************************************************/
function P_DOMXML_GetArray( $XML, $XPath, $FLG = "", $Change_Array = array( ) )
{
 global $P_DOMXML_Error; $P_DOMXML_Error = ""; $Out_Array = "";

 if( mb_strlen( $FLG ) <= 0 ){ $FLG = "id"; }

 $Array = P_DOMXML_SearchTree( $XML, $XPath, $Change_Array );

 if( $P_DOMXML_Error != "" ){ return $Out_Array; }

 if( is_array( $Array ) != TRUE ){ return $Out_Array; }

 foreach( $Array as $Value )
 {
  $Att_Array = $Value["attribute"];

  if( is_array( $Att_Array )        != TRUE ){ continue; }
  if( mb_strlen( $Att_Array[$FLG] ) <= 0 ){ continue; }
  if( mb_strlen( $Value["value"] )  <= 0 ){ continue; }

  $OUT_Key = $Att_Array[$FLG];
  $Out_Array[$OUT_Key] = $Value["value"];
 }

 return $Out_Array;
}

/*********************************************************************/
/*    �Ք���C�u�����֐��Q                                           */
/*********************************************************************/

@include_once( LIB_PATH . "P_DOMXML/P_DOMXML_SearchTree_Function.inc" );

?>
