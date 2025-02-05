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

#include "g2l-addresable-led.h"
#include <stdlib.h>
#include "g2l-addresable-led-platform.h"

typedef struct g2l_addresable_led {
    g2l_addresable_led_platform_t* platform;
} g2l_addresable_led_t;

static g2l_addresable_led_t* addressable_led = NULL;

g2l_addresable_led_t* g2l_addresable_led_create(
    g2l_addresable_led_configuration_t* config) {
    if (addressable_led || !config || config->led_count <= 0) {
        return NULL;
    }
    addressable_led =
        (g2l_addresable_led_t*)calloc(1, sizeof(g2l_addresable_led_t));
    if (!addressable_led) {
        return NULL;
    }

    g2l_addresable_led_platform_configuration_t platform_config = {
        .type = G2L_ADDRESABLE_LED_PLATFORM_WS2812_GRB,
        .gpio = config->gpio,
        .led_count = config->led_count,
    };

    addressable_led->platform =
        g2l_addresable_led_platform_create(&platform_config);
    if (!addressable_led->platform) {
        free(addressable_led);
        addressable_led = NULL;
        return NULL;
    }

    return addressable_led;
}

void g2l_addresable_led_set_color(g2l_addresable_led_t* led,
                                  int index,
                                  int r,
                                  int g,
                                  int b) {
    if (!led || index < 0 || index >= led->platform->led_count) {
        return;
    }
    index *= 3;
    led->platform->data[index] = r;
    led->platform->data[index + 1] = g;
    led->platform->data[index + 2] = b;
}

void g2l_addresable_led_set_all(g2l_addresable_led_t* led,
                                int r,
                                int g,
                                int b) {
    if (!led) {
        return;
    }
    int entries_count = led->platform->led_count * 3;
    for (int i = 0; i < entries_count; i++) {
        led->platform->data[i] = r;
        led->platform->data[i + 1] = g;
        led->platform->data[i + 2] = b;
    }
}

void g2l_addresable_led_update(g2l_addresable_led_t* led) {
    if (!led) {
        return;
    }
    g2l_addresable_led_platform_update(led->platform);
}

void g2l_addresable_led_destroy(g2l_addresable_led_t* led) {
    if (led) {
        g2l_addresable_led_platform_destroy(led->platform);
        free(led);
    }
}