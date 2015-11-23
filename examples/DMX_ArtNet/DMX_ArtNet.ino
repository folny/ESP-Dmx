#include "ESP8266WiFi.h"
#include "ESP8266mDNS.h"
#include "WiFiUdp.h"
#include "ESP_Artnet.h"
#include "ESPDMX.h"

DMXESPSerial dmx;         /*serial object */

Artnet artnet;

// Change ip and mac address for your setup
uint8_t ip[] = {192, 168, 2, 100};
uint8_t mac[] = {0x04, 0xE9, 0xE5, 0x00, 0x69, 0xEC};
char ssid[] = "SSID"; //  your network SSID (name)
char pass[] = "PASSWORD";    // your network password (use for WPA, or use as key for WEP)

void setup()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin ( ssid, pass );
  Serial.begin(115200);
  delay(10);
  while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
}
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("Server started");
  Serial.println(WiFi.localIP());

  artnet.begin(mac, ip);
  dmx.init();
  artnet.setArtDmxCallback(onDmxFrame1);
}

void loop()
{
  artnet.read();
}

void onDmxFrame1(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t* data)
{
  if (universe == 0)  {
      for (int i = 0; i < 512; i++){
      dmx.write(i, data[i - 1]);
   }
  dmx.update();
  }
  
}
