<div id="header_image"></div>
{if $smarty.session.admin.id != ''}
<div id="header_menu">
  <ul class="sf-menu">
    <li class="current">
      <a href="/admin/dashboard">Dashboard</a>
    </li>
    <li>
      <a href="/admin/categories">Sản phẩm</a>
    </li>
    <li>
      <a href="/admin/orders/list"{if $pendingOrderCount > 0} style="text-decoration: blink;color: #ffff00;font-weight: bold"{/if}>Đơn hàng</a>
    </li>
    <li>
      <a href="#">Thống kê</a>
      <ul>
        <li><a href="#">Bán chạy nhất</a></li>
      </ul>
    </li>
    <li>
      <a href="/admin/shop/config">Cấu hình</a>
    </li>
  </ul>
</div>
{/if}