<?php
/*
 * Created on Apr 10, 2010
 *
 * To change the template for this generated file go to
 * Window - Preferences - PHPeclipse - PHP - Code Templates
 */

define('HEADING_TITLE', 'Kiến Thức');
define('HEADING_TITLE_SEARCH', 'Search:');
define('HEADING_TITLE_GOTO', 'Go To:');

define('TABLE_HEADING_ID', 'ID');
define('TABLE_HEADING_NEWS_CATEGORIES', 'Danh muc Kien Thuc');
define('TABLE_HEADING_ACTION', 'Action');
define('TABLE_HEADING_STATUS', 'Status');

define('TEXT_NEW_NEWS', 'New news in &quot;%s&quot;');
define('TEXT_NEWS_CATEGORIES', 'News Categories:');
define('TEXT_SUBNEWSCATEGORIES', 'SubNews categories:');
define('TEXT_NEWS', 'News:');
define('TEXT_DATE_ADDED', 'Date Added:');
define('TEXT_IMAGE_NONEXISTENT', 'IMAGE DOES NOT EXIST');
define('TEXT_NO_CHILD_NEWS_CATEGORIES_OR_NEWS', 'Please insert a new news_category or news in this level.');
define('TEXT_NEWS_MORE_INFORMATION', 'For more information, please visit this NEWS <a href="http://%s" target="blank"><u>webpage</u></a>.');
define('TEXT_NEWS_DATE_ADDED', 'This product was added to our catalog on %s.');

define('TEXT_EDIT_INTRO', 'Please make any necessary changes');
define('TEXT_EDIT_NEWS_CATEGORIES_ID', 'NewsCategory ID:');
define('TEXT_EDIT_NEWS_CATEGORIES_NAME', 'NewsCategory Name:');
define('TEXT_EDIT_NEWS_CATEGORIES_IMAGE', 'NewsCategory Image:');
define('TEXT_EDIT_NEWS_CATEGORIES_ICON', 'NewsCategory Icon:');
define('TEXT_EDIT_SORT_ORDER', 'Sort Order:');

define('TEXT_INFO_COPY_TO_INTRO', 'Please choose a new category you wish to copy this product to');
define('TEXT_INFO_CURRENT_NEWS_CATEGORIES', 'Current NewsCategories:');

define('TEXT_INFO_HEADING_NEW_NEWS_CATEGORIES', 'New NEWS_CATEGORIES');
define('TEXT_INFO_HEADING_EDIT_NEWS_CATEGORIES', 'Edit NEWS_CATEGORIES');
define('TEXT_INFO_HEADING_DELETE_NEWS_CATEGORIES', 'Delete NEWS_CATEGORIES');
define('TEXT_INFO_HEADING_MOVE_NEWS_CATEGORIES', 'Move NEWS_CATEGORIES');
define('TEXT_INFO_HEADING_DELETE_PRODUCT', 'Delete Product');
define('TEXT_INFO_HEADING_MOVE_PRODUCT', 'Move Product');
define('TEXT_INFO_HEADING_COPY_TO', 'Copy To');

define('TEXT_DELETE_NEWS_CATEGORIES_INTRO', 'Are you sure you want to delete this NEWS_CATEGORIES?');
define('TEXT_DELETE_NEWS_INTRO', 'Are you sure you want to permanently delete this NEWS?');

define('TEXT_DELETE_WARNING_CHILDS', '<b>WARNING:</b> There are %s (child-)categories still linked to this NEWS_CATEGORIES!');
define('TEXT_DELETE_WARNING_NEWS', '<b>WARNING:</b> There are %s NEWS still linked to this NEWS_CATEGORIES!');

define('TEXT_MOVE_NEWS_INTRO', 'Please select which NEWS_CATEGORIES you wish <b>%s</b> to reside in');
define('TEXT_MOVE_NEWS_CATEGORIES_INTRO', 'Please select which NEWS_CATEGORIES you wish <b>%s</b> to reside in');
define('TEXT_MOVE', 'Move <b>%s</b> to:');

define('TEXT_NEW_NEWS_CATEGORIES_INTRO', 'Please fill out the following information for the new NEWS_CATEGORIES');
define('TEXT_NEWS_CATEGORIES_NAME', 'NEWS_CATEGORIES Name:');
define('TEXT_NEWS_CATEGORIES_IMAGE', 'NEWS_CATEGORIES Image:');
define('TEXT_NEWS_CATEGORIES_ICON', 'NEWS_CATEGORIES Icon:');
define('TEXT_SORT_ORDER', 'Sort Order:');

define('TEXT_NEWS_STATUS', 'NEWS Status:');

define('TEXT_NEWS_CHECKED', 'Admin checked');
define('TEXT_NEWS_UNCHECKED', 'Admin unchecked');
define('TEXT_NEWS_TITLE', 'NEWS Title:');
define('TEXT_NEWS_ICON', 'NEWS ICON:');
define('TEXT_NEWS_CONTENT', 'NEWS content:');

define('EMPTY_NEWS_CATEGORIES', 'Empty NEWS_CATEGORIES');

define('TEXT_HOW_TO_COPY', 'Copy Method:');
define('TEXT_COPY_AS_LINK', 'Link product');
define('TEXT_COPY_AS_DUPLICATE', 'Duplicate product');

define('ERROR_CANNOT_LINK_TO_SAME_NEWS_CATEGORIES', 'Error: Can not link NEWS in the same NEWS_CATEGORIES.');
define('ERROR_CATALOG_IMAGE_DIRECTORY_NOT_WRITEABLE', 'Error: Catalog images directory is not writeable: ' . DIR_FS_CATALOG_IMAGES);
define('ERROR_CATALOG_IMAGE_DIRECTORY_DOES_NOT_EXIST', 'Error: Catalog images directory does not exist: ' . DIR_FS_CATALOG_IMAGES);
define('ERROR_CANNOT_MOVE_NEWS_CATEGORIES_TO_PARENT', 'Error: NEWS_CATEGORIES cannot be moved into child NEWS_CATEGORIES.');
?>

