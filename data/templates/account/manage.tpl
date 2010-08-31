<table border="0" cellpadding="0" cellspacing="0" width="100%" style="padding: 10 0 10 0">
<tr><td><span class="bigtitle">Quản lý tài khoản</span></td><td align="right"><img width="57" height="40" border="0" title=" Đăng nhập " alt="Đăng nhập" src="/images/table_background_account.gif"></td></tr>
</table>
{if $flash_count > 0}
{foreach from=$flash item=msg}
<div class="w100p success_field t-left">&nbsp;&nbsp;<img height="10" border="0" width="10" title=" Thành công " alt="Thành công" src="/images/icons/success.gif">&nbsp;{$msg}</div>
{/foreach}
<br>
{/if}
<div class="w100p t-left"><span class="f13 fb">Tài khoản</span></div>
<table border="0" cellpadding="0" cellspacing="0" width="100%" class="register">
  <tr>
    <td rowspan="2" width="20%"><img src="/images/account_personal.gif" hspace="5" vspace="5"></td>
    <td><img width="12" height="10" border="0" alt="" src="/images/arrow_green.gif">&nbsp;<a class="account_man" href="/taikhoan/thongtin">Xem hoặc thay đổi thông tin tài khoản.</a></td>
  </tr>
  <tr><td><img width="12" height="10" border="0" alt="" src="/images/arrow_green.gif">&nbsp;<a class="account_man" href="/taikhoan/matkhau">Đổi mật khẩu.</a></td></tr>
</table>