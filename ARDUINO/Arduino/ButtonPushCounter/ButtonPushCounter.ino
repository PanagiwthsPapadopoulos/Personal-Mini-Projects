int button = 33;
int button_counter = 0;
int previous_button = 0;
int button_state;
String str;


void setup() {
  pinMode(button, INPUT);
  Serial.begin(9600);
}


void input(){
  str = Serial.read();
  if(str.compareTo("reset") == 0){
    button_counter = 0;4
    Serial.println("The counter was reset.");
  } 

}


void loop() {
  button_state = digitalRead(button);
  if(button_state == 1 && previous_button == !(button_state) ){
    button_counter++;
    Serial.println(button_counter);
  }
  
  if(Serial.available() > 0){
    input();
  }
  previous_button = button_state;
}
