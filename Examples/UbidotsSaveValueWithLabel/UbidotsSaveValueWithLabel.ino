#include "UbidotsMicroESP8266.h"

#define TOKEN  "Your_token_here"  // Put here your Ubidots TOKEN
#define WIFISSID "Your_WiFi_SSID" // Put here your Wi-Fi SSID
#define PASSWORD "Your_WiFi_Password" // Put here your Wi-Fi password

Ubidots client(TOKEN);

void setup(){
    Serial.begin(115200);
    client.wifiConnection(WIFISSID, PASSWORD);
    //client.setServerEndpoint("translate.ubidots.com");  // Uncomment this line if you are an educational user
    //client.setDebug(true); // Uncomment this line to print debug lines

}
void loop(){
    float value1 = analogRead(0);
    //float value2 = random(0, 1000)*1.0;
    client.add("temperature", value1);
    //client.add("switch", value2);
    if (client.sendAll(true)) {
      Serial.println("\nSucessfull!");
    } else {
      Serial.println("\nThere was an error sending your data");
    }
    delay(5000);
}