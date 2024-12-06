#include <Keypad.h>
#include <Servo.h>

// Serial data
String mensaje = "";

// servomotor
Servo servoGarage; // obejto servomotor
Servo servoPuerta;
int estadoGarage = 0; // estado del servomotor del garage
int estadoPuerta = 0;
int position = 0; // posicion del servomotor

// teclado matricial
const byte rowsCount = 4;   // no. de filas
const byte columsCount = 4; // no de columnas

String key = ""; // variable para la contraseña

// declaración del contenido de cada tecla
char keys[rowsCount][columsCount] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'#', '0', '*', 'D'}};

const byte rowPins[rowsCount] = {11, 10, 9, 8};    // pines de las filas
const byte columnPins[columsCount] = {7, 6, 5, 4}; // pines de las columnas

// creacion del objeto teclado
Keypad keypad = Keypad(makeKeymap(keys), rowPins, columnPins, rowsCount, columsCount);

void setup()
{
  Serial.begin(9600);
  servoGarage.attach(5);
  servoGarage.write(90);

  servoPuerta.attach(4);
  servoPuerta.write(90);
}

void loop()
{

  if (Serial.available() > 0)
  {
    mensaje = Serial.readStringUntil('\n');
    //Serial.println(mensaje);

    // ==== servo garage ====
    if (mensaje == "servoGarageOn")
    {
    }
    else if (mensaje == "servoGarageOff")
    {
      servoGarage.write(90);
    }

    // ==== servo puerta ====
    if (mensaje == "servoPuertaOn")
    {
      servoPuerta.write(90);
    }
    else if (mensaje == "servoPuertaOff")
    {
      servoPuerta.write(0);
    }
  }

  char cons = keypad.getKey(); // se obtine la tecla pulsada
  key += String(cons); // se concatena el contenido de las teclas pulsadas

  if (key.length() == 5)
  { // se verifica la extensión de la variable 'key'

    if (key == "12345")
    { // se verifica si la variable 'key' contiene '12345'
      estadoPuerta = 1;
      if (estadoPuerta == 1)
      { // se verifica que el estado del servo sea 1 (abierto)

        servoGarage.write(0); // se cierra el servo
        estadoPuerta = 0;     // se cambia el estado a 0 (cerrado)
        key = "";
        
        Serial.print('on');             
      }
      else if (estadoPuerta == 0)
      { // se verifica que el estado del servo sea 0 (cerrado)

        servoGarage.write(90);     // se abre el servo
        estadoPuerta = 1; // se cambia el estado a 1 (abierto)
        key = "";                  // se vacia key

        Serial.print('off');
      }
    }
  }  
}

/*void openGarageMAnually()
{
  char cons = keypad.getKey(); // se obtine la tecla pulsada

  key += String(cons); // se concatena el contenido de las teclas pulsadas

  if (key.length() == 5)
  { // se verifica la extensión de la variable 'key'

    if (key == "12345")
    { // se verifica si la variable 'key' contiene '12345'
      estadoPuerta = 1;
      if (estadoPuerta == 1)
      { // se verifica que el estado del servo sea 1 (abierto)

        servoGarage.write(0); // se cierra el servo
        estadoPuerta = 0;     // se cambia el estado a 0 (cerrado)
        key = "";
        
        Serial.print('on');             
      }
      else if (estadoPuerta == 0)
      { // se verifica que el estado del servo sea 0 (cerrado)

        servoGarage.write(90);     // se abre el servo
        estadoPuerta = 1; // se cambia el estado a 1 (abierto)
        key = "";                  // se vacia key

        Serial.print('off');
      }
    }
    else
    {
      
    }
  }
}*/
