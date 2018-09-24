
#include <SoftwareSerial.h>
SoftwareSerial mySerial(0, 1); // RX, TX
// ========================================================================================================
// --- Variáveis Globais --- 
int           rpm,distancia;
int           tracao    = 8;
double        andei;
volatile byte pulsos;
unsigned long timeold;

//Altere o numero abaixo de acordo com o seu disco encoder
unsigned int pulsos_por_volta = 20;

byte          command; // Nesta variavel sera guardado o byte enviado pelo aplicativo

// ========================================================================================================
// --- Interrupção ---
void contador()
{
  //Incrementa contador
  pulsos++;
  andei = 1.065 * pulsos;
}


// ========================================================================================================
// --- Configurações Iniciais ---
void setup()
{
  Serial.begin(115200);
  mySerial.begin(9600);
  pinMode(2, INPUT);
  pinMode(tracao, OUTPUT);
   
  
  //Interrupcao 0 - pino digital 2
  //Aciona o contador a cada pulso
  attachInterrupt(0, contador, RISING);
  pulsos    = 0;
  andei     = 0;
  distancia = 40;
  rpm       = 0;
  timeold   = 0;

  
} //end setup


// ========================================================================================================
// --- Loop Infinito ---
void loop()
{
    Serial.println(" esperando");
   if (mySerial.available()){
      Serial.println(" available");
      command = mySerial.read(); //Recebe o byte da serial
       Serial.println(" LEU");
       Serial.println(command);
      if (command == 1) {
        Serial.println(" ENTROU");
        //Atualiza contador a cada segundo
          while(andei < distancia)
          {
              //Desabilita interrupcao durante o calculo
              detachInterrupt(0);
              digitalWrite(tracao, HIGH);
              //Mostra o valor de RPM no serial monitor
              Serial.print("Pulsos = ");
              Serial.println(pulsos, DEC);
              Serial.println(andei);
              //Habilita interrupcao
              attachInterrupt(0, contador, RISING);
          }
          digitalWrite(tracao, LOW);
          Serial.print("Finalizou andando ");
          Serial.println(andei);
          delay(3000);
          //REINICIA O ANDAMENTO
          andei = 0;
          pulsos    = 0;
      }
   }
} //end loop
