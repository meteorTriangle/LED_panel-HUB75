# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Microcontroller/pico-SDK/pico-sdk/tools/pioasm"
  "M:/LED_panel-HUB75/build/pioasm"
  "M:/LED_panel-HUB75/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm"
  "M:/LED_panel-HUB75/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/tmp"
  "M:/LED_panel-HUB75/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp"
  "M:/LED_panel-HUB75/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src"
  "M:/LED_panel-HUB75/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "M:/LED_panel-HUB75/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "M:/LED_panel-HUB75/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp${cfgdir}") # cfgdir has leading slash
endif()
