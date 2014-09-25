### The mechanism is the following:
- 1. User submits his email address and the list of committees.
- 2.1 If the notification tick in the settings is checked user gets a notification email which he has to confirm. 
- 2.1.1. The confirmation email subject and body are configured in the settings. 
- 2.1.2. After a confirmation user is subscribed to the notifications from the selected committee.
- 2.2 If notification tick is not checked, user is subscribed to the notifications right away.
- 3. When meeting gets published (node_save hook) and its status is Dagsorden or Referat the subscribed users get notification.
- 4. The notification email subject and body are configured in the settings. 
- 4.1 If admin decides to enable unsubscription option - he can add the link to the email body. 
- 4.1.1 The are separate links to unsubscribe from this particular committee or from all committees.
