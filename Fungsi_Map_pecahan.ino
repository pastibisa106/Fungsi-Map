void setup() {
  Serial.begin(9600);
  Serial.println("Fungsi map untuk bilangan pecahan/float");
//  https://www.semesin.com/project/2018/04/17/fungsi-map-untuk-bilangan-pecahan-float-pada-arduino/
}
 
void loop() {
  uint16_t adc = analogRead(A0);
 
//Range/bentang asal adc = 0..1023
//Range/bentang tujuan   = 87.00 - 108.00
 
  float x1 = map(adc, 0, 1023, 87 * 100, 108 * 100) / 100.0;
  float x2 = mapPecahan(adc, 0, 1023, 87, 108);
   
  Serial.print(adc); Serial.print(" => ");
  Serial.print(x1, 2);
  Serial.print(" == ");
  Serial.println(x2, 2);
  delay(100);
}
 
float mapPecahan(long x, long fromLow, long fromHigh, float toLow, float toHigh) {
  return (x - fromLow) * (toHigh - toLow) / (fromHigh - fromLow) + toLow;
}
