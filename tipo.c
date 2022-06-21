#include "tipo.h"

#include <stdint.h>

#define MASK_ES_INF 0x40
#define MASK_TIPO   0x0E

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
