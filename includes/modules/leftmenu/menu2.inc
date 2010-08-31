<?php
/**************************************************************************************************/
/* Created on Dec 14, 2008                                                                        */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "categories/categories_db.inc" );
require_once( FUNCTIONS_PATH . "products/products_db.inc" );
require_once( FUNCTIONS_PATH . "news/news_db.inc" );

// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
function SetDisplayLevel(&$cats, $level=0)
{
  for($i=0;$i<count($cats);$i++)
  {
    $cats[$i]['level'] = $level;
  }
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
function ReverseDisplayLevel(&$cats, $maxlevel=0)
{
  for($i=0;$i<count($cats);$i++)
  {
    $cats[$i]['level'] = (int)$maxlevel - (int)$cats[$i]['level'];
  }
}
// ---------------------------------------------------------------------------------------------- //
// Product categories menu
// ---------------------------------------------------------------------------------------------- //
$Categories = List_Category();
for($i=0;$i<count($Categories);$i++)
{
  $Categories[$i]['level'] = 0;
}
// ---------------------------------------------------------------------------------------------- //
// Best seller
// ---------------------------------------------------------------------------------------------- //
$Best_Seller = LoadBestSellerProducts();
// ---------------------------------------------------------------------------------------------- //
// News categories menu
// ---------------------------------------------------------------------------------------------- //
$current_news_cat_id = NULL;
$current_cat         = NULL;

if(isset($Request["parameters"][':catid']))
  $current_news_cat_id = $Request["parameters"][':catid'];
elseif(isset($Request["parameters"][':id'])){
	$current_news_id = $Request["parameters"][':id'];
  $current_news_cat_id = FindCategoryIDOfNews($current_news_id);
}

if(Positive_Int_Check($current_news_cat_id))
{
  $current_cat  = FindNewsCategoryByID($current_news_cat_id);
  $level = 0;

  if( !empty( $current_cat ) )
  {
    $Hierarchy = ListNewsCategories($current_cat['parent_id']);

    // ------------------------------------------------------------------------------------------ //
    // Find child categories
    // ------------------------------------------------------------------------------------------ //
    $childs = ListNewsCategories($current_cat['news_categories_id']);
    if(count($childs > 0)) {
      SetDisplayLevel($childs, $level++);
      SetDisplayLevel($Hierarchy, $level++);
      for($i=0;$i<count($Hierarchy);$i++) {
        if((int)$current_news_cat_id == (int)$Hierarchy[$i]['news_categories_id']) {
          $arr1 = array_splice($Hierarchy, 0, $i+1);
          $Hierarchy = array_merge($arr1, $childs, $Hierarchy);
        }
      }
    }
    else SetDisplayLevel($Hierarchy, $level++);

    // ------------------------------------------------------------------------------------------ //
    // Find parent categories
    // ------------------------------------------------------------------------------------------ //
    if((int)$current_cat['parent_id']!=0) {
      $cat       = $current_cat;
      do {
        $parent  = FindNewsCategoryByID($cat['parent_id']);
        if(!empty($parent)) {
          $parentFriends = ListNewsCategories($parent['parent_id']);
          SetDisplayLevel($parentFriends, $level++);
          for($i=0;$i<count($parentFriends);$i++) {
            if((int)$parent['news_categories_id']==(int)$parentFriends[$i]['news_categories_id']){
              $arr1 = array_splice($parentFriends, 0, $i+1);
              $Hierarchy = array_merge($arr1, $Hierarchy, $parentFriends);
            }
          }
          $cat = $parent;
        }
      } while((int)$cat['parent_id'] != 0);
    }
    // ------------------------------------------------------------------------------------------ //
    //
    // ------------------------------------------------------------------------------------------ //
    ReverseDisplayLevel($Hierarchy, $level-1);
    $NewsCategories = $Hierarchy;
  }
}

if(empty($NewsCategories))
{
  $NewsCategories = ListNewsCategories();
  for($i=0;$i<count($NewsCategories);$i++)
  {
    $NewsCategories[$i]['level'] = 0;
  }
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
$smarty->assign( "current_news_cat", $current_news_cat_id );
$smarty->assign( "Categories", $Categories );
$smarty->assign( "NewsCategories", $NewsCategories );
$smarty->assign( "best_seller", $Best_Seller );
$left_col = $smarty->fetch( "leftmenu/menu2.tpl" );
?>
