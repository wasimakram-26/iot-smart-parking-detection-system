#define trigPin 9
#define echoPin 10

#define greenLED 6
#define redLED 7

long duration;
int distance;

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if(distance < 10) {

    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);

  }
  else {

    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);

  }

  delay(500);
}
