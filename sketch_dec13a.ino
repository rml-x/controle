int x = 0;
int garfield = 0;
unsigned long tempoEstabiliza;
unsigned long tempoConta;
unsigned long tempoLigou;
unsigned long tempoPartida;
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

  analogWrite(9, 0); // Motor inicialmente desligado
  tempoEstabiliza = millis();
}

void conta() {
  tempoConta = millis();
  x++;
}

void conta2() {
  // Função não utilizada, mas mantida para consistência
}

void loop() {
  if (ciclos < 5) {  
    if ((millis() - tempoEstabiliza > 1000) && (garfield == 0)) {
      Serial.println("Ligou");
      analogWrite(9, 255); // Liga o motor
      tempoPartida = millis();
      garfield = 1; // Motor ligado
    }

    // Calcula o tempo desde a partida
    if (garfield == 1 && (millis() - tempoPartida > 100)) { 
      tempoLigou = tempoConta - tempoPartida;
      Serial.print("Ciclo ");
      Serial.print(ciclos + 1);
      Serial.print(": Tempo para ligar (tempoLigou): ");
      Serial.println(tempoLigou);

      garfield = 0;
      ciclos++;  

      analogWrite(9, 0); // Desliga o motor
      Serial.println("Desligado");
     
      tempoEstabiliza = millis(); // Reinicia o tempo de espera para o próximo ciclo
    }
  } else {
    // Após 5 ciclos, desliga o motor e termina
    analogWrite(9, 0); 
    Serial.println("ACABOU!!!!!!!");
    while (true); 
  }
}
