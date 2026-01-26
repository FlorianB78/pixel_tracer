#include "command.h"

static unsigned int error_num = 0;
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
        /* liste à compléter */
};

Command *create_commande() {
    Command *cmd = (Command *) malloc(sizeof(Command));
    cmd->name[0] = '\0';
    cmd->int_size = 0;
    cmd->str_size = 0;
    cmd->flt_size = 0;
    return cmd;
}

void add_int_param(Command * cmd, int p) {
    if (cmd->int_size >= MAX_PARAM - 1)
        return;
    cmd->int_params[cmd->int_size] = p;
    cmd->int_size = cmd->int_size + 1;
}

void add_float_param(Command * cmd, float p) {
    if (cmd->flt_size >= MAX_PARAM - 1)
        return;
    cmd->flt_params[cmd->flt_size] = p;
    cmd->flt_size = cmd->flt_size + 1;
}

void add_str_param(Command * cmd, char *p) {
    if (cmd->str_size >= MAX_PARAM - 1)
        return;
    char *cpy_str = (char *) malloc(strlen(p) + 1);
    strcpy(cpy_str, p);
    cmd->str_params[cmd->str_size] = cpy_str;
    cmd->str_size = cmd->str_size + 1;
}

void free_cmd(Command * cmd) {
    int i;
    for (i = 0; i < cmd->str_size; i++) {
        free(cmd->str_params[i]);
    }
}

void strlwr2(char *str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if ((str[i] >= 'A') && (str[i] <= 'Z')) {
            str[i] += 'a' - 'A';
        }
    }
}

int is_int(const char *str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if ((str[i] < '0') || (str[i] > '9')) {
            return 0;
        }
    }
    return 1;
}

int is_word(const char *str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if ((str[i] < 'a') || (str[i] > 'z')) {
            return 0;
        }
    }
    return 1;
}


int is_float(const char *str) {
    return 0;                   /* TODO  */
}

void clean_text(char *str) {
    int i = 0;
    strlwr2(str);
    while (str[i] != '\0') {
        if (str[i] == '#' || str[i] == '\n') {
            str[i] = '\0';
            return;
        }
        if (((str[i] < '0') && (str[i] > '9')) && (str[i] < 'a')
            && (str[i] > 'z')) {
            strcpy(str, "error carractere inattendu !");
            return;
        }
        i++;
    }
}

void read_from_stdin(Command * cmd) {
    char *str1, *token;
    int nb_str = 0, nb_int = 0, nb_float = 0;
    char *line_read = (char *) NULL;
    char prompt[4] = "~> ";
    line_read = readline(prompt);
    if (line_read && *line_read) {
        add_history(line_read);
    } else {
        return;                 /* rien lu */
    }
    clean_text(line_read);

    token = strtok(line_read, " ");
    while (token != NULL) {
        if (cmd->str_size > MAX_PARAM || cmd->int_size > MAX_PARAM
            || cmd->flt_size > MAX_PARAM)
            return;             /* nb max args */

        if (is_word(token)) {
            add_str_param(cmd, token);
        } else if (is_int(token)) {
            add_int_param(cmd, atoi(token));
        } else if (is_float(token)) {
            add_float_param(cmd, atof(token));
        } else {
            // error ligne
            add_str_param(cmd, "error");
            add_str_param(cmd, "line");
        }
        token = strtok(NULL, " ");
    }
    free(line_read);
}


void debug_cmd(Command * cmd) {
    printf("\n --- \n");
    printf("str:\n");
    for (int i = 0; i < cmd->str_size; i++) {
        printf("<%s>\n", cmd->str_params[i]);
    }
    printf("int:\n");
    for (int i = 0; i < cmd->int_size; i++) {
        printf("<%d>\n", cmd->int_params[i]);
    }
    printf("float:\n");
    for (int i = 0; i < cmd->flt_size; i++) {
        printf("<%f>\n", cmd->flt_params[i]);
    }
}


void print_help() {
    printf("\t%s\n", "**************************************************");
    printf("\t%s\n", "****         VECTOR TEXT-BASED EDITOR         ****");
    printf("\t%s\n", "**************************************************");

    printf("\t%s\n", "==== Control ====");

    printf("\t%s\n", "clear : clear screen ");
    printf("\t%s\n", "exit : exit the program ");
    printf("\t%s\n", "help : print this help ");
    printf("\t%s\n", "plot : draw dcreen");

    printf("\t%s\n", "==== Draw shapes ====");

    printf("\t%s\n", "point px py : create point a position (px, px)");
    printf("\t%s\n",
           "line x1 y1 x2 x2 : draw line from (x1, y1) to (x1, y1)");
    printf("\t%s\n", "square x1 y1 l : draw square (x1, y1)  length ");
    printf("\t%s\n",
           "rectangle x1 y1 w h : draw square (x1, y1)  width height ");
    printf("\t%s\n", "circle x y r : center at (x, y) radus r");
    printf("\t%s\n", "polygon x1 y1 x2 y2 ... : draw polygon ");
    printf("\t%s\n", "curve x1 y1 x2 y2 x3 y3 x4 y4 : draw Bezier curve ");

    printf("\t%s\n", "==== Draw manager ====");

    printf("\t%s\n", "list {layers, arias, shapes}");
    printf("\t%s\n", "select {aria, layer} {id}");
    printf("\t%s\n", "delete {aria, layer, shape} {id}");
    printf("\t%s\n", "new {aria, layer}");

    printf("\t%s\n", "==== Set ====");
    printf("\t%s\n", "set char {border, background} ascii_code");
    printf("\t%s\n", "set layer {visible, unvisible} {id}");
    printf("\t%s\n", "==== Bugs ====");
    printf("\t%s\n",
           "If you find any bug please send an email to : hdd@halim.info");
}


int check_nb_params(Command * cmd, int nb_str, int nb_int, int nb_flt) {
    if (cmd->str_size != nb_str)
        return 0;
    if (cmd->int_size != nb_int)
        return 0;
    if (cmd->flt_size != nb_flt)
        return 0;
    return 1;
}

int check_nb_params_polygon(Command * cmd) {
    if (cmd->str_size != 1)
        return 0;
    if ((cmd->int_size == 0) || (cmd->int_size >= MAX_PARAM)
        || (cmd->int_size % 2 != 0))
        return 0;
    if (cmd->flt_size != 0)
        return 0;
    return 1;
}


int read_exec_command(Pixel_tracer_app * app) {
    error_num = 1;
    Command *cmd = create_commande();
    read_from_stdin(cmd);
    // debug_cmd(cmd);

    if (cmd->str_size == 0) {
        error_num = 2;
        goto end;
    }

    char *cmd_name = cmd->str_params[0];

    if (strcmp(cmd_name, "exit") == 0) {
        if (!check_nb_params(cmd, 1, 0, 0)) {
            error_num = 3;
            goto end;
        }
        error_num = 4;
    }

    else if (strcmp(cmd_name, "clear") == 0) {
        if (!check_nb_params(cmd, 1, 0, 0)) {
            error_num = 3;
            goto end;
        }
        error_num = 5;
    }

    else if (strcmp(cmd_name, "plot") == 0) {
        if (!check_nb_params(cmd, 1, 0, 0)) {
            error_num = 3;
            goto end;
        }
        error_num = 6;
    }


    else if (strcmp(cmd_name, "help") == 0) {
        if (!check_nb_params(cmd, 1, 0, 0)) {
            error_num = 3;
            goto end;
        }
        print_help();
        error_num = 7;
    }


    else if (strcmp(cmd_name, "point") == 0) {
        if (!check_nb_params(cmd, 1, 2, 0)) {
            error_num = 3;
            goto end;
        }
        Shape *sh =
            create_point_shape(cmd->int_params[0], cmd->int_params[1]);
        add_shape_to_layer(app->current_layer, sh);
        error_num = 0;

        error_num = 0;
    }

    else if (strcmp(cmd_name, "line") == 0) {
        if (!check_nb_params(cmd, 1, 4, 0)) {
            error_num = 3;
            goto end;
        }
        Shape *sh =
            create_line_shape(cmd->int_params[0], cmd->int_params[1],
                              cmd->int_params[2], cmd->int_params[3]);
        add_shape_to_layer(app->current_layer, sh);
        error_num = 0;
    }


    else if (strcmp(cmd_name, "circle") == 0) {
        if (!check_nb_params(cmd, 1, 3, 0)) {
            error_num = 3;
            goto end;
        }
        Shape *sh =
            create_cercle_shape(cmd->int_params[0], cmd->int_params[1],
                                cmd->int_params[2]);
        add_shape_to_layer(app->current_layer, sh);
        error_num = 0;
    }

    else if (strcmp(cmd_name, "square") == 0) {
        if (!check_nb_params(cmd, 1, 3, 0)) {
            error_num = 3;
            goto end;
        }
        Shape *sh =
            create_square_shape(cmd->int_params[0], cmd->int_params[1],
                                cmd->int_params[2]);
        add_shape_to_layer(app->current_layer, sh);
        error_num = 0;
    } else if (strcmp(cmd_name, "rectangle") == 0) {
        if (!check_nb_params(cmd, 1, 4, 0)) {
            error_num = 3;
            goto end;
        }
        Shape *sh =
            create_rectangle_shape(cmd->int_params[0], cmd->int_params[1],
                                   cmd->int_params[2], cmd->int_params[3]);
        add_shape_to_layer(app->current_layer, sh);
        error_num = 0;
    }

    else if (strcmp(cmd_name, "polygon") == 0) {
        if (!check_nb_params_polygon(cmd)) {
            error_num = 3;
            goto end;
        }

        Shape *sh = create_polygon_shape(cmd->int_size, cmd->int_params);

        add_shape_to_layer(app->current_layer, sh);
        error_num = 0;
    }

    else if (strcmp(cmd_name, "curve") == 0) {
        if (!check_nb_params(cmd, 1, 8, 0)) {
            error_num = 3;
            goto end;
        }
        Shape *sh =
            create_curve_shape(cmd->int_params[0], cmd->int_params[1],
                               cmd->int_params[2], cmd->int_params[3],
                               cmd->int_params[4], cmd->int_params[5],
                               cmd->int_params[6], cmd->int_params[7]);
        add_shape_to_layer(app->current_layer, sh);
        error_num = 0;
    }



    /* LIST commande  */
    else if (strcmp(cmd_name, "list") == 0) {
        if (!check_nb_params(cmd, 2, 0, 0)) {
            error_num = 3;
            goto end;
        }

        if (strcmp(cmd->str_params[1], "areas") == 0) {
            list *area_list = app->list_area;
            lnode *area_node = get_first_node(area_list);
            while (area_node != NULL) {
                Area *area = (Area *) area_node->data;
                if (area == app->current_area) {
                    printf(" * ");
                } else {
                    printf(" - ");
                }
                printf("%3d %s \n", area->id, area->name);
                area_node = get_next_node(area_list, area_node);
            }
            error_num = 8;
        }

        else if (strcmp(cmd->str_params[1], "layers") == 0) {
            list *layer_list = app->current_area->lst_layers;
            lnode *layer_node = get_first_node(layer_list);
            while (layer_node != NULL) {
                Layer *layer = (Layer *) layer_node->data;
                if (layer == app->current_layer) {
                    printf(" * ");
                } else {
                    printf(" - ");
                }
                char vis = 'V';
                if (layer->visible == 0) {
                    vis = 'H';
                }
                printf("%3d (%c) %s \n", layer->id, vis, layer->name);
                layer_node = get_next_node(layer_list, layer_node);
            }
            error_num = 8;
        }

        else if (strcmp(cmd->str_params[1], "shapes") == 0) {
            list shape_list = app->current_layer->shapes;
            lnode *shape_node = get_first_node(&shape_list);
            char *tab_shape[] =
                { "POINT", "LINE", "SQUAR", "RECTANGLE", "CIRCLE",
                "POLYGON", "CURVE"
            };
            while (shape_node != NULL) {
                Shape *shp = (Shape *) shape_node->data;
                if (shp == app->current_shape) {
                    printf(" * ");
                } else {
                    printf(" - ");
                }
                char info[200];
                sprint_shape(shp, info);
                printf("%3d : %s %s\n", shp->id,
                       tab_shape[shp->shape_type], info);
                shape_node = get_next_node(&shape_list, shape_node);
            }
            error_num = 8;
        }

    }
    /* end LIST commande  */


    /* new commande  */
    else if (strcmp(cmd_name, "new") == 0) {
        if (!check_nb_params(cmd, 2, 0, 0)) {
            error_num = 3;
            goto end;
        }

        if (strcmp(cmd->str_params[1], "area") == 0) {
            /* la création d'un area crée automatiquement un premier layer */
            Area *area = create_area(80, 40, get_next_id(), "area_name");
            add_area_to_list(app->list_area, area);
            app->current_area = area;

            LayersList *layerlst = create_layers_list();
            area->lst_layers = layerlst;
            Layer *layer = create_layer(get_next_id(), "Layer 1");
            add_layer_to_list(layerlst, layer);
            app->current_layer = layer;
            app->current_shape = NULL;
            error_num = 8;
        }

        if (strcmp(cmd->str_params[1], "layer") == 0) {
            Layer *layer = create_layer(get_next_id(), "layer_name");
            add_layer_to_list(app->current_area->lst_layers, layer);
            app->current_layer = layer;
            app->current_shape = NULL;
            error_num = 8;
        }

    }
    /* end NEW command  */


    /* select commande  */
    else if (strcmp(cmd_name, "select") == 0) {
        if (!check_nb_params(cmd, 2, 1, 0)) {
            error_num = 3;
            goto end;
        }

        if (strcmp(cmd->str_params[1], "area") == 0) {
            /* la création d'un area crée automatiquement un premier layer */
            list *area_list = app->list_area;
            lnode *area_node = get_first_node(area_list);
            while (area_node != NULL) {
                Area *area = (Area *) area_node->data;
                if (area->id == cmd->int_params[0]) {
                    app->current_area = area;

                    list *layer_list = area->lst_layers;
                    lnode *layer_node = get_last_node(layer_list);
                    Layer *layer = (Layer *) layer_node->data;

                    app->current_layer = layer;
                    app->current_shape = NULL;
                    printf("%3d %s : selected \n", area->id, area->name);
                    error_num = 8;
                    goto end;
                }
                area_node = get_next_node(area_list, area_node);
            }
            error_num = 9;
        }

        if (strcmp(cmd->str_params[1], "layer") == 0) {
            list *layer_list = app->current_area->lst_layers;
            lnode *layer_node = get_first_node(layer_list);
            while (layer_node != NULL) {
                Layer *layer = (Layer *) layer_node->data;
                if (layer->id == cmd->int_params[0]) {
                    app->current_layer = layer;
                    app->current_shape = NULL;
                    error_num = 8;
                    goto end;
                }
                layer_node = get_next_node(layer_list, layer_node);
            }
            error_num = 9;
        }


        if (strcmp(cmd->str_params[1], "shape") == 0) {
            list *shape_list = &app->current_layer->shapes;
            lnode *shape_node = get_first_node(shape_list);
            while (shape_node != NULL) {
                Shape *shape = (Shape *) shape_node->data;
                if (shape->id == cmd->int_params[0]) {
                    app->current_shape = shape;
                    error_num = 8;
                    goto end;
                }
                shape_node = get_next_node(shape_list, shape_node);
            }
            error_num = 9;
        }


    }
    /* end select command  */

    /* delete commande  */
    else if (strcmp(cmd_name, "delete") == 0) {
        if (!check_nb_params(cmd, 2, 1, 0)) {
            error_num = 3;
            goto end;
        }

        if (strcmp(cmd->str_params[1], "shape") == 0) {
            list *shape_list = &app->current_layer->shapes;
            lnode *shape_node = get_first_node(shape_list);
            while (shape_node != NULL) {
                Shape *shape = (Shape *) shape_node->data;
                if (shape->id == cmd->int_params[0]) {
                    lst_delete_lnode(shape_list, shape_node);
                    app->current_shape = NULL;
                    error_num = 8;
                    goto end;
                }
                shape_node = get_next_node(shape_list, shape_node);
            }
            error_num = 9;
        }
    }
    /* end SET commande  */
    else if (strcmp(cmd_name, "set") == 0) {
        if (!check_nb_params(cmd, 3, 1, 0)) {
            error_num = 3;
            goto end;
        }
        // char 
        if (strcmp(cmd->str_params[1], "char") == 0) {
            if (strcmp(cmd->str_params[2], "border") == 0) {
                app->current_area->full_char = cmd->int_params[0];
                error_num = 0;
                goto end;
            }
            if (strcmp(cmd->str_params[2], "background") == 0) {
                app->current_area->empty_char = cmd->int_params[0];
                error_num = 0;
                goto end;
            }
            error_num = 3;
            goto end;
        }
        // layer visibility
        if (strcmp(cmd->str_params[1], "layer") == 0) {
            if (strcmp(cmd->str_params[2], "visible") == 0
                || strcmp(cmd->str_params[2], "unvisible") == 0) {

                // HERER
                list *layer_list = app->current_area->lst_layers;
                lnode *layer_node = get_first_node(layer_list);
                while (layer_node != NULL) {
                    Layer *layer = (Layer *) layer_node->data;
                    if (layer->id == cmd->int_params[0]) {
                        if (strcmp(cmd->str_params[2], "visible") == 0) {
                            set_layer_visible(layer);
                        } else {
                            set_layer_unvisible(layer);
                        }
                        error_num = 0;
                        goto end;
                    }
                    layer_node = get_next_node(layer_list, layer_node);
                }
                error_num = 9;
                goto end;
            }

        }
        error_num = 3;
        goto end;
    }
    /*set commannd */


  end:
    printf("%s\n", error_messages[error_num]);
    free_cmd(cmd);
    return error_num;
}
