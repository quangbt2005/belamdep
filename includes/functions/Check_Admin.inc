<?php
/**************************************************************************************************/
/* Created on July 01, 2010                                                                       */
/**************************************************************************************************/
function Check_Admin()
{
	if(empty($_SESSION['admin']['id'])) {
    header('Location: /admin/login');
    exit;
  }
  return true;
}

function Check_Admin_Ajax()
{
  if(empty($_SESSION['admin']['id'])) {
    return false;
  }
  return true;
}
?>
