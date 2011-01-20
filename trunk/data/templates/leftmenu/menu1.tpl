<div style="background-color: #7DCCFF; width="100%">
<div class="side_container">
  <ul class="categories">
    {foreach from=$Categories item=cat}
    <li style="margin-left:{math equation="x * y" x=$cat.level y=30}{if $cat.level>0};list-style-type: square{/if};"><a href="/sanpham/danhsach/{$cat.categories_id}" style="{if $cat.level==0}background-image:url(/images/{$cat.icon});{else}padding-left:0;{/if}{if $cat.categories_id==$current_cat}color: red;{/if}">{$cat.categories_name}</a></li>
    {/foreach}
  </ul>
</div>
</div>
<div class="seperator"></div>
{TitleBox title="Bán chạy nhất"}
<div style="background-color: #7DCCFF; width="100%">
  <div class="side_container">
    <div id="slideshow">
      <div id="controls">
        <span><a href="" id="prev">Prev</a></span>
        <span><a href="" id="next">Next</a></span>
        <span><a href="" id="pause">Pause</a></span>
        <span><a href="" id="play">Play</a></span>
      </div>
      <div id="slides" class="pics">
        {foreach from=$best_seller item=best}
        <a href="/sanpham/{$best.products_id}/chitiet" title="{$best.products_name}"><img src="/product_thumb.php?f={$best.products_image}&w=auto&h=130&cx=198&cy=200" alt="{$best.products_name}" hspace="0" border="0" width="198" height="200"></a>
        {/foreach}
      </div>
    </div>
  </div>
</div>
<div class="seperator"></div>
{TitleBox title="TÀI KHOẢN NGÂN HÀNG"}
<div style="background-color: #7DCCFF; width="100%">
<div class="side_container">
<div class="t-left" style="padding-left: 5px">
  <span style="background-color: rgb(255, 255, 0);">VietcomBank(VCB): </span>
  <p>Nguyễn Thị Thanh Thủy</p>
  <p><b><font color="#ff0000">025 100 158 7962</font></b></p>
  <p><span style="background-color: rgb(255, 255, 0);">Á Châu (ACB): </span></p>
  <p>Nguyễn Thị Minh Hải </p>
  <p><font color="#ff0000"><b>4041 6931 8020 5507</b></font></p>
</div>
</div>
</div>
<div class="seperator"></div>
{TitleBox title='BẢO HIỂM GIÁO DỤC&nbsp;&nbsp;<img src="/images/hot.gif" border="0">'}
<div style="background-color: #7DCCFF; width="100%">
<div class="side_container">
<div class="t-left" style="padding-left: 5px">
  <p>Để đảm bảo cho con bạn một quỹ tài chính an toàn xin liên hệ: </p>
  <p></p>
  <p>Tư vấn viên bảo hiểm Thanh Thủy</p>
  <p>Điện thoại: <font color="#ff0000"><br><b>0907 537 422</b></font></p>
</div>
</div>
</div>