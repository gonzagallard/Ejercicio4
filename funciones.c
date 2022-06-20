#include <stdint.h>
#include <stdlib.h>

#include "funciones.h"

#define MASK_ES_INF         0x40
#define MASK_TIPO           0x0E
#define MASK_ES_RED         0x8000
#define MASK_ES_GREEN       0x4000
#define MASK_ES_BLUE        0x2000
#define MASK_ON_RED_COLOR   0x04
#define MASK_ON_GREEN_COLOR 0x02
#define MASK_ON_BLUE_COLOR  0x01
#define MASK_NPUNTOS        0x03FF

typedef uint8_t color_t;

static color_t color_crear(bool r, bool g, bool b){
    return r << 2 | g << 1 | b ;
}

static void color_a_rgb(color_t c, uint8_t *r, uint8_t *g, uint8_t *b){
    *r = (*g = (*b = 0));
    if(c & MASK_ON_RED_COLOR)
        *r = 0xFF;
    if(c & MASK_ON_GREEN_COLOR)
        *g = 0xFF;
    if(c & MASK_ON_BLUE_COLOR)
        *b = 0xFF;
}

const char *figuras[] = {
    [ICONO]  = "Icono",
    [NIVEL]  = "Nivel",
    [SPRITE] = "Sprite",
};

const char* figura_tipo_a_cadena(figura_tipo_t figura){
    return figuras[figura];
}

bool leer_encabezado_figura(FILE *f, char nombre[], figura_tipo_t *tipo, bool *infinito, size_t *cantidad_polilineas){
    if(!fread(nombre, sizeof(char), 20, f))
        return false;

    uint8_t caracteristicas;
    if(!fread(&caracteristicas, sizeof(uint8_t), 1, f))
        return false;
    *tipo = (caracteristicas & MASK_TIPO) >> 1;
    *infinito = caracteristicas & MASK_ES_INF;
    
    uint16_t n_polilineas;
    if(!fread(&n_polilineas, sizeof(uint16_t), 1, f))
        return false;
    *cantidad_polilineas = n_polilineas;
    
    return true;
}

struct polilinea{
    int x;
};

static polilinea_t *polilinea_crear_vacia(size_t n) {
    printf("POLILINEA N=%zd\n", n);
    static polilinea_t x;
    return &x;
}

void polilinea_destruir(polilinea_t *polilinea) {}

static bool polilinea_setear_punto(polilinea_t *polilinea, size_t pos, float x, float y) {
    printf("POLILINEA[%zd] = (%.2f, %.2f)\n", pos, x, y);
    return true;
}

static bool polilinea_setear_color(polilinea_t *polilinea, color_t color) {
    uint8_t r, g, b;
    color_a_rgb(color, &r, &g, &b);
    printf("POLILINEA COLOR: (%d, %d, %d)\n", r, g, b);
    return true;
}

polilinea_t *leer_polilinea(FILE *f){
    uint16_t encabezado_pol;
    size_t cant_puntos;
    
    if(!fread(&encabezado_pol, sizeof(uint16_t), 1, f))
    	return NULL;
    cant_puntos = encabezado_pol & MASK_NPUNTOS;
    polilinea_t *polilinea = polilinea_crear_vacia(cant_puntos);

    if(polilinea == NULL)
        return NULL;

    bool es_red   = encabezado_pol & MASK_ES_RED;
    bool es_green = encabezado_pol & MASK_ES_GREEN;
    bool es_blue  = encabezado_pol & MASK_ES_BLUE;
    
    color_t color = color_crear (es_red, es_green, es_blue);

    if(!polilinea_setear_color(polilinea, color)){
        polilinea_destruir(polilinea);
        return NULL;
    }

    for(size_t i = 0; i < cant_puntos ; i++){
        float punto_x, punto_y;
        if(!fread(&punto_x, sizeof(float), 1, f) || !fread(&punto_y, sizeof(float), 1, f)){
	    polilinea_destruir(polilinea);
	    return NULL;
	}
	if(!polilinea_setear_punto(polilinea, i, punto_x, punto_y)){
            polilinea_destruir(polilinea);
            return NULL;
        }
    }
    return polilinea;
}
