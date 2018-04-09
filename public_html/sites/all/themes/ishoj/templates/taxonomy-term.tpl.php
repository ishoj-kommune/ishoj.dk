<?php
/**
 * @file
 * Default theme implementation to display a term.
 *
 * Available variables:
 * - $name: (deprecated) The unsanitized name of the term. Use $term_name
 *   instead.
 * - $content: An array of items for the content of the term (fields and
 *   description). Use render($content) to print them all, or print a subset
 *   such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $term_url: Direct URL of the current term.
 * - $term_name: Name of the current term.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the following:
 *   - taxonomy-term: The current template type, i.e., "theming hook".
 *   - vocabulary-[vocabulary-name]: The vocabulary to which the term belongs to.
 *     For example, if the term is a "Tag" it would result in "vocabulary-tag".
 *
 * Other variables:
 * - $term: Full term object. Contains data that may not be safe.
 * - $view_mode: View mode, e.g. 'full', 'teaser'...
 * - $page: Flag for the full page state.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the term. Increments each time it's output.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * @see template_preprocess()
 * @see template_preprocess_taxonomy_term()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>

<?php 

function sortByTitle($a, $b){
  return strcmp($a->title, $b->title);
}

function sortByDateCreated($a, $b) {
  $result = NULL;
  if ((int) $a->created > (int) $b->created) {
    $result = -1;
  } elseif ((int) $a->created < (int) $b->created) {
    $result = 1;
  } else {
    $result = 0;
  }
  return $result;
}

$output = "";

  // ----------------------------  //
  //  K A T E G O R I   S I D E R  //
  // ----------------------------  //
  if($term->vocabulary_machine_name == "kategori") {
  
    $output = $output . "<!--  KATEGORI OVERSKRIFT START -->";
    
    if($term->description) {
      $output = $output . "<section class=\"kategori-overskrift har-beskrivelse\">";
    }
    else {
      $output = $output . "<section class=\"kategori-overskrift\">";
    }
    
    if($term->field_kategoribillede) {
      $output = $output . render($content['field_kategoribillede']);
    }
    // Temp; skal slettes, når alle kategorisider har fået billeder
    else {
      $output = $output . "<img src=\"/sites/all/themes/ishoj/img/diverse/kategori_aeldre3.jpg\">";
    }
      $output = $output . "<div class=\"kategori-container\">";
        $output = $output . "<div class=\"container\">";
          $output = $output . "<div class=\"row\">";
            $output = $output . "<div class=\"grid-full\">";
              $output = $output . "<h1>" . $term_name. "</h1>";
    
              if($term->description) {
                $output .= $term->description;
              }
    
            $output = $output . "</div>";
          $output = $output . "</div>";
        $output = $output . "</div>";
      $output = $output . "</div>";
    $output = $output . "</section>";
    $output = $output . "<!-- KATEGORI OVERSKRIFT SLUT -->";

    if($term_name != "Aktiviteter") { // kategorierne vises ikke på aktivitetssiden
      $output = $output . "<!-- CONTENT CATEGORY START -->";
      $output = $output . "<section class=\"content-category\">";
        $output = $output . "<div class=\"container\">";
          $output = $output . "<div class=\"row\">";

            $output = $output . "<ul class=\"list-unstyled\">";
            $a = taxonomy_select_nodes($term->field_os2web_base_field_kle_ref['und'], $pager = FALSE); 
        $nodes = array();
        foreach($a as $nid) {
            $checkifitis = 0;
            // check if node are allready there
           foreach($nodes as $n) {
                if ($n->nid == $nid) {
                  $checkifitis = 1;
                }
            }
             if ($checkifitis == 0) {
            $nodes[] = node_load($nid);
              }
            }

  usort($nodes, 'sortByDateCreated');
   foreach($nodes as $nid1) {
     
       if ($nid1->field_indholdstype['und'][0]['tid'] != '2928') {
           
       $output = $output . "<li class=\"grid-fourth\"><a href=\"" . url('node/' . $nid1->nid) . "\" title=\"" . $nid1->title . "\"><h3><span>" . $nid1->title . "</span></h3></a><li>";   
       }
     }


          $output = $output . "</div>";
        $output = $output . "</div>";
      $output = $output . "</section>";
      $output = $output . "<!-- CONTENT CATEGORY SLUT -->";
    }
    
  }


  // ----------------------------------- //
  //  S I D E N   A K T I V I T E T E R  //
  // ----------------------------------- //
  if($term->vocabulary_machine_name == "kategori") {
    if($term_name == "Aktiviteter") {
      $output .= "<section class=\"aktivitetsside\">";
        $output .= "<div class=\"container\">";
          $output .= "<div class=\"row\">";

            $output .= "<div class=\"activities node-visning\">";
              $output .= "<div class=\"swiper-container-activities-aktivitetsside\">";
                $output .= "<div class=\"swiper-wrapper\">";
                  $output .= views_embed_view('aktiviteter','aktivitet_kommende_aktiviteter');
                $output .= "</div>";
              $output .= "</div>";
            $output .= "</div>";

          $output .= "</div>";
        $output .= "</div>";
      $output .= "</section>";
    }
  }





  // ----------------------------- //
  //  A K T I V I T E T S S T E D  //
  // ----------------------------- //
  elseif($term->vocabulary_machine_name == "aktivitetssted") {
     $output .= "<h1>Bingo!!!!</h1>";
  }



  // --------------- //
  //  D E F A U L T  //
  // --------------- //
  else {
    
    $output .= "<!-- ARTIKEL START -->";
      $output .= "<section id=\"taxonomy-term-" . $term->tid . "\" class=\"" . $classes . " artikel\">";
        $output .= "<div class=\"container\">";
           
         // Brødkrummesti
          $output .= "<div class=\"row\">";
            $output .= "<div class=\"grid-two-thirds\">";
              $output .= "<p class=\"breadcrumbs\">" . theme('breadcrumb', array('breadcrumb'=>drupal_get_breadcrumb())) . " / " . $term_name . "</p>";
            $output .= "</div>";
          $output .= "</div>";
           
          $output .= "<div class=\"row second\">";
            $output .= "<div class=\"grid-two-thirds\">";
              $output .= "<h1>" . $term_name . "</h1>";
            $output .= "</div>";
            $output .= "<div class=\"grid-third sociale-medier social-desktop\"></div>";
          $output .= "</div>";
  
          $output .= "<div class=\"row second\">";
            $output .= "<div class=\"grid-two-thirds\">";

              $output .= "<!-- ARTIKEL TOP START -->";
              $output .= "<div class=\"artikel-top\">";
              $output .= "</div>";
              $output .= "<!-- ARTIKEL TOP SLUT -->";

              // ------------------------------  //
              //  P O L I T I S K   U D V A L G  //
              // ------------------------------  //
              if($term->vocabulary_machine_name == "politisk_udvalg") {
                  
                // UNDEROVERSKRIFT
                if($term->field_os2web_base_field_summary) {
                  $output .= "<h2>" . $term->field_os2web_base_field_summary['und'][0]['value'] . "</h2>";
                }
                
                // BODY 
                if($term->description) {
                  $output .= $term->description;
                }
                
                
                // REDIGÉR-KNAP
                if($logged_in) {
                  $output .= "<div style=\"position: relative; width: 100%; margin-bottom: 5.5em;\">";
                  $output .= "<div class=\"edit-node\"><a href=\"/taxonomy/term/" . $term->tid . "/edit\" title=\"Ret indhold\"><span>Ret indhold</span></a></div>";
                  $output .= "</div>";
                }

                
                // Medlemmer af det valgte udvalg
                //print views_embed_view('politisk_udvalg', 'taxonomivisning');
                $output .= "<h2>Medlemmer af " . $term_name . "</h2>";
                $output .= "<div class=\"politiker-liste\">";
                $output .= views_embed_view('politiker','politiker_liste', $term->tid);
                $output .= "</div>";
              }

              

      if($term->vocabulary_machine_name == "kontakt") {
      
      // KONTAKT
      $output .= "<!-- KONTAKT START -->";
      $output .= "<h2>Kontakt</h2>";
      $output .= views_embed_view('kontakttermside','default');
      $output .= "<!-- KONTAKT SLUT -->";
      }
      else
      {
      $output .= render($content);
      }
      
              // DEL PÅ SOCIALE MEDIER
              include_once drupal_get_path('theme', 'ishoj') . '/includes/del-paa-sociale-medier.php';

              // SENEST OPDATERET
              $output .= "<!-- SENEST OPDATERET START -->";
//              $output .= "<p class=\"last-updated\">Senest opdateret " . format_date($node->changed, 'senest_redigeret') . "</p>";
              $output .= "<!-- SENEST OPDATERET SLUT -->";

            $output .= "</div>";
    
            $output .= "<div class=\"grid-third\">";
    
              // ------------------------------  //
              //  P O L I T I S K   U D V A L G  //
              // ------------------------------  //
              if($term->vocabulary_machine_name == "politisk_udvalg") {
                $output .= "<nav class=\"menu-underside\">";
                  $output .= "<p class=\"menu-header\">Politiske udvalg</p>";
                  $output .= "<ul class=\"menu\">";
                    $output .= "<li class=\"first expanded active-trail\">";
                      $output .= "<ul class=\"menu\">";
                        $output .= views_embed_view('udvalg','udvalgs_liste');
                      $output .= "</ul>";
                    $output .= "</li>";
                  $output .= "</ul>";
                $output .= "</nav>";
              }
              else {
                  
                  if ($term->vocabulary_machine_name == "kontakt") {
                  
                   // MENU TIL UNDERSIDER START
                    $output = $output . "<nav class=\"menu-underside\">";
                 
 // http://stackoverflow.com/questions/4731420/how-to-insert-a-block-into-a-node-or-template-in-drupal-7
//                    $block = module_invoke('module_name', 'block_view', 'block_delta');
               //     $block = module_invoke('menu_block', 'block_view', '4');
                //    $output.= render($block['content']);
                    $output = $output . "<ul class=\"menu\">";
                      $output = $output . "<li class=\"first expanded active-trail\">";
                        $output = $output . "<a href=\"#\">" . $node->title . "</a>";
                        $output = $output . "<ul class=\"menu\">";
                     
                        $a = taxonomy_select_nodes($term->field_os2web_base_field_kle_ref['und'], $pager = FALSE); 
                        $nodes = array();
                        foreach($a as $nid) {
                          $checkifitis = 0;
                          foreach($nodes as $n) {
                            if ($n->nid == $nid) {
                              $checkifitis = 1;
                            }
                          }
                          if ($checkifitis == 0) {
                            $nodes[] = node_load($nid);
                          }
                        }
                        usort($nodes, 'sortByTitle');
                        foreach($nodes as $nid1) {
                          if ($node->nid != $nid1->nid) {
                            $output = $output . "<li><a href=\"" . url('node/' . $nid1->nid) . "\" title=\"" . $nid1->title . "\">" . $nid1->title . "</a></li>"; 
                          }
                        }

                      //  $output = $output . "<li class=\"active active-trail\"><a href=\"#\">Lorem ipsum dolor</a></li>";
                      $output = $output . "</ul>";
                      $output = $output . "</li>";
                      // GET ALL NOTES FROM KLE REF BY TERM KLE
                      $a = taxonomy_select_nodes($bterm->field_os2web_base_field_kle_ref['und'], $pager = FALSE); 
                      $nodes = array();
                      foreach($a as $nid2) {
                        $checkifitis = 0;
                        // check if node are allready there
                        foreach($nodes as $n) {
                          if ($n->nid == $nid2) {
                            $checkifitis = 1;
                          }
                        }
                        if ($checkifitis == 0) {
                          $nodes[] = node_load($nid2);
                        }
                      }
                      usort($nodes, 'sortByTitle');
                      foreach($nodes as $nid1) {
                        if ($node->nid != $nid1->nid) {
                          $output = $output . "<li class=\"collapsed\"><a href=\"" . url('node/' . $nid1->nid) . "\" title=\"" . $nid1->title . "\">" . $nid1->title . "</a><li>";
                        }
                      }
                      $output = $output . "</ul>";                  
                      // til BLOCK MENU SITES
                      // $block = module_invoke('menu_block', 'block_view', '4');
                      // $output.= render($block['content']);

                    $output = $output . "</nav>";
                    // MENU TIL UNDERSIDER SLUT
                  
                  }     
                  else {
                   // MENU TIL UNDERSIDER START
                $output .= "<nav class=\"menu-underside\">";                    
                $block = module_invoke('menu_block', 'block_view', '4');
                $output .= render($block['content']);
                $output .= "</nav>";
                // MENU TIL UNDERSIDER SLUT
                  }
                  
               
              }

            $output .= "</div>";              

        $output .= "</div>";
      $output .= "</div>";
    $output .= "</section>";
    $output .= "<!-- ARTIKEL SLUT -->";
    
    
    // DIMMER DEL SIDEN
    $options = array('absolute' => TRUE);
    // NODEVISNING
    // $nid = $node->nid; 
    // $abs_url = url('node/' . $nid, $options);
    // -----------
    // TAXONOMIVISNING
    $abs_url = url(substr($term_url, 1), $options);
    include_once drupal_get_path('theme', 'ishoj') . '/includes/dimmer-del-siden.php';
  }


?>

<!--<div id="taxonomy-term-<?php print $term->tid; ?>" class="<?php print $classes; ?>">-->

  <?php// if (!$page): ?>
<!--    <h2><a href="<?php //print $term_url; ?>"><?php //print $term_name; ?></a></h2>-->
  <?php //endif; ?>

<!--  <div class="content">-->
    <?php// print render($content); ?>
<!--  </div>-->

<!--</div>-->


<?php 
  
  // BREAKING
  print views_embed_view('kriseinformation', 'pagevisning');

  // OUTPUT
  print $output;



?>


