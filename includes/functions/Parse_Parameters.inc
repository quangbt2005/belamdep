<?php
/**************************************************************************************************/
/* Created on Nov 30, 2008                                                                        */
/* ---------------------------------------------------------------------------------------------- */
/* Parse necessary parameters for page                                                            */
/**************************************************************************************************/
function Parse_Parameters( &$Request )
{
  $Result = array();

  // if( !empty( $Request['request_module'] ) && !empty( $Request['request_page'] ) )
  {
      $param_name = trim($Request["route"], '/');
      $param_name = explode('/', $param_name);

      $url = strtolower( $_SERVER["REQUEST_URI"] );
      $url = trim($url, '/');

      $param_value = explode('/', $url);
      if(is_array($param_name) && is_array($param_value))
      {
        if(count($param_name)!=count($param_value))
        {
        	$param_value = array_pad($param_value, count($param_name), 0);
        }
        $combine = array_combine($param_name, $param_value);
      }
      else $combine = array();

      foreach($combine as $key => $value)
      {
        if($key[0] == ':')
        {
          $Result[$key] = $value;
        }
      }
  }

  $Request["parameters"] = $Result;
}
?>
