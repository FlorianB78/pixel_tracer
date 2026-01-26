#ifndef _PIXEL_H_
#  define _PIXEL_H_

#  include <stdlib.h>
#  include "shape.h"
#  include "list.h"


struct pixel {
    int px;
    int py;
    int color;
};

typedef struct pixel Pixel;


/* to export*/
list *create_shape_to_pixel(Shape * shape);

void remove_pixel_shape(list * pixel_lst);


/* private functions */

Pixel *create_pixel(int px, int py, int color);

void delete_pixel(Pixel * pixel);

void pixel_point(Shape * shape, list * lst);

void pixel_line(Shape * shape, list * lst);

void pixel_cercle(Shape * shape, list * lst);

void pixel_rectangle(Shape * shape, list * lst);

void pixel_square(Shape * shape, list * lst);

void pixel_polygon(Shape * shape, list * lst);

void pixel_curve(Shape * shape, list * lst);




#endif
