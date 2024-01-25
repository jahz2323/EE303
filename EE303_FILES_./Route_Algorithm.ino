//routes
class Routing_Algorithm{ 
public :

volatile int active = 0; 
volatile int orientation = 0; 
int counter; 
 

private :
int v; 
int w;
int edges;
boolean adj[][]; 
boolean visited[]; 
};
void addEdge(int v, int w){
  adj[v][w] = true;
  edges++;
}

void setup() {
  // put your setup code here, to run once:
  // create graph
}
// position will update when reach new station 

void loop() {
    v = position;

  // put your main code here, to run repeatedly: 
  switch (position){
  visited[v] = true; 
  case : 0{
    if(!visited[target]){
    if(target == "2"){
        // rotate orientation forward at junction 
        counter++;
        addEdge(target,position);
        rotate();
        // forward();
        oritentation = 1; 
        active  = 1; 
      }
    if(target == "1"){
      // rotate orientation turn left at junction 
      counter++;
      addEdge(target,position);
      orientation = 1;
      active  = 1;
      }
    if(target == "4"){
      // forward
      counter++; 
      addEdge(target,position);
      active = 1 ; 
      }
    }
    position = target; 
    break;
  }
  
 
  default:{
   // forward 
  }
  
}
