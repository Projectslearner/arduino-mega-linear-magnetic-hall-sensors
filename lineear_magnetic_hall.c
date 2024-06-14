/*
    Project name : Linear magnetic Hall sensors
    Modified Date: 14-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-mega-linear-magnetic-hall-sensors
*/

const int hallSensorPin = A0; // Analog pin connected to the Hall sensor
const int threshold = 512; // Threshold for magnetic field strength detection

void setup() {
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  int sensorValue = analogRead(hallSensorPin); // Read the value from the Hall sensor

  // Print the sensor value to the Serial Monitor
  Serial.print("Hall Sensor Value: ");
  Serial.println(sensorValue);

  // Check if the magnetic field is strong or weak
  if (isStrongMagneticField(sensorValue)) {
    Serial.println("Strong Magnetic Field Detected");
  } else {
    Serial.println("Weak Magnetic Field Detected");
  }

  // Add a small delay to avoid spamming the Serial Monitor
  delay(500);
}

bool isStrongMagneticField(int value) {
  return value > threshold;
}

bool isWeakMagneticField(int value) {
  return value <= threshold;
}
