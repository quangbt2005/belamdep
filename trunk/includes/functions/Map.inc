<?php
/**************************************************************************************************/
/* Created on Nov 30, 2008                                                                        */
/**************************************************************************************************/
function Request2Action( $Request, &$Response )
{
  global $Module_Map, $Left_Menu_Map, $Right_Menu_Map, $Header_Map, $Footer_Map, $Title_Map;

  if( empty( $Module_Map ) )
  {
    die( "Map not found. Check config file" );
  }

  $module = "";
  $page   = "";

  if( empty( $Request['module'] ) )
  {
    $module              = DEFAULT_MODULE;
    $page                = DEFAULT_PAGE;
    $Response["error"][] = 'Split module failed';
  }
  else
  {
    $module_not_found = !array_key_exists( $Request['module'], $Module_Map );
    $page_not_found   = !array_key_exists( $Request['page'], $Module_Map[$Request['module']] );

    if( $module_not_found || $page_not_found )
    {
      $module              = DEFAULT_MODULE;
      $page                = DEFAULT_PAGE;
      $Response["error"][] = 'Module or Page not found';
    }
    else
    {
      $module = $Request['module'];
      $page   = $Request['page'];
    }
  }

  $Response["response_module"] = $module;
  $Response["response_page"]   = $page;
  $Response["header_script"]   = empty($Header_Map[$module]) ? '' : $Header_Map[$module];
  $Response["left_script"]     = empty($Left_Menu_Map[$module]) ? '' : $Left_Menu_Map[$module];
  $Response["center_script"]   = empty($Module_Map[$module][$page]) ? '' : $Module_Map[$module][$page];
  $Response["right_script"]    = empty($Right_Menu_Map[$module]) ? '' : $Right_Menu_Map[$module];
  $Response["footer_script"]   = empty($Footer_Map[$module]) ? '' : $Footer_Map[$module];
  $Response["page_title"]      = empty($Title_Map[$module]) ? '' : $Title_Map[$module];

  if( empty( $Response["left_script"] ) )
  {
    $Response["left_script"]  = $Left_Menu_Map["default"];
    $Response["error"][]      = 'Left not found';
  }
  if( empty( $Response["right_script"] ) )
  {
    $Response["right_script"]  = $Right_Menu_Map["default"];
    $Response["error"][]       = 'Right not found';
  }
  if( empty( $Response["header_script"] ) )
  {
    $Response["header_script"]  = $Header_Map["default"];
    $Response["error"][]       = 'Header not found';
  }
  if( empty( $Response["footer_script"] ) )
  {
    $Response["footer_script"]  = $Footer_Map["default"];
    $Response["error"][]       = 'Footer not found';
  }
  if( empty( $Response["page_title"] ) )
  {
    $Response["page_title"]    = $Title_Map["default"];
    $Response["error"][]       = 'Title not found';
  }
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
function DefineAjaxRequest(&$Request)
{
  global $Ajax_Map;
  $Request['is_ajax'] = FALSE;
  if(in_array($Request['response_page'], $Ajax_Map[$Request['response_module']]))
  {
    $Request['is_ajax'] = TRUE;
  }
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
function Layout( $module )
{
  global $Layout_Map;

  if( is_array( $Layout_Map ) && empty( $Layout_Map ) == FALSE )
  {
    if( array_key_exists( $module, $Layout_Map ) )
    {
      return $Layout_Map[$module];
    }
  }

  return DEFAULT_LAYOUT;
}
?>
