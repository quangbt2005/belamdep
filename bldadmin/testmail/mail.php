<?php
function mailSMTP($from_name,$from,$to,$cc,$bcc,$subject,$message)
{
    include_once ("class.phpmailer.php");
    $mail = new PHPMailer();

//    $mail->IsSMTP();                                    // send via SMTP
//    $mail->Host     = "server1.hostno1.vn";             // SMTP servers
//    $mail->SMTPAuth = true;                             // turn on SMTP authentication
//    $mail->Username = 'admin@belamdep.com';             // SMTP username
//    $mail->Password = 'mi@1lau';                        // SMTP password
    
    $mail->IsSMTP();                        // send via SMTP
    $mail->Host     = "web72.vinahost.vn";    // SMTP servers
    $mail->SMTPAuth = true;                 // turn on SMTP authentication
    $mail->Username = 'belamdep';          // SMTP username
    $mail->Password = 'mi@1lauQua';      // SMTP password

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
    //$mail->Port     = 587;
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

//mailSMTP('Quang Tran', 'quang.tm@eps.com.vn', array('quangbt2005@gmail.com', 'quang.tm@eps.com.vn', 'admin@belamdep.com'), NULL, NULL, 'Test mail', 'MAKENO KEMENO');
mailSMTP('Quang Tran', 'quang.tm@eps.com.vn', 'quangbt2005@gmail.com','quang.tm@eps.com.vn', NULL, 'Test mail', 'MAKENO KEMENO');
?>