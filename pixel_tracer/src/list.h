#ifndef _LIST_H_
#define _LIST_H_

/**
 * @file list.h
 * @brief Gestion de listes doublement chaînées génériques.
 *
 * Ce module permet de créer, manipuler et supprimer des listes doublement chaînées
 * pouvant contenir n'importe quel type de données.
 * Chaque élément est représenté par un noeud (`lnode`).
 */

/**
 * @struct lnode_
 * @brief Représente un noeud dans une liste doublement chaînée.
 */
typedef struct lnode_ {
    void *data;             /**< Pointeur vers les données stockées */
    struct lnode_ *prev;    /**< Pointeur vers l'élément précédent */
    struct lnode_ *next;    /**< Pointeur vers l'élément suivant */
} lnode;

/**
 * @struct list_
 * @brief Représente une liste doublement chaînée.
 */
typedef struct list_ {
    lnode *head; /**< Premier noeud de la liste */
    lnode *tail; /**< Dernier noeud de la liste */
} list;

/**
 * @brief Crée un nouveau noeud.
 * @param dat Pointeur vers les données à stocker dans le noeud.
 * @return Pointeur vers le noeud créé.
 */
lnode *lst_create_lnode(void *dat);

/**
 * @brief Crée une nouvelle liste vide.
 * @return Pointeur vers la liste créée.
 */
list *lst_create_list();

/**
 * @brief Supprime une liste et tous ses noeuds.
 * @param lst Liste à supprimer.
 */
void lst_delete_list(list *lst);

/**
 * @brief Insère un noeud au début de la liste.
 * @param lst Liste cible.
 * @param pnew Noeud à insérer.
 */
void lst_insert_head(list *lst, lnode *pnew);

/**
 * @brief Insère un noeud à la fin de la liste.
 * @param lst Liste cible.
 * @param pnew Noeud à insérer.
 */
void lst_insert_tail(list *lst, lnode *pnew);

/**
 * @brief Insère un noeud juste après un autre noeud dans la liste.
 * @param lst Liste cible.
 * @param pnew Noeud à insérer.
 * @param ptr Noeud après lequel insérer.
 */
void lst_insert_after(list *lst, lnode *pnew, lnode *ptr);

/**
 * @brief Supprime le premier noeud de la liste.
 * @param lst Liste cible.
 */
void lst_delete_head(list *lst);

/**
 * @brief Supprime le dernier noeud de la liste.
 * @param lst Liste cible.
 */
void lst_delete_tail(list *lst);

/**
 * @brief Supprime un noeud spécifique de la liste.
 * @param lst Liste cible.
 * @param ptr Noeud à supprimer.
 */
void lst_delete_lnode(list *lst, lnode *ptr);

/**
 * @brief Supprime tous les noeuds de la liste.
 * @param lst Liste cible.
 */
void lst_erase(list *lst);

/**
 * @brief Retourne le premier noeud de la liste.
 * @param lst Liste cible.
 * @return Pointeur vers le premier noeud, NULL si la liste est vide.
 */
lnode *get_first_node(list *lst);

/**
 * @brief Retourne le dernier noeud de la liste.
 * @param lst Liste cible.
 * @return Pointeur vers le dernier noeud, NULL si la liste est vide.
 */
lnode *get_last_node(list *lst);

/**
 * @brief Retourne le noeud suivant d'un noeud donné.
 * @param lst Liste cible.
 * @param lnode Noeud courant.
 * @return Pointeur vers le noeud suivant, NULL si fin de liste.
 */
lnode *get_next_node(list *lst, lnode *lnode);

/**
 * @brief Retourne le noeud précédent d'un noeud donné.
 * @param lst Liste cible.
 * @param lnode Noeud courant.
 * @return Pointeur vers le noeud précédent, NULL si début de liste.
 */
void *get_previous_elem(list *lst, lnode *lnode);

#endif
