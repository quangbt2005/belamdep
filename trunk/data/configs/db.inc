<?php
/**************************************************************************************************/
/* Created on Nov 29, 2008                                                                        */
/**************************************************************************************************/
/* ---------------------------------------------------------------------------------------------- */
/* 'ORDER BY' statement is mandatory                                                              */
/* ---------------------------------------------------------------------------------------------- */
define( 'ORDER_BY_FLG', 'Off' );
/* ---------------------------------------------------------------------------------------------- */
/* Is 'SELECT *' statement allowed ?                                                              */
/* 'Off' = allow                                                                                  */
/* ---------------------------------------------------------------------------------------------- */
define( 'WILD_CARD_FLG', 'Off' );
/* ---------------------------------------------------------------------------------------------- */
/* Retry once again if fail to connect to DB                                                      */
/* ---------------------------------------------------------------------------------------------- */
define( 'RE_TRY_FLG', 'On' );
//------------------------------------------------------------------------------------------------//
// Define list of tables
//------------------------------------------------------------------------------------------------//
define( 'TBL_CAT', 'categories' );
define( 'TBL_PRODUCTS', 'products' );
define( 'TBL_CUSTOMERS', 'customers' );
define( 'TBL_USERS', 'users' );
define( 'TBL_CAT_DES', 'categories_description' );
define( 'TBL_PRO2CAT', 'products_to_categories' );
define( 'TBL_SPECCAT', 'special_cat' );
define( 'TBL_SALEOFF', 'specials' );
define( 'TBL_PRO_DES', 'products_description' );
define( 'TBL_ORDERS', 'orders' );
define( 'TBL_ORDERS_PRODUCTS', 'orders_products' );
define( 'TBL_ORDERS_STATUS', 'orders_status' );
define( 'TBL_ORDERS_STATUS_HISTORY', 'orders_status_history' );
define( 'TBL_ORDERS_TOTAL', 'orders_total' );
define( 'TBL_ADDRESS', 'address_book' );
define( 'TBL_NEWS_CAT', 'news_categories' );
define( 'TBL_NEWS', 'news' );
define( 'TBL_ADMIN', 'administrators' );
//------------------------------------------------------------------------------------------------//
// necessary constants for dnp
//------------------------------------------------------------------------------------------------//
define( 'DB_Host', 'localhost' );
define( 'DB_Name', 'belamdep_osc' );
define( 'DB_User', 'belamdep_quangbt' );
define( 'DB_Pass', 'mi@1lauqua' );
?>
