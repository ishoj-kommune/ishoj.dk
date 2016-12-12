<?php

/**
 * @file
 * Bartik's theme implementation to display a node.
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
 */

?>

<!-- ARTIKEL START -->
<section id=\"node-<?php $node->id ?>" class="artikel <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="container">

    <?php
    // Brødkrummesti
    $query = new EntityFieldQuery;
    $result2 = $query
      ->entityCondition('entity_type', 'taxonomy_term')
      ->propertyCondition('vid', 16)
      ->fieldCondition('field_os2web_base_field_kle_ref', 'tid', $node->field_os2web_base_field_kle_ref['und'][0]['tid'])
      ->execute();
    $bufcount = 0;
    $buftid = 0;
    foreach ($result2 as $v1) {
      foreach ($v1 as $v2) {
        if ($bufcount == 0) {
          $buftid = $v2->tid;
          ++$bufcount;
        }
      }
    }
    $bterm = taxonomy_term_load($buftid);
    ?>
    <div class="row">
      <div class="grid-two-thirds">
        <?php print "<p class=\"breadcrumbs\">" . theme('breadcrumb', array('breadcrumb' => drupal_get_breadcrumb())) . " / " . "<a href=\"" . url('taxonomy/term/' . $bterm->tid) . "\" title=\"Kategorien " . $bterm->name . "\">" . $bterm->name . "</a>" . " / " . $title . "</p>"; ?>
      </div>
    </div>

    <div class="row second">
      <div class="grid-two-thirds">
        <h1><?php print $title; ?></h1>
      </div>

      <div class="grid-third sociale-medier social-desktop"></div>
    </div>

    <div class="row second">
      <div class="grid-two-thirds">
        <?php
        print render($content['body']);

        if ($article_id = reset($content['field_borger_dk_article_ref'][0])) {
          $article = borgerdk_article_load(reset(array_keys($article_id)));
        }
        print render($content['field_borger_dk_article_ref']);
        ?>

        <h2>
          <?php print t('Kontakt'); ?>
        </h2>

        <?php
        // CONTACT BLOCK
        $args = array(
          $node->field_os2web_base_field_kle_ref['und'][0]['tid'],
          $node->field_os2web_base_field_kle_ref['und'][0]['tid']
        );
        $view = views_get_view('kontakt_kle');
        $view->set_display('default');
        $view->set_arguments($args);
        $view->execute();
        if (count($view->result) > 0) {
          $contact_block = $view->render();
        }
        else {
          $contact_block = views_embed_view('kontakt_kle', 'default', 1968);
        }
        print ($contact_block);

        $output = '';
        include_once drupal_get_path('theme', 'ishoj') . '/includes/del-paa-sociale-medier.php';
        print $output;
        ?>

        <p class="last-updated">
          <?php print t('Senest opdateret') . ' ' . format_date($node->changed, 'senest_redigeret'); ?>
        </p>

        <?php if ($article->byline): ?>
          <p class="byline">
            <?php print $article->byline; ?>
          </p>
        <?php endif; ?>
      </div>
      <div class="grid-third">
        <nav class="menu-underside">
          <ul class="menu">
            <li class="first expanded active-trail">
              <a href="#"><?php print $node->title ?></a>
              <ul class="menu">
                <?php
                $output = '';

                $nodes = array();
                foreach ($node->field_os2web_base_field_kle_ref['und'] as $kle_ref) {
                  $a = taxonomy_select_nodes($kle_ref['tid'], $pager = FALSE);
                  foreach ($a as $nid) {
                    $checkifitis = 0;
                    foreach ($nodes as $n) {
                      if ($n->nid == $nid) {
                        $checkifitis = 1;
                      }
                    }
                    if ($checkifitis == 0) {
                      $node_temp = node_load($nid);
                      $nodes[$node_temp->title] = $node_temp;
                    }
                  }
                }

                ksort($nodes);
                foreach ($nodes as $nid1) {
                  if ($node->nid != $nid1->nid) {
                    $output = $output . "<li><a href=\"" . url('node/' . $nid1->nid) . "\" title=\"" . $nid1->title . "\">" . $nid1->title . "</a></li>";
                  }
                }

                $output = $output . "</ul>";
                $output = $output . "</li>";

                // GET ALL NOTES FROM KLE REF BY TERM KLE
                $nodes = array();
                foreach ($bterm->field_os2web_base_field_kle_ref['und'] as $term_ref) {
                  $a = taxonomy_select_nodes($term_ref['tid'], $pager = FALSE);

                  foreach ($a as $nid2) {
                    $checkifitis = 0;
                    // check if node are allready there
                    foreach ($nodes as $n) {
                      if ($n->nid == $nid2) {
                        $checkifitis = 1;
                      }
                    }
                    if ($checkifitis == 0) {
                      $node_temp = node_load($nid2);
                      $nodes[$node_temp->title] = $node_temp;
                    }
                  }
                }

                ksort($nodes);
                foreach ($nodes as $nid1) {
                  if ($node->nid != $nid1->nid) {
                    $output = $output . "<li class=\"collapsed\"><a href=\"" . url('node/' . $nid1->nid) . "\" title=\"" . $nid1->title . "\">" . $nid1->title . "</a><li>";
                  }
                }

                print $output;


                ?>
              </ul>
        </nav>
      </div>
    </div>
  </div>
</section>

<?php
$options = array('absolute' => TRUE);
$nid = $node->nid; // Node ID
$abs_url = url('node/' . $nid, $options);
?>

<div class="dimmer-delsiden hidden">
  <ul>
    <li class="sociale-medier">
      <a class="sprite sprite-facebook"
         href="https://www.facebook.com/sharer/sharer.php?u=<?php print $abs_url; ?>" title="Del siden på Facebook">
        <span>
          <span class="screen-reader">Del siden på Facebook</span>
        </span>
      </a>
    </li>

    <li class="sociale-medier">
      <a class="sprite sprite-twitter" href="https://twitter.com/home?status=<?php print($title . ' ' . $abs_url); ?>"
         title="Del siden på Twitter">
      <span>
        <span class="screen-reader">Del siden på Twitter</span>
      </span>
      </a>
    </li>

    <li class="sociale-medier">
      <a class="sprite sprite-googleplus" href="https://plus.google.com/share?url=<?php print $abs_url; ?>"
         title="Del siden på Google+">
      <span>
        <span class="screen-reader">Del siden på Google+</span>
      </span>
      </a>
    </li>

    <li class="sociale-medier">
      <a class="sprite sprite-linkedin"
         href="https://www.linkedin.com/shareArticle?url=<?php print $abs_url; ?>&title=<?php print $title; ?>&summary=&source=&mini=true"
         title="Del siden på LinkedIn">
      <span>
        <span class="screen-reader">Del siden på LinkedIn</span>
      </span>
      </a>
    </li>

    <li class="sociale-medier">
      <a class="sprite sprite-mail" href="mailto:?subject=<?php print $title; ?>&body=<?php print $abs_url; ?>"
         title="Send som e-mail">
      <span>
         <span class="screen-reader">Send som e-mail</span>
      </span>
      </a>
    </li>

    <li class="sociale-medier">
      <a class="sprite sprite-link" href="#" title="Del link">
        <span>
          <span class="screen-reader">Del link</span>
        </span>
      </a>
    </li>
  </ul>
  <div class="link-url">
    <textarea><?php print $abs_url; ?></textarea>
  </div>
</div>




