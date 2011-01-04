<?php
/*
 * Created on May 14, 2010
 *
 * To change the template for this generated file go to
 * Window - Preferences - PHPeclipse - PHP - Code Templates
 */
// ---------------------------------------------------------------------------------------------- //
function d()
{
  die("123456");
}
// ---------------------------------------------------------------------------------------------- //
function p($v)
{
  echo('<pre>');
  print_r($v);
  echo('</pre>');
}
// ---------------------------------------------------------------------------------------------- //
function pd($v)
{
  echo('<pre>');
  print_r($v);
  echo('</pre>');
  d();
}
// ---------------------------------------------------------------------------------------------- //
function e($v)
{
  echo $v . '<br>';
}
// ---------------------------------------------------------------------------------------------- //
function Generate_Token()
{
  $time   = date("YmdHis");
  $result = md5( $time );

  return $result;
}
// ---------------------------------------------------------------------------------------------- //
function make_seed()
{
  list($usec, $sec) = explode(' ', microtime());
  return (float) $sec + ((float) $usec * 100000);
}
// ---------------------------------------------------------------------------------------------- //
function parse_input_field_data($data, $parse)
{
    return strtr(trim($data), $parse);
}
// ---------------------------------------------------------------------------------------------- //
function output_string($string, $translate = false, $protected = false)
{
    if ($protected == true) {
      return htmlspecialchars($string);
    } else {
      if ($translate == false) {
        return parse_input_field_data($string, array('"' => '&quot;'));
      } else {
        return parse_input_field_data($string, $translate);
      }
    }
}
// ---------------------------------------------------------------------------------------------- //
function output_string_protected($string)
{
    return output_string($string, false, true);
}
// ---------------------------------------------------------------------------------------------- //
function sanitize_string($string)
{
    $string = ereg_replace(' +', ' ', trim($string));

    return preg_replace("/[<>]/", '_', $string);
}
// ---------------------------------------------------------------------------------------------- //
// Break a word in a string if it is longer than a specified length ($len)
function break_string($string, $len, $break_char = '-')
{
    $l = 0;
    $output = '';
    for ($i=0, $n=strlen($string); $i<$n; $i++) {
      $char = substr($string, $i, 1);
      if ($char != ' ') {
        $l++;
      } else {
        $l = 0;
      }
      if ($l > $len) {
        $l = 1;
        $output .= $break_char;
      }
      $output .= $char;
    }

    return $output;
}
// ---------------------------------------------------------------------------------------------- //
// Return all HTTP GET variables, except those passed as a parameter
function get_all_get_params($exclude_array = '')
{
    global $HTTP_GET_VARS;

    if (!is_array($exclude_array)) $exclude_array = array();

    $get_url = '';
    if (is_array($HTTP_GET_VARS) && (sizeof($HTTP_GET_VARS) > 0)) {
      reset($HTTP_GET_VARS);
      while (list($key, $value) = each($HTTP_GET_VARS)) {
        if ( (strlen($value) > 0) && ($key != session_name()) && ($key != 'error') && (!in_array($key, $exclude_array)) && ($key != 'x') && ($key != 'y') ) {
          $get_url .= $key . '=' . rawurlencode(stripslashes($value)) . '&';
        }
      }
    }

    return $get_url;
}
// ---------------------------------------------------------------------------------------------- //
// Returns the clients browser
function browser_detect()
{
    global $_SERVER;
    $http_user_agent = $_SERVER['HTTP_USER_AGENT'];

    if(stripos($http_user_agent, 'Chrome') !== FALSE)  return 'chrome';
    if(stripos($http_user_agent, 'Safari') !== FALSE)  return 'safari';
    if(stripos($http_user_agent, 'Firefox') !== FALSE) return 'firefox';
    if(stripos($http_user_agent, 'MSIE') !== FALSE)    return 'ie';
    if(stripos($http_user_agent, 'Opera') !== FALSE)   return 'opera';

    return '';
}
// ---------------------------------------------------------------------------------------------- //
// Wrapper function for round()
function osc_round($number, $precision)
{
    if (strpos($number, '.') && (strlen(substr($number, strpos($number, '.')+1)) > $precision)) {
      $number = substr($number, 0, strpos($number, '.') + 1 + $precision + 1);

      if (substr($number, -1) >= 5) {
        if ($precision > 1) {
          $number = substr($number, 0, -1) + ('0.' . str_repeat(0, $precision-1) . '1');
        } elseif ($precision == 1) {
          $number = substr($number, 0, -1) + 0.1;
        } else {
          $number = substr($number, 0, -1) + 1;
        }
      } else {
        $number = substr($number, 0, -1);
      }
    }

    return $number;
}
// ---------------------------------------------------------------------------------------------- //
// Parse search string into indivual objects
function parse_search_string($search_str = '', &$objects)
{
    $search_str = trim(strtolower($search_str));

    // Break up $search_str on whitespace; quoted string will be reconstructed later
    $pieces = split('[[:space:]]+', $search_str);
    $objects = array();
    $tmpstring = '';
    $flag = '';

    for ($k=0; $k<count($pieces); $k++) {
      while (substr($pieces[$k], 0, 1) == '(') {
        $objects[] = '(';
        if (strlen($pieces[$k]) > 1) {
          $pieces[$k] = substr($pieces[$k], 1);
        } else {
          $pieces[$k] = '';
        }
      }

      $post_objects = array();

      while (substr($pieces[$k], -1) == ')')  {
        $post_objects[] = ')';
        if (strlen($pieces[$k]) > 1) {
          $pieces[$k] = substr($pieces[$k], 0, -1);
        } else {
          $pieces[$k] = '';
        }
      }

      // Check individual words

      if ( (substr($pieces[$k], -1) != '"') && (substr($pieces[$k], 0, 1) != '"') ) {
        $objects[] = trim($pieces[$k]);

        for ($j=0; $j<count($post_objects); $j++) {
          $objects[] = $post_objects[$j];
        }
      }
      else
      {
        /*
         * This means that the $piece is either the beginning or the end of a string.
         * So, we'll slurp up the $pieces and stick them together until we get to the
         * end of the string or run out of pieces.
        */

        // Add this word to the $tmpstring, starting the $tmpstring
        $tmpstring = trim(ereg_replace('"', ' ', $pieces[$k]));

        // Check for one possible exception to the rule. That there is a single quoted word.
        if (substr($pieces[$k], -1 ) == '"')
        {
        // Turn the flag off for future iterations
          $flag = 'off';

          $objects[] = trim($pieces[$k]);

          for ($j=0; $j<count($post_objects); $j++) {
            $objects[] = $post_objects[$j];
          }

          unset($tmpstring);

          // Stop looking for the end of the string and move onto the next word.
          continue;
        }

        // Otherwise, turn on the flag to indicate no quotes have been found attached to this word in the string.
        $flag = 'on';

        // Move on to the next word
        $k++;

        // Keep reading until the end of the string as long as the $flag is on

        while ( ($flag == 'on') && ($k < count($pieces)) ) {
          while (substr($pieces[$k], -1) == ')') {
            $post_objects[] = ')';
            if (strlen($pieces[$k]) > 1) {
              $pieces[$k] = substr($pieces[$k], 0, -1);
            } else {
              $pieces[$k] = '';
            }
          }

          // If the word doesn't end in double quotes, append it to the $tmpstring.
          if (substr($pieces[$k], -1) != '"') {
            // Tack this word onto the current string entity
            $tmpstring .= ' ' . $pieces[$k];

            // Move on to the next word
            $k++;
            continue;
          } else {
            /* If the $piece ends in double quotes, strip the double quotes, tack the
               $piece onto the tail of the string, push the $tmpstring onto the $haves,
               kill the $tmpstring, turn the $flag "off", and return.
            */
            $tmpstring .= ' ' . trim(ereg_replace('"', ' ', $pieces[$k]));

            // Push the $tmpstring onto the array of stuff to search for
            $objects[] = trim($tmpstring);

            for ($j=0; $j<count($post_objects); $j++) {
              $objects[] = $post_objects[$j];
            }

            unset($tmpstring);

            // Turn off the flag to exit the loop
            $flag = 'off';
          }
        }
      }
    }

    // add default logical operators if needed
    $temp = array();
    for($i=0; $i<(count($objects)-1); $i++) {
      $temp[] = $objects[$i];
      if ( ($objects[$i] != 'and') &&
           ($objects[$i] != 'or') &&
           ($objects[$i] != '(') &&
           ($objects[$i+1] != 'and') &&
           ($objects[$i+1] != 'or') &&
           ($objects[$i+1] != ')') ) {
        $temp[] = ADVANCED_SEARCH_DEFAULT_OPERATOR;
      }
    }
    $temp[] = $objects[$i];
    $objects = $temp;

    $keyword_count = 0;
    $operator_count = 0;
    $balance = 0;
    for($i=0; $i<count($objects); $i++) {
      if ($objects[$i] == '(') $balance --;
      if ($objects[$i] == ')') $balance ++;
      if ( ($objects[$i] == 'and') || ($objects[$i] == 'or') ) {
        $operator_count ++;
      } elseif ( ($objects[$i]) && ($objects[$i] != '(') && ($objects[$i] != ')') ) {
        $keyword_count ++;
      }
    }

    if ( ($operator_count < $keyword_count) && ($balance == 0) ) {
      return true;
    } else {
      return false;
    }
}
// ---------------------------------------------------------------------------------------------- //
// Check date
function osc_checkdate($date_to_check, $format_string, &$date_array)
{
    $separator_idx = -1;

    $separators = array('-', ' ', '/', '.');
    $month_abbr = array('jan','feb','mar','apr','may','jun','jul','aug','sep','oct','nov','dec');
    $no_of_days = array(31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31);

    $format_string = strtolower($format_string);

    if (strlen($date_to_check) != strlen($format_string)) {
      return false;
    }

    $size = sizeof($separators);
    for ($i=0; $i<$size; $i++) {
      $pos_separator = strpos($date_to_check, $separators[$i]);
      if ($pos_separator != false) {
        $date_separator_idx = $i;
        break;
      }
    }

    for ($i=0; $i<$size; $i++) {
      $pos_separator = strpos($format_string, $separators[$i]);
      if ($pos_separator != false) {
        $format_separator_idx = $i;
        break;
      }
    }

    if ($date_separator_idx != $format_separator_idx) {
      return false;
    }

    if ($date_separator_idx != -1) {
      $format_string_array = explode( $separators[$date_separator_idx], $format_string );
      if (sizeof($format_string_array) != 3) {
        return false;
      }

      $date_to_check_array = explode( $separators[$date_separator_idx], $date_to_check );
      if (sizeof($date_to_check_array) != 3) {
        return false;
      }

      $size = sizeof($format_string_array);
      for ($i=0; $i<$size; $i++) {
        if ($format_string_array[$i] == 'mm' || $format_string_array[$i] == 'mmm') $month = $date_to_check_array[$i];
        if ($format_string_array[$i] == 'dd') $day = $date_to_check_array[$i];
        if ( ($format_string_array[$i] == 'yyyy') || ($format_string_array[$i] == 'aaaa') ) $year = $date_to_check_array[$i];
      }
    } else {
      if (strlen($format_string) == 8 || strlen($format_string) == 9) {
        $pos_month = strpos($format_string, 'mmm');
        if ($pos_month != false) {
          $month = substr( $date_to_check, $pos_month, 3 );
          $size = sizeof($month_abbr);
          for ($i=0; $i<$size; $i++) {
            if ($month == $month_abbr[$i]) {
              $month = $i;
              break;
            }
          }
        } else {
          $month = substr($date_to_check, strpos($format_string, 'mm'), 2);
        }
      } else {
        return false;
      }

      $day = substr($date_to_check, strpos($format_string, 'dd'), 2);
      $year = substr($date_to_check, strpos($format_string, 'yyyy'), 4);
    }

    if (strlen($year) != 4) {
      return false;
    }

    if (!settype($year, 'integer') || !settype($month, 'integer') || !settype($day, 'integer')) {
      return false;
    }

    if ($month > 12 || $month < 1) {
      return false;
    }

    if ($day < 1) {
      return false;
    }

    if (is_leap_year($year)) {
      $no_of_days[1] = 29;
    }

    if ($day > $no_of_days[$month - 1]) {
      return false;
    }

    $date_array = array($year, $month, $day);

    return true;
}
// ---------------------------------------------------------------------------------------------- //
// Check if year is a leap year
function is_leap_year($year)
{
    if ($year % 100 == 0) {
      if ($year % 400 == 0) return true;
    } else {
      if (($year % 4) == 0) return true;
    }

    return false;
}
// ---------------------------------------------------------------------------------------------- //
// Get the number of times a word/character is present in a string
function word_count($string, $needle)
{
    $temp_array = split($needle, $string);

    return sizeof($temp_array);
}
// ---------------------------------------------------------------------------------------------- //
function create_random_value($length, $type = 'mixed')
{
    if ( ($type != 'mixed') && ($type != 'chars') && ($type != 'digits')) return false;

    $rand_value = '';
    while (strlen($rand_value) < $length) {
      if ($type == 'digits') {
        $char = rand(0,9);
      } else {
        $char = chr(rand(0,255));
      }
      if ($type == 'mixed') {
        if (eregi('^[a-z0-9]$', $char)) $rand_value .= $char;
      } elseif ($type == 'chars') {
        if (eregi('^[a-z]$', $char)) $rand_value .= $char;
      } elseif ($type == 'digits') {
        if (ereg('^[0-9]$', $char)) $rand_value .= $char;
      }
    }

    return $rand_value;
}
// ---------------------------------------------------------------------------------------------- //
function array_to_string($array, $exclude = '', $equals = '=', $separator = '&')
{
    if (!is_array($exclude)) $exclude = array();

    $get_string = '';
    if (sizeof($array) > 0) {
      while (list($key, $value) = each($array)) {
        if ( (!in_array($key, $exclude)) && ($key != 'x') && ($key != 'y') ) {
          $get_string .= $key . $equals . $value . $separator;
        }
      }
      $remove_chars = strlen($separator);
      $get_string = substr($get_string, 0, -$remove_chars);
    }

    return $get_string;
}
// ---------------------------------------------------------------------------------------------- //
function not_null($value)
{
    if (is_array($value)) {
      if (sizeof($value) > 0) {
        return true;
      } else {
        return false;
      }
    } else {
      if (($value != '') && (strtolower($value) != 'null') && (strlen(trim($value)) > 0)) {
        return true;
      } else {
        return false;
      }
    }
}
// ---------------------------------------------------------------------------------------------- //
// Return a random value
function osc_rand($min = null, $max = null)
{
    static $seeded;

    if (!isset($seeded)) {
      mt_srand((double)microtime()*1000000);
      $seeded = true;
    }

    if (isset($min) && isset($max)) {
      if ($min >= $max) {
        return $min;
      } else {
        return mt_rand($min, $max);
      }
    } else {
      return mt_rand();
    }
}
// ---------------------------------------------------------------------------------------------- //
function osc_setcookie($name, $value = '', $expire = 0, $path = '/', $domain = '', $secure = 0)
{
    setcookie($name, $value, $expire, $path, (not_null($domain) ? $domain : ''), $secure);
}
// ---------------------------------------------------------------------------------------------- //
function mailSMTP($from_name,$from,$to,$cc,$bcc,$subject,$message)
{
    include_once (LIB_PATH . "PHPMailer/class.phpmailer.php");
    $mail = new PHPMailer();

    $mail->IsSMTP();                                    // send via SMTP
    $mail->Host     = "server10.hostno1.vn";            // SMTP servers
    $mail->SMTPAuth = true;                             // turn on SMTP authentication
    $mail->Username = 'admin@belamdep.com';             // SMTP username
    $mail->Password = 'mi@1lau';                        // SMTP password

    $mail->From     = $from;
    $mail->FromName = $from_name;
    $mail->ClearAddresses();
    if(!empty($to)){
      if(is_array($to)){
        foreach($to as $to_addr){
          $mail->AddAddress($to_addr);
        }
      } else {
        $mail->AddAddress($to);
      }
    }

    if(!empty($cc)){
      if(is_array($cc)){
        foreach($cc as $cc_addr){
          $mail->AddCC($cc_addr);
        }
      } else {
        $mail->AddCC($cc);
      }
    }

    if(!empty($bcc)){
      if(is_array($bcc)){
        foreach($bcc as $bcc_addr){
          $mail->AddCC($bcc_addr);
        }
      } else {
        $mail->AddCC($bcc);
      }
    }
    $mail->WordWrap = 50;                              // set word wrap
    $mail->IsHTML(true);
    $mail->CharSet = "UTF-8";
    $mail->Subject  =  $subject;
    $mail->Body     =  $message;
    $ok = $mail->Send();
    //if($ok) echo 'phpmailer ok';
    //else
    //{
    //    echo 'phpmailer fail <br />';
    //    echo $mail->ErrorInfo . '<br />';
    //}
    $mail->SmtpClose();
    return $ok;
}

// ---------------------------------------------------------------------------------------------- //
// Recursively go through the newscategories and retreive all parent newscategories IDs
// TABLES: newscategories
function get_parent_news_categories(&$categories, $news_categories_id)
{
    $parent_categories_query = db_query("select parent_id from " . TABLE_NEWS_CATEGORIES . " where news_categories_id = '" . (int)$news_categories_id . "'");
    while ($parent_categories = db_fetch_array($parent_categories_query)) {
      if ($parent_categories['parent_id'] == 0) return true;
      $categories[sizeof($categories)] = $parent_categories['parent_id'];
      if ($parent_categories['parent_id'] != $news_categories_id) {
        get_parent_news_categories($categories, $parent_categories['parent_id']);
      }
    }
}

// ---------------------------------------------------------------------------------------------- //
// Construct a news_category path to the news
// TABLES: news
function get_news_path($news_id)
{
    $cPath = '';

    $category_query = db_query("select news_categories_id from " . TABLE_NEWS . " where news_id = '" . (int)$news_id . "' limit 1");
    if (db_num_rows($category_query)) {
      $category = db_fetch_array($category_query);

      $categories = array();
      get_parent_news_categories($categories, $category['news_categories_id']);

      $categories = array_reverse($categories);

      $cPath = implode('_', $categories);

      if (not_null($cPath)) $cPath .= '_';
      $cPath .= $category['news_categories_id'];
    }

    return $cPath;
}
// ---------------------------------------------------------------------------------------------- //
function build_ncpath()
{
    $cat_id = $_GET['ncPath'];
    if(is_numeric($cat_id))
    {
        $result = $cat_id;
        do
        {
            $query = 'SELECT parent_id FROM '. TABLE_NEWS_CATEGORIES.' WHERE news_categories_id=' . $cat_id;
            $query_result = db_query($query);
            $parent_id = db_fetch_array($query_result);
            $parent_id = $parent_id['parent_id'];

            if(!empty($parent_id))
            {
                $result = $parent_id . '_' . $result;
                $cat_id = $parent_id;
            }
            else
            {
                return $result;
            }
        }
        while(1);
    }

    return $cat_id;
}
// ---------------------------------------------------------------------------------------------- //
function get_news_title($news_id)
{
    $product_query = db_query("select news_title from " . TABLE_NEWS . " where news_id = '" . (int)$news_id . "'");
    $product = db_fetch_array($product_query);

    return $product['news_title'];
}
// ---------------------------------------------------------------------------------------------- //
function get_news_content($news_id)
{
    $product_query = db_query("select news_content from " . TABLE_NEWS . " where news_id = '" . (int)$news_id . "'");
    $product = db_fetch_array($product_query);

    return $product['news_content'];
}
// ---------------------------------------------------------------------------------------------- //
function get_news_icon($news_id)
{
    $product_query = db_query("select icon from " . TABLE_NEWS . " where news_id = '" . (int)$news_id . "'");
    $product = db_fetch_array($product_query);

    return $product['icon'];
}
// ---------------------------------------------------------------------------------------------- //
// get news categories tree
function get_news_categories_tree($parent_id = '0', $spacing = '', $exclude = '', $category_tree_array = '', $include_itself = false)
{
    if (!is_array($category_tree_array)) $category_tree_array = array();
    if ( (sizeof($category_tree_array) < 1) && ($exclude != '0') ) $category_tree_array[] = array('id' => '0', 'text' => TEXT_TOP);

    if ($include_itself) {
      $category_query = db_query("select nc.news_categories_name from " . TABLE_NEWS_CATEGORIES . " nc where nc.news_categories_id = '" . (int)$parent_id . "'");
      $category = db_fetch_array($category_query);
      $category_tree_array[] = array('id' => $parent_id, 'text' => $category['news_categories_name']);
    }

    $categories_query = db_query("select nc.news_categories_id, nc.news_categories_name, nc.parent_id from " . TABLE_NEWS_CATEGORIES . " nc where nc.parent_id = '" . (int)$parent_id . "' order by nc.sort_order, nc.news_categories_name");
    while ($categories = db_fetch_array($categories_query)) {
      if ($exclude != $categories['news_categories_id']) $category_tree_array[] = array('id' => $categories['news_categories_id'], 'text' => $spacing . $categories['news_categories_name']);
      $category_tree_array = get_news_categories_tree($categories['news_categories_id'], $spacing . '&nbsp;&nbsp;&nbsp;', $exclude, $category_tree_array);
    }

    return $category_tree_array;
}
// ---------------------------------------------------------------------------------------------- //
function generate_news_categories_path($id, $from = 'news', $categories_array = '', $index = 0)
{

    if (!is_array($categories_array)) $categories_array = array();

    {
      $category_query = db_query("select nc.news_categories_name, nc.parent_id from " . TABLE_NEWS_CATEGORIES . " nc where nc.news_categories_id = '" . (int)$id . "'");
      $category = db_fetch_array($category_query);
      $categories_array[$index][] = array('id' => $id, 'text' => $category['news_categories_name']);
      if ( (not_null($category['parent_id'])) && ($category['parent_id'] != '0') ) $categories_array = generate_news_categories_path($category['parent_id'], 'news', $categories_array, $index);
    }

    return $categories_array;
}
// ---------------------------------------------------------------------------------------------- //
function get_news_categories_path($current_category_id = '')
{
    global $cPath_array;

    if ($current_category_id == '') {
      $cPath_new = implode('_', $cPath_array);
    } else {
      if (sizeof($cPath_array) == 0) {
        $cPath_new = $current_category_id;
      } else {
        $cPath_new = '';
        $last_category_query = db_query("select parent_id from " . TABLE_NEWS_CATEGORIES . " where news_categories_id = '" . (int)$cPath_array[(sizeof($cPath_array)-1)] . "'");
        $last_category = db_fetch_array($last_category_query);

        $current_category_query = db_query("select parent_id from " . TABLE_NEWS_CATEGORIES . " where news_categories_id = '" . (int)$current_category_id . "'");
        $current_category = db_fetch_array($current_category_query);

        if ($last_category['parent_id'] == $current_category['parent_id']) {
          for ($i = 0, $n = sizeof($cPath_array) - 1; $i < $n; $i++) {
            $cPath_new .= '_' . $cPath_array[$i];
          }
        } else {
          for ($i = 0, $n = sizeof($cPath_array); $i < $n; $i++) {
            $cPath_new .= '_' . $cPath_array[$i];
          }
        }

        $cPath_new .= '_' . $current_category_id;

        if (substr($cPath_new, 0, 1) == '_') {
          $cPath_new = substr($cPath_new, 1);
        }
      }
    }

    return 'cPath=' . $cPath_new;
}
// ---------------------------------------------------------------------------------------------- //
function get_news_categories_name($category_id, $language_id)
{
    $category_query = db_query("select news_categories_name from " . TABLE_NEWS_CATEGORIES . " where news_categories_id = '" . (int)$category_id . "'");
    $category = db_fetch_array($category_query);

    return $category['news_categories_name'];
}
// ---------------------------------------------------------------------------------------------- //
function get_top_news_in_news_categories($category_id, $limit = '5')
{
  	 //get all subcategory of this category
  	 $news_query = db_query("select news_id, news_title, news_content, icon, news_categories_path from " . TABLE_NEWS . " where news_status='1' and news_categories_path like '%\_". $category_id ."\_%' order by date_added, sort_order limit 0," . $limit);
  	$news_array = array();
  	 while ($news = db_fetch_array($news_query))
  	 {
  	 	$news_array[] = array('news_id' => $news['news_id'],
  	 						'news_title' => $news['news_title'],
  	 						'news_content' => $news['news_content'],
  	 						'news_categories_path' => $news['news_categories_path'],
  	 						'icon' => $news['icon']	);
  	 }
  	 return $news_array;
}
// ---------------------------------------------------------------------------------------------- //
?>