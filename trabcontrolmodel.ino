int x = 0;
int garfield = 0;
unsigned long tempoEstabiliza;
unsigned long tempoConta;
unsigned long tempoConta2;
unsigned long CQaQ;
unsigned long tempoParada;
bool terminou = false;
int ciclos = 0;

void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT); // ponte h (entrada motor)
  pinMode(8, OUTPUT); // ponte h (enable)
  digitalWrite(8, HIGH); 
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), conta, RISING);
  attachInterrupt(digitalPinToInterrupt(3), conta2, FALLING);
  analogWrite(9, 255); // Velocidade máxima
  tempoEstabiliza = millis();

}

void conta() {
  tempoConta = millis();
  x++;
}

void conta2() {
  tempoConta2 = millis();
}

void loop() {
  

  if ((millis() - tempoEstabiliza > 10000) && (garfield == 0) {
    tempoParada = millis();
    Serial.println("Parou");
    analogWrite(5, 0); // Para o motor
    garfield = 1;
  }
  
  if ((millis() - tempoConta > 100) && garfield == 1) { // Exemplo de tempo para validar evento
    CQaQ = tempoConta - tempoParada;
    Serial.print("Tempo desde a parada: ");
    Serial.println(CQaQ);
    garfield = 0;
  }

}




