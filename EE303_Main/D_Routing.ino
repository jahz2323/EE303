int previous = 6;
int current = 0;
int junctionCount = 0;
int destination = 111;
int distance = 0;

void setupdecehlo() {
  Serial.begin(9600);
}

void loopdechelo() {
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
  if ( previous == 6) {
    POST_position(0);
    delay(500);
    destination = Read_Response();
  }
}

bool test(int dest) {
  //PREVIOUS = 6 | CURRENT = 0
  if ( previous == 6 && current == 0 && destination == 1) {
    if (junctionCount == 2) {
      left_angle_turn();
    }
    if (junctionCount == 3) {
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
      junctionCount = 0;
      POST_position(4);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 6 && current == 0 && destination == 5) {
    if (junctionCount == 2) {
      left_angle_turn();
    }
    if (junctionCount == 4) {
      while (park() == true) {
      }
      if (park() == false) {
        POST_position(5);
        return true;
      }
    }
  }
  //
  //
  //PREVIOUS = 0 | CURRENT = 1
  if (previous == 0 && current == 1 && destination  == 0) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      right_angle_turn();
    }
    if (junctionCount == 2) {
      previous = 1;
      current = 0;
      junctionCount = 0;
      POST_position(0);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 0 && current == 1 && destination  == 2) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      left_angle_turn();
    }
    if (junctionCount == 2) {
      previous = 1;
      current = 2;
      junctionCount = 0;
      POST_position(2);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 0 && current == 1 && destination  == 3) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      left_angle_turn();
    }
    if (junctionCount == 3) {
      previous = 2;
      current = 3;
      junctionCount = 0;
      POST_position(3);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 0 && current == 1 && destination == 4) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      right_angle_turn();
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
  if ( previous == 0 && current == 1 && destination == 5) {
    if (junctionCount == 1) {
      while (park() == true) {
      }
      if (park() == false) {
        POST_position(5);
        return true;
      }
    }
  }
  ////
  ////
  //PREVIOUS = 0 | CURRENT = 2
  if (previous == 0 && current == 2 && destination == 0) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 2) {
      previous = 2;
      current = 0;
      junctionCount = 0;
      POST_position(0);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 0 && current == 2 && destination == 1) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      right_angle_turn();
    }
    if (junctionCount == 2) {
      previous = 2;
      current = 1;
      junctionCount = 0;
      POST_position(1);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 0 && current == 2 && destination == 3) {
    if (junctionCount == 1) {
      previous = 2;
      current = 3;
      junctionCount = 0;
      POST_position(3);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 0 && current == 2 && destination == 4) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 3) {
      previous = 2;
      current = 4;
      junctionCount = 0;
      POST_position(4);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 0 && current == 2 && destination == 5) {
    if (junctionCount == 1) {
      right_angle_turn();
    }
    if (junctionCount == 3) {
      while (park() == true) {
      }
      if (park() == false) {
        POST_position(5);
        return true;
      }
    }
  }
  ////
  ////
  //PREVIOUS = 0 | CURRENT = 3
  if (previous == 0 && current == 3 && destination == 0) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 3) {
      previous = 3;
      current = 0;
      junctionCount = 0;
      POST_position(0);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 0 && current == 3 && destination == 1) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 2) {
      right_angle_turn();
    }
    if (junctionCount == 3) {
      previous = 3;
      current = 1;
      junctionCount = 0;
      POST_position(1);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 0 && current == 3 && destination == 2) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      previous = 3;
      current = 2;
      junctionCount = 0;
      POST_position(2);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 0 && current == 3 && destination == 4) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 4) {
      previous = 3;
      current = 4;
      junctionCount = 0;
      POST_position(4);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 0 && current == 3 && destination == 5) {
    if (junctionCount == 2) {
      right_angle_turn();
    }
    if (junctionCount == 4) {
      while (park() == true) {
      }
      if (park() == false) {
        POST_position(5);
        return true;
      }
    }
  }
  ////
  ////
  //PREVIOUS = 0 | CURRENT = 4
  if (previous == 0 && current == 4 && destination == 0) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      previous = 4;
      current = 0;
      junctionCount = 0;
      POST_position(0);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 0 && current == 4 && destination == 1) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 2) {
      left_angle_turn();
    }
    if (junctionCount == 3) {
      previous = 4;
      current = 1;
      junctionCount = 0;
      POST_position(1);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 0 && current == 4 && destination == 2) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 3) {
      previous = 4;
      current = 2;
      junctionCount = 0;
      POST_position(2);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 0 && current == 4 && destination == 3) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 4) {
      previous = 4;
      current = 3;
      junctionCount = 0;
      POST_position(3);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 0 && current == 4 && destination == 5) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 2) {
      left_angle_turn();
    }
    if (junctionCount == 4) {
      while (park() == true) {
      }
      if (park() == false) {
        POST_position(5);
        return true;
      }
    }
  }
  ////
  ////
  //PREVIOUS = 1 | CURRENT = 0
  if (previous == 1 && current == 0 && destination == 1) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      left_angle_turn();
    }
    if (junctionCount == 2) {
      previous = 0;
      current = 1;
      junctionCount = 0;
      POST_position(1);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 1 && current == 0 && destination == 2) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 2) {
      previous = 0;
      current = 2;
      junctionCount = 0;
      POST_position(2);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 1 && current == 0 && destination == 3) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 3) {
      previous = 0;
      current = 3;
      junctionCount = 0;
      POST_position(3);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 1 && current == 0 && destination == 4) {
    if (junctionCount == 1) {
      previous = 0;
      current = 4;
      junctionCount = 0;
      POST_position(4);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 1 && current == 0 && destination == 5) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      left_angle_turn();
    }
    if (junctionCount == 3) {
      while (park() == true) {
      }
      if (park() == false) {
        POST_position(5);
        return true;
      }
    }
  }
  ////
  ////
  //PREVIOUS = 1 | CURRENT = 2
  if (previous == 1 && current == 2 && destination == 0) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 2) {
      previous = 2;
      current = 0;
      junctionCount = 0;
      POST_position(0);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 1 && current == 2 && destination == 1) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      right_angle_turn();
    }
    if (junctionCount == 2) {
      previous = 2;
      current = 1;
      junctionCount = 0;
      POST_position(1);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 1 && current == 2 && destination == 3) {
    if (junctionCount == 1) {
      previous = 2;
      current = 3;
      junctionCount = 0;
      POST_position(3);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 1 && current == 2 && destination == 4) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 3) {
      previous = 2;
      current = 4;
      junctionCount = 0;
      POST_position(4);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 1 && current == 2 && destination == 5) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      right_angle_turn();
    }
    if (junctionCount == 3) {
      while (park() == true) {
      }
      if (park() == false) {
        POST_position(5);
        return true;
      }
    }
  }
  ////
  ////
  //PREVIOUS = 1 | CURRENT = 3
  if (previous == 1 && current == 3 && destination == 0) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 3) {
      previous = 3;
      current = 0;
      junctionCount = 0;
      POST_position(0);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 1 && current == 3 && destination == 1) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 2) {
      right_angle_turn();
    }
    if (junctionCount == 3) {
      previous = 3;
      current = 1;
      junctionCount = 0;
      POST_position(1);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 1 && current == 3 && destination == 2) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      previous = 3;
      current = 2;
      junctionCount = 0;
      POST_position(2);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 1 && current == 3 && destination == 4) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 4) {
      previous = 3;
      current = 4;
      junctionCount = 0;
      POST_position(4);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 1 && current == 3 && destination == 5) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 2) {
      right_angle_turn();
    }
    if (junctionCount == 4) {
      while (park() == true) {
      }
      if (park() == false) {
        POST_position(5);
        return true;
      }
    }
  }
  ////
  ////
  //PREVIOUS = 1 | CURRENT = 4
  if (previous == 1 && current == 4 && destination == 0) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      previous = 4;
      current = 0;
      junctionCount = 0;
      POST_position(0);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 1 && current == 4 && destination == 1) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 2) {
      left_angle_turn();
    }
    if (junctionCount == 3) {
      previous = 4;
      current = 1;
      junctionCount = 0;
      POST_position(1);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 1 && current == 4 && destination == 2) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 3) {
      previous = 4;
      current = 2;
      junctionCount = 0;
      POST_position(2);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 1 && current == 4 && destination == 3) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 4) {
      previous = 4;
      current = 3;
      junctionCount = 0;
      POST_position(3);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 1 && current == 4 && destination == 5) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 2) {
      left_angle_turn();
    }
    if (junctionCount == 4) {
      while (park() == true) {
      }
      if (park() == false) {
        POST_position(5);
        return true;
      }
    }
  }
  ////
  ////
  //PREVIOUS = 2 | CURRENT = 0
  if (previous == 2 && current == 0 && destination == 1) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      left_angle_turn();
    }
    if (junctionCount == 2) {
      previous = 0;
      current = 1;
      junctionCount = 0;
      POST_position(1);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 2 && current == 0 && destination == 2) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 2) {
      previous = 0;
      current = 2;
      junctionCount = 0;
      POST_position(2);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 2 && current == 0 && destination == 3) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 3) {
      previous = 0;
      current = 3;
      junctionCount = 0;
      POST_position(3);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 2 && current == 0 && destination == 4) {
    if (junctionCount == 1) {
      previous = 0;
      current = 4;
      junctionCount = 0;
      POST_position(4);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 2 && current == 0 && destination == 5) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      left_angle_turn();
    }
    if (junctionCount == 3) {
      while (park() == true) {
      }
      if (park() == false) {
        POST_position(5);
        return true;
      }
    }
  }
  ////
  ////
  //PREVIOUS = 2 | CURRENT = 1
  if (previous == 2 && current == 1 && destination == 0) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      right_angle_turn();
    }
    if (junctionCount == 2) {
      previous = 1;
      current = 0;
      junctionCount = 0;
      POST_position(0);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 2 && current == 1 && destination == 2) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      left_angle_turn();
    }
    if (junctionCount == 2) {
      previous = 1;
      current = 2;
      junctionCount = 0;
      POST_position(2);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 2 && current == 1 && destination == 3) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      left_angle_turn();
    }
    if (junctionCount == 3) {
      previous = 1;
      current = 3;
      junctionCount = 0;
      POST_position(3);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 2 && current == 1 && destination == 4) {
    if (junctionCount == 1) {
      right_angle_turn();
    }
    if (junctionCount == 3) {
      previous = 1;
      current = 4;
      junctionCount = 0;
      POST_position(4);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 2 && current == 1 && destination == 5) {
    if (junctionCount == 1) {
      while (park() == true) {
      }
      if (park() == false) {
        POST_position(5);
        return true;
      }
    }
  }
  ////
  ////
  //PREVIOUS = 2 | CURRENT = 3
  if (previous == 2 && current == 3 && destination == 0) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 3) {
      previous = 3;
      current = 0;
      junctionCount = 0;
      POST_position(0);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 2 && current == 3 && destination == 1) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 2) {
      right_angle_turn();
    }
    if (junctionCount == 3) {
      previous = 3;
      current = 1;
      junctionCount = 0;
      POST_position(1);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 2 && current == 3 && destination == 2) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      previous = 3;
      current = 2;
      junctionCount = 0;
      POST_position(2);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 2 && current == 3 && destination == 4) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 4) {
      previous = 3;
      current = 4;
      junctionCount = 0;
      POST_position(4);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 2 && current == 3 && destination == 5) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 2) {
      right_angle_turn();
    }
    if (junctionCount == 4) {
      while (park() == true) {
      }
      if (park() == false) {
        POST_position(5);
        return true;
      }
    }
  }
  ////
  ////
  //PREVIOUS = 2 | CURRENT = 4
  if (previous == 2 && current == 4 && destination == 0) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      previous = 4;
      current = 0;
      junctionCount = 0;
      POST_position(0);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 2 && current == 4 && destination == 1) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 2) {
      left_angle_turn();
    }
    if (junctionCount == 3) {
      previous = 4;
      current = 1;
      junctionCount = 0;
      POST_position(1);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 2 && current == 4 && destination == 2) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 3) {
      previous = 4;
      current = 2;
      junctionCount = 0;
      POST_position(2);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 2 && current == 4 && destination == 3) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 4) {
      previous = 4;
      current = 3;
      junctionCount = 0;
      POST_position(3);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 2 && current == 4 && destination == 5) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 2) {
      left_angle_turn();
    }
    if (junctionCount == 4) {
      while (park() == true) {
      }
      if (park() == false) {
        POST_position(5);
        return true;
      }
    }
  }
  ////
  ////
  //PREVIOUS = 3 | CURRENT = 0
  if (previous == 3 && current == 0 && destination == 1) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      left_angle_turn();
    }
    if (junctionCount == 2) {
      previous = 0;
      current = 1;
      junctionCount = 0;
      POST_position(1);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 3 && current == 0 && destination == 2) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 2) {
      previous = 0;
      current = 1;
      junctionCount = 0;
      POST_position(1);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 3 && current == 0 && destination == 3) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 3) {
      previous = 0;
      current = 3;
      junctionCount = 0;
      POST_position(3);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 3 && current == 0 && destination == 4) {
    if (junctionCount == 1) {
      previous = 0;
      current = 4;
      junctionCount = 0;
      POST_position(4);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 3 && current == 0 && destination == 5) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      left_angle_turn();
    }
    if (junctionCount == 3) {
      while (park() == true) {
      }
      if (park() == false) {
        POST_position(5);
        return true;
      }
    }
  }
  ////
  ////
  //PREVIOUS = 3 | CURRENT = 1
  if (previous == 3 && current == 1 && destination == 0) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      right_angle_turn();
    }
    if (junctionCount == 2) {
      previous = 1;
      current = 0;
      junctionCount = 0;
      POST_position(0);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 3 && current == 1 && destination == 2) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      left_angle_turn();
    }
    if (junctionCount == 2) {
      previous = 1;
      current = 2;
      junctionCount = 0;
      POST_position(2);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 3 && current == 1 && destination == 3) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      left_angle_turn();
    }
    if (junctionCount == 3) {
      previous = 1;
      current = 3;
      junctionCount = 0;
      POST_position(3);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 3 && current == 1 && destination == 4) {
    if (junctionCount == 1) {
      right_angle_turn();
    }
    if (junctionCount == 3) {
      previous = 1;
      current = 4;
      junctionCount = 0;
      POST_position(4);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 3 && current == 1 && destination == 5) {
    if (junctionCount == 1) {
      while (park() == true) {
      }
      if (park() == false) {
        POST_position(5);
        return true;
      }
    }
  }
  ////
  ////
  //PREVIOUS = 3 | CURRENT = 2
  if (previous == 3 && current == 2 && destination == 0) {
    if (junctionCount == 2) {
      previous = 2;
      current = 0;
      junctionCount = 0;
      POST_position(0);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 3 && current == 2 && destination == 1) {
    if (junctionCount == 1) {
      right_angle_turn();
    }
    if (junctionCount == 2) {
      previous = 2;
      current = 1;
      junctionCount = 0;
      POST_position(1);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 3 && current == 2 && destination == 3) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      previous = 2;
      current = 3;
      junctionCount = 0;
      POST_position(3);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 3 && current == 2 && destination == 4) {
    if (junctionCount == 3) {
      previous = 2;
      current = 4;
      junctionCount = 0;
      POST_position(4);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 3 && current == 2 && destination == 5) {
    if (junctionCount == 1) {
      right_angle_turn();
    }
    if (junctionCount == 3) {
      while (park() == true) {
      }
      if (park() == false) {
        POST_position(5);
        return true;
      }
    }
  }
  ////
  ////
  //PREVIOUS = 3 | CURRENT = 4
  if (previous == 3 && current == 4 && destination == 0) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      previous = 4;
      current = 0;
      junctionCount = 0;
      POST_position(0);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 3 && current == 4 && destination == 1) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 2) {
      left_angle_turn();
    }
    if (junctionCount == 3) {
      previous = 4;
      current = 1;
      junctionCount = 0;
      POST_position(1);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 3 && current == 4 && destination == 2) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 3) {
      previous = 4;
      current = 2;
      junctionCount = 0;
      POST_position(2);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 3 && current == 4 && destination == 3) {
    if (junctionCount == 4) {
      previous = 4;
      current = 3;
      junctionCount = 0;
      POST_position(3);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 3 && current == 4 && destination == 5) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 2) {
      left_angle_turn();
    }
    if (junctionCount == 4) {
      while (park() == true) {
      }
      if (park() == false) {
        POST_position(5);
        return true;
      }
    }
  }
  ////
  ////
  //PREVIOUS = 4 | CURRENT = 0
  if (previous == 4 && current == 0 && destination == 1) {
    if (junctionCount == 1) {
      left_angle_turn();
    }
    if (junctionCount == 2) {
      previous = 0;
      current = 1;
      junctionCount = 0;
      POST_position(1);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 4 && current == 0 && destination == 2) {
    if (junctionCount == 2) {
      previous = 0;
      current = 2;
      junctionCount = 0;
      POST_position(2);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 4 && current == 0 && destination == 3) {
    if (junctionCount == 3) {
      previous = 0;
      current = 3;
      junctionCount = 0;
      POST_position(3);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 4 && current == 0 && destination == 4) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      previous = 0;
      current = 4;
      junctionCount = 0;
      POST_position(4);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 4 && current == 0 && destination == 5) {
    if (junctionCount == 1) {
      left_angle_turn();
    }
    if (junctionCount == 3) {
      while (park() == true) {
      }
      if (park() == false) {
        POST_position(5);
        return true;
      }
    }
  }
  ////
  ////
  //PREVIOUS = 4 | CURRENT = 1
  if (previous == 4 && current == 1 && destination == 0) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      right_angle_turn();
    }
    if (junctionCount == 2) {
      previous = 1;
      current = 0;
      junctionCount = 0;
      POST_position(0);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 4 && current == 1 && destination == 2) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      left_angle_turn();
    }
    if (junctionCount == 2) {
      previous = 1;
      current = 2;
      junctionCount = 0;
      POST_position(2);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 4 && current == 1 && destination == 3) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      left_angle_turn();
    }
    if (junctionCount == 3) {
      previous = 1;
      current = 3;
      junctionCount = 0;
      POST_position(3);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 4 && current == 1 && destination == 4) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      right_angle_turn();
    }
    if (junctionCount == 3) {
      previous = 1;
      current = 4;
      junctionCount = 0;
      POST_position(4);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 4 && current == 1 && destination == 5) {
    if (junctionCount == 1) {
      while (park() == true) {
      }
      if (park() == false) {
        POST_position(5);
        return true;
      }
    }
  }
  ////
  ////
  //PREVIOUS = 4 | CURRENT = 2
  if (previous == 4 && current == 2 && destination == 0) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 2) {
      previous = 2;
      current = 0;
      junctionCount = 0;
      POST_position(0);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 4 && current == 2 && destination == 1) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      right_angle_turn();
    }
    if (junctionCount == 2) {
      previous = 2;
      current = 1;
      junctionCount = 0;
      POST_position(1);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 4 && current == 2 && destination == 3) {
    if (junctionCount == 1) {
      previous = 2;
      current = 3;
      junctionCount = 0;
      POST_position(3);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 4 && current == 2 && destination == 4) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 3) {
      previous = 2;
      current = 4;
      junctionCount = 0;
      POST_position(4);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 4 && current == 2 && destination == 5) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      right_angle_turn();
    }
    if (junctionCount == 3) {
      while (park() == true) {
      }
      if (park() == false) {
        POST_position(5);
        return true;
      }
    }
  }
  ////
  ////
  //PREVIOUS = 4 | CURRENT = 3
  if (previous == 4 && current == 3 && destination == 0) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 3) {
      previous = 3;
      current = 0;
      junctionCount = 0;
      POST_position(0);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 4 && current == 3 && destination == 1) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 2) {
      right_angle_turn();
    }
    if (junctionCount == 3) {
      previous = 3;
      current = 1;
      junctionCount = 0;
      POST_position(1);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if (previous == 4 && current == 3 && destination == 2) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 1) {
      previous = 3;
      current = 2;
      junctionCount = 0;
      POST_position(2);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 4 && current == 3 && destination == 4) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 4) {
      previous = 3;
      current = 4;
      junctionCount = 0;
      POST_position(4);
      delay(500);
      destination = Read_Response();
      return true;
    }
  }
  if ( previous == 4 && current == 3 && destination == 5) {
    if ( junctionCount == 0 ) {
      spin_turn();
    }
    if (junctionCount == 2) {
      right_angle_turn();
    }
    if (junctionCount == 4) {
      while (park() == true) {
      }
      if (park() == false) {
        POST_position(5);
        return true;
      }
    }
  }
  return false;
}
