#include <SimpleDHT.h>                   
#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include "MHZ19.h"

// WiFi parameters
#define WLAN_SSID       "YOUR_SSID"       
#define WLAN_PASS       "YOUR_PASWORD"

// Adafruit IO
#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883
#define AIO_USERNAME    "YOUR_USERNAME"
#define AIO_KEY         "YOUR_KEY" 
WiFiClient client;

// Create 3 feeds in io.adafreuit to add to a dashboard: Temperature, Humidity and CO2

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);
Adafruit_MQTT_Publish Temperature = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Temperature");
Adafruit_MQTT_Publish Humidity = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Humidity");
Adafruit_MQTT_Publish CO2 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/CO2");

int pinDHT22 = 12;      // DHT sensor pin
const int pwmpin = 14;  // MHZ19 sensor pin

MHZ19 *mhz19_pwm = new MHZ19(pwmpin);
SimpleDHT22 dht22(pinDHT22);

byte hum = 0;  //Stores humidity value
byte temp = 0; //Stores temperature value
byte co2ppm = 0; //Stores CO2 value

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("MH-Z19 now warming up...  status:");
  delay(3000);
  Serial.println(F("Initializing Sensors..."));
  // Connect to WiFi access point.
  Serial.println(); Serial.println();
  delay(10);
  Serial.print(F("Connecting to "));
  Serial.println(WLAN_SSID);
  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(F("."));
  }
  Serial.println();
  Serial.println(F("WiFi connected"));
  Serial.println(F("IP address: "));
  Serial.println(WiFi.localIP());

  // connect to adafruit io
  connect();

}

// connect to adafruit io via MQTT
void connect() {
  Serial.print(F("Connecting to Adafruit IO... "));
  int8_t ret;
  while ((ret = mqtt.connect()) != 0) {
    switch (ret) {
      case 1: Serial.println(F("Wrong protocol")); break;
      case 2: Serial.println(F("ID rejected")); break;
      case 3: Serial.println(F("Server unavail")); break;
      case 4: Serial.println(F("Bad user/pass")); break;
      case 5: Serial.println(F("Not authed")); break;
      case 6: Serial.println(F("Failed to subscribe")); break;
      default: Serial.println(F("Connection failed")); break;
    }

    if(ret >= 0)
      mqtt.disconnect();

    Serial.println(F("Retrying connection..."));
    delay(10000);
  }
  Serial.println(F("Adafruit IO Connected!"));
}

void loop() {
  // ping adafruit io a few times to make sure we remain connected
  if(! mqtt.ping(3)) {
    // reconnect to adafruit io
    if(! mqtt.connected())
      connect();
  }
  dht22.read(&temp, &hum, NULL);
  Serial.print((int)temp); Serial.print(" *C, "); 
  Serial.print((int)hum); Serial.println(" H");
   
   int co2ppm = mhz19_pwm->getPpmPwm();
   Serial.print("co2: ");
   Serial.println(co2ppm);
  delay(15000);     // Change this delay to increase the time to post to Adafruit
   
   if (! Temperature.publish(temp)) {                     //Publish to Adafruit
      Serial.println(F("Failed"));
    } 
       if (! Humidity.publish(hum)) {                     //Publish to Adafruit
      Serial.println(F("Failed"));
    }
       if (! CO2.publish(co2ppm)) {                     //Publish to Adafruit
      Serial.println(F("Failed"));
    }    
    else {
      Serial.println(F("Sent!"));
    }
}
