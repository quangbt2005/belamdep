<table border="0" cellpadding="0" cellspacing="0" width="100%" style="padding: 10 0 10 0">
<tr><td><span class="bigtitle">Xin chào ! Hãy đăng nhập.</span></td><td align="right"><img width="57" height="40" border="0" title=" Đăng nhập " alt="Đăng nhập" src="/images/table_background_login.gif"></td></tr>
</table>
{if $error_count > 0}
{foreach from=$errs item=error}
<div class="w100p error_field t-left">&nbsp;&nbsp;<img height="10" border="0" width="10" title=" Lỗi " alt="Lỗi" src="/images/icons/error.gif">&nbsp;{$error}</div>
{/foreach}
<br>
{/if}
<table border="0" cellpadding="0" cellspacing="3" width="100%" style="padding: 10 0 10 0">
<tr><td width="50%"><span class="f12 fb">Khách hàng mới</span></td><td><span class="f12 fb">Khách hàng cũ</span></td></tr>
</table>
<form action="/dangnhap" method="post">
<table width="100%" cellpadding="0" cellspacing="0">
  <tr>
    <td style="padding-right: 2px" width="50%">
      <table width="100%" cellpadding="0" cellspacing="0" class="register h300" border="0">
        <tr><td style="height: 32px">Tôi là khách hàng mới.</td></tr>
        <tr><td style="font: normal 14px/28px Tahoma;">Bằng cách tạo 1 tài khoản tại Be Lam Dep bạn sẽ được sử dụng các tính năng hấp dẫn như: chọn hàng, đặt hàng nhanh hơn, nhận thông tin cập nhật của các sản phẩm khi có thay đổi 1 cách nhanh chóng, xem lại lịch sử đơn hàng cũng như đánh giá các sản phẩm dễ dàng....</td></tr>
        <tr><td class="t-right" style="height: 32px"><a href="/taikhoan/dangky"><img border="0" title=" Đăng ký " alt="Đăng ký" src="/images/languages/vietnam/buttons/button_continue.gif"></a></td></tr>
      </table>
    </td>
    <td style="padding-left: 2px">
      <table width="100%" cellpadding="0" cellspacing="0" class="register h300" border="0">
        <tr><td style="height: 32px">Tôi là khách hàng cũ.</td></tr>
        <tr><td><table width="100%" cellpadding="0" cellspacing="0">
            <tr><td class="f10 fb">Email</td><td><input type="text" name="txtEmail" value="{$smarty.post.txtEmail}" class="w160"></td></tr>
            <tr><td class="f10 fb">Password</td><td><input type="password" name="txtPassword" class="w160"></td></tr>
          </table></td>
        </tr>
        <tr><td class="t-left f8"><a href="/quenmatkhau">Quên mật khẩu ? Nhấp vào đây.</a></td></tr>
        <tr><td class="t-right" style="height: 32px"><input type="image" border="0" title=" Đăng nhập " alt="Đăng nhập" src="/images/languages/vietnam/buttons/button_login.gif"></a></td></tr>
      </table>
    </td>
  </tr>
</table><input type="hidden" name="btnLogin" value="Login">
</form>