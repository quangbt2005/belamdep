<?php
/**********************************************************************/
/* Created on Dec 14, 2008                                            */
/**********************************************************************/
function Garbare_Session()
{
  global $Request, $Session_Map;

  $module    = $Request["fact_module"];
  $page      = $Request["fact_page"];

  $Keep_Data = array();

  $Require_Data = $Session_Map["require"];
  $Module_Data  = $Session_Map[$module][$page];

  foreach( $Require_Data as $key )
  {
    if( isset( $_SESSION[$key] ) )
    {
      $Keep_Data[$key] = $_SESSION[$key];
    }
  }
  if( empty( $Module_Data ) == FALSE && is_array( $Module_Data ) )
  {
    foreach( $Module_Data as $key )
    {
      if( isset( $_SESSION[$key] ) )
      {
        $Keep_Data[$key] = $_SESSION[$key];
      }
    }
  }

  $_SESSION = $Keep_Data;
}
?>
