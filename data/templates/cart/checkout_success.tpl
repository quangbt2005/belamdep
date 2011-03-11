<br><div class="clear"></div>
<img hspace="15" class="floatLeft" width="175" height="198" border="0" title=" Đơn hàng của bạn đã được xử lý! " alt="Đơn hàng của bạn đã được xử lý!" src="/images/table_background_man_on_board.gif">
<div class="f16 fb t-center fore-bulete">Đơn hàng của bạn đã được xử lý!</div><br>
<div class="tumlum1 t-left">Đơn hàng của bạn đã được xử lý thành công. Chúng tôi sẽ liên lạc với bạn trong thời gian sớm nhất có thể để thảo luận về việc giao/nhận hàng.</div>
{if $hash != ''}<br>
<div class="tumlum1 t-left">Bạn có thể xem lại đơn hàng tại <a href="/donhang/{$hash}" style="color:blue">đây</a></div>{/if}
<br><br><br>
<div class="f15 fb t-center">Cám ơn bạn đã xem và đặt hàng tại website của chúng tôi!</div>
<br><br><br>
{if $payment_gateway_return_error == 1}
<p style="color: red;font-weight: bold">Bạn đã chọn phương thức thanh toán qua <a style="color: blue" href="{$gateway_url}" target="blank">Cổng thanh toán {$gateway}</a>. Tuy nhiên quá trình thanh toán đã không thành công. Chúng tôi sẽ xem xét và giải quyết đơn hàng của bạn trong thời gian sớm nhất.</p>
<br><br>
{/if}
<table width="100%" cellpadding="0" cellspacing="0" class="register">
  <tr><th><a href="/trangchu"><img border="0" title=" Tiếp tục " alt="Tiếp tục" src="/images/languages/vietnam/buttons/button_continue.gif"></a></th></tr>
</table>