



int motor1PWM = 39; // P2.6
int motor1Phase = 40; // P2.7
int motor2PWM = 37; // P2.6
int motor2Phase = 38; // P2.7

bool motor_flag;

// the setup routine runs once when you press reset:
void setupC_Motor()
{ 
  Serial.begin(9600);
  delay(10000);
}
// the loop routine runs over and over again continuously:
void loopC_Motor()
  {
    if ((AnalogValue[2] < 600) && (AnalogValue[0] > 600) && (AnalogValue[4] > 600)) {
      digitalWrite(motor1Phase, HIGH); //forward
      digitalWrite(motor2Phase, HIGH); //forward
      analogWrite(motor1PWM, 180); // set speed of motor
      analogWrite(motor2PWM, 180); // set speed of motor

    }
    //REACHED STATION
    else if ( (AnalogValue[0] < 600) && (AnalogValue[2] < 600) && (AnalogValue[4] < 600)) {
      digitalWrite(motor1Phase, HIGH); //forward
      digitalWrite(motor2Phase, HIGH); //forward
      analogWrite(motor1PWM, 0); // set speed of motor
      analogWrite(motor2PWM, 0); // set speed of motor
      //Serial.println("station"); // Display motor direction
      junction();
      delay(300);
      analogWrite(motor1PWM, 70); // set speed of motor
      analogWrite(motor2PWM, 70); // set speed of motor
      delay(300);
    }
    else if (AnalogValue[3] < 600) {
      digitalWrite(motor1Phase, HIGH); //forward
      digitalWrite(motor2Phase, HIGH); //forward
      analogWrite(motor1PWM, 70); // set speed of motor
      analogWrite(motor2PWM, 150); // set speed of motor
     // Serial.println("RIGHT"); // Display motor direction
    }
    else if (AnalogValue[4] < 600) {
      digitalWrite(motor1Phase, HIGH); //forward
      digitalWrite(motor2Phase, HIGH); //forward
      analogWrite(motor1PWM, 50); // set speed of motor
      analogWrite(motor2PWM, 180); // set speed of motor
      //Serial.println("RIGHT"); // Display motor direction
    }
    else if (AnalogValue[1] < 600) {
      digitalWrite(motor1Phase, HIGH); //forward
      digitalWrite(motor2Phase, HIGH); //forward
      analogWrite(motor1PWM, 150); // set speed of motor
      analogWrite(motor2PWM, 70); // set speed of motor
     // Serial.println("LEFT"); // Display motor direction
    }
    else if (AnalogValue[0] < 600) {
      digitalWrite(motor1Phase, HIGH); //forward
      digitalWrite(motor2Phase, HIGH); //forward
      analogWrite(motor1PWM, 180); // set speed of motor
      analogWrite(motor2PWM, 50); // set speed of motor
     // Serial.println("LEFT"); // Display motor direction
    }
//    else {
//      analogWrite(motor1PWM, 0); // set speed of motor
//      analogWrite(motor2PWM, 0); // set speed of motor
//      // Serial.println("STOPPED");
//    }
}
