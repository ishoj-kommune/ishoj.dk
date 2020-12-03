    <!-- PAGE START -->
    <div data-role="page"> 
      
      <!-- CONTENT START -->
      <div data-role="content"> 
                
        <!-- ARTIKEL START -->
        <section class="artikel">
          <div class="container">
            <div class="row">
              <div class="grid-two-thirds">
                <h1>Velkommen 
                <?php 

                  global $user;
                  $user_fields = user_load($user->uid);

                  if($user_fields->field_fornavn) {
                    $fornavn = $user_fields->field_fornavn['und'][0]['value'];
                    if(strpos($fornavn, " ") !== false) {
                      print strstr($fornavn, " ", true);
                    }
                    else {
                      print $fornavn;
                    }
//                    print substr($fornavn, 0, 6);
                  }

                  ?>
                  </h1>
                  <?php
                    $block = module_invoke('block', 'block_view', '1');
                    print render($block['content']);
                    ?>
              </div>
      
            </div>
          </div>
        </section>
        <!-- ARTIKEL SLUT -->
        
      </div>
      <!-- CONTENT SLUT -->
      
    </div>
    <!-- PAGE SLUT -->



<?php




  
  
?>