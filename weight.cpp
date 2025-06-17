#include "weight.h"

long loadcell_values[LOADCELL_NUM];
HX711 scale[LOADCELL_NUM];

void setup_hx711()
{
    // Initialize library with data output pin, clock input pin and gain factor.
    // Channel selection is made by passing the appropriate gain:
    // - With a gain factor of 64 or 128, channel A is selected
    // - With a gain factor of 32, channel B is selected
    // By omitting the gain factor parameter, the library
    // default "128" (Channel A) is used here.
    for (unsigned char i = 0; i < LOADCELL_NUM; i++)
    {
        scale[i].begin(LOADCELL_DOUT_PIN[i], LOADCELL_SCK_PIN);
    }
}

void loop_hx711()
{
    static unsigned char i;
    for (i = 0; i < LOADCELL_NUM; i++)
    {
        if (scale[i].is_ready())
        {
            loadcell_values[i] = scale[i].read();
            //loadcell_values[i] = random(100);
        }
        else
        {
            Serial.print("HX711 ");
            Serial.print(i);
            Serial.println(" not found.");
            loadcell_values[i] = -1;
        }
    }
}