<?php
/*
 * Created on Apr 9, 2010
 *
 * To change the template for this generated file go to
 * Window - Preferences - PHPeclipse - PHP - Code Templates
 */

  require('includes/application_top.php');

  //cPath is parsed from application_top.php
  //cPath is default as categories path
  //but the parsing can be applied for news_categories, so get cPath as for news_categories
  //just rename the name
  $current_news_categories_id = $current_category_id;
  
  
  $action = (isset($HTTP_GET_VARS['action']) ? $HTTP_GET_VARS['action'] : '');

  if (tep_not_null($action)) {
    switch ($action) {
      case 'setflag':
        if ( ($HTTP_GET_VARS['flag'] == '0') || ($HTTP_GET_VARS['flag'] == '1') ) {
          if (isset($HTTP_GET_VARS['nID'])) {
            tep_set_news_status($HTTP_GET_VARS['nID'], $HTTP_GET_VARS['flag']);
          }

          if (USE_CACHE == 'true') {
            tep_reset_cache_block('news');
          }
        }

        tep_redirect(tep_href_link(FILENAME_NEWS, 'cPath=' . $HTTP_GET_VARS['cPath'] . '&nID=' . $HTTP_GET_VARS['nID']));
        break;
      case 'insert_news_categories':
      case 'update_news_categories':
        if (isset($HTTP_POST_VARS['news_categories_id'])) $news_categories_id = tep_db_prepare_input($HTTP_POST_VARS['news_categories_id']);
        $sort_order = tep_db_prepare_input($HTTP_POST_VARS['sort_order']);
        $news_categories_name = tep_db_prepare_input($HTTP_POST_VARS['news_categories_name']);

        $sql_data_array = array('sort_order' => (int)$sort_order,
        						'news_categories_name' => $news_categories_name
        						);

        if ($action == 'insert_news_categories') {
          $insert_sql_data = array('parent_id' => $current_news_categories_id,
                                   'date_added' => 'now()');

          $sql_data_array = array_merge($sql_data_array, $insert_sql_data);

          tep_db_perform(TABLE_NEWS_CATEGORIES, $sql_data_array);

          $news_categories_id = tep_db_insert_id();
        } elseif ($action == 'update_news_categories') {
          tep_db_perform(TABLE_NEWS_CATEGORIES, $sql_data_array, 'update', "news_categories_id = '" . (int)$news_categories_id . "'");
        }

        $news_categories_icon = new upload('icon');
        $news_categories_icon->set_destination(DIR_FS_CATALOG_IMAGES);

        if ($news_categories_icon->parse() && $news_categories_icon->save()) {
          tep_db_query("update " . TABLE_NEWS_CATEGORIES . " set icon = '" . tep_db_input($news_categories_icon->filename) . "' where news_categories_id = '" . (int)$news_categories_id . "'");
        }

        if (USE_CACHE == 'true') {
          tep_reset_cache_block('news');
        }

        tep_redirect(tep_href_link(FILENAME_NEWS, 'cPath=' . $cPath . '&cID=' . $news_categories_id));
        break;
      case 'delete_news_categories_confirm':
        if (isset($HTTP_POST_VARS['news_categories_id'])) {
          $news_categories_id = tep_db_prepare_input($HTTP_POST_VARS['news_categories_id']);
			//lay cac danh muc con
          $news_categories = tep_get_news_categories_tree($news_categories_id, '', '0', '', true);
          $news = array();
          $news_delete = array();
			//xoa tat ca cac news thuoc danh muc con vua lay o tren
          for ($i=0, $n=sizeof($news_categories); $i<$n; $i++) {
            $news_ids_query = tep_db_query("select news_id from " . TABLE_NEWS . " where news_categories_id = '" . (int)$news_categories[$i]['id'] . "'");

            while ($news_ids = tep_db_fetch_array($news_ids_query)) {
              //delete news
              tep_db_query("delete from " . TABLE_NEWS . " where news_id = '" . (int)$news_ids['news_id'] . "'");
            }
            //DELETE NEWS_CATEGORIES ITSELF
            tep_db_query("delete from " . TABLE_NEWS_CATEGORIES . " where news_categories_id = '" . (int)$news_categories[$i]['id'] . "'");
          }
        }

        if (USE_CACHE == 'true') {
          tep_reset_cache_block('news');
        }

        tep_redirect(tep_href_link(FILENAME_NEWS, 'cPath=' . $cPath));
        break;
      case 'delete_news_confirm':
        if (isset($HTTP_POST_VARS['news_id'])) {
//          $news_categories_id = tep_db_prepare_input($HTTP_POST_VARS['news_categories_id']);
          $news_id = $HTTP_POST_VARS['news_id'];
		  tep_db_query("delete from " . TABLE_NEWS . " where news_id = '" . (int)$news_id . "'");

        }

        if (USE_CACHE == 'true') {
          tep_reset_cache_block('news');
        }

        tep_redirect(tep_href_link(FILENAME_NEWS, 'cPath=' . $cPath));
        break;
      case 'move_news_categories_confirm':
        if (isset($HTTP_POST_VARS['news_categories_id']) && ($HTTP_POST_VARS['news_categories_id'] != $HTTP_POST_VARS['move_to_news_categories_id'])) {
          $news_categories_id = tep_db_prepare_input($HTTP_POST_VARS['news_categories_id']);
          $new_parent_id = tep_db_prepare_input($HTTP_POST_VARS['move_to_news_categories_id']);

          $path = explode('_', tep_get_generated_news_categories_path_ids($new_parent_id));

          if (in_array($news_categories_id, $path)) {
            $messageStack->add_session(ERROR_CANNOT_MOVE_NEWS_CATEGORIES_TO_PARENT, 'error');

            tep_redirect(tep_href_link(FILENAME_NEWS, 'cPath=' . $cPath . '&cID=' . $news_categories_id));
          } else {
            tep_db_query("update " . TABLE_NEWS_CATEGORIES . " set parent_id = '" . (int)$new_parent_id . "' where news_categories_id = '" . (int)$news_categories_id . "'");

            if (USE_CACHE == 'true') {
              tep_reset_cache_block('news');
            }

            tep_redirect(tep_href_link(FILENAME_NEWS, 'cPath=' . $new_parent_id . '&cID=' . $news_categories_id));
          }
        }

        break;
      case 'move_news_confirm':
        $news_id = tep_db_prepare_input($HTTP_POST_VARS['news_id']);
        $new_parent_id = tep_db_prepare_input($HTTP_POST_VARS['move_to_news_categories_id']);

		$news_categories_path_toinsert = tep_get_news_categories_path_toinsert($new_parent_id);
		tep_db_query("update " . TABLE_NEWS . " set parent_id='" . (int)$new_parent_id . "', news_categories_path='" . $news_categories_path_toinsert . "' where news_id='" . $news_id . "'");
        if (USE_CACHE == 'true') {
          tep_reset_cache_block('news');
        }

        tep_redirect(tep_href_link(FILENAME_NEWS, 'cPath=' . $new_parent_id . '&nID=' . $news_id));
        break;
      case 'insert_news':
      case 'update_news':
        if (isset($HTTP_POST_VARS['edit_x']) || isset($HTTP_POST_VARS['edit_y'])) {
          $action = 'new_news';
        } else {
          if (isset($HTTP_GET_VARS['nID'])) $news_id = tep_db_prepare_input($HTTP_GET_VARS['nID']);

          $sql_data_array = array('news_title' => tep_db_prepare_input($HTTP_POST_VARS['news_title']),
                                  'news_content' => tep_db_prepare_input($HTTP_POST_VARS['news_content']),
                                  'news_status' => tep_db_prepare_input($HTTP_POST_VARS['news_status']),
                                  'source' => tep_db_prepare_input($HTTP_POST_VARS['source']),
//                                  'icon'	=> tep_db_prepare_input($HTTP_POST_VARS['icon']),
								  'sort_order' =>	tep_db_prepare_input($HTTP_POST_VARS['sort_order']),
                                  'news_categories_id' => (int)$current_news_categories_id,
                                  'news_categories_path' => tep_get_news_categories_path_toinsert($current_news_categories_id));
			if (isset($HTTP_POST_VARS['icon']) && tep_not_null($HTTP_POST_VARS['icon']) && ($HTTP_POST_VARS['icon'] != 'none')) {
			     $sql_data_array['icon'] = tep_db_prepare_input($HTTP_POST_VARS['icon']);
			}
          
          if ($action == 'insert_news') {
            $insert_sql_data = array('date_added' => 'now()');

            $sql_data_array = array_merge($sql_data_array, $insert_sql_data);

            tep_db_perform(TABLE_NEWS, $sql_data_array);
            $news_id = tep_db_insert_id();

          } elseif ($action == 'update_news') {

            tep_db_perform(TABLE_NEWS, $sql_data_array, 'update', "news_id = '" . (int)$news_id . "'");
          }

                
          if (USE_CACHE == 'true') {
            tep_reset_cache_block('news');
          }

          tep_redirect(tep_href_link(FILENAME_NEWS, 'cPath=' . $cPath . '&nID=' . $news_id));
        }
        break;
//      case 'copy_to_confirm':
//        if (isset($HTTP_POST_VARS['news_id']) && isset($HTTP_POST_VARS['news_id'])) {
//          $news_id = tep_db_prepare_input($HTTP_POST_VARS['news_id']);
//          $news_id = tep_db_prepare_input($HTTP_POST_VARS['news_id']);
//
//          if ($HTTP_POST_VARS['copy_as'] == 'link') {
//            if ($news_id != $current_news_id) {
//              $check_query = tep_db_query("select count(*) as total from " . TABLE_PRODUCTS_TO_news . " where news_id = '" . (int)$news_id . "' and news_id = '" . (int)$news_id . "'");
//              $check = tep_db_fetch_array($check_query);
//              if ($check['total'] < '1') {
//                tep_db_query("insert into " . TABLE_PRODUCTS_TO_news . " (news_id, news_id) values ('" . (int)$news_id . "', '" . (int)$news_id . "')");
//              }
//            } else {
//              $messageStack->add_session(ERROR_CANNOT_LINK_TO_SAME_news, 'error');
//            }
//          } elseif ($HTTP_POST_VARS['copy_as'] == 'duplicate') {
//            $product_query = tep_db_query("select products_quantity, products_model, products_image, products_price, products_date_available, products_weight, products_tax_class_id, manufacturers_id from " . TABLE_PRODUCTS . " where news_id = '" . (int)$news_id . "'");
//            $product = tep_db_fetch_array($product_query);
//
//            tep_db_query("insert into " . TABLE_PRODUCTS . " (products_quantity, products_model,products_image, products_price, products_date_added, products_date_available, products_weight, products_status, products_tax_class_id, manufacturers_id) values ('" . tep_db_input($product['products_quantity']) . "', '" . tep_db_input($product['products_model']) . "', '" . tep_db_input($product['products_image']) . "', '" . tep_db_input($product['products_price']) . "',  now(), " . (empty($product['products_date_available']) ? "null" : "'" . tep_db_input($product['products_date_available']) . "'") . ", '" . tep_db_input($product['products_weight']) . "', '0', '" . (int)$product['products_tax_class_id'] . "', '" . (int)$product['manufacturers_id'] . "')");
//            $dup_news_id = tep_db_insert_id();
//
//            $description_query = tep_db_query("select language_id, products_name, products_description, products_url from " . TABLE_PRODUCTS_DESCRIPTION . " where news_id = '" . (int)$news_id . "'");
//            while ($description = tep_db_fetch_array($description_query)) {
//              tep_db_query("insert into " . TABLE_PRODUCTS_DESCRIPTION . " (news_id, language_id, products_name, products_description, products_url, products_viewed) values ('" . (int)$dup_news_id . "', '" . (int)$description['language_id'] . "', '" . tep_db_input($description['products_name']) . "', '" . tep_db_input($description['products_description']) . "', '" . tep_db_input($description['products_url']) . "', '0')");
//            }
//
//            tep_db_query("insert into " . TABLE_PRODUCTS_TO_news . " (news_id, news_id) values ('" . (int)$dup_news_id . "', '" . (int)$news_id . "')");
//            $news_id = $dup_news_id;
//          }
//
//          if (USE_CACHE == 'true') {
//            tep_reset_cache_block('news');
//            tep_reset_cache_block('also_purchased');
//          }
//        }
//
//        tep_redirect(tep_href_link(FILENAME_news, 'cPath=' . $news_id . '&nID=' . $news_id));
//        break;
      case 'new_news_preview':
// copy image only if modified
        $news_icon = new upload('icon');
        $news_icon->set_destination(DIR_FS_CATALOG_IMAGES);
        if ($news_icon->parse() && $news_icon->save()) {
          $news_icon_name = $news_icon->filename;
        } else {
          $news_icon_name = (isset($HTTP_POST_VARS['news_previous_icon']) ? $HTTP_POST_VARS['news_previous_icon'] : '');
        }
        break;
    }
  }

// check if the catalog image directory exists
  if (is_dir(DIR_FS_CATALOG_IMAGES)) {
    if (!is_writeable(DIR_FS_CATALOG_IMAGES)) $messageStack->add(ERROR_CATALOG_IMAGE_DIRECTORY_NOT_WRITEABLE, 'error');
  } else {
    $messageStack->add(ERROR_CATALOG_IMAGE_DIRECTORY_DOES_NOT_EXIST, 'error');
  }
?>
<!doctype html public "-//W3C//DTD HTML 4.01 Transitional//EN">
<html <?php echo HTML_PARAMS; ?>>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=<?php echo CHARSET; ?>">
<title><?php echo TITLE; ?></title>
<link rel="stylesheet" type="text/css" href="includes/stylesheet.css">
<script language="javascript" src="includes/general.js"></script>
</head>
<body marginwidth="0" marginheight="0" topmargin="0" bottommargin="0" leftmargin="0" rightmargin="0" bgcolor="#FFFFFF" onload="SetFocus();">
<div id="spiffycalendar" class="text"></div>
<!-- header //-->
<?php require(DIR_WS_INCLUDES . 'header.php'); ?>
<!-- header_eof //-->

<!-- body //-->
<table border="0" width="100%" cellspacing="2" cellpadding="2">
  <tr>
    <td width="<?php echo BOX_WIDTH; ?>" valign="top"><table border="0" width="<?php echo BOX_WIDTH; ?>" cellspacing="1" cellpadding="1" class="columnLeft">
<!-- left_navigation //-->
<?php require(DIR_WS_INCLUDES . 'column_left.php'); ?>
<!-- left_navigation_eof //-->
    </table></td>
<!-- body_text //-->
    <td width="100%" valign="top">
<?php
  if ($action == 'new_news') {
    $parameters = array('news_title' => '',
                       'source' => '',
                       'sort_order' => '',
                       'news_categories_id' => '',
                       'date_added' => '',
                       'news_content' => '',
                       'news_status' => '',
                       'icon' => '');

    $nInfo = new objectInfo($parameters);

    if (isset($HTTP_GET_VARS['nID']) && empty($HTTP_POST_VARS)) {
      $news_query = tep_db_query("select n.news_id, n.news_title, n.news_content, n.source, n.icon, n.sort_order, n.news_categories_id, n.news_status, n.date_added from " . TABLE_NEWS . " n where n.news_id = '" . (int)$HTTP_GET_VARS['nID'] . "'");
      $news = tep_db_fetch_array($news_query);

      $nInfo->objectInfo($news);
    } elseif (tep_not_null($HTTP_POST_VARS)) {
      $nInfo->objectInfo($HTTP_POST_VARS);
//      $products_name = $HTTP_POST_VARS['products_name'];
//      $products_description = $HTTP_POST_VARS['products_description'];
//      $products_url = $HTTP_POST_VARS['products_url'];
//	  $news_title = $HTTP_POST_VARS['news_title'];
//	  $news_content = $HTTP_POST_VARS['news_content'];
//	  $news_icon_name = $HTTP_POST_VARS['icon'];
    }

    if (!isset($nInfo->news_status)) $nInfo->news_status = '1';
    switch ($nInfo->news_status) {
      case '0': $checked_status = false; $unchecked_status = true; break;
      case '1':
      default: $checked_status = true; $unchecked_status = false;
    }
?>
<?php echo tep_draw_form('new_news', FILENAME_NEWS, 'cPath=' . $cPath . (isset($HTTP_GET_VARS['nID']) ? '&nID=' . $HTTP_GET_VARS['nID'] : '') . '&action=new_news_preview', 'post', 'enctype="multipart/form-data"'); ?>
    <table border="0" width="100%" cellspacing="0" cellpadding="2">
      <tr>
        <td><table border="0" width="100%" cellspacing="0" cellpadding="0">
          <tr>
            <td class="pageHeading"><?php echo sprintf(TEXT_NEW_NEWS, tep_output_generated_news_categories_path($current_news_categories_id)); ?></td>
            <td class="pageHeading" align="right"><?php echo tep_draw_separator('pixel_trans.gif', HEADING_IMAGE_WIDTH, HEADING_IMAGE_HEIGHT); ?></td>
          </tr>
        </table></td>
      </tr>
      <tr>
        <td><?php echo tep_draw_separator('pixel_trans.gif', '1', '10'); ?></td>
      </tr>
      <tr>
        <td><table border="0" cellspacing="0" cellpadding="2">
          <tr>
            <td class="main"><?php echo TEXT_NEWS_STATUS; ?></td>
            <td class="main"><?php echo tep_draw_separator('pixel_trans.gif', '24', '15') . '&nbsp;' . tep_draw_radio_field('news_status', '1', $checked_status) . '&nbsp;' . TEXT_NEWS_CHECKED . '&nbsp;' . tep_draw_radio_field('news_status', '0', $unchecked_status) . '&nbsp;' . TEXT_NEWS_UNCHECKED; ?></td>
          </tr>
          <tr>
            <td colspan="2"><?php echo tep_draw_separator('pixel_trans.gif', '1', '10'); ?></td>
          </tr>
          <tr>
            <td class="main"><?php echo TEXT_NEWS_TITLE; ?></td>
            <td class="main"><?php echo tep_draw_input_field('news_title', (isset($news_title)) ? stripslashes($news_title) : tep_get_news_title($nInfo->news_id)); ?></td>
          </tr>
          <tr>
            <td colspan="2"><?php echo tep_draw_separator('pixel_trans.gif', '1', '10'); ?></td>
          </tr>
        <tr>
            <td class="main" valign="top"><?php echo TEXT_NEWS_CONTENT; ?></td>
            <td><?php echo tep_draw_textarea_field('news_content', 'soft', '70', '15', (isset($news_content) ? stripslashes($news_content) : tep_get_news_content($nInfo->news_id))); ?></td>
          </tr>
          <tr>
            <td colspan="2"><?php echo tep_draw_separator('pixel_trans.gif', '1', '10'); ?></td>
          </tr>
          <tr>
            <td class="main"><?php echo TEXT_NEWS_SOURCE; ?></td>
            <td class="main"><?php echo tep_draw_separator('pixel_trans.gif', '24', '15') . '&nbsp;' . tep_draw_input_field('source', $nInfo->source); ?></td>
          </tr>
          <tr>
            <td colspan="2"><?php echo tep_draw_separator('pixel_trans.gif', '1', '10'); ?></td>
          </tr>
          <tr>
            <td class="main"><?php echo TEXT_NEWS_ICON; ?></td>
            <td class="main"><?php echo tep_draw_separator('pixel_trans.gif', '24', '15') . '&nbsp;' . tep_draw_file_field('icon') . '<br>' . tep_draw_separator('pixel_trans.gif', '24', '15') . '&nbsp;' . $nInfo->icon . tep_draw_hidden_field('news_previous_icon', $nInfo->icon); ?></td>
          </tr>
          <tr>
            <td colspan="2"><?php echo tep_draw_separator('pixel_trans.gif', '1', '10'); ?></td>
          </tr>
          <tr>
            <td class="main"><?php echo TEXT_NEWS_SORT_ORDER; ?></td>
            <td class="main"><?php echo tep_draw_separator('pixel_trans.gif', '24', '15') . '&nbsp;' . tep_draw_input_field('sort_order', $nInfo->sort_order); ?></td>
          </tr>
        </table></td>
      </tr>
      <tr>
        <td><?php echo tep_draw_separator('pixel_trans.gif', '1', '10'); ?></td>
      </tr>
      <tr>
        <td class="main" align="right"><?php echo tep_draw_hidden_field('date_added', (tep_not_null($nInfo->date_added) ? $nInfo->date_added : date('Y-m-d'))) . tep_image_submit('button_preview.gif', IMAGE_PREVIEW) . '&nbsp;&nbsp;<a href="' . tep_href_link(FILENAME_NEWS, 'cPath=' . $cPath . (isset($HTTP_GET_VARS['nID']) ? '&nID=' . $HTTP_GET_VARS['nID'] : '')) . '">' . tep_image_button('button_cancel.gif', IMAGE_CANCEL) . '</a>'; ?></td>
      </tr>
    </table></form>
<?php
  } elseif ($action == 'new_news_preview') {
    if (tep_not_null($HTTP_POST_VARS)) {
      $nInfo = new objectInfo($HTTP_POST_VARS);
//      $products_name = $HTTP_POST_VARS['products_name'];
//      $products_description = $HTTP_POST_VARS['products_description'];
//      $products_url = $HTTP_POST_VARS['products_url'];
//      $news_title = $HTTP_POST_VARS['news_title'];
//	  $news_content = $HTTP_POST_VARS['news_content'];
//	  $news_icon_name  = $HTTP_POST_VARS['icon'];
    } else { 
      $news_query = tep_db_query("select n.news_id, n.news_title, n.news_content, n.source, n.icon, n.sort_order, n.news_categories_id, n.news_status, n.date_added from " . TABLE_NEWS . " n where n.news_id = '" . (int)$HTTP_GET_VARS['nID'] . "'");
      $news = tep_db_fetch_array($news_query);

      $nInfo = new objectInfo($news);
//      $news_icon_name = $nInfo->icon;
    }
    
    $form_action = (isset($HTTP_GET_VARS['nID'])) ? 'update_news' : 'insert_news';

    echo tep_draw_form($form_action, FILENAME_NEWS, 'cPath=' . $cPath . (isset($HTTP_GET_VARS['nID']) ? '&nID=' . $HTTP_GET_VARS['nID'] : '') . '&action=' . $form_action, 'post', 'enctype="multipart/form-data"');
//
//        $pInfo->products_name = tep_db_prepare_input($products_name[$languages[$i]['id']]);
//        $pInfo->products_description = tep_db_prepare_input($products_description[$languages[$i]['id']]);
//        $pInfo->products_url = tep_db_prepare_input($products_url[$languages[$i]['id']]);
	  if (isset($HTTP_GET_VARS['read']) && ($HTTP_GET_VARS['read'] == 'only')) {
//        $pInfo->products_name = tep_get_products_name($pInfo->products_id, $languages[$i]['id']);
//        $pInfo->products_description = tep_get_products_description($pInfo->products_id, $languages[$i]['id']);
//        $pInfo->products_url = tep_get_products_url($pInfo->products_id, $languages[$i]['id']);
//        $nInfo->news_title = tep_get_news_title($nInfo->news_id);
//        $nInfo->news_content = tep_get_news_content($nInfo->news_id);
      } else {
//        $pInfo->products_name = tep_db_prepare_input($products_name[$languages[$i]['id']]);
//        $pInfo->products_description = tep_db_prepare_input($products_description[$languages[$i]['id']]);
//        $pInfo->products_url = tep_db_prepare_input($products_url[$languages[$i]['id']]);
//        $nInfo->news_title = tep_db_prepare_input($news_title);
//        $nInfo->news_content = tep_db_prepare_input($news_content);
      }
?>
    <table border="0" width="100%" cellspacing="0" cellpadding="2">
      <tr>
        <td><table border="0" width="100%" cellspacing="0" cellpadding="0">
          <tr>
            <td class="pageHeading"><?php echo $nInfo->news_title; ?></td>
            <td class="pageHeading" align="right"><?php echo tep_image(DIR_WS_CATALOG_IMAGES . $nInfo->icon, $nInfo->news_title, SMALL_IMAGE_WIDTH, SMALL_IMAGE_HEIGHT, 'align="right" hspace="5" vspace="5"'); ?></td>
          </tr>
        </table></td>
      </tr>
      <tr>
        <td><?php echo tep_draw_separator('pixel_trans.gif', '1', '10'); ?></td>
      </tr>
      <tr>
        <td class="main"><?php echo $nInfo->news_content; ?></td>
      </tr>

      <tr>
        <td><?php echo tep_draw_separator('pixel_trans.gif', '1', '10'); ?></td>
      </tr>
<?php

    if (isset($HTTP_GET_VARS['read']) && ($HTTP_GET_VARS['read'] == 'only')) {
      if (isset($HTTP_GET_VARS['origin'])) {
        $pos_params = strpos($HTTP_GET_VARS['origin'], '?', 0);
        if ($pos_params != false) {
          $back_url = substr($HTTP_GET_VARS['origin'], 0, $pos_params);
          $back_url_params = substr($HTTP_GET_VARS['origin'], $pos_params + 1);
        } else {
          $back_url = $HTTP_GET_VARS['origin'];
          $back_url_params = '';
        }
      } else {
        $back_url = FILENAME_NEWS;
        $back_url_params = 'cPath=' . $cPath . '&nID=' . $nInfo->news_id;
      }
?>
      <tr>
        <td align="right"><?php echo '<a href="' . tep_href_link($back_url, $back_url_params, 'NONSSL') . '">' . tep_image_button('button_back.gif', IMAGE_BACK) . '</a>'; ?></td>
      </tr>
<?php
    } else {
?>
      <tr>
        <td align="right" class="smallText">
<?php
/* Re-Post all POST'ed variables */
      reset($HTTP_POST_VARS);
      while (list($key, $value) = each($HTTP_POST_VARS)) {
        if (!is_array($HTTP_POST_VARS[$key])) {
          echo tep_draw_hidden_field($key, htmlspecialchars(stripslashes($value)));
        }
      }
//        echo tep_draw_hidden_field('news_title', htmlspecialchars(stripslashes($news_title)));
//        echo tep_draw_hidden_field('news_content', htmlspecialchars(stripslashes($news_content)));
      echo tep_draw_hidden_field('icon', stripslashes($news_icon_name));

      echo tep_image_submit('button_back.gif', IMAGE_BACK, 'name="edit"') . '&nbsp;&nbsp;';

      if (isset($HTTP_GET_VARS['nID'])) {
        echo tep_image_submit('button_update.gif', IMAGE_UPDATE);
      } else {
        echo tep_image_submit('button_insert.gif', IMAGE_INSERT);
      }
      echo '&nbsp;&nbsp;<a href="' . tep_href_link(FILENAME_NEWS, 'cPath=' . $cPath . (isset($HTTP_GET_VARS['nID']) ? '&nID=' . $HTTP_GET_VARS['nID'] : '')) . '">' . tep_image_button('button_cancel.gif', IMAGE_CANCEL) . '</a>';
?></td>
      </tr>
    </table></form>
<?php
    }
  } else {//show news categories
?>
    <table border="0" width="100%" cellspacing="0" cellpadding="2">
      <tr>
        <td><table border="0" width="100%" cellspacing="0" cellpadding="0">
          <tr>
            <td class="pageHeading"><?php echo HEADING_TITLE; ?></td>
            <td class="pageHeading" align="right"><?php echo tep_draw_separator('pixel_trans.gif', 1, HEADING_IMAGE_HEIGHT); ?></td>
            <td align="right"><table border="0" width="100%" cellspacing="0" cellpadding="0">
              <tr>
                <td class="smallText" align="right">
<?php
    echo tep_draw_form('search', FILENAME_NEWS, '', 'get');
    echo HEADING_TITLE_SEARCH . ' ' . tep_draw_input_field('search');
    echo tep_hide_session_id() . '</form>';
?>
                </td>
              </tr>
              <tr>
                <td class="smallText" align="right">
<?php
    echo tep_draw_form('goto', FILENAME_NEWS, '', 'get');
    echo HEADING_TITLE_GOTO . ' ' . tep_draw_pull_down_menu('cPath', tep_get_news_categories_tree(), $current_news_categories_id, 'onChange="this.form.submit();"');
    echo tep_hide_session_id() . '</form>';
?>
                </td>
              </tr>
            </table></td>
          </tr>
        </table></td>
      </tr>
      <tr>
        <td><table border="0" width="100%" cellspacing="0" cellpadding="0">
          <tr>
            <td valign="top"><table border="0" width="100%" cellspacing="0" cellpadding="2">
              <tr class="dataTableHeadingRow">
                <td class="dataTableHeadingContent"><?php echo TABLE_HEADING_NEWS_CATEGORIES; ?></td>
                <td class="dataTableHeadingContent" align="center"><?php echo TABLE_HEADING_STATUS; ?></td>
                <td class="dataTableHeadingContent" align="right"><?php echo TABLE_HEADING_ACTION; ?>&nbsp;</td>
              </tr>
<?php
    $news_categories_count = 0;
    $rows = 0;
    if (isset($HTTP_GET_VARS['search'])) {
      $search = tep_db_prepare_input($HTTP_GET_VARS['search']);

      $news_categories_query = tep_db_query("select nc.news_categories_id, nc.sort_order, nc.news_categories_name, nc.parent_id, nc.date_added, nc.icon from " . TABLE_NEWS_CATEGORIES . " nc where nc.news_categories_name like '%" . tep_db_input($search) . "%' order by nc.sort_order, nc.news_categories_name");
    } else {
      $news_categories_query = tep_db_query("select nc.news_categories_id, nc.sort_order, nc.news_categories_name, nc.parent_id, nc.date_added, nc.icon from " . TABLE_NEWS_CATEGORIES . " nc where nc.parent_id = '" . (int)$current_news_categories_id . "' order by nc.sort_order, nc.news_categories_name");
    }
    while ($news_categories = tep_db_fetch_array($news_categories_query)) {
      $news_categories_count++;
      $rows++;

// Get parent_id for subnews if search
      if (isset($HTTP_GET_VARS['search'])) $cPath= $news_categories['parent_id'];

      if ((!isset($HTTP_GET_VARS['cID']) && !isset($HTTP_GET_VARS['nID']) || (isset($HTTP_GET_VARS['cID']) && ($HTTP_GET_VARS['cID'] == $news_categories['news_categories_id']))) && !isset($cInfo) && (substr($action, 0, 3) != 'new')) {
        //get category con
        $news_categories_childs = array('childs_count' => tep_childs_in_news_categories_count($news_categories['news_categories_id']));
        //lay cac news thuoc category
        $news = array('news_count' => tep_news_in_news_categories_count($news_categories['news_categories_id']));

        $cInfo_array = array_merge($news_categories, $news_categories_childs, $news);
        $cInfo = new objectInfo($cInfo_array);
      }

      if (isset($cInfo) && is_object($cInfo) && ($news_categories['news_categories_id'] == $cInfo->news_categories_id) ) {
        echo '              <tr id="defaultSelected" class="dataTableRowSelected" onmouseover="rowOverEffect(this)" onmouseout="rowOutEffect(this)" onclick="document.location.href=\'' . tep_href_link(FILENAME_NEWS, tep_get_news_categories_path($news_categories['news_categories_id'])) . '\'">' . "\n";
      } else {
        echo '              <tr class="dataTableRow" onmouseover="rowOverEffect(this)" onmouseout="rowOutEffect(this)" onclick="document.location.href=\'' . tep_href_link(FILENAME_NEWS, 'cPath=' . $cPath . '&cID=' . $news_categories['news_categories_id']) . '\'">' . "\n";
      }
?>
                <td class="dataTableContent"><?php echo '<a href="' . tep_href_link(FILENAME_NEWS, tep_get_news_categories_path($news_categories['news_categories_id'])) . '">' . tep_image(DIR_WS_ICONS . 'folder.gif', ICON_FOLDER) . '</a>&nbsp;<b>' . $news_categories['news_categories_name'] . '</b>'; ?></td>
                <td class="dataTableContent" align="center">&nbsp;</td>
                <td class="dataTableContent" align="right"><?php if (isset($cInfo) && is_object($cInfo) && ($news_categories['news_categories_id'] == $cInfo->news_categories_id) ) { echo tep_image(DIR_WS_IMAGES . 'icon_arrow_right.gif', ''); } else { echo '<a href="' . tep_href_link(FILENAME_NEWS, 'cPath=' . $cPath . '&cID=' . $news_categories['news_categories_id']) . '">' . tep_image(DIR_WS_IMAGES . 'icon_info.gif', IMAGE_ICON_INFO) . '</a>'; } ?>&nbsp;</td>
              </tr>
<?php
    }

    $news_count = 0;
    if (isset($HTTP_GET_VARS['search'])) {
      $news_query = tep_db_query("select n.news_id, n.news_categories_id, n.news_title, n.news_content, n.source, n.icon, n.date_added, n.sort_order, n.news_status from " . TABLE_NEWS . " n where n.news_title like '%" . tep_db_input($search) . "%' order by n.sort_order, n.news_title");
    } else {
      $news_query = tep_db_query("select n.news_id, n.news_categories_id, n.news_title, n.news_content, n.source, n.icon, n.date_added, n.sort_order, n.news_status from " . TABLE_NEWS . " n where n.news_categories_id = '" . (int)$current_news_categories_id . "' order by n.sort_order, n.news_title");
    }
    while ($news = tep_db_fetch_array($news_query)) {
      $news_count++;
      $rows++;

// Get news_categories_id for news if search
      if (isset($HTTP_GET_VARS['search'])) $cPath = $news['news_categories_id'];

      if ( (!isset($HTTP_GET_VARS['nID']) && !isset($HTTP_GET_VARS['cID']) || (isset($HTTP_GET_VARS['nID']) && ($HTTP_GET_VARS['nID'] == $news['news_id']))) && !isset($nInfo) && !isset($cInfo) && (substr($action, 0, 3) != 'new')) {
// find out the rating average from customer reviews
		  $nInfo = new objectInfo($news);	
      }

      if (isset($nInfo) && is_object($nInfo) && ($news['news_id'] == $nInfo->news_id) ) {
        echo '              <tr id="defaultSelected" class="dataTableRowSelected" onmouseover="rowOverEffect(this)" onmouseout="rowOutEffect(this)" onclick="document.location.href=\'' . tep_href_link(FILENAME_NEWS, 'cPath=' . $cPath . '&nID=' . $news['news_id'] . '&action=new_news_preview&read=only') . '\'">' . "\n";
      } else {
        echo '              <tr class="dataTableRow" onmouseover="rowOverEffect(this)" onmouseout="rowOutEffect(this)" onclick="document.location.href=\'' . tep_href_link(FILENAME_NEWS, 'cPath=' . $cPath . '&nID=' . $news['news_id']) . '\'">' . "\n";
      }
?>
                <td class="dataTableContent"><?php echo '<a href="' . tep_href_link(FILENAME_NEWS, 'cPath=' . $cPath . '&nID=' . $news['news_id'] . '&action=new_news_preview&read=only') . '">' . tep_image(DIR_WS_ICONS . 'preview.gif', ICON_PREVIEW) . '</a>&nbsp;' . $news['news_title']; ?></td>
                <td class="dataTableContent" align="center">
<?php
      if ($news['news_status'] == '1') {
        echo tep_image(DIR_WS_IMAGES . 'icon_status_green.gif', IMAGE_ICON_STATUS_GREEN, 10, 10) . '&nbsp;&nbsp;<a href="' . tep_href_link(FILENAME_NEWS, 'action=setflag&flag=0&nID=' . $news['news_id'] . '&cPath=' . $cPath) . '">' . tep_image(DIR_WS_IMAGES . 'icon_status_red_light.gif', IMAGE_ICON_STATUS_RED_LIGHT, 10, 10) . '</a>';
      } else {
        echo '<a href="' . tep_href_link(FILENAME_NEWS, 'action=setflag&flag=1&nID=' . $news['news_id'] . '&cPath=' . $cPath) . '">' . tep_image(DIR_WS_IMAGES . 'icon_status_green_light.gif', IMAGE_ICON_STATUS_GREEN_LIGHT, 10, 10) . '</a>&nbsp;&nbsp;' . tep_image(DIR_WS_IMAGES . 'icon_status_red.gif', IMAGE_ICON_STATUS_RED, 10, 10);
      }
?></td>
                <td class="dataTableContent" align="right"><?php if (isset($nInfo) && is_object($nInfo) && ($news['news_id'] == $nInfo->news_id)) { echo tep_image(DIR_WS_IMAGES . 'icon_arrow_right.gif', ''); } else { echo '<a href="' . tep_href_link(FILENAME_NEWS, 'cPath=' . $cPath . '&nID=' . $news['news_id']) . '">' . tep_image(DIR_WS_IMAGES . 'icon_info.gif', IMAGE_ICON_INFO) . '</a>'; } ?>&nbsp;</td>
              </tr>
<?php
    }

    $cPath_back = '';
    if (sizeof($cPath_array) > 0) {
      for ($i=0, $n=sizeof($cPath_array)-1; $i<$n; $i++) {
        if (empty($cPath_back)) {
          $cPath_back .= $cPath_array[$i];
        } else {
          $cPath_back .= '_' . $cPath_array[$i];
        }
      }
    }

    $cPath_back = (tep_not_null($cPath_back)) ? 'cPath=' . $cPath_back . '&' : '';
?>
              <tr>
                <td colspan="3"><table border="0" width="100%" cellspacing="0" cellpadding="2">
                  <tr>
                    <td class="smallText"><?php echo TEXT_NEWS_CATEGORIES . '&nbsp;' . $news_categories_count . '<br>' . TEXT_NEWS . '&nbsp;' . $news_count; ?></td>
                    <td align="right" class="smallText"><?php if (sizeof($cPath_array) > 0) echo '<a href="' . tep_href_link(FILENAME_NEWS, $cPath_back . 'cID=' . $current_news_categories_id) . '">' . tep_image_button('button_back.gif', IMAGE_BACK) . '</a>&nbsp;'; if (!isset($HTTP_GET_VARS['search'])) echo '<a href="' . tep_href_link(FILENAME_NEWS, 'cPath=' . $cPath . '&action=new_news_categories') . '">' . tep_image_button('button_new_category.gif', IMAGE_NEW_NEWS_CATEGORIES) . '</a>&nbsp;<a href="' . tep_href_link(FILENAME_NEWS, 'cPath=' . $cPath . '&action=new_news') . '">' . tep_image_button('button_new_product.gif', IMAGE_NEW_NEWS) . '</a>'; ?>&nbsp;</td>
                  </tr>
                </table></td>
              </tr>
            </table></td>
<?php
    $heading = array();
    $contents = array();
    switch ($action) {
      case 'new_news_categories':
        $heading[] = array('text' => '<b>' . TEXT_INFO_HEADING_NEW_NEWS_CATEGORIES . '</b>');

        $contents = array('form' => tep_draw_form('newnewscategories', FILENAME_NEWS, 'action=insert_news_categories&cPath=' . $cPath, 'post', 'enctype="multipart/form-data"'));
        $contents[] = array('text' => TEXT_NEW_NEWS_CATEGORIES_INTRO);

        $news_categories_inputs_string = '';

        $contents[] = array('text' => '<br>' . TEXT_NEWS_CATEGORIES_NAME . '<br>' . tep_draw_input_field('news_categories_name'));
        $contents[] = array('text' => '<br>' . TEXT_NEWS_CATEGORIES_ICON . '<br>' . tep_draw_file_field('icon'));
        $contents[] = array('text' => '<br>' . TEXT_SORT_ORDER . '<br>' . tep_draw_input_field('sort_order', '', 'size="2"'));
        $contents[] = array('align' => 'center', 'text' => '<br>' . tep_image_submit('button_save.gif', IMAGE_SAVE) . ' <a href="' . tep_href_link(FILENAME_NEWS, 'cPath=' . $cPath) . '">' . tep_image_button('button_cancel.gif', IMAGE_CANCEL) . '</a>');
        break;
      case 'edit_news_categories':
        $heading[] = array('text' => '<b>' . TEXT_INFO_HEADING_EDIT_NEWS_CATEGORIES . '</b>');

        $contents = array('form' => tep_draw_form('news_categories', FILENAME_NEWS, 'action=update_news_categories&cPath=' . $cPath, 'post', 'enctype="multipart/form-data"') . tep_draw_hidden_field('news_categories_id', $cInfo->news_categories_id));
        $contents[] = array('text' => TEXT_EDIT_INTRO);

        $contents[] = array('text' => '<br>' . TEXT_EDIT_NEWS_CATEGORIES_NAME . '<br>' . tep_draw_input_field('news_categories_name', tep_get_news_categories_name($cInfo->news_categories_id)));
        $contents[] = array('text' => '<br>' . tep_image(DIR_WS_CATALOG_IMAGES . $cInfo->icon, $cInfo->news_categories_name) . '<br>' . DIR_WS_CATALOG_IMAGES . '<br><b>' . $cInfo->icon . '</b>');
        $contents[] = array('text' => '<br>' . TEXT_EDIT_NEWS_CATEGORIES_ICON . '<br>' . tep_draw_file_field('icon'));
        $contents[] = array('text' => '<br>' . TEXT_EDIT_SORT_ORDER . '<br>' . tep_draw_input_field('sort_order', $cInfo->sort_order, 'size="2"'));
        $contents[] = array('align' => 'center', 'text' => '<br>' . tep_image_submit('button_save.gif', IMAGE_SAVE) . ' <a href="' . tep_href_link(FILENAME_NEWS, 'cPath=' . $cPath . '&cID=' . $cInfo->news_categories_id) . '">' . tep_image_button('button_cancel.gif', IMAGE_CANCEL) . '</a>');
        break;
      case 'delete_news_categories':
        $heading[] = array('text' => '<b>' . TEXT_INFO_HEADING_DELETE_NEWS_CATEGORIES . '</b>');

        $contents = array('form' => tep_draw_form('news_categories', FILENAME_NEWS, 'action=delete_news_categories_confirm&cPath=' . $cPath) . tep_draw_hidden_field('news_categories_id', $cInfo->news_categories_id));
        $contents[] = array('text' => TEXT_DELETE_NEWS_CATEGORIES_INTRO);
        $contents[] = array('text' => '<br><b>' . $cInfo->news_categories_name . '</b>');
        if ($cInfo->childs_count > 0) $contents[] = array('text' => '<br>' . sprintf(TEXT_DELETE_WARNING_CHILDS, $cInfo->childs_count));
        if ($cInfo->news_count > 0) $contents[] = array('text' => '<br>' . sprintf(TEXT_DELETE_WARNING_PRODUCTS, $cInfo->news_count));
        $contents[] = array('align' => 'center', 'text' => '<br>' . tep_image_submit('button_delete.gif', IMAGE_DELETE) . ' <a href="' . tep_href_link(FILENAME_NEWS, 'cPath=' . $cPath . '&cID=' . $cInfo->news_categories_id) . '">' . tep_image_button('button_cancel.gif', IMAGE_CANCEL) . '</a>');
        break;
      case 'move_news_categories':
        $heading[] = array('text' => '<b>' . TEXT_INFO_HEADING_MOVE_NEWS_CATEGORIES . '</b>');

        $contents = array('form' => tep_draw_form('news', FILENAME_NEWS, 'action=move_news_categories_confirm&cPath=' . $cPath) . tep_draw_hidden_field('news_categories_id', $cInfo->news_categories_id));
        $contents[] = array('text' => sprintf(TEXT_MOVE_NEWS_CATEGORIES_INTRO, $cInfo->news_categories_name));
        $contents[] = array('text' => '<br>' . sprintf(TEXT_MOVE, $cInfo->news_categories_name) . '<br>' . tep_draw_pull_down_menu('move_to_news_categories_id', tep_get_news_categories_tree(), $current_news_categories_id));
        $contents[] = array('align' => 'center', 'text' => '<br>' . tep_image_submit('button_move.gif', IMAGE_MOVE) . ' <a href="' . tep_href_link(FILENAME_NEWS, 'cPath=' . $cPath . '&cID=' . $cInfo->news_categories_id) . '">' . tep_image_button('button_cancel.gif', IMAGE_CANCEL) . '</a>');
        break;
      case 'delete_news':
        $heading[] = array('text' => '<b>' . TEXT_INFO_HEADING_DELETE_NEWS . '</b>');

        $contents = array('form' => tep_draw_form('news', FILENAME_NEWS, 'action=delete_news_confirm&cPath=' . $cPath) . tep_draw_hidden_field('news_id', $nInfo->news_id));
        $contents[] = array('text' => TEXT_DELETE_NEWS_INTRO);
        $contents[] = array('text' => '<br><b>' . $nInfo->news_title . '</b>');

        $contents[] = array('align' => 'center', 'text' => '<br>' . tep_image_submit('button_delete.gif', IMAGE_DELETE) . ' <a href="' . tep_href_link(FILENAME_NEWS, 'cPath=' . $cPath . '&nID=' . $nInfo->news_id) . '">' . tep_image_button('button_cancel.gif', IMAGE_CANCEL) . '</a>');
        break;
      case 'move_news':
        $heading[] = array('text' => '<b>' . TEXT_INFO_HEADING_MOVE_NEWS . '</b>');

        $contents = array('form' => tep_draw_form('news', FILENAME_NEWS, 'action=move_news_confirm&cPath=' . $cPath) . tep_draw_hidden_field('news_id', $nInfo->news_id));
        $contents[] = array('text' => sprintf(TEXT_MOVE_NEWS_INTRO, $nInfo->news_title));
        $contents[] = array('text' => '<br>' . TEXT_INFO_CURRENT_NEWS_CATEGORIES . '<br><b>' . tep_output_generated_news_categories_path($nInfo->news_id, 'news') . '</b>');
        $contents[] = array('text' => '<br>' . sprintf(TEXT_MOVE, $nInfo->news_title) . '<br>' . tep_draw_pull_down_menu('move_to_news_categories_id', tep_get_news_categories_tree(), $current_news_categories_id));
        $contents[] = array('align' => 'center', 'text' => '<br>' . tep_image_submit('button_move.gif', IMAGE_MOVE) . ' <a href="' . tep_href_link(FILENAME_NEWS, 'cPath=' . $cPath . '&nID=' . $nInfo->news_id) . '">' . tep_image_button('button_cancel.gif', IMAGE_CANCEL) . '</a>');
        break;
//      case 'copy_to':
//        $heading[] = array('text' => '<b>' . TEXT_INFO_HEADING_COPY_TO . '</b>');
//
//        $contents = array('form' => tep_draw_form('copy_to', FILENAME_NEWS, 'action=copy_to_confirm&cPath=' . $cPath) . tep_draw_hidden_field('news_id', $pInfo->news_id));
//        $contents[] = array('text' => TEXT_INFO_COPY_TO_INTRO);
//        $contents[] = array('text' => '<br>' . TEXT_INFO_CURRENT_news . '<br><b>' . tep_output_generated_news_path($pInfo->news_id, 'product') . '</b>');
//        $contents[] = array('text' => '<br>' . TEXT_news . '<br>' . tep_draw_pull_down_menu('news_id', tep_get_news_tree(), $current_news_id));
//        $contents[] = array('text' => '<br>' . TEXT_HOW_TO_COPY . '<br>' . tep_draw_radio_field('copy_as', 'link', true) . ' ' . TEXT_COPY_AS_LINK . '<br>' . tep_draw_radio_field('copy_as', 'duplicate') . ' ' . TEXT_COPY_AS_DUPLICATE);
//        $contents[] = array('align' => 'center', 'text' => '<br>' . tep_image_submit('button_copy.gif', IMAGE_COPY) . ' <a href="' . tep_href_link(FILENAME_NEWS, 'cPath=' . $cPath . '&nID=' . $pInfo->news_id) . '">' . tep_image_button('button_cancel.gif', IMAGE_CANCEL) . '</a>');
//        break;
      default:
        if ($rows > 0) {
          if (isset($cInfo) && is_object($cInfo)) { // news info box contents
            $news_categories_path_string = '';
            $news_categories_path = tep_generate_news_categories_path($cInfo->news_categories_id);
            for ($i=(sizeof($news_categories_path[0])-1); $i>0; $i--) {
              $news_categories_path_string .= $news_categories_path[0][$i]['id'] . '_';
            }
            $news_categories_path_string = substr($news_categories_path_string, 0, -1);

            $heading[] = array('text' => '<b>' . $cInfo->news_categories_name . '</b>');

            $contents[] = array('align' => 'center', 'text' => '<a href="' . tep_href_link(FILENAME_NEWS, 'cPath=' . $news_categories_path_string . '&cID=' . $cInfo->news_categories_id . '&action=edit_news_categories') . '">' . tep_image_button('button_edit.gif', IMAGE_EDIT) . '</a> <a href="' . tep_href_link(FILENAME_NEWS, 'cPath=' . $news_categories_path_string . '&cID=' . $cInfo->news_categories_id . '&action=delete_news_categories') . '">' . tep_image_button('button_delete.gif', IMAGE_DELETE) . '</a> <a href="' . tep_href_link(FILENAME_NEWS, 'cPath=' . $news_categories_path_string . '&cID=' . $cInfo->news_categories_id . '&action=move_news_categories') . '">' . tep_image_button('button_move.gif', IMAGE_MOVE) . '</a>');
            $contents[] = array('text' => '<br>' . TEXT_DATE_ADDED . ' ' . tep_date_short($cInfo->date_added));
            
            $contents[] = array('text' => '<br>' . TEXT_SUBNEWSCATEGORIES . ' ' . $cInfo->childs_count . '<br>' . TEXT_NEWS . ' ' . $cInfo->news_count);
          } elseif (isset($nInfo) && is_object($nInfo)) { // product info box contents
            $heading[] = array('text' => '<b>' . tep_get_news_title($nInfo->news_id) . '</b>');

            $contents[] = array('align' => 'center', 'text' => '<a href="' . tep_href_link(FILENAME_NEWS, 'cPath=' . $cPath . '&nID=' . $nInfo->news_id . '&action=new_news') . '">' . tep_image_button('button_edit.gif', IMAGE_EDIT) . '</a> <a href="' . tep_href_link(FILENAME_NEWS, 'cPath=' . $cPath . '&nID=' . $nInfo->news_id . '&action=delete_news') . '">' . tep_image_button('button_delete.gif', IMAGE_DELETE) . '</a> <a href="' . tep_href_link(FILENAME_NEWS, 'cPath=' . $cPath . '&nID=' . $nInfo->news_id . '&action=move_news') . '">');
            $contents[] = array('text' => '<br>' . TEXT_DATE_ADDED . ' ' . tep_date_short($nInfo->date_added));
          }
        } else { // create news/product info
          $heading[] = array('text' => '<b>' . EMPTY_NEWS_CATEGORIES . '</b>');

          $contents[] = array('text' => TEXT_NO_CHILD_NEWS_CATEGORIES_OR_NEWS);
        }
        break;
    }

    if ( (tep_not_null($heading)) && (tep_not_null($contents)) ) {
      echo '            <td width="25%" valign="top">' . "\n";

      $box = new box;
      echo $box->infoBox($heading, $contents);

      echo '            </td>' . "\n";
    }
?>
          </tr>
        </table></td>
      </tr>
    </table>
<?php
  }
?>
    </td>
<!-- body_text_eof //-->
  </tr>
</table>
<!-- body_eof //-->

<!-- footer //-->
<?php require(DIR_WS_INCLUDES . 'footer.php'); ?>
<!-- footer_eof //-->
<br>
</body>
</html>
<?php require(DIR_WS_INCLUDES . 'application_bottom.php'); ?>
