<?
/*********************************************************************/
/*      V001 ： 新規  2004.10.31  桝形                               */
/*********************************************************************/

/*********************************************************************/
/*    関数名 ： P_SJIS_DecodeCode                                    */
/*-------------------------------------------------------------------*/
/*      機能 ： 特殊な文字に変換した文字列を元の文字に戻す           */
/*-------------------------------------------------------------------*/
/*      引数 ： $Str      (i)    特殊な文字が定義された文字列        */
/*           ： $Encoding (i)    動作させる文字コード                */
/*-------------------------------------------------------------------*/
/*    戻り値 ： 元に戻した文字列                                     */
/*-------------------------------------------------------------------*/
/* Copyright ： DNP DigitalCom CO.,LTD.                              */
/*      P001 ： 新規  2004.10.31  桝形                               */
/*********************************************************************/
function P_SJIS_DecodeCode( $Str, $Encoding = "" )
{
 $Length   = mb_strlen( $Str );
 $XX       = 0;
 $StartTag = "[[G:";
 $EndTag   = "]]";
 $Start    = FALSE;
 $End      = FALSE;

 $OutRegex    = mb_regex_encoding( );
 $OutEncoding = mb_internal_encoding( );

 if( mb_strlen( $Encoding ) > 0 )
   {
    mb_regex_encoding( $Encoding );
    mb_internal_encoding( $Encoding );
   }

 while( $XX < $Length )
 {
  $Start = mb_strpos( mb_strtoupper( $Str ), $StartTag );
  $End   = mb_strpos( mb_strtoupper( $Str ), $EndTag, ( $Start + 1 ) );

  if( $Start === FALSE || $End === FALSE ){ break; }

  $Start_Str  = mb_substr( $Str, 0, $Start );
  $End_Str    = mb_substr( $Str, ( $End + 2 ) );
  $Change_Str = mb_substr( $Str, ( $Start + 4 ), ( $End - $Start - 4 ) );

  if( mb_strlen( $Change_Str ) < 2 ||
      mb_strlen( $Change_Str ) > 6 ){ $XX = ( $End + 2 ); continue; }

  if( mb_strlen( $Change_Str ) % 2 != 0 ){ $XX = ( $End + 2 ); continue; }

  if( mb_strlen( mb_eregi_replace( "[0-9A-F]", "", $Change_Str ) ) > 0 )
    { $XX = ( $End + 2 ); continue; }

  $Change_Str = @pack( "H*", mb_strtolower( $Change_Str ) );

  $Str = $Start_Str.$Change_Str.$End_Str;

  $XX = 0;
 }

 mb_regex_encoding( $OutRegex );
 mb_internal_encoding( $OutEncoding );

 return $Str;
}

?>
