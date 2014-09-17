<?php

// Plugin definition
$plugin = array(
  'title' => t('Node'),
  'category' => t('Ishøj Kommune'),
  'icon' => 'ishoj_node.png',
  'theme' => 'ishoj_node',
  'css' => 'ishoj_node.css',
  'regions' => array(
	'article' => t('Artikel'),
	'right' => t('Højre kolonne'),
	'navigation' => t('Navigation')
  ),
);
