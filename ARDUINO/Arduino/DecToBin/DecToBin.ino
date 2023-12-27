//BINARY TO DECIMAL WITH LEDs
int led0 = 2;                           //led with lsb
int led1 = 17;
int led2 = 18;
int led3 = 19;                          //led with msb
int indx = 0, max_char = 2;
char input[2];

void setup(){
  pinMode(led0,OUTPUT);                 
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);                 
  Serial.begin(9600);
  Serial.print("Enter a number: ");
}
void serialFlush(){
  while(Serial.available() > 0){
    char t = Serial.read();
  }
}

void math(int num){
  int t;
  
    
    if(num%2 == 1) digitalWrite(led0,HIGH);
    num = num/2;
    if(num%2 == 1) digitalWrite(led1, HIGH);
    num = num/2;
    if(num%2 == 1) digitalWrite(led2, HIGH);
    num = num/2;
    if(num%2 == 1) digitalWrite(led3, HIGH);
  
}

void output(){
  Serial.println(input);
  if( isalpha(input[0]) || isalpha(input[1]) ) Serial.print("Invalid input. Try again: ");
  else{
    math(atoi(input));
  }
  Serial.print("Enter a new number: ");
  
}




void loop(){
  
  if(Serial.available() > 0){
    
    char temp = Serial.read();
    
    digitalWrite(led0, LOW);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    
    if(indx <= max_char ){
      
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