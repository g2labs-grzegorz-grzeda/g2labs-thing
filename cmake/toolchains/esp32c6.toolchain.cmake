# MIT License
#
# Copyright (c) 2025 G2Labs Grzegorz Grzeda
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#
# Set the path to the ESP-IDF toolchain file
set(ESP_IDF_TOOLCHAIN_FILE "$ENV{IDF_PATH}/tools/cmake/toolchain-esp32c6.cmake")

# Include the ESP-IDF toolchain file
include(${ESP_IDF_TOOLCHAIN_FILE})

set(G2L_PLATFORM "esp32" CACHE STRING "Platform name" FORCE)
set(G2L_PLATFORM_FLAVOR "c6" CACHE STRING "Platform flavor" FORCE)
set(ESP_TARGET "esp32c6" CACHE STRING "ESP32-C6 target" FORCE)