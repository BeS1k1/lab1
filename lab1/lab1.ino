#include <Arduino.h>
#include <MD_TCS230.h>

#define RGB1 2
#define RGB2 3
#define RGB3 4
#define RGB4 5
#define RGB5 6
#define RGB6 8
#define RGB7 9
#define RGB8 10

void setup()
{
  Serial.begin(115200);
  Serial.println("Enter a number from 0 to 255");

  pinMode(RGB1, OUTPUT);
  pinMode(RGB2, OUTPUT);
  pinMode(RGB3, OUTPUT);
  pinMode(RGB4, OUTPUT);
  pinMode(RGB5, OUTPUT);
  pinMode(RGB6, OUTPUT);
  pinMode(RGB7, OUTPUT);
  pinMode(RGB8, OUTPUT);
}

void loop() 
{
  if (Serial.available() > 0)
  {
    int num = Serial.parseInt();
    if (num > 255 || num < 0){
      Serial.println("Incorrect input, please enter a number from 0 to 255");
    }
    else
    {
      int *bits;
      bits = to_binary(num);
      lighting(bits);
    }
  }
}

int *to_binary(int num)
{
  int *bits = new int[8];
  for (int j = 0; j < 8; j++)
  {
    bits[j] = HIGH;
  }
  int i=7;
  while (num>0)
  {
    if (num%2 == 1)
    {
      bits[i] = LOW;
    }
    num/=2;
    i--;
  }
  return bits;
}

void lighting(int *bits)
{
  digitalWrite(RGB1, bits[7]);
  digitalWrite(RGB2, bits[6]);
  digitalWrite(RGB3, bits[5]);
  digitalWrite(RGB4, bits[4]);
  digitalWrite(RGB5, bits[3]);
  digitalWrite(RGB6, bits[2]);
  digitalWrite(RGB7, bits[1]);
  digitalWrite(RGB8, bits[0]);
}
