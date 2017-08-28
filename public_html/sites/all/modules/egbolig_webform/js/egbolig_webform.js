(function($) {
    $(document).ready(function() {
        var last_child_cpr_num = 0;
        $('input[id*="child-cpr-nr"]').each(function() {
            if ($(this).val() != "") {
                last_child_cpr_num = $(this).attr('id').substring($(this).attr('id').lastIndexOf('-') + 1);
                $(this).parent('div[class*="child-cpr-nr"]').show();
            }
            else
                $(this).parent('div[class*="child-cpr-nr"]').hide();
        });
        $('input[id$="child-cpr-nr-' + (++last_child_cpr_num) + '"]').parent('div[class*="child-cpr-nr"]').show();

        $('input[id*="child-cpr-nr"]').keyup(function() {
            current_child_cpr_num = $(this).attr('id').substring($(this).attr('id').lastIndexOf('-') + 1);
            if ($(this).val() != "") {
                $('input[id*="child-cpr-nr-' + (++current_child_cpr_num) + '"]').parent('div[class*="child-cpr-nr"]').show();
            }
            else {
                $('input[id*="child-cpr-nr-' + (++current_child_cpr_num) + '"]').parent('div[class*="child-cpr-nr"]').hide();
            }
        });
    });
})(jQuery);