<?php
/**************************************************************************************************/
/* Created on Nov 30, 2008                                                                        */
/**************************************************************************************************/
/**************************************************************************************************/
/*  Function Name :  Validatize_Current_Page                                                      */
/*------------------------------------------------------------------------------------------------*/
/*  Function      :  Make current-page value right                                                */
/*------------------------------------------------------------------------------------------------*/
/*  Parameters    :                                                                               */
/*------------------------------------------------------------------------------------------------*/
/*  Return value  :  Int                                                                          */
/*------------------------------------------------------------------------------------------------*/
/*  Warning       :                                                                               */
/*------------------------------------------------------------------------------------------------*/
/*  Copyright     :                                                                               */
/*------------------------------------------------------------------------------------------------*/
/*  M001          :  Create New  2008/09/17 quangtm                                               */
/**************************************************************************************************/
function Validatize_Current_Page( $current_page, $total_page )
{
    if( isset( $current_page ) == FALSE ) return 1;
    if( isset( $total_page ) == FALSE ) return 1;
    if( Positive_Int_Check( $current_page ) == FALSE ) return 1;
    if( Positive_Int_Check( $total_page ) == FALSE ) return 1;
    $current_page = $current_page + 0;
    $total_page = $total_page + 0;

    if( $current_page <= 0 ) return 1;
    if( $current_page > $total_page ) return $total_page;
    return $current_page;
}
/**************************************************************************************************/
/*  Function Name :  Compute_Total_Page                                                           */
/*------------------------------------------------------------------------------------------------*/
/*  Function      :  Compute total page depend on total record and                                */
/*                   page size                                                                    */
/*------------------------------------------------------------------------------------------------*/
/*  Parameters    :                                                                               */
/*------------------------------------------------------------------------------------------------*/
/*  Return value  :  Total page (int)                                                             */
/*------------------------------------------------------------------------------------------------*/
/*  Warning       :                                                                               */
/*------------------------------------------------------------------------------------------------*/
/*  Copyright     :                                                                               */
/*------------------------------------------------------------------------------------------------*/
/*  M001          :  Create New  2008/09/17 quangtm                                               */
/**************************************************************************************************/
function Compute_Total_Page( $total_count, $limit=10 )
{
  if( isset( $total_count ) == FALSE ) return 0;
  if( Positive_Int_Check( $total_count ) == FALSE ) return 0;
  if( Positive_Int_Check( $limit ) == FALSE ) return 0;
  if( $limit == "0" ) return 0;

  $total_page = (int)($total_count / $limit);

  $remain = $total_count % $limit;
  if( $remain > 0 ) $total_page += 1;


  return $total_page;
}
/**************************************************************************************************/
/*  Function Name :  Common_Paging                                                                */
/*------------------------------------------------------------------------------------------------*/
/*  Function      :  Generate pager                                                               */
/*------------------------------------------------------------------------------------------------*/
/*  Parameters    :                                                                               */
/*------------------------------------------------------------------------------------------------*/
/*  Return value  :  Total page (int)                                                             */
/*------------------------------------------------------------------------------------------------*/
/*  Warning       :                                                                               */
/*------------------------------------------------------------------------------------------------*/
/*  Copyright     :                                                                               */
/*------------------------------------------------------------------------------------------------*/
/*  M001          :  Create New  2008/09/17 quangtm                                               */
/**************************************************************************************************/
function Paginate( $PageInfo )
{
  if( isset( $PageInfo ) == FALSE || is_array( $PageInfo ) == FALSE )
  {
    return "";
  }
  /* --------------------------------------------------------------- */
  /* Set default value for parameters                                */
  /* --------------------------------------------------------------- */
  global $Request;
  $url          = "";
  $limit        = DEFAULT_PAGER_LIMIT;
  $prev_scale   = DEFAULT_PAGER_PREV_SCALE;
  $next_scale   = DEFAULT_PAGER_NEXT_SCALE;
  $current_page = 1;
  $total_page   = 1;
  $pager_class  = DEFAULT_PAGER_CSS_CLASS;
  $align        = DEFAULT_PAGER_ALIGN;
  $current_page_class = DEFAULT_PAGER_CURRENT_CSS_CLASS;
  $page_param_name    = DEFAULT_PAGER_PARAM_NAME;

  $module       = $Request["fact_module"];
  $page         = $Request["fact_page"];
  /* --------------------------------------------------------------- */
  /* Replace default value if parameters were passed                 */
  /* --------------------------------------------------------------- */
  if( isset( $PageInfo["URL"] ) == TRUE )
  {
    $url = $PageInfo["URL"];
  }
  if( isset( $PageInfo["TOTAL_PAGE"] ) == TRUE &&
      Positive_Int_Check( $PageInfo["TOTAL_PAGE"] ) == TRUE )
  {
    $total_page = $PageInfo["TOTAL_PAGE"];
  }
  if( isset( $PageInfo["LIMIT"] ) == TRUE &&
      Positive_Int_Check( $PageInfo["LIMIT"] ) == TRUE )
  {
    $limit = $PageInfo["LIMIT"];
  }
  if( isset( $PageInfo["PREV_SCALE"] ) == TRUE &&
      Positive_Int_Check( $PageInfo["PREV_SCALE"] ) == TRUE )
  {
    $prev_scale = $PageInfo["PREV_SCALE"];
  }
  if( isset( $PageInfo["NEXT_SCALE"] ) == TRUE &&
      Positive_Int_Check( $PageInfo["NEXT_SCALE"] ) == TRUE )
  {
    $next_scale = $PageInfo["NEXT_SCALE"];
  }
  if( isset( $PageInfo["CURRENT_PAGE"] ) == TRUE &&
      Positive_Int_Check( $PageInfo["CURRENT_PAGE"] ) == TRUE )
  {
    $current_page = $PageInfo["CURRENT_PAGE"];
  }
  if( isset( $PageInfo["CLASS"] ) == TRUE )
  {
    $pager_class = $PageInfo["CLASS"];
  }
  if( isset( $PageInfo["CURRENT_PAGE_CLASS"] ) == TRUE )
  {
    $current_page_class = $PageInfo["CURRENT_PAGE_CLASS"];
  }
  if( isset( $PageInfo["ALIGN"] ) == TRUE )
  {
    $align = $PageInfo["ALIGN"];
  }
  if( isset( $PageInfo["PAGE_PARAM_NAME"] ) == TRUE )
  {
    $page_param_name = $PageInfo["PAGE_PARAM_NAME"];
  }
  /* --------------------------------------------------------------- */
  /* Make the current-page correct                                   */
  /* --------------------------------------------------------------- */
  $current_page = Validatize_Current_Page( $current_page,
                                           $total_page );
  /* --------------------------------------------------------------- */
  /* Init url of first page & last page                              */
  /* --------------------------------------------------------------- */
  $result = array();
  $result[] = "<table class=\"$pager_class\" align=\"$align\" border=\"0\"><tr>";

  $first_page_symbol = "<strong>&laquo;</strong>";
  $last_page_symbol  = "<strong>&raquo;</strong>";
  $first_page_url    = Embed_Current_Page_To_Url($url, array(':page' => 1) );
  $last_page_url     = Embed_Current_Page_To_Url($url, array(':page' => $total_page ));

  $first_page_link  = "<td><a href=\"$first_page_url\">";
  $first_page_link .= "$first_page_symbol</a></td>";

  $last_page_link   = "<td><a href=\"$last_page_url\">";
  $last_page_link  .= "$last_page_symbol</a></td>";
  /* --------------------------------------------------------------- */
  /* Compute start page & end page showing on pager                  */
  /* --------------------------------------------------------------- */
  $start_prev = $current_page - $prev_scale;
  $end_next = $current_page + $next_scale;
  if( $start_prev <= 0 ) $start_prev = 1;
  if( $end_next > $total_page ) $end_next = $total_page;
  /* --------------------------------------------------------------- */
  /* FIRST PAGE URL                                                  */
  /* --------------------------------------------------------------- */
  if( $current_page != 1 )
    $result[] = $first_page_link;
  else
    $result[] = "<td>$first_page_symbol</td>";
  /* --------------------------------------------------------------- */
  /* BETWEENT FIRST PAGE & LAST PAGE                                 */
  /* --------------------------------------------------------------- */
  for( $i=$start_prev;$i<=$end_next;$i++ )
  {
    if( $i != $current_page )
    {
      $tmp = Embed_Current_Page_To_Url( $url, array(':page' => $i ));
      $td = "<td><a href=\"$tmp\">$i</a></td>";
    }
    else
    {
      $td = "<td class=\"$current_page_class\">$i</td>";
    }
    $result[] = $td;
  }
  /* --------------------------------------------------------------- */
  /* LAST PAGE URL                                                   */
  /* --------------------------------------------------------------- */
  if( $current_page != $total_page )
    $result[] = $last_page_link;
  else
    $result[] = "<td>$last_page_symbol</td>";
  /* --------------------------------------------------------------- */
  /*                                                                 */
  /* --------------------------------------------------------------- */
  $result[] = "</tr></table>";
  $result = implode( "", $result );
  return $result;
}
/**************************************************************************************************/
/*  Function Name :  Embed_Current_Page_To_Url                                                    */
/*------------------------------------------------------------------------------------------------*/
/*  Function      :  Generate pager                                                               */
/*------------------------------------------------------------------------------------------------*/
/*  Parameters    :                                                                               */
/*------------------------------------------------------------------------------------------------*/
/*  Return value  :  Total page (int)                                                             */
/*------------------------------------------------------------------------------------------------*/
/*  Warning       :                                                                               */
/*------------------------------------------------------------------------------------------------*/
/*  Copyright     :                                                                               */
/*------------------------------------------------------------------------------------------------*/
/*  M001          :  Create New  2008/09/17 quangtm                                               */
/**************************************************************************************************/
function Embed_Current_Page_To_Url( $route, $params )
{
  if( empty( $route ) )
  {
    return "/";
  }

  $result = $route;
  foreach($params as $key=>$value)
  {
    $result = str_replace($key, $value, $result);
  }

  return $result;
}
?>
