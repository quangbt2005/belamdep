<?php
function P_MySQL_Close2( )
{
 global $P_MySQL_Connect2;

 if( @is_resource( $P_MySQL_Connect2 ) != TRUE ){ return TRUE; } /* P002 : Add!! */

/* P002 : Change Start!! *********************************************/

/**********************************************************************

 if( @mysql_close( $P_MySQL_Connect2 ) == TRUE ){ return TRUE;  }
   else                                         { return FALSE; }

**********************************************************************/

 $Bool = @mysql_close( $P_MySQL_Connect2 );

 $P_MySQL_Connect2 = "";

 if( $Bool == TRUE ){ return TRUE;  }
   else             { return FALSE; }

/*********************************************** P002 : Change End!! */
}

?>
