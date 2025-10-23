const int Sensor = 7;
const int ledPin = 13;
const int ledPin2= 12;
const int ledPin3= 11;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3,OUTPUT);
}

void loop() {
  long duration, cm;

  pinMode(Sensor, OUTPUT);
  digitalWrite(Sensor, LOW);
  delayMicroseconds(2);
  digitalWrite(Sensor, HIGH);
  delayMicroseconds(5);
  digitalWrite(Sensor, LOW);
  pinMode(Sensor, INPUT);
  duration = pulseIn(Sensor, HIGH);

  cm = microsecondsToCentimeters(duration);

  Serial.print("Distance: ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  if (cm <= 100) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    Serial.println("Nivel PELIGROSO - ALERTA ROJA");
  } 
  else if (cm > 100 && cm < 200) {
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
    Serial.println("Nivel MEDIO - Precaución");
  } 
  else if (cm >= 200 && cm < 300) {
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, HIGH);
    Serial.println("Nivel NORMAL - Flujo estable");
  } 
  else {
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    Serial.println("Sin lectura válida o fuera de rango...");
  }

  Serial.println("--------------------------------");
  delay(1000);
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
