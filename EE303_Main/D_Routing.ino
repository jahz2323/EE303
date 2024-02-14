int previous = 6;
int current = 0;
int junctionCount = 0;
int destination = 111;
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
  Serial.print("  NUM OF JUNCTIONS");
  Serial.println(junctionCount);
  if (junctionCount == 1) {
    post();
  }
  else{
    test(destination);
  }
}

void post() {
  if ( previous = 6) {
    POST_position(0);
    delay(500);
    int destination = Read_Response();
    Serial.print("     Destination is...");
    Serial.print(destination);
  }
}
bool test(int dest){
  if(junctionCount == 2){
    Serial.println(" left");
    left_angle_turn();
    //left turn 
  }
  if(junctionCount == 3){
    Serial.println("FINISHED");
    POST_position(1);
    return true;
  }
  return false;
}

//
//void routing(int destination) {
//
//  switch (destination) {
//    case 0:
//      if (current == 1) {
//        if (previous == 1 || 2 || 3) {
//          //rotate 180()
//          //move()
//          //juction B turn right
//          //junction 0
//          //junction()
//        }
//      }
//      if (current == 2) {
//        if (previous == 0 || 1 || 4) {
//          //rotate 180()
//          //move()
//          //juction B
//          //junction 0
//          //junction()
//        }
//        else  {
//          //move()
//          //juction B
//          //junction 0
//          //junction()
//        }
//      }
//      if (current == 3) {
//        if (previous == 0 || 1 || 2 || 4) {
//          //rotate 180()
//          //move()
//          //junction 2
//          //juction B
//          //junction 0
//          //junction()
//        }
//      }
//      if (current == 4) {
//        if (previous == 0 || 1 || 2 || 3) {
//          //rotate 180()
//          //move()
//          //junction 0
//          //junction()
//        }
//      }
//      //dest = 1
//    case 1:
//    Serial.println("  CASE 1");
//    // current position 0
//      if (current == 0) {
//        if (previous == 1 || 2 || 3) {
//          //rotate 180()
//          //move()
//          //juction B turn left
//          //junction 1
//          //junction()
//        }
//        // at junctions
//        else {
//           Serial.println(" JUNCTIONS");
//          //move()
//          //juction B turn left
//          if(junctionCount = 2 ){
//             Serial.println(" left");
//              // left_angle_turn();
//          }
//          //junction 1
//          //junction()
//         if(junctionCount = 3){
//          Serial.println("Finished");
//         }
//        }
//      }
//      if (current == 2) {
//        if (previous == 0 || 1 || 4) {
//          //rotate 180()
//          //move()
//          //juction B turn right
//          //junction 1
//          //junction()
//        }
//        else  {
//          //move()
//          //juction B turn right
//          //junction 1
//          //junction()
//        }
//      }
//      if (current == 3) {
//        if (previous == 0 || 1 || 2 || 4) {
//          //rotate 180()
//          //move()
//          //junction 2
//          //juction B turn left
//          //junction 1
//          //junction()
//        }
//      }
//      if (current == 4) {
//        if (previous == 0 || 1 || 2 || 3) {
//          //rotate 180()
//          //move()
//          //junction 0
//          //juction B turn right
//          //junction 1
//          //junction()
//        }
//      }
//      }
//  }
