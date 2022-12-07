#include <Servo.h> //서보모터 라이브러리

Servo servoMot; //서보모터
int sensorPin = A0 ;//가변저항
int LED_pins[] = {10,11,12,13}; //led 배열
int currentVoltage = 0;//현재 전압의 상태를 확인
int previousVoltage = 0;//이전 전압의 상태를 확인

void setup() {
  servoMot.attach(8); //서보모터 8번에 연결
 
 // for 문을 활용하여 i = 0 이라는 초기화식을 선언하고, sizeof를 통해 앞서 언급한 LED_pins의 배열을 불러와 OUTPUT(출력)으로 설정
  for(int i = 0; i < sizeof(LED_pins) / sizeof(int); i++){
  pinMode(LED_pins[i],OUTPUT);
 
}
}
void loop() {
 

    int analogValue = analogRead(sensorPin) ;
  servoMot.write(map(analogValue,0,1023,0,180));
    delay (15);
     
  //아날로그 0번핀에 연결된 가변 저항의 값을 읽고, 다시 현재 전압으로 map()함수를 이용하여 변환
    int analogIn = analogRead(A0);  
    currentVoltage = map(analogIn , 0, 1023, 0, 5);
  
  //만약에 현재 전압 currentVoltage 가 != 즉 , 이전 전압 previousVoltage 와 같지 않을때,이전 전압을 갱신  
   if(currentVoltage != previousVoltage){
    previousVoltage = currentVoltage;
    
    // for 구문을 사용하여 현재 전압에 비례하여 배열된 LED pin을 켜고  나머지의 경우 LED pin을 끔 
     for(int i =0; i < currentVoltage; i++){
      digitalWrite(LED_pins[i],HIGH);
    }
    for(int i = currentVoltage; i < 5; i++){
      digitalWrite(LED_pins[i],LOW);
    }
  }
}
