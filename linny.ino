#define ena 5
#define enb 10
#define in1 6
#define in2 7
#define in3 8
#define in4 9
#define lir 11
#define rir 12

bool irl , irr;

void setup() {
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(lir, INPUT);
  pinMode(rir, INPUT);

 

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(ena, 128);
  analogWrite(enb, 128);
}

void loop() {
  irl = digitalRead(lir);
  irr = digitalRead(rir);
  Serial.print(irl);
  Serial.println(irr);
  
  if(irl == 0 && irr == 1){
    analogWrite(ena, 0);
    analogWrite(enb, 70);
    }

   else if(irl == 1 && irr == 0){
    analogWrite(ena, 70);
    analogWrite(enb, 0);
    } 

    else if(irl == 1 && irr == 1){
    analogWrite(ena, 70);
    analogWrite(enb, 70);
    }
}
