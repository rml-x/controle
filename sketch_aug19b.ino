#define motor1 6 // pino motor1 
#define motor2 5

// variaveis encoder
int encoder = 2; 
float v; // variavel da velocidade
int pulsos = 0; // pulsos contados
unsigned long time1 = millis(); // variavel tempo ms 


//variaveis de controle
float erro = 0;
float setpoint = 0;
float integral = 0;
float derivada = 0;
float erroant = 0;
float saida = 0;
float kp = 20;
float ki = 0;
float kd = 0;
float leitura = 0;

void setup() {
  Serial.begin(9600);// inicia o monitor serial

  pinMode(2,INPUT);// pino 2 entrada, por onde entra o sinal de leitura do encoder
  pinMode(6,OUTPUT); // entrada da ponte h
  pinMode(8,OUTPUT); // pino enable da ponte h

  attachInterrupt(digitalPinToInterrupt(3),pulse, RISING);// interrupção que ira ser ativada quando houver borda de subida e ativa a função equacao

  digitalWrite(8, HIGH);
  


}

void loop() {
  if (millis() - time1 > 1000){ // se o tempo decorrido menos o tempo inicial for maior que 1s ent aciona o if 
    v = (pulsos) * 10; // calculo da velocidade
    //Serial.println(v);// imprime o valor de v no monitor serial

    time1 = millis(); // atualiza o tempo atual 
    pulsos = 0; //zera o numero de pulsos para a nova iteração, se isso não fosse feito o valor de a cresceria sem parar e não nos daria leituras fieis  
    

  erro = setpoint - v; 
  saida = kp * erro + ki * (somaintregalerro);
  //Serial.print(erro);
  saida = constrain(saida, 0, 255);
  Serial.println(saida);
  analogWrite(6, saida);// manda um sinal pwm para a entrada da ponte h

  if (Serial.available() > 0) { // se serial esta disponivel ent 
    leitura = Serial.parseInt();// valor digitado é pego pela serial 
      if (leitura > 0){ // se o valor for valido
        setpoint = leitura;
        //Serial.print(sp);
        

      }
  }
    
  }
  }



void pulse() 
  {// função que incrementa +1 a variavel a toda vez que é chamada 
    pulsos++;

  }

