(function () {
'use strict';

  jQuery(document).ready(function() {
  if(jQuery("#edit-field-os2web-base-field-faq-en-und:checked").length > 0) {
     jQuery('#edit-field-os2web-base-field-faq').show();
    }else{
        jQuery('#edit-field-os2web-base-field-faq').hide();
  }
  jQuery("#edit-field-os2web-base-field-faq-en-und").change(function() {
    if(this.checked) {
        jQuery('#edit-field-os2web-base-field-faq').show();
    }else{
        jQuery('#edit-field-os2web-base-field-faq').hide();
    }
  }
  )})  
  })(jQuery);

