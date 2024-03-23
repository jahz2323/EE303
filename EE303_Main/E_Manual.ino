void setupE_Manual() {

}

void loopE_Manual() {

}

void spin_turn() {
  digitalWrite(motor1Phase, LOW); //forward
  digitalWrite(motor2Phase, HIGH); //forward
  analogWrite(motor1PWM, 175); // set speed of motor
  analogWrite(motor2PWM, 175); // set speed of motor
  delay(250);
}

void left_angle_turn() {
  digitalWrite(motor1Phase, HIGH); //forward
  digitalWrite(motor2Phase, HIGH); //forward
  analogWrite(motor1PWM, 150); // set speed of motor
  analogWrite(motor2PWM, 0); // set speed of motor
  delay(100);

}

void right_angle_turn() {
  digitalWrite(motor1Phase, HIGH); //forward
  digitalWrite(motor2Phase, HIGH); //forward
  analogWrite(motor1PWM, 0); // set speed of motor
  analogWrite(motor2PWM, 150); // set speed of motor
  delay(100);

}
void stopmotor() {
  digitalWrite(motor1Phase, HIGH); //forward
  digitalWrite(motor2Phase, HIGH); //forward
  analogWrite(motor1PWM, 0); // set speed of motor
  analogWrite(motor2PWM, 0); // set speed of motor
  delay(10000);
}



bool park() {
  distance = analogRead(A5);
  Serial.print(distance);
  Serial.println("   ");
  Serial.print("\t"); //tab over on screen
  //  digitalWrite(motor1Phase, HIGH); //forward
  //  digitalWrite(motor2Phase, HIGH); //forward
  //  analogWrite(motor1PWM, 185); // set speed of motor
  //  analogWrite(motor2PWM, 185); // set speed of motor
  //  delay(4000);
  if (distance >= 0 && distance < 200) {
    Serial.println(" Moving....);
    analogWrite(motor1PWM, 230); // set speed of motor
    analogWrite(motor2PWM, 230); // set speed of motor
    park();
  }

  else if (distance > 200 && distance < 600) {
    Serial.println(" stopping...");
    analogWrite(motor1PWM, 120); // set speed of motor
    analogWrite(motor2PWM, 120); // set speed of motor
    park();
  }
  else if (distance > 600) {
    Serial.println("STOP NOW");
    digitalWrite(motor1Phase, HIGH); //forward
    digitalWrite(motor2Phase, HIGH); //forward
    analogWrite(motor1PWM, 0); // set speed of motor
    analogWrite(motor2PWM, 0); // set speed of motor
    return false;

  }
  return true;
}
