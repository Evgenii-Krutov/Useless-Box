#include <Servo.h>

Servo SERVO_DRIVE;
int SERVO_POS = 0;
int TUMBLER_PIN = 0;
int PHOTO_PIN = 0;
int COUNT = 0;
int RANDOM_NUMBER;

int ENGINE_A = 5;
int IN_1 = 6;
int IN_2 = 7;

int ENGINE_B = 8;
int IN_3 = 9;
int IN_4 = 10;
 
void setup() {
  SERVO_DRIVE.attach(2);
  SERVO_DRIVE.write(90);
  
  pinMode(ENGINE_A, OUTPUT);
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  
  pinMode(ENGINE_B, OUTPUT);
  pinMode(IN_3, OUTPUT);
  pinMode(IN_4, OUTPUT);
  Serial.begin(9600);
}
 
void loop() {
  TUMBLER_PIN = digitalRead(4);
  PHOTO_PIN = digitalRead(3);
  Serial.println(PHOTO_PIN);
  if(PHOTO_PIN == 1) {
    if(TUMBLER_PIN == HIGH) {
      RANDOM_NUMBER = random(1,6);
      switch(RANDOM_NUMBER) {
        case 1: holdingSwitch();delay(3000); break;
        case 2: quietSwitch();delay(3000); break;
        case 3: regularSwitch();delay(3000); break;
        case 4: playingSwitch();delay(3000); break;
        case 5: thinkingSwitch();delay(3000); break;
      }
      COUNT += 1; 
    }
  }else {
    if(COUNT > 5){
      engineStart();
      COUNT = 0;
    }
  }
}

void regularSwitch() {
  for (SERVO_POS = 0; SERVO_POS <= 90; SERVO_POS += 1) {
    SERVO_DRIVE.write(SERVO_POS);
    delay(3);
  }
  for (SERVO_POS = 90; SERVO_POS >= 0; SERVO_POS -= 1) {
    SERVO_DRIVE.write(SERVO_POS);
    delay(3);
  }
}

void quietSwitch() {
  delay(3000);
  for (SERVO_POS = 0; SERVO_POS <= 90; SERVO_POS += 1) {
    SERVO_DRIVE.write(SERVO_POS);
    delay(3);
  }
  for (SERVO_POS = 90; SERVO_POS >= 0; SERVO_POS -= 1) {
    SERVO_DRIVE.write(SERVO_POS);
    delay(3);
  }
}

void holdingSwitch() {
  for (SERVO_POS = 0; SERVO_POS <= 90; SERVO_POS += 1) {
    SERVO_DRIVE.write(SERVO_POS);
    delay(2);
  }
  delay(3000);
  for (SERVO_POS = 90; SERVO_POS >= 0; SERVO_POS -= 1) {
    SERVO_DRIVE.write(SERVO_POS);
    delay(2);
  }
}

void playingSwitch() {
  for (SERVO_POS = 0; SERVO_POS <= 40; SERVO_POS += 1) {
    SERVO_DRIVE.write(SERVO_POS);
    delay(30);
  }
  delay(500);
  for (SERVO_POS = 40; SERVO_POS <= 90; SERVO_POS += 1) {
    SERVO_DRIVE.write(SERVO_POS);
    delay(3);
  }
  for (SERVO_POS = 90; SERVO_POS >= 0; SERVO_POS -= 1) {
    SERVO_DRIVE.write(SERVO_POS);
    delay(3);
  }  
}

void thinkingSwitch() {
  for (SERVO_POS = 0; SERVO_POS <= 50; SERVO_POS += 1) {
    SERVO_DRIVE.write(SERVO_POS);
    delay(5);
  }
  delay(500);
  for (SERVO_POS = 50; SERVO_POS >= 0; SERVO_POS -= 1) {
    SERVO_DRIVE.write(SERVO_POS);
    delay(15);
  }
  
  delay(2000);
  
  for (SERVO_POS = 0; SERVO_POS <= 90; SERVO_POS += 1) {
    SERVO_DRIVE.write(SERVO_POS);
    delay(3);
  }
  for (SERVO_POS = 90; SERVO_POS >= 0; SERVO_POS -= 1) {
    SERVO_DRIVE.write(SERVO_POS);
    delay(3);
  }
}

void engineStart() {
  digitalWrite(IN_1, HIGH);
  digitalWrite(IN_2, LOW);
  analogWrite(ENGINE_A, 220);
  
  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, HIGH);
  analogWrite(ENGINE_B, 220);

  delay(1500);
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, LOW);
  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, LOW);  
}

