#include <SoftwareSerial.h>

// LED 핀 설정
const int ledPins[6] = {7, 6, 5, 4, 3, 2};  // Led1, Led4, Led2, Led5, Led3, Led6

// 블루투스 시리얼 설정
SoftwareSerial btSerial(10, 11); // RX, TX

// 버튼 핀 설정
const int buttonPin = 8; 

// 한국어 초성 점자 패턴
const int cho[][6] = {
  {0, 0, 0, 1, 0, 0}, // ㄱ
  {0, 0, 0, 1, 0, 0}, // ㄲ
  {1, 0, 0, 1, 0, 0}, // ㄴ
  {0, 1, 0, 1, 0, 0}, // ㄷ
  {0, 1, 0, 1, 0, 0}, // ㄸ
  {0, 0, 0, 0, 1, 0}, // ㄹ
  {1, 0, 0, 0, 1, 0}, // ㅁ
  {0, 0, 0, 1, 1, 0}, // ㅂ
  {0, 0, 0, 1, 1, 0}, // ㅃ
  {0, 0, 0, 0, 0, 1}, // ㅅ
  {0, 0, 0, 0, 0, 1}, // ㅆ
  {1, 1, 0, 1, 1, 0}, // ㅇ
  {0, 0, 1, 1, 0, 0}, // ㅈ
  {0, 0, 1, 1, 0, 0}, // ㅉ
  {0, 0, 0, 0, 1, 1}, // ㅊ
  {1, 1, 0, 1, 0, 0}, // ㅋ
  {1, 1, 0, 0, 1, 0}, // ㅌ
  {1, 0, 0, 1, 1, 0}, // ㅍ
  {0, 1, 0, 1, 1, 0}, // ㅎ
};

// 한국어 중성 점자 패턴
const int jung[][6] = {
  {1, 1, 0, 0, 0, 1}, // ㅏ
  {1, 1, 1, 0, 1, 0}, // ㅐ
  {0, 0, 1, 1, 1, 0}, // ㅑ
  {0, 0, 1, 1, 1, 0}, // ㅒ
  {0, 1, 1, 1, 0, 0}, // ㅓ
  {1, 0, 1, 1, 1, 0}, // ㅔ
  {1, 0, 0, 0, 1, 1}, // ㅕ  
  {0, 0, 1, 1, 0, 0}, // ㅖ
  {1, 0, 1, 0, 0, 1}, // ㅗ  
  {1, 1, 1, 0, 0, 1}, // ㅘ
  {1, 1, 1, 0, 0, 1}, // ㅙ
  {1, 0, 1, 1, 1, 1}, // ㅚ
  {0, 0, 1, 1, 0, 1}, // ㅛ
  {1, 0, 1, 1, 0, 0}, // ㅜ
  {1, 1, 1, 1, 0, 0}, // ㅝ
  {1, 1, 1, 1, 0, 0}, // ㅞ
  {1, 0, 1, 1, 0, 0}, // ㅟ
  {1, 0, 0, 1, 0, 1}, // ㅠ
  {0, 1, 0, 1, 0, 1}, // ㅡ
  {0, 1, 0, 1, 1, 1}, // ㅢ
  {1, 0, 1, 0, 1, 0}  // ㅣ
};

// 알파벳 점자 배열 (영어 대문자)
int alphabetBraille[26][6] = {
  {1, 0, 0, 0, 0, 0}, // A
  {1, 1, 0, 0, 0, 0}, // B
  {1, 0, 0, 1, 0, 0}, // C
  {1, 0, 0, 1, 1, 0}, // D
  {1, 0, 0, 0, 1, 0}, // E
  {1, 1, 0, 1, 0, 0}, // F
  {1, 1, 0, 1, 1, 0}, // G
  {1, 1, 0, 0, 1, 0}, // H
  {0, 0, 1, 1, 0, 0}, // I
  {0, 0, 1, 1, 1, 0}, // J
  {1, 0, 1, 0, 0, 0}, // K
  {1, 1, 1, 0, 0, 0}, // L
  {1, 0, 1, 1, 0, 0}, // M
  {1, 0, 1, 1, 1, 0}, // N
  {1, 0, 1, 0, 1, 0}, // O
  {1, 1, 1, 1, 0, 0}, // P
  {1, 1, 1, 1, 1, 0}, // Q
  {1, 1, 1, 0, 1, 0}, // R
  {0, 0, 1, 1, 1, 1}, // S
  {0, 0, 1, 1, 0, 1}, // T
  {1, 0, 0, 0, 0, 1}, // U
  {1, 1, 0, 0, 1, 1}, // V
  {0, 0, 1, 1, 1, 1}, // W
  {1, 0, 1, 0, 1, 1}, // X
  {1, 0, 1, 1, 1, 1}, // Y
  {1, 0, 1, 0, 0, 1}  // Z
};

// 숫자 점자 배열 (0-9)
int numberBraille[10][6] = {
  {0, 1, 0, 1, 1, 0}, // 0
  {1, 0, 0, 0, 0, 0}, // 1
  {1, 1, 0, 0, 0, 0}, // 2
  {1, 0, 0, 1, 0, 0}, // 3
  {1, 0, 0, 1, 1, 0}, // 4
  {1, 0, 0, 0, 1, 0}, // 5
  {1, 1, 0, 1, 0, 0}, // 6
  {1, 1, 0, 1, 1, 0}, // 7
  {1, 1, 0, 0, 1, 0}, // 8
  {0, 1, 0, 1, 0, 0}  // 9
};

int chosungIdx = -1;
int jungsungIdx = -1;

// 점자 출력 함수
void displayBraille(int braille[6]) {
  for (int i = 0; i < 6; i++) {
    digitalWrite(ledPins[i], braille[i] == 1 ? HIGH : LOW);
  }
}

// 초성, 중성 분리 함수
void processCharacter(unsigned int unicodeValue){
  if (unicodeValue >= 0xAC00 && unicodeValue <= 0xD7A3) {
    // 초성 (자음) 인덱스 (0~18)
    chosungIdx = (unicodeValue - 0xAC00) / (21 * 28);
    // 중성 (모음) 인덱스 (0~20)
    jungsungIdx = ((unicodeValue - 0xAC00) % (21 * 28)) / 28;
  } else {
    chosungIdx = -1;
    jungsungIdx = -1;
  }

  // 초성 LED 출력
  if (chosungIdx != -1) {
    displayBraille(cho[chosungIdx]);
    Serial.println("Chosung displayed");
    delay(1000);
  }

  // 중성 LED 출력
  if (jungsungIdx != -1) {
    displayBraille(jung[jungsungIdx]);
    Serial.println("Jungsung displayed");
    delay(1000);
  }
}

// 문자열이 16진수인지 확인하는 함수
bool isHexadecimal(String str) {
  for (int i = 0; i < str.length(); i++) {
    char c = str.charAt(i);
    if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))) {
      return false;  
    }
  }
  return true;  
}

void setup() {
  // LED 핀을 출력으로 설정
  for (int i = 0; i < 6; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  // 버튼 핀을 입력으로 설정
  pinMode(buttonPin, INPUT);

  // 블루투스 시리얼 시작
  btSerial.begin(9600);

  // 시리얼 모니터 시작
  Serial.begin(9600);
}


void loop() {
  static String receivedText = "";   
  static int currentCharIndex = 0;  
  
//블루투스 연결 확인
  if (btSerial.available()) {
    receivedText = btSerial.readStringUntil('\n'); 
    currentCharIndex = 0;  
  }

  
  if (currentCharIndex < receivedText.length()) {
    String currentText = receivedText.substring(currentCharIndex, currentCharIndex + 4); 

    //16진수 확인 후, 한글 출력
    if (isHexadecimal(currentText)) {
      unsigned int unicodeValue = strtol(currentText.c_str(), NULL, 16);  
      
      
      if (unicodeValue >= 0xAC00 && unicodeValue <= 0xD7A3) {
        processCharacter(unicodeValue);  
        currentCharIndex += 4;  
      }
      else {
        currentCharIndex += 4;  
      }
    }
    else {
      char currentChar = receivedText.charAt(currentCharIndex);  
      currentChar = toupper(currentChar);  // 대소문자 구분 없이 대문자로 변환 
      
      // 영어 출력
      if (currentChar >= 'A' && currentChar <= 'Z') {
        int index = currentChar - 'A'; 
        displayBraille(alphabetBraille[index]); 
        Serial.println("Braille for alphabet displayed");
        delay(1000);  
        currentCharIndex++;  
      }
      //한글 출력
      else if (currentChar >= '0' && currentChar <= '9') {
        int index = currentChar - '0'; 
        displayBraille(numberBraille[index]);  
        Serial.println("Braille for number displayed");
        delay(1000); 
        currentCharIndex++; 
      }
      else {
        currentCharIndex++;  
      }
    }
  }
}




