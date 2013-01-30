/*
  This is the code for controlling the lights in my home automation project.
  This is generic-ish code to control a bank of 4 relays
  There are 3 HTTP requests for each relay...
  
  HTTP GET    http://192.168.1.50/relay/1 -- Get the state of relay 1
  HTTP POST   http://192.168.1.50/relay/1 -- Turn relay 1 on
  HTTP DELETE http://192.168.1.50/relay/1 -- Turn relay 1 off
  
  Relays are ID'd as 1, 2, 3 and 4
*/

#include <SPI.h>
#include <Ethernet.h>
#include <dht11.h>
#include <WebServer.h>

static byte mac[] =  {0x12, 0x34, 0x56, 0x78 };
byte ip[] = { 192, 168, 1, 50 };
byte gateway[] = { 192, 168, 0, 1 };
byte subnet[] = { 255, 255, 255, 0 };

WebServer webserver("", 80);

int relay1Pin = 8;
int relay2Pin = 7;
int relay3Pin = 6;
int relay4Pin = 5;

void switchRelay(WebServer &server, WebServer::ConnectionType type, char **url_path, char *url_tail, bool tail_complete)
{
  int relayPin = -1;
  if (sizeof(url_path) == 2 && strcmp(url_path[0], "relay") == 0)
  {
    switch (atoi(url_path[1]))
    {
      case 1:
        relayPin = relay1Pin; 
        break;
      case 2:
        relayPin = relay2Pin;
        break;
      case 3:
        relayPin = relay3Pin;
        break;
      case 4:
        relayPin = relay4Pin;
        break;
    }
  }
  
  if (relayPin == -1)
  {
    server.httpFail();
    return;
  }
  
  if (type == WebServer::POST)
  {
     digitalWrite(relayPin, LOW);
     boolean state = !digitalRead(relayPin);
     server.httpSuccess("application/json");
     server.print("{\"status\": true, \"state\": " + String(state) + "}");
   }
   else if (type == WebServer::DELETE)
   {
     digitalWrite(relayPin, HIGH);
     boolean state = !digitalRead(relayPin);
     server.httpSuccess("application/json");
     server.print("{\"status\": true, \"state\": " + String(state) + "}");
   }
   else if (type == WebServer::GET)
   { 
     boolean state = !digitalRead(relayPin);
     server.httpSuccess("application/json");
     server.print("{\"status\": true, \"state\": " + String(state) + "}");
   }
}

void setup()
{
  Serial.begin(9600);
  
  // Setup network stack
  Ethernet.begin(mac, ip, gateway, subnet);
  
  Serial.print("IP address: ");
  for (byte thisByte = 0; thisByte < 4; thisByte++) {
    // print the value of each byte of the IP address:
    Serial.print(Ethernet.localIP()[thisByte], DEC);
    Serial.print("."); 
  }
  Serial.println();
  Serial.println("Network stack setup is complete");
  
  // Initalize all relays
  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);
  pinMode(relay3Pin, OUTPUT);
  pinMode(relay4Pin, OUTPUT);
 
  digitalWrite(relay1Pin, HIGH);
  digitalWrite(relay2Pin, HIGH); 
  digitalWrite(relay3Pin, HIGH); 
  digitalWrite(relay4Pin, HIGH);
  
  Serial.println();
  Serial.println("Relay setup is complete");
  
  webserver.setUrlPathCommand(&switchRelay);
  webserver.begin();
}

void loop()
{
  char buff[64];
  int len = 64;
  webserver.processConnection(buff, &len); 
}

