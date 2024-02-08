int switchL = 2;
int switchR = 4;
int motorR = 9;
int motorL = 10;
int PR = A1;
int PL = A0;
int valueL;
int valueR;
int speedR;
int speedL;
char reading;

void setup() {
  pinMode(motorR, OUTPUT);
  pinMode(motorL, OUTPUT);
  pinMode(switchL, INPUT);
  pinMode(switchR, INPUT);
  Serial.begin(9600);
}
void loop() {
  valueR = digitalRead(switchR);
  valueL = digitalRead(switchL);
  speedR = analogRead(PR);
  speedL = analogRead(PL);

  // Reading the received data (characters)
  if (Serial.available()) {
     reading = Serial.read();
  }
    // Right motor speed control; by the characters received ('R', 'S') in the case of switch ON:
  switch (valueR) {
     case HIGH :
       switch (reading) {
         case 'R' :
         analogWrite(motorR, map(speedR, 0, 1023, 255, 0));
         break;
         case 'S' :
         analogWrite(motorR, 0);  
         break;
         default :
         analogWrite(motorR, 0);
         break;
        }
  // Right motor speed control; by the characters received ('R', 'S') in the case of switch OFF:
     case LOW :
       switch (reading) {
         case 'R' :
         analogWrite(motorR, map(speedR, 0, 1023, 255, 0));
         break;
         case 'S' :
         analogWrite(motorR, 0);
         break;
         default :
         analogWrite(motorR, 0);
         break;
        }
  }    
  // Left motor speed control; by the characters received ('L', 'S') in the case of switch ON:
  switch (valueL) {
     case HIGH :
       switch (reading) {
         case 'L' :
         analogWrite(motorL, map(speedL, 0, 1023, 255, 0));
         break;
         case 'S' :
         analogWrite(motorL, 0); 
         break;
         default :
         analogWrite(motorL, 0);
         break;
        }
  // Left motor speed control; by the characters received ('L', 'S') in the case of switch OFF:
     case LOW :
       switch (reading) {
         case 'L' :
         analogWrite(motorL, map(speedL, 0, 1023, 255, 0));
         case 'S' :
         break;
         analogWrite(motorL, 0);
         break;
         default :
         analogWrite(motorL, 0);
         break;
        }
    }
 }