(function($) {

	$(document).ready(function() {
		
		/**************************************/
		/****** Selvbetjenings accordion ******/
		/**************************************/

		$(".foldudContent, .foldud_alfabetisk, .foldud_sog").addClass("hideMe");		
		$(".foldudknap > h3").each(function() {
			$(this).wrap('<div />');
		});
	
		// Åbner/lukker den enkelte listitem, der klikkes på
		function foldalleind(i, j){
			if(!j) 
				j = 200;
			if(i) {
				$(".foldudContentSub .foldudContent, .foldud_alfabetisk .foldudContentSub .foldudContent").each(function() {
					$(this).slideUp(j, "easeOutQuart");
					$(this).parent().removeClass("foldindknap");
					if($(this).hasClass("isExpanded")) {
						$(this).removeClass("isExpanded");					
					}
				});
			}
			else {
				$(".foldudknap ul.foldudContent").each(function() {
					$(this).slideUp(j, "easeOutQuart");
					$(this).parent().find("> div").removeClass("foldudGreen");
					$(this).parent().removeClass("foldindknap");
					if($(this).hasClass("isExpanded")) {
						$(this).removeClass("isExpanded");
					}
				});
				$(".foldudContentSub .foldudContent, .foldud_alfabetisk .foldudContentSub .foldudContent").each(function() {
					$(this).slideUp(j, "easeOutQuart");
					$(this).parent().removeClass("foldindknap");
					if($(this).hasClass("isExpanded")) {
						$(this).removeClass("isExpanded");					
					}
				});
			}
		}	
		
		/* SELVBETJENINGSEMNER */
		$(".foldudknap").click(function() {
			if($(this).find("> .foldudContent").hasClass("isExpanded")) {
				foldalleind(1);
			}
			else {
				foldalleind();
			}
			$(this).find("ul.foldudContent").slideToggle(350, "easeOutQuart");
			if(!$(this).find("ul.foldudContent").hasClass("isExpanded")) {
				$(this).find("ul.foldudContent").addClass("isExpanded");
				$(this).find("> div").addClass("foldudGreen");
				$(this).addClass("foldindknap");
			}
			else {
				$(this).find("ul.foldudContent").removeClass("isExpanded");
				$(this).find("> div").removeClass("foldudGreen");
				$(this).removeClass("foldindknap");
			}
		});	
		
		/* SELVBETJENINGSLØSNINGER */
		$(".foldudContentSub li").click(function() {
			if(!$(this).find(".foldudContent").hasClass("isExpanded")) {
				foldalleind(1);
			}
			$(this).find("div.foldudContent").slideToggle(350, "easeOutQuart");			
			if(!$(this).find("div.foldudContent").hasClass("isExpanded")) {
				$(this).find("div.foldudContent").addClass("isExpanded");
				$(this).addClass("foldindknap");
			}
			else {
				$(this).find("div.foldudContent").removeClass("isExpanded");
				$(this).removeClass("foldindknap");
			}
		});		
	
		// Sørger for, at den ikke folder ind igen ved klik på selve tekst-indholdet
		$(".foldudContent").click(function(e) {
			e.stopPropagation();
		});

		/* FOLDUD TABS */
		$(".foldudTab").click(function(){
			if(!$(this).hasClass("foldudTabActive")){
				if($(this).is("#tabEmne")){
					$(".foldud").removeClass("hideMe");
					$(".foldud_alfabetisk, .foldud_sog").addClass("hideMe");
				}
				if($(this).is("#tabAlfabetisk")){
					$(".foldud_alfabetisk").removeClass("hideMe");
					$(".foldud, .foldud_sog").addClass("hideMe");
				}
				if($(this).is("#tabSoeg")){
					$(".foldud_sog").removeClass("hideMe");
					$(".foldud, .foldud_alfabetisk").addClass("hideMe");
				}
				$(".foldudTab").removeClass("foldudTabActive");
				$(this).addClass("foldudTabActive");
				foldalleind(0,1);
			}	
		});

		// Rens Drupal-output
		$("#edit-s").removeClass("required").removeClass("error");
		$("#edit-submit-selvbetjening-search").addClass("box");
		
		var selvbetjeningUrl 	 = document.location.href;
		var sogePatternStr 		 = "/selvbetjening?s=";
		var emnePatternStr 		 = "/selvbetjening?e=";
		var alfabetiskPatternStr = "/selvbetjening?a=";
		
		/* Hvis der er søgt på en selvbetjeningsløsning */
		if(selvbetjeningUrl.indexOf(sogePatternStr) > -1) {
			$(".foldud_sog").removeClass("hideMe");
			$(".foldud, .foldud_alfabetisk").addClass("hideMe");
			$(".foldudTab").removeClass("foldudTabActive");	
			$("#tabSoeg").addClass("foldudTabActive");
		} 
		
		/* Hvis der er valgt et selvbetjeningsemne */
		if(selvbetjeningUrl.indexOf(emnePatternStr) > -1) {
			var emneResultStr = selvbetjeningUrl.split(emnePatternStr);
			$(".foldudknap:nth-child(" + emneResultStr[1] + ")").find("ul.foldudContent").slideToggle().addClass("isExpanded");
			$(".foldudknap:nth-child(" + emneResultStr[1] + ")").find("> div").addClass("foldudGreen");
			$(".foldudknap:nth-child(" + emneResultStr[1] + ")").addClass("foldindknap");
			var emneA = 1;
			$(".foldudknap > div").each(function(){
				$(this).prepend("<a name=\"e" + emneA + "\"></a>");
				emneA++;
			});
			location.hash = "#e" + (emneResultStr[1]-1);
		}
		
		/* Hvis der er valgt en "Hvis du"-selvbetjeningsløsning */
		if(selvbetjeningUrl.indexOf(alfabetiskPatternStr) > -1) {
			$(".foldud_alfabetisk").removeClass("hideMe");
			$(".foldud, .foldud_sog").addClass("hideMe");
			$(".foldudTab").removeClass("foldudTabActive");	
			$("#tabAlfabetisk").addClass("foldudTabActive");
			var alfabetiskResultStr = selvbetjeningUrl.split(alfabetiskPatternStr);
			$('a[name="a' + alfabetiskResultStr[1] + '"]').parent().find("div.foldudContent").slideToggle().addClass("isExpanded");
			$('a[name="a' + alfabetiskResultStr[1] + '"]').parent().addClass("foldindknap");
			location.hash = "#a" + (alfabetiskResultStr[1]);
		}

	});
	
})(jQuery);




