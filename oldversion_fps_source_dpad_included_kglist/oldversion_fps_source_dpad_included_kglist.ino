/** 
* Code Info
* Description: [구버전 주의] [2024년 화동제 프로젝트 - 자이로 슈팅] 의 총기 하드웨어 코드에 D-패드 코드를 병합한 코드입니다.
* Developer: 최정운, 이호진 (일부 자료 외부 사이트 참조)
* Last Bulid Date: 2024/07/10
* Note: 구 버전, 코드의 모든 부분이 동작하지 않습니다! 사용에 주의하세요!!
*/
#include<Wire.h> // 통신 때문에 필요
#include<Mouse.h> // 마우스 움직여야지!

/*
 SDA 2번 Pin, SCL 3번 Pin, Int 7번 Pin
 Int 무조건 박아야됨. 
*/
 
#define MPU6050_INT_PIN 7 // 레오나르도에서는 무조건 7번 Pin에 박아주자
#define MPU6050_INT digitalPinToInterrupt(MPU6050_INT_PIN)

const int MPU_addr=0x68;  // I2C address of the MPU-6050
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

//민감도 조절 변수
int timer1 = 0;
int sens = 1100; // sens_num = 3
int sens_num = 3; // sens = 1100;

//D패드식 버튼 정의
int adc_key_val[5] = {30, 150, 360, 535, 760}; // 센서 버튼 값 정의
int NUM_KEYS = 5; // 버튼 개수
int adc_key_in; // 데이터를 읽을 변수

// 중복 출력 방지를 위한 변수 세트
int key = -1;
int oldkey = -1;
void setup() {
  Serial.begin(9600);
}


void setup()
{
  // 설정인데 안 건드는게 좋음. 잘 되있음.
  Serial.begin(9600);
  Serial.println("start");
  Serial.print(MPU6050_INT); Serial.print(" on pin "); Serial.print(MPU6050_INT_PIN);
  pinMode(8, INPUT_PULLUP); // 좌클릭 버튼
  Mouse.begin();

  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  

  pinMode(MPU6050_INT, INPUT);
  
  //attachInterrupt(MPU6050_INT, dmpDataReady, RISdlfhgk62ING);
}

void loop()
{
  //D패드식 버튼 조작 신호처리 (WASD)
  adc_key_in = analogRead(0); // 데이터 읽음
  key = get_key(adc_key_in);  // 어떤 버튼이 클릭되었는지 찾음

  if (key != oldkey) {   // 유효한 버튼이 눌려졌으면,
    delay(50);  // 채터링을 방지하기 위해 잠시 기다림
    oldkey = key;
    if (key != -1) { // 버튼 누른 상태가 종료되면 -1을 출력하기 때문에 -1이 아닐 때만 출력함
      switch (key) {

        /** 
         * Button Instructions
         * Yellow SW → Btn W→1
         * Red SW → Btn A→2
         * Blue SW → Btn S→3
         * Green SW → Btn D→4
         * White SW → Btn Start/Stop→5
         */
        case 0: /** 이곳에 1번 API 입력 * ex: Serial.print("1"); */
          break;
        case 1: /** 이곳에 2번 API 입력 * ex: Serial.print("2"); */
          break;
        case 2: /** 이곳에 3번 API 입력 * ex: Serial.print("3"); */
          break;
        case 3: /** 이곳에 4번 API 입력 * ex: Serial.print("4"); */
          break;
        case 4: /** 이곳에 5번 API 입력 * ex: Serial.print("5"); */
          break;
      }
    }
  }
  delay(100);
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
  AcX=Wire.read()<<8|Wire.read();  // 0x3B( ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)     
  AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Tmp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
  // 여기 위까지는 코드 건들지 않는 걸 추천. 여기 아래부터 수정 ㄱㄱ

  float gyroY, gyroZ;
   
  gyroZ = GyZ / sens;  // X축
  gyroY = -GyY / sens; // Y축
  
  // 버튼의 센서값을 읽음 -> 누르면 1, 안 누르면 0
  // 좌클릭, 1이면 누른 상태, 0이면 안 누른 상태임.
  int lb;
  lb = 1-digitalRead(8);

  // lb 가 1 -> 좌클릭을 한 경우
  if(lb == 1)  {
    // 마우스를 누른 상태로 유지시켜주는 Mouse.press()를 사용함.           
    Mouse.press(); // 좌클릭 한 상태 유지
  }

  // 클릭 상태 해제
  else if (lb == 0) {
    Mouse.release(); //클릭 상태 해제
  }

  Sprint1(gyroY, gyroZ, lb); // 센서 값을출 력해줌
  Mouse.move(gyroZ, gyroY); // 마우스를 움직여주는 함수
}

// 센서 값을 출력해줌는 함수(자이로, 버튼)
void Sprint1(int gyroY, int gyroZ, int lb)
{
  Serial.print("X축: "); 
  Serial.print(gyroZ);
  Serial.print(" || Y축: "); 
  Serial.print(-gyroY);
  Serial.print(" || 좌 클릭: ");
  Serial.println(lb);
}

// 클릭 D패드 버튼 찾는 함수
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