<?php /* Smarty version 2.6.20, created on 2010-06-08 20:29:00
         compiled from header/header1.tpl */ ?>
  <img src="/images/banner_2nd.jpg"><div class="clear"></div>
  <div class="w100p" style="margin-top: 15px">
    <div id="marquee_wrapper">
      <marquee><strong><font size="3" color="#FF00FF">Hàng hi&#7879;u &#273;&#7865;p, ch&#7845;t l&#432;&#7907;ng. Giá h&#7907;p lý. </font> <font size="3" color="#008080">Giao hàng t&#7853;n n&#417;i.  V&#7851;n &#273;ang update s&#7843;n ph&#7849;m hàng ngày.</font></strong></marquee>
    </div>

    <div class="navigation2_icon">
      <?php if ($_SESSION['logon']['id'] != ''): ?>
      <a href="/dangxuat" class="headerNavigation2" style="background-image: url(/images/logoff_30x30.gif);">Thoát</a>&nbsp;&nbsp;
      <?php endif; ?>
        <a href="/taikhoan" class="headerNavigation2" style="background-image: url(/images/header_account.gif);">Tài khoản</a>&nbsp;&nbsp;
        <a href="/giohang/xem" class="headerNavigation2" style="background-image: url(/images/header_cart.gif);">Giỏ hàng</a> &nbsp;&nbsp;
        <a href="/thanhtoan" class="headerNavigation2" style="background-image: url(/images/header_checkout.gif);">Thanh Toán</a>
    </div>
  </div>
  <div class="clear"></div>
  <div class="headerNavigation" style="<?php if ($this->_tpl_vars['BROWSER_NAME'] == 'ie'): ?>margin-bottom: -18px;<?php elseif ($this->_tpl_vars['BROWSER_NAME'] == 'opera'): ?>margin-bottom: -10px;margin-top: -25px;<?php else: ?>margin-top: -25px;<?php endif; ?>">
    <ul class="headerNavigation">
            <li><a href="/home">TRANG CHỦ</a></li>
            <li><a href="/tintuc">KIẾN THỨC</a></li>
            <li><a href="/huongdanmuahang">HƯỚNG DẪN MUA HÀNG</a></li>

            <li><a href="/huongdanthanhtoan">GIAO HÀNG & THANH TOÁN</a></li>
            <li><a href="/lienhe">LIÊN HỆ</a></li>
        </ul>
  </div>