<?php
function P_CSS_Cnv_addslashes( $Str )
{
 $Ot = mb_ereg_replace( "\\\\", "\\\\", $Str );
 $Ot = mb_ereg_replace( "\"",   "\\\"", $Ot );
 $Ot = mb_ereg_replace( "'",    "\\'",  $Ot );

 return $Ot;
}

function P_CSS_Cnv_htmlspecialchars( $Str )
{
 $Ot = mb_ereg_replace( "&",  "&amp;",  $Str );
 $Ot = mb_ereg_replace( "\"", "&quot;", $Ot );
 $Ot = mb_ereg_replace( "<",  "&lt;",   $Ot );
 $Ot = mb_ereg_replace( ">",  "&gt;",   $Ot );

 return $Ot;
}

function P_CSS_Cnv_stripslashes( $Str )
{
 $Ot = ""; $Buffer = ""; $Count = mb_strlen( $Str );

 for( $XX = 0; $XX < $Count; ++$XX )
 {
  $Key = mb_substr( $Str, $XX, 1 );

  if( $Key != "\\" ){ $Ot .= $Key; }
    else
    {
     if( $Buffer != "\\" ){ $Buffer = $Key; }
       else               { $Ot .= $Key; $Buffer = ""; }
    }
 }

 return $Ot;
}

function P_CSS_Cnv_strip_tags( $Str )
{
 $Ot = mb_ereg_replace( "<[^>]*>", "", $Str );

 return $Ot;
}

?>
