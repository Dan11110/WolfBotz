


#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Configurações do WiFi
const char* ssid = "SUA_REDE_WIFI";     // Nome da sua rede WiFi
const char* password = "SUA_SENHA_WIFI"; // Senha da sua rede WiFi

#define s_frontal A0
#define s_esq A1
#define s_dir A2
#define s_besq 2
#define s_bdir 3
#define microstart 4
#define m_pwmesq 5
#define m_pwmdir 6
#define m_esq_direcaoA 7
#define m_esq_direcaoB 8
#define m_dir_direcaoA 10
#define m_dir_direcaoB 9


// motor esquerdo
//direcao b== frente
//direcao a== tras

// motor direito
//direcao a== frente
//direcao b== tras

// os sensores de borda possuem logica invertida



void setup()
{

  pinMode(s_frontal, INPUT);  // frontal
  pinMode(s_esq, INPUT);  // esquerda
  pinMode(s_dir, INPUT);  // direita
  pinMode(s_besq, INPUT);   // borda esquerda
  pinMode(s_bdir, INPUT);   // borda direito 

  pinMode(microstart, INPUT);   // microstart  
  
  pinMode(m_pwmesq, OUTPUT);  // pwm a motor esquerdo
  pinMode(m_pwmdir, OUTPUT);  // pwm b motor direito 
  pinMode(m_esq_direcaoA, OUTPUT);  // in1a 
  pinMode(m_esq_direcaoB, OUTPUT);  // in2a
  pinMode(m_dir_direcaoA, OUTPUT);  // in1b
  pinMode(m_dir_direcaoB, OUTPUT); // in2b
  
  pinMode(13, OUTPUT); // led

  Serial.begin(9600);
}




  void frente(void){
  digitalWrite(m_esq_direcaoA, LOW);
  digitalWrite(m_esq_direcaoB, HIGH);
  digitalWrite(m_dir_direcaoA, HIGH);
  digitalWrite(m_dir_direcaoB, LOW);
  analogWrite(m_pwmesq, 76);
  analogWrite(m_pwmdir, 35);
  Serial.println("F");
  }

  void frente_full(void){
  digitalWrite(m_esq_direcaoA, LOW);
  digitalWrite(m_esq_direcaoB, HIGH);
  digitalWrite(m_dir_direcaoA, HIGH);
  digitalWrite(m_dir_direcaoB, LOW);
  analogWrite(m_pwmesq, 125); // diferença dos motores
  analogWrite(m_pwmdir, 90);
  Serial.println("FF");
  }
  
  void tras(void){
  digitalWrite(m_esq_direcaoA, HIGH);
  digitalWrite(m_esq_direcaoB, LOW);
  digitalWrite(m_dir_direcaoA, LOW);
  digitalWrite(m_dir_direcaoB, HIGH);
  analogWrite(m_pwmesq, 66);
  analogWrite(m_pwmdir, 45);
  Serial.println("T");
  }

  void esquerda(void){
  digitalWrite(m_esq_direcaoA, HIGH);
  digitalWrite(m_esq_direcaoB, LOW);
  digitalWrite(m_dir_direcaoA, HIGH);
  digitalWrite(m_dir_direcaoB, LOW);
  analogWrite(m_pwmesq, 66);
  analogWrite(m_pwmdir, 45);
  Serial.println("E");
  }

   void direita(void){
  digitalWrite(m_esq_direcaoA, LOW);
  digitalWrite(m_esq_direcaoB, HIGH);
  digitalWrite(m_dir_direcaoA, LOW);
  digitalWrite(m_dir_direcaoB, HIGH);
  analogWrite(m_pwmesq, 66);
  analogWrite(m_pwmdir, 45);
  Serial.println("D");
  }
  
  void parar(void){
  digitalWrite(m_esq_direcaoA, LOW);
  digitalWrite(m_esq_direcaoB, LOW);
  digitalWrite(m_dir_direcaoA, LOW);
  digitalWrite(m_dir_direcaoB, LOW);
  analogWrite(m_pwmesq, 0);
  analogWrite(m_pwmdir, 0);  
  }

  void borda_esquerda(void){
  parar();
  delay(200);
  tras(); 
  delay(200);
  direita();
  delay(400);
  frente();
  delay(100);
  Serial.println("BE");
  }

  void borda_direita(void){
  parar();
  delay(200);
  tras(); 
  delay(200);
  esquerda();
  delay(400);
  frente();
  delay(100);
  Serial.println("BD");
  }
  
void loop() 
{

 // if(digitalRead(microstart)){


 if(!digitalRead(s_besq)) {borda_esquerda(); digitalWrite(13,HIGH);}
 else if(!digitalRead(s_bdir)) {borda_direita(); digitalWrite(13,HIGH);}
 else {

  if(digitalRead(s_frontal)){
    frente_full();
    }
    else if(digitalRead(s_esq)){
        esquerda();
        //delay(500);
        if(digitalRead(s_frontal)){frente_full();}
      }
    else if(digitalRead(s_dir)){
      direita();
     // delay(500);
      if(digitalRead(s_frontal)){frente_full();}
      }
   else{
      frente();
    }
  }

delay(50);
//} 
//else parar();

}



