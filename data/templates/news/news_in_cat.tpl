{if $child_count > 0}
{foreach from=$ChildCats item=childcat}
<div class="w50p t-left floatLeft" style="padding-bottom:25px"><a href="/tintuc/danhmuc/{$childcat.news_categories_id}"><span class="f14 fb">{$childcat.news_categories_name}</span></a></div>
{/foreach}
<div class="seperator w100p" style="border-top:3px solid #cccccc"></div>
{/if}
<table width="100%" cellpadding="0" cellspacing="2">
{foreach from=$Items item=news}
<tr>
	<td colspan="2"><a class="news2 fb" href="/tintuc/{$news.news_id}/chitiet"><span class="f12 fb">{$news.news_title}</span></a></td>
</tr>
<tr>
	<td width="110" valign="top"><a href="/tintuc/{$news.news_id}/chitiet"><img border="0" class="floatLeft" width="{$HEADING_NEWS_IMAGE_WIDTH}" height="{$HEADING_NEWS_IMAGE_HEIGHT}" src="/images/tintuc/{$news.icon}" hspace="5"></a></td>
	<td valign="top"><span class="f10">{$news.summary}</span></td>
</tr>
<tr><td colspan="2">&nbsp;</td></tr>
{/foreach}
</table>
{if $older_count > 0}
<div class="w100p t-left">
<p>
	<ul>
		{foreach from=$OlderNews item=oldnews}
		<li><a class="news1" href="/tintuc/{$oldnews.news_id}/chitiet">{$oldnews.news_title}</a></li>
		{/foreach}
	</ul>
</p>
</div>
{/if}