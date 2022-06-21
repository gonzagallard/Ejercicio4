#ifndef TIPO_H 
#define TIPO_H

#include <stdio.h>
#include <stdbool.h>

typedef enum {
     ICONO,        
     NIVEL,    
     SPRITE
}figura_tipo_t;

const char* figura_tipo_a_cadena(figura_tipo_t figura);

bool leer_encabezado_figura(FILE *f, char nombre[], figura_tipo_t *tipo, bool *infinito, size_t *cantidad_polilineas);

#endif
