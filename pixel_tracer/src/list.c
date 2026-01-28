/**
 * @file list.c
 * @brief Implémentation des listes doublement chaînées génériques.
 *
 * Ce module fournit toutes les fonctions pour manipuler des listes
 * et leurs noeuds : création, insertion, suppression, accès aux éléments.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * @brief Crée un nouveau noeud avec les données fournies.
 * @param dat Pointeur vers les données à stocker.
 * @return Pointeur vers le noeud créé.
 */
lnode *lst_create_lnode(void *dat) {
    lnode *ptmp = (lnode *) malloc(sizeof(lnode));
    ptmp->data = dat;
    ptmp->next = NULL;
    ptmp->prev = NULL;
    return ptmp;
}

/**
 * @brief Crée une nouvelle liste vide.
 * @return Pointeur vers la liste créée.
 */
list *lst_create_list() {
    list *lst = (list *) malloc(sizeof(list));
    lst->head = NULL;
    lst->tail = NULL;
    return lst;
}

/**
 * @brief Supprime la liste et tous ses noeuds.
 * @param lst Liste à supprimer.
 */
void lst_delete_list(list *lst) {
    lst_erase(lst);
    free(lst);
}

/**
 * @brief Insère un noeud au début de la liste.
 */
void lst_insert_head(list *lst, lnode *pnew) {
    if (lst->head == NULL) {
        lst->head = pnew;
        lst->tail = pnew;
        return;
    }
    pnew->next = lst->head;
    pnew->prev = NULL;
    lst->head = pnew;
    pnew->next->prev = pnew;
}

/**
 * @brief Insère un noeud à la fin de la liste.
 */
void lst_insert_tail(list *lst, lnode *pnew) {
    if (lst->head == NULL) {
        lst->head = pnew;
        lst->tail = pnew;
        return;
    }
    pnew->next = NULL;
    pnew->prev = lst->tail;
    lst->tail = pnew;
    pnew->prev->next = pnew;
}

/**
 * @brief Insère un noeud après un noeud donné.
 */
void lst_insert_after(list *lst, lnode *pnew, lnode *ptr) {
    if (lst->head == NULL) {
        lst->head = pnew;
        lst->tail = pnew;
    } else if (ptr == NULL) {
        return;
    } else if (lst->tail == ptr) {
        lst_insert_tail(lst, pnew);
    } else {
        pnew->next = ptr->next;
        pnew->prev = ptr;
        pnew->next->prev = pnew;
        pnew->prev->next = pnew;
    }
}

/**
 * @brief Supprime le premier noeud de la liste.
 */
void lst_delete_head(list *lst) {
    if (lst->head->next == NULL) {
        free(lst->head);
        lst->head = NULL;
        lst->tail = NULL;
        return;
    }
    lst->head = lst->head->next;
    free(lst->head->prev);
    lst->head->prev = NULL;
}

/**
 * @brief Supprime le dernier noeud de la liste.
 */
void lst_delete_tail(list *lst) {
    if (lst->tail->prev == NULL) {
        free(lst->tail);
        lst->head = NULL;
        lst->tail = NULL;
        return;
    }
    lst->tail = lst->tail->prev;
    free(lst->tail->next);
    lst->tail->next = NULL;
}

/**
 * @brief Supprime un noeud spécifique de la liste.
 */
void lst_delete_lnode(list *lst, lnode *ptr) {
    if (ptr == NULL) return;
    if (ptr == lst->head) {
        lst_delete_head(lst);
        return;
    }
    if (ptr == lst->tail) {
        lst_delete_tail(lst);
        return;
    }
    ptr->next->prev = ptr->prev;
    ptr->prev->next = ptr->next;
    free(ptr);
}

/**
 * @brief Supprime tous les noeuds de la liste.
 */
void lst_erase(list *lst) {
    if (lst->head == NULL) return;
    while (lst->head != lst->tail) {
        lst->head = lst->head->next;
        free(lst->head->prev);
    }
    free(lst->head);
    lst->head = NULL;
    lst->tail = NULL;
}

/**
 * @brief Retourne le premier noeud de la liste.
 */
lnode *get_first_node(list *lst) {
    if (lst->head == NULL) return NULL;
    return lst->head;
}

/**
 * @brief Retourne le dernier noeud de la liste.
 */
lnode *get_last_node(list *lst) {
    if (lst->tail == NULL) return NULL;
    return lst->tail;
}

/**
 * @brief Retourne le noeud suivant d'un noeud donné.
 */
lnode *get_next_node(list *lst, lnode *lnode) {
    if (lnode == NULL) return NULL;
    return lnode->next;
}

/**
 * @brief Retourne le noeud précédent d'un noeud donné.
 */
void *get_previous_elem(list *lst, lnode *lnode) {
    if (lnode == NULL) return NULL;
    return lnode->prev;
}
