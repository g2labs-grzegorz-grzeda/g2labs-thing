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

typedef enum {
    G2L_ADDRESABLE_LED_PLATFORM_WS2812_GRB = 0,
} g2l_addresable_led_platform_type_t;

typedef struct g2l_addresable_led_platform_configuration {
    g2l_addresable_led_platform_type_t type;
    int gpio;
    int led_count;
} g2l_addresable_led_platform_configuration_t;

typedef struct g2l_addresable_led_platform {
    uint8_t* data;
    size_t len;
    int led_count;
} g2l_addresable_led_platform_t;

g2l_addresable_led_platform_t* g2l_addresable_led_platform_create(
    g2l_addresable_led_platform_configuration_t* config);

void g2l_addresable_led_platform_update(g2l_addresable_led_platform_t* led);

void g2l_addresable_led_platform_destroy(g2l_addresable_led_platform_t* led);