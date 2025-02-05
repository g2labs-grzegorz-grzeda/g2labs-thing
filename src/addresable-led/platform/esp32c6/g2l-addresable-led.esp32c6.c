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
#include <stddef.h>
#include <stdint.h>
#include "driver/rmt_tx.h"
#include "g2l-addresable-led-platform.h"

g2l_addresable_led_platform_t* g2l_addresable_led_platform_create(
    g2l_addresable_led_platform_configuration_t* config) {
    printf("<g2l_addresable_led_platform:ESP32C6> NOT IMPLEMENTED\n");
    return NULL;
}

void g2l_addresable_led_platform_update(g2l_addresable_led_platform_t* led) {
    printf("<g2l_addresable_led_platform:ESP32C6> NOT IMPLEMENTED\n");
}

void g2l_addresable_led_platform_destroy(g2l_addresable_led_platform_t* led) {
    printf("<g2l_addresable_led_platform:ESP32C6> NOT IMPLEMENTED\n");
}