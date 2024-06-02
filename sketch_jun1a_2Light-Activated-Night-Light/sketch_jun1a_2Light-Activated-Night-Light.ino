int lightPin = A0; // Pin connected to the photoresistor 
int ledPin = 9;    // Pin connected to the LED, using a PWM pin

const int numReadings = 10;  // Number of readings for smoothing
int readings[numReadings];   // Array to store readings
int readIndex = 0;           // Current reading index
int total = 0;               // Total of all readings
int average = 0;             // Average of the readings

void setup() {
  Serial.begin(9600); // Begin serial communication 
  pinMode(ledPin, OUTPUT); // Set the LED pin as an output
  
  // Initialize all readings to 0
  for (int i = 0; i < numReadings; i++) {
    readings[i] = 0;
  }
}

void loop() {
  // Subtract the last reading
  total = total - readings[readIndex];
  
  // Read the current value from the photoresistor
  readings[readIndex] = analogRead(lightPin);
  
  // Add the reading to the total
  total = total + readings[readIndex];
  
  // Advance to the next position in the array
  readIndex = readIndex + 1;
  
  // If we're at the end of the array, wrap around to the beginning
  if (readIndex >= numReadings) {
    readIndex = 0;
  }
  
  // Calculate the average
  average = total / numReadings;
  
  // Write the average value to the Serial Monitor for debugging
  Serial.println(average);
  
  // Map the average sensor value to a range of 0-255 for PWM control
  int ledBrightness = map(average, 0, 1023, 0, 255);
  
  // Send the mapped value to the ledPin
  analogWrite(ledPin, ledBrightness);
  
  // Short delay before the sequence loops again
  delay(100); // Increased delay to stabilize the reading
}
