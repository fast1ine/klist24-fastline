/** 
* Code Info
* Description: [2024년 화동제 프로젝트 - 10초 카운터] 시설물의 LED 부분에 사용되는 코드입니다
* Developer: 이호진 (일부 자료 외부 사이트 참조)
* Last Bulid Date: 2024/07/11
*/

int red = 5;       //Red LED→Pin5
int yellow = 6;    //Yellow LED→Pin6
int blue = 9;      //Blue LED→Pin9
int green = 10;     //Green LED→Pin10

void setup() {
  pinMode(red, OUTPUT);        // 각 포트를 출력 포트로 설정합니다
  pinMode(yellow, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  
  
}

void loop() {
  // 모든 LED를 먼저 끄기
  digitalWrite(red, LOW);   
  digitalWrite(yellow, LOW); 
  digitalWrite(green, LOW); 
  digitalWrite(blue, LOW);  

  // 하나의 LED를 랜덤하게 켜기
  int ledToTurnOn = random(4); // 0에서 3 사이의 숫자 랜덤 생성

  switch (ledToTurnOn) {
    case 0:
      digitalWrite(red, HIGH);    // Turn On Red LIGHT
      break;
    case 1:
      digitalWrite(yellow, HIGH); // Turn On Yellow LIGHT
      break;
    case 2:
      digitalWrite(green, HIGH);  // Turn On Green LIGHT
      break;
    case 3:
      digitalWrite(blue, HIGH);   // Turn On Blue LIGHT
      break;
  }

  // 5초 지연
  delay(5000);
}