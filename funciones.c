#include <stdint.h>
#include <stdbool.h>

#include "funciones.h"

#define MASK_RGB 0xE000

typedef uint8_t color_t;

color_t color_crear(bool r, bool g, bool b){


}

void color_a_rgb(color_t c, uint8_t *r, uint8_t *g, uint8_t *b){


}


struct polilinea{
    int x;
};

typedef struct polilinea polilinea_t;

typedef enum {ICONO, NIVEL, SPRITE} figura_tipo_t;

char *figuras[]{
    [ICONO]  = "Icono",
    [NIVEL]  = "Nivel",
    [SPRITE] = "Sprite",
}

const char* figura_tipo_a_cadena(figura_tipo_t figura){
    return figuras[figura];
}

bool leer_encabezado_figura(FILE *f, char nombre[], figura_tipo_t *tipo, bool *infinito, size_t *cantidad_polilineas){

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
