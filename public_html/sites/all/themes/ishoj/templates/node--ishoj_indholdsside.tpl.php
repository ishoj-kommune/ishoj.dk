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
<div id="node-<?php print $node->nid; ?>" class="articleHeaderInner"<?php print $attributes; ?>>

  <?php //print $user_picture; ?>

  <?php print render($title_prefix); ?>
  <?php if (!$page): ?>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  	<?php 
    if (!$status) {
    	print '<h2 style="color:red;">INDHOLDET ER "IKKE PUBLICERET" - KAN KUN SES AF ADMINISTRATOR</h2>';
    }
	?>
  
    <h1><?php print drupal_get_title(); ?></h1>
    

    

    
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
		print render($content);

		// MIKROARTIKLER		
		if($node->field_mikroartikler_titel or 
		$node->field_mikroartikler_titel2 or 
		$node->field_mikroartikler_titel3 or 
		$node->field_mikroartikler_titel4 or 
		$node->field_mikroartikler_titel5 or 
		$node->field_mikroartikler_titel6 or 
		$node->field_mikroartikler_titel7 or 
		$node->field_mikroartikler_titel8 or 
		$node->field_mikroartikler_titel9 or 
		$node->field_mikroartikler_titel10) {
			
			$mikroartikel = '';
			
//			$mikroartikel = $mikroartikel . '<div class="microArticleContainer">';
			
			if($node->field_mikroartikler_titel) {
				$mikroartikel = $mikroartikel . '<div class="microArticle"><h2 class="mArticle" id="mArticle1">' . $node->field_mikroartikler_titel['und'][0]['safe_value'] . '</h2>';
				$mikroartikel = $mikroartikel . '<div class="mArticle1 mArticle">' . $node->field_mikroartikler_tekst['und'][0]['safe_value'] . '</div></div>';
			}
			
			if($node->field_mikroartikler_titel2) {
				$mikroartikel = $mikroartikel . '<div class="microArticle"><h2 class="mArticle" id="mArticle2">' . $node->field_mikroartikler_titel2['und'][0]['safe_value'] . '</h2>';
				$mikroartikel = $mikroartikel . '<div class="mArticle2 mArticle">' . $node->field_mikroartikler_tekst2['und'][0]['safe_value'] . '</div></div>';
			}
			
			if($node->field_mikroartikler_titel3) {
				$mikroartikel = $mikroartikel . '<div class="microArticle"><h2 class="mArticle" id="mArticle3">' . $node->field_mikroartikler_titel3['und'][0]['safe_value'] . '</h2>';
				$mikroartikel = $mikroartikel . '<div class="mArticle3 mArticle">' . $node->field_mikroartikler_tekst3['und'][0]['safe_value'] . '</div></div>';
			}
			
			if($node->field_mikroartikler_titel4) {
				$mikroartikel = $mikroartikel . '<div class="microArticle"><h2 class="mArticle" id="mArticle4">' . $node->field_mikroartikler_titel4['und'][0]['safe_value'] . '</h2>';
				$mikroartikel = $mikroartikel . '<div class="mArticle4 mArticle">' . $node->field_mikroartikler_tekst4['und'][0]['safe_value'] . '</div></div>';
			}
			
			if($node->field_mikroartikler_titel5) {
				$mikroartikel = $mikroartikel . '<div class="microArticle"><h2 class="mArticle" id="mArticle5">' . $node->field_mikroartikler_titel5['und'][0]['safe_value'] . '</h2>';
				$mikroartikel = $mikroartikel . '<div class="mArticle5 mArticle">' . $node->field_mikroartikler_tekst5['und'][0]['safe_value'] . '</div></div>';
			}
			
			if($node->field_mikroartikler_titel6) {
				$mikroartikel = $mikroartikel . '<div class="microArticle"><h2 class="mArticle" id="mArticle6">' . $node->field_mikroartikler_titel6['und'][0]['safe_value'] . '</h2>';
				$mikroartikel = $mikroartikel . '<div class="mArticle6 mArticle">' . $node->field_mikroartikler_tekst6['und'][0]['safe_value'] . '</div></div>';
			}
			
			if($node->field_mikroartikler_titel7) {
				$mikroartikel = $mikroartikel . '<div class="microArticle"><h2 class="mArticle" id="mArticle7">' . $node->field_mikroartikler_titel7['und'][0]['safe_value'] . '</h2>';
				$mikroartikel = $mikroartikel . '<div class="mArticle7 mArticle">' . $node->field_mikroartikler_tekst7['und'][0]['safe_value'] . '</div></div>';
			}
			
			if($node->field_mikroartikler_titel8) {
				$mikroartikel = $mikroartikel . '<div class="microArticle"><h2 class="mArticle" id="mArticle8">' . $node->field_mikroartikler_titel8['und'][0]['safe_value'] . '</h2>';
				$mikroartikel = $mikroartikel . '<div class="mArticle8 mArticle">' . $node->field_mikroartikler_tekst8['und'][0]['safe_value'] . '</div></div>';
			}
			
			if($node->field_mikroartikler_titel9) {
				$mikroartikel = $mikroartikel . '<div class="microArticle"><h2 class="mArticle" id="mArticle9">' . $node->field_mikroartikler_titel9['und'][0]['safe_value'] . '</h2>';
				$mikroartikel = $mikroartikel . '<div class="mArticle9 mArticle">' . $node->field_mikroartikler_tekst9['und'][0]['safe_value'] . '</div></div>';
			}
			
			if($node->field_mikroartikler_titel10) {
				$mikroartikel = $mikroartikel . '<div class="microArticle"><h2 class="mArticle" id="mArticle10">' . $node->field_mikroartikler_titel10['und'][0]['safe_value'] . '</h2>';
				$mikroartikel = $mikroartikel . '<div class="mArticle10 mArticle">' . $node->field_mikroartikler_tekst10['und'][0]['safe_value'] . '</div></div>';
			}
			

//			$mikroartikel = $mikroartikel . '</div>';
			print $mikroartikel;	
			
		}
    ?>


  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>



    
  
  <?php 
  // nid = 107 (siden "Ledige stillinger")
  //if ($display_submitted and ($node->nid <> 107)) { ?>
  
    <!--<div class="__________submitted">-->
      <?php // print $submitted; ?>
    <!--</div>-->

  <?php //} ?>


  <?php 
  if($logged_in) {
    print '<div><a class="editNode round3" href="/node/' . $node->nid . '/edit?destination=admin/content" title="Rediger">< &nbsp;Rediger&nbsp; ></a></div>';
  
  	if($node->field_status_sideindhold['und'][0]['tid'] == 3391) {
	  print '<h2>Ikke rettet</h2>';	
	}
	
  	if($node->field_status_sideindhold['und'][0]['tid'] == 3392) {
	  print '<h2>Rettet</h2>';	
	}

  	if($node->field_status_sideindhold['und'][0]['tid'] == 3398) {
	  print '<h2>Delvist rettet</h2>';	
	}
	
	
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


</div>
