/* Water Sensor

   GitHub URL - https://github.com/narayanvyas/Water-Level-Sensor-With-Arduino

   Developed By Web Dev Fusion

   Components
   ----------
    - Arduino Uno R3
    - Water Level Sensor
    - Two LEDs
    - Two 220 Ohm Resistors
    - A Buzzer
    - PCB
    - Wires

   Connections
   -----------
        Break out          |     Arduino Uno
   --------------------------------------------
        Water Sensor VCC     |          5V
        Water Sensor GND     |          GND
        Water Sensor Output  |          A5
        Buzzer GND           |          GND
        Buzzer OUT           |          2
        LED 1 OUT            |          3
        LED 2 OUT            |          4

     Also connect LEDs to 220 Ohm Resistors.

         ----/\/\/\/\----(LED |)----GND
*/

int sensorValue;
int buzzerPin = 2;
int greenLED = 3;
int redLED = 4;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  Serial.println("Water Sensor Project");
  digitalWrite(greenLED, HIGH);
  digitalWrite(greenLED, LOW);
}

void loop() {
  sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  if (sensorValue > 200) {
    tone(buzzerPin, 1000);
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);

  }
  else {
    noTone(buzzerPin);
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
  }
  delay(400);
}
