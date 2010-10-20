<?
/*********************************************************************/
/*      V001 �F �V�K  2005.01.01  ���`                               */
/*      V002 �F �ǉ�  2005.10.31  ���`                               */
/*      V003 �F �ǉ�  2006.06.01  ���`                               */
/*********************************************************************/

/*********************************************************************/
/*    �֐��� �F P_SJIS_Convert_Private_Function                      */
/*-------------------------------------------------------------------*/
/*      �@�\ �F P_SJIS���C�u�����ɓo�^����Ă���֐��Q����           */
/*           �F �̂݌Ăяo�����v���C�x�[�g�֐��Q                   */
/*-------------------------------------------------------------------*/
/*      ���� �F �����͊���                                           */
/*-------------------------------------------------------------------*/
/*    �߂�l �F �����͊���                                           */
/*-------------------------------------------------------------------*/
/*      �x�� �F �@�\�ɏ����Ă���ʂ�A�ʏ험�p�͔����ĉ������B       */
/*-------------------------------------------------------------------*/
/* Copyright �F DNP DigitalCom CO.,LTD.                              */
/*      P001 �F �V�K  2004.05.01  ���`                               */
/*      P002 �F �ǉ�  2004.10.31  ���`                               */
/*********************************************************************/
/*********************************************************************/
function P_SJIS_Convert_ChangeGAIJI
                        ( $String, $GAIJI, $Convert_Array, $GAIJI_Flg )
{
 if( mb_strlen( $String ) <= 0 ){ return ""; }

 if( is_array( $Convert_Array ) != TRUE )
   {
    return P_SJIS_Convert_ChangeGAIJI_GetString
                                       ( $String, $GAIJI, $GAIJI_Flg );
   }

 $Key = mb_strtoupper( bin2hex( $String ) );

 if( mb_strlen( $Convert_Array[$Key] ) > 0 )
   {
    $Value = $Convert_Array[$Key];
    $Value = @pack( "H*", $Value );
    $Value = P_SJIS_Convert_ConvertEncoding( $Value );

    return $Value;
   }

 return P_SJIS_Convert_ChangeGAIJI_GetString
                                       ( $String, $GAIJI, $GAIJI_Flg );
}

/*********************************************************************/
function P_SJIS_Convert_ChangeGAIJI_GetString
                                        ( $String, $GAIJI, $GAIJI_Flg )
{
/* P002 : Add Start!! ************************************************/

 if( mb_strtoupper( $GAIJI ) == "CODE CONVERT" )
   { return "[[G:".mb_strtoupper( bin2hex( $String ) )."]]"; }

/************************************************** P002 : Add End!! */

 if(  mb_strtoupper( $GAIJI_Flg ) == "NO CHANGE" )
   {
    if( strtoupper( mb_internal_encoding( ) ) == "SJIS"     ||
        strtoupper( mb_internal_encoding( ) ) == "SJIS-WIN" )
      { return $String; }
   }

 return $GAIJI;
}

/*********************************************************************/
function P_SJIS_Convert_isGAIJI( $String )
{
 if( strlen( $String ) < 2 ){ return FALSE; }

  $SJIS_Array = array(
  "/[\\x89-\\x97\\x99-\\x9F\\xE0-\\xE9][\\x40-\\x7E\\x80-\\xFC]/",
  "/\\x81[\\x40-\\x7E\\x80-\\xAC\\xB8-\\xBF\\xC8-\\xCE".
                                       "\\xDA-\\xE8\\xF0-\\xF7\\xFC]/",
  "/\\x82[\\x4F-\\x58\\x60-\\x79\\x81-\\x9A\\x9F-\\xF1]/",
  "/\\x83[\\x40-\\x7E\\x80-\\x96\\x9F-\\xB6\\xBF-\\xD6]/",
  "/\\x84[\\x40-\\x60\\x70-\\x7E\\x80-\\x91\\x9F-\\xBE]/",
  "/\\x88[\\x9F-\\xFC]/",
  "/\\x98[\\x40-\\x72\\x9F-\\xFC]/",
  "/\\xEA[\\x40-\\x7E\\x80-\\xA4]/" );

 foreach( $SJIS_Array as $Value )
 {
  if( mb_strlen( preg_replace( $Value, "", $String ) ) !=
      mb_strlen( $String ) ){ return FALSE; }
 }

 return TRUE;
}

/*********************************************************************/
function P_SJIS_Convert_ChangeString
                        ( $String, $GAIJI, $Convert_Array, $GAIJI_Flg )
{
 $Length    = mb_strlen( $String, "SJIS-win" );
 $OutString = "";

 for( $XX = 0; $XX < $Length; ++$XX )
 {
  $Out = mb_substr( $String, $XX, 1, "SJIS-win" );

  if( P_SJIS_Convert_isGAIJI( $Out ) == TRUE )
    {
     $Out = P_SJIS_Convert_ChangeGAIJI( $Out, $GAIJI,
                                          $Convert_Array, $GAIJI_Flg );
    }
    else
    { $Out = P_SJIS_Convert_ConvertEncoding( $Out ); }

  $OutString .= $Out;
 }

 return $OutString;
}

/*********************************************************************/
function P_SJIS_Convert_ConvertEncoding( $String )
{
 if( strtoupper( mb_internal_encoding( ) ) != "SJIS"     &&
     strtoupper( mb_internal_encoding( ) ) != "SJIS-WIN" )
   {
    $String = mb_convert_encoding( $String,
                                 mb_internal_encoding( ), "SJIS-win" );
   }

 return $String;
}

/*V003:AddStart!!*****************************************************/

global $P_SJIS_SetGAIJI; $P_SJIS_SetGAIJI = "";

/*******************************************************V003:AadEnd!!*/
?>