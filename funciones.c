#include <stdint.h>

#include "funciones.h"

#define MASK_ES_INF 0x40
#define MASK_TIPO   0x0E
#define MASK_NPOL   0xFFFF
#define MASK_RGB    0xE000

typedef uint8_t color_t;

color_t color_crear(bool r, bool g, bool b){


}

void color_a_rgb(color_t c, uint8_t *r, uint8_t *g, uint8_t *b){


}

struct polilinea{
    int x;
};

typedef struct polilinea polilinea_t;

char *figuras[] = {
    [ICONO]  = "Icono",
    [NIVEL]  = "Nivel",
    [SPRITE] = "Sprite",
};

const char* figura_tipo_a_cadena(figura_tipo_t figura){
    return figuras[figura];
}

bool leer_encabezado_figura(FILE *f, char nombre[], figura_tipo_t *tipo, bool *infinito, size_t *cantidad_polilineas){
    if(fread(nombre, sizeof(char), 20, f) == EOF)
        return false;

    uint8_t caracteristicas;
    if(fread(&caracteristicas, sizeof(uint8_t), 1, f) == EOF)
        return false;
    *tipo = (caracteristicas & MASK_TIPO) >> 1;
    *infinito = caracteristicas & MASK_ES_INF;
    
    uint16_t n_polilineas;
    if(fread(&n_polilineas, sizeof(uint16_t), 1, f) == EOF)
        return false;
    *cantidad_polilineas = n_polilineas & MASK_NPOL;
    
    return true;
}

polilinea_t *polilinea_crear_vacia(size_t n) {
    printf("POLILINEA N=%zd\n", n);
    static polilinea_t x;
    return &x;
}


bool polilinea_setear_color(polilinea_t *polilinea, color_t color) {
    uint8_t r, g, b;
    color_a_rgb(color, &r, &g, &b);
    printf("POLILINEA COLOR: (%d, %d, %d)\n", r, g, b);
    return true;
}

bool polilinea_setear_punto(polilinea_t *polilinea, size_t pos, float x, float y) {
    printf("POLILINEA[%zd] = (%.2f, %.2f)\n", pos, x, y);
    return true;
}

polilinea_t *leer_polilinea(FILE *f){



}

void polilinea_destruir(polilinea_t *polilinea) {



}

