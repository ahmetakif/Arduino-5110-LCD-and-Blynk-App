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

    Social networks:            http://www.fb.com/blynkapp

                                http://twitter.com/blynk_app



  Blynk library is licensed under MIT license

  This example code is in public domain.



 *************************************************************

  This example runs directly on NodeMCU.



  Note: This requires ESP8266 support package:

    https://github.com/esp8266/Arduino



  Please be sure to select the right NodeMCU module

  in the Tools -> Board menu!



  For advanced settings please follow ESP examples :

   - ESP8266_Standalone_Manual_IP.ino

   - ESP8266_Standalone_SmartConfig.ino

   - ESP8266_Standalone_SSL.ino



  Change WiFi ssid, pass, and Blynk auth token to run :)

  Feel free to apply it to any other example. It's simple!

 *************************************************************/



/* Comment this out to disable prints and save space */

#define BLYNK_PRINT Serial



#include <ESP8266WiFi.h>

#include <BlynkSimpleEsp8266.h>



#include <SPI.h>

#include <Adafruit_GFX.h>

#include <Adafruit_PCD8544.h>

Adafruit_PCD8544 display = Adafruit_PCD8544(5, 4, 14, 12, 2);

#define NUMFLAKES 10

#define XPOS 0

#define YPOS 1

#define DELTAY 2

#define LOGO16_GLCD_HEIGHT 16

#define LOGO16_GLCD_WIDTH  1



// You should get Auth Token in the Blynk App.

// Go to the Project Settings (nut icon).

char auth[] = "...";



// Your WiFi credentials.

// Set password to "" for open networks.

char ssid[] = "...";

char pass[] = "...";



String screentext = "";

int PhoneBarSensor = 0;

int PhoneLightSensor =0;



void setup()

{

  // Debug console

  Serial.begin(9600);

  

  display.begin();

  display.setContrast(50);

  

  Blynk.begin(auth, ssid, pass);

  // You can also specify server:

  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);

  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);



  pinMode(D3,OUTPUT);

}



BLYNK_WRITE(V0) // V0 is the number of Virtual Pin  

{

  int brightnessval = param.asInt();

  analogWrite(D3,brightnessval);

}



BLYNK_WRITE(V1) // V1 is the number of Virtual Pin  

{

  display.display(); // show splashscreen

  display.clearDisplay();   // clears the screen and buffer

  

  int textindex = param.asInt();



  if (textindex == 1) {

    screentext = "Hello";

  }

  if (textindex == 2) {

    screentext = "Merhaba";

  }

  if (textindex == 3) {

    screentext = "Hallo";

  }

  if (textindex == 4) {

    screentext = "Konnichiwa";

  }

  if (textindex == 5) {

    screentext = "Bonjour";

  }

  

  display.setTextSize(1);

  display.setTextColor(BLACK);

  display.setCursor(0,0);

  display.println(screentext);

  display.setCursor(0,10);

  display.print(PhoneBarSensor);

  display.print("mbar");

  display.setCursor(0,20);

  display.print(PhoneLightSensor);

  display.print("lx");

}



BLYNK_WRITE(V2) // V2 is the number of Virtual Pin  

{

  display.display(); // show splashscreen

  display.clearDisplay();   // clears the screen and buffer

  

  int PhoneBarSensor = param.asInt();



  display.setTextSize(1);

  display.setTextColor(BLACK);

  display.setCursor(0,0);

  display.println(screentext);

  display.setCursor(0,10);

  display.print(PhoneBarSensor);

  display.print("mbar");

  display.setCursor(0,20);

  display.print(PhoneLightSensor);

  display.print("lx");

}



BLYNK_WRITE(V3) // V2 is the number of Virtual Pin  

{

  display.display(); // show splashscreen

  display.clearDisplay();   // clears the screen and buffer

  

  int PhoneLightSensor = param.asInt();



  display.setTextSize(1);

  display.setTextColor(BLACK);

  display.setCursor(0,0);

  display.println(screentext);

  display.setCursor(0,10);

  display.print(PhoneBarSensor);

  display.print("mbar");

  display.setCursor(0,20);

  display.print(PhoneLightSensor);

  display.print("lx");

}



void loop()

{

  Blynk.run();

}
