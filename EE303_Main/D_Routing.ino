int previous = 6;
int current = 0;
int junctionCount = 0;
int destination = 111;


int distance = 0;

void setupdecehlo() {
  // put your setup code here, to run once
  Serial.begin(9600);

  //    String response = readResponse();
  //    String route = getRoute(response);
  //    Serial.println("Route is.." + route);

}

void loopdechelo() {
  distance = analogRead(A5);
  //  Serial.println("   ");
  //  Serial.print(distance);
  test(destination);
}

void junction() {
  junctionCount++;
  if (junctionCount == 1 && previous == 6)  {
    post();
  }
  else {
    test(destination);
  }
  Serial.print("  NUM OF JUNCTIONS     ");
  Serial.println(junctionCount);
  Serial.println(" ");
  Serial.print("  Previous Position is.... ");
  Serial.print(previous);
  Serial.print("   Current Position is...  ");
  Serial.print(current);
  Serial.println(" ");
  Serial.print("  Destination Position is...  ");
  Serial.print(destination);
  Serial.println(" ");
}

void post() {
  if ( previous = 6) {
    POST_position(0);
    delay(500);
    destination = Read_Response();
  }
}

bool test(int dest) {
  //PREVIOUS = NULL - CURRENT 0
  if ( previous == 6 && current == 0 && destination == 1) {
    if (junctionCount == 2) {
      Serial.println(" left");
      left_angle_turn();
      //left turn
    }
    if (junctionCount == 3) {
      //Serial.println("FINISHED");
      previous = 0;
      current = 1;
      junctionCount = 0;
      POST_position(1);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 6 && current == 0 && destination == 2) {
    if (junctionCount == 3) {
      previous = 0;
      current = 2;
      junctionCount = 0;
      POST_position(2);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 6 && current == 0 && destination == 3) {
    if (junctionCount == 4) {
      previous = 2;
      current = 3;
      junctionCount = 0;
      POST_position(3);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 6 && current == 0 && destination == 4) {
    if (junctionCount == 1) {
      spin_turn();
    }
    if (junctionCount == 2) {
      previous = 0;
      current = 4;
      POST_position(4);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  //
  //
  //PREVIOUS = 0 - CURRENT 1
  if (previous == 0 && current == 1 && destination  == 2) {
    spin_turn();
    if (junctionCount == 1) {
      Serial.println(" left");
      left_angle_turn();
    }
    if (junctionCount == 2) {
      previous = 1;
      current = 2;
      POST_position(2);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 0 && current == 1 && destination  == 0) {
    spin_turn();
    if (junctionCount == 1) {
      Serial.println(" right");
      right_angle_turn();
    }
    if (junctionCount == 2) {
      previous = 1;
      current = 0;
      POST_position(0);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 0 && current == 1 && destination  == 3) {
    spin_turn();
    if (junctionCount == 1) {
      Serial.println(" left");
      left_angle_turn();
    }
    if (junctionCount == 3) {
      previous = 2;
      current = 3;
      POST_position(3);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 0 && current == 1 && destination == 4) {
    spin_turn();
    if (junctionCount == 1) {
      Serial.println(" left");
      left_angle_turn();
    }
    if (junctionCount == 2) {
      previous = 1;
      current = 4;
      junctionCount = 0;
      POST_position(4);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  ////
  ////
  //PREVIOUS = 0 - CURRENT 2
  if (previous == 0 && current == 2 && destination == 0) {
    spin_turn();
    if (junctionCount == 2) {
      previous = 2;
      current = 0;
      POST_position(0);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 0 && current == 2 && destination == 1) {
    spin_turn();
    if (junctionCount == 1) {
      left_angle_turn();
    }
    if (junctionCount == 2) {
      previous = 2;
      current = 1;
      POST_position(1);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 0 && current == 2 && destination == 3) {
    if(junctionCount == 1){
      previous = 2;
      current = 3;
      POST_position(3);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 0 && current == 2 && destination == 4){
  spin_turn();
  if(junctionCount == 3){
  previous = 2;
  current = 4;
  POST_position(4);
  delay(500);
  destination = Read_Response();
  return true;
 }
}


  else if ( previous == 0 && current == 1 && destination == 5) {

    if (distance > 900) {
      POST_position(5);
    }
    return true;
  }
  return false;
}
