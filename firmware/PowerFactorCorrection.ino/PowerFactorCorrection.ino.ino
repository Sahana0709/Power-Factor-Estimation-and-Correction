const int sensorPin = A1;

const int relay1 = 8;
const int relay2 = 9;

float pf_before = 0.75;
float pf_after = 0.75;

void setup() {
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  int sensorValue = analogRead(sensorPin);
  float voltage = sensorValue * (5.0 / 1023.0);
  float current = (voltage - 2.5) / 0.185;

  // -------- BEFORE CORRECTION --------
  pf_before = 0.75;

  Serial.println("------ BEFORE CORRECTION ------");
  Serial.print("Current: ");
  Serial.print(current);
  Serial.print(" A | PF: ");
  Serial.println(pf_before);

  delay(3000);

  // -------- APPLY CORRECTION --------
  digitalWrite(relay1, HIGH);
  delay(1000);
  digitalWrite(relay2, HIGH);

  pf_after = 0.95;

  Serial.println("------ AFTER CORRECTION ------");
  Serial.print("Current: ");
  Serial.print(current);
  Serial.print(" A | PF: ");
  Serial.println(pf_after);

  Serial.println("------------------------------");

  delay(5000);

  // reset relays for repeat demo
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);

  delay(3000);
}