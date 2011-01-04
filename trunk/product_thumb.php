<?php
function setTransparency($new_image,$image_source)
{
  $transparencyIndex = imagecolortransparent($image_source);
  $transparencyColor = array('red' => 255, 'green' => 255, 'blue' => 255);

  if ($transparencyIndex >= 0) {
    $transparencyColor    = imagecolorsforindex($image_source, $transparencyIndex);
  }

  $transparencyIndex    = imagecolorallocate($new_image, $transparencyColor['red'], $transparencyColor['green'], $transparencyColor['blue']);
  imagefill($new_image, 0, 0, $transparencyIndex);
  imagecolortransparent($new_image, $transparencyIndex);
}

$f  = $_GET['f'];

$img_dir = 'images/';
if(!is_file($img_dir.$f)){
  $f = 'noimage.jpg';
}
$gis = getimagesize($img_dir.$f);
$type = $gis[2];
switch($type)
{
  case "1": $imorig = imagecreatefromgif($img_dir.$f); break;
  case "2": $imorig = imagecreatefromjpeg($img_dir.$f);break;
  case "3": $imorig = imagecreatefrompng($img_dir.$f); break;
  default: $imorig = imagecreatefromjpeg($img_dir.$f);
}

$x = imagesx($imorig);
$y = imagesy($imorig);

$w  = empty($_GET['w']) ? $x : $_GET['w'];
$h  = empty($_GET['h']) ? $y : $_GET['h'];
$ma = empty($_GET['ma']) ? 500 : $_GET['ma'];

if($h=='auto' && is_numeric($w))
{
  $h=($w/$x*100)*($y/100);
  if($h > $ma)
  {
    $h = $ma;
    $w = ($h/$y*100)*($x/100);
  }
}
if($w=='auto' && is_numeric($h))
{
  $w=($h/$y*100)*($x/100);
  if($w > $ma)
  {
    $w = $ma;
    $h = ($w/$x*100)*($y/100);
  }
}

$im = imagecreatetruecolor($w,$h);
setTransparency($im,$imorig);
imagecopyresampled($im,$imorig , 0,0,0,0,$w,$h,$x,$y);

$cx = empty($_GET['cx']) ? 0 : $_GET['cx'];
$cy = empty($_GET['cy']) ? 0 : $_GET['cy'];

if(!empty($cx) && !empty($cy))
{
    $sx = ($cx - $w)/2;
    $sy = ($cy - $h)/2;

    $canvas = imagecreatetruecolor($cx,$cy);
    $white  = imagecolorallocate($canvas, 255, 255, 255);
    imagefill($canvas, 0, 0, $white);
    imagecopy($canvas, $im, $sx, $sy, 0, 0, $w, $h);
    $im = $canvas;
}

//if (imagecopyresampled($im,$imorig , 0,0,0,0,$w,$h,$x,$y))
{
  header('Content-Type: image/jpeg');
  imagejpeg($im);
  imagedestroy($im);
}
//} else {
//    $imorig = imagecreatefrompng($img_dir.'app-search.png');
//    header('Content-Type: image/jpeg');
//    imagejpeg($imorig);
//    imagedestroy($imorig);
//}
?>
