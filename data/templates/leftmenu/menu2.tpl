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
{TitleBox title="Danh mục tin"}
<div style="background-color: #7DCCFF; width="100%">
<div class="side_container">
  <ul class="categories">
    {foreach from=$NewsCategories item=newscat}
    <li style="margin-left:{if $newscat.level>0}{math equation="x * y" x=$newscat.level y=30}{else}15{/if}{if $newscat.level>=0};list-style-type: square{/if};"><a href="/tintuc/danhmuc/{$newscat.news_categories_id}" style="{if $newscat.level==-1}background-image:url(/images/{$newscat.icon});{else}padding-left:0;{/if}{if $newscat.news_categories_id==$current_news_cat}color: red;{/if}">{$newscat.news_categories_name}</a></li>
    {/foreach}
  </ul>
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
