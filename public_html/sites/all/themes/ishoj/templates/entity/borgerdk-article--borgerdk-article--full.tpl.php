<?php

/**
 * @file
 * Default theme implementation for entities.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) entity label.
 * - $url: Direct url of the current entity if specified.
 * - $page: Flag for the full page state.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-{ENTITY_TYPE}
 *   - {ENTITY_TYPE}-{BUNDLE}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>
<?php $entity = $variables['borgerdk_article']; ?>
<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="content"<?php print $content_attributes; ?>>
    <h2>
      <?php
      $content['header']['#label_display'] = 'hidden';
      print render($content['header']);
      ?>
    </h2>

    <h3>
      <?php print t('Selvbetjening'); ?>
    </h3>

    <?php
    foreach (array_keys($content['microarticles']['#items']) as $mkey) {
      $content['microarticles'][$mkey]['borgerdk_microarticle'][$mkey]['selfservices']['#label_display'] = 'hidden';
      print render($content['microarticles'][$mkey]['borgerdk_microarticle'][$mkey]['selfservices']);
    }
    ?>

    <h2>
      <?php print t("Læs om ") . lcfirst($entity->title); ?>
    </h2>

    <div class="microArticleContainer">
      <?php
      $content['microarticles']['#label_display'] = 'hidden';
      print render($content['microarticles']);
      ?>
    </div>

    <h2>
      <?php print t('Læs også'); ?>
    </h2>
    <?php
    $content['recommendation']['#label_display'] = 'hidden';
    print render($content['recommendation']);
    ?>

  </div>
</div>