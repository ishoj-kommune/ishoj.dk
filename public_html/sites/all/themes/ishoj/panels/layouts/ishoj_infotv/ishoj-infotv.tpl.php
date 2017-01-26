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
//      $output .= "<li data-duration=\"0.001\" class=\"infotv-dummy\"></li>";


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

        $url = "http://prod.booksys.dk/infoapi/rest/rfv/YY0002"; // json fra Kiehn (må efter aftale max hentes hvert 5. minut)
        $request = drupal_http_request($url);
        $json_response = drupal_json_decode($request->data);

        if($json_response) {
          $data = $json_response['bookings'];
          // var_dump($data);
          // $data_length = sizeof($data); // antallet af elementer

          // Antallet af aktuelle aktiviteter (aktiviteter som er i gang og fremtidige aktiviteter på dagen)
          $current_time = time(); // Unix Epoch
          $current_elements = 0;
          foreach ($data as $response_data) {
            if($response_data['slut'] >= $current_time) {
              $current_elements++;
            }
          }

          // Antallet af sider (8 elementer pr. side)
          $elements_pr_page = 8;
          $current_pages = intval($current_elements / $elements_pr_page);
          if(($current_elements % $elements_pr_page) > 0) {
            $current_pages++;
          }

          for($i = 0; $i < $current_pages; $i++) {
            $idraetscenter .= '<li data-page="' . $current_pages . '" class="infotv-skabelon idraetscenter-lokalebooking" data-duration="20">';

              $idraetscenter .= '<div class="container">';

              $idraetscenter .= '<div class="header">';
                // $idraetscenter .= '<span class="animationForward">AKTIVITETER I DAG</span>';
                $idraetscenter .= '<span class="animationForward">' . format_date(time(), 'custom', 'l j. F Y') . '</span>'; // Datoformat: FREDAG 6. NOVEMBER 2015

                // $idraetscenter .= '<div class="pagers">';
                //   $idraetscenter .= '<div class="pager active"></div>';
                //   $idraetscenter .= '<div class="pager"></div>';
                //   $idraetscenter .= '<div class="pager"></div>';
                // $output .= '</div>';
              $idraetscenter .= '</div>';

              // Rækker med skiftevis lys/mørk baggrund
              for($j = 0; $j < $elements_pr_page; $j++) {
                if ($j % 2 == 0) {
                  // even
                  $idraetscenter .= '<div class="even">';
                }
                else {
                  // odd
                  $idraetscenter .= '<div class="odd">';
                }
                $idraetscenter .= '</div>';
              }

              // Rækker med tekstindhold
              $elements_counter = 1;
              foreach ($data as $response_data) {
                if($response_data['slut'] >= $current_time) {

                  if(($elements_counter > ($i * $elements_pr_page)) and ($elements_counter <= (($i + 1) * $elements_pr_page))) {
                    $idraetscenter .= '<div class="row row-' . ($elements_counter % $elements_pr_page) . '">';
                      $idraetscenter .= '<span class="time">' . date("H:i", $response_data['start']) . ' - ' . date("H:i", $response_data['slut']) . '</span>';
                      $idraetscenter .= '<span class="room">' . $response_data['beskrivelse'] . '</span>';
                      $idraetscenter .= '<span class="company">' . $response_data['navnFirma'] . '</span>';
                    $idraetscenter .= '</div>';
                  }

                  $elements_counter++;
                }
              }
              $idraetscenter .= '</div>';
            $idraetscenter .= '</li>';
          }

          // Hvis $current_pages < 2 (der må ikke være kun én side, da Flexslideren derved går i stå), lav da en dublikat af li-elementet
          if($current_pages < 2) {
            // Ingen aktiviteter i dag (eller ikke flere i dag)
            if($current_pages = 0) {
              $idraetscenter .= '<li class="infotv-skabelon idraetscenter-lokalebooking" data-duration="10">';
                $idraetscenter .= '<div class="container">';
                  $idraetscenter .= '<div class="header">';
                    $idraetscenter .= '<span class="animationForward">INGEN AKTIVITETER I DAG</span>';
                  $idraetscenter .= '</div>';
                $idraetscenter .= '</div>';
              $idraetscenter .= '</li>';
            }
            $output .= $idraetscenter . $idraetscenter;
          }
          else {
            $output .= $idraetscenter;
          }
        }
      }
      ///////////////////////////////////////////////////////
      

      print $output;
      print $content['content']; ?>
      <!-- info-tv slut -->
    </ul>
  </div>
</section>
