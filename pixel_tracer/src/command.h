#ifndef _COMMAND_H_
#  define _COMMAND_H_

/**
 * @file command.h
 * @brief Interface pour la gestion des commandes utilisateur.
 *
 * Ce module permet de créer, remplir, analyser et exécuter
 * les commandes saisies par l'utilisateur.
 */

#  define MAX_PARAM 30

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "pixel_tracer.h"

/**
 * @struct command
 * @brief Structure représentant une commande utilisateur.
 *
 * Une commande contient :
 * - son nom
 * - des paramètres entiers, flottants et chaînes
 * - les compteurs correspondants
 */
struct command {
    char name[50];                  /**< Nom de la commande */
    int int_size;                   /**< Nombre de paramètres entiers */
    int int_params[MAX_PARAM];      /**< Tableau des paramètres entiers */
    int str_size;                   /**< Nombre de paramètres chaîne */
    char *str_params[MAX_PARAM];    /**< Tableau des paramètres chaîne */
    int flt_size;                   /**< Nombre de paramètres flottants */
    float flt_params[MAX_PARAM];    /**< Tableau des paramètres flottants */
};

typedef struct command Command;

/**
 * @brief Crée et initialise une nouvelle commande.
 *
 * @return Pointeur vers la commande créée.
 */
Command *create_commande();

/**
 * @brief Ajoute un paramètre entier à une commande.
 *
 * @param cmd Commande à modifier.
 * @param p Paramètre entier à ajouter.
 */
void add_int_param(Command *cmd, int p);

/**
 * @brief Ajoute un paramètre flottant à une commande.
 *
 * @param cmd Commande à modifier.
 * @param p Paramètre flottant à ajouter.
 */
void add_float_param(Command *cmd, float p);

/**
 * @brief Ajoute un paramètre chaîne à une commande.
 *
 * @param cmd Commande à modifier.
 * @param p Chaîne de caractères à ajouter.
 */
void add_str_param(Command *cmd, char *p);

/**
 * @brief Libère la mémoire associée aux paramètres chaîne d'une commande.
 *
 * @param cmd Commande à libérer.
 */
void free_cmd(Command *cmd);

/**
 * @brief Lit une commande depuis l'entrée standard.
 *
 * Parse la ligne saisie et remplit la commande avec ses paramètres.
 *
 * @param cmd Commande à remplir.
 */
void read_from_stdin(Command *cmd);

/**
 * @brief Lit et exécute une commande.
 *
 * Analyse la commande saisie et met à jour l'état de l'application.
 *
 * @param app Pointeur vers l'application.
 * @return Code d'erreur ou succès.
 */
int read_exec_command(Pixel_tracer_app *app);

#endif
