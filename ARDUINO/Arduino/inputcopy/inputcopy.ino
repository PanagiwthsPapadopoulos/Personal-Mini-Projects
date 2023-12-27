char string[32]; // for incoming serial data
int ndx = 0, check = 0;
int max_char = 32;

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  pinMode(2, OUTPUT);
  Serial.println("Enter new message: ");
}

void output(){
  for(int i=0; i<ndx; i++){
    if(string[i] >=48 && string[i] <= 57 ) check++;
  }

  if(check == ndx){
    digitalWrite(2, HIGH);
    delay(90);
    digitalWrite(2, LOW);
    delay(40);
    digitalWrite(2, HIGH);
    delay(90);
    Serial.print("The input was the number: ");
  }    
  else{
    digitalWrite(2, HIGH);
    delay(70);
    Serial.print("The input was: ");
  }
  
  check = 0;
  Serial.println(string);
  digitalWrite(2, LOW);
  Serial.println("Enter new message: ");

}

void serialFlush(){
  while(Serial.available() > 0){
    char t = Serial.read();
  }
}

void loop() {
  
  if (Serial.available() > 0) {
    
    char character = Serial.read();
    
    if(ndx <= max_char){
    
      if(character == '\n'){      
        string[ndx] = '\0';
        output();
        ndx = 0;
      }else{
        string[ndx] = character;
        ndx++;
      }
    }else{
      Serial.println("Maximum charactes reached.");
      serialFlush();
      ndx = 0;
      Serial.println("Enter new message: ");
    }
  
  }


}

