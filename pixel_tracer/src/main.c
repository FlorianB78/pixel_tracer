/**
 * @file main.c
 * @brief Point d'entrée de l'application Pixel Tracer
 *
 * Ce fichier contient la fonction main() qui initialise l'application,
 * gère la boucle principale de lecture et d'exécution des commandes,
 * et affiche la zone et ses couches.
 *
 * Il utilise les modules suivants :
 * - pixel_tracer.h : structures et fonctions principales de l'application
 * - command.h : lecture et exécution des commandes utilisateurs
 */

#include <stdio.h>
#include <stdlib.h>
#include "pixel_tracer.h"
#include "command.h"

/**
 * @brief Point d'entrée du programme.
 *
 * Fonction principale qui :
 * - Initialise l'application Pixel Tracer
 * - Vide l'écran et affiche la zone initiale
 * - Boucle de lecture/exécution des commandes
 * - Met à jour l'affichage après certaines commandes
 * - Termine proprement l'application à la commande "exit"
 *
 * @return int Code de sortie (0 si succès)
 */
int main() {
    Pixel_tracer_app app;

    /** Initialise l'application */
    init_app(&app);

    /** Vide l'écran et dessine l'état initial */
    clear_screen();
    draw_all_layers(app.current_area);
    draw_area(app.current_area);

    /** Boucle principale */
    while (1) {
        /** Lecture et exécution de la commande utilisateur */
        int err = read_exec_command(&app);

        /** Mise à jour de l'affichage selon la commande exécutée */
        if (err == 0 || err == 6) {
            clear_screen();
            draw_all_layers(app.current_area);  // générer les pixels
            draw_area(app.current_area);        // rendre l'affichage
        }

        /** Commande "plot" spécifique */
        if (err == 6) {
            clear_screen();
            draw_all_layers(app.current_area);
            draw_area(app.current_area);
        }

        /** Commande "exit" */
        if (err == 4) {
            break;
        }

        /** Commande "clear" */
        if (err == 5) {
            clear_screen();
        }

        /** Commandes help et autres affichages non bloquants */
        if (err == 7 || err == 8) {
            continue;
        }
    }

    /** Libération des ressources de l'application */
    destry_app(&app);

    return 0;
}
