<?php
/*
  $Id: database.php 1739 2007-12-20 00:52:16Z hpdl $

  osCommerce, Open Source E-Commerce Solutions
  http://www.oscommerce.com

  Copyright (c) 2007 osCommerce

  Released under the GNU General Public License
*/

  function db_connect($server = DB_Host, $username = DB_User, $password = DB_Pass, $database = DB_Name, $link = 'db_link') {
    global $$link;

    if (USE_PCONNECT == 'true') {
      $$link = mysql_pconnect($server, $username, $password);
    } else {
      $$link = mysql_connect($server, $username, $password);
    }

    if ($$link) mysql_select_db($database);

    return $$link;
  }

  function db_close($link = 'db_link') {
    global $$link;

    return mysql_close($$link);
  }

  function db_error($query, $errno, $error) {
    die('<font color="#000000"><b>' . $errno . ' - ' . $error . '<br><br>' . $query . '<br><br><small><font color="#ff0000">[TEP STOP]</font></small><br><br></b></font>');
  }

  function db_query($query, $link = 'db_link') {
    global $$link;

    if (defined('STORE_DB_TRANSACTIONS') && (STORE_DB_TRANSACTIONS == 'true')) {
      error_log('QUERY ' . $query . "\n", 3, STORE_PAGE_PARSE_TIME_LOG);
    }

    $result = mysql_query($query, $$link) or db_error($query, mysql_errno(), mysql_error());

    if (defined('STORE_DB_TRANSACTIONS') && (STORE_DB_TRANSACTIONS == 'true')) {
       $result_error = mysql_error();
       error_log('RESULT ' . $result . ' ' . $result_error . "\n", 3, STORE_PAGE_PARSE_TIME_LOG);
    }

    return $result;
  }

  function db_perform($table, $data, $action = 'insert', $parameters = '', $link = 'db_link') {
    reset($data);
    if ($action == 'insert') {
      $query = 'insert into ' . $table . ' (';
      while (list($columns, ) = each($data)) {
        $query .= $columns . ', ';
      }
      $query = substr($query, 0, -2) . ') values (';
      reset($data);
      while (list(, $value) = each($data)) {
        switch ((string)$value) {
          case 'now()':
            $query .= 'now(), ';
            break;
          case 'null':
            $query .= 'null, ';
            break;
          default:
            $query .= '\'' . db_input($value) . '\', ';
            break;
        }
      }
      $query = substr($query, 0, -2) . ')';
    } elseif ($action == 'update') {
      $query = 'update ' . $table . ' set ';
      while (list($columns, $value) = each($data)) {
        switch ((string)$value) {
          case 'now()':
            $query .= $columns . ' = now(), ';
            break;
          case 'null':
            $query .= $columns .= ' = null, ';
            break;
          default:
            $query .= $columns . ' = \'' . db_input($value) . '\', ';
            break;
        }
      }
      $query = substr($query, 0, -2) . ' where ' . $parameters;
    }

    return db_query($query, $link);
  }

  function db_fetch_array($db_query) {
    return mysql_fetch_array($db_query, MYSQL_ASSOC);
  }

  function db_fetch_all_array($db_query)
  {
    $result = array();
    while ($row = mysql_fetch_array($db_query, MYSQL_ASSOC))
    {
      $result[] = $row;
    }

    return $result;
  }

  function db_num_rows($db_query) {
    return mysql_num_rows($db_query);
  }

  function db_data_seek($db_query, $row_number) {
    return mysql_data_seek($db_query, $row_number);
  }

  function db_insert_id($link = 'db_link') {
    global $$link;

    return mysql_insert_id($$link);
  }

  function db_free_result($db_query) {
    return mysql_free_result($db_query);
  }

  function db_fetch_fields($db_query) {
    return mysql_fetch_field($db_query);
  }

  function db_output($string) {
    return htmlspecialchars($string);
  }

  function db_input($string, $link = 'db_link') {
    global $$link;

    if (function_exists('mysql_real_escape_string')) {
      return mysql_real_escape_string($string, $$link);
    } elseif (function_exists('mysql_escape_string')) {
      return mysql_escape_string($string);
    }

    return addslashes($string);
  }

  function db_prepare_input($string)
  {
    if (is_string($string))
    {
      return trim(sanitize_string(stripslashes($string)));
    }
    elseif (is_array($string))
    {
      reset($string);
      while (list($key, $value) = each($string))
      {
        $string[$key] = db_prepare_input($value);
      }
      return $string;
    }
    else
    {
      return $string;
    }
  }
?>
