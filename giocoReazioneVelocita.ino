#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);    

#define tacswitch 2
#define redled 9
#define yelled 10
#define greled 11
 
long starttime = 0;
long stoptime = 0;
long mytime = 0;


float redrand;
float yelrand;

void setup() {
  Serial.begin(115200);
  
  pinMode(redled, OUTPUT);
  pinMode(yelled, OUTPUT); 
  pinMode(greled, OUTPUT);
  pinMode(tacswitch, INPUT_PULLUP);
  
  digitalWrite(redled, LOW);
  digitalWrite(yelled, LOW);
  digitalWrite(greled, LOW);

 
  lcd.init();
  lcd.backlight();
  
  lcd.setCursor(0, 0);
  lcd.print("gioco reazione");
  lcd.setCursor(0, 1); 
  lcd.print("-by Antonio S");
  delay(2000); 
  lcd.clear();

 
  redrand = random(500, 2000);
  yelrand = random(500, 3000);

  
  digitalWrite(redled, HIGH);
  delay(redrand);
  digitalWrite(redled, LOW);

  digitalWrite(yelled, HIGH);
  delay(yelrand);
  digitalWrite(yelled, LOW);

  
  digitalWrite(greled, HIGH);
  starttime = millis(); 
}

void loop() {
 

delay(100);



digitalWrite(greled,HIGH);

if(digitalRead(2)==0){
  long stoptime=millis();

  long mytime=(stoptime-starttime);

  lcd.setCursor(0,0);

  lcd.print("punteggio di ");

  lcd.setCursor(0,1);

  lcd.print(mytime);

  lcd.print(" msecondi: ");



  Serial.print(" inizio- ");

  Serial.println(starttime);

  Serial.print(" fine- ");

  Serial.println(stoptime);

  Serial.print(" tempo fatto- ");

   Serial.print(mytime);

}
}
