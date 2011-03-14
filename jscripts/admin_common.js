$(document).ready(function() {
  $('ul.sf-menu').superfish();
});

function update_sub_categories_tree(parent_id)
{
  $.get("/admin/categories/" + parent_id + "/products", function(data){
    $("#sub_cat_con").html(data);
  });
}

function trim(str, chars) {
	return ltrim(rtrim(str, chars), chars);
}

function ltrim(str, chars) {
	chars = chars || "\\s";
	return str.replace(new RegExp("^[" + chars + "]+", "g"), "");
}

function rtrim(str, chars) {
	chars = chars || "\\s";
	return str.replace(new RegExp("[" + chars + "]+$", "g"), "");
}