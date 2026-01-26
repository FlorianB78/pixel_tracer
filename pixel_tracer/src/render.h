#include <stdlib.h>
#include <stdio.h>
#include "layers.h"
#include "area.h"
#include "pixel.h"

#ifndef _RENDER_H_
#  define _RENDER_H_

typedef enum { EMPTY_CELL, BLACK_CELL, RED_CELL } color_cell;

#  define EMPTY_CHAR '.'
#  define FULL_CHAR  '#'

void render_area(Area * area);
void draw_area(Area * area);

void clear_screen();

void draw_layer_shapes(Area * area, Layer * layer);

void draw_all_layers(Area * area);

#endif
