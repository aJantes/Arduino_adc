#include "Arduino.h"

void setup()
{
    dacWrite(20, 100); //IO20 DAC输出 100*3.3V/255≈1.294V
}