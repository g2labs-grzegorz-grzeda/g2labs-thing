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
typedef enum {
    G2L_ADDRESABLE_LED_WS2812 = 0,
} g2l_addresable_led_type_t;

typedef struct g2l_addresable_led g2l_addresable_led_t;

typedef struct g2l_addresable_led_configuration {
    int gpio;
    int led_count;
} g2l_addresable_led_configuration_t;

g2l_addresable_led_t* g2l_addresable_led_create(
    g2l_addresable_led_configuration_t* config);

void g2l_addresable_led_set_color(g2l_addresable_led_t* led,
                                  int index,
                                  int r,
                                  int g,
                                  int b);

void g2l_addresable_led_set_all(g2l_addresable_led_t* led, int r, int g, int b);

void g2l_addresable_led_update(g2l_addresable_led_t* led);

void g2l_addresable_led_destroy(g2l_addresable_led_t* led);