#include "hub75.h"
hub75::hub75(
    ScanBits scan_col_bits, 
    color_format sourse_color_format, 
    int lengh,
    uint8_t displayColorDepth,
    uint firstPin,
    uint clkPin,
    uint OEPin,
    uint latPin){
    this->col_bits = scan_col_bits;
    this->sourse_color_format = sourse_color_format;
    this->LED_lengh = lengh;
    this->displayColorDepth = displayColorDepth;
    this->firstPin = firstPin;
    this->clkPin = clkPin;
    this->OEPin = OEPin;
    this->latPin = latPin;
}
void hub75::convertData(uint32_t *pixelImage, uint32_t *displayData){
    int col_bit_i;
    if(col_bits = scan_8){
        col_bit_i = 8;
    }
    if(col_bits = scan_16){
        col_bit_i = 16;
    }
    if(col_bits = scan_32){
        col_bit_i = 32;
    }
    int second_index = col_bit_i*LED_lengh;
    for(int BCMbit = 0; BCMbit < displayColorDepth; BCMbit++)
        for(int col=0; col<col_bit_i; col++){
            for(int row=0; row<LED_lengh; row++){
                int up_bit = (col*LED_lengh+row);
                int down_bit = ((col + (col_bit_i/2))*LED_lengh+row);
                uint16_t display = 0;
                display |= BCMbit << 13;
                display |= col<<6;
                display |= ((*(pixelImage+up_bit))>>(16+BCMbit)|1)<<0;//r1
                display |= ((*(pixelImage+up_bit))>>( 8+BCMbit)|1)<<1;//g1
                display |= ((*(pixelImage+up_bit))>>( 0+BCMbit)|1)<<2;//b1
                display |= ((*(pixelImage+down_bit))>>(16+BCMbit)|1)<<3;//r2
                display |= ((*(pixelImage+down_bit))>>( 8+BCMbit)|1)<<4;//g2
                display |= ((*(pixelImage+down_bit))>>( 0+BCMbit)|1)<<5;//b2
                *(displayData++) = display;
            }
        }
}