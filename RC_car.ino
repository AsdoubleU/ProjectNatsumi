#include <SoftwareSerial.h>
#include "HUSKYLENS.h"
#include "SoftwareSerial.h" //각종 라이브러리 추가

HUSKYLENS huskylens; //허스키 렌즈를 사용하기 위하여 허스키렌즈 객체 추가 

void Tracking(HUSKYLENSResult result); // 물체 추적 함수 선언. 

SoftwareSerial btSerial(9,10); // 블루투스모듈에 연결하는 핀 선언 

#define B1 3
#define B2 4
#define A1 5
#define A2 6  //DC모터 전용 핀 설정.

void forward(int v);
void backward(int v);
void turnright(int v);
void turnleft(int v);
void stops(int v);
// 전진, 후진, 좌회전, 우회전 함수 설정. 각 함수 코드는 moving 파일 참조.

void setup() {
  btSerial.begin(9600);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(B1,OUTPUT);
  pinMode(B2,OUTPUT);

  Serial.begin(115200);
    Wire.begin();
    while (!huskylens.begin(Wire))
    {
        Serial.println(F("Begin failed!"));
        Serial.println(F("1.Please recheck the \"Protocol Type\" in HUSKYLENS (General Settings>>Protocol Type>>I2C)"));
        Serial.println(F("2.Please recheck the connection."));
        delay(100);
    }
}

void loop() {

  if (!huskylens.request()) Serial.println(F("Fail to request data from HUSKYLENS, recheck the connection!"));
    else if(!huskylens.isLearned()) Serial.println(F("Nothing learned, press learn button on HUSKYLENS to learn one!"));
    else if(!huskylens.available()) {
      Serial.println(F("No block or arrow appears on the screen!"));
      stops(0);
    }
    else
    {
        Serial.println(F("###########"));
        while (huskylens.available())
        {
            HUSKYLENSResult result = huskylens.read();
            Tracking(result);  
         }
        }    
   //물체가 감지될 시, 물체 추적 함수로 돌입한다.     
  
  char c;
  int det = 0;
  
  if(btSerial.available()){ //이외에 스마트폰으로부터 신호가 들어올 시 이를 c라는 변수에 저장.
    c = btSerial.read();
  }
  
  switch (c){
    case 'S':
    stops(0);
    break;
    case 'F':
    forward(255);
    break;
    case 'B':
    backward(255);
    break;
    case 'R':
    turnright(255);
    break;
    case 'L':
    turnleft (255);
    break;
    case 'H':
    det = 1;
    break;
    }

    // 각 전진, 후진, 좌회전, 우회전 등의 버튼에 관한 신호가 들어오면 모터를 움직임.
    
  }
  

void Tracking(HUSKYLENSResult result){
    if (result.command == COMMAND_RETURN_BLOCK){
        Serial.println(String()+F("Block:xCenter=")+result.xCenter+F(",yCenter=")+result.yCenter+F(",width=")+result.width+F(",height=")+result.height+F(",ID=")+result.ID);
 
 int num1 = map(result.xCenter,0,320,-160,160);
 int num2 = map(result.yCenter,0,240,0,50);
 // map함수를 통해 허스키렌즈 화면 상의 물체를 -160부터 160의 값으로 변환.
 
if(result.ID == 1){
  Serial.println(num1);
  if(num1 > 30) {
    turnright(140);
    delay(9);
    stops(0);
    delay(10); 
  }
  else if (num1 < -30){
    turnleft(150);
    delay(20);
    stops(0);
    delay(10); //물체가 화면 상의 중심의 x좌표가 원점으로부터 +-30이 넘어가면, RC카를 움직여서 다시 물체를 화면의 중심으로 되돌려놓음.
  }            //RC카 자체의 전력문제 때문에 특정 값 이하의 속도는 사용할 수 없어, 딜레이로 짧게 끊어가며 중심 조절한다.
  else{
    stops(0); 
  }
  Serial.println(num2);
}
 }
}
