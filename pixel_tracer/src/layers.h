#include "list.h"
#include "shape.h"
#include <stdlib.h>
#include <string.h>

#ifndef _LAYERS_H_
#  define _LAYERS_H_

/**
 * @file layers.h
 * @brief Définition des structures et fonctions pour gérer les couches (Layer)
 *
 * Ce module permet de créer, manipuler et supprimer des couches,
 * gérer leur visibilité, et stocker les formes qu'elles contiennent.
 */

#define LAYER_VISIBLE   1 /**< Indique qu'une couche est visible */
#define LAYER_UNVISIBLE 0 /**< Indique qu'une couche est invisible */

/**
 * @struct layer
 * @brief Représente une couche dans une zone.
 *
 * Une couche contient :
 * - son identifiant unique
 * - son nom
 * - sa visibilité
 * - une liste de formes
 */
struct layer {
    unsigned char id;      /**< Identifiant unique de la couche */
    char name[255];        /**< Nom de la couche */
    list shapes;           /**< Liste des formes contenues dans la couche */
    unsigned char visible; /**< Indique si la couche est visible */
};

typedef struct layer Layer;

/**
 * @typedef LayersList
 * @brief Liste de couches.
 */
typedef list LayersList;

/**
 * @brief Crée une nouvelle couche.
 *
 * @param id Identifiant unique de la couche.
 * @param name Nom de la couche.
 * @return Pointeur vers la couche créée.
 */
Layer *create_layer(int id, char *name);

/**
 * @brief Supprime une couche et libère sa mémoire.
 *
 * @param layer Pointeur vers la couche à supprimer.
 */
void delete_layer(Layer *layer);

/**
 * @brief Crée une liste de couches.
 *
 * @return Pointeur vers la liste créée.
 */
LayersList *create_layers_list();

/**
 * @brief Supprime une liste de couches et libère sa mémoire.
 *
 * @param layer_list Pointeur vers la liste à supprimer.
 */
void delete_layers_list(LayersList *layer_list);

/**
 * @brief Ajoute une couche à une liste.
 *
 * @param layer_list Pointeur vers la liste de couches.
 * @param layer Pointeur vers la couche à ajouter.
 */
void add_layer_to_list(LayersList *layer_list, Layer *layer);

/**
 * @brief Supprime une couche d'une liste.
 *
 * @param layer_list Pointeur vers la liste de couches.
 * @param layer Pointeur vers la couche à supprimer.
 */
void remove_layer_from_list(LayersList *layer_list, Layer *layer);

/**
 * @brief Rend une couche visible.
 *
 * @param layer Pointeur vers la couche à rendre visible.
 */
void set_layer_visible(Layer *layer);

/**
 * @brief Rend une couche invisible.
 *
 * @param layer Pointeur vers la couche à rendre invisible.
 */
void set_layer_unvisible(Layer *layer);

/**
 * @brief Ajoute une forme à une couche.
 *
 * @param layer Pointeur vers la couche.
 * @param shape Pointeur vers la forme à ajouter.
 */
void add_shape_to_layer(Layer *layer, Shape *shape);

/**
 * @brief Supprime une forme d'une couche.
 *
 * @param layer Pointeur vers la couche.
 * @param shape Pointeur vers la forme à supprimer.
 */
void remove_shape_to_from(Layer *layer, Shape *shape);

#endif

