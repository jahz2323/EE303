//int route[NULL];
int route_matrix[NULL][NULL];


void setup(){
 Serial.begin(9600);
 delay(20000);
 String response = readResponse();
 String route = getRoute(response);
 Serial.println("Route is..." + route);
 
  
}
void loop(){
  
  
}
void junction(){
    Serial.println("Test");
    POST_position(0);
    int destination = Read_Response();
    Serial.println("destination is...." + destination);
}
