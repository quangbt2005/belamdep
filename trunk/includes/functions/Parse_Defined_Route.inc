<?php
/*
 * Created on May 14, 2010
 *
 * To change the template for this generated file go to
 * Window - Preferences - PHPeclipse - PHP - Code Templates
 */
function Parse_Defined_Route()
{
  global $Routes;

  $query_string = '?' . $_SERVER['QUERY_STRING'];
  $url = trim(strtolower( $_SERVER["REQUEST_URI"] ), '/');
  if($_SERVER['QUERY_STRING'] != ''){
  	$url = str_replace($query_string,'',$url);
  }
  $url_parts = explode('/', $url);

  foreach($Routes as $key => $value){
    $route = trim($key, '/');
    $route_parts = explode('/', $route);
    if(count($url_parts) != count($route_parts)) continue;

    for($i=0;$i<count($url_parts);$i++){
      if($route_parts[$i][0] != ':'){
        if($route_parts[$i] != $url_parts[$i]) break;
      }
    }

    if($i == count($url_parts)){
      $result["module"] = $value['module'];
      $result["page"]   = $value['page'];
      $result["route"]  = $key;
      return $result;
    }
  }

  return false;
}
?>
