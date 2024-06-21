#include <stdio.h>
#include "pico/stdlib.h"

// pins
const uint moisture_sensor_pin = 26;
const uint motor_pin = 16;

// initialize pins and initializing functions with setup function
void setup();
// read moisture level
float read_moisture();


int main()
{
    stdio_init_all();
    while(1)
        puts("Hello, world!");

    return 0;
}

float read_moisture() {
    const float conversion_factor = 3.3f / (1 << 12); // Convert to voltage
    uint16_t result = adc_read(); // Read raw sensor value from ADC0
    float voltage = result * conversion_factor; // Convert raw value to voltage

    return voltage;
}

void setup()
{
    stdio_init_all();
    adc_init(); //initiliaze adc module
    adc_gpio_init(moisture_sensor_pin);
    adc_select_input(0); // selects ADC0 as the input

    // initialise motor pin as output
    gpio_init(motor_pin);
    gpio_set_dir(motor_pin, GPIO_OUT);
    // set to low, off
    gpio_put(motor_pin, 0);
}