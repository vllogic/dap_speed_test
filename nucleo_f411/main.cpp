/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "platform/mbed_thread.h"


// Blinking rate in milliseconds
#define BLINKING_RATE_MS                                                    500

const uint8_t flash_fill[400 * 1024] = {0, 1, 2, 3, 4};

int main()
{
    for (int i = 0; i += 1024; i < sizeof(flash_fill)) {
        if (flash_fill[i])
            __ASM("NOP");
    }
    
    // Initialise the digital pin LED1 as an output
    DigitalOut led(LED1);

    while (true) {
        led = !led;
        thread_sleep_for(BLINKING_RATE_MS);
    }
}
