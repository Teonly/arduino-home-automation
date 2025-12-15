
#include <SoftwareSerial.h> // biblioteca para que eu conseguisse ter maior controle da comunicação serial


SoftwareSerial BT(10, 11);  // adicionando o modulo bluetooth
String buffer = ""; // zera a variavel que vou usar pros comando




const int LED_QUARTO = 13; // configurando as portas ai
const int LED_SALA = 12;




const int VENT_PIN1 = 8;
const int VENT_PIN2 = 9;


void setup() {
  Serial.begin(9600);  // ligando as coisa
  BT.begin(38400);  // esse begin é o unico que funcionou no meu modulo


 
  pinMode(LED_QUARTO, OUTPUT); // configurando as porta
  pinMode(LED_SALA, OUTPUT);
  digitalWrite(LED_QUARTO, LOW);
  digitalWrite(LED_SALA, LOW);


 
  pinMode(VENT_PIN1, OUTPUT);
  pinMode(VENT_PIN2, OUTPUT);
  digitalWrite(VENT_PIN1, LOW);
  digitalWrite(VENT_PIN2, LOW);


  Serial.println("Sistema iniciado. Aguardando comandos por voz...");// pra saber se ta funcionando legal
}


void loop() {
 
  while (BT.available()) {
    char c = BT.read(); //le o comando
    buffer += c;
    Serial.print(c); // escreve oque ele recebeu, pra saber oque ele ta recebendo
  }


 
  String comando = buffer; // isso para o arduino não ficar ligado a comandos de duas palavras somente e consiga usar palavras chave
  comando.toLowerCase(); // deixa tudo minusculo
  comando.trim();


  bool comandoProcessado = false;


 
  while (comando.length() > 0) {
    bool encontrado = false;


   //estruturas separadas de ativar ou desativar as coisas de acordo com as palavras chaves recebidas 
    if ((comando.indexOf("quarto") >= 0) && 
        (comando.indexOf("ligar") >= 0 || comando.indexOf("acender") >= 0)) {
      digitalWrite(LED_QUARTO, HIGH);
      Serial.println("\n-> LED QUARTO ACESO");
      comando.replace("quarto", "");
      encontrado = true;
    } else if ((comando.indexOf("quarto") >= 0) &&
               (comando.indexOf("apagar") >= 0 || comando.indexOf("desligar") >= 0)) {
      digitalWrite(LED_QUARTO, LOW);
      Serial.println("\n-> LED QUARTO APAGADO");
      comando.replace("quarto", "");
      encontrado = true;
    }


   
    if ((comando.indexOf("sala") >= 0) &&
        (comando.indexOf("ligar") >= 0 || comando.indexOf("acender") >= 0)) {
      digitalWrite(LED_SALA, HIGH);
      Serial.println("\n-> LED SALA ACESO");
      comando.replace("sala", "");
      encontrado = true;
    } else if ((comando.indexOf("sala") >= 0) &&
               (comando.indexOf("apagar") >= 0 || comando.indexOf("desligar") >= 0)) {
      digitalWrite(LED_SALA, LOW);
      Serial.println("\n-> LED SALA APAGADO");
      comando.replace("sala", "");
      encontrado = true;
    }


   
    if ((comando.indexOf("ventilador") >= 0) &&
        (comando.indexOf("ligar") >= 0 || comando.indexOf("acender") >= 0)) {
      digitalWrite(VENT_PIN1, HIGH);
      digitalWrite(VENT_PIN2, LOW);
      Serial.println("\n-> VENTILADOR LIGADO"); //cansado dessa bomba não ligar :(
      comando.replace("ventilador", "");
      encontrado = true;
    } else if ((comando.indexOf("ventilador") >= 0) &&
               (comando.indexOf("apagar") >= 0 || comando.indexOf("desligar") >= 0)) {
      digitalWrite(VENT_PIN1, LOW);
      digitalWrite(VENT_PIN2, LOW);
      Serial.println("\n-> VENTILADOR DESLIGADO");
      comando.replace("ventilador", "");
      encontrado = true;
    }


    if (!encontrado) break;


    comandoProcessado = true;
  }


  if (comandoProcessado) {
    buffer = ""; //reseta o comando pra não dar ruim
  }
}//gg
