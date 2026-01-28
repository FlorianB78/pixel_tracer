/**
 * @file pixel_tracer.h
 * @brief Gestion globale de l'application Pixel Tracer
 *
 * Ce module fournit les structures et fonctions pour initialiser
 * et détruire l'application Pixel Tracer, contenant les zones,
 * calques et formes courantes.
 *
 * API publique :
 * - init_app()
 * - destry_app()
 *
 * Structures :
 * - Pixel_tracer_app : état global de l'application
 */

#ifndef _PIXEL_TRACER_H_
#define _PIXEL_TRACER_H_

#include "list.h"
#include "id.h"
#include "area.h"
#include "layers.h"
#include "shape.h"
#include "pixel.h"
#include "render.h"

/**
 * @struct pixel_tracer
 * @brief Contient l'état global de l'application
 */
struct pixel_tracer {
    AreaList *list_area;    /**< Liste des zones de dessin */
    Area *current_area;     /**< Zone active */
    Layer *current_layer;   /**< Calque actif */
    Shape *current_shape;   /**< Forme active */
};

typedef struct pixel_tracer Pixel_tracer_app;

/**
 * @brief Initialise l'application avec une zone et un calque par défaut
 *
 * Crée :
 * - Une liste de zones
 * - Une zone par défaut ("Area1")
 * - Une liste de calques pour cette zone
 * - Un calque par défaut ("Layer 1")
 *
 * @param app Pointeur vers la structure Pixel_tracer_app à initialiser
 */
void init_app(Pixel_tracer_app * app);

/**
 * @brief Détruit l'application et libère toute la mémoire allouée
 *
 * @param app Pointeur vers l'application à détruire
 */
void destry_app(Pixel_tracer_app * app);

#endif
