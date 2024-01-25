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
char ssid[] = "NETGEAR63";
char password[] = "littlecello367";
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
int target; 

void setup() {
  Serial.begin(9600);
  connectToWiFi();
  delay(200);
  // send post request and headers
  postBody = "position=1";
  //position = "0";
  postBody += position;
 if(connect() == true){
// send post body
  client.println("POST /api/arrived/kltg2568 HTTP/1.1");  
  client.println("Content-Type: application/x-www-form-urlencoded");
  client.print("Content-Length: ");
  client.println(postBody.length());
  Serial.println("-> " + postBody);
  client.println();
  client.println(postBody);
 }
  delay(500);
}

void loop(){
  
//Serial.println("NOW IN LOOP" );
int statusCode = getStatusCode(_read);
  
    
     // send post body
  _read = readResponse();
  _send = getResponseBody(_read);
  String body = getResponseBody(_read);
 
  Serial.println();
  Serial.println(_send);
  position = _read;
  postBody = "position=";
  postBody += position;
// check if at final destination
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
int getStatusCode(String& response) {
String code = response.substring(9, 12);
return code.toInt();
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
