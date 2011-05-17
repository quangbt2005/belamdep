<?php
  // For production host --------------------------------------------------------------------------
  /*define('HTTP_SERVER', 'http://belamdep.com');
  define('HTTP_CATALOG_SERVER', 'http://belamdep.com');
  define('HTTPS_CATALOG_SERVER', 'http://belamdep.com');
  define('DIR_FS_DOCUMENT_ROOT', '/home/belamdep/public_html/');
  define('DIR_FS_ADMIN', '/home/belamdep/public_html/bldadmin/');
  define('DIR_FS_CATALOG', '/home/belamdep/public_html/');*/
  // For localhost --------------------------------------------------------------------------------
  define('HTTP_SERVER', 'http://localhost:8081');
  define('HTTP_CATALOG_SERVER', 'http://localhost:8081');
  define('HTTPS_CATALOG_SERVER', 'http://localhost:8081');
  define('DIR_FS_DOCUMENT_ROOT', 'd:/WWW/');
  define('DIR_FS_ADMIN', DIR_FS_DOCUMENT_ROOT . 'baby/bldadmin/');
  define('DIR_FS_CATALOG', DIR_FS_DOCUMENT_ROOT . 'baby/');
  // Common ---------------------------------------------------------------------------------------
  define('ENABLE_SSL_CATALOG', 'false');
  define('DIR_WS_ADMIN', '/bldadmin/');
  define('DIR_WS_CATALOG', '/');
  define('DIR_WS_IMAGES', 'images/');
  define('DIR_WS_ICONS', DIR_WS_IMAGES . 'icons/');
  define('DIR_WS_CATALOG_IMAGES', DIR_WS_CATALOG . 'images/');
  define('DIR_WS_INCLUDES', 'includes/');
  define('DIR_WS_BOXES', DIR_WS_INCLUDES . 'boxes/');
  define('DIR_WS_FUNCTIONS', DIR_WS_INCLUDES . 'functions/');
  define('DIR_WS_CLASSES', DIR_WS_INCLUDES . 'classes/');
  define('DIR_WS_MODULES', DIR_WS_INCLUDES . 'modules/');
  define('DIR_WS_LANGUAGES', DIR_WS_INCLUDES . 'languages/');
  define('DIR_WS_CATALOG_LANGUAGES', DIR_WS_CATALOG . 'includes/languages/');
  define('DIR_FS_CATALOG_LANGUAGES', DIR_FS_CATALOG . 'includes/languages/');
  define('DIR_FS_CATALOG_IMAGES', DIR_FS_CATALOG . 'images/');
  define('DIR_FS_CATALOG_MODULES', DIR_FS_CATALOG . 'includes/modules/');
  define('DIR_FS_BACKUP', DIR_FS_ADMIN . 'backups/');

  define('DB_SERVER', 'localhost');
  define('DB_SERVER_USERNAME', 'belamdep_quangbt');
  define('DB_SERVER_PASSWORD', 'mi@1lauqua');
  define('DB_DATABASE', 'belamdep_osc');
  define('USE_PCONNECT', 'false');
//  define('STORE_SESSIONS', 'mysql');
  define('STORE_SESSIONS', '');
?>