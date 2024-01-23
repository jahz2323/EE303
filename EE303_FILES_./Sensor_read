int AnalogValue[5] = {0,0,0,0,0};
int AnalogPin[5] = {A0,A1,A6,A9,A11}; //Analog pins P4.7, P4.4, P4.2, P4.0, P6.1
 // J3 -> 28, 26, 25, 24, 23
 // keep A8 free for tone O/P music
 int value;
void setup()
{
 // put your setup code here, to run once:
 Serial.begin(9600);
}
void loop()
 {
 // put your main code here, to run repeatedly:
 int i=value;
 for (i=0;i<5;i++)
 {
 AnalogValue[i]=analogRead(AnalogPin[i]);

 Serial.print(AnalogValue[i]); // This prints the actual analog reading from the sensors
 Serial.print("\t"); //tab over on screen
 if(i==4)
 {
 Serial.println(""); //carriage return
 delay(50); // display new set of readings every 600mS
 }
 }
 }
