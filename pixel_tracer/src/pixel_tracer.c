/**
 * @file pixel_tracer.c
 * @brief Implémentation de l'initialisation et destruction de l'application
 *
 * Ce fichier contient les fonctions pour initialiser et détruire
 * l'état global de l'application Pixel Tracer.
 */

#include "pixel_tracer.h"

/**
 * @brief Initialise l'application Pixel Tracer
 *
 * Crée une liste de zones et ajoute une zone par défaut avec un calque.
 * Initialise les pointeurs vers la zone, le calque et la forme courante.
 *
 * @param app Pointeur vers la structure Pixel_tracer_app
 */
void init_app(Pixel_tracer_app * app) {
    app->list_area = create_area_list();
    Area *area = create_area(80, 40, get_next_id(), "Area1");
    add_area_to_list(app->list_area, area);
    app->current_area = area;

    LayersList *layerlst = create_layers_list();
    area->lst_layers = layerlst;
    Layer *layer = create_layer(get_next_id(), "Layer 1");
    add_layer_to_list(layerlst, layer);
    app->current_layer = layer;
    app->current_shape = NULL;
}

/**
 * @brief Détruit l'application Pixel Tracer
 *
 * Supprime toutes les zones et libère la mémoire associée.
 * Réinitialise les pointeurs vers la zone, le calque et la forme courante.
 *
 * @param app Pointeur vers la structure Pixel_tracer_app
 */
void destry_app(Pixel_tracer_app * app) {
    delete_area_list(app->list_area);
    app->current_area = NULL;
    app->current_layer = NULL;
    app->current_shape = NULL;
}
