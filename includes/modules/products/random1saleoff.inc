<?php
/**************************************************************************************************/
/* Created on Dec 4, 2008                                                                         */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "products/products_db.inc" );
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
$saleoffProduct = LoadRandom1SaleOffProducts();
$html = '';
if(!empty($saleoffProduct))
{
  $html = '<a href="/sanpham/' . $saleoffProduct['products_id'] . '/chitiet">'
	      . '<img border="0" title="' . $saleoffProduct['products_name'] . '" alt="'
        . $saleoffProduct['products_name'] . '" src="/product_thumb.php?f='
        . $saleoffProduct['products_image'] . '&w=auto&h=80&ma=500"></a>';

  $html .= '<br><a href="/sanpham/' . $saleoffProduct['products_id'] . '/detail">'
          .'<span class="f9">' . $saleoffProduct['products_name'] . '</span></a>';
  $html .= '<br><s class="f8">' . number_format($saleoffProduct['products_price'],0) . '</s>';
  $html .= '<br><b class="f8 fore-red">' . number_format($saleoffProduct['special_price'],0)
           . '&nbsp;VND</b>';
}

echo $html;
?>
