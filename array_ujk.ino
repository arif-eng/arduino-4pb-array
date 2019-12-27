int led [ ] = {2,3,4,5};
int num_led = 4;
int pbKanan = 6;
int pbKiri = 7;
int pbOff = 8;
int pbPause = 9;
int i;

  void untukOff() {
    digitalWrite(led [i], LOW);
  } 

void setup() {
  // put your setup code here, to run once:
  for(i=0; i<5; i++) 
  pinMode(led [i], OUTPUT);
  pinMode(pbKanan, INPUT);
  pinMode(pbKiri, INPUT);
  pinMode(pbPause, INPUT);
  pinMode(pbOff, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  keluar:
  if(digitalRead(pbKanan) == HIGH) {
    while(1) {
      for(i=0; i<5; i++) {
        digitalWrite(led [i], HIGH);
        jump:
        //for(int a=0; a<100; a++){delay(3);
        delay(300);
        digitalWrite(led [i], LOW);
        
        if(digitalRead(pbOff) == HIGH) {untukOff(); goto keluar;}
        if(digitalRead(pbKiri) == HIGH) { goto jump1;}
        if(digitalRead(pbPause) == HIGH) {
          digitalWrite(led [i], HIGH);
          while(1) {
            if(digitalRead(pbKiri) == HIGH) { goto jump1;}
            if(digitalRead(pbKanan) == HIGH) { goto jump;}
            if(digitalRead(pbOff) == HIGH) { untukOff(); goto keluar;}
          
            }
         }
      }
   }
}

  if(digitalRead(pbKiri) == HIGH) {
    while(1) {
      for(i=5; i>-1; i--) {
        jump1:
        digitalWrite(led [i], HIGH);
        //for(int a=0; a<100; a++) {delay(3);
        delay(300);
        digitalWrite(led [i], LOW);

        if(digitalRead(pbOff) == HIGH) { untukOff(); goto keluar;}
        if(digitalRead(pbKanan) == HIGH) { goto jump;}
        if(digitalRead(pbPause) == HIGH) {
          digitalWrite(led [i], HIGH);
          while(1) {
            if(digitalRead(pbKanan) == HIGH) {goto jump;}
            if(digitalRead(pbKiri) == HIGH) {goto jump1;}
            if(digitalRead(pbOff) == HIGH) { untukOff(); goto keluar;}
        
               }
            }
         }
      }
   }
}
