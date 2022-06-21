#include "color.h"

#define MASK_ON_RED_COLOR   0x04
#define MASK_ON_GREEN_COLOR 0x02
#define MASK_ON_BLUE_COLOR  0x01

color_t color_crear(bool r, bool g, bool b){
    return r << 2 | g << 1 | b ;
}

void color_a_rgb(color_t c, uint8_t *r, uint8_t *g, uint8_t *b){
    *r = (*g = (*b = 0));
    if(c & MASK_ON_RED_COLOR)
        *r = 0xFF;
    if(c & MASK_ON_GREEN_COLOR)
        *g = 0xFF;
    if(c & MASK_ON_BLUE_COLOR)
        *b = 0xFF;
}
