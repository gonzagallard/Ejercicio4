#ifndef FUNCIONES_H
#define FUNCIONES_H


typedef uint8_t color_t;

color_t color_crear(bool r, bool g, bool b);

void color_a_rgb(color_t c, uint8_t *r, uint8_t *g, uint8_t *b);

const char* figura_tipo_a_cadena(figura_tipo_t figura);

bool leer_encabezado_figura(FILE *f, char nombre[], figura_tipo_t *tipo, bool *infinito, size_t *cantidad_polilineas);

polilinea_t *leer_polilinea(FILE *f);


#endif