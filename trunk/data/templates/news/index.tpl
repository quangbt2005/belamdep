{foreach from=$Items item=news}
<div class="w100p t-left" style="border-bottom: 1px solid #cccccc">
<a href="/tintuc/danhmuc/{$news.cat.news_categories_id}"><span class="f12 fb">{$news.cat.news_categories_name}</span></a><br>
<a href="/tintuc/{$news.top_news[0].news_id}/chitiet"><img border="0" class="floatLeft" width="{$HEADING_NEWS_IMAGE_WIDTH}" height="{$HEADING_NEWS_IMAGE_HEIGHT}" src="/images/tintuc/{$news.top_news[0].icon}" hspace="5" vspace="5"></a>
<a class="news2" href="/tintuc/{$news.top_news[0].news_id}/chitiet">{$news.top_news[0].news_title}</a><br>
<span class="f10">{$news.summary} ...</span><br>
<p>
	<ul>
		{foreach from=$news.top_news item=next_first}
		<li><a class="news1" href="/tintuc/{$next_first.news_id}/chitiet">{$next_first.news_title}</a></li>
		{/foreach}
	</ul>
</p>
</div>
<div class="seperator"></div>
{/foreach}