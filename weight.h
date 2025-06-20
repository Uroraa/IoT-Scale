#include <HX711.h>
#ifndef WEIGHT_H
#define WEIGHT_H

#define LOADCELL_NUM 4

const int LOADCELL_DOUT_PIN[LOADCELL_NUM] = {0,1,2,3};
const int LOADCELL_SCK_PIN = 4;

extern long loadcell_values[LOADCELL_NUM];

void setup_hx711();

void loop_hx711();

#endif