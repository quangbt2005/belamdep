<?php
/**********************************************************************/
/* Created on Nov 29, 2008                                            */
/**********************************************************************/
require_once( FUNCTIONS_PATH . "Parse_Defined_Route.inc" );
require_once( FUNCTIONS_PATH . "Parse_Default_Route.inc" );
require_once( FUNCTIONS_PATH . "Parse_Parameters.inc" );

function Parse__URL()
{
  $Module = Parse_Defined_Route();
  if($Module == false)
  {
    $Module = Parse_Default_Route();
    $Result["defined_route"] = false;
    $Result["route"]         = "/module/page/:id";
  }
  else
  {
    $Result["defined_route"] = true;
    $Result["route"]         = $Module["route"];
  }

  $Result["request_module"] = $Module['module'];
  $Result["request_page"]   = $Module['page'];

  Request2Action($Module, $Result);
  Parse_Parameters( $Result );
  DefineAjaxRequest( $Result );

  return $Result;
}
?>
