// High Voltage Switching Code for 2 optoRelays

// Input sparking parameters

int Left = 9; // arduino input that leads to transistor
int Right = 8; // arduino input that leads to transistor
int command = 5;

int countmax = 5;         // set number of repetitions

double freq = 5;              // set sparking frequency
double DelayTot = 1000/freq;   // 1000ms / frequency
double DC = 10;                // Duty Cycle in %
double DelaySpark = DelayTot*(DC/100);   // Delay for spark
double DelayNoSpark = DelayTot-DelaySpark ; // Delay for no spark


void setup() {
   
// Set up pins that will control switching
  Serial.begin(9600);
  pinMode(Left, OUTPUT);
  pinMode(Right, OUTPUT);
  digitalWrite(Left, HIGH);
  digitalWrite(Right, HIGH);
}

void loop() {

if (Serial.available() > 0) {
  int command = Serial.read();
  Serial.println(command);
  switch (command){       // For all chambers actuating

    case 'a':    // 2 sparks
     for (int count = 1; count <= countmax; count++){
     digitalWrite(Right,LOW); 
     digitalWrite(Left,LOW);   
     delay(DelaySpark); 
     digitalWrite(Left,HIGH);
     digitalWrite(Right,HIGH);  
     delay(DelayNoSpark);}
     //Serial.print("count = ");
     //Serial.println(count);}
     break;
     
    case 'b':    // one spark gap
    int count;
     for (count = 1; count <= countmax; count++){
     digitalWrite(Right,HIGH); 
     digitalWrite(Left,LOW);   
     delay(DelaySpark); 
     digitalWrite(Left,HIGH); 
     delay(DelayNoSpark);}
     //Serial.print("count = ");
     //Serial.println(count);}
     break;
     
    case 'c':      // other spark gap
     for (int count = 1; count <= countmax; count++){
      digitalWrite(Left,HIGH);
      digitalWrite(Right,LOW); 
     delay(DelaySpark); 
     digitalWrite(Right,HIGH);  
     delay(DelayNoSpark);}
     //Serial.print("count = ");
    // Serial.println(count);}
     break;
     
     case 'd':  // 20Hz
     for (int count = 1; count <= 50; count++){
     digitalWrite(Right,LOW); 
     digitalWrite(Left,LOW);   
     delay(7.5); 
     digitalWrite(Left,HIGH);
     digitalWrite(Right,HIGH);  
     delay(42.5);
     Serial.print("count = ");
     Serial.println(count);}
     break;
     
    default:
     digitalWrite(Left,HIGH);
     digitalWrite(Right,HIGH); 
  }
}
}
