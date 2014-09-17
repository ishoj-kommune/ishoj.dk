<?php

// Plugin definition
$plugin = array(
  'title' => t('Forside'),
  'category' => t('Ishøj Kommune'),
  'icon' => 'ishoj_forside.png',
  'theme' => 'ishoj_forside',
  'css' => 'ishoj_forside.css',
  'regions' => array(
	'content-top' => t('Top'),
	'selvbetjening' => t('Selvbetjeningsteaser'),
	'left' => t('Venstre kolonne'),
	'right1dob' => t('Højre kolonne - række 1 (dobbelt bredde)'),
	'right2single' => t('Højre kolonne - række 2'),
	'right3dob' => t('Højre kolonne - række 3 (dobbelt bredde)'),
    'right4single' => t('Højre kolonne - række 4')
  ),
);
