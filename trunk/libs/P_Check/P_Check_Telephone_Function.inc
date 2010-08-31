<?php
function P_Check_Telephone( $Tel )
{
 $Pattern1 = "^[\\d\\(\\)-]+\$";
 $Pattern2 = "^0[^0]";
 $Pattern3 = "^(090|080|070|060|050)";

 $Result   = FALSE;

 if( mb_ereg( $Pattern1, $Tel ) == TRUE )
   {
     $Tel     = mb_ereg_replace( "\D", "", $Tel );
     $Length = strlen( $Tel );

     switch( $Length )
     {
      case  9 :
      case 10 : {
                 if( mb_ereg( $Pattern2, $Tel ) == TRUE )
                   { $Result = TRUE; }

                 break;
                }
      case 11 : {
                 if( mb_ereg( $Pattern3, $Tel ) == TRUE )
                   { $Result = TRUE; }

                 break;
                }
      default : {
                 break;
                }
     }
    }

  return $Result;
}

?>
