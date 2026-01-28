/**
 * @file pixel.c
 * @brief Implémentation des fonctions de création et gestion des pixels
 *
 * Ce fichier contient l'implémentation complète de la conversion
 * des formes en pixels et des algorithmes de tracé des formes :
 * - Points, lignes, carrés, rectangles, cercles, polygones, courbes
 *
 * Il utilise les modules :
 * - list.h : pour gérer la liste de pixels
 * - shape.h : pour accéder aux données des formes
 */

#include "pixel.h"

/**
 * @brief Crée un pixel à une position donnée avec une couleur
 *
 * @param px Coordonnée X
 * @param py Coordonnée Y
 * @param color Couleur du pixel
 * @return Pixel* Pointeur vers le pixel créé
 */
Pixel *create_pixel(int px, int py, int color) {
    Pixel *pixel = (Pixel *) malloc(sizeof(Pixel));
    pixel->px = px;
    pixel->py = py;
    pixel->color = color;
    return pixel;
}

/**
 * @brief Supprime un pixel
 *
 * @param pixel Pointeur vers le pixel à supprimer
 */
void delete_pixel(Pixel * pixel) {
    free(pixel);
}

/**
 * @brief Crée une liste de pixels pour une forme
 *
 * Détermine le type de la forme et appelle la fonction
 * correspondante pour générer les pixels.
 *
 * @param shape Pointeur vers la forme
 * @return list* Liste de pixels générés
 */
list *create_shape_to_pixel(Shape * shape) {
    if (shape->ptrShape == NULL) {
        return NULL;
    }
    list *lst = lst_create_list();

    switch (shape->shape_type) {
    case POINT:
        pixel_point(shape, lst);
        break;
    case LINE:
        pixel_line(shape, lst);
        break;
    case SQUAR:
        pixel_square(shape, lst);
        break;
    case RECTANGLE:
        pixel_rectangle(shape, lst);
        break;
    case CERCLE:
        pixel_cercle(shape, lst);
        break;
    case POLYGON:
        pixel_polygon(shape, lst);
        break;
    case CURVE:
        pixel_curve(shape, lst);
        break;
    }

    return lst;
}

/**
 * @brief Supprime les pixels d'une liste (non implémentée)
 *
 * @param pixel_lst Liste de pixels à supprimer
 */
void remove_pixel_shape(list * pixel_lst) {
    /* TODO */
}

/**
 * @brief Génère les pixels d'un point
 *
 * @param shape Forme de type POINT
 * @param lst Liste dans laquelle insérer les pixels
 */
void pixel_point(Shape * shape, list * lst) {
    Point *pt = (Point *) shape->ptrShape;
    Pixel *px = create_pixel(pt->pos_x, pt->pos_y, shape->color);
    lst_insert_tail(lst, lst_create_lnode(px));
}

/**
 * @brief Trace un segment de pixels entre deux points
 *
 * Utilise l'algorithme de tracé classique (Bresenham-like)
 *
 * @param x Coordonnée de départ X
 * @param y Coordonnée de départ Y
 * @param dx Déplacement X
 * @param dy Déplacement Y
 * @param color Couleur du segment
 * @param lst Liste de pixels
 */
void draw_segment(int x, int y, int dx, int dy, Color color, list * lst) {
    int i, cumul;
    int xinc, yinc;
    Pixel *px;

    xinc = (dx > 0) ? 1 : -1;
    yinc = (dy > 0) ? 1 : -1;
    dx = abs(dx);
    dy = abs(dy);

    px = create_pixel(x, y, color);
    lst_insert_tail(lst, lst_create_lnode(px));

    if (dx > dy) {
        cumul = dx / 2;
        for (i = 1; i <= dx; i++) {
            x += xinc;
            cumul += dy;
            if (cumul >= dx) {
                cumul -= dx;
                y += yinc;
            }
            px = create_pixel(x, y, color);
            lst_insert_tail(lst, lst_create_lnode(px));
        }
    } else {
        cumul = dy / 2;
        for (i = 1; i <= dy; i++) {
            y += yinc;
            cumul += dx;
            if (cumul >= dy) {
                cumul -= dy;
                x += xinc;
            }
            px = create_pixel(x, y, color);
            lst_insert_tail(lst, lst_create_lnode(px));
        }
    }
}

/**
 * @brief Génère les pixels d'une ligne
 *
 * @param shape Forme de type LINE
 * @param lst Liste dans laquelle insérer les pixels
 */
void pixel_line(Shape * shape, list * lst) {
    Line *p_line = (Line *) shape->ptrShape;
    int dx, dy, x, y;

    x = p_line->p1->pos_x;
    y = p_line->p1->pos_y;
    dx = p_line->p2->pos_x - p_line->p1->pos_x;
    dy = p_line->p2->pos_y - p_line->p1->pos_y;
    draw_segment(x, y, dx, dy, shape->color, lst);
}

/**
 * @brief Génère les pixels d'un cercle
 *
 * @param shape Forme de type CERCLE
 * @param lst Liste dans laquelle insérer les pixels
 */
void pixel_cercle(Shape * shape, list * lst) {
    Cercle *p_cercle = (Cercle *) shape->ptrShape;
    int x = 0;
    int y = p_cercle->radus;
    int d = p_cercle->radus - 1;
    Pixel *px;

    while (y >= x) {
        /* Insère tous les octants du cercle */
        px = create_pixel(p_cercle->center->pos_x + x,
                          p_cercle->center->pos_y + y, shape->color);
        lst_insert_tail(lst, lst_create_lnode(px));
        px = create_pixel(p_cercle->center->pos_x + y,
                          p_cercle->center->pos_y + x, shape->color);
        lst_insert_tail(lst, lst_create_lnode(px));

        px = create_pixel(p_cercle->center->pos_x - x,
                          p_cercle->center->pos_y + y, shape->color);
        lst_insert_tail(lst, lst_create_lnode(px));
        px = create_pixel(p_cercle->center->pos_x - y,
                          p_cercle->center->pos_y + x, shape->color);
        lst_insert_tail(lst, lst_create_lnode(px));

        px = create_pixel(p_cercle->center->pos_x + x,
                          p_cercle->center->pos_y - y, shape->color);
        lst_insert_tail(lst, lst_create_lnode(px));
        px = create_pixel(p_cercle->center->pos_x + y,
                          p_cercle->center->pos_y - x, shape->color);
        lst_insert_tail(lst, lst_create_lnode(px));

        px = create_pixel(p_cercle->center->pos_x - x,
                          p_cercle->center->pos_y - y, shape->color);
        lst_insert_tail(lst, lst_create_lnode(px));
        px = create_pixel(p_cercle->center->pos_x - y,
                          p_cercle->center->pos_y - x, shape->color);
        lst_insert_tail(lst, lst_create_lnode(px));

        if (d >= 2 * x) {
            d -= 2 * x + 1;
            x++;
        } else if (d < 2 * (p_cercle->radus - y)) {
            d += 2 * y - 1;
            y--;
        } else {
            d += 2 * (y - x - 1);
            y--;
            x++;
        }
    }
}

/**
 * @brief Génère les pixels d'un rectangle
 *
 * @param shape Forme de type RECTANGLE
 * @param lst Liste de pixels
 */
void pixel_rectangle(Shape * shape, list * lst) {
    Rectangle *p_rec = (Rectangle *) shape->ptrShape;
    draw_segment(p_rec->p1->pos_x, p_rec->p1->pos_y, 0, p_rec->width - 1,
                 shape->color, lst);
    draw_segment(p_rec->p1->pos_x, p_rec->p1->pos_y, p_rec->height - 1, 0,
                 shape->color, lst);
    draw_segment(p_rec->p1->pos_x, p_rec->p1->pos_y + p_rec->width - 1,
                 p_rec->height - 1, 0, shape->color, lst);
    draw_segment(p_rec->p1->pos_x + p_rec->height - 1, p_rec->p1->pos_y, 0,
                 p_rec->width - 1, shape->color, lst);
}

/**
 * @brief Génère les pixels d'un carré
 *
 * @param shape Forme de type SQUAR
 * @param lst Liste de pixels
 */
void pixel_square(Shape * shape, list * lst) {
    Squar *p_sqaure = (Squar *) shape->ptrShape;
    draw_segment(p_sqaure->p1->pos_x, p_sqaure->p1->pos_y,
                 p_sqaure->length - 1, 0, shape->color, lst);
    draw_segment(p_sqaure->p1->pos_x, p_sqaure->p1->pos_y, 0,
                 p_sqaure->length - 1, shape->color, lst);
    draw_segment(p_sqaure->p1->pos_x, p_sqaure->p1->pos_y + p_sqaure->length - 1,
                 p_sqaure->length - 1, 0, shape->color, lst);
    draw_segment(p_sqaure->p1->pos_x + p_sqaure->length - 1, p_sqaure->p1->pos_y,
                 0, p_sqaure->length - 1, shape->color, lst);
}

/**
 * @brief Génère les pixels d'un polygone
 *
 * @param shape Forme de type POLYGON
 * @param lst Liste de pixels
 */
void pixel_polygon(Shape * shape, list * lst) {
    Polygon *poly = (Polygon *) shape->ptrShape;
    for (int i = 1; i < poly->n; i++) {
        Point *p1 = poly->points[i - 1];
        Point *p2 = poly->points[i];
        int dx = p2->pos_x - p1->pos_x;
        int dy = p2->pos_y - p1->pos_y;
        draw_segment(p1->pos_x, p1->pos_y, dx, dy, shape->color, lst);
    }
}

/**
 * @brief Calcule le point intermédiaire entre deux points
 *
 * @param p1 Premier point
 * @param p2 Deuxième point
 * @param t Paramètre entre 0 et 1
 * @return Point Point interpolé
 */
Point calc_point_median(Point * p1, Point * p2, double t) {
    double x = p1->pos_x * (1 - t) + p2->pos_x * t;
    double y = p1->pos_y * (1 - t) + p2->pos_y * t;
    Point result = { x, y };
    return result;
}

/**
 * @brief Calcule un point sur la courbe de Bezier via Casteljau
 *
 * @param points Tableau de points de contrôle
 * @param num_pt Nombre de points
 * @param t Paramètre entre 0 et 1
 * @return Point Calculé sur la courbe
 */
Point cj_calc(Point ** points, int num_pt, double t) {
    Point tmp_pt[num_pt];
    for (int i = 0; i < num_pt; ++i) {
        tmp_pt[i] = *points[i];
    }
    for (int i = num_pt - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            tmp_pt[j] = calc_point_median(&tmp_pt[j], &tmp_pt[j + 1], t);
        }
    }
    return tmp_pt[0];
}

/**
 * @brief Génère les pixels pour une courbe de Bezier
 *
 * @param shape Forme de type CURVE
 * @param lst Liste de pixels
 */
void pixel_curve(Shape * shape, list * lst) {
    Curve *p_curve = (Curve *) shape->ptrShape;
    Point *points[] = { p_curve->p1, p_curve->p2, p_curve->p3, p_curve->p4 };
    int num_pt = sizeof(points) / sizeof(Point *);
    double t;

    for (t = 0; t < 1.0; t += 0.0001) {
        Point cjp1 = cj_calc(points, num_pt, t);
        Pixel *px = create_pixel(cjp1.pos_x, cjp1.pos_y, shape->color);
        lst_insert_tail(lst, lst_create_lnode(px));
    }
}
