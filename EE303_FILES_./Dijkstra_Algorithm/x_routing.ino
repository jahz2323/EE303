char route_arr[10];
int int_route[5]; 
unsigned int len = 5;
bool visited;
bool active;

void setup() {
  Serial.begin(9600);
  if (connect() == true) {
    // send post body
    client.println("GET /api/getRoute/kltg258 HTTP/1.1");
    client.println("Content-Type: application/x-www-form-urlencoded");
    client.print("Content-Length: ");
    delay(50);
  }

  String Full_Route = readResponse();
  int statusCode = getStatusCode(Full_Route);
  if (statusCode == 200) {
    // success, read body
    String Route_Arr = getResponseBody(Full_Route);
    Route_Arr.toCharArray(route_arr, len);
    Serial.println("Full route is....");
    for (int i = 0; i < len; i++) {
      Serial.print(route_arr[i]);
      int_route[i] = atoi(&route_arr[i]);
    }
  }
  Queue<int, 5> myQueue;
  // Enqueue elements
  myQueue.enqueue(int_route[0]);
  myQueue.enqueue(int_route[1]);
  myQueue.enqueue(int_route[2]);
  myQueue.enqueue(int_route[3]);
  myQueue.enqueue(int_route[4]);
}
void loop() {
   // Dequeue and print elements
  Serial.println(myQueue.dequeue()); // Should print 1
  Serial.println(myQueue.dequeue()); // Should print 2

  // Enqueue more elements
  myQueue.enqueue(4);
  myQueue.enqueue(5);

  // Peek at the front element
  Serial.println(myQueue.peek()); // Should print 3
}
void turn_right() {
  digitalWrite(motor1Phase, HIGH); //forward
  digitalWrite(motor2Phase, HIGH); //forward
  analogWrite(motor1PWM, 200); // set speed of motor
  analogWrite(motor2PWM, 200); // set speed of motor
}
void turn_left() {
  digitalWrite(motor1Phase, HIGH); //forward
  digitalWrite(motor2Phase, HIGH); //forward
  analogWrite(motor1PWM, 200); // set speed of motor
  analogWrite(motor2PWM, 200); // set speed of motor
}
void rotate_orientation() {
  digitalWrite(motor1Phase, HIGH); //forward
  digitalWrite(motor2Phase, HIGH); //forward
  analogWrite(motor1PWM, 200); // set speed of motor
  analogWrite(motor2PWM, 200); // set speed of motor
}
