#include <stdio.h>
#include "pico/stdlib.h"


typedef enum scan_bit{
    scan_8,
    scan_16,
    scan_32,
} ScanBits;
typedef enum cf{
    colorFormat_8bit,
    colorFormat_6bit,
    colorFormat_16bit,
    colorFormat_15bit,
    colorFormat_24bit,
    colorFormat_18bit,
} color_format;

class hub75{
    public:
        hub75(
            ScanBits scan_col_bits, 
            color_format sourse_color_format, 
            int lengh,
            uint8_t displayColorDepth,
            uint firstPin,
            uint clkPin,
            uint OEPin,
            uint latPin);
        void convertData(uint32_t *pixelImage, uint32_t *displayData);
        void run(uint32_t *displayData);
    private:
        int LED_lengh;
        uint8_t displayColorDepth;
        uint firstPin, OEPin, latPin, clkPin;
        ScanBits col_bits;
        color_format sourse_color_format; 
};