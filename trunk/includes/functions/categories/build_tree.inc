<?php
/**************************************************************************************************/
/* Created on July 2, 2010                                                                        */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "categories/categories_db.inc" );
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
function BuildCategoryTree()
{
  $overflow = false;

  $Tree = array();
  $List = List_All_Category();

  while(count($List)>0 && $overflow<150){
    foreach($List as $key => $value){
      if($value['parent_id']==0){
      	$Tree[$value['categories_id']] = $value;
        unset($List[$key]);
      } else {
      	$found = ArrangeSubCat($Tree, $value);
        if($found){
          unset($List[$key]);
        }
      }
    }
    $overflow++;
  }

  return $Tree;
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
function ArrangeSubCat(&$Tree, $cat)
{
  $__queue = array(&$Tree);
  $pointer = 0;
  while($pointer < count($__queue)){
    $root = &$__queue[$pointer];
    reset($root);
    while(list($key,$value)=each($root)){
      if((int)$key==(int)$cat['parent_id']){
        $root[$key]['childs'][$cat['categories_id']] = $cat;
        return true;
      }
      if(isset($value['childs'])){
        $__queue[] = &$value['childs'];
      }
    }
    $pointer++;
  }

  return false;
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
?>
