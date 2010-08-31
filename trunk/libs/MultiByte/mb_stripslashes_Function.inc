<?php
if( @function_exists( "mb_stripslashes" ) != TRUE )
  {
   function mb_stripslashes( $Str )
   {
    $Ot = ""; $Buffer = ""; $Count = mb_strlen( $Str );

    for( $XX = 0; $XX < $Count; ++$XX )
    {
     $Key = mb_substr( $Str, $XX, 1 );

     if( $Key != "\\" ){ $Ot .= $Key; $Buffer = ""; }
       else
       {
        if( $Buffer != "\\" ){ $Buffer = $Key; }
          else               { $Ot .= $Key; $Buffer = ""; }
       }
    }

    return $Ot;
   }
  }

?>
