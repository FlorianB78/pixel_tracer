#include "id.h"

static unsigned long long int global_id = 0;

/**
 * @brief Génère et retourne un nouvel identifiant unique.
 *
 * Cette fonction incrémente l'identifiant global interne et retourne
 * sa nouvelle valeur. Elle permet de garantir l'unicité des identifiants
 * générés au cours de l'exécution du programme.
 *
 * @return unsigned long long int
 *         Le nouvel identifiant généré.
 */
unsigned long long int get_next_id() {
    global_id++;
    return global_id;
}

/**
 * @brief Définit manuellement la valeur de l'identifiant global.
 *
 * Cette fonction permet d'initialiser ou de modifier l'identifiant global
 * utilisé pour la génération des prochains identifiants.
 *
 * @param id unsigned long long int
 *        Nouvelle valeur à assigner à l'identifiant global.
 */
void set_id(unsigned long long int id) {
    global_id = id;
}

/**
 * @brief Sauvegarde l'identifiant global courant.
 *
 * Cette fonction est destinée à enregistrer la valeur actuelle de
 * l'identifiant global dans un fichier (par exemple ID_FILE) afin de
 * permettre sa restauration lors d'une prochaine exécution du programme.
 *
 * @note Fonction non implémentée pour le moment.
 */
void save_id() {
    // todo save id in file ID_FILE
}

/**
 * @brief Charge l'identifiant global depuis une source persistante.
 *
 * Cette fonction est destinée à charger la valeur de l'identifiant global
 * depuis un fichier (par exemple ID_FILE) afin de reprendre la génération
 * des identifiants sans collision.
 *
 * @note Fonction non implémentée pour le moment.
 */
void load_id() {
    // todo load id from file ID_FILE
}
