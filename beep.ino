int button = 2;
int piezo = 8;
int led = 13;

void setup() {
    pinMode(piezo, OUTPUT);
    pinMode(led, OUTPUT);
}

void loop() {
    if (digitalRead(button)) {
        //digitalWrite(led, HIGH);
        digitalWrite(led, LOW);
        // beep 음을 0.5초간 발생시켜 주세요.
        tone(piezo, 1000, 500);

        delay(1000);
  
        // beep 음을 중단시켜 주세요.
        noTone(piezo);       
        
        digitalWrite(led, LOW);
        delay (200); 
    }
}
