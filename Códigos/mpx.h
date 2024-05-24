int sensorPin = A0;                                                                                    
int sensorValue = 0;                                                                                    
float Vout, Value_Kpa, Value_mmHg;
float OffSet = 1.08;                                                                                  
//------------------------------------------------------------------------------------------------       
void setup() {
  Serial.begin(9600);
}
//------------------------------------------------------------------------------------------------    
void loop() {
  sensorValue = analogRead(sensorPin);
  Vout = (sensorValue * 0.00459);           
  Value_Kpa = (Vout - 0.2)/0.09;
  Value_Kpa = Value_Kpa * OffSet;
  Value_mmHg = Value_Kpa * 7.50061;                                                                    

  if(Value_Kpa < 0) Value_Kpa = 0, Value_mmHg = 0;         

  Serial.print(Value_Kpa, 0);
  Serial.println(" Kpa ");

  Serial.print(Vout);
  Serial.println(" V ");

  Serial.print(Value_mmHg, 0);
  Serial.println(" mmHg ");
  delay(500);

}