#include <Wire.h>

#include "Adafruit_MLX90393.h"

Adafruit_MLX90393 sensor = Adafruit_MLX90393();


const int MPU = 0x68; // MPU6050 I2C address
float AccX, AccY, AccZ;
float GyroX, GyroY, GyroZ;
float accAngleX, accAngleY, gyroAngleX, gyroAngleY, gyroAngleZ;
float roll, pitch, yaw;
float AccErrorX, AccErrorY, GyroErrorX, GyroErrorY, GyroErrorZ;
float elapsedTime, currentTime, previousTime;
int c = 0;

  

void setup(void)
{
  digitalWrite(15, LOW);
  pinMode(15, OUTPUT);
  digitalWrite(15, LOW);
  
  Serial.begin(19200);

  /* Wait for serial on USB platforms. */
  while(!Serial) {
      delay(10);
  }

  Serial.println("Starting Adafruit MLX90393 Demo");

  if (sensor.begin_I2C())
  {
    Serial.println("Found a MLX90393 sensor");
  }
  else
  { 
    Serial.println("No sensor found ... check your wiring?");
    while (1);
  }

  sensor.setGain(MLX90393_GAIN_5X);
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //Serial.begin(19200);
  Wire.begin();                      // Initialize comunication
  Wire.beginTransmission(MPU);       // Start communication with MPU6050 // MPU=0x68
  Wire.write(0x6B);                  // Talk to the register 6B
  Wire.write(0x00);                  // Make reset - place a 0 into the 6B register
  Wire.endTransmission(true); 

  calculate_IMU_error();
  delay(20);
}

void loop(void)
{
    float x, y, z;

    if(sensor.readData(&x, &y, &z)) {
        Serial.print("{");
        Serial.print("\"X\":"); Serial.print((int)x); Serial.print(",");
        Serial.print("\"Y\":"); Serial.print((int)y); Serial.print(",");
        Serial.print("\"Z\":"); Serial.print((int)z); Serial.print("}");
        Serial.println("\r\n");
    } else {
        Serial.println("Unable to read XYZ data from the sensor.");

        pinMode(15, INPUT);
        delay(200);
        digitalWrite(15, LOW);
        pinMode(15, OUTPUT);
        digitalWrite(15, LOW);
    }

    delay(100);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    Wire.beginTransmission(MPU);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6, true);  
  
  AccX = (Wire.read() << 8 | Wire.read()) / 16384.0;  
  AccY = (Wire.read() << 8 | Wire.read()) / 16384.0;  
  AccZ = (Wire.read() << 8 | Wire.read()) / 16384.0;  
  
  accAngleX = (atan(AccY / sqrt(pow(AccX, 2) + pow(AccZ, 2))) * 180 / PI) - 0.58;       
  accAngleY = (atan(-1 * AccX / sqrt(pow(AccY, 2) + pow(AccZ, 2))) * 180 / PI) + 1.58;  
  
  previousTime = currentTime;                         
  currentTime = millis();                             
  elapsedTime = (currentTime - previousTime) / 1000;  
  Wire.beginTransmission(MPU);
  Wire.write(0x43);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6, true);                    
  GyroX = (Wire.read() << 8 | Wire.read()) / 131.0;  
  GyroY = (Wire.read() << 8 | Wire.read()) / 131.0;
  GyroZ = (Wire.read() << 8 | Wire.read()) / 131.0;
  
  GyroX = GyroX + 0.56;  
  GyroY = GyroY - 2;     
  GyroZ = GyroZ + 0.79;  
  
  gyroAngleX = gyroAngleX + GyroX * elapsedTime;  
  gyroAngleY = gyroAngleY + GyroY * elapsedTime;
  yaw = yaw + GyroZ * elapsedTime;
  
  roll = 0.96 * gyroAngleX + 0.04 * accAngleX;
  pitch = 0.96 * gyroAngleY + 0.04 * accAngleY;

  
  Serial.print(roll);
  Serial.print(" /|/ ");
  Serial.print(pitch);
  Serial.print(" /|/ ");
  Serial.println(yaw);
  delay(100);
}


void calculate_IMU_error() {
  
  
  
  while (c < 200) {
    Wire.beginTransmission(MPU);
    Wire.write(0x3B);
    Wire.endTransmission(false);
    Wire.requestFrom(MPU, 6, true);
    AccX = (Wire.read() << 8 | Wire.read()) / 16384.0;
    AccY = (Wire.read() << 8 | Wire.read()) / 16384.0;
    AccZ = (Wire.read() << 8 | Wire.read()) / 16384.0;
    
    AccErrorX = AccErrorX + ((atan((AccY) / sqrt(pow((AccX), 2) + pow((AccZ), 2))) * 180 / PI));
    AccErrorY = AccErrorY + ((atan(-1 * (AccX) / sqrt(pow((AccY), 2) + pow((AccZ), 2))) * 180 / PI));
    c++;
  }
  
  AccErrorX = AccErrorX / 200;
  AccErrorY = AccErrorY / 200;
  c = 0;
  
  while (c < 200) {
    Wire.beginTransmission(MPU);
    Wire.write(0x43);
    Wire.endTransmission(false);
    Wire.requestFrom(MPU, 6, true);
    GyroX = Wire.read() << 8 | Wire.read();
    GyroY = Wire.read() << 8 | Wire.read();
    GyroZ = Wire.read() << 8 | Wire.read();
    
    GyroErrorX = GyroErrorX + (GyroX / 131.0);
    GyroErrorY = GyroErrorY + (GyroY / 131.0);
    GyroErrorZ = GyroErrorZ + (GyroZ / 131.0);
    c++;
  }
  
  GyroErrorX = GyroErrorX / 200;
  GyroErrorY = GyroErrorY / 200;
  GyroErrorZ = GyroErrorZ / 200;
  
  Serial.print("AccErrorX: ");
  Serial.println(AccErrorX);
  Serial.print("AccErrorY: ");
  Serial.println(AccErrorY);
  Serial.print("GyroErrorX: ");
  Serial.println(GyroErrorX);
  Serial.print("GyroErrorY: ");
  Serial.println(GyroErrorY);
  Serial.print("GyroErrorZ: ");
  Serial.println(GyroErrorZ);
}

