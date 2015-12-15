<?php

// Plugin definition
$plugin = array(
  'title' => t('Info-tv-udvikling'),
  'category' => t('Ishøj Kommune'),
  'icon' => 'ishoj_infotv_udvikling.png',
  'theme' => 'ishoj_infotv_udvikling',
  'css' => 'ishoj_infotv_udvikling.css',
  'regions' => array(
	'content' => t('INDHOLD'),
	'overlay_top' => t('OVERLAY (uden tjek af indhold)'),
	'overlay_bottom' => t('OVERLAY (med tjek af indhold)')
  ),
);
