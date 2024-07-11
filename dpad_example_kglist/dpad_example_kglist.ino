/** 
* Code Info
* Description: 2024년 과기부에서 사용하는 ADKeyboard D-패드의 예제코드
* Developer: 이호진 (일부 자료 외부 사이트 참조)
* Last Bulid Date: 2024/07/10
*/
int adc_key_val[5] = {30, 150, 360, 535, 760}; // 센서 버튼 값 정의
int NUM_KEYS = 5; // 버튼 개수
int adc_key_in; // 데이터를 읽을 변수
// 중복 출력 방지를 위한 변수 세트
int key = -1;
int oldkey = -1;
void setup() {
  Serial.begin(9600);
}

void loop() {
  adc_key_in = analogRead(0); // 데이터 읽음
  key = get_key(adc_key_in);  // 어떤 버튼이 클릭되었는지 찾음

  if (key != oldkey) {   // 유효한 버튼이 눌려졌으면,
    delay(50);  // 채터링을 방지하기 위해 잠시 기다림
    oldkey = key;
    if (key != -1) { // 버튼 누른 상태가 종료되면 -1을 출력하기 때문에 -1이 아닐 때만 출력함
    Serial.print("버튼 ");
      switch (key) {
        case 0: Serial.print("1");
          break;
        case 1: Serial.print("2");
          break;
        case 2: Serial.print("3");
          break;
        case 3: Serial.print("4");
          break;
        case 4: Serial.print("5");
          break;
      }
      Serial.println("눌려짐!");
    }
  }
  delay(100);
}
// 클릭한 버튼을 찾기 위한 함수
int get_key(unsigned int input) {
  int k;
  for (k = 0; k < NUM_KEYS; k++) {
    if (input < adc_key_val[k]) {
      return k;
    }
  }
  if (k >= NUM_KEYS)k = -1; // 만약 유효한 버튼이 클릭되지 않았다면 -1 출력
  return k;
}