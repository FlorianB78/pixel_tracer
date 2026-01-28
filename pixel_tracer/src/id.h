#ifndef _ID_H_
#  define _ID_H_

/**
 * @file id.h
 * @brief Gestion de la génération et de la persistance des identifiants uniques.
 *
 * Ce fichier contient les déclarations des fonctions permettant de générer,
 * définir, sauvegarder et charger des identifiants uniques utilisés dans
 * l'application.
 */

/**
 * @def ID_FILE
 * @brief Fichier de sauvegarde de l'identifiant global.
 *
 * Constante définissant le nom du fichier dans lequel l'identifiant global
 * est sauvegardé afin d'assurer la persistance entre deux exécutions.
 */
#  define ID_FILE "id.txt"

/**
 * @brief Génère et retourne un nouvel identifiant unique.
 *
 * Incrémente l'identifiant global interne et retourne sa nouvelle valeur.
 * Cette fonction garantit l'unicité des identifiants générés pendant
 * l'exécution du programme.
 *
 * @return unsigned long long int
 *         Le nouvel identifiant généré.
 */
unsigned long long int get_next_id();

/**
 * @brief Définit manuellement la valeur de l'identifiant global.
 *
 * Permet d'initialiser ou de modifier la valeur de l'identifiant global
 * utilisé par le générateur d'identifiants.
 *
 * @param id unsigned long long int
 *        Nouvelle valeur à assigner à l'identifiant global.
 */
void set_id(unsigned long long int id);

/**
 * @brief Sauvegarde l'identifiant global courant.
 *
 * Enregistre la valeur actuelle de l'identifiant global dans le fichier
 * défini par la constante ID_FILE afin de permettre sa restauration
 * ultérieure.
 */
void save_id();

/**
 * @brief Charge l'identifiant global depuis un fichier.
 *
 * Charge la valeur de l'identifiant global depuis le fichier défini par
 * la constante ID_FILE afin d'assurer la continuité de la génération
 * des identifiants.
 */
void load_id();

#endif /* _ID_H_ */
