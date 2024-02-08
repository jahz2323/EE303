int x;
int y; 
void setup() {
  Serial1.begin(9600); /* Define baud rate for serial communication */
  Serial.begin(9600); /* Define baud rate for serial communication */
}

void loop() {
  delay(10);  // Introduce a small delay

  if (Serial1.available() >= 2)  /* Check if at least two bytes (X and Y) are available on the serial port */
  {
    char data_received_X = Serial1.read();  /* Read X coordinate from Bluetooth */
    char data_received_Y = Serial1.read();  /* Read Y coordinate from Bluetooth */

    Serial1.write(data_received_X);  /* Send X coordinate back to sender for confirmation */
    Serial1.write(data_received_Y);  /* Send Y coordinate back to sender for confirmation */

    // Process X and Y coordinates as needed
    x = data_received_X - '0';  // Convert char to int
    y = data_received_Y - '0';  // Convert char to int

    // Example: print the adjusted coordinates
    Serial.print("Received Coordinates: X=");
    Serial.print(x);
    Serial.print(", Y=");
    Serial.println(y);
    if(data_received_X == '1'){
      playmusic();
    }
  }
}

