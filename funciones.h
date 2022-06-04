#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdbool.h>
      
typedef enum {
     ICONO,        
     NIVEL,    
     SPRITE
}figura_tipo_t;

typedef struct polilinea polilinea_t;

const char* figura_tipo_a_cadena(figura_tipo_t figura);

bool leer_encabezado_figura(FILE *f, char nombre[], figura_tipo_t *tipo, bool *infinito, size_t *cantidad_polilineas);

polilinea_t *leer_polilinea(FILE *f);

void polilinea_destruir(polilinea_t *p);

#endif
