<?php
/**********************************************************************/
/* Created on Dec 7, 2008                                             */
/**********************************************************************/
$smarty->assign( 'WEB_ROOT', WEB_ROOT );
$smarty->assign( 'IMAGES_PATH', IMAGES_PATH );
$smarty->assign( 'IMAGES_LANG_PATH', IMAGES_LANG_PATH );
$smarty->assign( 'LANGUAGE', LANGUAGE );
$smarty->assign( 'PART_ROW', PART_ROW );
$smarty->assign( 'PART_ROW_ITEM', PART_ROW_ITEM );
$smarty->assign( 'PART_ITEM_LIMIT', PART_ITEM_LIMIT );
$smarty->assign( 'SMALL_IMAGE_HEIGHT', SMALL_IMAGE_HEIGHT );
$smarty->assign( 'HEADING_NEWS_IMAGE_WIDTH', HEADING_NEWS_IMAGE_WIDTH );

$smarty->register_function('number_format', 'smarty_number_format');
$smarty->register_function('CategoryName',  'smarty_category_name');
$smarty->register_function('ImageThumb',    'smarty_image_thumb');
$smarty->register_function('ImageButton',   'smarty_image_button');
$smarty->register_function('TitleBox',      'smarty_title_box');
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
function smarty_number_format( $param )
{
  return number_format( $param["number"], 0, '.', ',' );
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
function smarty_category_name( $param )
{
  // -------------------------------------------------------------------------------------------- //
  // in categories_db.inc
  // -------------------------------------------------------------------------------------------- //
  return Category_Name( $param["category_id"] );
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
function smarty_image_thumb($params)
{
  $image = image_thumb($params['src'], $params['alt'], $params['width'],
                       $params['height'], $params['options'], $params['ma']);

  return $image;
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
function smarty_image_button($params)
{
  $image = image_button($params['image'], $params['alt'], $params['options']);
  return $image;
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
function smarty_title_box($params)
{
  $innerHtml = '';
  if(!empty($params['href'])) $innerHtml = '<a href="' . $params['href'] . '" '
                                           . $params['hrefoptions'] . '>';
  $innerHtml .= $params['title'];
  if(!empty($params['href'])) $innerHtml .= '</a>';

  $result = '<table width="100%" cellpadding="0" cellspacing="0" border="0"><tr>' .
            '<td class="title-corner-left">&nbsp;</td>' .
            '<td class="title-center">' . $innerHtml . '</td>' .
            '<td class="title-corner-right">&nbsp;</td></tr></table>';
  return $result;
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
function ClearAllSmartyAssign()
{
  global $smarty;

  $smarty->clear_all_assign();

  $smarty->assign( "WEB_ROOT", WEB_ROOT );
  $smarty->assign( "IMAGES_PATH", IMAGES_PATH );
  $smarty->assign( "PART_ROW", PART_ROW );
  $smarty->assign( "PART_ROW_ITEM", PART_ROW_ITEM );
  $smarty->assign( "PART_ITEM_LIMIT", PART_ITEM_LIMIT );
}
?>
