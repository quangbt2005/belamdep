<?
/*********************************************************************/
/*      V001 �F �V�K  2004.05.01  ���`                               */
/*      V002 �F �ǉ�  2006.06.01  ���`                               */
/*      V003 �F �ǉ�  2007.05.25  ���`                               */
/*********************************************************************/

/*********************************************************************/
/*    �֐��� �F P_SJIS_Convert                                       */
/*-------------------------------------------------------------------*/
/*      �@�\ �F SJIS�������Ք�R�[�h�֕ϊ�                         */
/*-------------------------------------------------------------------*/
/*      �� �F $String        (i)    �ϊ��Ώە�����                 */
/*           �F $GAIJI         (i)    �ϊ������̎w��                 */
/*           �F $Convert_Array (i)    �Ǝ��ϊ��p�z��̒�`           */
/*           �F $GAIJI_Flg     (i)    �O���t���O                     */
/*           �F $KANA          (i)    �ϊ��t���O             *//*P003*/
/*-------------------------------------------------------------------*/
/*    �߂�l �F �ϊ��㕶����                                         */
/*-------------------------------------------------------------------*/
/*      �x�� �F �ϊ��Ώە�����̕����R�[�h��"SJIS"�Œ�ł��B         */
/*           �F                                                      */
/*           �F �O���[�o���̈�ϐ����L���Ă���̂ŁA���L�̕ϐ�     */
/*           �F �ɑ΂��ĎQ�ƈȊO�̗��p�͔⯂ĉ������B               */
/*           �F                                                      */
/*           �F $P_SJIS_SetGAIJI                                     */
/*           �F                                                      */
/*           �F �ȉ��̒萔�𗘗p���Ă��܂�                   *//*P003*/
/*           �F                                              *//*P003*/
/*           �F SJIS_optionConvert                           *//*P003*/
/*-------------------------------------------------------------------*/
/* Copyright �F DNP DigitalCom CO.,LTD.                              */
/*      P001 �F �V�K  2004.05.01  ���`                               */
/*      P002 �F �ǉ�  2006.06.01  ���`                               */
/*      P003 �F �ǉ�  2007.05.25  ���`                               */
/*********************************************************************/
/* P003 : Change Start!! *********************************************/
/**********************************************************************
function P_SJIS_Convert
         ( $String, $GAIJI = "", $Convert_Array = "", $GAIJI_Flg = "" )
{
**********************************************************************/
function P_SJIS_Convert( $String, $GAIJI = "", $Convert_Array = "",
                                          $GAIJI_Flg = "", $KANA = "" )
{
/*********************************************** P003 : Change End!! */
/* P002 : Add Start!! ************************************************/

 global $P_SJIS_SetGAIJI;

 if( mb_strlen( $GAIJI ) <= 0 ){ $GAIJI = $P_SJIS_SetGAIJI; }

/************************************************** P002 : Add End!! */
 if( $GAIJI == "" ){ $GAIJI = P_SJIS_Convert_Get_DefaultGAIJI( ); }
   else
 if( mb_strtoupper( $GAIJI ) == "DELETE" ){ $GAIJI = ""; }

 $Out = P_SJIS_Convert_ChangeString( $String, $GAIJI,
                                          $Convert_Array, $GAIJI_Flg );
/* P003 : Add Start!! ************************************************/

 if( @defined( "SJIS_optionConvert" ) == TRUE && mb_strlen( SJIS_optionConvert ) > 0 )
   {
    $Out = @mb_convert_kana( $Out, SJIS_optionConvert );
   }
   else
 if( mb_strlen( $KANA ) > 0 )
   {
    $Out = @mb_convert_kana( $Out, $KANA );
   }

/************************************************** P003 : Add End!! */
 return $Out;
}

/*********************************************************************/
/*    �Ք���C�u�����֐��Q                                           */
/*********************************************************************/

@include_once( LIB_PATH . "P_SJIS/P_SJIS_Convert_Private_Function.inc" );

switch( mb_strtoupper( mb_internal_encoding( ) ) )
{
 case "SJIS"     :
 case "SJIS-WIN" : {
                    @include_once( LIB_PATH . "P_SJIS/P_SJIS_Convert_Get_DefaultGAIJI_SJIS_Private_Function.inc" );
                    break;
                   }
 case "UTF8"     :
 case "UTF-8"    : {
                    @include_once( LIB_PATH . "P_SJIS/P_SJIS_Convert_Get_DefaultGAIJI_UTF8_Private_Function.inc" );
                    break;
                   }
 default         : {
                    @include_once( LIB_PATH . "P_SJIS/P_SJIS_Convert_Get_DefaultGAIJI_EUC_Private_Function.inc" );
                    break;
                   }
}

?>