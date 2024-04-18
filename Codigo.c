#define MOTOR1_ENABLE 3
#define MOTOR1_IN1 4
#define MOTOR1_IN2 5
#define MOTOR2_ENABLE 6
#define MOTOR2_IN1 7
#define MOTOR2_IN2 8


#define BOTON_ADELANTE 9
#define BOTON_ATRAS 10
#define BOTON_IZQUIERDA 11
#define BOTON_DERECHA 12

int motorSpeed= 150; 
  
void setup() {
  
  pinMode(MOTOR1_ENABLE, OUTPUT);
  pinMode(MOTOR1_IN1, OUTPUT);
  pinMode(MOTOR1_IN2, OUTPUT);
  pinMode(MOTOR2_ENABLE, OUTPUT);
  pinMode(MOTOR2_IN1, OUTPUT);
  pinMode(MOTOR2_IN2, OUTPUT);

 
  pinMode(BOTON_ADELANTE, INPUT_PULLUP);
  pinMode(BOTON_ATRAS, INPUT_PULLUP);
  pinMode(BOTON_IZQUIERDA, INPUT_PULLUP);
  pinMode(BOTON_DERECHA, INPUT_PULLUP);
}

void loop() {
 
  int adelanteState = digitalRead(BOTON_ADELANTE);
  int atrasState = digitalRead(BOTON_ATRAS);
  int izquierdaState = digitalRead(BOTON_IZQUIERDA);
  int derechaState = digitalRead(BOTON_DERECHA);
  
  analogWrite(MOTOR1_ENABLE, motorSpeed);
  analogWrite(MOTOR2_ENABLE, motorSpeed);
  // adelante
  if (adelanteState == HIGH) {
    digitalWrite(MOTOR1_IN1, LOW);
    digitalWrite(MOTOR1_IN2, HIGH);
    digitalWrite(MOTOR1_ENABLE, HIGH);
    digitalWrite(MOTOR2_IN1, LOW);
    digitalWrite(MOTOR2_IN2, HIGH);
    digitalWrite(MOTOR2_ENABLE, HIGH);
  }
  // atras
  else if (atrasState == HIGH) {
    digitalWrite(MOTOR1_IN1, HIGH);
    digitalWrite(MOTOR1_IN2, LOW);
    digitalWrite(MOTOR1_ENABLE, HIGH);
    digitalWrite(MOTOR2_IN1, HIGH);
    digitalWrite(MOTOR2_IN2, LOW);
    digitalWrite(MOTOR2_ENABLE, HIGH);
  }
  // Izquierda
  else if (izquierdaState == HIGH) {
    digitalWrite(MOTOR1_IN1, HIGH);
    digitalWrite(MOTOR1_IN2, LOW);
    digitalWrite(MOTOR1_ENABLE, HIGH);
    digitalWrite(MOTOR2_IN1, LOW);
    digitalWrite(MOTOR2_IN2, HIGH);
    digitalWrite(MOTOR2_ENABLE, HIGH);
  }
  // derecha
  else if (derechaState == HIGH) {
    digitalWrite(MOTOR1_IN1, LOW);
    digitalWrite(MOTOR1_IN2, HIGH);
    digitalWrite(MOTOR1_ENABLE, HIGH);
    digitalWrite(MOTOR2_IN1, HIGH);
    digitalWrite(MOTOR2_IN2, LOW);
    digitalWrite(MOTOR2_ENABLE, HIGH);
  }
  // Stop
  else {
    digitalWrite(MOTOR1_ENABLE, LOW);
    digitalWrite(MOTOR2_ENABLE, LOW);
  }
}
