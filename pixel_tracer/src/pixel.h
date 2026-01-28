/**
 * @file pixel.h
 * @brief Gestion des pixels et conversion des formes en pixels
 *
 * Ce module fournit des fonctions pour créer et manipuler les pixels
 * à partir des formes (Shape) et générer une liste de pixels pour
 * le rendu.
 *
 * API publique :
 * - create_shape_to_pixel()
 * - remove_pixel_shape()
 *
 * Structures :
 * - Pixel : position et couleur d'un pixel
 */

#ifndef _PIXEL_H_
#define _PIXEL_H_

#include <stdlib.h>
#include "shape.h"
#include "list.h"

/**
 * @struct pixel
 * @brief Représente un pixel à l'écran
 */
struct pixel {
    int px;     /**< Coordonnée X du pixel */
    int py;     /**< Coordonnée Y du pixel */
    int color;  /**< Couleur du pixel */
};

typedef struct pixel Pixel;

/**
 * @brief Convertit une forme (Shape) en liste de pixels
 *
 * Cette fonction analyse le type de la forme et génère une
 * liste de Pixel correspondant aux coordonnées de la forme.
 *
 * @param shape Pointeur vers la forme à convertir
 * @return list* Liste de pixels représentant la forme
 */
list *create_shape_to_pixel(Shape * shape);

/**
 * @brief Supprime les pixels d'une liste
 *
 * Libère les Pixel contenus dans la liste et vide la liste.
 *
 * @param pixel_lst Liste de pixels à supprimer
 */
void remove_pixel_shape(list * pixel_lst);

/* Fonctions internes (non API publique) */
Pixel *create_pixel(int px, int py, int color);
void delete_pixel(Pixel * pixel);
void pixel_point(Shape * shape, list * lst);
void pixel_line(Shape * shape, list * lst);
void pixel_cercle(Shape * shape, list * lst);
void pixel_rectangle(Shape * shape, list * lst);
void pixel_square(Shape * shape, list * lst);
void pixel_polygon(Shape * shape, list * lst);
void pixel_curve(Shape * shape, list * lst);

#endif
