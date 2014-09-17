<?php

/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct URL of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type; for example, "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type; for example, story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode; for example, "full", "teaser".
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined; for example, $node->body becomes $body. When needing to
 * access a field's raw values, developers/themers are strongly encouraged to
 * use these variables. Otherwise they will have to explicitly specify the
 * desired field language; for example, $node->body['en'], thus overriding any
 * language negotiation rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<!--<div id="node-<?php print $node->nid; ?>" class="articleHeaderInner"<?php print $attributes; ?>>-->

  <?php //print $user_picture; ?>

  <?php print render($title_prefix); ?>
  <?php if (!$page): ?>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  	<?php 
  //  if (!$status) {
  //  	print '<h2 style="color:red;">INDHOLDET ER "IKKE PUBLICERET" - KAN KUN SES AF ADMINISTRATOR</h2>';
  //  }
	?>
  
    
    

    

    
<!--    [field_underoverskrift] => Array
        (
            [und] => Array
                (
                    [0] => Array
                        (
                            [value] => Siden hvor du kan finde information for informationens skyld
                            [format] => 
                            [safe_value] -->
    <?php
      // We hide the comments and links now so that we can render them later.
	  
		hide($content['comments']);
		hide($content['links']);
		


    ?>


  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>



    
    <?php
      // KANDIDAT NR.
//      print "<div style=\"float:left; width:100%; margin:1.0em 0 0 0;\">KANDIDAT NR. " . $node->field_kandidat_nr_['und'][0]['value'] . "</div>";
      
      $nodeTitle = drupal_get_title();
              
      // FOTO
//      print "<img src=\"" . file_create_url($node->field_foto['und'][0]['uri']) . "\" alt=\"" . $nodeTitle . "\" />";
    
          
//      $style = "large";
//      print "<img src=\"" . image_style_url($style, $node->field_foto['und'][0]['uri']) . "\" alt=\"" . $nodeTitle . "\" />";
      
      //print "<img src=\"" . file_create_url($node->picture->uri) . "\" alt=\"" . $nodeTitle . "\" />";
      
      // NAVN      
      print "<h1>" . $nodeTitle . "</h1>";
      
      // CIVILT ERHVERV
      if($node->field_civilt_erhverv) {
        print "<h2>" . $node->field_civilt_erhverv['und'][0]['safe_value'] . "</h2>"; 
      }

      // UDDANNELSE
      if($node->field_uddannelse) {
        print "<p><strong>Uddannelse:</strong> " . $node->field_uddannelse['und'][0]['safe_value'] . "</p>"; 
      }
      
      // FØDT 
      if($node->field_foedt){
        print "<p><strong>Født:</strong> " . $node->field_foedt['und'][0]['safe_value'] . "</p>";
      }
      
      // ADRESSE
//      if($node->field_adresse){
//        print "<p><strong>Adresse:</strong><br />" . $node->field_adresse['und'][0]['safe_value'] . "<br />2635 Ishøj</p>";
//      }

      // TELEFON
      if($node->field_telefon){
        print "<p><strong>Telefon:</strong> " . $node->field_telefon['und'][0]['safe_value'] . "</p>";
      }

      // E-MAIL
      if($node->field_email_tekstfelt){
        print "<p><strong>E-mail:</strong> <a href=\"mailto:" . $node->field_email_tekstfelt['und'][0]['safe_value'] . "\" title=\"Send en e-mail til " . $nodeTitle . "\">" . $node->field_email_tekstfelt['und'][0]['safe_value'] . "</a></p>";
      }

      
      

      // VALGPROGRAM (PDF)
//      if($node->field_valgprogram) {
//        $valgprogram = "<p><a href=\"" . file_create_url($node->field_valgprogram['und'][0]['uri']) . "\" title=\"Læs mit valgprogram\">";
//        $valgprogram = $valgprogram . "<img class=\"politikerSocialemedier round2\" src=\"/sites/all/themes/ishoj/images/pdf.png\" alt=\"Læs mit valgprogram (pdf-dokument)\" />";
//        $valgprogram = $valgprogram . "</a><a href=\"" . file_create_url($node->field_valgprogram['und'][0]['uri']) . "\" title=\"Læs mit valgprogram\">Læs mit valgprogram (pdf)</a></p>"; 
//        //print "<a href=\"" . file_create_url($node->field_valgprogram['und'][0]['uri']) . "\" title=\"Læs mit valgprogram\">Læs mit valgprogram (pdf-dokument)</a></p>"; 
//        print $valgprogram;
//      } 
      
      // FACEBOOK / TWITTER 
      if($node->field_facebook_tekstfelt or $node->field_twitter_tekstfelt){
        $socialeMedier = "<p>";

        if($node->field_facebook_tekstfelt){
          $socialeMedier = $socialeMedier . "<a href=\"" . $node->field_facebook_tekstfelt['und'][0]['safe_value'] . "\" title=\"Se min facebook-side\">";
          $socialeMedier = $socialeMedier . "<img class=\"politikerSocialemedier round2\" src=\"/sites/all/themes/ishoj/images/iconFacebook.png\" alt=\"Se min Facebook-side\" />";
          $socialeMedier = $socialeMedier . "</a><a href=\"" . $node->field_facebook_tekstfelt['und'][0]['safe_value'] . "\" title=\"Se min facebook-side\">";
          //$socialeMedier = $socialeMedier . $node->field_facebook_tekstfelt['und'][0]['safe_value'] . "</a>";
          $socialeMedier = $socialeMedier . "Se min Facebook-side</a>";
        }
                        
        if($node->field_facebook_tekstfelt and $node->field_twitter_tekstfelt){
          $socialeMedier = $socialeMedier . "</p><p>";
        }
        if($node->field_twitter_tekstfelt){
          $socialeMedier = $socialeMedier . "<a href=\"" . $node->field_twitter_tekstfelt['und'][0]['safe_value'] . "\" title=\"Se min Twitter-profil\">"; 
          $socialeMedier = $socialeMedier . "<img class=\"politikerSocialemedier round2\" src=\"/sites/all/themes/ishoj/images/iconTwitter.png\" alt=\"Se min Twitter-profil\" />";
          $socialeMedier = $socialeMedier . "</a><a href=\"" . $node->field_twitter_tekstfelt['und'][0]['safe_value'] . "\" title=\"Se min Twitter-profil\">"; 
          //$socialeMedier = $socialeMedier . $node->field_twitter_tekstfelt['und'][0]['safe_value'] . "</a>";
          $socialeMedier = $socialeMedier . "Se min Twitter-profil</a>";
        }

        $socialeMedier = $socialeMedier . "</p>";
        print $socialeMedier;
      }

                
      
      // FRITIDSINTERESSER
      if($node->body) {
        print "<p>&nbsp;</p><div><strong>Fritidsinteresser: </strong>";
        print $node->body['und'][0]['safe_value'] . "</div>";
      }

      // POLITISKE MÆRKESAGER
      if($node->field_politiske_maerkesager) {
        print "<div><strong>Politiske mærkesager: </strong>";
        print "<p>" . $node->field_politiske_maerkesager['und'][0]['safe_value'] . "</p></div>";
      }
      

      // I BYRÅDET SIDEN
      if($node->field_i_byraadet_siden){
        print "<p><strong>I byrådet siden:</strong> " . $node->field_i_byraadet_siden['und'][0]['safe_value'] . "</p>";    
      }
    
      
    ?>
    <p>&nbsp;</p>
    <p>&nbsp;</p>


  <!--  Embedding the view before the comments are displayed-->
	<div class="embedded-view">
    <?php print views_embed_view('politikers_udvalg','panel_pane_1', $node->nid); ?>
  </div>
    
    
  <?php
    print render($content);    
  ?>
    
  


  <?php 
  if($logged_in) {
    print '<div><a class="editNode round3" href="/node/' . $node->nid . '/edit?destination=admin/content" title="Rediger">< &nbsp;Rediger&nbsp; ></a></div>';
  
//  	if($node->field_status_sideindhold['und'][0]['tid'] == 3391) {
//	  print '<h2>Ikke rettet</h2>';	
//	}
//	
//  	if($node->field_status_sideindhold['und'][0]['tid'] == 3392) {
//	  print '<h2>Rettet</h2>';	
//	}
//
//  	if($node->field_status_sideindhold['und'][0]['tid'] == 3398) {
//	  print '<h2>Delvist rettet</h2>';	
//	}
	
	
/*
    
  
  [field_status_sideindhold] => Array
        (
            [und] => Array
                (
                    [0] => Array
                        (
                            [tid] => 3391
                        )
                        
                        
                        
                        
   [field_status_sideindhold] => Array
        (
            [und] => Array
                (
                    [0] => Array
                        (
                            [tid] => 3392
                        )*/
  
  
  }
  ?>  
  


  <?php //dsm($node); //drupal_set_message('<pre>' . print_r($node, TRUE) . '</pre>'); ?>


<!--</div>-->
