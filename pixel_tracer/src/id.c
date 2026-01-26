#include "id.h"

unsigned long long int get_next_id();

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

void set_id(unsigned long long int id) {
    global_id = id;
}

void save_id() {
    // todo save id in file ID_FILE
}

void load_id() {
    // todo load id from file ID_FILE
}
