#ifndef _PIXEL_TRACER_H_
#  define _PIXEL_TRACER_H_

#  include "list.h"
#  include "id.h"
#  include "area.h"
#  include "layers.h"
#  include "shape.h"
#  include "pixel.h"
#  include "render.h"



struct pixel_tracer {
    AreaList *list_area;
    Area *current_area;
    Layer *current_layer;
    Shape *current_shape;
};


typedef struct pixel_tracer Pixel_tracer_app;


/**
 * Créer une area par defaut 
 */
void init_app(Pixel_tracer_app * app);

void destry_app(Pixel_tracer_app * app);


#endif
