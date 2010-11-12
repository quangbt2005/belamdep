<?php
/**************************************************************************************************/
/* Created on Nov 30, 2008                                                                        */
/**************************************************************************************************/
// ---------------------------------------------------------------------------------------------- //
// Find category which product is belong to
// ---------------------------------------------------------------------------------------------- //
function FindNewProducts($category=0, $offset=0, $limit=9)
{
  global $languages_id;
  if(Positive_Int_Check($category))
  {
    if((int)$category == 0)
    {
      $query = 'SELECT p.products_id,p.products_image,pd.products_name,'
               . 's.specials_new_products_price special_price,p.products_price '
               . 'FROM ' . TBL_PRODUCTS . ' p LEFT JOIN ' . TBL_SALEOFF
               . ' s ON (p.products_id=s.products_id), '
               . TBL_PRO_DES . ' pd WHERE p.products_id=pd.products_id AND'
               . " pd.language_id='" . LANGUAGE_ID . "'"
               . 'ORDER BY p.products_date_added DESC LIMIT ' . $offset . ',' . $limit;
    }
    else
    {
      $query = 'SELECT DISTINCT p.products_id,p.products_image,pd.products_name,'
               . 's.specials_new_products_price special_price,p.products_price '
               . 'FROM ' . TBL_PRODUCTS . ' p LEFT JOIN ' . TBL_SALEOFF
               . ' s ON (p.products_id=s.products_id), '
               . TBL_PRO_DES . ' pd, ' . TBL_PRO2CAT . ' p2c, ' . TBL_CAT
               . ' c WHERE p.products_id=p2c.products_id AND p2c.categories_id=c.categories_id'
               . " AND c.categories_id='" . (int)$category . "'"
               . " AND p.products_id=pd.products_id AND pd.language_id='" . LANGUAGE_ID . "'"
               . ' ORDER BY p.products_date_added DESC LIMIT ' . $offset . ',' . $limit;

    }
    return P_MySQL_Real_SELECT_GetArrayIndex($query);
  }
  return array();
}
// ---------------------------------------------------------------------------------------------- //
// Find category which product is belong to
// ---------------------------------------------------------------------------------------------- //
function FindProductsInSpecialCat($limit=8)
{
  $result = array();

  $query = 'SELECT cat_id FROM ' .  TBL_SPECCAT . ' LIMIT ' . $limit;
  $List  = P_MySQL_Real_SELECT_GetArray($query);

  foreach($List as $cat_id)
  {
    $product_count = Count_Products($cat_id[0]);

    if(!empty($product_count))
    {
      $prod_id_offset = rand(0, $product_count - 1);
      $query  = 'SELECT p.products_id FROM ' . TBL_PRODUCTS . ' p INNER JOIN ' . TBL_PRO2CAT;
      $query .= ' p2c ON(p2c.products_id=p.products_id)';
      $query .= ' WHERE p2c.categories_id=' . $cat_id[0] . ' LIMIT ' . $prod_id_offset . ',1';

      $prod_id_query_result = P_MySQL_Real_SELECT($query);
      $prod_id = $prod_id_query_result[0];

      $query  = 'SELECT p2c.categories_id, p2c.products_id, p.products_image,';
      $query .= 'IF(s.specials_new_products_price,s.specials_new_products_price,p.products_price)';
      $query .= ' AS products_price,des.products_name';
      $query .= ' FROM ' . TBL_PRO2CAT . ' p2c INNER JOIN ' . TBL_PRODUCTS;
      $query .= ' p ON(p2c.products_id=p.products_id) INNER JOIN ' . TBL_PRO_DES;
      $query .= ' des ON(p2c.products_id=des.products_id) LEFT JOIN ' . TBL_SALEOFF;
      $query .= ' s ON(p.products_id=s.products_id)';
      $query .= ' WHERE p2c.products_id=' . $prod_id;
      $query .= ' LIMIT 1';

      $tmp = P_MySQL_Real_SELECT_GetArrayIndex($query);
      $result[] = $tmp[0];
    }
  }

  return $result;
}
// ---------------------------------------------------------------------------------------------- //
// Find category which product is belong to
// ---------------------------------------------------------------------------------------------- //
function Product_To_Category( $product_id )
{
  if( empty( $product_id ) )
  {
    return 0;
  }

  $product_id = P_SQL_Quote_NumberOnly( $product_id );

  $SQL  = "SELECT categories_id FROM " . TBL_PRO2CAT . " pc ";
  $SQL .= "WHERE products_id = " . $product_id;

  //------------------------------------------------------------------//
  // Execute query
  //------------------------------------------------------------------//
  $Result = P_MySQL_Real_SELECT( $SQL ) ;

  if( empty ( $Result ) == FALSE )
  {
    return $Result[0] ;
  }
  return 0 ;
}
// ---------------------------------------------------------------------------------------------- //
// Count products all in category and sub categories
// ---------------------------------------------------------------------------------------------- //
function Count_Products( $category_id )
{
  if( empty( $category_id ) )
  {
    return 0;
  }

  $categories = FindSubCategories( $category_id );

  $categories_string = implode(',', $categories);

  $SQL  = "SELECT COUNT(1) FROM " . TBL_PRODUCTS . " p ";
  $SQL .= "  INNER JOIN " . TBL_PRO2CAT . " pc ";
  $SQL .= "  ON(p.products_id = pc.products_id) ";
  $SQL .= "WHERE pc.categories_id in (" . $categories_string . ")";
  // e($SQL);
  //------------------------------------------------------------------//
  // Execute query
  //------------------------------------------------------------------//
  $Result = P_MySQL_Real_SELECT( $SQL ) ;

  if(!empty($Result[0]))
  {
    return $Result[0] ;
  }
  return 0 ;
}
// ---------------------------------------------------------------------------------------------- //
// Count products by category (not including subcategories of category)
// ---------------------------------------------------------------------------------------------- //
function Count_Products_Exactly( $category_id )
{
  if( empty( $category_id ) )
  {
    return 0;
  }

  $category_id = P_SQL_Quote_NumberOnly( $category_id );

  $SQL  = "SELECT COUNT(1) FROM " . TBL_PRODUCTS . " p ";
  $SQL .= "  INNER JOIN " . TBL_PRO2CAT . " pc ";
  $SQL .= "  ON(p.products_id = pc.products_id) ";
  $SQL .= "  INNER JOIN " . TBL_CAT . " c ";
  $SQL .= "  ON(pc.categories_id=c.categories_id) ";
  $SQL .= "WHERE c.categories_id = " . $category_id;

  //------------------------------------------------------------------//
  // Execute query
  //------------------------------------------------------------------//
  $Result = P_MySQL_Real_SELECT( $SQL ) ;

  if( empty ( $Result ) == FALSE )
  {
    return $Result[0] ;
  }
  return 0 ;
}
// ---------------------------------------------------------------------------------------------- //
// Load all products in category (not including subcategories of category)
// ---------------------------------------------------------------------------------------------- //
function List_Product_By_Category_Exactly( $category_id, $offset=0,
                                           $limit=DEFAULT_PAGER_LIMIT )
{
  if( empty( $category_id ) )
  {
    return array();
  }

  $category_id = P_SQL_Quote_NumberOnly( $category_id );

  $query = 'SELECT DISTINCT p.products_id,p.products_image,pd.products_name,'
               . 's.specials_new_products_price special_price,p.products_price '
               . 'FROM ' . TBL_PRODUCTS . ' p LEFT JOIN ' . TBL_SALEOFF
               . ' s ON (p.products_id=s.products_id), '
               . TBL_PRO_DES . ' pd, ' . TBL_PRO2CAT . ' p2c, ' . TBL_CAT
               . ' c WHERE p.products_id=p2c.products_id AND p2c.categories_id=c.categories_id'
               . ' AND c.categories_id=' . $category_id
               . " AND p.products_id=pd.products_id AND pd.language_id='" . LANGUAGE_ID . "'"
               . ' ORDER BY p.products_date_added DESC LIMIT ' . $offset . ',' . $limit;
// pd($query);
  return P_MySQL_Real_SELECT_GetArrayIndex($query);
}
// ---------------------------------------------------------------------------------------------- //
// Load all products in category and subcategories of category
// ---------------------------------------------------------------------------------------------- //
function List_Product_By_Category( $category_id, $offset=0,
                                   $limit=DEFAULT_PAGER_LIMIT )
{
  if( empty( $category_id ) )
  {
    return array();
  }

  $categories = FindSubCategories( $category_id );

  $categories_string = implode(',', $categories);

  $query = 'SELECT DISTINCT p.products_id,p.products_image,pd.products_name,'
               . 's.specials_new_products_price special_price,p.products_price '
               . 'FROM ' . TBL_PRODUCTS . ' p LEFT JOIN ' . TBL_SALEOFF
               . ' s ON (p.products_id=s.products_id), '
               . TBL_PRO_DES . ' pd, ' . TBL_PRO2CAT . ' p2c, ' . TBL_CAT
               . ' c WHERE p.products_id=p2c.products_id AND p2c.categories_id=c.categories_id'
               . " AND c.categories_id in (" . $categories_string . ")"
               . " AND p.products_id=pd.products_id AND pd.language_id='" . LANGUAGE_ID . "'"
               . ' ORDER BY p.products_date_added DESC LIMIT ' . $offset . ',' . $limit;
  return P_MySQL_Real_SELECT_GetArrayIndex($query);
}
// ---------------------------------------------------------------------------------------------- //
// Load product
// ---------------------------------------------------------------------------------------------- //
function LoadProduct( $product_id )
{
  if( empty( $product_id ) ) {
    return NULL;
  }

  $product_id = P_SQL_Quote_NumberOnly( $product_id );
  $query = 'SELECT DISTINCT p.products_id,p.products_image,pd.products_name,p2c.categories_id,'
           . 's.specials_new_products_price special_price,p.products_price,pd.products_description,'
           . 'p.products_quantity FROM ' . TBL_PRODUCTS . ' p LEFT JOIN ' . TBL_SALEOFF
           . ' s ON (p.products_id=s.products_id) LEFT JOIN ' . TBL_PRO_DES . ' pd ON ('
           . 'p.products_id=pd.products_id AND pd.language_id=' . LANGUAGE_ID . ') LEFT JOIN '
           . TBL_PRO2CAT . ' p2c ON(p.products_id=p2c.products_id) '
           . 'WHERE p.products_id=' . $product_id . ' LIMIT 1';

  $Result = P_MySQL_Real_SELECT_GetArrayIndex( $query );

  if( empty( $Result[0] ) == FALSE ) {
    return $Result[0];
  }

  return NULL;
}
// ---------------------------------------------------------------------------------------------- //
// Load products
// ---------------------------------------------------------------------------------------------- //
function LoadProducts( $product_id_array )
{
  if( empty( $product_id_array ) ) {
    return array();
  }

  for($i=0;$i<count($product_id_array);$i++) {
    $product_id_array[$i] = P_SQL_Quote_NumberOnly($product_id_array[$i]);
  }
  $id_string = implode(',', $product_id_array);

  $query = 'SELECT DISTINCT p.products_id,p.products_image,pd.products_name,'
           . 's.specials_new_products_price special_price,p.products_price '
           . 'FROM ' . TBL_PRODUCTS . ' p LEFT JOIN ' . TBL_SALEOFF
           . ' s ON (p.products_id=s.products_id), '
           . TBL_PRO_DES . ' pd, ' . TBL_PRO2CAT . ' p2c, ' . TBL_CAT
           . ' c WHERE p.products_id=p2c.products_id AND p2c.categories_id=c.categories_id'
           . " AND p.products_id in (" . $id_string . ")"
           . " AND p.products_id=pd.products_id AND pd.language_id='" . LANGUAGE_ID . "'"
           . ' ORDER BY pd.products_name LIMIT ' . count($product_id_array);

  $Result = P_MySQL_Real_SELECT_GetArrayIndex( $query );

  if( empty( $Result[0] ) == FALSE ) {
    return $Result;
  }

  return array();
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
function LoadRandom1SaleOffProducts()
{
  $query = 'SELECT COUNT(1) FROM ' . TBL_SALEOFF;
  $saleoff_count = P_MySQL_Real_SELECT( $query ) ;
  $saleoff_count = $saleoff_count[0];

  $query = 'SELECT DISTINCT p.products_id,p.products_image,pd.products_name,'
           . 's.specials_new_products_price special_price,p.products_price '
           . 'FROM ' . TBL_PRODUCTS . ' p INNER JOIN ' . TBL_SALEOFF
           . ' s ON (p.products_id=s.products_id), '
           . TBL_PRO_DES . ' pd'
           . ' WHERE p.products_id=pd.products_id AND pd.language_id=' . LANGUAGE_ID
           . ' LIMIT ' . rand(0,$saleoff_count-1) . ',1';
  $Result = P_MySQL_Real_SELECT_GetArrayIndex( $query );

  if( empty( $Result[0] ) == FALSE ) {
    return $Result[0];
  }
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
function CountSaleOffProducts()
{
  $query = 'SELECT COUNT(1) FROM ' . TBL_SALEOFF;
  $saleoff_count = P_MySQL_Real_SELECT( $query ) ;
  $saleoff_count = $saleoff_count[0];

  return $saleoff_count;
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
function LoadSaleOffProducts( $offset=0, $limit=DEFAULT_PAGER_LIMIT )
{
  $query = 'SELECT DISTINCT p.products_id,p.products_image,pd.products_name,'
           . 's.specials_new_products_price special_price,p.products_price '
           . 'FROM ' . TBL_PRODUCTS . ' p INNER JOIN ' . TBL_SALEOFF
           . ' s ON (p.products_id=s.products_id), '
           . TBL_PRO_DES . ' pd'
           . ' WHERE p.products_id=pd.products_id AND pd.language_id=' . LANGUAGE_ID
           . ' LIMIT ' . $offset . ',' . $limit;

  $Result = P_MySQL_Real_SELECT_GetArrayIndex( $query );

  if( empty( $Result[0] ) == FALSE ) {
    return $Result;
  }

  return array();
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
function CountSearchResult( $keyword_arr )
{
  if(empty($keyword_arr)) return 0;

  $condition = array();
  foreach($keyword_arr as $keyword)
  {
    $keyword = trim($keyword);
    $keyword = P_SQL_Quote_Like($keyword);
    if(strlen($keyword) > 0)
    {
      $condition[] = "products_name LIKE '%" . P_SQL_Quote_Like($keyword) . "%'";
      $condition[] = "products_description LIKE '%" . $keyword . "%'";
    }
  }
  if(count($condition) <= 0) return 0;

  $query = 'SELECT COUNT(1) FROM ' . TBL_PRO_DES . ' p WHERE ' . implode(' OR ', $condition);
  $Result = P_MySQL_Real_SELECT( $query );
  $Result = $Result[0];

  return $Result;
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
function LoadSearchResultProductID( $keyword_arr, $offset=0, $limit=DEFAULT_PAGER_LIMIT )
{
  if(empty($keyword_arr)) return array();

  $condition = array();
  foreach($keyword_arr as $keyword)
  {
    $keyword = trim($keyword);
    $keyword = P_SQL_Quote_Like($keyword);
    if(strlen($keyword) > 0)
    {
      $condition[] = "products_name LIKE '%" . P_SQL_Quote_Like($keyword) . "%'";
      $condition[] = "products_description LIKE '%" . $keyword . "%'";
    }
  }
  if(count($condition) <= 0) return array();

  $query = 'SELECT products_id FROM ' . TBL_PRO_DES . ' p WHERE ' . implode(' OR ', $condition)
           . ' LIMIT ' . $offset . ',' . $limit;

  $tmp = P_MySQL_Real_SELECT_GetArray( $query );

  if( empty( $tmp[0] ) == FALSE ) {
    foreach($tmp as $value)
    {
      $Result[] = $value[0];
    }
    return $Result;
  }

  return array();
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
function LoadBestSellerProducts($limit=MAX_BEST_SELLER)
{
  $query  = 'SELECT DISTINCT p.products_id,pd.products_name,products_image FROM ' . TBL_PRODUCTS;
  $query .= ' p,' . TBL_PRO_DES . ' pd WHERE products_ordered>0 AND p.products_id=pd.products_id ';
  $query .= ' AND pd.language_id=1 ORDER BY products_ordered DESC, products_name limit ' . $limit;

  return P_MySQL_Real_SELECT_GetArrayIndex( $query );
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
?>
