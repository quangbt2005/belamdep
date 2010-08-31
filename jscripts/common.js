function update_side_saleoff()
{
  $.get("/sanpham/giamgia/ajax", function(data){
    $("#divSaleOff").html(data);
    setTimeout(update_side_saleoff, 3000);
  });
}
$(document).ready(function(){
  setTimeout(update_side_saleoff, 3000);
});
$(document).ready(function(){
  $('a.agallery').lightBox();
});
$(document).ready(function() {
    $('#pause').click(function() { $('#slides').cycle('pause'); return false; });
    $('#play').click(function() { $('#slides').cycle('resume'); return false; });

    $('#slideshow').hover(
        function() { $('#controls').fadeIn(); },
        function() { $('#controls').fadeOut(); }
    );

    $('#slides').cycle({
        fx:     'scrollLeft,scrollDown,scrollRight,scrollUp,fade,zoom,blindX,blindY,blindZ,growX,growY,curtainX,curtainY',
        speed:   800,
        timeout: 4000,
        next:   '#next',
        prev:   '#prev'
    });
});
$(document).ready(function() {
    $("#makeMeScrollable").smoothDivScroll({
        autoScroll: "onstart",
        autoScrollDirection: "backandforth",
        autoScrollStep: 1,
        autoScrollInterval: 15,
        startAtElementId: "startAtMe",
        visibleHotSpots: "always" });
});