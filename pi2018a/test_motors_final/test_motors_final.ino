/////////////////////////////////////////////////////////////
///                                                       ///
///                     C O N T A N T E S                 ///
///                                                       ///
/////////////////////////////////////////////////////////////

//Motor 01 - Direção
  //Ativo em nivel Alto - Motor 01 - Sentido Horario
  #define M1HOR 4

  //Ativo em nivel Alto - Motor 01 - Sentido Anti-horario
  #define M1ANT 5


//Motor 02 - Tração
  //Ativo em nivel Alto - Motor 02 - Sentido Horario
  #define M2HOR 6
  
  //Ativo em nivel Alto - Motor 02 - Sentido Anti-horario
  #define M2ANT 7


//Bluetooth
  //Pino TX do modulo bluetooth
  #define BTX 1
  
  //Pino TX do modulo bluetooth
  #define BRX 2
  



/////////////////////////////////////////////////////////////
///                                                       ///
///                          S E T U P                    ///
///                                                       ///
/////////////////////////////////////////////////////////////

void setup() {

  pinMode(M1HOR, OUTPUT);                     // Define pino como saída

  pinMode(M1ANT, OUTPUT);                     // Define pino como saída             

  pinMode(M2HOR, OUTPUT);                     // Define pino como saída

  pinMode(M2ANT, OUTPUT);                     // Define pino como saída

  pinMode(BTX,   OUTPUT);                     // Define pino como saída
  
  pinMode(BRX,    INPUT);                     // Define pino como entrada
  
  
  Serial.begin(9600);                          // Inicia Monitoramento por barramento na velocidade 9600
  

  preset();                                   // Define STATUS para todos os pinos usados
  
} //end setup()


void preset(){
  
  digitalWrite(M1HOR, LOW);                   // Atribui nivel baixo para o pino
  
  digitalWrite(M1ANT, LOW);                   // Atribui nivel baixo para o pino
  
  digitalWrite(M2HOR, LOW);                   // Atribui nivel baixo para o pino
  
  digitalWrite(M2ANT, LOW);                   // Atribui nivel baixo para o pino

  
} //end reset()


void reset(char modulo){
  
  if(modulo == 'D'){
                                                //RESET para os controles de DIREÇÃO
    digitalWrite(M1HOR, LOW);                   // Atribui nivel baixo para o pino
  
    digitalWrite(M1ANT, LOW);                   // Atribui nivel baixo para o pino
    
  } // end if(D)
  
  
  if(modulo == 'T'){
                                                //RESET para os controles de TRAÇÃO
    digitalWrite(M2HOR, LOW);                   // Atribui nivel baixo para o pino
  
    digitalWrite(M2ANT, LOW);                   // Atribui nivel baixo para o pino
    
  } // end if(T)
  
  
  if(modulo != 'D' and modulo != 'T'){
                                                //RESET para todos os controles
    digitalWrite(M1HOR, LOW);                   // Atribui nivel baixo para o pino
  
    digitalWrite(M1ANT, LOW);                   // Atribui nivel baixo para o pino
 
    digitalWrite(M2HOR, LOW);                   // Atribui nivel baixo para o pino
  
    digitalWrite(M2ANT, LOW);                
  
    
  } // endif All
  
} //end reset()


/////////////////////////////////////////////////////////////
///                                                       ///
///                     C O N T R O L E S                 ///
///                                                       ///
/////////////////////////////////////////////////////////////

void setDirecao(int sentido = 0){
  // Espera 4 ← para virar a esquerda
  // Espera 6 → para virar a direita
  
  // Qualquer outro valor leva para leva a direção para frente
  
  if(sentido == 6){
    reset('D');
    digitalWrite(M1ANT, HIGH); 
  }
  
  else if(sentido == 4){
    reset('D');
    digitalWrite(M1HOR, HIGH);
  }
  
  else{
    reset('D');
  }
  
} // end setDirecao()


void setTracao(int sentido = 0){
  // Espera 8 ↑ para drive
  // Espera 2 ↓ para reverse
  
  // Qualquer outro valor NÃO traciona o veículo
  
  if(sentido == 8){
    reset('T');
    digitalWrite(M2ANT, HIGH); 
  }
  
  else if(sentido == 2){
    reset('T');
    digitalWrite(M2HOR, HIGH);
  }
  
  else{
    reset('T');
  }
  
} // end setTracao()


/////////////////////////////////////////////////////////////
///                                                       ///
///                         M A I N                       ///
///                                                       ///
/////////////////////////////////////////////////////////////


void loop() {

  setTracao(8);
  delay(2000);

  setDirecao(6);
  delay(2000);

  setDirecao(4);
  delay(2000);
  
  setTracao(2);
  delay(2000);

  setDirecao(6);
  delay(2000);

  setDirecao(4);
  delay(2000);
    
  reset(' ');
  
  delay(4000);
  
} //end loop()


