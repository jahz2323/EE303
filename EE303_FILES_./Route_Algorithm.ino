//routes 
public :
int counter; 
int target; 
private :
int v; 
int w;
int edges;
int [][] adj; 
bool[] visited; 

void setup() {
  // put your setup code here, to run once:
  
}
void addEdge(int v, int w){
  adj[v][w] = true;
  edges++;
}
void loop() {
    

  // put your main code here, to run repeatedly: 
  switch (){
  
  case : (position="0"){
    
  
    if(target == "2"){
        // rotate orientation forward at junction 
        counter++;
        visited[position] = true;
        addEdge(position,target);
        
    }
    if(target == "1"){
      // rotate orientation turn left at junction 
      counter++;
    }
    if(target == "4"){
      // forward
      counter++; 
    }
    break;
  }
  
  case : (position="1"){
    
  
    if(target == "0"){
        // rotate orientation and turn right  
        counter++;
    }
    if(target == "2"){
      // rotate orientation turn left at junction 
      counter++;
    }
    if(target == "4"){
      // turn left and follow line 
      counter++;
    }
    if(target == "3"){
      // turn right and follow   
      counter++;
    }
    break;
  }
  
  case : (position="2"){
    if(target == "1"){
        // rotate orientation and turn right  
        counter++;
      }
    
    if(target == "0"){
      // rotate orientation turn and follow line 
      counter++;
    }
    if(target == "3"){
      // forward 
      counter++;
    }
    break;
  }
  
  case : (position="3"){
    if(target == "1"){
        // follow line and turn left at junction 
        counter++;
      }
    
    if(target == "2"){
      // rotate orientation turn and forward 
      counter++;
    }
    if(target == "4"){
      // follow line and do not turn at junction 
      counter++;
    }
    break;
  }
  
  case : (position="4"){
    if(target == "0"){
        // rotate orientation and forward 
        counter++;
      }
    
    if(target == "1"){
      // followline and turn at junction 
      counter++;
    }
    if(target == "3"){
      // follow line and do not turn at junction 
      counter++;
    }
    break; 
  }
  
  default:{
    forward 
  }
  
}
