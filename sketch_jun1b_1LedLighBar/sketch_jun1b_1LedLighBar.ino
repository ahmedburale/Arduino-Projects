
/*
The sketch sets the pins connected to the LEDs as outputs, and then defines a function to turn all the LEDs off at the same time. 
This function is called in the loop cycle to turn the LEDs off, and then the LEDs are turned on one at a time - a 200-millisecond delay between each one - to create a sweeping effect. 
Another loop seconds 
*/
void setup() {
  // put your setup code here, to run once:
  for (int i = 2; i < 10; i++) { // Choose pins 2-9
    pinMode(i, OUTPUT); // Set the pins as output
  }
}

// Define function to turn off all LEDs at the same time 
void allLEDsOff(void) {
  for(int i = 2; i < 10; i++) {
    digitalWrite(i, LOW);
  }
}

// Switch on LEDs in sequence from left to right
void loop() {
  for(int i = 2; i < 10; i++) { // Run loop once for each LED
    allLEDsOff(); // Turn off all LEDs
    digitalWrite(i, HIGH); // Turn on current LED
    delay(200); // Delay of 200 ms, then repeat loop to move on to the next LED
  }
  for(int i = 9; i >= 2; i--) { // Light LEDs from right to left
    allLEDsOff(); 
    digitalWrite(i, HIGH); 
    delay(200); 
  }
}
