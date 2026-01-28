#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "id.h"
#include "shape.h"

/** @brief Crée un point */
Point *create_point(int px, int py) {
    Point *p = (Point *) malloc(sizeof(Point));
    p->pos_x = px;
    p->pos_y = py;
    return p;
}

/** @brief Supprime un point */
void delete_point(Point * point) {
    free(point);
}

/** @brief Crée une ligne entre deux points */
Line *create_line(Point * p1, Point * p2) {
    Line *l = (Line *) malloc(sizeof(Line));
    l->p1 = p1;
    l->p2 = p2;
    return l;
}

/** @brief Supprime une ligne et ses points */
void delete_line(Line * line) {
    delete_point(line->p1);
    delete_point(line->p2);
    free(line);
}

/** @brief Crée un carré */
Squar *create_squar(Point * point, int length) {
    Squar *squar = (Squar *) malloc(sizeof(Squar));
    squar->p1 = point;
    squar->length = length;
    return squar;
}

/** @brief Supprime un carré et son point */
void delete_squar(Squar * squar) {
    delete_point(squar->p1);
    free(squar);
}

/** @brief Crée un rectangle */
Rectangle *create_rectangle(Point * point, int width, int height) {
    Rectangle *rec = (Rectangle *) malloc(sizeof(Rectangle));
    rec->p1 = point;
    rec->width = width;
    rec->height = height;
    return rec;
}

/** @brief Supprime un rectangle et son point */
void delete_rectangle(Rectangle * rectangle) {
    delete_point(rectangle->p1);
    free(rectangle);
}

/** @brief Crée un cercle */
Cercle *create_cercle(Point * center, int radus) {
    Cercle *cercle = (Cercle *) malloc(sizeof(Cercle));
    cercle->center = center;
    cercle->radus = radus;
    return cercle;
}

/** @brief Supprime un cercle et son centre */
void delete_cercle(Cercle * cercle) {
    delete_point(cercle->center);
    free(cercle);
}

/** @brief Crée un polygone avec n points */
Polygon *create_polygon(int n) {
    Polygon *poly = (Polygon *) malloc(sizeof(Polygon));
    poly->points = (Point **) malloc(sizeof(Point *) * n);
    poly->n = n;
    for (int i = 0; i < n; i++) {
        poly->points[i] = NULL;
    }
    return poly;
}

/** @brief Supprime un polygone et tous ses points */
void delete_polygon(Polygon * polygon) {
    for (int i = 0; i < polygon->n; i++) {
        delete_point(polygon->points[i]);
    }
    free(polygon->points);
    free(polygon);
}

/** @brief Crée une courbe de Bézier */
Curve *create_curve(Point * p1, Point * p2, Point * p3, Point * p4) {
    Curve *cur = (Curve *) malloc(sizeof(Curve));
    cur->p1 = p1;
    cur->p2 = p2;
    cur->p3 = p3;
    cur->p4 = p4;
    return cur;
}

/** @brief Supprime une courbe et ses points */
void delete_curve(Curve * curve) {
    delete_point(curve->p1);
    delete_point(curve->p2);
    delete_point(curve->p3);
    delete_point(curve->p4);
    free(curve);
}

/** @brief Crée une Shape vide */
Shape *create_empty_shape(Shape_type shape_type) {
    Shape *shp = (Shape *) malloc(sizeof(Shape));
    shp->id = get_next_id();
    shp->shape_type = shape_type;
    shp->color = BLACK;
    shp->ptrShape = NULL;
    shp->thickness = 1.0;
    shp->rotation = 0.0;
    return shp;
}

/** @brief Sérialisation point en chaîne */
void sprint_point(Point * p, char *str) {
    sprintf(str, "%d %d", p->pos_x, p->pos_y);
}

/** @brief Sérialisation ligne en chaîne */
void sprint_line(Line * line, char *str) {
    char str1[50], str2[50];
    sprint_point(line->p1, str1);
    sprint_point(line->p2, str2);
    sprintf(str, "%s %s", str1, str2);
}

/** @brief Sérialisation carré en chaîne */
void sprint_squar(Squar * squar, char *str) {
    char str1[50];
    sprint_point(squar->p1, str1);
    sprintf(str, "%s %d %d", str1, squar->length, squar->length);
}

/** @brief Sérialisation rectangle en chaîne */
void sprint_rectangle(Rectangle * rectangle, char *str) {
    char str1[50];
    sprint_point(rectangle->p1, str1);
    sprintf(str, "%s %d %d", str1, rectangle->width, rectangle->height);
}

/** @brief Sérialisation cercle en chaîne */
void sprint_cercle(Cercle * cercle, char *str) {
    char str1[50];
    sprint_point(cercle->center, str1);
    sprintf(str, "%s %d", str1, cercle->radus);
}

/** @brief Sérialisation polygone en chaîne */
void sprint_polygon(Polygon * polygon, char *str) {
    char str_res[200] = {0};
    char str1[50];
    for (int i = 0; i < polygon->n; i++) {
        sprint_point(polygon->points[i], str1);
        strcat(str_res, str1);
        strcat(str_res, " ");
    }
    sprintf(str, "%s", str_res);
}

/** @brief Sérialisation courbe en chaîne */
void sprint_curve(Curve * curve, char *str) {
    char str1[50], str2[50], str3[50], str4[50];
    sprint_point(curve->p1, str1);
    sprint_point(curve->p2, str2);
    sprint_point(curve->p3, str3);
    sprint_point(curve->p4, str4);
    sprintf(str, "%s %s %s %s", str1, str2, str3, str4);
}

/** @brief Crée une Shape Point */
Shape *create_point_shape(int px, int py) {
    Shape *shp = create_empty_shape(POINT);
    shp->ptrShape = create_point(px, py);
    return shp;
}

/** @brief Crée une Shape Line */
Shape *create_line_shape(int px1, int py1, int px2, int py2) {
    Shape *shp = create_empty_shape(LINE);
    shp->ptrShape = create_line(create_point(px1, py1), create_point(px2, py2));
    return shp;
}

/** @brief Crée une Shape Square */
Shape *create_square_shape(int px, int py, int length) {
    Shape *shp = create_empty_shape(SQUAR);
    shp->ptrShape = create_squar(create_point(px, py), length);
    return shp;
}

/** @brief Crée une Shape Rectangle */
Shape *create_rectangle_shape(int px, int py, int width, int height) {
    Shape *shp = create_empty_shape(RECTANGLE);
    shp->ptrShape = create_rectangle(create_point(px, py), width, height);
    return shp;
}

/** @brief Crée une Shape Cercle */
Shape *create_cercle_shape(int px, int py, int radus) {
    Shape *shp = create_empty_shape(CERCLE);
    shp->ptrShape = create_cercle(create_point(px, py), radus);
    return shp;
}

/** @brief Crée une Shape Polygon à partir d'un tableau de coordonnées */
Shape *create_polygon_shape(int n, int *tab) {
    if (n % 2 != 0) return NULL;
    Shape *shp = create_empty_shape(POLYGON);
    Polygon *poly = create_polygon(n / 2);
    int k = 0;
    for (int i = 0; i < n; i += 2)
        poly->points[k++] = create_point(tab[i], tab[i + 1]);
    shp->ptrShape = poly;
    return shp;
}

/** @brief Crée une Shape Curve */
Shape *create_curve_shape(int px1, int py1, int px2, int py2, int px3,
                          int py3, int px4, int py4) {
    Shape *shp = create_empty_shape(CURVE);
    shp->ptrShape = create_curve(create_point(px1, py1),
                                 create_point(px2, py2),
                                 create_point(px3, py3),
                                 create_point(px4, py4));
    return shp;
}

/** @brief Supprime une Shape et toutes ses formes internes */
void delete_shape(Shape * shape) {
    if (!shape->ptrShape) { free(shape); return; }
    switch (shape->shape_type) {
        case POINT: delete_point(shape->ptrShape); break;
        case LINE: delete_line(shape->ptrShape); break;
        case SQUAR: delete_squar(shape->ptrShape); break;
        case RECTANGLE: delete_rectangle(shape->ptrShape); break;
        case CERCLE: delete_cercle(shape->ptrShape); break;
        case POLYGON: delete_polygon(shape->ptrShape); break;
        case CURVE: delete_curve(shape->ptrShape); break;
    }
    free(shape);
}

/** @brief Sérialise une Shape en chaîne de caractères */
void sprint_shape(Shape * shape, char *str) {
    if (!shape->ptrShape) return;
    switch (shape->shape_type) {
        case POINT: sprint_point(shape->ptrShape, str); break;
        case LINE: sprint_line(shape->ptrShape, str); break;
        case SQUAR: sprint_squar(shape->ptrShape, str); break;
        case RECTANGLE: sprint_rectangle(shape->ptrShape, str); break;
        case CERCLE: sprint_cercle(shape->ptrShape, str); break;
        case POLYGON: sprint_polygon(shape->ptrShape, str); break;
        case CURVE: sprint_curve(shape->ptrShape, str); break;
    }
}
