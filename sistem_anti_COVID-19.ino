/*  
   UNTUK ATOMISASI GERBANG PENYEMPROT DISENFEKTAN
   create by : Bagus Miftah Rizqullah
   Bahan yg di perlukan
   1. Arduino uno
   2. Sensor PIR (sensor pergerakan)
   3. Relay 1 chanel (benda ini menyesuaikan jumlah pompa yang digunakan)
   4. Pompa air 100v (1 buah)
   5. Niat Untuk NKRI, Bismillah......
   6. Tinggal copas dan Upload :V

   Jangan lupa like nya yaaa,:* 
*/
 
int led = 13;                // the pin that the LED is atteched to
int sensor = 2;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)
const int pinRelay = 11;   // definisikan Relay pada pin digital 11

void setup() {
  // CODINGAN SENSOR PIR AKTIF
  pinMode(led, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  Serial.begin(115200);        // initialize serial
   // CODINGAN RELAY aktif
  pinMode(pinRelay,OUTPUT);          // definisikan keluaran
  Serial.begin(115200);        // initialize serial
}

void loop(){
  val = digitalRead(sensor);   // read sensor value
  if (val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(led, HIGH);   // turn LED ON
    digitalWrite(pinRelay,HIGH); // nyalain relay
    delay(0);                // delay 100 milliseconds
    
    
    if (state == LOW) {
      Serial.println("TERDETEKSI PERGERAKAN !!!"); 
      state = HIGH;       // update variable state to HIGH
    }
  } 
  else {
      digitalWrite(led, LOW); // turn LED OFF
      digitalWrite(pinRelay,LOW); // matikan relay
      delay(0);             // delay 200 milliseconds 
      
      if (state == HIGH){
        Serial.println("TIDAK ADA PERGERAKAN !!!");
        state = LOW;       // update variable state to LOW
    }
  }
}
