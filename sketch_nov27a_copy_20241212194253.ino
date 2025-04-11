int x = 0;
int garfield = 0;
unsigned long tempoEstabiliza;
unsigned long tempoConta;
unsigned long tempoConta2;
unsigned long CQaQ;
unsigned long tempoParada;
int ciclos = 0;

void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT); // Ponte H (entrada motor)
  pinMode(8, OUTPUT); // Ponte H (enable)
  digitalWrite(8, HIGH); 
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(2), conta, RISING);
  attachInterrupt(digitalPinToInterrupt(3), conta2, FALLING);
  
  analogWrite(5, 255); 
  tempoEstabiliza = millis();
}

void conta() {
  tempoConta = millis();
  x++;
}

void conta2() {
  
}

void loop() {
  if (ciclos < 5) {  
    // Verifica se passou 10 segundos e para o motor
    if ((millis() - tempoEstabiliza > 10000) && (garfield == 0)) {
      tempoParada = millis();
      Serial.println("Parou");
      analogWrite(5, 0); // Para o motor
      garfield = 1; // Motor desligado
    }

    // Calcula o tempo desde a parada
    if (garfield == 1) { 
      CQaQ = tempoParada - tempoConta ;  
      Serial.print("Ciclo ");
      Serial.print(ciclos + 1);
      Serial.print(": Tempo desde a parada (CQaQ): ");
      Serial.println(CQaQ);
     
      garfield = 0;
      ciclos++;  
      
      delay(2000); 
      Serial.println("ligado novamente");
      analogWrite(5, 255); 
      tempoEstabiliza = millis(); // Reinicia o tempo de estabilização para o próximo ciclo
    }
  } else {
    // Após 5 ciclos, desliga o motor e termina
    analogWrite(5, 0); 
    Serial.println("ACABOU!!!!!!!");
    while (true); 
  }
}
