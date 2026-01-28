/**
 * @file layers.c
 * @brief Implémentation des fonctions de gestion des couches (Layer)
 *
 * Ce module permet :
 * - la création et suppression des couches
 * - la gestion de leur visibilité
 * - l'ajout et suppression des formes dans une couche
 * - la gestion des listes de couches
 */

#include "layers.h"

/**
 * @brief Crée et initialise une couche.
 *
 * La couche est initialisée avec :
 * - identifiant et nom
 * - liste de formes vide
 * - visibilité à visible
 *
 * @param id Identifiant unique
 * @param name Nom de la couche
 * @return Pointeur vers la couche créée
 */
Layer *create_layer(int id, char *name) {
    Layer *ptr_layer = (Layer *) malloc(sizeof(Layer));
    ptr_layer->id = id;
    strcpy(ptr_layer->name, name);
    ptr_layer->shapes = *lst_create_list();
    ptr_layer->visible = LAYER_VISIBLE;
    return ptr_layer;
}

/**
 * @brief Supprime une couche et libère ses ressources.
 *
 * @param layer Pointeur vers la couche à supprimer
 */
void delete_layer(Layer *layer) {
    lst_erase(&layer->shapes);
    free(layer);
}

/**
 * @brief Crée une liste de couches.
 *
 * @return Pointeur vers la liste créée
 */
LayersList *create_layers_list() {
    LayersList *lst_layer = lst_create_list();
    return lst_layer;
}

/**
 * @brief Supprime une liste de couches et libère la mémoire.
 *
 * @param layer_list Liste à supprimer
 */
void delete_layers_list(LayersList *layer_list) {
    lst_delete_list(layer_list);
}

/**
 * @brief Ajoute une couche à la liste.
 *
 * @param layer_list Liste de couches
 * @param layer Couche à ajouter
 */
void add_layer_to_list(LayersList *layer_list, Layer *layer) {
    lnode *l = lst_create_lnode(layer);
    lst_insert_tail(layer_list, l);
}

/**
 * @brief Supprime une couche d'une liste.
 *
 * @param layer_list Liste de couches
 * @param layer Couche à supprimer
 * @todo Implémenter la suppression d'une couche spécifique
 */
void remove_layer_from_list(LayersList *layer_list, Layer *layer) {
    /* TODO */
}

/**
 * @brief Rend une couche visible.
 *
 * @param layer Couche à rendre visible
 */
void set_layer_visible(Layer *layer) {
    layer->visible = LAYER_VISIBLE;
}

/**
 * @brief Rend une couche invisible.
 *
 * @param layer Couche à rendre invisible
 */
void set_layer_unvisible(Layer *layer) {
    layer->visible = LAYER_UNVISIBLE;
}

/**
 * @brief Ajoute une forme à la couche.
 *
 * @param layer Couche cible
 * @param shape Forme à ajouter
 */
void add_shape_to_layer(Layer *layer, Shape *shape) {
    lnode *l = lst_create_lnode(shape);
    lst_insert_tail(&(layer->shapes), l);
}

/**
 * @brief Supprime une forme de la couche.
 *
 * @param layer Couche cible
 * @param shape Forme à supprimer
 * @todo Implémenter la suppression d'une forme spécifique
 */
void remove_shape_to_from(Layer *layer, Shape *shape) {
    /* TODO */
}
