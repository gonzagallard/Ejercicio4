#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdbool.h>
#include "enum_figuras.h"

const char* figura_tipo_a_cadena(figura_tipo_t figura);

bool leer_encabezado_figura(FILE *f, char nombre[], figura_tipo_t *tipo, bool *infinito, size_t *cantidad_polilineas);

// polilinea_t *leer_polilinea(FILE *f);


#endif
