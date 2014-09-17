// JavaScript Document
jQuery(function($){
	//image folder
	var imgs_url = theblogurl+'/wp-content/plugins/flickr-mini-gallery/images';
	function initialize_flickr(){
		if($('.flickr-mini-gallery')){
/*			if($('.fmg-hover-image')){
				$("body").append('<div id="fmg-float-img"><img class="fmg-float-img-loading" src="'+imgs_url+'/lightbox-ico-loading.gif" /><img class="fmg-float-img-tag" src=""/><p class="fmg-description"></p></div>');
			
			}
*/			
			$('.flickr-mini-gallery').each(function (i) {
					$(this).empty();					 
					var filter = $(this).attr('rel');
					var formatArray = $(this).attr("lang").split("&");
					var format = formatArray[0];
					var formatGal = formatArray[1];
					var hasTitle = $(this).hasClass("fmg-hover-image");
					var is_photoset = $(this).attr('longdesc');
					build_gallery(filter, this, format, hasTitle, is_photoset, formatGal);
					
			});
			
		}
		
		
	}
	function build_gallery(filter, obj, format, hasTitle, is_photoset, formatGal){
	  if(is_photoset == "photoset"){
	  	var api = "http://api.flickr.com/services/rest/?method=flickr.photosets.getPhotos&api_key=36c8b00c47e8934ff302dcad7775d0a2&"+filter;
	  }else{
	  	var api = "http://api.flickr.com/services/rest/?method=flickr.photos.search&api_key=36c8b00c47e8934ff302dcad7775d0a2&tag_mode=all&"+filter; 
	  }
		$.getJSON(api+"&format=json&jsoncallback=?",
	        function(data){
				
				// Opretter vindue-div'en hvori billederne skal vises
				//$('<div id="flickr-mini-gallery-window"></div>').appendTo(obj);

				// Opretter den relative vindue-div, hvori den absolute div skal placeres
				$('<div id="flickr-mini-gallery-window_rel"></div>').appendTo(obj);

				// Opretter div'en med ajax-loaderen
				$('<div id="flickr-mini-gallery-window_ajax-loader"></div>').appendTo('#flickr-mini-gallery-window_rel');

				// Opretter den absolutte vindue-div, hvori billederne skal vises
				$('<div id="flickr-mini-gallery-window_abs"></div>').appendTo('#flickr-mini-gallery-window_rel');
				
				
		        if(is_photoset == "photoset"){
		        	
					var windowCounter = 0;
		        	$.each(data.photoset.photo, function(i,item){   
		        		if(typeof item.description != "undefined"){
							var description = item.description._content;}
						else{
							var description = "";}
		        		if(hasTitle) {
							var titleImg = '';
						}else{
							var titleImg = item.title;
						}
						
						// eks.
						// url til ikon: http://farm6.static.flickr.com/5280/5870534312_1fbc5d0c08_s.jpg   _m
						// url til foto: http://farm6.static.flickr.com/5280/5870534312_1fbc5d0c08.jpg
						
						
						// opretter og viser det første foto i fotosettet
						if(windowCounter==0) {
							var attrib2 = { src: "http://farm"+item.farm+".static.flickr.com/"+item.server+"/"+item.id+"_"+item.secret+formatGal+".jpg"};
							//var attrib2 = { src: "http://farm"+item.farm+".static.flickr.com/"+item.server+"/"+item.id+"_"+item.secret+"_z.jpg"};
							//$("<img />").attr(attrib2).appendTo('#flickr-mini-gallery-window_abs');
							
							$("<img />").attr(attrib2).appendTo("#flickr-mini-gallery-window_abs").wrap('<a href="http://farm' + item.farm + '.static.flickr.com/' + item.server + '/' + item.id + '_' + item.secret + '_b.jpg"></a>');			
						}
						

						// attributter til img-tag'et
				    	var attrib = { src: "http://farm"+item.farm+".static.flickr.com/"+item.server+"/"+item.id+"_"+item.secret+format+".jpg", alt:item.title, longdesc:"http://www.flickr.com/photos/"+data.photoset.owner+"/"+item.id, rel:description, title:titleImg}
					  	//$("<img />").attr(attrib).appendTo(obj).wrap("<a href=http://farm" + item.farm + ".static.flickr.com/" + item.server + "/" + item.id + "_" + item.secret + formatGal + ".jpg alt=" + item.id + formatGal + "></a>").addClass("flickr-mini-gallery-thumb");
					  	$("<img />").attr(attrib).appendTo(obj).addClass("flickr-mini-gallery-thumb");
						
						// Sætter en border på den første thumb 
						if(windowCounter==0){
							$(".flickr-mini-gallery-thumb").css("border-color", "#70ac4a");	
							
							//Sætter meta-tagget for thumb til Facebook-deling
							$('meta[property="og:image"]').attr("content", "http://farm"+item.farm+".static.flickr.com/"+item.server+"/"+item.id+"_"+item.secret+format+".jpg");
							
						}

						// Gør at den sidste thumb bliver -1px i margenen, så der kan være 6 thumbs på en række
						if(((windowCounter+1) % 6) == 0){
							$(".flickr-mini-gallery-thumb:nth-child(7)").css("margin-right", "-1px");	
						}
						//alert((windowCounter + 1) % 6);
						windowCounter++;
			         });
		        }else{
		        	/*$.each(data.photos.photo, function(i,item){
		        		if(typeof item.description != "undefined"){var description = item.description._content;}else{var description = "";}
		        		if(hasTitle){var titleImg = '';}else{var titleImg = item.title;}
				       var attrib = {src: "http://farm"+item.farm+".static.flickr.com/"+item.server+"/"+item.id+"_"+item.secret+format+".jpg", alt:item.title, longdesc:"http://www.flickr.com/photos/"+item.owner+"/"+item.id, rel:description, title:titleImg}
					  $("<img/>").attr(attrib).appendTo(obj).wrap("<a href=http://farm"+item.farm+".static.flickr.com/"+item.server+"/"+item.id+"_"+item.secret+formatGal+".jpg alt="+item.id+formatGal+"></a>").addClass("flickr-mini-gallery-thumb");
			         });
		       */ }
		        
	          
	         
			 //$(".flickr-mini-gallery a:has(img)").lightBox();
			 $("#flickr-mini-gallery-window_abs a:has(img)").lightBox();
			 
			 
	      });	 
	}
	
	
	
		
	// Skifter vindue-foto ved klik på thumbnail
	$(".flickr-mini-gallery-thumb").live('click', function() {
		$(".flickr-mini-gallery-thumb").css("border-color", "#ffffff");
		$(this).css("border-color", "#70ac4a");
		var src = $(this).attr("src");
		//alert(src);
		var title = $(this).attr("alt");
		var img = src.replace("_t", "_m");
                //var img = src.replace("_t", "_z");
		//var url = img.replace("_s", "_m");
		var url2 = img.replace("_s", "_b");
		var url  = img.replace("_s", "");
		
		if($("#flickr-mini-gallery-window_abs img").attr("src") != url){ 
			$("#flickr-mini-gallery-window_abs img").hide();
			$("#flickr-mini-gallery-window_abs img").attr("src",url).load(function() {
  				$("#flickr-mini-gallery-window_abs img").fadeIn(500, function(){ 				
  				});
 			});
			$("#flickr-mini-gallery-window_abs a").attr("href", url2);
		}
	});



	
	// reveals bigger image when you pass the mouse over it
	$(".fmg-hover-image a:has(img)").live("mouseover", function(){
		var src = $("img", this).attr("src");
		var title = $("img", this).attr("alt");
		var img = src.replace("_t", "_m");
		var url = img.replace("_s", "_m");
		$("#fmg-float-img").show()
		$("#fmg-float-img .fmg-description").hide()		
		$("#fmg-float-img .fmg-float-img-loading").show()
		$("#fmg-float-img .fmg-float-img-tag").hide().attr("src",url).load(function() {
  			$("#fmg-float-img .fmg-float-img-loading").hide()
  			$(".fmg-float-img-tag").fadeIn(500, function(){
  				//console.log(title)
  				
  			});
  			$("#fmg-float-img .fmg-description").text(title).slideDown()
		})
	});
	
	$(".fmg-hover-image a:has(img)").live("mouseout", function(){
		$("#fmg-float-img").hide()
		$("#fmg-float-img .fmg-description").hide()		
		$("#fmg-float-img .fmg-float-img-loading").hide()
	});
	$('.fmg-hover-image').live("mousemove",function(e) {
		var pos = $(this).position()
		var h = $("#fmg-float-img").height() 
  		$("#fmg-float-img").css({top:e.pageY-40, left:e.pageX+20})
  		//console.log((e.pageY - pos.top) +", "+(e.pageX - pos.left))
	});
	
	function add_description(n){
		//var img_id = $(".felickr a[alt]:eq["+n+"]");
		var img_id = '2388852124';
		$.getJSON('http://api.flickr.com/services/rest/?method=flickr.photos.getInfo&api_key=36c8b00c47e8934ff302dcad7775d0a2&photo_id='+img_id+'&format=json&jsoncallback=?',
	        	function(data){
					var textInfo = data.photo.description._content;
					$(".felickr:first").append(textInfo+"<br/>");					
	         	});
	}
	function description(){
		$(".felickr img").each(function(i){
				add_description(i)						
		})
	}
	$(document).ready(function(){
		initialize_flickr()	;
		

	


		
		
	});
});
