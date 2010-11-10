$(document).ready(function() {
  $('ul.sf-menu').superfish();
});

function update_sub_categories_tree(parent_id)
{
  $.get("/admin/categories/" + parent_id + "/products", function(data){
    $("#sub_cat_con").html(data);
  });
}