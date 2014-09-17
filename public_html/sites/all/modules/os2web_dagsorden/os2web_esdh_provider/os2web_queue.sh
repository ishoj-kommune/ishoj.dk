#!/bin/bash
while true; do
	echo "Import queue run"
	drush scr os2web_esdh_provider.queue.php
	sleep 100
	
done
