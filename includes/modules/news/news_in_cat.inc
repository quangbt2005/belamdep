<?php
/**************************************************************************************************/
/* Created on June 02, 2010                                                                       */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "news/news_db.inc" );
// ---------------------------------------------------------------------------------------------- //
$current_cat = $Request['parameters'][':catid'];

$child_cat   = ListNewsCategories($current_cat);
$news_in_cat = LoadNews($current_cat, 0, 15);
$older_news  = LoadOlderNews($news_in_cat[sizeof($news_in_cat)-1]['news_id']);

foreach($news_in_cat as $news)
{
  // -------------------------------------------------------------------------------------------- //
  $summary = strip_tags(substr($news['news_content'],0, 1000),"<b><font><u><i>");
  //bao dam summary du 300 ky tu
  if (strlen($summary) < 500)
  {
      $summary = strip_tags(substr($news['news_content'],0, 1500),"<b><font><u><i>");
  }
  //cut to fix 200 character
  $summary = substr($summary, 0, 500);
  //
  $pos = strrpos($summary, " ");
  $summary = substr($summary, 0, $pos);
  // -------------------------------------------------------------------------------------------- //
  $news['summary'] = $summary;
  $Items[] = $news;
}

// ---------------------------------------------------------------------------------------------- //
$smarty->assign( "current_cat", $current_cat );
$smarty->assign( "ChildCats", $child_cat );
$smarty->assign( "Items", $Items );
$smarty->assign( "OlderNews", $older_news );
$smarty->assign( "child_count", count($child_cat) );
$smarty->assign( "older_count", count($older_news) );
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
$center_col = $smarty->fetch( "news/news_in_cat.tpl" );
?>
