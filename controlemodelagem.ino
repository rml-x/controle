#define motor1 6 // pino motor1 
#define motor2 5

// variaveis encoder
int encoder = 2; 
float rpm; // variavel da velocidade
int pulsos = 0; // pulsos contados
unsigned long time1 = millis(); // variavel tempo ms 
int pulsospervolta = 6; 
unsigned long inicio = millis();
unsigned long fim = millis();
float tempo;
float mediatempo;
float somatempo;

//variaveis de controle
float erro = 0;
float setpoint = 290;
float integral = 0;
float derivada = 0;
float erroant = 0;
float saida = 0;
float kp = 0.2136;
float ki = 0.0374;
float kd = 0.1294;
float leitura = 0;

float w;



void contapulso()// função que incrementa +1 a variavel a toda vez que é chamada 
{
  pulsos++;
  
}

void setup() {
Serial.begin(9600); // inicia o monitor serial

pinMode(motor1,OUTPUT); 
pinMode(encoder,INPUT);
pinMode(8,OUTPUT); // pino enable da ponte h

digitalWrite(8,HIGH);

attachInterrupt(digitalPinToInterrupt(2),contapulso, RISING);// interrupção que ira ser ativada quando houver borda de descida e ativa a função contapulso
 pulsos = 0; // variaveis colocadas no setup para garantir que estarão zeradas na incialização
 rpm = 0;
 time1 = 0;

}

void loop() {
  
  /*if (Serial.available()>0) { // se serial esta disponivel
      leitura = Serial.parseInt(); // valor digitado é lido pela serial
     
       if (leitura > 0) { 
    setpoint = leitura; // definir o setpoint como o valor lido
    
  }
  }
  */
analogWrite(5,255);

if (millis() - time1 >= 1000){ //passado 1 segundo executa(ou a cada 1 segundo executa)

rpm = 60 * (pulsos / pulsospervolta); // calculo da velocidade se divide o numero de pulsos contados numa volta pelo numero de pulsos para se ter uma volta, apos isso multiplicamos o valor que esta em segundos por 60 e temos a velocidade em rpm
w = rpm * (3.14 / 30);
Serial.println(w);
 
time1 = millis();// atualiza o tempo atual do encoder
pulsos = 0; // zera os pulsos para a nova iteração, isso é feito para que o numero de pulsos não fique crescendo para sempre, isso nao nos daria o resultado desejado

/*erro = setpoint - rpm; //formula do erro, diferença entre setpoint e saida

integral = erro*ki + integral; 
derivada =(erroant - erro)*kd;
saida = kp * erro + integral +  derivada; // formula do controle pid
// kp vezes erro aq é a formula da proporcional

erroant = erro;


saida = constrain(saida, 0, 255);// limita os valores de saida entre 0 e 255*/
//analogWrite(5,255);//liga o motor1 de acordo com o valor pwm da saida:


//Serial.println(rpm);// printa o resultado



//Serial.println(mediatempo);
    
}


}
