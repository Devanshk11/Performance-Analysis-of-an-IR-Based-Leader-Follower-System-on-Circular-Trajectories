

const int SENSOR_LEFT_PIN = A0; 

const int SENSOR_RIGHT_PIN = A3;
 


const int L_PWM = 10; 

const int L_DIR = 16; 

const int R_PWM = 9; 

const int R_DIR = 15;
 

const int BASE_SPEED = 26;

const int MAX_SPEED = 100;

const float Kp = 0.8; 

int currentLeftSpeed = 0;
int currentRightSpeed = 0;

const int DECELERATION = 15;
 
void setup() {

  Serial.begin(9600);
 

  pinMode(L_PWM, OUTPUT);

  pinMode(L_DIR, OUTPUT);

  pinMode(R_PWM, OUTPUT);

  pinMode(R_DIR, OUTPUT);

  pinMode(SENSOR_LEFT_PIN, INPUT_PULLUP);
  pinMode(SENSOR_RIGHT_PIN, INPUT_PULLUP);
 
//  Beep

  tone(6, 500, 200);

  delay(1000);

}
 
void loop() {

  int leftVal = analogRead(SENSOR_LEFT_PIN);

  int rightVal = analogRead(SENSOR_RIGHT_PIN);

  
  Serial.println("Left:");
  Serial.print(leftVal);
  Serial.print("  Right:");
  Serial.print(rightVal);



  int total = leftVal + rightVal;

  Serial.print("  TOTAL:");
  Serial.print(total);
 

 
  if (total > 1930) {

    if (currentLeftSpeed > 0) currentLeftSpeed -= DECELERATION;
    if (currentLeftSpeed < 0) currentLeftSpeed += DECELERATION;

    if (currentRightSpeed > 0) currentRightSpeed -= DECELERATION;
    if (currentRightSpeed < 0) currentRightSpeed += DECELERATION;

    
    if (abs(currentLeftSpeed) < DECELERATION) currentLeftSpeed = 0;
    if (abs(currentRightSpeed) < DECELERATION) currentRightSpeed = 0;

    setMotors(currentLeftSpeed, currentRightSpeed);
    return;
  }
  

  else {



    int error = leftVal - rightVal;

    int turnAdjustment = error * Kp;
 
    int leftSpeed = BASE_SPEED + turnAdjustment;

    int rightSpeed = BASE_SPEED - turnAdjustment;
 


    if (leftSpeed > MAX_SPEED) leftSpeed = MAX_SPEED;

    if (leftSpeed < -MAX_SPEED) leftSpeed = -MAX_SPEED;

    if (rightSpeed > MAX_SPEED) rightSpeed = MAX_SPEED;

    if (rightSpeed < -MAX_SPEED) rightSpeed = -MAX_SPEED;
 
    setMotors(leftSpeed, rightSpeed);

  }

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
 