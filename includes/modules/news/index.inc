<?php
/**************************************************************************************************/
/* Created on June 02, 2010                                                                       */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "news/news_db.inc" );
// ---------------------------------------------------------------------------------------------- //
$news_cat = ListNewsCategories();
$index = 0;
foreach($news_cat as $cat)
{
	$Items[$index]['cat'] = $cat;
  $top_news = LoadNews($cat['news_categories_id']);
  // -------------------------------------------------------------------------------------------- //
  $first_top_summary = strip_tags(substr($top_news[0]['news_content'],0, 1000),"<b><font><u><i>");
  //bao dam summary du 300 ky tu
  if (strlen($first_top_summary) < 500)
  {
    $news_content_summary = strip_tags(substr($news[0]['news_content'],0, 1500),"<b><font><u><i>");
  }
  //cut to fix 200 character
  $first_top_summary = substr($first_top_summary, 0, 500);
  //
  $pos = strrpos($first_top_summary, " ");
  $first_top_summary = substr($first_top_summary, 0, $pos);
  // -------------------------------------------------------------------------------------------- //
  $Items[$index]['top_news'] = $top_news;
  $Items[$index]['summary']  = $first_top_summary;
  $index++;
}
//pd($Items);
// ---------------------------------------------------------------------------------------------- //
$smarty->assign( "Items", $Items );
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
$center_col = $smarty->fetch( "news/index.tpl" );
?>
