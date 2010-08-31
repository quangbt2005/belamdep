<?php
/**************************************************************************************************/
/* Created on June 02, 2010                                                                       */
/**************************************************************************************************/
function ListNewsCategories($parent_id=0)
{
  $parent_id = P_SQL_Quote_NumberOnly($parent_id);
	$query = 'SELECT news_categories_id, news_categories_name, sort_order, icon FROM ' . TBL_NEWS_CAT
           . " WHERE parent_id='" . $parent_id . "' ORDER BY sort_order, news_categories_name";

  $Result = P_MySQL_Real_SELECT_GetArrayIndex( $query );

  if( empty( $Result[0] ) == FALSE ) {
    return $Result;
  }

  return array();
}
// ---------------------------------------------------------------------------------------------- //
// Load products
// ---------------------------------------------------------------------------------------------- //
function LoadNews($cat_id, $offset=0, $limit=DEFAULT_PAGER_NEWS_LIMIT)
{
  $cat_id = P_SQL_Quote_NumberOnly($cat_id);
	$query = 'SELECT news_id, news_title, news_content, icon, news_categories_path FROM '
           . TBL_NEWS . " WHERE news_status='1' AND news_categories_path like '%\_". $cat_id
           . "\_%' ORDER BY date_added, sort_order LIMIT " . $offset . ',' . $limit;

  $Result = P_MySQL_Real_SELECT_GetArrayIndex( $query );

  if( empty( $Result[0] ) == FALSE ) {
    return $Result;
  }

  return NULL;
}
// ---------------------------------------------------------------------------------------------- //
// Load products
// ---------------------------------------------------------------------------------------------- //
function Load1News($news_id)
{
  $news_id = P_SQL_Quote_NumberOnly($news_id);
  $query = 'SELECT news_id, news_title, news_content, icon, news_categories_path FROM '
           . TBL_NEWS . " WHERE news_status='1' AND news_id='" . $news_id . "'";

  $Result = P_MySQL_Real_SELECT_GetArrayIndex( $query );

  if( empty( $Result[0] ) == FALSE ) {
    return $Result[0];
  }

  return array();
}
// ---------------------------------------------------------------------------------------------- //
// Load products
// ---------------------------------------------------------------------------------------------- //
function LoadOlderNews($cat_id, $limit=10)
{
  $cat_id = P_SQL_Quote_NumberOnly($cat_id);
  $query = "SELECT news_id, news_title, news_categories_path FROM ". TBL_NEWS
           . " WHERE news_id < '" . $cat_id
           . "' ORDER BY date_added DESC, news_title LIMIT 0,".$limit;

  $Result = P_MySQL_Real_SELECT_GetArrayIndex( $query );

  if( empty( $Result[0] ) == FALSE ) {
    return $Result;
  }

  return array();
}
// ---------------------------------------------------------------------------------------------- //
// Load products
// ---------------------------------------------------------------------------------------------- //
function LoadMostNewNews($limit=5)
{
  $cat_id = P_SQL_Quote_NumberOnly($cat_id);
  $query = "SELECT news_id, news_title, news_categories_path FROM ". TBL_NEWS
           . " ORDER BY date_added DESC, news_title LIMIT 0,".$limit;

  $Result = P_MySQL_Real_SELECT_GetArrayIndex( $query );

  if( empty( $Result[0] ) == FALSE ) {
    return $Result;
  }

  return array();
}
// ---------------------------------------------------------------------------------------------- //
// Load products
// ---------------------------------------------------------------------------------------------- //
function FindCategoryIDOfNews($news_id)
{
  $news_id = P_SQL_Quote_NumberOnly($news_id);
  $query = "SELECT news_categories_path FROM ". TBL_NEWS . " WHERE news_id=" . $news_id . " LIMIT 1";

  $tmp = P_MySQL_Real_SELECT_GetArray( $query );

  if( empty( $tmp[0] ) == FALSE ) {
    $result = $tmp[0][0];
    $result = trim($result,'_');
    $result = explode('_', $result);
    return $result[count($result)-1];
  }

  return 0;
}
// ---------------------------------------------------------------------------------------------- //
// Load products
// ---------------------------------------------------------------------------------------------- //
function FindNewsCategoryByID($cat_id)
{
  $cat_id = P_SQL_Quote_NumberOnly($cat_id);
  $query = "SELECT * FROM ". TBL_NEWS_CAT . " WHERE news_categories_id=" . $cat_id . " LIMIT 1";

  $tmp = P_MySQL_Real_SELECT_GetArrayIndex( $query );

  if( empty( $tmp[0] ) == FALSE ) {
    return $tmp[0];
  }

  return NULL;
}
// ---------------------------------------------------------------------------------------------- //
// Load products
// ---------------------------------------------------------------------------------------------- //
function FindParentCategory($cat_id)
{
  $cat_id = P_SQL_Quote_NumberOnly($cat_id);
  $query = "SELECT * FROM ". TBL_NEWS_CAT . " WHERE news_categories_id=" . $cat_id . " LIMIT 1";

  $tmp = P_MySQL_Real_SELECT_GetArrayIndex( $query );

  if( empty( $tmp[0] ) == FALSE ) {
    $result = $tmp[0];
  }

  return NULL;
}
?>