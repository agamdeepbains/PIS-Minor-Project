int trigPin1=2;
int echoPin1=3;
int TouchSensor = 4;
int pot_pin1 = A0;   // Initializing the Potentiometer pin
int pot_pin2 = A1;
int pot_output1 ;     // Declaring a variable for potentiometer output
int pot_output2 ; 



void setup()
{
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT );
  pinMode(echoPin1, INPUT  );
  pinMode(TouchSensor, INPUT);
}

void loop() {
  long duration1, distance1;
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1/2) / 29.1;

   if ((distance1 >= 0) && (distance1 <= 20)){
    Serial.print("U/");
   }   
   else if ( (distance1 >= 20) && (distance1 <= 40))
   {
    Serial.print("D/");
   }
  
  else {
    Serial.print("N/");
    
  }
  delay(10);
  
  if(digitalRead(TouchSensor)==HIGH)       //Read Touch sensor signal
   { 
    
    Serial.print("F/");
   }
  else
   {
    
    Serial.print(" /");
   }
  delay(10); // Slow down the output for easier reading
 
 pot_output1 = analogRead (pot_pin1); // Reading from the potentiometer
int mapped_output1 = map (pot_output1, 0, 1023, -100, 100); // Mapping the output of potentiometer to 0-255 to be read by the Processing IDE 

Serial.print(mapped_output1); 
Serial.print("/");
  delay(10);
  
 pot_output2 = analogRead (pot_pin2); // Reading from the potentiometer
int mapped_output2 = map (pot_output2, 0, 1023, -100, 100); // Mapping the output of potentiometer to 0-255 to be read by the Processing IDE 

Serial.print(mapped_output2); 
Serial.println("");
  delay(10);

}
