<?php
/**********************************************************************/
/* Created on Dec 7, 2008                                             */
/**********************************************************************/
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
