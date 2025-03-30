int ledState = HIGH;
int buttonState;
int lastButtonState = LOW;
const int buttonPin = 7;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
int reading;
int valor = 0;
int botao = LOW;
void setup()
{
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(7, INPUT_PULLUP);
  Serial.begin(9600);
  randomSeed(analogRead(0));
}
void loop()
{
  reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }
  //botao = digitalRead(buttonPin);
  //Serial.println(buttonState);
  if(buttonState == HIGH){
  	valor = random(31);
   // Serial.println(valor, BIN);
    for (int i = 0; 4; i++){
      	//Serial.println(i);
    	int bit = bitRead(valor, i);
      	if(bit == 1){
      		digitalWrite(8+i, HIGH);}
      	else{
          digitalWrite(8+i, LOW);}}}
          
lastButtonState = reading;

}