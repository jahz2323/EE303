void setupE_Manual() {
  
}

void loopE_Manual() {
  
}

void spin_turn(){
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
      delay(500);
   
}

void right_angle_turn() {
      digitalWrite(motor1Phase, HIGH); //forward
      digitalWrite(motor2Phase, HIGH); //forward
      analogWrite(motor1PWM, 0); // set speed of motor
      analogWrite(motor2PWM, 150); // set speed of motor
      delay(500);
 
}

void move_to_five() {
      digitalWrite(motor1Phase, HIGH); //forward
      digitalWrite(motor2Phase, HIGH); //forward
      analogWrite(motor1PWM, 100); // set speed of motor
      analogWrite(motor2PWM, 100); // set speed of motor
      delay(2000);

}
