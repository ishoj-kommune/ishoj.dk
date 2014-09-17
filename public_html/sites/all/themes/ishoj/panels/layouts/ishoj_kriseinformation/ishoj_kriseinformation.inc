<?php

// Plugin definition
$plugin = array(
  'title' => t('Kriseinformation'),
  'category' => t('Ishøj Kommune'),
  'icon' => 'ishoj_kriseinformation.png',
  'theme' => 'ishoj_kriseinformation',
  'css' => 'ishoj_kriseinformation.css',
  'regions' => array(
	'article' => t('Artikel'),
	'right' => t('Højre kolonne'),
	'navigation' => t('Navigation')
  ),
);
