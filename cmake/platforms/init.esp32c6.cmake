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
include($ENV{IDF_PATH}/tools/cmake/idf.cmake)

function(g2l_thing_platform_build_executable executable)
    idf_build_process("${ESP_TARGET}"
        COMPONENTS
        freertos
        esptool_py
        vfs
        spiffs
        driver
        esp_wifi
        nvs_flash
        mqtt

        # SDKCONFIG_DEFAULTS ${ESP32_SDKCONFIG_FILES}
        SDKCONFIG ${CMAKE_BINARY_DIR}/sdkconfig
    )
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
    target_link_libraries(${executable} PRIVATE idf::freertos idf::esp_common)

    idf_build_executable(${executable})
endfunction()
