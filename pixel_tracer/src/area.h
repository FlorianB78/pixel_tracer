#include <stdlib.h>
#include <stdio.h>
#include "layers.h"

#ifndef _AREA_H_
#  define _AREA_H_



struct area {
    unsigned char id;
    char name[255];
    unsigned int width;
    unsigned int height;
    char **area;
    LayersList *lst_layers;
    char empty_char;
    char full_char;
};

typedef struct area Area;

typedef list AreaList;


Area *create_area(unsigned int width, unsigned int height,
                  unsigned char id, char *name);
void delete_area(Area * area);
void clear_area(Area * area);


AreaList *create_area_list();

void delete_area_list(AreaList * area_list);

void add_area_to_list(AreaList * area_list, Area * area);

void remove_area_from_list(AreaList * area_list, Area * area);




#endif
