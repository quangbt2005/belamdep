<?php
function P_MySQL_Connect_Host
                     ( &$Connect, $DB_Host, $DB_User, $DB_Pass, $Type )
{
 global $P_MySQL_Warning; $P_MySQL_Warning = ""; /* P002 : Add!! */

 if( $Type == "2" )
   { $Connect = @mysql_pconnect( $DB_Host, $DB_User, $DB_Pass ); }
   else
   { $Connect = @mysql_connect(  $DB_Host, $DB_User, $DB_Pass ); }

 if( $Connect == FALSE )
   {
    @mysql_close( $Connect );
    sleep( 1 );

    if( $Type == "2" )
      { $Connect = @mysql_pconnect( $DB_Host, $DB_User, $DB_Pass ); }
      else
      { $Connect = @mysql_connect(  $DB_Host, $DB_User, $DB_Pass ); }

    if( $Connect == FALSE )
      {
       $P_MySQL_Warning = "P_MySQL\P_MySQL_Private_Function.inc\nLine 25\n";

       return $P_MySQL_Warning;
      }
   }

 return "";
}

/*********************************************************************/
define('DB_EmptyResult', 'ON');
function P_MySQL_Get_Num_Row( &$Result )
{
 $Line_XX = @mysql_num_rows( $Result );

 if( strtoupper( DB_EmptyResult ) == "ON" )
   {
    if( $Line_XX == FALSE || $Line_XX == 0 )
      { $Array = array( ); return $Array; }
   }

 if( $Line_XX == FALSE || $Line_XX == 0 )
   { $Array[0] = FALSE; return $Array; }

 return $Line_XX;
}

/*********************************************************************/
function P_MySQL_Get_Num_Fields( &$Result, &$Line_YY )
{
 $Line_YY = @mysql_num_fields( $Result );
 if( $Line_YY == FALSE )
   { return "P_MySQL\P_MySQL_Private_Function.inc\nLine 56\n"; }

 return "";
}
/*********************************************************************/
function P_MySQL_Get_Value( &$Result, &$Array, $Line_XX, $Line_YY,
                                    $Type, $FLG = "", $Delimiter = "" )
{
 if( strlen( $Delimiter ) <= 0 ){ $Delimiter = "\t"; }
 $Array = array( );

 for( $XX = 0; $XX < $Line_XX; ++$XX )
 {
    if( strtoupper( $FLG ) == "KEY INDEX" )
    {
      $Record = @mysql_fetch_array( $Result, MYSQL_ASSOC );

      if( $Record == FALSE )
      { return "P_MySQL\P_MySQL_Private_Function.inc\nLine 74\n"; }

      $Array[] = $Record;
      continue;
    }

    $Record = @mysql_fetch_row( $Result );

    if( $Record == FALSE )
      { return "P_MySQL\P_MySQL_Private_Function.inc\nLine 83\n"; }

    if( strtoupper( $FLG ) == "NUMBER INDEX" ){ $Array[] = $Record; continue; }

    for( $YY = 0; $YY < $Line_YY; ++$YY )
    {
      switch( $Type )
      {
        case "1" : {
                    $Array[$XX] .= P_HTML_Cnv( $Record[$YY], "1" );
                    break;
                   }
        case "2" : {
                    $Array[$XX] .= P_HTML_Cnv( $Record[$YY], "2" );
                    break;
                   }
        case "3" : {
                    $Array[$XX] .= P_HTML_Cnv( $Record[$YY], "4" );
                    break;
                   }
        case "4" : {
                    $Array[$XX] .= P_HTML_Cnv( $Record[$YY], "5" );
                    break;
                   }
        case "5" : {
                    $Array[$XX] .= P_HTML_Cnv( $Record[$YY], "6" );
                    break;
                   }
        default  : {
                    if(isset($Array[$XX]))
                      $Array[$XX] .= $Record[$YY];
                    else
                      $Array[$XX] = $Record[$YY];

                    break;
                   }
      }

      if( ( $YY + 1 ) < $Line_YY ){ $Array[$XX] .= $Delimiter; }
    }
 }

 return "";
}

/*********************************************************************/
function P_MySQL_MemoryFree( &$Result )
{
 if( @mysql_free_result( $Result ) == FALSE )
   { return "P_MySQL\P_MySQL_Private_Function.inc\nLine 128\n"; }

 return "";
}

/*********************************************************************/
function P_MySQL_QueryExec( &$Connect, &$Result, $SQL, $DB_Host,
                            $DB_User, $DB_Pass, $DB_Name, $Type, $Flg )
{
 $Result = mysql_query( $SQL, $Connect );

 if( $Result == FALSE )
   {
    if( stristr( @mysql_error( $Connect ),
                 "Lost connection to MySQL server during query" )
        != FALSE )
      {
       if( RE_TRY_FLG == "On" && $Flg == "" )
         {
          return P_MySQL_Retry( $Connet, $Result, $SQL, $DB_Host,
                                 $DB_User, $DB_Pass, $DB_Name, $Type );
         }
      }

    return "P_MySQL\P_MySQL_Private_Function.inc\nLine 152\n";
   }

 return "";
}

/*********************************************************************/
function P_MySQL_QueryCheck( $SQL, $Type, $Level, $DB_Name, $Function )
{
 global $P_MySQL_Error;

 if( stristr( substr( $SQL, 0 , 5 ), "DROP "  )  != FALSE ||
     stristr( substr( $SQL, 0 , 7 ), "CREATE " ) != FALSE )
   {
    return "P_MySQL\P_MySQL_Private_Function.inc\nLine 166\n";
   }

 if( $Type == "SELECT" )
   {
    if( stristr( substr( $SQL, 0 , 8 ), "SELECT "  ) == FALSE &&
        stristr( substr( $SQL, 0 , 8 ), "EXPLAIN " ) == FALSE &&
        stristr( substr( $SQL, 0 , 8 ), "SHOW "    ) == FALSE )
      {
       return "P_MySQL\P_MySQL_Private_Function.inc\nLine 175\n";
      }

    if( ORDER_BY_FLG == "On" )
      {
       if( stristr( $SQL, "ORDER BY" ) == FALSE &&
           "SELECT COUNT("             != substr( $SQL, 0, 13 ) )
         {
          return "P_MySQL\P_MySQL_Private_Function.inc\nLine 183\n";
         }
      }

    if( WILD_CARD_FLG == "On" )
      {
       if( stristr( substr( $SQL, 0, 13 ), "SELECT * FROM" ) != FALSE )
         {
          return "P_MySQL\P_MySQL_Private_Function.inc\nLine 191\n";
         }
      }
   }
   else
   {
    if( stristr( substr( $SQL, 0, 8 ), "SELECT "  ) != FALSE ||
        stristr( substr( $SQL, 0, 8 ), "EXPLAIN " ) != FALSE ||
        stristr( substr( $SQL, 0, 8 ), "SHOW "    ) != FALSE )
      {
       return "P_MySQL\P_MySQL_Private_Function.inc\nLine 201\n";
      }
   }

 return "";
}

/*********************************************************************/
function P_MySQL_Quote_Escape_String( $SQL, $Reg_Array, $Cnv_Array )
{
 $Pattern = "/[\\x00-\\x08]|[\\x0B-\\x0C]|[\\x0E-\\x1F]/";
 $SQL     = preg_replace( $Pattern, "", $SQL );

 $XX = 0;

 $Count = count( $Reg_Array );

 while( $XX < $Count )
 {
  $SQL = mb_ereg_replace( $Reg_Array[$XX], $Cnv_Array[$XX], $SQL );
  ++$XX;
 }

 return $SQL;
}

/*********************************************************************/
function P_MySQL_Retry( &$Connect, &$Result, $SQL, $DB_Host,
                                 $DB_User, $DB_Pass, $DB_Name, $Type )
{
 @mysql_close( $Connect );

 $P_MySQL_Error = P_MySQL_Connect_Host( $Connect,
                                $DB_Host, $DB_User, $DB_Pass, $Type );

 if( $P_MySQL_Error != "" ){ return $P_MySQL_Error; }

 $P_MySQL_Error = P_MySQL_Select_DB( $Connect, $DB_Name );

 if( $P_MySQL_Error != "" ){ return $P_MySQL_Error; }

 $P_MySQL_Error = P_MySQL_QueryExec( $Connect, $Result, $SQL,
            $DB_Host, $DB_User, $DB_Pass, $DB_Name, $Type, "Warning" );

 if( $P_MySQL_Error != "" ){ return $P_MySQL_Error; }

 return "";
}

/*********************************************************************/
function P_MySQL_Select_DB( &$Connect, $DB_Name )
{
 if( @mysql_select_db( $DB_Name, $Connect ) == FALSE )
   {
    return "P_MySQL\P_MySQL_Private_Function.inc\nLine 255\n";
   }
}

@include_once( LIB_PATH . "P_MySQL/P_MySQL_Error_SetErrorHandler_Private_Function.inc" );
@include_once( LIB_PATH . "P_CSS_Cnv/P_HTML_Cnv_Function.inc" );

?>
