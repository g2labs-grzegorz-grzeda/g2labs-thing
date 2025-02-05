/*
 * MIT License
 *
 * Copyright (c) 2025 G2Labs Grzegorz Grzeda
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include <stdio.h>
#include "g2l-addresable-led.h"
#include "g2l-delay.h"

int application_main(int argc, char** argv) {
    printf("Hello, World!\n");
    g2l_addresable_led_configuration_t config = {
        .gpio = 8,
        .led_count = 1,
    };
    g2l_addresable_led_t* led = g2l_addresable_led_create(&config);
    if (!led) {
        return -1;
    }

    while (1) {
        g2l_delay_ms(500);
        g2l_addresable_led_set_all(led, 0, 50, 0);
        g2l_addresable_led_update(led);
        g2l_delay_ms(500);
        g2l_addresable_led_set_all(led, 50, 0, 0);
        g2l_addresable_led_update(led);
        g2l_delay_ms(500);
        g2l_addresable_led_set_all(led, 0, 0, 50);
        g2l_addresable_led_update(led);
        g2l_delay_ms(500);
        g2l_addresable_led_set_all(led, 0, 0, 0);
        g2l_addresable_led_update(led);
    }

    return 0;
}