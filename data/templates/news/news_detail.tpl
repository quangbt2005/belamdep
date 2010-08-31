{if $has_news=='true'}
<table width="100%" cellpadding="0" cellspacing="10">
	<tr><td align="left"><a class="news2 fb" href="/tintuc/{$current_news.news_id}/chitiet"><span class="f12 fb">{$current_news.news_title}</span></a></td></tr>
	<tr><td align="center"><img border="0" src="/images/tintuc/{$current_news.icon}"></td></tr>
	<tr><td align="left" style="font-family: verdana;font-size:10pt;">{$current_news.news_content}</td></tr>
</table>
{/if}
{if $new_news_count > 0}
<div class="w100p t-left">
	<p class="fb f12">Tin mới nhất</p>
	<p>
		<ul>
			{foreach from=$NewNews item=new_news}
			<li><a class="news1" href="/tintuc/{$new_news.news_id}/chitiet">{$new_news.news_title}</a></li>
			{/foreach}
		</ul>
	</p>
</div>
{/if}
{if $older_count > 0}
<div class="w100p t-left">
	<p class="fb">Tin cũ hơn</p>
	<p>
		<ul>
			{foreach from=$OlderNews item=older_news}
			<li><a class="news1" href="/tintuc/{$older_news.news_id}/chitiet">{$older_news.news_title}</a></li>
			{/foreach}
		</ul>
	</p>
</div>
{/if}