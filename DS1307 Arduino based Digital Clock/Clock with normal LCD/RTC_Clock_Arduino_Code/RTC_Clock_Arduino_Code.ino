//By HomeMade Electronics
//Subscribe to my channel https://www.youtube.com/channel/UC8isJR_71x1wIfw6jB106pg
//Visit website https://sirboatengonline.com
//for more tutorial videos
//like, share and leave a comment if you need help. Thank you

#include <LiquidCrystal.h>
#include <DS1307.h>
#include <Wire.h>

LiquidCrystal lcd(13,12,11,10,9,8);

int clock[7];

void setup(){
for(int i=3;i<8;i++){
 pinMode(i,INPUT); 
}

lcd.begin(20,4);
DS1307.begin();
//Set the current time
DS1307.setDate(21,3,15,0,18,20,04); //year, month, day, week, hours, minutes, seconds
}

void loop(){
DS1307.getDate(clock);

lcd.setCursor(3,2);
lcd.print("Time: ");
Print(clock[4]);
lcd.print(":");
Print(clock[5]);
lcd.print(":");
Print(clock[6]);
lcd.setCursor(3,1);
lcd.print("Date: ");
Print(clock[1]);
lcd.print("/");
Print(clock[2]);
lcd.print("/");
lcd.print("20");
Print(clock[0]);

//minutes settings
if(digitalRead(7)){
 clock[5]++;
 if(clock[5]>59) clock[5]=0;
 DS1307.setDate(clock[0],clock[1],clock[2],0,clock[4],clock[5],clock[6]);
 while(digitalRead(7));
}

//hours settings
if(digitalRead(6)){
 clock[4]++;
 if(clock[4]>23) clock[4]=0;
 DS1307.setDate(clock[0],clock[1],clock[2],0,clock[4],clock[5],clock[6]);
 while(digitalRead(6));
}

//day settings
if(digitalRead(5)){
 clock[2]++;
  if(clock[2]>31) clock[2]=1;
 DS1307.setDate(clock[0],clock[1],clock[2],0,clock[4],clock[5],clock[6]);
 while(digitalRead(5));
}

//months settings
if(digitalRead(4)){
 clock[1]++;
 if(clock[1]>12) clock[1]=1;
 DS1307.setDate(clock[0],clock[1],clock[2],0,clock[4],clock[5],clock[6]);
 while(digitalRead(4));
}

//year settings
if(digitalRead(3)){
 clock[0]++;
 if(clock[0]>99) clock[0]=0;
 DS1307.setDate(clock[0],clock[1],clock[2],0,clock[4],clock[5],clock[6]);
 while(digitalRead(3));
}


delay(100);
}

// Function to set the digits to 00,01,02, ...
void Print(int number){
//prints the most significant digit
lcd.print(number/10);
//prints the least significant digit
lcd.print(number%10);
}
