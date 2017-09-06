#include <LiquidCrystal.h>
#include <Wire.h>
#include <SFE_BMP180.h>
SFE_BMP180 sensor;
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
void setup()
{
  double hPa = 0;
  double hPaMax = 0;
  lcd.begin(16, 2);
  Serial.begin(9600);
  //Serial.println("Initializing");
  lcd.clear();
  lcd.print("Starting up");
  lcd.setCursor(0,1);
  //delay(500);
  if (sensor.begin())
      {
       Serial.println("Initialization successful");
       lcd.print("Done");
      }
    else
      {
      Serial.println("Initialization failed");
      lcd.print("Startup Failed");
      while(1);
      }
    //  delay(1000);
    lcd.clear();
}

    double T;
    double A = 1.8;
    double P;
    double K;
    double R = 0;
    double I;
void loop() 
  {
    //double T;
    //double A = 1.8;
    //double P;
    //double K;
    //double R;
    sensor.startTemperature();
    
    delay(500);
    
    sensor.getTemperature(T);

    

    //Serial.print("Temperature in Celcius is ");
    
    //Serial.println(T,1);

    
    
    K = (A*T);
    
    K = K+32;
 //   delay(500);


    
    //Serial.print("Temperature is ");
    
    //Serial.println(K,2);

    
    
    
    sensor.startPressure(3);
    
    delay(500);
    
    sensor.getPressure(P, T);



    
    lcd.setCursor(0,0);
    lcd.print("hPa");
    lcd.setCursor(5,0);
    lcd.print(P);


    
    Serial.print("Pressure is ");
    
    Serial.print(P);

    Serial.println(" hPa");

      if (P > R){
        R=P;
      }
      else{
        Serial.print("Difference from max pressure in hPa ");
        I = (R-P);
        Serial.println(I);
        I = I * .02953;
        Serial.print("Difference from max pressure in \"Hg ");
        Serial.println(I);

        lcd.setCursor(0,1);
        //lcd.print("InHg Level");
        lcd.print("Temp.");
        lcd.setCursor(7, 1);
        lcd.print(K);
      }
      
    delay(500);
  }
