<?php
/**************************************************************************************************/
/* Created on Dec 4, 2008                                                                         */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "categories/categories_db.inc" );
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
if(! Check_Admin_Ajax()) return;

$parent_id = $Request['parameters'][':parentid'];
$Cat       = List_Category($parent_id);
$html      = '';

if(!empty($Cat))
{
  $html = '<ul style="list-style-type: none;">';
  foreach($Cat as $value){
  	$html .= '<li class="folder">' . $value['categories_name'] . '</li>';
  }
  $html .= '</ul>';
}

echo $html;
?>
