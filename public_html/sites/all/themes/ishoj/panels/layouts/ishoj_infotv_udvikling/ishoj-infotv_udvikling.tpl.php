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
      
      
      // UGLEN - START
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
      // UGLEN - SLUT

      
      print $output;
      print $content['content']; 
      
      ?>
      <!-- info-tv slut -->
    </ul>
  </div>
</section>
