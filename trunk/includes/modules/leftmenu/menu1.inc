<?php
/**************************************************************************************************/
/* Created on Dec 14, 2008                                                                        */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "categories/categories_db.inc" );
require_once( FUNCTIONS_PATH . "products/products_db.inc" );

// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
function SetDisplayLevel(&$cats, $level=0){
	for($i=0;$i<count($cats);$i++){
  	$cats[$i]['level'] = $level;
  }
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
function ReverseDisplayLevel(&$cats, $maxlevel=0){
  for($i=0;$i<count($cats);$i++){
    $cats[$i]['level'] = (int)$maxlevel - (int)$cats[$i]['level'];
  }
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
$current_cat_id = $Request["parameters"][':catid'];
if(empty($current_cat_id)){
	$product_id     = $Request["parameters"][':productid'];
  if(!empty($product_id)){
    $current_cat_id = Find_CategoryID_Of_Product($product_id);
  }
}
$current_cat    = NULL;

if(Positive_Int_Check($current_cat_id))
{
  $current_cat  = Find_Category_By_ID($current_cat_id);
  $level = 0;

  if( !empty( $current_cat ) )
  {
    $Hierarchy = List_Category($current_cat['parent_id']);

    // ------------------------------------------------------------------------------------------ //
    // Find child categories
    // ------------------------------------------------------------------------------------------ //
    $childs = List_Category($current_cat['categories_id']);
    if(count($childs > 0)) {
      SetDisplayLevel($childs, $level++);
      SetDisplayLevel($Hierarchy, $level++);
      for($i=0;$i<count($Hierarchy);$i++) {
        if((int)$current_cat_id == (int)$Hierarchy[$i]['categories_id']) {
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
        $parent  = Find_Parent_Category($cat['categories_id']);
        if(!empty($parent)) {
          $parentFriends = List_Category($parent['parent_id']);
          SetDisplayLevel($parentFriends, $level++);
          for($i=0;$i<count($parentFriends);$i++) {
            if((int)$parent['categories_id'] == (int)$parentFriends[$i]['categories_id']) {
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
    $Categories = $Hierarchy;
  }
}

if(empty($Categories))
{
	$Categories = List_Category();
  for($i=0;$i<count($Categories);$i++)
  {
    $Categories[$i]['level'] = 0;
  }
}

$Best_Seller = LoadBestSellerProducts();

$smarty->assign( "current_cat", $current_cat_id );
$smarty->assign( "Categories", $Categories );
$smarty->assign( "best_seller", $Best_Seller );
$left_col = $smarty->fetch( "leftmenu/menu1.tpl" );
?>
