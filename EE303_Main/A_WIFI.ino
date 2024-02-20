#define BUFSIZE 512
#include <SLFS.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>
#include <WiFi.h>
#include <SPI.h>

// wifi details
WiFiClient client;
// char ssid[] = "NETGEAR63";
// char password[] = "littlecello367";
char ssid[] = "iot";
char password[] = "disdaining78compromiser";


String position;
String body;

char server[] = "3.250.38.184";
int port = 8000;

//responses

//int target;

void setup() {
  Serial.begin(9600);
  connectToWiFi();
  delay(2000);
  // send post request and headers
  String postBody("position=");
  postBody += position;
  
if (connect() == true) {
//     send post body
//    client.println("GET /api/getRoute/kltg2568 HTTP/1.1");
//    client.println("Content-Type: application/x-www-form-urlencoded");
//    client.print("Content-Length: ");
//    client.println(postBody.length());
//    Serial.println("-> " + postBody);
//    client.println();
//    client.println(postBody);
    delay(50);
    }
}

void POST_position(int value) {
  
  position = String(value);
  String postBody("position=");
  postBody += position;
  client.println("POST /api/arrived/kltg2568 HTTP/1.1");
  client.println("Content-Type: application/x-www-form-urlencoded");
  client.print("Content-Length: ");
  client.println(postBody.length());
  Serial.println("-> " + postBody);
  client.println();
  client.println(postBody);
}


int Read_Response() {
  int destination;
  String read = readResponse();
 
  int statusCode = getStatusCode(read);
  if (statusCode == 200) {
    // success, read body
    String body = getResponseBody(read);
    // check if at final destination
    if (!body.equals("Finished")) {
      destination = body.toInt();
    }
    else {
      client.stop();
      stopmotor();
    }
  }
  return destination;
}
void loop() {

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


int getStatusCode(String & response) {
  String code = response.substring(9, 12);
  return code.toInt();
}

String readResponse() {
  char buffer[BUFSIZE];
  memset(buffer, 0, BUFSIZE);
  client.readBytes(buffer, BUFSIZE);
  String response(buffer);
  //  String route = response.substring(264, 276);
  //  Serial.println(route);
  return response;
}

String getResponseBody(String & response) {
  int split = response.indexOf("\r\n\r\n");
  String body = response.substring(split + 4, response.length());
  body.trim();
  return body;
}

String getRoute(String & response) {
  String route = response.substring(264, 276);
  Serial.println(route);
  return route;
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
