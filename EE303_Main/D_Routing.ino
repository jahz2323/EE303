int previous = 6;
int current = 0;
int junctionCount = 0;
int destination = 0;


void setupdecehlo() {
  // put your setup code here, to run once
  Serial.begin(9600);

  //    String response = readResponse();
  //    String route = getRoute(response);
  //    Serial.println("Route is.." + route);

}

void loopdechelo() {

}

void junction() {
  junctionCount++;
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
  if (junctionCount == 1) {
    post();
  }
  else {
    test(destination);
  }
}

void post() {
  if ( previous = 6) {
    POST_position(0);
    delay(500);
    destination = Read_Response();
    Serial.print("     Destination is...");
    Serial.print(destination);

  }
}

  //spin_turn(){
  //left_angle_turn() {
  //right_angle_turn() {
  //move_to_five() {
  bool test(int dest) {
    //FROM 0
    if ( (previous == 6) && (current == 0) && (dest == 1)) {
      if (junctionCount = 2) {
        Serial.println(" left");
        left_angle_turn();
        //left turn
      }
      if (junctionCount = 3) {
        Serial.println("FINISHED");
        POST_position(1);
        current == 1;
        junctionCount == 0;
        return true;
      }
    }
    else if ( (previous == 6) && (current == 0) && (dest == 4) ) {
      if (junctionCount == 1) {
        spin_turn();
      }
      if (junctionCount == 2) {
        POST_position(4);
        current == 4;
        junctionCount == 0;
        return true;
      }
    }
    else if ( (previous == 6) && (current == 0) && (dest == 2)) {
      if (junctionCount == 3) {
        POST_position(2);
        current == 2;
        junctionCount == 0;
        return true;
      }
    }
    else if ( (previous == 6) && (current == 0) && (dest == 3)) {
      if (junctionCount == 4) {
        POST_position(3);
        current == 3;
        junctionCount == 0;
        return true;
      }
    }
    //
    //
    //
    return false;
  }
