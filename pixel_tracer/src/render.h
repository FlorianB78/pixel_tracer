/**
 * @file render.h
 * @brief Fonctions de rendu pour les zones et calques
 *
 * Ce module fournit l'API publique pour dessiner et gérer
 * l'affichage des zones, calques et pixels dans l'application.
 *
 * API publique :
 * - render_area()       : dessine une zone entière
 * - draw_area()         : affiche la zone à l'écran
 * - clear_screen()      : efface l'écran du terminal
 * - draw_layer_shapes() : dessine toutes les formes d'un calque dans la zone
 * - draw_all_layers()   : dessine tous les calques visibles d'une zone
 *
 * Structures et types :
 * - color_cell : type énuméré pour représenter le contenu d'une cellule
 */

#ifndef _RENDER_H_
#define _RENDER_H_

#include <stdlib.h>
#include <stdio.h>
#include "layers.h"
#include "area.h"
#include "pixel.h"

/**
 * @enum color_cell
 * @brief Représente l'état d'une cellule dans une zone
 */
typedef enum { 
    EMPTY_CELL,  /**< cellule vide */
    BLACK_CELL,  /**< cellule remplie noire */
    RED_CELL     /**< cellule remplie rouge */
} color_cell;

/**
 * @brief Caractères pour l'affichage d'une zone
 */
#define EMPTY_CHAR '.'   /**< caractère pour une cellule vide */
#define FULL_CHAR  '#'   /**< caractère pour une cellule pleine */

/**
 * @brief Dessine la zone en mémoire (remplit la matrice area->area)
 * @param area Pointeur vers la zone à dessiner
 */
void render_area(Area * area);

/**
 * @brief Affiche la zone à l'écran
 * @param area Pointeur vers la zone à afficher
 */
void draw_area(Area * area);

/**
 * @brief Efface l'écran du terminal
 */
void clear_screen();

/**
 * @brief Dessine toutes les formes d'un calque dans la zone
 * @param area Pointeur vers la zone
 * @param layer Pointeur vers le calque
 */
void draw_layer_shapes(Area * area, Layer * layer);

/**
 * @brief Dessine tous les calques visibles de la zone
 * @param area Pointeur vers la zone
 */
void draw_all_layers(Area * area);

#endif
