/**
 * @file render.c
 * @brief Implémentation des fonctions de rendu
 *
 * Ce fichier contient les fonctions pour effacer et dessiner
 * les zones et calques dans l'application Pixel Tracer.
 */

#include "render.h"
#include <string.h>

/**
 * @brief Efface toutes les cellules d'une zone
 *
 * Remplit chaque cellule de area->area avec EMPTY_CELL.
 *
 * @param area Pointeur vers la zone à effacer
 */
void clear_area(Area * area) {
    for (unsigned int i = 0; i < area->height; i++) {
        for (unsigned int j = 0; j < area->width; j++) {
            area->area[i][j] = EMPTY_CELL;
        }
    }
}

/**
 * @brief Affiche une zone sur le terminal
 *
 * Parcourt la matrice area->area et affiche chaque cellule
 * en utilisant area->empty_char ou area->full_char.
 *
 * @param area Pointeur vers la zone à afficher
 */
void draw_area(Area * area) {
    for (unsigned int i = 0; i < area->height; i++) {
        for (unsigned int j = 0; j < area->width; j++) {
            switch (area->area[i][j]) {
            case EMPTY_CELL:
                printf("%c", area->empty_char);
                break;
            case FULL_CHAR:
                printf("%c", area->full_char);
                break;
            default:
                printf("?");
            }
        }
        printf("\n");
    }
}

/**
 * @brief Efface l'écran du terminal
 *
 * Utilise les séquences ANSI sur Linux/Mac ou la commande system("cls") sur Windows.
 */
void clear_screen() {

#ifdef __linux__
    printf("\033[H\033[J");
#elif _WIN32
    system("cls");
#else
    printf("\033[H\033[J");
#endif

}

/**
 * @brief Dessine tous les calques visibles d'une zone
 *
 * Appelle draw_layer_shapes sur chaque calque visible.
 *
 * @param area Pointeur vers la zone
 */
void draw_all_layers(Area * area) {
    clear_area(area);
    list *layer_list = area->lst_layers;
    lnode *layer_node = get_first_node(layer_list);
    while (layer_node != NULL) {
        Layer *layer = (Layer *) layer_node->data;
        if (layer->visible == LAYER_VISIBLE) {
            draw_layer_shapes(area, layer);
        }
        layer_node = get_next_node(layer_list, layer_node);
    }
}

/**
 * @brief Dessine toutes les formes d'un calque dans une zone
 *
 * Convertit chaque forme en pixels et les insère dans area->area.
 *
 * @param area Pointeur vers la zone
 * @param layer Pointeur vers le calque
 */
void draw_layer_shapes(Area * area, Layer * layer) {
    list shape_list = layer->shapes;
    lnode *shape_node = get_first_node(&shape_list);

    while (shape_node != NULL) {
        Shape *shp = (Shape *) shape_node->data;
        list *list_pixel = create_shape_to_pixel(shp);

        lnode *pixel_node = get_first_node(list_pixel);
        while (pixel_node != NULL) {
            Pixel *pxl = pixel_node->data;
            if (pxl->px < area->height && pxl->py < area->width)
                area->area[pxl->px][pxl->py] = FULL_CHAR;
            pixel_node = get_next_node(list_pixel, pixel_node);
        }

        remove_pixel_shape(list_pixel); // libère la mémoire des pixels
        shape_node = get_next_node(&shape_list, shape_node);
    }
    
    return;
}
