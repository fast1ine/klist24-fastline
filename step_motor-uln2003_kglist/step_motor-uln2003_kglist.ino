/** 
* Code Info
* Description: [2024년 화동제 프로젝트 - 미니카 레이싱] 시설물 일부에서 사용되는 코드입니다 (스텝 모터 사용 부분)
* Developer: 이호진 (일부 자료 외부 사이트 참조)
* Last Bulid Date: 2024/07/11
*/

#define IN1  10
#define IN2  11
#define IN3  12
#define IN4  13

int Steps = 7; // 시작 값을 7로 변경
unsigned long last_time;
unsigned long currentMillis;
const int steps_per_revolution = 4096; // 한 바퀴에 필요한 스텝 수
const int step_delay = 850; // 스텝 간 딜레이 (마이크로초 단위)

void setup() {
  Serial.begin(115200);
  pinMode(IN1, OUTPUT); 
  pinMode(IN2, OUTPUT); 
  pinMode(IN3, OUTPUT); 
  pinMode(IN4, OUTPUT); 
  last_time = micros();
}

void loop() {
  currentMillis = micros();
  if (currentMillis - last_time >= step_delay) {
    stepper(1); 
    last_time = currentMillis;
  }
}

void stepper(int xw) {
  for (int x = 0; x < xw; x++) {
    switch (Steps) {
      case 0:
        digitalWrite(IN1, LOW); 
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        break; 
      case 1:
        digitalWrite(IN1, LOW); 
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, HIGH);
        break; 
      case 2:
        digitalWrite(IN1, LOW); 
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        break; 
      case 3:
        digitalWrite(IN1, LOW); 
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        break; 
      case 4:
        digitalWrite(IN1, LOW); 
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        break; 
      case 5:
        digitalWrite(IN1, HIGH); 
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        break; 
      case 6:
        digitalWrite(IN1, HIGH); 
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        break; 
      case 7:
        digitalWrite(IN1, HIGH); 
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        break; 
      default:
        digitalWrite(IN1, LOW); 
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        break; 
    }
    Steps--;
    if (Steps < 0) { 
      Steps = 7; 
    }
  }
}
