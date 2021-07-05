const int pinBoton = 2;
const unsigned long TIEMPO_ENCENDIDO = 5000;
int contadorBoton = 0;
bool estadoLed = true;
bool estadoBoton = false;
bool estadoAnterior = false;
unsigned long t;

void botonContador();

void setup()
{
  Serial.begin(9600);
  pinMode(pinBoton, INPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  botonContador();
  comportamientoValvula();
}

void comportamientoValvula(){
  if(contadorBoton == 0){
    digitalWrite(13, 0); 
    t = millis();
  }else{
    digitalWrite(13, 1);
    
    if(millis() - t >= TIEMPO_ENCENDIDO){
      contadorBoton++;
      t = millis();
    }
  }
}

void botonContador(){
  estadoBoton = digitalRead(pinBoton);
  
  if(estadoBoton && !estadoAnterior){
    contadorBoton++;
    estadoAnterior = estadoBoton;  
  }else if(!estadoBoton && estadoAnterior){
    estadoAnterior = estadoBoton;
  }
  
  if(contadorBoton > 1){
    contadorBoton = 0;
  }
}
