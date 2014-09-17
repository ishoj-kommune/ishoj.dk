
(function($) {
	
	$(document).ready(function() {

    
    
		
		var teaserCounter = 0; 
		$(".teaserSwap").each(function() {
			$("#teaserNav li a:eq(" + teaserCounter + ")").html($(this).find("h1").html());
			$("#teaserNav li a:eq(" + teaserCounter + ")").attr('title', $(this).find("h1").html());
			teaserCounter++;
			$(this).css("backgroundImage", "url(" + $(this).find("img").attr("src") + ")");
		});

		/* SELVBETJENINGSTEASER */
		$('.teaserWrap').flexslider({ animation:"fade", slideshow:true, controlNav:true, directionNav:false });
		$('.teaserWrap').data('flexslider');	
		$('.teaserBtn01').click(function() { $('.teaserWrap').flexslider(0); });
		$('.teaserBtn02').click(function() { $('.teaserWrap').flexslider(1); });
		$('.teaserBtn03').click(function() { $('.teaserWrap').flexslider(2); });
		/*$('.teaserBtn04').click(function() { $('.teaserWrap').flexslider(3); });*/		
		$(".teaserWrap .flex-control-nav:not([id])").addClass('hideMe');

		/* BILLEDGALLERI-BOX */		
		//$('#flex01').flexslider({ animation:"slide", slideshow:false, directionNav:false, controlsContainer:"#flexCon01" });

	
		if($(window).width() <= 720) {
			$(".omdoemmeThumb a.vimeo").each(function(){
				var newUrl = $(this).attr('href').replace('player.', '');
				newUrl = newUrl.replace('/video/', '/');
				$(this).attr('href', newUrl);
			});			
		}
		else {
			//$(".vimeo").colorbox({iframe:true, innerWidth:700, innerHeight:393});
		}

//		$(".vimeo").colorbox({iframe:true, innerWidth:500, innerHeight:409});


//		$(".omdoemmeThumb a.vimeo").attr("href").replace("player.", "").replace("/video/", "/");
		
/*		$(".detskeriishoj_forside").css('height', $(".detskeriishoj_forside img").clientHeight);
		alert($(".detskeriishoj_forside img").height());*/

	});

})(jQuery);



