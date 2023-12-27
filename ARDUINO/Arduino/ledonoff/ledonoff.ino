char input[32];
int max_char = 32, indx = 0;
#define PIN 2
int light = 0;

void setup() {
  Serial.begin(9600);
  pinMode(PIN, OUTPUT);
  Serial.print("Enter input: ");
}

void output(){
  Serial.println(input);
  if(strcmp(input, "ON") == 0 || strcmp(input, "on") == 0 || strcmp(input, "On") == 0){   
    if(light != 1){
      Serial.println("Turning LED ON");
      digitalWrite(PIN, HIGH);
      light = 1;
      //delay(200);
      Serial.print("Enter new input: ");
    }else Serial.print("The LED is already ON. Try again: ");
  }else if(strcmp(input, "OFF") == 0 || strcmp(input, "off") == 0 || strcmp(input, "Off") == 0){
    if(light != 0){
      Serial.println("Turning LED OFF");
      digitalWrite(PIN, LOW);
      light = 0;
      //delay(200);
      Serial.print("Enter new input: ");
    }else Serial.print("The LED is already OFF. Try again: ");
  }else Serial.print("Invalid input. Try again: ");
}

void serialFlush(){
  while(Serial.available() > 0){
    char t = Serial.read();
  }
}

void loop() {
  if(Serial.available() > 0){
    char temp = Serial.read();

    if(indx < max_char - 1){
      if(temp != '\n'){
        input[indx] = temp;
        indx++;
      }else{
        input[indx] = '\0';
        output();
        indx = 0;
      }
    }else{
      serialFlush();
      Serial.print("Input too large. Try again: ");
      indx = 0;
    }
    
  
  }

}
