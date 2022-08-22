//각 자동차가 수행할 동작의 함수들에 해당.

void forward(){
  digitalWrite(FB1,LOW);
  digitalWrite(FB2,HIGH);
  digitalWrite(FA1,HIGH);
  digitalWrite(FA2,LOW);
  digitalWrite(BB1,LOW);
  digitalWrite(BB2,HIGH);
  digitalWrite(BA1,HIGH);
  digitalWrite(BA2,LOW);
}

void backward(){
  digitalWrite(FB1,HIGH);
  digitalWrite(FB2,LOW);
  digitalWrite(FA1,LOW);
  digitalWrite(FA2,HIGH);
  digitalWrite(BB1,HIGH);
  digitalWrite(BB2,LOW);
  digitalWrite(BA1,LOW);
  digitalWrite(BA2,HIGH);
}

void turnleft(){
  digitalWrite(FB1,LOW);
  digitalWrite(FB2,HIGH);
  digitalWrite(FA1,LOW);
  digitalWrite(FA2,HIGH);
  digitalWrite(BB1,HIGH);
  digitalWrite(BB2,LOW);
  digitalWrite(BA1,HIGH);
  digitalWrite(BA2,LOW);
}

void turnright(){
  digitalWrite(FB1,HIGH);
  digitalWrite(FB2,LOW);
  digitalWrite(FA1,HIGH);
  digitalWrite(FA2,LOW);
  digitalWrite(BB1,LOW);
  digitalWrite(BB2,HIGH);
  digitalWrite(BA1,LOW);
  digitalWrite(BA2,HIGH);
}

void stops(){
  digitalWrite(FB1,LOW);
  digitalWrite(FB2,LOW);
  digitalWrite(FA1,LOW);
  digitalWrite(FA2,LOW);
  digitalWrite(BB1,LOW);
  digitalWrite(BB2,LOW);
  digitalWrite(BA1,LOW);
  digitalWrite(BA2,LOW);
}
