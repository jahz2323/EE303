// keep A8 free for tone O/P music
#define BUFSIZE 512
#include <SLFS.h>
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
String body;
int _position;
char server[] = "3.250.38.184";
int port = 8000;

bool JP = false; 
int destination;
//responses

//int target;

void setup() {
  Serial.begin(9600);
  connectToWiFi();
  delay(200);
  // send post request and headers
  postBody = "position=";
  position = "0";
  postBody += position;
  if (connect() == true) {
    // send post body
    client.println("POST /api/arrived/kltg2568 HTTP/1.1");
    client.println("Content-Type: application/x-www-form-urlencoded");
    client.print("Content-Length: ");
    client.println(postBody.length());
    Serial.println("-> " + postBody);
    client.println();
    client.println(postBody);
    delay(50);
  }
  
}
void loop() {
  
  String _read = readResponse();
  // get status code
  int statusCode = getStatusCode(_read);
  
  if (statusCode == 200) {
    // success, read body
    String body = getResponseBody(_read);
    // check if at final destination
    if (!body.equals("Finished")) {
      if(JP = true){
      destination = body.toInt();
      postBody = "position=";
      position = String(destination);
      postBody += position;
      Serial.println("Postbody ="+ postBody);
      
        // send post body
        client.println("POST /api/arrived/kltg2568 HTTP/1.1");
        client.println("Content-Type: application/x-www-form-urlencoded");
        client.print("Content-Length: ");
        client.println(postBody.length());
        Serial.println("-> " + postBody);
        client.println();
        client.println(postBody);
        JP = false; 
      }
      
    }
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
  String body = response.substring(split + 4, response.length());
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
