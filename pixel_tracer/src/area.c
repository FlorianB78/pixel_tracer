#include "area.h"


Area *create_area(unsigned int width,
                  unsigned int height, unsigned char id, char *name) {
    Area *ptr_area = (Area *) malloc(sizeof(Area));
    ptr_area->width = width;
    ptr_area->height = height;
    ptr_area->lst_layers = create_layers_list();
    ptr_area->id = id;
    ptr_area->empty_char = '.';
    ptr_area->full_char = '@';
    strcpy(ptr_area->name, name);
    ptr_area->area = (char **) malloc(height * sizeof(char *));
    for (unsigned int i = 0; i < ptr_area->height; i++) {
        ptr_area->area[i] = (char *) malloc(width * sizeof(char));
    }
    return ptr_area;
}

void delete_area(Area * area) {
    // todo: delate layers
    for (unsigned int i = 0; i < area->height; i++) {
        free(area->area[i]);
    }
    free(area);
}


AreaList *create_area_list() {
    AreaList *lst_area;
    lst_area = lst_create_list();
    return lst_area;


}

void delete_area_list(AreaList * area_list) {
    /* TODO : delete all layers on the list */
    lst_delete_list(area_list);

}

void add_area_to_list(AreaList * area_list, Area * area) {
    lnode *l = lst_create_lnode(area);
    lst_insert_tail(area_list, l);
}

void remove_area_from_list(AreaList * area_list, Area * area) {
    /* TODO  */

}
