$(document).bind("mobileinit", function () {
    $.mobile.pushStateEnabled = true;
	$.mobile.page.prototype.options.keepNative = "select, input, textarea"; // modvirker ar jQueryMobile wrapper form elementer ind i mobil-udgaver
});
