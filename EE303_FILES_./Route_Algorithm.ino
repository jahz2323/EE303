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

void addEdge(int v, int w){
  adj[v][w] = true;
  edges++;
}

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
    

  // put your main code here, to run repeatedly: 
  switch (position){
  
  case : "0"){
    visited[v] = true; 
    if(!visited[w]){
    if(target == "2"){
        // rotate orientation forward at junction 
        counter++;
        addEdge(target,position);
      }
    if(target == "1"){
      // rotate orientation turn left at junction 
      counter++;
      }
    if(target == "4"){
      // forward
      counter++; 
      }
    }
    break;
  }
  
  case :"1"{
    
  
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
  
  case : "2"{
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
  
  case : "3"{
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
  
  case :"4"{
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
