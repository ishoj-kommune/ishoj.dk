<section class="overlay">
 <div class="spinner"></div>
  <?php print $content['overlay_top']; ?>
  <div class="overlay_bottom">
    <!-- overlay-bottom start -->
    <?php print $content['overlay_bottom']; ?>
    <!-- overlay-bottom slut -->
  </div>
</section>
<section class="slider hide"> 
  <div class="flexslider">
    <ul class="slides">
      <!-- info-tv start -->
      <?php
      $output = ""; 
      
      
      // Dummy
      $output .= "<li data-duration=\"0.1\" class=\"infotv-dummy\"></li>"; 

      
      /////////////////////////////////////////
      //////////////  U G L E N  //////////////
      /////////////////////////////////////////
      if($_GET['uglen'] == '1') {
        
        // TOPNYHEDER
        $url = "http://uglen.ishoj.dk/json-nyheder-uglen?no_login=1&hest=" . rand();
        $request = drupal_http_request($url);
        $json_response = drupal_json_decode($request->data);
        if($json_response) { 
          foreach ($json_response as $response_data) {

            $output .= '<li class="infotv-skabelon">';
//              $output .= '<img src="' + val.billede.src + '">';
              $output .= '<img src="' . $response_data['billede'] . '">';
              $output .= '<div class="bgBox animationForward animationBack animationStart"></div>';
              $output .= '<div class="bgBoxInvisible animationForward animationBack animationEnd">';
                $output .= '<h1>' . $response_data['titel'] . '</h1>';
                if($response_data['resume']) {
                  $output .= '<p>' . $response_data['resume'] . '</p>';
                }
                $output .= '<h2>Læs mere på Uglen</h2>';
              $output .= '</div>';
            $output .= '</li>';
          }
        }
        
        // ALMINDELIGE NYHEDER
        $url = "http://uglen.ishoj.dk/json-nyheder-uglen-alle?no_login=1&hest=" . rand();
        $request = drupal_http_request($url);
        $json_response = drupal_json_decode($request->data);

        if($json_response) { 
          $output .= '<li class="infotv-skabelon uglen-alle-nyheder">';
          $output .= '<img src="/sites/all/themes/ishoj/img/sprites-no/infotv-nyt-paa-uglen2.png">';
            $output .= '<h1 class="animationForward">Nyt på Uglen</h1>';

            $i = 0;
            foreach ($json_response as $response_data) {

              switch ($i) {
                case 0:
                  $output .= '<ul>';  
                  $output .= '<li>' . $response_data['titel'] . '</li>';
                  break;
                case 2:
                  $output .= '<li class="animationStart">' . $response_data['titel'] . '</li>';  
                  $output .= '</ul>';
                  break;
                case 3:
                  $output .= '<ul class="last">';  
                  $output .= '<li>' . $response_data['titel'] . '</li>';
                  break;
                case 5:
                  $output .= '<li>' . $response_data['titel'] . '</li>';  
                  $output .= '<li class="animationEnd"></li>';  
                  $output .= '</ul>';
                  break;
                default:
                  $output .= '<li>' . $response_data['titel'] . '</li>';
                  break;
              }

              $i++;
            }

          $output .= '</li>';

        }

      }

      
      
      /////////////////////////////////////////////////////////
      //////////////  U N G D O M S S K O L E N  //////////////
      /////////////////////////////////////////////////////////
      if($_GET['isung'] == '1') {
//      if (isset($_GET['isung'])) {
        
        // DAGSPLAN
        $url = "http://www.ishoj.dk/json-ungdomsskolen-dagsprogram?no_login=1&hest=" . rand();
        $request = drupal_http_request($url);
        $json_response = drupal_json_decode($request->data);
        $json_count = sizeof($json_response);
        if($json_count < 8) {
          $json_last_in_first = $json_count;
        }
        else {
          $json_last_in_first = 8;
        }
        $pages = 1;
        if($json_count > 8) {
          $pages = 2;
        }

        if($json_response) { 
          $output .= '<li data-pages="' . $pages . '" data-elements="' . $json_count . '" class="infotv-skabelon ungdomsskolen-dagensprogram">';
            $output .= '<div class="bar">';
              $output .= '<h2 class="animationForward">' . format_date(time(), 'custom', 'l j. F Y') . '</h2>'; // Datoformat: FREDAG 6. NOVEMBER 2015
            $output .= '</div>';

            if($pages == 2) {
              $output .= '<div class="pager"><span class="page-1 action"></span><span class="page-2"></span></div>';    
            }
          
            $i = 1;
            foreach ($json_response as $response_data) {
              
              $output_line = '<li>';
              $output_line .= '<span class="tid">' . $response_data['klokken'] . '</span>';
              $output_line .= '<span class="fag">' . $response_data['fag'] . '</span>';
              $output_line .= '<span class="navn">' . $response_data['underviser'] . '</span>';
              $output_line .= '<span class="lokale">' . $response_data['lokale'] . '</span>';
              $output_line .= '</li>';
              
              // <ul>
              if($i == 1) {
//                $output .= '<ul>';  
                $output .= '<ul class="animationForward">';  
              }              
              if($i == 9) {
                $output .= '<ul class="last">';
              }
              
              // <li>
              if($i == $json_last_in_first) {
                $output .= str_replace('<li>', '<li class="animationStart">', $output_line); 
              }
              else {
                $output .= $output_line;
              }
              if(($i > 8) and ($i == $json_count)) {
                $output .= '<li class="animationEnd"></li>';  
              }

              // </ul>
              if(($i == $json_count) or ($i == $json_last_in_first)) {
                $output .= '</ul>';
              }
               
              $i++;

            }

          $output .= '</li>';

        }
      }
      
      
      
      ///////////////////////////////////////////////////////
      //////////////  I D R Æ T S C E N T E R  //////////////
      ///////////////////////////////////////////////////////
      if($_GET['idraetscenter'] == '1') {
      
      }
      
        
      print $output;
      print $content['content']; 
      
      ?>
      <!-- info-tv slut -->
    </ul>
  </div>
</section>
