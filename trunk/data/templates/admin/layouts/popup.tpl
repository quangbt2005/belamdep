<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" dir="ltr" lang="en" xml:lang="en">
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
  <meta name="robots" content="noindex" />
  <link rel="StyleSheet" href="/style/admin.css" type="text/css" />
  {if $Request.request_page == 'addproduct' || $Request.request_page == 'editproduct'}
  <script type="text/javascript" src="/jscripts/jquery/jquery-1.4.2.js"></script>
  <script type="text/javascript" src="/jscripts/jquery/tiny_mce/jquery.tinymce.js"></script>
  {/if}
  <link rel="shortcut icon" href="/favico.ico" type="image/x-icon" />
  <title>{$title}</title>
</head>
<body>
<div id="allscreen">
  <div id="allcontent">
    {$center_col}
    <!-- <textarea id="elm1" name="elm1" rows="15" cols="80" style="width: 80%" class="tinymce">{$txtProductDescription}</textarea> -->
  </div>
</div>
</body>
</html>