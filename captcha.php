<?php
function writelog($fn, $cnt)
{
    // Let's make sure the file exists and is writable first.
    if (is_writable($fn))
    {
        // In our example we're opening $filename in append mode.
        // The file pointer is at the bottom of the file hence
        // that's where $somecontent will go when we fwrite() it.
        if (!$handle = fopen($fn, 'a'))
        {
            // echo "Cannot open file ($fn)";
            exit;
        }
    }
    // Write $somecontent to our opened file.
    if (fwrite($handle, $cnt) === FALSE)
    {
        exit;
    }
    fclose($handle);

}
session_start();

/*
* File: CaptchaSecurityImages.php
* Author: Simon Jarvis
* Copyright: 2006 Simon Jarvis
* Date: 03/08/06
* Updated: 07/02/07
* Requirements: PHP 4/5 with GD and FreeType libraries
* Link: http://www.white-hat-web-design.co.uk/articles/php-captcha.php
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details:
* http://www.gnu.org/licenses/gpl.html
*
*/

class CaptchaSecurityImages {

   var $font = './tahoma.ttf';

   function generateCode($characters) {
      /* list all possible characters, similar looking characters and vowels have been removed */
      $possible = '23456789bcdfghjkmnpqrstvwxyz';
      $code = '';
      $i = 0;
      while ($i < $characters) {
         $code .= substr($possible, mt_rand(0, strlen($possible)-1), 1);
         $i++;
      }
      return $code;
   }

   function CaptchaSecurityImages($width='120',$height='40',$characters='6')
   {
      $code = $this->generateCode($characters);
      /* font size will be 75% of the image height */
      // $font_size = $height * 0.60;
      $font_size = 18;
      $image = imagecreate($width, $height) or die('Cannot initialize new GD image stream');
      /* set the colours */
      $background_color = imagecolorallocate($image, 255, 255, 255);
      $text_color = imagecolorallocate($image, 20, 40, 100);
      $noise_color = imagecolorallocate($image, 100, 120, 180);
      /* generate random dots in background */
      for( $i=0; $i<($width*$height)/3; $i++ ) {
         imagefilledellipse($image, mt_rand(0,$width), mt_rand(0,$height), 1, 1, $noise_color);
      }
      /* generate random lines in background */
      for( $i=0; $i<($width*$height)/150; $i++ ) {
         imageline($image, mt_rand(0,$width), mt_rand(0,$height), mt_rand(0,$width), mt_rand(0,$height), $noise_color);
      }
      /* create textbox and add text */
      $textbox = imagettfbbox($font_size, 0, $this->font, $code) or die('Error in imagettfbbox function');
      $x = ($width - $textbox[4])/2 - 11;
      $y = ($height - $textbox[5])/2 - 3;
      //imagettftext($image, $font_size, 0, $x, $y, $text_color, $this->font , $code) or die('Error in imagettftext function');
      for($i=0;$i<(int)($characters);$i++)
      {
        $angle = rand(-15, 15);
        imagettftext($image, $font_size, $angle, $x, $y, $text_color, $this->font , $code[$i]) or die('Error in imagettftext function');
        $x += 16;
      }
      /* output captcha image to browser */
      header('Content-Type: image/jpeg');
      imagejpeg($image);
      imagedestroy($image);

      $sess_name = $_GET['name'];
      if(empty($sess_name))
        $_SESSION['seccode'] = $code;
      else
        $_SESSION[$sess_name]['seccode'] = $code;
      // writelog('captcha.log', "$code\n");
   }

}

// $width = isset($_GET['width']) && $_GET['width'] < 600 ? $_GET['width'] : '60';
// $height = isset($_GET['height']) && $_GET['height'] < 200 ? $_GET['height'] : '15';
// $characters = isset($_GET['characters']) && $_GET['characters'] > 2 ? $_GET['characters'] : '6';


$captcha = new CaptchaSecurityImages();

?>