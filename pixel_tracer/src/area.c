#include "area.h"


/**
 * @brief Crée et initialise une nouvelle zone (Area).
 *
 * Alloue dynamiquement une structure Area, initialise ses dimensions,
 * son identifiant, son nom, ses caractères par défaut, sa liste de couches
 * ainsi que la grille représentant la zone.
 *
 * @param width unsigned int
 *        Largeur de la zone à créer.
 * @param height unsigned int
 *        Hauteur de la zone à créer.
 * @param id unsigned char
 *        Identifiant unique de la zone.
 * @param name char *
 *        Nom de la zone.
 *
 * @return Area *
 *         Pointeur vers la zone nouvellement créée.
 */
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

/**
 * @brief Supprime une zone et libère la mémoire associée.
 *
 * Libère la mémoire allouée pour la grille de la zone ainsi que la structure
 * Area elle-même. Les couches associées à la zone ne sont pas encore supprimées.
 *
 * @param area Area *
 *        Pointeur vers la zone à supprimer.
 *
 * @note La suppression des couches est à implémenter.
 */
void delete_area(Area *area){
    // todo: delate layers
    for (unsigned int i = 0; i < area->height; i++) {
        free(area->area[i]);
    }
    free(area);
}

/**
 * @brief Crée une liste de zones.
 *
 * Initialise et retourne une liste vide destinée à contenir des zones (Area).
 *
 * @return AreaList *
 *         Pointeur vers la liste de zones nouvellement créée.
 */
AreaList *create_area_list() {
    AreaList *lst_area;
    lst_area = lst_create_list();
    return lst_area;


}

/**
 * @brief Supprime une liste de zones.
 *
 * Supprime la structure de la liste de zones. Les zones contenues dans
 * la liste ne sont pas supprimées automatiquement.
 *
 * @param area_list AreaList *
 *        Pointeur vers la liste de zones à supprimer.
 *
 * @note La suppression des zones contenues dans la liste est à implémenter.
 */
void delete_area_list(AreaList * area_list) {
    /* TODO : delete all layers on the list */
    lst_delete_list(area_list);

}

/**
 * @brief Ajoute une zone à une liste de zones.
 *
 * Crée un nouveau nœud de liste contenant la zone fournie et l'insère
 * à la fin de la liste de zones.
 *
 * @param area_list AreaList *
 *        Liste dans laquelle ajouter la zone.
 * @param area Area *
 *        Zone à ajouter à la liste.
 */
void add_area_to_list(AreaList * area_list, Area * area) {
    lnode *l = lst_create_lnode(area);
    lst_insert_tail(area_list, l);
}

/**
 * @brief Retire une zone d'une liste de zones.
 *
 * Supprime la zone spécifiée de la liste de zones sans libérer
 * la mémoire associée à la zone elle-même.
 *
 * @param area_list AreaList *
 *        Liste depuis laquelle retirer la zone.
 * @param area Area *
 *        Zone à retirer de la liste.
 *
 * @note Fonction non implémentée pour le moment.
 */
void remove_area_from_list(AreaList * area_list, Area * area) {
    /* TODO  */

}
