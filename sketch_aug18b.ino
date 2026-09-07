// SIT210/730 - Task 1.1P
// Switching ON Lights using Modular Programming


// ---------- Pin Definitions ----------
const int buttonPin = 2;

const int porchLight = 12;
const int hallwayLight = 11;


// ---------- Timing ----------
const unsigned long porchDuration = 30000;      // 30 seconds
const unsigned long hallwayDuration = 60000;   // 60 seconds


// ---------- Function Prototypes ----------
bool isButtonPressed();

void turnLightsOn();

void controlPorchLight();

void controlHallwayLight();

void turnLightsOff();


// Setup Function


void setup()
{
  Serial.begin(9600);

  // Set button as input using internal pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);

  // Set LEDs as outputs
  pinMode(porchLight, OUTPUT);
  pinMode(hallwayLight, OUTPUT);

  // Make sure lights start OFF
  turnLightsOff();

  Serial.println("Smart Lighting System Started");
}


// ==========================================
// Main Loop
// ==========================================

void loop()
{
  // Check whether button has been pressed
  if (isButtonPressed())
  {
    Serial.println("Button Pressed");

    // Turn both lights ON
    turnLightsOn();

    // Control porch light for 30 seconds
    controlPorchLight();

    // Control hallway light for remaining time
    controlHallwayLight();
  }
}


// Function: Check Button

bool isButtonPressed()
{
  // INPUT_PULLUP means LOW = button pressed

  if (digitalRead(buttonPin) == LOW)
  {
    delay(50); // Simple debounce

    if (digitalRead(buttonPin) == LOW)
    {
      return true;
    }
  }

  return false;
}


// Function: Turn Both Lights ON

void turnLightsOn()
{
  digitalWrite(porchLight, HIGH);
  digitalWrite(hallwayLight, HIGH);

  Serial.println("Porch and hallway lights ON");
}

// Function: Control Porch Light

void controlPorchLight()
{
  delay(porchDuration);

  digitalWrite(porchLight, LOW);

  Serial.println("Porch light OFF after 30 seconds");
}


// Function: Control Hallway Light

void controlHallwayLight()
{
  // Porch already stayed ON for 30 seconds.
  // Hallway needs total 60 seconds.
  // Therefore wait another 30 seconds.

  delay(hallwayDuration - porchDuration);

  digitalWrite(hallwayLight, LOW);

  Serial.println("Hallway light OFF after 60 seconds");
}


// Function: Turn Lights OFF


void turnLightsOff()
{
  digitalWrite(porchLight, LOW);
  digitalWrite(hallwayLight, LOW);
}