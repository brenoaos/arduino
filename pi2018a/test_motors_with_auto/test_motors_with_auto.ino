//Testando a implementação da eletronica para controlar motores
//Teste será realizado com botões que irão setar o sentido de giro dos motores


//////////////////////////////////////////
///                                    ///
///          Variaveis Globais         ///
///                                    ///
//////////////////////////////////////////

  #define outM1Horario 4
  #define outM1Antihorario 5
  #define outM2Horario 6
  #define outM2Antihorario 7

  #define inpM1Horario 8
  #define inpM1Antihorario 9
  #define inpM2Horario 10
  #define inpM2Antihorario 11


void setup(){

//////////////////////////////////////////
///                                    ///
///            Conf Iniciais           ///
///                                    ///
//////////////////////////////////////////


  //Outputs
  pinMode(outM1Horario, OUTPUT);
  pinMode(outM1Antihorario, OUTPUT);
  pinMode(outM2Horario, OUTPUT);
  pinMode(outM2Antihorario, OUTPUT);


  //Imputs
    pinMode(inpM1Horario, INPUT);
    pinMode(inpM1Antihorario, INPUT);
    pinMode(inpM2Horario, INPUT);
    pinMode(inpM2Antihorario, INPUT);


 //Monitor
   Serial.begin(9600);

}

void loop(){
     digitalWrite(outM1Horario, HIGH);
      digitalWrite(outM1Horario, LOW);
delay(5000);
     digitalWrite(outM1Antihorario, HIGH);
     digitalWrite(outM1Horario, LOW);

delay(5000);


     digitalWrite(outM1Horario, HIGH);
}



void teste(){
  Serial.println("Escutado...");
  
  if(digitalRead(inpM1Horario) == HIGH){
    digitalWrite(outM1Horario, HIGH);
    Serial.println("primeiro...");
  }
  else if(digitalRead(inpM1Antihorario) == HIGH){
         digitalWrite(outM1Antihorario, HIGH);
          Serial.println("segundo...");
  }
    
  else if(digitalRead(inpM2Horario) == HIGH){
         digitalWrite(outM2Horario, HIGH);
         Serial.println("terceiro...");
  } 
  
  else if(digitalRead(inpM2Antihorario) == HIGH){
         digitalWrite(outM2Antihorario, HIGH);
         Serial.println("quarto...");
 
  }
  else{

    digitalWrite(outM1Horario, LOW);
    digitalWrite(outM1Antihorario, LOW);
    digitalWrite(outM2Antihorario, LOW);
    digitalWrite(outM2Horario, LOW);
  }
    
 

}




