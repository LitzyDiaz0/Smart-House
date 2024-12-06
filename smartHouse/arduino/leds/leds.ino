// mensaje del serial
String mensaje;

#define led_garage 13
#define led_cocina 12
#define led_bano 11
#define led_habitacion 10
#define ventilador 9
#define led_sala 8
// pines de los leds

// estado de los leds (1 = encendido, 0 = apagado)
int estado_habitacion = 0,
    estado_cocina = 0,
    estado_bano = 0,
    estado_sala = 0,
    estado_garage = 0,
    estado_ventilador = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(led_habitacion, OUTPUT);
  pinMode(led_cocina, OUTPUT);
  pinMode(led_bano, OUTPUT);
  pinMode(led_sala, OUTPUT);
  pinMode(led_garage, OUTPUT);
  pinMode(ventilador, OUTPUT);
}

void loop()
{
  if (Serial.available() > 0)
  {                                         // se verifica que el puerto este no este ocupado
    mensaje = Serial.readStringUntil('\n'); // se guarda en forma de string lo que haya en el puerto serial
    Serial.println("mensaje: " + mensaje);

    // ==== recamara =====
    if (mensaje == "ledRecamaraOn")
    {
      digitalWrite(led_habitacion, HIGH);
    }
    else if (mensaje == "ledRecamaraOff")
    {
      digitalWrite(led_habitacion, LOW);
    }

    // ==== cocina ====
    if (mensaje == "ledCocinaOn")
    {
      digitalWrite(led_cocina, HIGH);
    }
    else if (mensaje == "ledCocinaOff")
    {
      digitalWrite(led_cocina, LOW);
    }

    // ==== baño ====
    if (mensaje == "ledBanoOn")
    {
      digitalWrite(led_bano, HIGH);
    }
    else if (mensaje == "ledBanoOff")
    {
      digitalWrite(led_bano, LOW);
    }

    // ==== sala ====
    if (mensaje == "ledSalaOn")
    {
      digitalWrite(led_sala, HIGH);
    }
    else if (mensaje == "ledSalaOff")
    {
      digitalWrite(led_sala, LOW);
    }

    // ==== garage ====
    /*
    if (mensaje == "servoGarageOn")
    {
      digitalWrite(led_garage, HIGH);
    }
    else if (mensaje == "servoGarageOff")
    {
      digitalWrite(led_garage, LOW);
    }
    */
    if (mensaje == "ledGarageOn"){
      digitalWrite(led_garage, HIGH);
    }
    else if(mensaje == "ledGarageOff")
    {
      digitalWrite(led_garage, LOW);
    }

    // ==== ventilador ====
    if (mensaje == "ventiladorOn")
    {
      digitalWrite(ventilador, HIGH);
    }
    else if (mensaje == "ventiladorOff")
    {
      digitalWrite(ventilador, LOW);
    }
  }
}
