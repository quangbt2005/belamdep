<?php
/**************************************************************************************************/
/* Created on June 02, 2010                                                                       */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "news/news_db.inc" );
// ---------------------------------------------------------------------------------------------- //
$current_news_id = $Request['parameters'][':id'];
$current_news    = Load1News($current_news_id);
$older_news      = LoadOlderNews($current_news_id, 5);
$most_new_news   = LoadMostNewNews();

if(!empty($current_news)) $has_news = 'true';
// ---------------------------------------------------------------------------------------------- //
$smarty->assign( "current_news_id", $current_news_id );
$smarty->assign( "current_news", $current_news );
$smarty->assign( "OlderNews", $older_news );
$smarty->assign( "NewNews", $most_new_news );
$smarty->assign( "older_count", count($older_news) );
$smarty->assign( "new_news_count", count($most_new_news) );
$smarty->assign( "has_news", $has_news );
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
$center_col = $smarty->fetch( "news/news_detail.tpl" );
?>