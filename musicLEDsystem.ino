/* LED Music System
 *  Author: Yash Jain
 *  Summer 2016
 */
int LED = 3;
int sensor = A0;
int val = 0;
int sw = 4;
int X_axis = 1;
int Y_axis = 2;
int frequency = 0;
int mode=0;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(sw, INPUT);
  digitalWrite(sw, HIGH);
  pinMode(X_axis, INPUT);
  pinMode(Y_axis, INPUT);
}


void loop() {

    //***********Mode 0 ********
  if(mode==0){
  //reading values from sonar sensor. typical range 0-150
  val = (analogRead(sensor));
  //map out values
  val = map(val, 0, 120, 0, 255);

  if (val > (20 + frequency)) {
    analogWrite(LED, val);
  }

  else if (val < (20 + frequency)) {
    digitalWrite(LED, LOW);
   }
  }
  //******** Mode 0 ***********



  //******** Mode 1 ***********
    if(mode==1){
      fullOn();
    }  
  //*********Mode 1 ***********



  
  //******* Control Unit ***********
  if (analogRead(Y_axis) < 300) {
    if (frequency > -20 && mode == 0) {
      frequency--;
      delay(150);
    }
    if (frequency > -255 && mode == 1) {
      frequency--;
      delay(10);
    }
  }

  if (analogRead(Y_axis) > 600) {
    if (frequency < 100 && mode == 0) {
      frequency++;
      delay(150);
    }
    if (frequency < 0 && mode == 1) {
      frequency++;
      delay(10);
    }
  }

  if (digitalRead(sw) == 0) {
    frequency = 0;
  }

  if(analogRead(X_axis)<300){
    mode++;
    if(mode==2){
      mode=0;
    }
    delay(500);
   }

   if(analogRead(X_axis)>600){
    mode--;
    if(mode <0){
      mode=1;
    }
    delay(500);
   }
  //********** Control Unit ***********
}



void fullOn() {
    analogWrite(LED, 255+frequency);
    if(255+frequency >255){
      frequency=0;
    }
  }




















