




int motor1PWM = 39; // P2.6
int motor1Phase = 40; // P2.7
int motor2PWM = 37; // P2.6
int motor2Phase = 38; // P2.7

bool motor_flag;

// the setup routine runs once when you press reset:
void setup()
{ 
  Serial.begin(9600);
  delay(5000);
}
// the loop routine runs over and over again continuously:
void loop()
  {
    if ((AnalogValue[2] < 600) && (AnalogValue[0] > 600) && (AnalogValue[4] > 600)) {
      digitalWrite(motor1Phase, HIGH); //forward
      digitalWrite(motor2Phase, HIGH); //forward
      analogWrite(motor1PWM, 100); // set speed of motor
      analogWrite(motor2PWM, 100); // set speed of motor

    }
    //REACHED STATION
    else if ( (AnalogValue[0] < 600) && (AnalogValue[4] < 600) && (AnalogValue[2] < 600)) {
      digitalWrite(motor1Phase, HIGH); //forward
      digitalWrite(motor2Phase, HIGH); //forward
      analogWrite(motor1PWM, 0); // set speed of motor
      analogWrite(motor2PWM, 0); // set speed of motor
      Serial.println("station"); // Display motor direction
      junction();
    }
    else if (AnalogValue[3] < 600) {
      digitalWrite(motor1Phase, HIGH); //forward
      digitalWrite(motor2Phase, HIGH); //forward
      analogWrite(motor1PWM, 40); // set speed of motor
      analogWrite(motor2PWM, 90); // set speed of motor
      Serial.println("RIGHT"); // Display motor direction
    }
    else if (AnalogValue[4] < 600) {
      digitalWrite(motor1Phase, HIGH); //forward
      digitalWrite(motor2Phase, HIGH); //forward
      analogWrite(motor1PWM, 40); // set speed of motor
      analogWrite(motor2PWM, 180); // set speed of motor
      Serial.println("RIGHT"); // Display motor direction
    }
    else if (AnalogValue[1] < 600) {
      digitalWrite(motor1Phase, HIGH); //forward
      digitalWrite(motor2Phase, HIGH); //forward
      analogWrite(motor1PWM, 90); // set speed of motor
      analogWrite(motor2PWM, 40); // set speed of motor
      Serial.println("LEFT"); // Display motor direction
    }
    else if (AnalogValue[0] < 600) {
      digitalWrite(motor1Phase, HIGH); //forward
      digitalWrite(motor2Phase, HIGH); //forward
      analogWrite(motor1PWM, 180); // set speed of motor
      analogWrite(motor2PWM, 40); // set speed of motor
      Serial.println("LEFT"); // Display motor direction
    }
    else {
      analogWrite(motor1PWM, 0); // set speed of motor
      analogWrite(motor2PWM, 0); // set speed of motor
      // Serial.println("STOPPED");
    }
}
