<?
/*********************************************************************/
/*     Client  Name  :  Global Cybersoft                             */
/*     System  Name  :  GCS Web Site                                 */
/*     Project Name  :  GCS Web Site                                 */
/*     Program Name  :  XML_ErrorCheck_Config.inc                    */
/*     Create Date   :  2008/09/16                                   */
/*     Programmer    :  hoangpm(GCS)                                 */
/*     Entry Server  :                                               */
/*     Called By     :  ALL                                          */
/*     File Code     :  SJIS                                         */
/*     Execute Env   :  EUC                                          */
/*     Copyright     :  Global Cybersoft.                            */
/*-------------------------------------------------------------------*/
/*     Comment       :                                               */
/*-------------------------------------------------------------------*/
/*     Version V001  :  2008/09/25 (hoangpm) New Create              */
/*********************************************************************/

//-------------------------------------------------------------------//
// Include check XML error
//-------------------------------------------------------------------//
include_once( "P_XML_ErrorCheck/P_XML_ErrorCheck_Function.inc" );

include_once( "P_Mail/P_Mail_Check_P2_Function.inc" );

include_once( "P_Check/P_Word_Check_Beta_Function.inc" );

include_once( "PHP_Error/PHP_Error_Abend_Function.inc" );

include_once( "P_Check/P_Check_Ascii_MultiByte_Function.inc" );
include_once( "P_Check/P_Check_Hira_Kata_Function.inc" );
include_once( "P_Check/P_Check_PostalCode_Function.inc" );
include_once( "P_Check/P_Check_Telephone_Function.inc" );
include_once( "P_Check/P_Check_Date_Function.inc" );
include_once( "P_Cr/P_Cnv_Kaigyo_Function.inc" );
include_once( "P_Check/P_Word_Check_Alpha_Function.inc" );
include_once( "MultiByte/mb_explode_Function.inc" );

?>
