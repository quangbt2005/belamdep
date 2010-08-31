<?php
/**************************************************************************************************/
/* Created on July 01, 2010                                                                       */
/**************************************************************************************************/
function LoadAdministrator($user_name='')
{
  if(!empty($user_name))
  {
    $user_name = P_SQL_Quote($user_name);
    $query = 'SELECT * FROM ' . TBL_ADMIN . " WHERE user_name='" . $user_name . "'";
// pd($query);
    $Result = P_MySQL_Real_SELECT_GetArrayIndex( $query );

    if( empty( $Result[0] ) == FALSE ) {
      return $Result[0];
    }
  }

  return NULL;
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
?>
