#define inicio 4
#define arame 3
#define fim 5
#define ledverm 2
#define ledverd 1
#define buzzer 0
int estado = LOW;

void setup() {
  pinMode(inicio, INPUT);
  pinMode(arame, INPUT);
  pinMode(fim, INPUT);
  pinMode(ledverm, OUTPUT);
  pinMode(ledverd, OUTPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite(ledverm, LOW);
  digitalWrite(ledverd, LOW);
}

void loop() {
  if (digitalRead(arame) == HIGH && estado == HIGH) {
    digitalWrite(ledverm, HIGH);
    tone(buzzer, 1109);
    delay(1000);
    noTone(buzzer);
    estado = LOW;
  }

  if (digitalRead(inicio) == HIGH) {
    estado = HIGH;
    digitalWrite(ledverm, LOW);
    digitalWrite(ledverd, HIGH);
    delay(500);
    digitalWrite(ledverd, LOW);
  }

  if (digitalRead(fim) == HIGH && estado == HIGH) {
    digitalWrite(ledverd, HIGH);
    tone(buzzer, 880, 150);
    delay(300);
    tone(buzzer, 1109, 150);
    delay(300);
    tone(buzzer, 1175, 150);
    estado = LOW;
  }
  delay(10);
}
