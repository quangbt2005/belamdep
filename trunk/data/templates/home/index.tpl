  <div id="start_picture">
    <div id="box_1_1">
    {if $Specs[0] != ''}
      <a href="/product_thumb.php?f={$Specs[0].products_image}&w=auto&h=500&ma=1000" ref="/sanpham/{$Specs[0].products_id}/chitiet" class="agallery" title="{$Specs[0].products_name|upper}&nbsp;&nbsp;{number_format number=$Specs[0].products_price}&nbsp;VND">{ImageThumb src=$Specs[0].products_image width=auto height=64 alt=$Specs[0].products_name options="hspace=\"5\" vspace=\"5\""}</a>
    {/if}
    </div>

    <div id="box_1_2">
    {if $Specs[1] != ''}
      <a href="/product_thumb.php?f={$Specs[1].products_image}&w=auto&h=500&ma=1000" ref="/sanpham/{$Specs[1].products_id}/chitiet" class="agallery" title="{$Specs[1].products_name|upper}&nbsp;&nbsp;{number_format number=$Specs[1].products_price}&nbsp;VND">{ImageThumb src=$Specs[1].products_image width=auto height=64 alt=$Specs[1].products_name options="hspace=\"5\" vspace=\"5\""}</a>
    {/if}
    </div>

    <div id="box_1_3">
    {if $Specs[2] != ''}
      <a href="/product_thumb.php?f={$Specs[2].products_image}&w=auto&h=500&ma=1000" ref="/sanpham/{$Specs[2].products_id}/chitiet" class="agallery" title="{$Specs[2].products_name|upper}&nbsp;&nbsp;{number_format number=$Specs[2].products_price}&nbsp;VND">{ImageThumb src=$Specs[2].products_image width="auto" height="64" alt=$Specs[2].products_name options="hspace=\"5\" vspace=\"5\""}</a>
    {/if}
    </div>

    <div id="box_1_4">
    {if $Specs[3] != ''}
      <a href="/product_thumb.php?f={$Specs[3].products_image}&w=auto&h=500&ma=1000" ref="/sanpham/{$Specs[3].products_id}/chitiet" class="agallery" title="{$Specs[3].products_name|upper}&nbsp;&nbsp;{number_format number=$Specs[3].products_price}&nbsp;VND">{ImageThumb src=$Specs[3].products_image width="auto" height="64" alt=$Specs[3].products_name options="hspace=\"5\" vspace=\"5\""}</a>
    {/if}
    </div>

    <div id="box_2_1">
    {if $Specs[4] != ''}
      <a href="/product_thumb.php?f={$Specs[4].products_image}&w=auto&h=500&ma=1000" ref="/sanpham/{$Specs[4].products_id}/chitiet" class="agallery" title="{$Specs[4].products_name|upper}&nbsp;&nbsp;{number_format number=$Specs[4].products_price}&nbsp;VND">{ImageThumb src=$Specs[4].products_image width="auto" height="135" ma="148" alt=$Specs[4].products_name options="hspace=\"5\" vspace=\"5\""}</a>
    {/if}
    </div>


    <div id="box_3_1">
    {if $Specs[5] != ''}
      <a href="/product_thumb.php?f={$Specs[5].products_image}&w=auto&h=500&ma=1000" ref="/sanpham/{$Specs[5].products_id}/chitiet" class="agallery" title="{$Specs[5].products_name|upper}&nbsp;&nbsp;{number_format number=$Specs[5].products_price}&nbsp;VND">{ImageThumb src=$Specs[5].products_image width="auto" height="64" alt=$Specs[5].products_name options="hspace=\"5\" vspace=\"5\""}</a>
    {/if}
    </div>

    <div id="box_3_2">
    {if $Specs[6] != ''}
      <a href="/product_thumb.php?f={$Specs[6].products_image}&w=auto&h=500&ma=1000" ref="/sanpham/{$Specs[6].products_id}/chitiet" class="agallery" title="{$Specs[6].products_name|upper}&nbsp;&nbsp;{number_format number=$Specs[6].products_price}&nbsp;VND">{ImageThumb src=$Specs[6].products_image width="auto" height="64" alt=$Specs[6].products_name options="hspace=\"5\" vspace=\"5\""}</a>
    {/if}
    </div>


    <div id="box_2_2">
    {if $Specs[7] != ''}
      <a href="/product_thumb.php?f={$Specs[7].products_image}&w=auto&h=500&ma=1000" ref="/sanpham/{$Specs[7].products_id}/chitiet" class="agallery" title="{$Specs[7].products_name|upper}&nbsp;&nbsp;{number_format number=$Specs[7].products_price}&nbsp;VND">{ImageThumb src=$Specs[7].products_image width="auto" height="135" ma="148" alt=$Specs[7].products_name options="hspace=\"5\" vspace=\"5\""}</a>
    {/if}
    </div>

    <div id="maxbox">
    <a href="/sanpham/danhsach/42"><img src="/images/startbox/baby{php}echo rand(1,10);{/php}.png" alt="T-Shirts" title="T-Shirts" border="0" height="326"></a>
    </div>
  </div><!-- start_picture -->
  <br>
  <div class="wrapper" style="width: 547px; margin-left: 1px;"><!-- New product -->
    {TitleBox title="&nbsp;Sản phẩm mới"}
    {foreach from=$NewProducts item=newProduct}
    <div class="product">
      <div style="height: 155px;padding-top: 5px">
        <a href="/sanpham/{$newProduct.products_id}/chitiet">{ImageThumb src=$newProduct.products_image width=auto height=$SMALL_IMAGE_HEIGHT alt=$newProduct.products_name}<br>
        <a href="/sanpham/{$newProduct.products_id}/chitiet">{$newProduct.products_name}</a><br>
      </div>
      {if $newProduct.special_price != ''}<s>{number_format number=$newProduct.products_price}</s>&nbsp;<span class="fore-red">{number_format number=$newProduct.special_price}</span>{else}{number_format number=$newProduct.products_price}{/if}&nbsp;VND<br>
      <a href="/sanpham/{$newProduct.products_id}/order">{ImageButton image="button_buy_now.png" alt="Đặt hàng"}</a>
    </div>
    {/foreach}
  </div>