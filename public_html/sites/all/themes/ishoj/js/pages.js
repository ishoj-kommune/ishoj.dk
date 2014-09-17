
// Debouncing ensures that exactly one signal is sent for an event that may be happening several times 
// http://paulirish.com/2009/throttled-smartresize-jquery-event-handler/
(function($,sr){
 
  // debouncing function from John Hann
  // http://unscriptable.com/index.php/2009/03/20/debouncing-javascript-methods/
  var debounce = function (func, threshold, execAsap) {
      var timeout;
 
      return function debounced () {
          var obj = this, args = arguments;
          function delayed () {
              if (!execAsap)
                  func.apply(obj, args);
              timeout = null; 
          };
 
          if (timeout)
              clearTimeout(timeout);
          else if (execAsap)
              func.apply(obj, args);
 
          timeout = setTimeout(delayed, threshold || 100); 
      };
  }
	// smartresize 
	jQuery.fn[sr] = function(fn){  return fn ? this.bind('resize', debounce(fn)) : this.trigger(sr); };
 
})(jQuery,'smartresize');

// Funktion til at tjekke om et element eksisterer i DOM'en
// Kaldes fx via $(".frontRightCol2").exist() - returnerer true/false
(function($) {
	if (!$.exist) {
		$.extend({
			exist: function(elm) {
				if (typeof elm == null) return false;
				if (typeof elm != "object") elm = $(elm);
				return elm.length ? true : false;
			}
		});
		$.fn.extend({
			exist: function() {
				return $.exist($(this));
			}
		});
	}
})(jQuery);
 

/*************************/
/*** GLOBALE VARIABLER ***/
/*************************/
contentNavigationIsList = 0; // bruges til at angive om contentNavigationen er i thumbnails eller som liste
contentNavigationDescriptionLength = 100;
frontFillerActive = 0; // bruges til at angive om der skal sættes en frontFiller

(function($) {

	$(document).ready(function() {
		
		
		// Tester om browseren understøtter position:fixed. Det er især et problem ved nogle browsere i mobiler. 
		// Se http://kangax.github.com/cft/#IS_POSITION_FIXED_SUPPORTED
		function isPositionFixedSupported() {
			var container = document.body;
	  
			if (document.createElement && container && container.appendChild && container.removeChild) {
				var el = document.createElement('div');
				
				if (!el.getBoundingClientRect) return null;
					
				el.innerHTML = 'x';
				el.style.cssText = 'position:fixed;top:100px;';
				container.appendChild(el);
				
				var originalHeight = container.style.height,
					originalScrollTop = container.scrollTop;
				
				container.style.height = '3000px';
				container.scrollTop = 500;
				
				var elementTop = el.getBoundingClientRect().top;
				container.style.height = originalHeight;
				
				var isSupported = (elementTop === 100);
				container.removeChild(el);
				container.scrollTop = originalScrollTop;
				
				return /*null*/isSupported;
			}
			return null;
		}	

		var positionFixedIsSupported = isPositionFixedSupported();

	
		// Funktion til at vise/skjule den mobile udgave af navigationsmenuen
		function setNavigation() {
			
			var windowWidth = $(window).width();

			/*if(windowWidth <= 480 && $(".mobileNavBtn").hasClass("hideMe")) {*/	
			if(windowWidth <= 800 && $(".mobileNavBtn").hasClass("hideMe")) {
				$(".mobileNavBtn").removeClass("hideMe"); // Vis Mobil-navigationsknappen
				$(".mainMenu").addClass("hideMe");     // Skjul alm. menu
				
				//Tilføjer runde hjørner til Hjemmeside-vælgeren
				$(".sitePickerBtn").addClass("round3");
				
				// Hvis der ikke allerede er blevet klonet én gang før
/*				if($("[data-role="mobilenav"] > *").length == 0) {*/

					// Klon alle elementer i Hovedmenuen til [data-role="mobilenav"] - og tilføj klasser
/*					$(".mainMenu > li").each(function() { 
						var	$cloned = $(this).clone();
						$cloned.addClass("mobileNav"),
						$cloned.addClass("isCloned");
						if($cloned.has("roundTop")) {
							$cloned.removeClass("roundTop");
						};
						$cloned.appendTo("[data-role="mobilenav"]");
					});*/				
					// Klon alle elementer i Alternativ menu til [data-role="mobilenav"] - og tilføj klasser
/*					$(".altMenu li").each(function() {
						var $cloned = $(this).clone();
						$cloned.addClass("mobileNav"),
						$cloned.addClass("isCloned"),
						$cloned.appendTo("[data-role="mobilenav"]");
					}); */				
					// Hvis der er et ulige antal i "50/50 menuen", så smid en <li>-dummy ind
/*					if($("[data-role="mobilenav"] > li").length % 2 != 0) {
						$("[data-role="mobilenav"]").append('<li class="mobileNav isCloned"></li>');
					};*/				
					
/*					$("[data-role="mobilenav"] li .menuSub").addClass("hideMe");*/
/*				}*/
				
				$(".altMenu").addClass("hideMe");
				
				// Flyt søgeboksen til mobil menuen
				/*$("#search").appendTo(".mobilSearchTarget");*/
				$("#apachesolr-panels-search-block").appendTo(".mobilSearchTarget");
			}
			
			/*if(windowWidth > 480 && !$(".mobileNavBtn").hasClass("hideMe")) {*/
			if(windowWidth > 800 && !$(".mobileNavBtn").hasClass("hideMe")) {
				$(".mobileNavBtn").addClass("hideMe");
				$(".mainMenu").removeClass("hideMe");
				$(".altMenu").removeClass("hideMe");

				if(menuStatus) {
/*					$("#mobileContainer").slideToggle(0).addClass("hideMe");*/

					if($("html").hasClass("no-csstransitions")) {
						$("[data-role='page']").animate({ left:0, }, 0);
						$("[data-role='mobilenav']").animate({ left:-100, }, 0);
					}
					else { 
						$("[data-role='page']").css("left", 0);
						$("[data-role='mobilenav']").css("left", -100);
					}
		
					$("[data-role='page']").removeClass("positionFixed");
					//$("[data-role='page'] .dimmer").addClass("hideMe"); 
					dimmer();
					menuStatus = false;
				
				
/*				}
*/
				
/*				if(!$('[data-role="mobilenav"]').hasClass("hideMe")) {

					$(".ui-page-active").animate({ marginLeft: "0px", }, 0, function() {
						menuStatus = false;
						$('[data-role="mobilenav"]').addClass("hideMe");
					});*/
					$(".mobileNavBtn").removeClass("greenBtn");
					$(".mobileNavImg").removeClass("mobileNavImgOn");
		
					
/*					$("[data-role="mobilenav"]").slideToggle("fast").addClass("hideMe");
					$(".mobileNavBtn").removeClass("greenBtn");
					$(".mobileNavImg").removeClass("mobileNavImgOn");*/
				}
				// Fjerner runde hjørner til Hjemmeside-vælgeren
				$(".sitePickerBtn").removeClass("round3");
				
				// Flyt søgeboksen til oprindelig position
				//$("#apachesolr-panels-search-block").appendTo(".searchOrigin div div div:not(.contextual-links-wrapper)");
				$("#apachesolr-panels-search-block").appendTo(".searchOrigin div div div");
				if($(".searchPickerBtn div").hasClass("searchPickerImgUp")) {
					$(".searchPickerBtn div").removeClass("searchPickerImgUp");
					$(".searchPickerBtn").removeClass("greenBtn");
					$(".mobilSearchTarget").css("height", "0");	
				}	

				/*$("#search").appendTo(".searchOrigin");*/
			}
			
			
			
		}
		

		/*var initContentNavigationThumb = false;*/
				
		function setStructure(init) {
			var windowWidth = $(window).width();
			
			if(!contentNavigationIsList) { // Hvis der ikke er klikket på liste-knappen
				if(windowWidth <= 640) {
					contentNavigationSetList(1,0); // Sæt ContentNavigation til liste-form men uden at sætte en cookie
					//$(".contentNavigationBtnContainer").addClass("hideMe");
				}
				else {
					contentNavigationSetList(0,0); // Sæt ContentNavigation tilbage til thumbnails men uden at sætte en cookie
					//$(".contentNavigationBtnContainer").removeClass("hideMe");
				}			
			}
			
//			if(!$(".contentNavigationInner").hasClass("contentNavigationList")) {
				// initiering af højden på ContentNavigationsThumbs
				if(init) {
					setTimeout(function(){setThumbsHighestHight(1)},500);
				}
				else {
					setThumbsHighestHight(1);
				}
/*				if(!initContentNavigationThumb) {
					setTimeout(function(){setThumbsHighestHight(1)},500);
					initContentNavigationThumb = true;
				}
				else {
					setThumbsHighestHight(1);
				}*/
//			}
			
			
			// Flytte Content Navigation til target
/*			if(windowWidth <= 540) {
				$(".contentNavigation").appendTo(".contentNavigationTarget");
			}
			else {
				$(".contentNavigation").appendTo(".contentNavigationOrigin");				
			}		*/	

			
			
			if(windowWidth <= 800) {
				$(".contentNavigation").appendTo(".contentNavigationTarget"); // Flytte Content Navigation til target
				$(".asideSelvbetjening").appendTo(".selvbetjeningTarget");    // Flytte selvbetjeningsboksen til target
				normalizeFrontPageElements(0);
				$("#top").addClass("positionFixed").css("z-index", 99999);
				
				if($(".frontFiller").exist()) {
					$(".frontLeftCol1 > *:not(.nyhedsliste)").appendTo(".frontRightCol2.target");
					if(frontFillerActive) {
						setFrontFiller();
					}
				}
				//setFixedTopWidth(windowWidth);
			}
			else {
				$(".contentNavigation").appendTo(".contentNavigationOrigin");	
				/*$(".asideSelvbetjening").appendTo(".selvbetjeningOrigin");*/
				$(".asideSelvbetjening").prependTo(".subRightCol1");
				
				// Normaliserer højden parvis på children i 1. niveau under parent-elementet .frontRightCol2 
				if(init) {
					setTimeout(function(){normalizeFrontPageElements(1)},300);
					setTimeout(function(){normalizeFrontPageElements(1)},800);
					setTimeout(function(){normalizeFrontPageElements(1)},1200);
					//setTimeout(function(){setFrontFiller(1)},300);
				}
				else {	
					normalizeFrontPageElements(1);
					//setFrontFiller(1);
				}

				$("#top").removeClass("positionFixed").css("z-index", 'auto');
				
				if($(".frontFiller").exist()) {
					$(".frontRightCol2.target > *").appendTo(".frontLeftCol1");
					$(".frontLeftCol1 > *:not(.nyhedsliste)").each(function(){
						$(this).css("height", "auto");	
					});
					if(frontFillerActive) {
						setTimeout(function(){setFrontFiller()},300);
					}
				}				
				
			}
			// Udkommenter dette til KV2013 - start
			if(windowWidth > 1024) {
				//flyt boks til teaser
				$("#teaserBox").appendTo(".teaserWrap .teaser");
				//skjul teasertarget
				$(".teaserWrapTarget").hide();
				//vis teaser
				$(".teaserWrap").show();
				
			}	
			else {
				//flyt boks til teaserTarget
        $("#teaserBox").appendTo(".teaserTarget");
				//vis teasertarget
        $(".teaserWrapTarget").show();
				//skjul teaser
				$(".teaserWrap").hide();
			}
			// Udkommenter dette til KV2013 - slut

		}
		
		
		function initContentNavigation() {
			$(".contentNavigationBtnContainer").removeClass("hideMe");
			
			// Hvis cookien eksisterer
			if($.cookie("cookieContentNavigation") == "list") {
				contentNavigationSetList(1,1);
			}
			
			// Klipper længden på ContentNavigation-beskrivelserne (p-elementerne), 
			// så de passer til længden defineret i den globale variabel, contentNavigationDescriptionLength.
			$(".contentNavigationInner p").each(function(){
				$(this).html($(this).html().substr(0,contentNavigationDescriptionLength));
			});
		}
		
		// Initiering 
		setNavigation();
		setStructure(1);
		initContentNavigation();
					

		// Usage:
	    $(window).smartresize(function() {
			// code that takes it easy...
			setNavigation();
			setStructure();
			//getHighestNavigationThumb();
		});    



		/***************************************/
		/*** SÆTTER BREDDEN PÅ TOPBAREN #top ***/
		/***************************************/	
		function setFixedTopWidth(windowWidth){
			$("#top").css('width', windowWidth);
		}

		/******************************************/
		/*** CONTENT NAVIGATION SET LIST/THUMBS ***/
		/******************************************/	
		
		function getHighestNavigationThumb() {
			var h = 0;
			var h2 = 0;
			$(".contentNavigation li").each(function() {  // init menu - fjern active-klasse sat på af drupal 
				$(this).find("a:first").css("height", "auto");
				h2 = $(this).height(); 
				if(h2 > h)
					h = h2;
			});
			return h;
		}

		function setThumbsHighestHight(a) {
			var h = getHighestNavigationThumb() + "px";
			$(".contentNavigation li a").each(function() {
				if(a && !$(".contentNavigationInner").hasClass("contentNavigationList")) 
					$(this).css("height", h);
				else 
					$(this).css("height", "auto");
			}); 
		}
				
		function contentNavigationSetList(a,b){
			if(a) {
				$(".contentNavigationInner").addClass("contentNavigationList").addClass("round3").addClass("box");
				$(".contentNavigation li").removeClass("box");
				$(".contentNavigationBtn[data-info='list']").addClass("contentNavigationBtnOnList").removeClass("contentNavigationBtnOffList");
				$(".contentNavigationBtn[data-info='thumbs']").removeClass("contentNavigationBtnOnThumbs").addClass("contentNavigationBtnOffThumbs");

				setThumbsHighestHight(0); 				

				if(b) {
					contentNavigationIsList = 1;
					$.cookie("cookieContentNavigation", "list", { expires: 1, path: '/' });
				}
			}
			else {
				$(".contentNavigationInner").removeClass("contentNavigationList").removeClass("round3").removeClass("box");
				$(".contentNavigation li").addClass("box");
				$(".contentNavigationBtn[data-info='thumbs']").addClass("contentNavigationBtnOnThumbs").removeClass("contentNavigationBtnOffThumbs");
				$(".contentNavigationBtn[data-info='list']").removeClass("contentNavigationBtnOnList").addClass("contentNavigationBtnOffList");

				setThumbsHighestHight(1);
				
				if(b) {
					contentNavigationIsList = 0;		
					$.cookie("cookieContentNavigation", "list", { expires: -1, path: '/' });
				}
//				$.cookie("cookieContentNavigation", "thumbs", { expires: -1, path: '/ishoj/' });
			}
		}


		/*******************************************/
		/*** CONTENT NAVIGATION LIST/THUMBS KNAP ***/
		/*******************************************/			
		$(".contentNavigationBtn[data-info='list']").click(function() {
			contentNavigationSetList(1,1);
		});
		
		
		$(".contentNavigationBtn[data-info='thumbs']").click(function() {
			contentNavigationSetList(0,1);
		});
		


		/*********************************/
		/*** FIND MOBIL-MENUENS BREDDE ***/
		/*********************************/			
		function getMobileMenuWidth(){
			var windowWidth = $(window).width();
			var visibleArea = 70;
			var mobileMenuWidth = 0;
			
			if(windowWidth <= 480) {
				mobileMenuWidth = windowWidth - visibleArea;
			}
			else {
				mobileMenuWidth = 480 - visibleArea;
			} 
			return mobileMenuWidth;
		}


		/***************************/
		/*** MOBIL MENU KNAP V.2 ***/
		/***************************/	
		var menuStatus = false;
	 
		// Klik på menuknap
		$(".mobileNavBtn").click(function() {
			if (!menuStatus) {
				
				/* SITE PICKER BUTTON */
				if($(".sitePickerBtn div").hasClass("sitePickerImgUp")) {
					$(".sitePickerBtn div").removeClass("sitePickerImgUp");
					$(".sitePickerBtn").removeClass("greenBtn");
					$('.sitePickerSectionInner').slideToggle('fast');	
				}	
							
				/* SEARCH PICKER BUTTON */
				if($(".searchPickerBtn div").hasClass("searchPickerImgUp")) {
					$(".searchPickerBtn div").removeClass("searchPickerImgUp");
					$(".searchPickerBtn").removeClass("greenBtn");
					$(".mobilSearchTarget").css("height", "0");	
				}
				
				
				//////////$("#top").removeClass("positionFixed").css("z-index", 'auto');
				/*$(".sitePickerSection").css("margin-top", 0);*/
				
				//$('.mobilSearchTarget, [data-role="mobilenav"]').css("width", getMobileMenuWidth());
				
/*				$(".ui-page-active").animate({ marginLeft:getMobileMenuWidth(), }, 200, function() { 

						$("div[data-role='page']").addClass("positionFixed"); // test af fixed position
					menuStatus = true;
				});
	
				$('[data-role="mobilenav"]').removeClass("hideMe");*/
				
				/**************************************************/
	
//				$("[data-role='mobilenav'], .mobilSearchTarget").css("width", getMobileMenuWidth()-3); // (-3 er pga. en border-right på 3px) 
				$("[data-role='mobilenav']").css("width", getMobileMenuWidth()-3); // (-3 er pga. en border-right på 3px) 

				if($("html").hasClass("no-csstransitions")) {
					$("[data-role='page']").animate({ left:getMobileMenuWidth(), }, 300);
					$("[data-role='mobilenav']").animate({ left:0, }, 300);
				}
				else {
					$("[data-role='page']").addClass("animate").css("left", getMobileMenuWidth());
					$("[data-role='mobilenav']").addClass("animate").css("left", 0);
				}

				$("[data-role='page']").addClass("positionFixed");
				setTimeout(function(){dimmer(1)},50); 
				menuStatus = true;

				/**************************************************/
				
				$(".mobileNavBtn").addClass("greenBtn");
				$(".mobileNavImg").addClass("mobileNavImgOn");			
	
				/*return false;*/
			} 
			else {
				
				/****************************************************/
				
				if($("html").hasClass("no-csstransitions")) {
					$("[data-role='page']").animate({ left:0, }, 300);
					$("[data-role='mobilenav']").animate({ left:-100, }, 300);
				}
				else { 
					$("[data-role='page']").css("left", 0);
					$("[data-role='mobilenav']").css("left", -100);
				}
				
				$("[data-role='page']").removeClass("positionFixed");
				dimmer(); 
				menuStatus = false;	
				
				/****************************************************/				
				
//				if(positionFixedIsSupported) 
				///////////$("#top").addClass("positionFixed").css("z-index", 99999);
				//$('div[data-role="content"]').css("padding-top", '1.75em !important');
				/*$(".sitePickerSection").css("margin-top", '3.25em');*/
/*				$("div[data-role='page']").removeClass("positionFixed"); // test af fixed position
				$(".ui-page-active").animate({ marginLeft: "0px", }, 200, function() {
					menuStatus = false;
					$('[data-role="mobilenav"]').addClass("hideMe");
				});*/
				
				$(".mobileNavBtn").removeClass("greenBtn");
				$(".mobileNavImg").removeClass("mobileNavImgOn");
	
				/*return false;*/
			}
		});
		
		/* "Disabler" data-role=page */
		function dimmer(i) {
			if(i) {
				$("[data-role='page'] .dimmer").css("top", $("#mobile").height()).fadeIn(250);
			}
			else {
				$("[data-role='page'] .dimmer").fadeOut(300);
			}
		}
		
		
		
		// Swipe mod venstre (luk)
/*		$('body, [data-role="mobilenav"], .pageSwipe').live("swipeleft", function() {
			if (menuStatus) {
				if(positionFixedIsSupported) 
					$("div[data-role='page']").removeClass("positionFixed");
				$(".ui-page-active").animate({ marginLeft: "-1px", }, 200, function() {
					$(".ui-page-active").animate({ marginLeft: "0px", }, 1); // swipefix (x -> -1px -> 0)
					$("[data-role="mobilenav"]").addClass("hideMe");
					$(".mobileNavBtn").removeClass("greenBtn");
					$(".mobileNavImg").removeClass("mobileNavImgOn");
					menuStatus = false;
				});
			}
		});
*/		
		// Swipe mod højre (åbn)
/*		$('.pageSwipe').live("swiperight", function() {
			if (!menuStatus && ($(window).width() <= 768)) {
				if($('.sitePickerBtn div').hasClass("sitePickerImgUp")) { 
					$('.sitePickerBtn div').removeClass("sitePickerImgUp");
					$('.sitePickerBtn').removeClass("greenBtn");					
					$('.sitePickerSectionInner').slideToggle('fast');		
				}
			
				$(".ui-page-active").animate({ marginLeft:getMobileMenuWidth(), }, 200, function() { 
					if(positionFixedIsSupported)
						$("div[data-role='page']").addClass("positionFixed");
					menuStatus = true;
				});
	
				$("[data-role="mobilenav"]").removeClass("hideMe");
				$(".mobileNavBtn").addClass("greenBtn");
				$(".mobileNavImg").addClass("mobileNavImgOn");			
			}
		});*/
		
/*		$('div[data-role="page"]').live('pagebeforeshow', function(event, ui) {
			menuStatus = false;
			$(".pageSwipe").css("margin-left", "0");*/
			//return false;
/*		});	*/
	
/*    $(".mobileNavBtn").click(function() {
        if (!menuStatus) {
            $(".ui-page-active").animate({ marginLeft:"165px", }, 200, function() { 
				menuStatus = true;
            });
            return false;
        } 
		else {
            $(".ui-page-active").animate({ marginLeft: "0px", }, 200, function() {
                menuStatus = false;
            });
            return false;
        }
    });*/
	
	
 
 	// Swipe mod venstre
/*    $('#minmobilmenu, .pageSwipe').live("swipeleft", function() {
        if (menuStatus) {
            $(".ui-page-active").animate({ marginLeft: "0px", }, 200, function() {
                menuStatus = false;
            });
        }
    });*/
	
	// Swipe mod højre
/*    $('.pageSwipe').live("swiperight", function() {
        if (!menuStatus) {
            $(".ui-page-active").animate({ marginLeft: "165px", }, 200, function() {
                menuStatus = true;
            });
        }
    });*/
 
	
				
/*		$(".mobileNavBtn").click(function() {
			//$(".mainMenu").slideToggle("slow");
			if($("[data-role="mobilenav"]").hasClass("hideMe")) {
				
				if($('.sitePickerBtn div').hasClass("sitePickerImgUp")) { 
					$('.sitePickerBtn div').removeClass("sitePickerImgUp");
					$('.sitePickerBtn').removeClass("greenBtn");					
					$('.sitePickerSectionInner').slideToggle('fast');		
				}

				$("[data-role="mobilenav"]").slideToggle("fast").removeClass("hideMe");
				$(".mobileNavBtn").addClass("greenBtn");
				$(".mobileNavImg").addClass("mobileNavImgOn");
			}
			else {
				
				$("[data-role="mobilenav"]").slideToggle("fast").addClass("hideMe");
				$(".mobileNavBtn").removeClass("greenBtn");
				$(".mobileNavImg").removeClass("mobileNavImgOn");
			}
		});*/


		/***********************/
		/*** MOBIL MENU KNAP ***/
		/***********************/			
/*		$(".mobileNavBtn").click(function() {
			//$(".mainMenu").slideToggle("slow");
			if($("[data-role="mobilenav"]").hasClass("hideMe")) {
				
				if($('.sitePickerBtn div').hasClass("sitePickerImgUp")) { 
					$('.sitePickerBtn div').removeClass("sitePickerImgUp");
					$('.sitePickerBtn').removeClass("greenBtn");					
					$('.sitePickerSectionInner').slideToggle('fast');		
				}

				$("[data-role="mobilenav"]").slideToggle("fast").removeClass("hideMe");
				$(".mobileNavBtn").addClass("greenBtn");
				$(".mobileNavImg").addClass("mobileNavImgOn");
			}
			else {
				
				$("[data-role="mobilenav"]").slideToggle("fast").addClass("hideMe");
				$(".mobileNavBtn").removeClass("greenBtn");
				$(".mobileNavImg").removeClass("mobileNavImgOn");
			}
		});*/



		/*************************************/
		/*** MOBIL MENU NAVIGATIONSKNAPPER ***/
		/*************************************/			 
		$('[data-role="mobilenav"] li').each(function() {  // init menu - fjern active-klasse sat på af drupal 
			$(this).removeClass("active");
		});
		
		function getMobileMenuSpeed(e) {
			var speed = 450;
			var count = e.find("ul:first").children().length;
			if(count < 15)
				speed = 350;
			if(count < 10)
				speed = 250;
			if(count < 5)
				speed = 150; 
			return speed;	
		}
		
		$('[data-role="mobilenav"] li.menuparent, [data-role="mobilenav"] li.expanded').click(function(){ // mobilmenu-knapper med children
			if($(this).hasClass("active")) {
				$(this).removeClass("active");
				$(this).find("ul:first").slideToggle(getMobileMenuSpeed($(this)));
			}
			else {
				$('[data-role="mobilenav"] li.menuparent, [data-role="mobilenav"] li.expanded').each(function() { 
					$(this).removeClass("active");
					$(this).find("ul:first").slideUp(getMobileMenuSpeed($(this)));
				});
				if($(this).find("a").html() != "Om os") {
					$(this).addClass("active");	
				}
				$(this).find("ul:first").slideToggle(getMobileMenuSpeed($(this)));		
			}
		});


		/***********************************************************************/
		/*** FORSIDEN: NORMALISERER HØJDEN PÅ DIV'ERNE UNDER PARENT-ELEMENTET ***/
		/***********************************************************************/	
		function normalizeFrontPageElements(x) {
			if($(".frontRightCol2").exist()) {
				$(".frontRightCol2").each(function(){

					$(this).find("> *").each(function() {
						$(this).css("height", "auto");
					});
	
					if(x) {
						var element = $(this).find("> *");
						for(var i = 0; i < element.length; i += 2) {
							var curSet = element.slice(i, i + 2), 
							height = 0;
							curSet.each(function() { 
								height = Math.max(height, $(this).height()); 
							}).css('height', height);
							//console.log(height);
						}
					}
				});
			}
		}

		/************************************************/
		/*** FORSIDEN: SÆTTER HØJDEN PÅ FRONTFILLEREN ***/
		/************************************************/	
		function setFrontFiller(x) {
			if($(".frontFiller").exist()) {
				$(".frontFiller").css("height", "auto");
				
				if($(".frontRight").height() > $(".frontLeft").height()) {
					var diff = $(".frontRight").height() - $(".frontLeft").height()
					//$(".frontFiller").css("height", (diff - 32));
					$(".frontFiller").css("height", diff);
				}
				//$(".frontFiller").addClass("hideMe").removeClass("hideMe");
				//$(".frontFiller").addClass("hideMe").removeClass("hideMe");
			}
		}






		/**************************/
		/*** SEARCH PICKER KNAP ***/
		/**************************/		
		$('.searchPickerBtn').click(function(){
			if(!$(".searchPickerBtn div").hasClass("searchPickerImgUp")) {

				/* SITE PICKER BUTTON */
				if($(".sitePickerBtn div").hasClass("sitePickerImgUp")) {
					$(".sitePickerBtn div").removeClass("sitePickerImgUp");
					$(".sitePickerBtn").removeClass("greenBtn");
					$('.sitePickerSectionInner').slideToggle('fast');	
				}				
				
				$(".searchPickerBtn div").addClass("searchPickerImgUp");
				$(".searchPickerBtn").addClass("greenBtn");

				if($("html").hasClass("no-csstransitions")) {
					$(".mobilSearchTarget").animate({ height:90, }, 150);
				}
				else {
					$(".mobilSearchTarget").css("height", "90px");	
				}			
			}			
			else {
				$(".searchPickerBtn div").removeClass("searchPickerImgUp");
				$(".searchPickerBtn").removeClass("greenBtn");

				if($("html").hasClass("no-csstransitions")) {
					$(".mobilSearchTarget").animate({ height:0, }, 150);
				}
				else {
					$(".mobilSearchTarget").css("height", "0");	
				}			
			}
			window.scrollTo(0, 0);
		});	


		/************************/
		/*** SITE PICKER KNAP ***/
		/************************/		

		/*$('.sitePickerSectionInner').hide();*/

		$('.sitePickerBtn').click(function(){
			
			if(!$('.sitePickerBtn div').hasClass("sitePickerImgUp")) {
				
				/* SEARCH PICKER BUTTON */
				if($(".searchPickerBtn div").hasClass("searchPickerImgUp")) {
					$(".searchPickerBtn div").removeClass("searchPickerImgUp");
					$(".searchPickerBtn").removeClass("greenBtn");
					$(".mobilSearchTarget").css("height", "0");	
				}
				
/*				if(!$('[data-role="mobilenav"]').hasClass("hideMe")) {
					$('[data-role="mobilenav"]').slideToggle("fast").addClass("hideMe");

					$(".mobileNavBtn").removeClass("greenBtn");
					$(".mobileNavImg").removeClass("mobileNavImgOn");
				}*/				

				$('.sitePickerBtn div').addClass("sitePickerImgUp");
				$('.sitePickerBtn').addClass("greenBtn");

			}
			
			else {

				$('.sitePickerBtn div').removeClass("sitePickerImgUp");
				$('.sitePickerBtn').removeClass("greenBtn");
			}
			
			window.scrollTo(0, 0);
			$('.sitePickerSectionInner').slideToggle('fast');			
		});
		
		
		

		// Initiering af sitePicker flexslider
		$('.sitePickerContentCol3').flexslider({
			animation: "fade",
			slideshow: true,
			slideshowSpeed: 7000,           
			animationDuration: 600,  
			controlNav:false, 
			directionNav: false

		});		

		// Initiering af flexsliders
		$('#menuSpotFlex01').flexslider({
			animation: "slide",
			slideshow: true,
			slideshowSpeed: 7000,           
			animationDuration: 600,  
			directionNav: false,
			controlsContainer: "#menuSpotFlexContainer01",
			//itemWidth: '100%',                   //{NEW} Integer: Box-model width of individual carousel items, including horizontal borders and padding.
			itemMargin: 20,                  //{NEW} Integer: Margin between carousel items.
			minItems: 1,                    //{NEW} Integer: Minimum number of carousel items that should be visible. Items will resize fluidly when below this.
			maxItems: 1  
		});		





		/**************************/
		/****** DRUPAL FIXES ******/
		/**************************/
		
		/* Fjerner .leaf-klasserne fra menuliste-elementerme og kloner menupunkterne over til mobiludgaven*/
		$(".altMenu li").each(function(){
			$(this).removeClass("leaf");
			/* Klon over til mobil-menuen */
			if($(this).children("a").html() != "Om os" ) {
				$(this).clone().appendTo(".menu-block-8 > ul").removeClass("active").addClass("cloned");	
			}
		}); 

		/* Fjernet linket fra bestemte first-level menuitems i mobilmenuen */
		$("[data-role='mobilenav'] ul:first-child > li").each(function(){
			if($(this).children("a").html() == "Borger" || $(this).find("a").html() == "Erhverv" || $(this).find("a").html() == "Politik" || $(this).find("a").html() == "Om os") {
				$(this).children("a").attr('href','#');	
			}
			/* Hvis det er "Om os"-menuen */
			if($(this).find("a").html() == "Om os") {
				$(this).removeClass("expanded");
				$(this).find("ul").remove();  
				$(this).children("a").attr('href','/indhold/om-kommunen');
			}
		}); 

		/* Fjerner links for Borger, Erhverv, Politik og Om os i brødkrummestien */
		if($("nav.breadcrumb a:nth-child(3)").text() == "Borger" || $("nav.breadcrumb a:nth-child(3)").text() == "Erhverv" || $("nav.breadcrumb a:nth-child(3)").text() == "Politik" || $("nav.breadcrumb a:nth-child(3)").text() == "Om os")
			$("nav.breadcrumb a:nth-child(3)").contents().unwrap();

		/* Bruger sidens titel som title-attribut i brødkrummestien, hvis den ikke er udfyldt af redaktøren */
		$("nav.breadcrumb a").each(function() {
            if(!$(this).attr('title')){
				$(this).attr('title', $(this).text());
			}
        });
		
		/* Hvis der ikke er indtastet en Alt-tekst til topfotoet, indsættes nodens titel */
		if(!$(".articleHeader > img").attr('alt')){ 
			$(".articleHeader img").attr('alt', $(".articleHeaderInner h1").text());
		}

		/* Fjerner styles-attributten på billeder, der er indsat i brødteksten. Herved kan billeder bliver skaleret responsivt via css */
		$(".articleHeaderInner img, .box_plus img").each(function(){
			if($(this).attr("style")) {
				$(this).removeAttr("style");	
			}
		});
		
		/* Føjer en box-klasse til søgeformularfelterne */
		$("#edit-search-block-form--2, #edit-apachesolr-panels-search-form, #edit-apachesolr-panels-search-form--3, #edit-submit, #edit-submit--2").addClass("box");
		$("#edit-apachesolr-panels-search-form--2").addClass("round3");
		/* Føjer placeholder-attribut til søgefeltet */
		$("#edit-search-block-form--2, #edit-apachesolr-panels-search-form, #edit-apachesolr-panels-search-form--2, #edit-apachesolr-panels-search-form--3").attr("placeholder", "Hvad søger du?");
		
		/* Fjerner contextual-links-wrapper */
		$(".contextual-links-wrapper").each(function(){
			$(this).remove();	
		});

		
		/**************************************/
		/****** Selvbetjenings accordion ******/
		/**************************************/

		$(".foldudContent").addClass("hideMe");
		$(".foldud_alfabetisk").addClass("hideMe");
		$(".foldud_sog").addClass("hideMe");		
		
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
/*		if(selvbetjeningUrl.indexOf(sogePatternStr) > -1) {
			$(".foldud_sog").removeClass("hideMe");
			$(".foldud, .foldud_alfabetisk").addClass("hideMe");
			$(".foldudTab").removeClass("foldudTabActive");	
			$("#tabSoeg").addClass("foldudTabActive");
		}*/
		if($(".foldud_sog").children('ul.foldudContentSub').length > 0) {
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


		/* TEASER SELECT-BOX-JUMPER**/
		$(function() {
			// bind change event to select
			$(".teaserDropdownInner select").bind("change", function() {
				if($(this).val() != "0") {
					if($(this).parent().parent().is(".emne")) {
						selIndex = $("#teaserDrop_emne").attr("selectedIndex");
						$("#teaserDrop_emne option:first-child").attr("selected", true);
						window.location = "/selvbetjening?e=" + selIndex;
					}
					else {
						selIndex = $(this).val();
						$("#teaserDrop_hvisdu option:first-child").attr("selected", true);
						window.location = "/selvbetjening?a=" + selIndex;
					}
				}
				return false;
			});
		});
		
		/* SITEPICKER SELECT-BOX-JUMPER**/
		$(function() {
			// bind change event to select
			$(".dropdownContainer select").bind("change", function() {
				if($(this).val() != "0") {
					if($(this).is("#sitepicker_emne")) {
						selIndex = $(this).attr("selectedIndex");
						$("#sitepicker_emne option:first-child").attr("selected", true);
						window.location = "/selvbetjening?e=" + selIndex;
					}
					else {
						selIndex = $(this).val();
						if(selIndex.substr(0,7) != 'http://'){
							selIndex = 'http://' + selIndex;
						}								
						$("#sitepicker_hjemmeside option:first-child").attr("selected", true);
						window.location = selIndex;
					}
				}
				return false;
			});
		});


		/*************************************/
		/**** MIKROARTIKLER FRA BORGER.DK ****/
		/*************************************/
		$(".microArticle div.mArticle").hide();
		$(".microArticle").wrapAll("<div class=\"microArticleContainer\" />");	
			
		$(".microArticle h2.mArticle").click(function(){
			$(this).parent().find("div.mArticle").slideToggle('fast');
			if($(this).parent().hasClass("active")){
				$(this).parent().removeClass("active");
				$(this).removeClass("active");
			}
			else {
				$(this).parent().addClass("active");
				$(this).addClass("active");
			}
		});


		/*************************/
		/**** SITEMAP KNAPPER ****/
		/*************************/
		$(".sitemapBtn").click(function(){
			if(!$(this).hasClass("active")){
				
				$(".sitemapBtn").removeClass("active");
				$(this).addClass("active");				
				
				if($(this).is("#sitemapBorger")){
					$(".menu-block-11 ul").removeClass("hideMe");
					$(".menu-block-12 ul, .menu-block-13 ul, .menu-block-14 ul").addClass("hideMe");
				}				
				if($(this).is("#sitemapErhverv")){
					$(".menu-block-12 ul").removeClass("hideMe");
					$(".menu-block-11 ul, .menu-block-13 ul, .menu-block-14 ul").addClass("hideMe");
				}
				if($(this).is("#sitemapPolitik")){
					$(".menu-block-13 ul").removeClass("hideMe");
					$(".menu-block-11 ul, .menu-block-12 ul, .menu-block-14 ul").addClass("hideMe");
				}
				if($(this).is("#sitemapOmos")){
					$(".menu-block-14 ul").removeClass("hideMe");
					$(".menu-block-11 ul, .menu-block-12 ul, .menu-block-13 ul").addClass("hideMe");
				}
			}	
		});
		

		/************************/
		/**** FLYT ELEMENTER ****/
		/************************/
		$(".delSocialeMedier").appendTo(".articleHeaderInner:last-child");
		$(".submitted").appendTo(".articleHeaderInner:last-child");

    
		/*************************/
		/**** PARTI FANER ****/
		/*************************/
		$(".partiFane").click(function(){
			if($(this).find(".partiFaneSub").hasClass("hideMe")){
        $(this).find(".partiFaneHeader").addClass("open"); 
        $(this).find(".partiFaneSub").removeClass("hideMe");
      }
      else {
        $(this).find(".partiFaneHeader").removeClass("open");
        $(this).find(".partiFaneSub").addClass("hideMe");
      }
		});
    // Hvis siden er en politikerside
    if($(".bg_parti_politiker")) {
      if($(".bg_parti_politiker").hasClass("A")) {
        $(".partiFaneA .partiFaneHeader").addClass("open");
        $(".partiFaneA .partiFaneSub").removeClass("hideMe");
      }
      if($(".bg_parti_politiker").hasClass("B")) {
        $(".partiFaneB .partiFaneHeader").addClass("open");
        $(".partiFaneB .partiFaneSub").removeClass("hideMe");
      }
      if($(".bg_parti_politiker").hasClass("C")) {
        $(".partiFaneC .partiFaneHeader").addClass("open");
        $(".partiFaneC .partiFaneSub").removeClass("hideMe");
      }
      if($(".bg_parti_politiker").hasClass("F")) {
        $(".partiFaneF .partiFaneHeader").addClass("open");
        $(".partiFaneF .partiFaneSub").removeClass("hideMe");
      }
      if($(".bg_parti_politiker").hasClass("I")) {
        $(".partiFaneI .partiFaneHeader").addClass("open");
        $(".partiFaneI .partiFaneSub").removeClass("hideMe");
      }
      if($(".bg_parti_politiker").hasClass("O")) {
        $(".partiFaneO .partiFaneHeader").addClass("open");
        $(".partiFaneO .partiFaneSub").removeClass("hideMe");
      }
      if($(".bg_parti_politiker").hasClass("V")) {
        $(".partiFaneV .partiFaneHeader").addClass("open");
        $(".partiFaneV .partiFaneSub").removeClass("hideMe");
      }
      if($(".bg_parti_politiker").hasClass("OE")) {
        $(".partiFaneOE .partiFaneHeader").addClass("open");
        $(".partiFaneOE .partiFaneSub").removeClass("hideMe");
      }      
    }

		/*******************************************/
		/**** FORSIDE-RESULTAT (OG PÅ VALGSIDEN ****/
		/*******************************************/
    if($(".kv2013-resultat-data") && $(".kv2013-resultat-data-parti")) {
      $(".kv2013-resultat-data-parti").each(function(){
        $procent = $(this).data("procent");
        $procentStrippet = $procent.toString();
        // erstat , med .
        $procentStrippet = $procentStrippet.replace(/,/g, ".");
        // erstat % med ""
        $procentStrippet = $procentStrippet.replace(/%/g, "");
        // erstat " " med ""
        $procentStrippet = $procentStrippet.replace(/ /g, "");
        $procentOutput = $procentStrippet;
        // med parantes
        if($procentStrippet.indexOf("(") !== -1) {
          $procentSplittet = $procentStrippet.split("(");
          $procentOutput = $procentSplittet[0];
          console.log("der er noteret en (\n$procentSplittet[0]=" + $procentSplittet[0] + ", $procentSplittet[1]=" + $procentSplittet[1] + "\n");
        } 
        else { 
        // ingen parantes
          $procentSplittet = "-1";
        }
        // Sørger for, at der kun er en decimal, fx 10.53 => 10.5 
        if(($procentSplittet[0].indexOf('.') !== -1) && ($procentSplittet !== -1)) {
          $procentDecimal  = $procentSplittet[0].split(".");
          $procentOutput = $procentDecimal[0] + "." + $procentDecimal[1].charAt(0); 
        }        
        if(($procent == "0") || ($procent == "undefined") || ($procent == "") || ($procent == -1) || ($procent == undefined) || ($procent == null)) {
          $(".kv2013-resultat-data-parti-bar", this).height(0);
          $(".kv2013-resultat-data-parti-bar p", this).html(0 + "&nbsp;%");
        }
        else {
          $(".kv2013-resultat-data-parti-bar", this).height(($procentOutput * 4));
          $(".kv2013-resultat-data-parti-bar p", this).html($procentOutput + "&nbsp;%");
        }
      });
      
    }


    
    

	});
	
})(jQuery);















