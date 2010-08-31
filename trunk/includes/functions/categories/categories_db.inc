<?php
/**************************************************************************************************/
/* Created on Dec 3, 2008                                                                         */
/**************************************************************************************************/
function FindSubCategories($cat)
{
  $categories[] = (int)$cat;
  $i = 0;
  while(!empty($categories[$i]))
  {
    $c     = P_SQL_Quote_NumberOnly($categories[$i]);
    $query = 'SELECT categories_id FROM ' . TBL_CAT . ' WHERE parent_id=' . $c;
    $List  = P_MySQL_Real_SELECT_GetArray($query);

    foreach( $List as $cat_id )
    {
      if(!empty($cat_id[0])) $categories[] = $cat_id[0];
    }
    $i++;
  }
  return $categories;
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
function GetFirstCategoryId()
{
  $SQL  = "SELECT id FROM " . TABLE_CATEGORIES . " ";
  $SQL .= "WHERE delete_flg='0' ";
  $SQL .= "ORDER BY sort_order ASC ";
  $SQL .= "LIMIT 0,1";

  $Result = P_MySQL_Real_SELECT( $SQL ) ;

  if( empty ( $Result ) == FALSE )
  {
    return $Result[0] ;
  }
  return 0 ;
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
function Category_Name( $category_id )
{
  if( empty( $category_id ) )
  {
    return "";
  }

  $category_id = P_SQL_Quote_NumberOnly( $category_id );

  $SQL  = "SELECT categories_name FROM " . TBL_CAT_DES . " ";
  $SQL .= "WHERE categories_id=" . $category_id . " ";
  $SQL .= "LIMIT 1";

  $Result = P_MySQL_Real_SELECT( $SQL ) ;

  if( empty ( $Result ) == FALSE )
  {
    return $Result[0] ;
  }
  return "";
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
function List_CategoryId( )
{
  $SQL  = "SELECT id FROM " . TABLE_CATEGORIES . " ";
  $SQL .= "WHERE delete_flg='0' ";
  $SQL .= "ORDER BY sort_order ASC ";

  $List = P_MySQL_Real_SELECT_GetArray( $SQL );

  if( empty( $List[0] ) == FALSE )
  {
    $Result = array();
    foreach( $List as $cat_id )
    {
      $Result[] = $cat_id[0];
    }

    return $Result;
  }

  return NULL;
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
function List_Category($parent='0')
{
  $parent = P_SQL_Quote_NumberOnly($parent);

  $SQL  = "SELECT c.categories_id,cd.categories_name,c.icon,c.parent_id FROM " . TBL_CAT . ' c';
  $SQL .= " INNER JOIN " . TBL_CAT_DES . ' cd ON(cd.categories_id=c.categories_id)';
  $SQL .= " WHERE parent_id=" . $parent;
  $SQL .= " ORDER BY sort_order ASC ";
//e($SQL);
  $List = P_MySQL_Real_SELECT_GetArrayIndex( $SQL );

  if( empty( $List[0] ) == FALSE )
  {
    return $List;
  }

  return array();
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
function Find_Parent_Category($cat_id='0')
{
  $cat_id = P_SQL_Quote_NumberOnly($cat_id);

  $SQL  = 'SELECT pc.categories_id,cd.categories_name,pc.icon,pc.parent_id FROM ' . TBL_CAT . ' c';
  $SQL .= ' LEFT JOIN ' . TBL_CAT . ' pc ON(c.parent_id=pc.categories_id)';
  $SQL .= ' LEFT JOIN ' . TBL_CAT_DES . ' cd ON(cd.categories_id=pc.categories_id)';
  $SQL .= ' WHERE c.categories_id=' . $cat_id;
  $SQL .= ' LIMIT 1';

  $List = P_MySQL_Real_SELECT_GetArrayIndex( $SQL );

  if( empty( $List[0] ) == FALSE )
  {
    return $List[0];
  }

  return NULL;
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
function Find_Category_By_ID($cat_id)
{
  $cat_id = P_SQL_Quote_NumberOnly($cat_id);

  $SQL  = "SELECT c.categories_id,cd.categories_name,c.icon,c.parent_id FROM " . TBL_CAT . ' c';
  $SQL .= " INNER JOIN " . TBL_CAT_DES . ' cd ON(cd.categories_id=c.categories_id)';
  $SQL .= " WHERE c.categories_id=" . $cat_id;
  $SQL .= " ORDER BY sort_order ASC LIMIT 1";

  $List = P_MySQL_Real_SELECT_GetArrayIndex( $SQL );

  if( empty( $List[0] ) == FALSE )
  {
    return $List[0];
  }

  return NULL;
}
// ---------------------------------------------------------------------------------------------- //
// Find category which product belongs to
// ---------------------------------------------------------------------------------------------- //
function Find_CategoryID_Of_Product($product_id)
{
  $product_id = P_SQL_Quote_NumberOnly($product_id);

  $SQL  = "SELECT c.categories_id FROM " . TBL_CAT . ' c';
  $SQL .= " INNER JOIN " . TBL_PRO2CAT . ' pc USING (categories_id)';
  $SQL .= " WHERE pc.products_id=" . $product_id . " LIMIT 1";

  $List = P_MySQL_Real_SELECT_GetArray( $SQL );

  if( empty( $List[0] ) == FALSE )
  {
    return $List[0][0];
  }

  return 0;
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
function List_All_Category()
{
  $SQL  = "SELECT c.categories_id,cd.categories_name,c.icon,c.parent_id FROM " . TBL_CAT . ' c';
  $SQL .= " INNER JOIN " . TBL_CAT_DES . ' cd USING(categories_id)';
  $SQL .= " ORDER BY sort_order ASC";
//e($SQL);
  return P_MySQL_Real_SELECT_GetArrayIndex( $SQL );
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
?>
