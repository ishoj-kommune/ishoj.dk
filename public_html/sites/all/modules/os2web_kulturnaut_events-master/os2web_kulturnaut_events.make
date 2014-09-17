api = 2
core = 7.x

;; OS2Web projects:

; OS2Web Modules

;; Contrib modules below:

; Libraries

; Contrib modules

; Features + related
projects[features][subdir] = "contrib"
projects[features][version] = "2.0-beta1"

projects[strongarm][subdir] = "contrib"
projects[strongarm][version] = "2.0"

; Panels
projects[panels][subdir] = "contrib"
projects[panels][version] = "3.2"


; Basic
projects[ctools][subdir] = "contrib"
projects[ctools][version] = "1.2"

projects[views][subdir] = "contrib"
projects[views][version] = "3.5"

projects[date][subdir] = "contrib"
projects[date][version] = "2.6"

projects[filefield_sources][subdir] = "contrib"
projects[filefield_sources][version] = "1.7"

projects[pathauto][subdir] = "contrib"
projects[pathauto][version] = "1.1"

projects[entityreference][subdir] = "contrib"
projects[entityreference][version] = "1.0"

projects[job_scheduler][subdir] = "contrib"
projects[job_scheduler][version] = "2.0-alpha3"

projects[feeds][subdir] = "contrib"
projects[feeds][version] = "2.0-alpha4"
; Patch to support import of hierarchical taxonomy terms
projects[feeds][patch][] = "http://drupal.org/files/issues/feeds_hierarchical_term_processor-1152940-23.patch"
; Patch to support text format (eg. html) when importing to custom taxonomy term fields
projects[feeds][patch][] = "http://drupal.org/files/feeds-taxonomy-text-format-1466170-1.patch"
; Patch to enable Proxy support
; projects[feeds][patch][] = "patches/feeds-proxy.patch"

projects[feeds_xpathparser][subdir] = "contrib"
projects[feeds_xpathparser][version] = "1.x-dev"
