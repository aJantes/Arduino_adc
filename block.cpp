#include "Arduino.h"
#include "math.h"

const float R1 = 10000.0; //10K
const float T2 = (273.15 + 25.0);    
const float Bx = 3950.0;    // B值
const float Ka = 273.15;

void setup()
{

  Serial.begin(115200);
  Serial.println();
}

int tempCount(float vtmp)       // 温度转换
{
  float Rt;
  float temp;
  float v0 = (vtmp * 3.9) / 4095.0;

  Rt=(3.3-v0)/v0*R1;
  temp = Rt/R1 ;
  temp = log10(temp); 
  temp /= Bx;         
  temp += (1 / T2);
  temp = 1 / (temp);
  temp -= Ka;
  return temp;
}

void loop()
{
  float vtmp = analogRead(34); //IO34 ADC获取电压
  float temp = tempCount(vtmp);

  Serial.printf("T:%f\n", temp);
  Serial.println();
  Serial.printf("C:%f\n", vtmp);
  Serial.println();
  Serial.printf("V:%.3fV\n", vtmp * 3.9 / 4095);
  Serial.println();

  delay(1000);
}
