<?php

// Plugin definition
$plugin = array(
  'title' => t('Node plus'),
  'category' => t('Ishøj Kommune'),
  'icon' => 'ishoj_node_plus.png',
  'theme' => 'ishoj_node_plus',
  'css' => 'ishoj_node_plus.css',
  'regions' => array(
	'article' => t('Artikel'),
	'articleInner' => t('Artikel inderst'),
	'right' => t('Højre kolonne'),
	'navigation' => t('Navigation')
  ),
);
