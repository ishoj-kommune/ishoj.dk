<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 */
?>
<!-- DATA-ROLE="PAGE" START -->
<div data-role="page">

    <!-- HEADER START -->
	<header data-role="header">
    
    	<?php print render($page['header']); ?>
    
        
        <!-- TOP SECTION START -->
		<section id="top">
        	<div class="container">
				<div class="content">

					<!-- MOBIL NAVIGATION START -->
				    <div class="mobileNavBtn round3 hideMe">
                    	<div class="mobileNavImg"></div>
                    </div>
					<!-- MOBIL NAVIGATION END -->
                    
                	<!-- LOGO START -->
					<?php if ($logo): ?>
                    <a id="logo" href="<?php print $front_page; ?>" title="<?php print t('Til forsiden af Ishøj Kommunes hjemmeside'); ?>" rel="home">
                        <img src="<?php print $logo; ?>" alt="<?php print t('Til forsiden af Ishøj Kommunes hjemmeside'); ?>" />
						<?php if ($site_name): ?>
                        <span><?php print $site_name; ?></span>
                        <?php endif; ?>
                    </a>
					<?php endif; ?>                    
                    <!-- LOGO END -->

					<!-- HJEMMESIDE VÆLGER START -->
                    <div class="sitePickerBtn roundBottom" title="Andre websites fra Ishøj Kommune">
                    	<div class="sitePickerImg"><p>Genveje</p></div>
                    </div>
					<!-- HJEMMESIDE VÆLGER END -->
                    
					<!-- SØGEBOKS START -->
                    <div class="searchPickerBtn roundBottom roundTop" title="Søg på hjemmesiden">
                    	<div class="searchPickerImg"></div>
                    </div>
					<!-- SØGEBOKS END -->

					
	                <!-- ALTERNATIVE MENU START --> 
                    <?php print render($page['menu_alternativ']); ?>   
                	<!-- ALTERNATIVE NAVIGATION MENU END -->
                    
                </div>
            </div>
		</section>
        <!-- TOP SECTION END -->


		<!-- SITE PICKER SECTION START -->
		<section class="sitePickerSection">
            <div class="sitePickerSectionInner">
            	<div class="sitePickerSectionInnerInner">
                
                <div class="container">
                    <div class="content">
                    	<div class="sitePickerContent">
                                                	
                            <!-- KOLONNE 1 START -->
                            <div class="sitePickerContentCol1 sitePickerContentColBg">

								<?php print render($page['sitepicker']); ?>
                            
                            </div>
                            <!-- KOLONNE 1 END -->
                            <!-- KOLONNE 2 START -->
                            <div class="sitePickerContentCol2 sitePickerContentColBg">
                            	<span>Ofte benyttede genveje</span>
                                <?php print render($page['oftebenyttedegenveje']); ?>
                            </div>
                            <!-- KOLONNE 2 END -->
                            <!-- KOLONNE 3 START -->
                            <div class="sitePickerContentCol3 sitePickerContentColBg">
                            	<span>Websites i fokus</span>
                                <div class="flexslider">
									<?php print render($page['websitesifokus']); ?>
                                </div>
                            </div>
                            <!-- KOLONNE 3 END -->
                        </div>
					</div>
            	</div>
                
                </div>
			</div>
    </section>
    <!-- SITE PICKER SECTION END -->
    
    <!-- NAVIGATION START -->
		<nav id="navigation" class="bg01">
        	<div class="container">
				<div class="content">

                    <!-- SEARCH ORIGIN START -->
					<div class="searchOrigin">
                    	
                        <?php print render($page['search']); ?>
                                        
                    </div>
                    <!-- SEARCH ORIGIN END -->
                    

                                        
					<!-- MAIN MENU START --> 
					<ul id="mainMenu" class="mainMenu firstLevel">
						<li class="topNav roundTop active"><a href="/forside" title="">Forside</a></li>
						<li id="menuBorger" class="topNav roundTop"><a href="#" title="">Borger</a>
                        	<div class="menuSub roundBottom shadowBottomNavi">
                            	<div class="menuSubLeft">
                                	<?php print render($page['menu_borger']); ?>
                                </div>
                                
                                <!-- menuSubRight START -->
                                <div class="menuSubRight">
                        			<div class="menuSpots">
                                       <h1>Selvbetjening</h1>
                                        <ul>
                                            <li>
                                            	<?php print render($page['menu_borger_selvbtj']); ?>
                                            </li>
                                        </ul>
                                    </div>
                                    
                                </div>
                                <!-- menuSubRight END -->
                                
                            </div>
                        </li>
						<li id="menuErhverv" class="topNav roundTop"><a href="#" title="">Erhverv</a>
                        	<div class="menuSub roundBottom shadowBottomNavi">
                            	<div class="menuSubLeft">
									<?php print render($page['menu_erhverv']); ?>
                                </div>
                                
                                <!-- menuSubRight START -->
                                <div class="menuSubRight">
                        			<div class="menuSpots">
                                       <h1>Selvbetjening</h1>
                                        <ul>
                                            <li>
                                            	<?php print render($page['menu_erhverv_selvbtj']); ?>
                                            </li>
                                        </ul>
                                    </div>
                                    
                                </div>
                                <!-- menuSubRight END -->
                            </div>
                        </li>
						<li id="menuPolitik" class="topNav roundTop lastTopNav"><a href="#" title="">Politik</a>
                        	<div class="menuSub roundBottom shadowBottomNavi">
                            	<div class="menuSubLeft">
									<?php print render($page['menu_politik']); ?>
                                </div>
                                
                                <!-- menuSubRight START -->
                                <div class="menuSubRight">
                        			<div class="menuSpots">
                                       <h1>Selvbetjening</h1>
                                        <ul>
                                            <li>
                                            	<?php print render($page['menu_politik_selvbtj']); ?>
                                            </li>
                                        </ul>
                                    </div>
                                    
                                </div>
                                <!-- menuSubRight END -->
                            </div>
                        </li>
					</ul>
                    <!-- MAIN MENU END --> 
                    
                </div>
            </div>
		</nav>
		<!-- NAVIGATION END -->


        <!-- MOBIL MENU SEARCH TARGET START -->
        <div class="mobilSearchTarget bg01"></div>
        <!-- MOBIL MENU SEARCH TARGET END -->
        
	           		
	</header>
	<!-- HEADER END -->

	<!-- DATA-ROLE CONTENT START -->
	<div data-role="content">
        
<!--        <div style="float:left; display:block;">
            <div id="px1600">1600 pixels</div>
            <div id="px1500">1500 pixels</div>
            <div id="px1400">1400 pixels</div>
            <div id="px1280">1280 pixels</div>
            <div id="px1200">1200 pixels</div>
            <div id="px1100">1100 pixels</div>
            <div id="px1024">1024 pixels</div>
            <div id="px960">960 pixels</div>
            <div id="px800">800 pixels</div>
            <div id="px768">768 pixels</div>
            <div id="px640">640 pixels</div>
            <div id="px600">600 pixels</div>
            <div id="px540">540 pixels</div>
            <div id="px480">480 pixels</div>
            <div id="px320">320 pixels</div>
        </div>  -->      


		<?php if ($messages): ?>
        <div class="container">
            <div class="content">
            	<div class="drupalMessages">
				<?php print $messages; ?>
                <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
                <?php print render($page['help']); ?>
                <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
				</div>
            </div>
        </div>
        <?php endif; ?>
        
        

        
            
        <div class="container">
            <div class="content">
            
            
            <!-- Old Browser Warning -->
            <!--[if lt IE 9]>
            <section class="breaking box"><div class="breakingInner box">
            <p>Vidste du, at din browser er gammel? Det betyder, at noget af indholdet på hjemmesiden ikke bliver vist korrekt i din browser.</p><p> <a href="http://www.whatbrowser.org/intl/da/">Opdater din browser</a>, så får du en hurtigere, bedre og mere sikker oplevelse på hjemmesiden.</p></div></section>
            <![endif]-->
            
            

				<?php if($page['editor'] and $logged_in): ?>
                    <!-- REDAKTØRMENU START -->        
                    <section class="editor box">
                        <div class="editorInner">
                            <div class="profilfoto">
                            <?php $user_item = user_load($user->uid); //user_load_by_name($username); // or user_load( $user->uid )
                                  print theme('user_picture', array('account' =>$user_item)); ?>
                            </div>						
							<?php print render($page['editor']); ?>
                        </div>
                    </section>
                    <!-- REDAKTØRMENU END -->
            	<?php endif; ?>

      <?php //if ($is_admin and $logged_in): ?> 
				<?php if ($page['krisekommunikation']): ?>
                <!-- BREAKING NEWS START -->        
                <section class="breaking box">
                    <div class="breakingInner"><?php print render($page['krisekommunikation']); ?></div>
                </section>
                <!-- BREAKING NEWS END -->
      	<?php endif; ?>
      <? //endif ?>         
             
				<?php print render($page['content']); ?>    
            </div>
        </div>

	</div>
    <!-- DATA-ROLE CONTENT END -->


   	<!-- DATA-ROLE FOOTER START -->
   	<footer data-role="footer" class="bg01">
    	<div>
		<div class="container">
   	    	<div class="content">
            
            	
            
            	<?php print render($page['footer']); ?>

                <section class="footerLeft">
                    <div class="footerSocialemedier">
                        <h1>Følg os på</h1>
                        <div class="footerSocialeMedier footerFacebook"><a href="https://www.facebook.com/ishojkommune" title="Følg os på Facebook"><img src="/<?php print $path_to_theme ?>images/iconFacebook.png" alt="Følg os på Facebook" class="box" /></a></div>
                        <div class="footerSocialeMedier footerTwitter"><a href="https://twitter.com/ishojkommune" title="Følg os på Twitter"><img src="/<?php print $path_to_theme ?>images/iconTwitter.png" alt="Følg os på Twitter" class="box" /></a></div>
                        <div class="footerSocialeMedier footerYoutube"><a href="http://www.youtube.com/tvishoj" title="Følg os på Youtube"><img src="/<?php print $path_to_theme ?>images/iconYoutube.png" alt="Følg os på Youtube" class="box" /></a></div>
                    </div>

                	<div>
                    	<?php print render($page['footer_kontakt']); ?>
                    	<h1>Ishøj Kommune</h1>
                        <p>Ishøj Store Torv 20<br />
                        2635 Ishøj<br />
                        Tlf. 43 57 75 75</p>
                        <p><a href="mailto:ishojkommune@ishoj.dk" title="Kontakt os via e-mail">ishojkommune@ishoj.dk</a></p>
                        <p><a href="#" title="Find vej til Ishøj Kommune">Find vej til Ishøj Kommune</a></p>
                        
<!--                        <h1>Åbningstider</h1>
                        <p>Mandag-onsdag: 10.00-14.00<br />
                        Torsdag: 10.00-14.00 & 15.00-16.30<br />
                        Fredag: 10.00-13.00<br /></p>

                        <h1>Telefontider</h1>
                        <p>Mandag-onsdag: 09.00-15.30<br />
                        Torsdag: 09.00-17.00<br />
                        Fredag: 09.00-13.30<br /></p>-->
                    </div>
                </section>
                
                <section class="footerRight">
                	<div>
                        <div>
                        	<?php print render($page['footer_menu_borger']); ?>
                            <?php print render($page['footer_menu_erhverv']); ?>
                            <?php print render($page['footer_menu_politik']); ?>
                        </div>
                    
	                    <div class="footerLogo"></div>
                    </div>
                </section>
                                
            </div>
        </div>
        </div>
    </footer>
	<!-- DATA-ROLE FOOTER END -->

	<!-- DIMMER START -->
	<div class="dimmer hideMe"></div>
    <!-- DIMMER END -->

</div>
<!-- DATA-ROLE="PAGE" END -->


<!-- MOBIL MENU NAVIGATION START -->   
<nav data-role="mobilenav">

    <!-- MOBIL MENU START -->
    <?php print render($page['menu_mobil']); ?>
    <!-- MOBIL MENU END -->

</nav>
<!-- MOBIL MENU NAVIGATION END -->
