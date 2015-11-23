<?php

$url = "http://uglen.ishoj.dk/json-nyheder-uglen?hest=" . rand();
$json = file_get_contents($url);
//echo json_encode($json);
echo $json;


?>