#include <stdlib.h>
#include <stdio.h>
#include "layers.h"

#ifndef _AREA_H_
#  define _AREA_H_

/**
 * @file area.h
 * @brief Définition des structures et fonctions de gestion des zones (Area).
 *
 * Ce module permet de créer, manipuler et supprimer des zones rectangulaires,
 * ainsi que de gérer des listes de zones et leurs couches (layers).
 */

#include <stdlib.h>
#include <stdio.h>
#include "layers.h"

/**
 * @struct area
 * @brief Structure représentant une zone rectangulaire.
 *
 * Une zone contient sa taille, son identifiant, son nom,
 * la grille de caractères, et la liste de ses couches.
 */
struct area {
    unsigned char id;          /**< Identifiant unique de la zone */
    char name[255];            /**< Nom de la zone */
    unsigned int width;        /**< Largeur de la zone */
    unsigned int height;       /**< Hauteur de la zone */
    char **area;               /**< Grille de caractères représentant la zone */
    LayersList *lst_layers;    /**< Liste des couches de la zone */
    char empty_char;           /**< Caractère représentant une case vide */
    char full_char;            /**< Caractère représentant une case pleine */
};

typedef struct area Area;

/** @typedef AreaList
 *  @brief Liste de zones.
 */
typedef list AreaList;

/**
 * @brief Crée une nouvelle zone.
 *
 * Alloue dynamiquement une zone et sa grille.
 *
 * @param width Largeur de la zone.
 * @param height Hauteur de la zone.
 * @param id Identifiant unique de la zone.
 * @param name Nom de la zone.
 * @return Pointeur vers la zone créée.
 */
Area *create_area(unsigned int width, unsigned int height,
                  unsigned char id, char *name);

/**
 * @brief Supprime une zone et libère sa mémoire.
 *
 * @param area Pointeur vers la zone à supprimer.
 */
void delete_area(Area *area);

/**
 * @brief Vide une zone en remettant toutes les cases à empty_char.
 *
 * @param area Pointeur vers la zone à vider.
 */
void clear_area(Area *area);

/**
 * @brief Crée une liste de zones.
 *
 * @return Pointeur vers la liste créée.
 */
AreaList *create_area_list();

/**
 * @brief Supprime une liste de zones et libère sa mémoire.
 *
 * @param area_list Pointeur vers la liste à supprimer.
 */
void delete_area_list(AreaList *area_list);

/**
 * @brief Ajoute une zone à une liste.
 *
 * @param area_list Pointeur vers la liste.
 * @param area Pointeur vers la zone à ajouter.
 */
void add_area_to_list(AreaList *area_list, Area *area);

/**
 * @brief Supprime une zone d'une liste.
 *
 * @param area_list Pointeur vers la liste.
 * @param area Pointeur vers la zone à supprimer.
 */
void remove_area_from_list(AreaList *area_list, Area *area);

#endif /* _AREA_H_ */
