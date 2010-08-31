<?php
/**********************************************************************/
/* Created on Nov 30, 2008                                            */
/* ------------------------------------------------------------------ */
/*                                                                    */
/**********************************************************************/
function Parse_Default_Route()
{
  $url = strtolower( $_SERVER["REQUEST_URI"] );
  $url = trim($url, '/');

  $Parts  = explode( "/", $url );
  $result["module"] = $Parts[0];
  $result["page"]   = empty($Parts[1]) ? '' : $Parts[1];

  return $result;
}
?>
