
#include <LiquidCrystal.h>
#include <Keypad.h>


LiquidCrystal lcd(8,9,10,11,12,13);
const byte ROWS=4;
const byte  COLS=3;
char keys[ROWS][COLS]= {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'},
  };
byte rowPins[ROWS]={3,2,1,0};
byte colPins[COLS]={4,5,6};
Keypad keypad=Keypad( makeKeymap(keys),rowPins,colPins,ROWS,COLS);
#define IR A0
#define COIN A1
#define OR A2
unsigned int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0,k=0,l=0;

void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("WELCOME");
  pinMode(IR,INPUT);
  pinMode(COIN,INPUT);
  pinMode(OR,INPUT);
  delay(2000);

}

void loop() {
  a=digitalRead(IR);
  if(a==1)
  {
    b=1;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("INSERT COIN");
    delay(1000);
  }
  if(b==1)
  {
    while(b==1)
    {
      c=digitalRead(COIN);
      if(c==1)
      {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("ENTER NUMBER");
        delay(1000);
        b=0;
        c=0;
        d=1;
        lcd.setCursor(0,1);
      }
    }
  }
  if(d==1)
  {
    while(d==1)
    {
      char key=keypad.getKey();
      if(key!=NO_KEY)
      {
        lcd.print(key);
        e++;
        char key=keypad.waitForKey();
        if(e>=9)
        {
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("DAILING");
          delay(300);
          d=0;
          f=1;
        }
      }
    }
  }
  if(f==1)
  {
    g=digitalRead(OR);
    if(g==1)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("CONNECTING");
      f=0;
      h=1;
      i=60;
    }
  }
  if(h==1)
  {
    i=i-1;
    lcd.setCursor(13,1);
    lcd.print(i);
    delay(1000);
    j=1;
    if(i==0)
    {
      h=0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("CALL ENDED");
    }
  }
  if(j==1)
  {
    k=digitalRead(COIN);
    if(k==1)
    {
      i=i+60;
    }
  }
}
        
