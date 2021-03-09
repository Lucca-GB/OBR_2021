#define echo 52
#define trig 53
#define velocidade_motor 3
#define mla 4 
#define mlb 5
#define mlc 6
#define mld 7

#define tempo 1500
int vel = 0;

unsigned tempos;
double distancia;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  Serial.begin(9600);

  digitalWrite(trig, LOW);

  pinMode(velocidade_motor,OUTPUT);
  pinMode(mla,OUTPUT);
  pinMode(mlb,OUTPUT);
  pinMode(mlc, OUTPUT);
  pinMode(mld, OUTPUT);
  digitalWrite(mla,LOW);
  digitalWrite(mlb,LOW);
  digitalWrite(mlc,LOW);
  digitalWrite(mld,LOW);
  analogWrite(velocidade_motor, vel);
}

void loop() {
  vel = 255;
  
  if(distancia < 15){
  analogWrite(velocidade_motor, vel);

  digitalWrite(mla,HIGH);
  digitalWrite(mlb,HIGH);
  digitalWrite(mlc,LOW);
  digitalWrite(mld,LOW);
  delay (tempo);

  digitalWrite(mla,LOW);
  digitalWrite(mlb,LOW);
  digitalWrite(mlc,HIGH);
  digitalWrite(mld,HIGH);
  delay (tempo);


  digitalWrite(mla,HIGH);
  digitalWrite(mlb,LOW);
  digitalWrite(mlc,LOW);
  digitalWrite(mld,HIGH);
  delay(tempo);
  }
  
  
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  tempos = pulseIn(echo, HIGH);

  distancia = tempos/58;

  Serial.println(distancia);

  delay(500);

}
