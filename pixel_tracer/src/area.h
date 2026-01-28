#include <stdlib.h>
#include <stdio.h>
#include "layers.h"

#ifndef _AREA_H_
#  define _AREA_H_

/**
 * @file area.h
 * @brief Gestion des zones (Area) et des listes de zones.
 *
 * Ce fichier définit la structure Area ainsi que les fonctions permettant
 * de créer, supprimer et manipuler des zones et des listes de zones.
 */

/**
 * @struct area
 * @brief Représente une zone rectangulaire du monde.
 *
 * Une zone contient une grille de caractères, des dimensions, un identifiant,
 * un nom, une liste de couches ainsi que les caractères représentant les
 * cellules vides et pleines.
 */
struct area {
    unsigned char id;          /**< Identifiant unique de la zone */
    char name[255];            /**< Nom de la zone */
    unsigned int width;        /**< Largeur de la zone */
    unsigned int height;       /**< Hauteur de la zone */
    char **area;               /**< Grille représentant la zone */
    LayersList *lst_layers;    /**< Liste des couches associées à la zone */
    char empty_char;           /**< Caractère représentant une cellule vide */
    char full_char;            /**< Caractère représentant une cellule pleine */
};

/**
 * @typedef Area
 * @brief Alias de la structure area.
 */
typedef struct area Area;

/**
 * @typedef AreaList
 * @brief Type représentant une liste de zones.
 */
typedef list AreaList;

/**
 * @brief Crée et initialise une nouvelle zone.
 *
 * Alloue et initialise une structure Area avec ses dimensions, son identifiant,
 * son nom, sa grille, ses caractères par défaut et sa liste de couches.
 *
 * @param width unsigned int
 *        Largeur de la zone.
 * @param height unsigned int
 *        Hauteur de la zone.
 * @param id unsigned char
 *        Identifiant unique de la zone.
 * @param name char *
 *        Nom de la zone.
 *
 * @return Area *
 *         Pointeur vers la zone nouvellement créée.
 */
Area *create_area(unsigned int width,
                  unsigned int height,
                  unsigned char id,
                  char *name);

/**
 * @brief Supprime une zone et libère la mémoire associée.
 *
 * Libère la mémoire allouée pour la grille et la structure Area.
 * Les couches associées ne sont pas encore supprimées.
 *
 * @param area Area *
 *        Zone à supprimer.
 */
void delete_area(Area *area);

/**
 * @brief Réinitialise le contenu d'une zone.
 *
 * Remet la grille de la zone dans un état vide sans détruire la structure
 * ni ses dimensions.
 *
 * @param area Area *
 *        Zone à réinitialiser.
 */
void clear_area(Area *area);

/**
 * @brief Crée une liste de zones.
 *
 * Initialise et retourne une liste vide destinée à contenir des zones.
 *
 * @return AreaList *
 *         Pointeur vers la liste de zones créée.
 */
AreaList *create_area_list();

/**
 * @brief Supprime une liste de zones.
 *
 * Supprime la structure de la liste. Les zones contenues dans la liste
 * ne sont pas supprimées automatiquement.
 *
 * @param area_list AreaList *
 *        Liste de zones à supprimer.
 */
void delete_area_list(AreaList *area_list);

/**
 * @brief Ajoute une zone à une liste de zones.
 *
 * Insère la zone donnée à la fin de la liste de zones.
 *
 * @param area_list AreaList *
 *        Liste dans laquelle ajouter la zone.
 * @param area Area *
 *        Zone à ajouter.
 */
void add_area_to_list(AreaList *area_list, Area *area);

/**
 * @brief Retire une zone d'une liste de zones.
 *
 * Supprime la zone spécifiée de la liste sans libérer la mémoire
 * associée à la zone.
 *
 * @param area_list AreaList *
 *        Liste depuis laquelle retirer la zone.
 * @param area Area *
 *        Zone à retirer.
 */
void remove_area_from_list(AreaList *area_list, Area *area);

#endif /* _AREA_H_ */
