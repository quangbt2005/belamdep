<?php
function P_MySQL_Close( )
{
 global $P_MySQL_Connect;

 if( @is_resource( $P_MySQL_Connect ) != TRUE ){ return TRUE; } /* P002 : Add!! */

/* P002 : Change Start!! *********************************************/

/**********************************************************************

 if( @mysql_close( $P_MySQL_Connect ) == TRUE ){ return TRUE;  }
   else                                        { return FALSE; }

**********************************************************************/

 $Bool = @mysql_close( $P_MySQL_Connect );

 $P_MySQL_Connect = "";

 if( $Bool == TRUE ){ return TRUE;  }
   else             { return FALSE; }

/*********************************************** P002 : Change End!! */
}

?>
