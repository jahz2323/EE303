#define BUFSIZE 512
#include <SLFS.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>
#include <WiFi.h>
#include <SPI.h>

// wifi details
WiFiClient client;
char ssid[] = "NETGEAR65";
char password[] = "freshbird648";
String postBody;
String position;
char server[] = "3.250.38.184"; 
int port = 8000;
//remote control config 
int x; 
int y;
int z;
 
//responses 
String _read;
String _send; 

void setup() {
  Serial.begin(9600);
  delay(1000);
  connectToWiFi();
  // send post request and headers
  postBody = "position=";
  position = "0";
  postBody += position;

// send post body
  client.println(postBody);
}

void loop(){
  
  client.println("POST /api/arrived/kltg2668/1.1");  
  client.println("Content-Type: application/x-www-form-urlencoded");
  client.print("Content-Length: ");
  client.println(postBody.length());
  client.println("Connection: close");
  client.println();

   // send post body
   client.println(postBody);
   _read = readResponse();
   _send = getResponseBody(_read);
   Serial.println(_send);
   client.stop();
   position = _send;
   postBody = "position=";
   postBody += position;
   if(position!="undefined"){
    // normal function
  }
  else{
    // stop code
    while (1) {}
    }
  }

bool connect() {
  Serial.println("Connecting to server");
    if (!client.connect(server, port)) {
    Serial.println("error connecting to server");
  return false;
    }
    Serial.println("Connected to server");
    return true;
}

String readResponse() {
  char buffer[BUFSIZE];
  memset(buffer, 0, BUFSIZE);
  client.readBytes(buffer, BUFSIZE);
  String response(buffer);
  return response;
}
String getResponseBody(String& response) {
  int split = response.indexOf("\r\n\r\n");
  String body = response.substring(split+4, response.length());
  body.trim();
  return body;
}

void connectToWiFi() {
  Serial.print("Connecting to network: ");
  Serial.print(ssid);
  Serial.flush();
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    Serial.flush();
    delay(300);
  }
  Serial.println("Connected");
  Serial.print("Obtaining IP address");
  Serial.flush();

  while (WiFi.localIP() == INADDR_NONE) {
  Serial.print(".");
  Serial.flush();
  delay(300);
}
  Serial.println();
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}
