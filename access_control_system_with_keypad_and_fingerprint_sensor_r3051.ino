#include <Key.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(32,16,2);
const byte rows=4;
const byte cols=4;
char keys [rows][cols]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
char key;
byte row_pins[4]={2,3,4,5};
byte col_pins[4]={6,7,8,9};
Keypad keypad = Keypad (makeKeymap(keys),row_pins,col_pins,rows,cols);
char check[]={"1345"};
byte counter=0,i=0,num=sizeof(check)-1;
char pass[sizeof(check)-1];
byte pb[6]={A2,A1,A0,13,12,11};
void start(){
  lcd.clear();
        lcd.print("Wrong pass    ");
        delay(2000);
        i=0,counter=0;
        lcd.setCursor(0,0);
        lcd.print("Enter Pass     ");
        lcd.setCursor(0,1);}
        
void setup() {
  for(byte j=0;j<6;j++){
    pinMode(pb[j],INPUT_PULLUP);}
  lcd.init();
  lcd.backlight();
  lcd.print("Enter pass    ");
  lcd.setCursor(0,1);
}

void loop() {
  key = keypad.getKey();
  if(key>'0'&&key!='D'){
    lcd.print('*');
    pass[i]=key;
    i++;
  }else if(key=='D'){
    if(i==num){
      for(byte j=0;j<num;j++){
        if(pass[j]==check[j])counter++;
      }if(counter==num){
        lcd.clear();
        lcd.print("Correct pass       ");
        delay(2000);
        lcd.clear();
        i=0,counter=0;
        lcd.print("Enter your finger  ");
        delay(2000);
        for(byte z=0;z<6;z++){
          if(!digitalRead(pb[z])){
            while(!digitalRead(pb[z]));
            lcd.clear();
            lcd.print("The ID is:");
            lcd.print(            z+1);
            delay(2000);
            lcd.clear();
          }
        }
        
        lcd.setCursor(0,0);
        lcd.print("Enter Pass      ");
        lcd.setCursor(0,1);
        
        
      
   }else{
      start();
    }
    }else{
      start();
    }
   }
  }