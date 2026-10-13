// Flex sensor voltage reader – Arduino Nano
const int FLEX_PIN = A4;    // analog input from the voltage divider
const int LED_PIN  = 2;     // LED on D2

const float VCC = 5.0;      // Nano reference voltage (use 3.3 for a Nano 33 board)
const float ADC_MAX = 1023.0;

float threshold = 2.5;      // volts – tune this after watching your readings

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int raw = analogRead(FLEX_PIN);
  float voltage = raw * (VCC / ADC_MAX);

  Serial.print("Raw:");
  Serial.print(raw);
  Serial.print("\tVoltage:");
  Serial.println(voltage, 3);

  digitalWrite(LED_PIN, voltage > threshold ? HIGH : LOW);

  delay(100);
}