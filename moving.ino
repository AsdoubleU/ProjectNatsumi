//각 자동차가 수행할 동작의 함수들에 해당.

void forward(int v){
  analogWrite(A1,0);
  analogWrite(A2,v);
  analogWrite(B1,v);
  analogWrite(B2,0);
}

void backward(int v){
  analogWrite(A1,v);
  analogWrite(A2,0);
  analogWrite(B1,0);
  analogWrite(B2,v);
}

void turnleft(int v){
  analogWrite(A1,v);
  analogWrite(A2,0);
  analogWrite(B1,v);
  analogWrite(B2,0);
}

void turnright(int v){
  analogWrite(A1,0);
  analogWrite(A2,v);
  analogWrite(B1,0);
  analogWrite(B2,v);
}

void stops(int v){
  analogWrite(A1,0);
  analogWrite(A2,0);
  analogWrite(B1,0);
  analogWrite(B2,0);
}
