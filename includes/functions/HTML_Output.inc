<?php
/*
  $Id: html_output.php 1739 2007-12-20 00:52:16Z hpdl $

  osCommerce, Open Source E-Commerce Solutions
  http://www.oscommerce.com

  Copyright (c) 2007 osCommerce

  Released under the GNU General Public License
*/
// ---------------------------------------------------------------------------------------------- //
function draw_security_code()
{
    $result = '<img src="' . DIR_WS_HTTP_CATALOG . 'captcha.php" />';
    return $result;
}
// ---------------------------------------------------------------------------------------------- //
function href_link($page = '', $parameters = '', $connection = 'NONSSL', $add_session_id = true,
                       $search_engine_safe = true)
{
    global $request_type, $session_started, $SID;

    if (!not_null($page))
    {
      die('</td></tr></table></td></tr></table><br><br><font color="#ff0000"><b>Error!</b>'.
          '</font><br><br><b>Unable to determine the page link!<br><br>');
    }

    if ($connection == 'NONSSL')
    {
      $link = HTTP_SERVER . DIR_WS_HTTP_CATALOG;
    }
    elseif ($connection == 'SSL')
    {
      if (ENABLE_SSL == true)
      {
        $link = HTTPS_SERVER . DIR_WS_HTTPS_CATALOG;
      }
      else
      {
        $link = HTTP_SERVER . DIR_WS_HTTP_CATALOG;
      }
    }
    else
    {
      die('</td></tr></table></td></tr></table><br><br><font color="#ff0000"><b>Error!</b>'.
          '</font><br><br><b>Unable to determine connection method on a link!<br>'.
          '<br>Known methods: NONSSL SSL</b><br><br>');
    }

    if (not_null($parameters))
    {
      $link .= $page . '?' . output_string($parameters);
      $separator = '&';
    }
    else
    {
      $link .= $page;
      $separator = '?';
    }

    while ( (substr($link, -1) == '&') || (substr($link, -1) == '?') ) $link = substr($link, 0, -1);

    // Add the session ID when moving from different HTTP and HTTPS servers, or when SID is defined
    if ( ($add_session_id == true) && ($session_started == true)
          && (SESSION_FORCE_COOKIE_USE == 'False') )
    {
      if (not_null($SID))
      {
        $_sid = $SID;
      }
      elseif ((($request_type == 'NONSSL') && ($connection == 'SSL') && (ENABLE_SSL == true) )
              || ( ($request_type == 'SSL') && ($connection == 'NONSSL') ) )
      {
        if (HTTP_COOKIE_DOMAIN != HTTPS_COOKIE_DOMAIN)
        {
          $_sid = session_name() . '=' . session_id();
        }
      }
    }

    if ( (SEARCH_ENGINE_FRIENDLY_URLS == 'true') && ($search_engine_safe == true) )
    {
      while (strstr($link, '&&')) $link = str_replace('&&', '&', $link);

      $link = str_replace('?', '/', $link);
      $link = str_replace('&', '/', $link);
      $link = str_replace('=', '/', $link);

      $separator = '?';
    }

    if (isset($_sid))
    {
      $link .= $separator . output_string($_sid);
    }

    return $link;
}
// ---------------------------------------------------------------------------------------------- //
function image($src, $alt = '', $width = '', $height = '', $parameters = '')
{
    if ( (empty($src) || ($src == DIR_WS_IMAGES)) && (IMAGE_REQUIRED == 'false') )
    {
      return false;
    }

    // alt is added to the img tag even if it is null to prevent browsers from outputting
    // the image filename as default
    $image = '<img src="' . output_string($src) . '" border="0" alt="' .
             output_string($alt) . '"';

    if (not_null($alt)) {
      $image .= ' title=" ' . output_string($alt) . ' "';
    }

    if ( (CONFIG_CALCULATE_IMAGE_SIZE == 'true') && (empty($width) || empty($height)) ) {
      if ($image_size = @getimagesize($src)) {
        if (empty($width) && not_null($height)) {
          $ratio = $height / $image_size[1];
          $width = intval($image_size[0] * $ratio);
        } elseif (not_null($width) && empty($height)) {
          $ratio = $width / $image_size[0];
          $height = intval($image_size[1] * $ratio);
        } elseif (empty($width) && empty($height)) {
          $width = $image_size[0];
          $height = $image_size[1];
        }
      } elseif (IMAGE_REQUIRED == 'false') {
        return false;
      }
    }

    if (not_null($width) && not_null($height)) {
      $image .= ' width="' . output_string($width) . '" height="' .
                output_string($height) . '"';
    }

    if (not_null($parameters)) $image .= ' ' . $parameters;

    $image .= '>';
    // $image = image_thumb($src, $alt, $width, $height, $parameters);

    return $image;
}
// ---------------------------------------------------------------------------------------------- //
// The HTML form submit button wrapper function
// Outputs a button in the selected language
function image_submit($image, $alt = '', $parameters = '')
{
    global $language;

    $image_submit = '<input type="image" src="' .
                    output_string(DIR_WS_LANGUAGES . $language . '/images/buttons/' . $image) .
                    '" border="0" alt="' . output_string($alt) . '"';

    if (not_null($alt)) $image_submit .= ' title=" ' . output_string($alt) . ' "';

    if (not_null($parameters)) $image_submit .= ' ' . $parameters;

    $image_submit .= '>';

    return $image_submit;
}

// ---------------------------------------------------------------------------------------------- //
// Output a function button in the selected language
function image_button($image, $alt = '', $parameters = '')
{
    global $language;

    return image(IMAGES_PATH . 'languages/' . LANGUAGE . '/buttons/' . $image, $alt,
                     '', '', $parameters);
}

// ---------------------------------------------------------------------------------------------- //
// Output a separator either through whitespace, or with an image
function draw_separator($image = 'pixel_black.gif', $width = '100%', $height = '1')
{
    return image(DIR_WS_IMAGES . $image, '', $width, $height);
}

// ---------------------------------------------------------------------------------------------- //
// Output a form
function draw_form($name, $action, $method = 'post', $parameters = '')
{
    $form = '<form name="' . output_string($name) . '" action="' .
            output_string($action) . '" method="' . output_string($method) . '"';

    if (not_null($parameters)) $form .= ' ' . $parameters;

    $form .= '>';

    return $form;
}

// ---------------------------------------------------------------------------------------------- //
// Output a form input field
function draw_input_field($name, $value = '', $parameters = '', $type = 'text',
                                $reinsert_value = true, $from_session='')
{
    global $HTTP_GET_VARS, $HTTP_POST_VARS;
    $field = '<input type="' . output_string($type) . '" name="' .
             output_string($name) . '"';

    if ( ($reinsert_value == true) && ( (isset($HTTP_GET_VARS[$name])
          && is_string($HTTP_GET_VARS[$name])) || (isset($HTTP_POST_VARS[$name])
          && is_string($HTTP_POST_VARS[$name])) ) )
    {
      if (isset($HTTP_GET_VARS[$name]) && is_string($HTTP_GET_VARS[$name]))
      {
        $value = stripslashes($HTTP_GET_VARS[$name]);
      }
      elseif (isset($HTTP_POST_VARS[$name]) && is_string($HTTP_POST_VARS[$name]))
      {
        $value = stripslashes($HTTP_POST_VARS[$name]);
      }
    }

    if(!empty($from_session))
    {
      if($_SERVER['REQUEST_METHOD'] == 'GET')
      {
    	 if(isset($_SESSION[$from_session]))
       {
        $value = $_SESSION[$from_session];
       }
      }
    }

    if (not_null($value)) {
      $field .= ' value="' . output_string($value) . '"';
    }

    if (not_null($parameters)) $field .= ' ' . $parameters;

    $field .= '>';

    return $field;
  }

////
// Output a form password field
  function draw_password_field($name, $value = '', $parameters = 'maxlength="40"') {
    return draw_input_field($name, $value, $parameters, 'password', false);
  }

// ---------------------------------------------------------------------------------------------- //
// Output a selection field - alias function for draw_checkbox_field()
// and draw_radio_field()
function draw_selection_field($name, $type, $value = '', $checked = false, $parameters = '')
{
    global $HTTP_GET_VARS, $HTTP_POST_VARS;

    $selection = '<input type="' . output_string($type) . '" name="' .
                 output_string($name) . '"';

    if (not_null($value)) $selection .= ' value="' . output_string($value) . '"';

    if ( ($checked == true) || (isset($HTTP_GET_VARS[$name])
         && is_string($HTTP_GET_VARS[$name])
         && (($HTTP_GET_VARS[$name] == 'on') || (stripslashes($HTTP_GET_VARS[$name]) == $value)))
         || (isset($HTTP_POST_VARS[$name]) && is_string($HTTP_POST_VARS[$name])
         && (($HTTP_POST_VARS[$name] == 'on')
         || (stripslashes($HTTP_POST_VARS[$name]) == $value))) )
    {
      $selection .= ' CHECKED';
    }

    if (not_null($parameters)) $selection .= ' ' . $parameters;

    $selection .= '>';

    return $selection;
}
// ---------------------------------------------------------------------------------------------- //
function draw_checkbox_field($name, $value = '', $checked = false, $parameters = '')
{
    return draw_selection_field($name, 'checkbox', $value, $checked, $parameters);
}

// ---------------------------------------------------------------------------------------------- //
// Output a form radio field
function draw_radio_field($name, $value = '', $checked = false, $parameters = '')
{
    return draw_selection_field($name, 'radio', $value, $checked, $parameters);
}

// ---------------------------------------------------------------------------------------------- //
// Output a form textarea field
function draw_textarea_field($name, $wrap, $width, $height, $text = '', $parameters = '',
                                 $reinsert_value = true)
{
    global $HTTP_GET_VARS, $HTTP_POST_VARS;

    $field = '<textarea name="' . output_string($name) . '" wrap="' .
             output_string($wrap) . '" cols="' . output_string($width) .
             '" rows="' . output_string($height) . '"';

    if (not_null($parameters)) $field .= ' ' . $parameters;

    $field .= '>';

    if ( ($reinsert_value == true) && ( (isset($HTTP_GET_VARS[$name])
         && is_string($HTTP_GET_VARS[$name])) || (isset($HTTP_POST_VARS[$name])
         && is_string($HTTP_POST_VARS[$name])) ) )
    {
      if (isset($HTTP_GET_VARS[$name]) && is_string($HTTP_GET_VARS[$name]))
      {
        $field .= output_string_protected(stripslashes($HTTP_GET_VARS[$name]));
      }
      elseif (isset($HTTP_POST_VARS[$name]) && is_string($HTTP_POST_VARS[$name]))
      {
        $field .= output_string_protected(stripslashes($HTTP_POST_VARS[$name]));
      }
    }
    elseif (not_null($text))
    {
      $field .= output_string_protected($text);
    }

    $field .= '</textarea>';

    return $field;
}

// ---------------------------------------------------------------------------------------------- //
// Output a form hidden field
function draw_hidden_field($name, $value = '', $parameters = '')
{
    global $HTTP_GET_VARS, $HTTP_POST_VARS;

    $field = '<input type="hidden" name="' . output_string($name) . '"';

    if (not_null($value))
    {
      $field .= ' value="' . output_string($value) . '"';
    }
    elseif ( (isset($HTTP_GET_VARS[$name]) && is_string($HTTP_GET_VARS[$name]))
             || (isset($HTTP_POST_VARS[$name]) && is_string($HTTP_POST_VARS[$name])) )
    {
      if ( (isset($HTTP_GET_VARS[$name]) && is_string($HTTP_GET_VARS[$name])) )
      {
        $field .= ' value="' . output_string(stripslashes($HTTP_GET_VARS[$name])) . '"';
      }
      elseif ( (isset($HTTP_POST_VARS[$name]) && is_string($HTTP_POST_VARS[$name])) )
      {
        $field .= ' value="' . output_string(stripslashes($HTTP_POST_VARS[$name])) . '"';
      }
    }

    if (not_null($parameters)) $field .= ' ' . $parameters;

    $field .= '>';

    return $field;
  }

// ---------------------------------------------------------------------------------------------- //
// Hide form elements
function hide_session_id()
{
    global $session_started, $SID;

    if (($session_started == true) && not_null($SID))
    {
      return draw_hidden_field(session_name(), session_id());
    }
}
// ---------------------------------------------------------------------------------------------- //
// Output a form pull down menu
function draw_pull_down_menu($name, $values, $default = '', $parameters = '',
                                 $required = false, $from_session='')
{
    global $HTTP_GET_VARS, $HTTP_POST_VARS;

    $field = '<select name="' . output_string($name) . '"';

    if (not_null($parameters)) $field .= ' ' . $parameters;

    $field .= '>';

    if (empty($default) && ( (isset($HTTP_GET_VARS[$name]) && is_string($HTTP_GET_VARS[$name]))
        || (isset($HTTP_POST_VARS[$name]) && is_string($HTTP_POST_VARS[$name])) ) )
    {
      if (isset($HTTP_GET_VARS[$name]) && is_string($HTTP_GET_VARS[$name]))
      {
        $default = stripslashes($HTTP_GET_VARS[$name]);
      }
      elseif (isset($HTTP_POST_VARS[$name]) && is_string($HTTP_POST_VARS[$name]))
      {
        $default = stripslashes($HTTP_POST_VARS[$name]);
      }
    }

    if(!empty($from_session))
    {
      if($_SERVER['REQUEST_METHOD'] == 'GET')
      {
        if(isset($_SESSION[$from_session]))
        {
            $default = $_SESSION[$from_session];
        }
      }
    }

    for ($i=0, $n=sizeof($values); $i<$n; $i++) {
      $field .= '<option value="' . output_string($values[$i]['id']) . '"';
      if ($default == $values[$i]['id']) {
        $field .= ' SELECTED';
      }

      $field .= '>' . output_string($values[$i]['text'], array('"' => '&quot;',
                '\'' => '&#039;', '<' => '&lt;', '>' => '&gt;')) . '</option>';
    }
    $field .= '</select>';

    if ($required == true) $field .= TEXT_FIELD_REQUIRED;

    return $field;
  }

// ---------------------------------------------------------------------------------------------- //
// Creates a pull-down list of countries
function get_country_list($name, $selected = '', $parameters = '')
{
    $countries_array = array(array('id' => '', 'text' => PULL_DOWN_DEFAULT));
    $countries = get_countries();

    for ($i=0, $n=sizeof($countries); $i<$n; $i++)
    {
      $countries_array[] = array('id' => $countries[$i]['countries_id'],
                                 'text' => $countries[$i]['countries_name']);
    }

    return draw_pull_down_menu($name, $countries_array, $selected, $parameters);
}
// ---------------------------------------------------------------------------------------------- //
function image_thumb($src, $alt = '', $width = '', $height = '', $parameters = '', $ma=500)
{
    if(!is_numeric($width) && !is_numeric($height))
    {
    	$height = 80;
      $width  = 'auto';
    }

    if(is_numeric($width) && $width > 1024) $width = 1024;
    if(is_numeric($height) && $height > 768) $height = 768;
    if($width=='auto' && is_numeric($ma) && $ma > 1024) $ma = 1024;
    if($height=='auto' && is_numeric($ma) && $ma > 768) $ma = 768;

    // alt is added to the img tag even if it is null to prevent browsers from outputting
    // the image filename as default
    $image = '<img src="/product_thumb.php?f=' . output_string($src) .
             '&w='.$width.'&h='.$height.'&ma='.$ma.'" border="0" alt="' .
             output_string($alt) . '"';

    if (not_null($alt))
    {
        $image .= ' title=" ' . output_string($alt) . ' "';
    }
    if (not_null($parameters)) $image .= ' ' . $parameters;

    $image .= '>';
    return $image;
}
// ---------------------------------------------------------------------------------------------- //
?>
