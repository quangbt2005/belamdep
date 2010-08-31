<?php
function P_Mail_Check_P( $Mail )
{
 $Pattern1 = "/[".
                 "\\x21\\x23-\\x27\\x2A-\\x2B".
                 "\\x2D-\\x39\\x3D\\x3F-\\x5A".
                 "\\x5E-\\x7E".
             "]/";
 
 $Pattern2 = "/^[^@]+@[^@\\.]+\.[^@]+\$/";
 
 $Pattern3 = "/\\@.*\\.\\..*/";
 
 if( preg_replace( $Pattern1, "", $Mail ) != "" ){ return FALSE; }

 if( preg_match( $Pattern2, $Mail ) != TRUE ){ return FALSE; }

 if( preg_replace( $Pattern3, "", $Mail ) != $Mail ){ return FALSE; }

 if( @defined( "Mail_Syntax_Start_Period" ) == TRUE &&
     strtoupper( Mail_Syntax_Start_Period ) == "OFF" )
   {
   }
   else
   {
    if( substr( $Mail, 0, 1 ) == "." ){ return FALSE; }
   }

 if( strtoupper( Mail_Syntax_End_Period ) == "ON" )
   { if( substr( $Mail, -1 ) == "." ){ return FALSE; }  }

 return TRUE;
}

?>
