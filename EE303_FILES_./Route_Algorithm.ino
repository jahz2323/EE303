//routes 

int counter; 
int target; 

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly: 
  switch (){
  
  case : (position="0"){
    if(target == "2"){
        // rotate orientation forward at junction 
    }
    if(target == "1"){
      // rotate orientation turn left at junction 
    }
    if(target == "4"){
      // forward 
    }
    break;
  }
  case : (position="1"){
    if(target == "0"){
        // rotate orientation and turn right  
    }
    if(target == "2"){
      // rotate orientation turn left at junction 
    }
    if(target == "4"){
      // turn left and follow line 
    }
    if(target == "3"){
      // turn right and follow   
    }
    break;
  }
  case : (position="2"){
    if(target == "1"){
        // rotate orientation and turn right  
      }
    
    if(target == "0"){
      // rotate orientation turn and follow line 
    }
    if(target == "3"){
      // forward 
    }
    break;
  }
  case : (position="3"){
    if(target == "1"){
        // follow line and turn left at junction 
      }
    
    if(target == "2"){
      // rotate orientation turn and forward 
    }
    if(target == "4"){
      // follow line and do not turn at junction 
    }
    break;
  }
  case : (position="4"){
    if(target == "0"){
        // rotate orientation and forward 
      }
    
    if(target == "1"){
      // followline and turn at junction 
    }
    if(target == "3"){
      // follow line and do not turn at junction 
    }
    break; 
  }
  default:{
    forward 
  }
  
}
