<?php
/**************************************************************************************************/
/* Created on May 30, 2010                                                                        */
/**************************************************************************************************/
function encrypt_password($plain)
{
  $password = '';

  for ($i=0; $i<10; $i++) {
    $password .= osc_rand();
  }

  $salt = substr(md5($password), 0, 2);

  $password = md5($salt . $plain) . ':' . $salt;

    return $password;
}
function validate_password($plain, $encrypted)
{
  if (!empty($plain) && !empty($encrypted)) {
    $stack = explode(':', $encrypted);

    if (sizeof($stack) != 2) return false;

    if (md5($stack[1] . $plain) == $stack[0]) {
      return true;
    }
  }

  return false;
}
?>
