#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
#include "SoftwareSerial.h"
SoftwareSerial mySerial(5, 6);
String zone = "AM";

#include <Servo.h>

Servo myservo;

Servo myservo2;

int a = 4;
int b = 3;
//int c = 10;

int av = 0;
int bv = 0;
//int cv = 0;

int count1 = 1;
int count2 = 1;
int count3 = 1;

int buzzer = 7;

//int pos = 0;


void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  while (!Serial) ; // wait for serial
  delay(200);
  Serial.println("DS1307RTC Read Test");
  Serial.println("-------------------");

  myservo.attach(9);
  myservo2.attach(10);

  pinMode(a, INPUT);
  pinMode(b, INPUT);
//  pinMode(c, INPUT);
  pinMode(buzzer, OUTPUT);

  //  myservo2.write(pos);
  //      delay(1500);
  //      myservo.write(pos);
  ////      delay(1500);
  //
  //  //  myservo2.write(10);
  //  //  myservo.write(0);
}

void loop() {
  tmElements_t tm;

  if (RTC.read(tm)) {
    //    if(tm.Hour>12){
    //      tm.Hour=tm.Hour-12;
    //      zone="PM";
    //      Serial.print(zone);
    //    }else{
    //      zone="AM";
    //      Serial.print(zone);
    //    }
    Serial.print("Time = ");
    print2digits(tm.Hour);
    Serial.print(':');
    print2digits(tm.Minute);
    Serial.print(':');
    print2digits(tm.Second);

    av = digitalRead(a);
    bv = digitalRead(b);
   // cv = digitalRead(c);

    Serial.println(av);
    Serial.println(bv);
   // Serial.println(cv);
    delay(1000);


    //    if(tm.Hour=="09"&& zone.compareTo("AM")){
    //      Serial.println("mrg alert ");
    //
    //    }else  if(tm.Hour=="01"&& zone.compareTo("PM")){
    //       Serial.println("aft alert");
    //    }else if(tm.Hour=="09"&& zone.compareTo("PM")){
    //       Serial.println("night alert");
    //
    //    }


    Serial.println("count1==");
    Serial.println(count1);
    Serial.println("count2==");
    Serial.println(count2);
    Serial.println("count3==");
    Serial.println(count3);


    if (tm.Hour == 15 && count1 == 1 && av == 1) {
      Serial.println("mrg alert");
      mySerial.println("1");

      int pos1 = 0;
      myservo.write(pos1);
      delay(1000);
      digitalWrite(buzzer, HIGH);
      delay(1000);
      // myservo.write(0);
    }
    //    else if (tm.Hour == 14 && count2 == 1 && bv == 1)
    //     Serial.println("aft alert");
    //
    //
    //
    //      digitalWrite(buzzer, HIGH);
    //      delay(2000);
    //    }
    else if (tm.Hour == 13 && count2 == 1 && bv == 1) {
      Serial.println("Night Tablet");
      int pos2 = 180;
      myservo2.write(pos2);

      mySerial.println("2");
      digitalWrite(buzzer, HIGH);
      delay(1000);
      //myservo2.write(0);
    }

    else {
      digitalWrite(buzzer, LOW);
      count1 = 0;
      count2 = 0;
      count3 = 0;
     // int pos = 0;

      myservo2.write(40);
      delay(1500);
      myservo.write(120);
      delay(1500);

      Serial.println("nothing");

    }
} else {
    if (RTC.chipPresent()) {
      Serial.println("The DS1307 is stopped.  Please run the SetTime");
      Serial.println("example to initialize the time and begin running.");
      Serial.println();
    } else {
      Serial.println("DS1307 read error!  Please check the circuitry.");
      Serial.println();
    }
    delay(9000);
  }
  delay(1000);
}

void print2digits(int number) {
  if (number >= 0 && number < 10) {
    Serial.write('0');
  }
  Serial.print(number);
}






