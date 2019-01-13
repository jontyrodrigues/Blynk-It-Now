/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************

  This sketch shows how to read values from Virtual Pins

  App project setup:
    Slider widget (0...100) on Virtual Pin V1
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
int Light = 14;
int Light0 = 12;
int Enable = 13;
bool enabled = false;
bool parameter;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = ""; //put you auth token here

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = ""; //put your ssid token here
char pass[] = ""; //put your password token here

// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin V1
BLYNK_WRITE(V0)
{
 if(param.asInt() == 1)
 {
  parameter = true;
 }
 else
 {
   parameter = false;
 }
 if(parameter == !digitalRead(Enable))
 {
  if(enabled == false)
  {
    digitalWrite(Light,HIGH);
    enabled = true;
  }
  else
  {
    digitalWrite(Light,LOW);
    enabled = false;
  }
 }
 
 // Serial.println("Toggled");
}

void setup()
{
  pinMode(Light, OUTPUT); 
  pinMode(Light0, OUTPUT);
  pinMode(Enable, INPUT);

  // Debug console
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
}

