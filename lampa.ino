int pin1 = 19;
int pin2 = 23;
int pin3 = 22;
int buttonPin = 18;
int buttonState;
int intensitate = 0;
int lastButtonState = LOW;

void setup() {
  Serial.begin(115200);
  pinMode (pin1, OUTPUT);
  pinMode (pin2, OUTPUT);
  pinMode (pin3, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  lastButtonState = digitalRead(buttonPin);
}

void loop() 
{
buttonState = digitalRead(buttonPin);
if (buttonState == LOW && lastButtonState == HIGH) 
{
  intensitate = intensitate + 51;
  if(intensitate > 255)
  {
    intensitate = 0;
  }
analogWrite (pin1, intensitate);
analogWrite (pin2, intensitate);
analogWrite (pin3, intensitate);

}
lastButtonState = buttonState;
}