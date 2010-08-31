<div id="header_image"></div>
{if $smarty.session.admin.id != ''}
<div id="header_menu">
  <ul class="sf-menu">
    <li class="current">
      <a href="/admin/dashboard">Dashboard</a>
    </li>
    <li>
      <a href="#">Product</a>
      <ul>
        <li><a href="/admin/categories">Categories</a></li>
        <li><a href="#">Products</a></li>
        <li><a href="#">Sale Off</a></li>
      </ul>
    </li>
    <li>
      <a href="#">Sales</a>
      <ul>
        <li><a href="#">Orders</a></li>
        <li><a href="#">Customers</a></li>
      </ul>
    </li>
    <li>
      <a href="#">Reports</a>
      <ul>
        <li><a href="#">Best Seller</a></li>
      </ul>
    </li>
  </ul>
</div>
{/if}