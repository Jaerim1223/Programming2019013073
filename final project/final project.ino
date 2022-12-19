#include <Wire.h> //I2C쓰기위한 헤더파일
#include <LiquidCrystal_I2C.h> //lcd 뒷편 보드 4핀을 제어.
#include "HX711.h" //로드셀은 무게가 실리면 작은 전압이 생김 그 전압이 아주 작음.

LiquidCrystal_I2C lcd(0x27, 16, 2); //lcd 객채 생성 가로 16글자 2줄

const float PRESS = 420.0; //로드센서의 임계값(세팅값). 실수형태로 저장하기 위해 FLOAT이라는 자료형에 넣은 것. 이 값을 넘으면 사람이 있음을 의미.
const int reedSW[4] = { 10, 11, 12, 13 }; //핀 선언. 벨트를 채우면 1 안채우면 0
int reedValue_curr[4] = {0,  }; //현재의 리드스위치 상태 저장 4개 필요.

char _String[4][5] = { "Empty", "Exist", "Gone ", "Belt " }; //char형 글자 담을 수 있는 1바이트형.
char tx_data[4] = {'M', 'E', 'G', 'B'}; //블루투스 보내기 위해 간단하게 1문자로 만듦.

HX711 scale[4]; //객채 생성 4개

float Weight[4] = {0.0, }; //소수점까지 출력하는 무게 4개.

uint8_t currentState[4] = {0, }; //좌석 상태를 담을 변수.

char dispString[30] = {0x00, }; //sprintf의 %s문자열을 담음.

void setup() {
  Serial.begin(115200); //통신속도 1초에 115200글자를 보낼 수 있는 속도.
  
  scale[0].begin(2, 3); //첫번째 로드셀 핀 번호 선언 
  scale[1].begin(4, 5); //두번째 로드셀
  scale[2].begin(6, 7); //세번째 로드셀
  scale[3].begin(8, 9); //네번째 로드셀

  for (int i = 0; i < 4 ; i++ ) 
  {
    scale[i].set_scale(2280.f); //로드셀에 따라 정확한 KG을 찾으려면 set_scale 조정.
    scale[i].tare(); //현재 상태를 0으로 리셋.
  }

  for (int i = 0; i < 4; i++) {
    pinMode(reedSW[i], INPUT);
  } 

  // LCD
  lcd.init(); 
  lcd.backlight(); 
  lcd.setCursor(5, 0); 
  lcd.print("SMART BUS");
  delay(500);
  lcd.clear();
}

void loop() {

  for (int i = 0; i < 4; i++) {
    reedValue_curr[i] = digitalRead(reedSW[i]); //0과1을 읽음.
    Weight[i] = scale[i].get_units(); 
  Serial.print(' ');
  Serial.print(i);
  Serial.print(':');
  Serial.print(Weight[i]);
  
  }

  for (int i = 0; i < 4; i++) {
    if (reedValue_curr[i] && Weight[i] > PRESS ) currentState[i] = 1; //리드스위치가 감지되고, 기준 무게가 넘으면 상태는 1.
    else if ( Weight[i] > PRESS ) currentState[i] = 3; //사람만 감지되면 3.
    else if ( currentState[i] == 0 ) ; //초기상태면 계속 0으로 남아있음  empty유지하려고 0을 넣음.
    else { 
      currentState[i] = 2; // 초기 상태가 0이 아니라면, 모두 gone. 감지 됬다가 사람도 감지 안되고, 리드스위치도 감지가 안되면.
    }
  }

  sprintf(dispString, "%d:%s %d:%s", 1, _String[currentState[0]], 2, _String[currentState[1]]); //sprinf는 변수를 담음. 1,2번 좌석 상태
  lcd.setCursor(0, 0);
  lcd.print(dispString);
  sprintf(dispString, "%d:%s %d:%s", 3, _String[currentState[2]], 4, _String[currentState[3]]); //3,4번 좌석 상태
  lcd.setCursor(0, 1);
  lcd.print(dispString);

  delay(100);
}
