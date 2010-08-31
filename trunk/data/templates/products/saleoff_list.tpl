  {if $total_products > 0}
  <div class="wrapper" style="width: 547px; margin-left: 1px;">
  {TitleBox title="Sản phẩm khuyến mãi"}
    {foreach from=$Product_List item=product}
    <div class="product">
      {if $product.empty != 'true'}
      <div style="height: 155px;padding: 5px">
        <a href="/sanpham/{$product.products_id}/chitiet">{ImageThumb src=$product.products_image width=auto height=$SMALL_IMAGE_HEIGHT alt=$product.products_name}<br>
        <a href="/sanpham/{$product.products_id}/chitiet">{$product.products_name}</a><br>
      </div>
      {if $product.special_price != ''}<s>{number_format number=$product.products_price}</s>&nbsp;<span class="fore-red">{number_format number=$product.special_price}{else}{number_format number=$product.products_price}{/if}&nbsp;VND</span><br>
      <a href="/sanpham/{$product.products_id}/order">{ImageButton image="button_buy_now.png" alt="Đặt hàng"}</a>
      {/if}
    </div>
    {/foreach}
  </div>
  <div class="clear"></div>
  {$pager}<div class="clear"></div>
  <div class="t-right" style="width: 547px;"><span class="f10">Hiển thị {$product_count} sản phẩm từ {$product_from} đến {$product_to} trong tổng số {$total_products} sản phẩm</span></div>
  {else}
  <h1>Không tìm thấy sản phẩm nào {$total_products}</h1>
  {/if}