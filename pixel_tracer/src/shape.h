#ifndef _SHAPE_H_
#define _SHAPE_H_

/**
 * @file shape.h
 * @brief Gestion des formes géométriques pour Pixel Tracer.
 *
 * Ce module fournit des types de données et des fonctions pour créer,
 * manipuler et supprimer des formes géométriques telles que Point, Line,
 * Square, Rectangle, Circle, Polygon et Curve.
 *
 * Structures principales :
 *  - Point, Line, Squar, Rectangle, Cercle, Polygon, Curve
 *  - Shape : encapsule une forme avec ID, couleur, rotation et remplissage
 *
 * Fonctions exportées :
 *  - Création et destruction de formes individuelles
 *  - Création de Shape "exportable" pour l'API
 *  - Fonctions de sérialisation des formes (sprint_*)
 */

typedef enum shape_type { POINT, LINE, SQUAR, RECTANGLE, CERCLE,
    POLYGON, CURVE
} Shape_type;

typedef enum color { BLACK, WIGHT, RED, GREEN } Color;

/** @struct Point */
struct point {
    int pos_x;
    int pos_y;
};
typedef struct point Point;

/** @struct Line */
struct line {
    Point *p1;
    Point *p2;
};
typedef struct line Line;

/** @struct Squar */
struct squar {
    Point *p1;
    int length;
};
typedef struct squar Squar;

/** @struct Rectangle */
struct rectangle {
    Point *p1;
    int width;
    int height;
};
typedef struct rectangle Rectangle;

/** @struct Cercle */
struct cercle {
    Point *center;
    int radus;
};
typedef struct cercle Cercle;

/** @struct Polygon */
struct polygon {
    int n;
    Point **points;
};
typedef struct polygon Polygon;

/** @struct Curve */
struct curve {
    Point *p1;
    Point *p2;
    Point *p3;
    Point *p4;
};
typedef struct curve Curve;

/** @struct Shape
 *  Structure générique pour représenter une forme avec ID, type, couleur, rotation, etc.
 */
struct shape {
    unsigned long long int id;
    Shape_type shape_type;
    void *ptrShape;  /**< pointeur vers la forme spécifique */
    unsigned char fill;
    float thickness;
    Color color;
    double rotation;
};
typedef struct shape Shape;


/** Création et destruction des formes de base */
Point *create_point(int px, int py);
void delete_point(Point * point);
Line *create_line(Point * p1, Point * p2);
void delete_line(Line * line);
Squar *create_squar(Point * point, int legth);
void delete_squar(Squar * squar);
Rectangle *create_rectangle(Point * point, int width, int height);
void delete_rectangle(Rectangle * rectangle);
Cercle *create_cercle(Point * center, int radus);
void delete_cercle(Cercle * cercle);
Polygon *create_polygon(int n);
void delete_polygon(Polygon * polygon);
Curve *create_curve(Point * p1, Point * p2, Point * p3, Point * p4);
void delete_curve(Curve * curve);

/** Création d'une Shape vide */
Shape *create_empty_shape(Shape_type shape_type);

/** Sérialisation des formes en chaîne de caractères */
void sprint_point(Point * p, char *str);
void sprint_line(Line * line, char *str);
void sprint_squar(Squar * squar, char *str);
void sprint_rectangle(Rectangle * rectangle, char *str);
void sprint_cercle(Cercle * cercle, char *str);
void sprint_polygon(Polygon * polygon, char *str);
void sprint_curve(Curve * curve, char *str);


/** Fonctions exportées pour créer des Shapes directement */
Shape *create_point_shape(int px, int py);
Shape *create_line_shape(int px1, int py1, int px2, int py2);
Shape *create_square_shape(int px, int py, int length);
Shape *create_rectangle_shape(int px, int py, int width, int height);
Shape *create_cercle_shape(int px, int py, int radus);
Shape *create_polygon_shape(int n, int *tab);
Shape *create_curve_shape(int px1, int py1, int px2, int py2, int px3,
                          int py3, int px4, int py4);

/** Supprime une Shape et toutes ses formes internes */
void delete_shape(Shape * shape);

/** Sérialisation d'une Shape en chaîne de caractères */
void sprint_shape(Shape * shape, char *str);

#endif
