<?php
/**************************************************************************************************/
/* Created on May 30, 2010                                                                        */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "Paging.inc" );
require_once( FUNCTIONS_PATH . "products/products_db.inc" );
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
$errs = array();

if($_SERVER['REQUEST_METHOD'] == 'POST'){
  $keyword_string = $_POST['txtKey'];
  $encode_for_url = /*urlencode*/htmlentities($_POST['txtKey']);
  $current_page   = 1;

  $tmp_keyword_string = trim($keyword_string, '"');
  $tmp_keyword_string = trim($tmp_keyword_string);
  if(strlen($tmp_keyword_string)<3) $errs[] = 'Hãy nhập ít nhất 1 từ khóa có 3 ký tự trở lên';
} else {
  $keyword_string = rawurldecode($Request['parameters'][':key']);
  $keyword_string = trim($keyword_string);
  $current_page   = $Request['parameters'][':page'];
  $encode_for_url = htmlentities($keyword_string);
}

if(count($errs) <= 0){
  $pos_offset = 0;
  do{
    $close_bracket_pos = FALSE;
    // ------------------------------------------------------------------------------------------ //
  	$open_bracket_pos  = strpos($keyword_string, '"',$pos_offset);
    if($open_bracket_pos !== FALSE)
      $close_bracket_pos = strpos($keyword_string, '"',$open_bracket_pos+1);
    // ------------------------------------------------------------------------------------------ //
    if($close_bracket_pos !== FALSE)
    {
    	$pos_offset = $close_bracket_pos+1;
      $tmp_complex_keys[] = substr($keyword_string, $open_bracket_pos+1,
                                   $close_bracket_pos-$open_bracket_pos-1);
    }
  } while ($close_bracket_pos !== FALSE);
  // -------------------------------------------------------------------------------------------- //
  // Exclude complex_key from $keyword_string
  // and reject empty complex_key
  // -------------------------------------------------------------------------------------------- //
  foreach($tmp_complex_keys as $complex_key)
  {
  	$keyword_string = str_replace('"' . $complex_key . '"', '', $keyword_string);
    $complex_key = trim($complex_key);
    if(strlen($complex_key)>0) $complex_keys[] = $complex_key;
  }
  // -------------------------------------------------------------------------------------------- //
  $keyword_string = trim($keyword_string);
  $keyword_string = str_replace('  ', ' ', $keyword_string);

  $simple_keys = explode(' ', $keyword_string);
  if(is_array($complex_keys))
    $keyword_array = array_merge($simple_keys, $complex_keys);
  else
    $keyword_array = $simple_keys;
}
// ---------------------------------------------------------------------------------------------- //
// Count result
// ---------------------------------------------------------------------------------------------- //
$Product_List  = array();

$limit         = 9;
$total_records = CountSearchResult( $keyword_array );

if($total_records > 0)
{
  $total_pages   = Compute_Total_Page( $total_records, $limit );
  $current_page  = Validatize_Current_Page( $current_page, $total_pages );

  $offset        = ($current_page - 1) * $limit;
  $ID_List       = LoadSearchResultProductID( $keyword_array, $offset, $limit );
  $Product_List  = LoadProducts($ID_List);
}
// ---------------------------------------------------------------------------------------------- //
// Paging
// ---------------------------------------------------------------------------------------------- //
$Paging_info["TOTAL_PAGE"]   = $total_pages;
$Paging_info["CURRENT_PAGE"] = $current_page;
$Paging_info["LIMIT"]        = $limit;
$Paging_info["URL"]          = '/timkiem/' . $encode_for_url . '/:page';

$pager = Paginate( $Paging_info );
$list_pad = 0;
$product_count = count($ID_List);

if($product_count <= 3) $list_pad = 3;
elseif($product_count <= 6) $list_pad = 6;
elseif($product_count <= 9) $list_pad = 9;
elseif($product_count <= 12) $list_pad = 12;
$Product_List = array_pad($Product_List, $list_pad, array('empty'=>'true'));
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
$smarty->assign( "product_from", $offset + 1 );
$smarty->assign( "product_to", $offset + $product_count );
$smarty->assign( "product_count", $product_count );
$smarty->assign( "total_products", $total_records );
$smarty->assign( "Product_List", $Product_List );
$smarty->assign( "pager", $pager );
$smarty->assign( "txtKey", $encode_for_url );

$smarty->assign( "error_count", count($errs) );
$smarty->assign( "errs", $errs );
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
$center_col = $smarty->fetch( "search/search.tpl" );
?>
