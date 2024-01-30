
int v;
int w;
int edges;
int adj[5][5];
bool visited[5];


void addEdge(int v, int w) {
  //adj[v][w] = true;
  edges++;
}

void setup() {
  delay(2000);
  // put your setup code here, to run once
}

void loop() {


  // put your main code here, to run repeatedly:
  switch (destination) {

    case 0: {
        Serial.println("CASE 0");
        //Serial.println(destination);

        if (destination == 1) {
          Serial.println("GOTO 1");

          digitalWrite(motor1Phase, LOW); //forward
          digitalWrite(motor2Phase, HIGH); //forward
          analogWrite(motor1PWM, 150); // set speed of motor
          analogWrite(motor2PWM, 150); // set speed of motor
          delay(100);
          active = 1;
          if (station = 1)
          {
            digitalWrite(motor1Phase, HIGH); //forward
            digitalWrite(motor2Phase, HIGH); //forward
            analogWrite(motor1PWM, 90); // set speed of motor
            analogWrite(motor2PWM, 0); // set speed of motor
            delay(500);

          }

          //Serial.println(station);
          if (_move = 2) {
            Serial.println("UPDATED POSITION");
            
          }
        }

        else if (destination == 4) {
          // forward
          active = 1;
          if (station = 1)
          {
            analogWrite(motor1PWM, 0); // set speed of motor
            analogWrite(motor2PWM, 0); // set speed of motor
            //            postBody = "position=";
            //            postBody += 4;
            //            client.println(postBody);
            delay(6000);
            _position = 4;
          }

        }
      }
      break;
    case 1: {
        Serial.println("_SEND= 1");
        active = 1;
        break;
      }
    case 4: {
        Serial.println("_SEND= 4");
        active = 1;
        break;
      }
    default: {
        active = 0;
      }
  }
}




//    if(target == "0"){
//        // rotate orientation and turn right
//        counter++;
//    }
//    if(target == "2"){
//      // rotate orientation turn left at junction
//      counter++;
//    }
//    if(target == "4"){
//      // turn left and follow line
//      counter++;
//    }
//    if(target == "3"){
//      // turn right and follow
//      counter++;
//    }
//    break;
//  }
//
//  case : "2"{
//    if(target == "1"){
//        // rotate orientation and turn right
//        counter++;
//      }
//
//    if(target == "0"){
//      // rotate orientation turn and follow line
//      counter++;
//    }
//    if(target == "3"){
//      // forward
//      counter++;
//    }
//    break;
//  }
//
//  case : "3"{
//    if(target == "1"){
//        // follow line and turn left at junction
//        counter++;
//      }
//
//    if(target == "2"){
//      // rotate orientation turn and forward
//      counter++;
//    }
//    if(target == "4"){
//      // follow line and do not turn at junction
//      counter++;
//    }
//    break;
//  }
//
//  case :"4"{
//    if(target == "0"){
//        // rotate orientation and forward
//        counter++;
//      }
//
//    if(target == "1"){
//      // followline and turn at junction
//      counter++;
//    }
//    if(target == "3"){
//      // follow line and do not turn at junction
//      counter++;
//    }
//    break;
//  }
//
//  default:{
//    forward
//  }
//
//}
