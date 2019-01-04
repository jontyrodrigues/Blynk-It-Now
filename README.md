# Blynk-It-Now
Using blynk and ifttt's google assistant integration toggle switches using a NodeMCU as a microcontroller
This project references https://gist.github.com/xmfcx/3e6be68dd655cd7058085702e0bcb4b0

<h2>Requirements</h2>
1. NodeMCU <br>
2. Arduino IDE - https://www.arduino.cc/en/main/software <br>
3. IFTTT for android - https://play.google.com/store/apps/details?id=com.ifttt.ifttt&hl=en_IN <br>
4. Blynk - https://www.blynk.cc/ <br>

<h2>Step One</h2>
1. Upload the sketch given to your NodeMCU using its specifications. <br>
2. For me 115200 baud rate worked. <br>
3. Modify the necessary details like your auth token, ssid and password.<br>
4. I used D5 as my output pin you can select any pin you want. <br>
5. This works on the principle that any update to a virtual pin in the Blynk sketch causes. <br>

<p><i>BLYNK_WRITE(pin)
{

}</i>

<p> to be called. <br>
6. I wanted to toggle my output instead of turning it on and off so i used that. <br>
7. You can use https://blynkapi.docs.apiary.io/#reference/0/write-pin-value-via-get/write-pin-value-via-get to update a pin
https://blynkapi.docs.apiary.io/#reference/0/write-pin-value-via-get/write-pin-value-via-get?console=1 .<br>

<h2>Step Two</h2>
1. Make a blynk account make a sketch and add a button which controls pin V0 (this is for testing no need to do this). <br>
2. Once you make a sketch you will be emailed your auth token use this in your code. <br>

<h2>Step Three</h2>
1. Download the IFTTT app on your phone. <br>
2. Create a new applet. <br>
3. In the use google assistant and use whatever you want i used say a simple phrase use whichever phrase you want. <br>
4. For the Then part use webhooks. <br>
5. Reference https://blynkapi.docs.apiary.io/#reference/0/write-pin-value-via-get/write-pin-value-via-get?console=1 .<br>
6. Your URL should look something like this http://blynk-cloud.com/<i>Your-Auth-Token</i>/update/V0?value=1 .<br>
7. Put your auth token in place of Your-Auth-Token. <br>
8. For me using blynk-cloud.com would give me error 400 on IFTTT i.e. invalid token i used ping to get the ip address of blynk-cloud.com and then use that IP address (Note: IP address can change hence using the domain name is recommended but for me it wouldn't work so i had to use that). <br>
9. Mine URL looks something like this: http://188.166.206.43/My-Auth-Token/update/V0?value=1 .<br>

Now check weather it works you can also make a widget button first in the if statement to check whether it works or not

<h2>Notice: High Voltage AC is dangerous please do not attempt if you don't have any experience</h2>
Also have provided my diagram for 2 way switch configuration which i use to toggle the input i use a spdt relay board for Arduino i.e. 3.3V and a SPDT switch to toggle the inputs.
