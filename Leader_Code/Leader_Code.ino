 
// LEADER ROBOT: 3 CIRCLE 
 
const int EMITTER_PIN = 11;
 

const int L_PWM = 10; 
const int L_DIR = 16; 
const int R_PWM = 9; 
const int R_DIR = 15;
 
void setup() {

  pinMode(11, INPUT);
  pinMode(L_PWM, OUTPUT);
  pinMode(L_DIR, OUTPUT);
  pinMode(R_PWM, OUTPUT);
  pinMode(R_DIR, OUTPUT);
 

  tone(6, 500, 200); 
  delay(1000);
  tone(6, 1000, 500);
}
 
void loop() {

  pinMode(11, OUTPUT);
  digitalWrite(11, LOW);
 

  // Experiment 1: The "wide" circle = 40 cm

  // setMotors(-25, -28); 

  // Experiment 2: The "medium" circle = 28 cm

    // setMotors(-25, -30);
 

  // Experiment 3: The "small" circle = 20.5 cm

  setMotors(-25, -32);

}
 

void setMotors(int leftSpeed, int rightSpeed) {
  // LEFT MOTOR
  if (leftSpeed >= 0) {
    digitalWrite(L_DIR, LOW);   // Forward
    analogWrite(L_PWM, leftSpeed);
  } else {
    digitalWrite(L_DIR, HIGH);  // Backward
    analogWrite(L_PWM, -leftSpeed); 
  }
 
  // RIGHT MOTOR
  if (rightSpeed >= 0) {
    digitalWrite(R_DIR, LOW);   // Forward
    analogWrite(R_PWM, rightSpeed);
  } else {
    digitalWrite(R_DIR, HIGH);  // Backward
    analogWrite(R_PWM, -rightSpeed); 
  }
}