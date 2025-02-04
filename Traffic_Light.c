#include <stdio.h>
#include "pico/stdlib.h"

#define RED_LED 11
#define YELLOW_LED 12
#define GREEN_LED 13

void SetOutput(int pin)
{
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_OUT);
}

int main()
{
    stdio_init_all();

    SetOutput(RED_LED);
    SetOutput(YELLOW_LED);
    SetOutput(GREEN_LED);

    while (true)
    {
        gpio_put(RED_LED, true);
        sleep_ms(1000);

        gpio_put(RED_LED, false);
        sleep_ms(1000);
    }
}
