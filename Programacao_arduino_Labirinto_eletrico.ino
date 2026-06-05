#define inicio 4
#define arame 3
#define fim 5
#define ledverm 2
#define ledverd 1
#define buzzer 0
int estado = LOW;


void setup( ) {
  pinMode(inicio, INPUT_PULLUP);
  pinMode(arame, INPUT_PULLUP);
  pinMode(fim, INPUT_PULLUP);
  pinMode(ledverm, OUTPUT);
  pinMode(ledverd, OUTPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite(ledverm, LOW);
  digitalWrite(ledverd, LOW);
}

void loop( ) {
  if(digitalRead(arame) == LOW && estado == LOW){
    digitalWrite(ledverm, HIGH);
    tone(buzzer, 1109);
    delay(1000);
    noTone(buzzer);
    estado = HIGH;
  }
  
  if(digitalRead(inicio) == LOW){
    estado = LOW;
    digitalWrite(ledverm, LOW);
    digitalWrite(ledverd, HIGH);
    delay(500);
    digitalWrite(ledverd, LOW);
  }
  
  if(digitalRead(fim) == LOW && estado == LOW){
    digitalWrite(ledverd, HIGH);
    tone(buzzer, 880, 150);
    delay(300);
    tone(buzzer, 1109, 150);
    delay(300);
    tone(buzzer, 1175, 150);
    estado = HIGH;
  }
  delay(10);
}
