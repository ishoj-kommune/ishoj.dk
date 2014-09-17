/*
Plugin:  MIKLS.swap v.1.1
Author:  Thomas Mikkel Jensen
Website: Mikls.net
*/
(function($) {
	
	jQuery.fn.mikls_swap = function(options) {
		
		var settings = jQuery.extend({
			navigation:   false,
			display_time: 8000,	// Milisekeunder, 1000 = 1 sek.
			duration: 	  1000,
			nav_duration: 300,
			auto_run: 	  true
			
		},options), clicked = false;
		
		
		return this.each(function() {
			// Variabler
			var $this = $(this), 
					swap_timer = false, 
					count = $(this).children('.teaserSwap').size(), // Antallet af elementer
					//count = 4;
					current_slide  = 1,
					previous_slide = count,
					next_slide     = 2;
				
			function setup() {
				
				//$("#logo").text(current_slide);
				
				$this.children('.teaserSwap').hide();
				//$this.children('.teaserSwap:first').show();
				//$("#teaser div.teaserSwap:nth-child(" + (1) + ")").show();
				$("#teaser1").show();
				
/*				if(settings.navigation && count > 1) {
					buildNavigation();
					clearCircles();
					$(".circle:nth-child(" + current_slide + ") .middle-circle").addClass('hover');
				}*/
				
				
				if(settings.auto_run && count > 1) {
					initInterval();
					
					$("#teaser").hover(function() {
						//swap_timer.toggle();
						swap_timer.pause();	
					}, function() {
						swap_timer.reset();
					});
					// Stop og slet auto-swapperen ved mouseover og initier påny ved mouseout
/*					$this.parent().hover(function() {
						clearInterval(swap_timer);
					},function() {
						initInterval();
					});
*/				}

				$('#teaserNav li a').click(function() {
					if(!clicked) {
						clicked = true;
						
						//var i = $(this).find('.middle-circle span').text();
						
						//$('#teaserNav li a').index(this)
						
						//$('#teaserNav li a').index(this)
						
						swapElement(parseInt($('#teaserNav li a').index(this) + 1));
						
						//swapElement(parseInt());
					}
				});

			}
					
			setup();		
			
/*			function clearCircles() {
				for(i = 0; i < count; i++) {
					$(".circle:nth-child(" + (i + 1) + ") .middle-circle").removeClass('hover');
				}	
			}
			
*/			
			function clearHover() {
				for(i = 0; i < count; i++) {
					$("#teaserNav li:nth-child(" + (i + 1) + ") a").removeClass('teaserNavActive');
				}	
			}


			function swapElement(element) {
			
				if (count > 1) { // Hvis der er child-elementer
					
					//$("#teaser .teaserSwap:nth-child(" + current_slide + ")").fadeOut(settings.duration);
					//$("#teaser .teaserSwap:nth-child(" + current_slide + ")").fadeOut(settings.duration);
					$("#teaser" + current_slide + "").fadeOut(settings.duration);
					//$(".teaserSwap:nth-child(" + current_slide + ")").fadeOut(settings.duration);
				
								
					if(element == null) {	// Hvis der ikke er parametre med i funktionskaldet (når den selv swapper)
						
						//$("#logo").text(current_slide);
						
						$("#teaserNav li:nth-child(" + current_slide + ") a").removeClass('teaserNavActive');
						//clearCircles();
						clearHover();
						
						$("#teaserNav li:nth-child(" + next_slide + ") a").addClass('teaserNavActive');
						
						//$(".teaserSwap:nth-child(" + next_slide + ")").fadeIn(settings.duration,function() {
						$("#teaser" + next_slide + "").fadeIn(settings.duration,function() {
							clicked = false;
							
							current_slide++;
							if(current_slide > count) {
								current_slide = 1;
							}	
							
							next_slide = current_slide + 1;
							if(next_slide > count) {
								next_slide = 1;
							}						
							
							previous_slide = current_slide - 1;
							if(previous_slide < 1) {
								previous_slide = count;
							}									
		
						});

					}
					else {	// Når der er parametre med i funktionskaldet (når der er klikket på en navigationsknap)
							
						$("#teaserNav li:nth-child(" + current_slide + ") a").removeClass('teaserNavActive');
						//clearCircles();
						clearHover();
						$("#teaserNav li:nth-child(" + element + ") a").addClass('teaserNavActive');
						
						//$("#teaser .teaserSwap:nth-child(" + element + ")").fadeIn(settings.duration,function() {
						$("#teaser" + element + "").fadeIn(settings.duration,function() {
							clicked = false;
							
							current_slide = element;
							if(current_slide > count) {
								current_slide = 1;
							}	
							
							next_slide = current_slide + 1;
							if(next_slide > count) {
								next_slide = 1;
							}						
							
							previous_slide = current_slide - 1;
							if(previous_slide < 1) {
								previous_slide = count;
							}									
																			
						 });

					}
				}
				
			}

			// Opretter navigationsknapper
/*			function buildNavigation() {

				// Opretter Næste/forrige knapper
				var $div	  = $('<div></div>'), 
					$next_button     = $div.clone().addClass('swap_nav swap_next').appendTo($this.parent()).hide(), 	 // Næste
					$previous_button = $div.clone().addClass('swap_nav swap_previous').appendTo($this.parent()).hide(); // Forrige
				
				$next_button.click(function() {
					if(!clicked) {
						clicked = true;
						swapElement(next_slide);
					}
				});
				
				$previous_button.click(function() {
					if(!clicked) {
						clicked = true;
						swapElement(previous_slide);
					}
				});
				
				$this.parent().hover(function() {
					$next_button.fadeIn(settings.nav_duration);
					$previous_button.fadeIn(settings.nav_duration);
				},function() {
					$next_button.fadeOut(settings.nav_duration);
					$previous_button.fadeOut(settings.nav_duration);
				});
				
				// Opretter cirkelknapper
				for(i = 0; i < count; i++) {
					$('<div class="circle"><div class="middle-circle"><span>' + (i + 1) + '</span></div></div>').appendTo('#swap_circles');
				}
			
				$('#swap_circles').css('left', parseInt((((573 - (count * $('.circle').width())) / 2)) + 8) +'px');
				
				$('.circle').click(function() {
					if(!clicked) {
						clicked = true;
						var i = $(this).find('.middle-circle span').text();
						swapElement(parseInt(i));
					}
				});

			}*/
			
			// Initierer timeren
			function initInterval() {
				
				swap_timer = $.timer(function() {
					swapElement();
				});
				
				swap_timer.set({ time : settings.display_time, autostart : true });			
			}

		});	
	};
})(jQuery);