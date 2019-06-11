#include "Arduino.h"

void setup()
{
    Serial.begin(115200);
    Serial.println();

    float vtmp = analogRead(34); //从IO34 利用 ADC 获取电压
    printf("%.3f",vtmp);
}

void loop()
{

}