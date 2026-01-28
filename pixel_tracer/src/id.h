#ifndef _ID_H_
#  define _ID_H_

/**
 * @file id.h
 * @brief Gestion des identifiants uniques persistants.
 */

#  define ID_FILE "id.txt"

/**
 * @brief Génère un nouvel identifiant unique.
 *
 * @return unsigned long long int
 *         Identifiant généré.
 */
unsigned long long int get_next_id();

/**
 * @brief Définit la valeur courante de l'identifiant.
 *
 * @param id Nouvelle valeur de l'identifiant.
 */
void set_id(unsigned long long int id);

/**
 * @brief Sauvegarde l'identifiant courant.
 */
void save_id();

/**
 * @brief Charge l'identifiant sauvegardé.
 */
void load_id();

#endif
