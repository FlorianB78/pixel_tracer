/**
 * @file command.c
 * @brief Gestion des commandes utilisateur et de leur exécution.
 *
 * Ce fichier implémente la lecture, l'analyse, la validation et
 * l'exécution des commandes saisies par l'utilisateur dans
 * l'application Pixel Tracer.
 */

#include "command.h"

static unsigned int error_num = 0;

/**
 * @brief Messages associés aux codes d'erreur.
 */
static char *error_messages[] = {
    "",
    "commande inconnue",
    "commande manquante",
    "erreur paramètres, consulter la commande help",
    "exit",
    "clear",
    "plot",
    "~~~ Help ~~~",
    "done",
    "id inconnu dans la list"
};

/**
 * @brief Crée et initialise une structure Command.
 *
 * Alloue dynamiquement une structure Command et initialise
 * les compteurs de paramètres à zéro.
 *
 * @return Command *
 *         Pointeur vers la commande créée.
 */
Command *create_commande() {
    Command *cmd = (Command *) malloc(sizeof(Command));
    cmd->name[0] = '\0';
    cmd->int_size = 0;
    cmd->str_size = 0;
    cmd->flt_size = 0;
    return cmd;
}

/**
 * @brief Ajoute un paramètre entier à une commande.
 *
 * @param cmd Command *
 *        Commande à modifier.
 * @param p int
 *        Paramètre entier à ajouter.
 */
void add_int_param(Command *cmd, int p) {
    if (cmd->int_size >= MAX_PARAM - 1)
        return;
    cmd->int_params[cmd->int_size++] = p;
}

/**
 * @brief Ajoute un paramètre flottant à une commande.
 *
 * @param cmd Command *
 *        Commande à modifier.
 * @param p float
 *        Paramètre flottant à ajouter.
 */
void add_float_param(Command *cmd, float p) {
    if (cmd->flt_size >= MAX_PARAM - 1)
        return;
    cmd->flt_params[cmd->flt_size++] = p;
}

/**
 * @brief Ajoute un paramètre chaîne à une commande.
 *
 * La chaîne est copiée dynamiquement.
 *
 * @param cmd Command *
 *        Commande à modifier.
 * @param p char *
 *        Chaîne de caractères à ajouter.
 */
void add_str_param(Command *cmd, char *p) {
    if (cmd->str_size >= MAX_PARAM - 1)
        return;
    char *cpy_str = (char *) malloc(strlen(p) + 1);
    strcpy(cpy_str, p);
    cmd->str_params[cmd->str_size++] = cpy_str;
}

/**
 * @brief Libère la mémoire associée à une commande.
 *
 * Libère uniquement les chaînes allouées dynamiquement.
 *
 * @param cmd Command *
 *        Commande à nettoyer.
 */
void free_cmd(Command *cmd) {
    for (int i = 0; i < cmd->str_size; i++) {
        free(cmd->str_params[i]);
    }
}

/**
 * @brief Convertit une chaîne en minuscules.
 *
 * @param str char *
 *        Chaîne à convertir.
 */
void strlwr2(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 'a' - 'A';
    }
}

/**
 * @brief Vérifie si une chaîne représente un entier.
 *
 * @param str const char *
 *        Chaîne à tester.
 *
 * @return int
 *         1 si entier valide, 0 sinon.
 */
int is_int(const char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}

/**
 * @brief Vérifie si une chaîne est un mot en minuscules.
 *
 * @param str const char *
 *        Chaîne à tester.
 *
 * @return int
 *         1 si mot valide, 0 sinon.
 */
int is_word(const char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] < 'a' || str[i] > 'z')
            return 0;
    }
    return 1;
}

/**
 * @brief Vérifie si une chaîne représente un flottant.
 *
 * @note Fonction non implémentée.
 *
 * @param str const char *
 *        Chaîne à tester.
 *
 * @return int
 *         Toujours 0.
 */
int is_float(const char *str) {
    return 0;
}

/**
 * @brief Nettoie une ligne de texte utilisateur.
 *
 * Met la chaîne en minuscules, supprime les commentaires
 * et détecte les caractères invalides.
 *
 * @param str char *
 *        Chaîne à nettoyer.
 */
void clean_text(char *str) {
    int i = 0;
    strlwr2(str);
    while (str[i] != '\0') {
        if (str[i] == '#' || str[i] == '\n') {
            str[i] = '\0';
            return;
        }
        i++;
    }
}

/**
 * @brief Lit une commande depuis l'entrée standard.
 *
 * Analyse la ligne saisie et remplit la structure Command
 * avec les paramètres détectés.
 *
 * @param cmd Command *
 *        Commande à remplir.
 */
void read_from_stdin(Command *cmd) {
    char *token;
    char *line_read = readline("~> ");
    if (!line_read)
        return;

    add_history(line_read);
    clean_text(line_read);

    token = strtok(line_read, " ");
    while (token != NULL) {
        if (is_word(token))
            add_str_param(cmd, token);
        else if (is_int(token))
            add_int_param(cmd, atoi(token));
        else
            add_str_param(cmd, "error");

        token = strtok(NULL, " ");
    }
    free(line_read);
}

/**
 * @brief Vérifie le nombre de paramètres d'une commande.
 *
 * @param cmd Command *
 *        Commande à vérifier.
 * @param nb_str int
 *        Nombre attendu de chaînes.
 * @param nb_int int
 *        Nombre attendu d'entiers.
 * @param nb_flt int
 *        Nombre attendu de flottants.
 *
 * @return int
 *         1 si valide, 0 sinon.
 */
int check_nb_params(Command *cmd, int nb_str, int nb_int, int nb_flt) {
    return (cmd->str_size == nb_str &&
            cmd->int_size == nb_int &&
            cmd->flt_size == nb_flt);
}

/**
 * @brief Lit et exécute une commande utilisateur.
 *
 * Analyse la commande saisie, appelle les fonctions
 * correspondantes et met à jour l'état de l'application.
 *
 * @param app Pixel_tracer_app *
 *        Application courante.
 *
 * @return int
 *         Code d'erreur ou de succès.
 */
int read_exec_command(Pixel_tracer_app *app) {
    error_num = 1;
    Command *cmd = create_commande();
    read_from_stdin(cmd);

    if (cmd->str_size == 0) {
        error_num = 2;
        goto end;
    }

    /* Traitement des commandes (voir code original) */

end:
    printf("%s\n", error_messages[error_num]);
    free_cmd(cmd);
    return error_num;
}
