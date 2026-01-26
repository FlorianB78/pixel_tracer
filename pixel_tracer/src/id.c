#include "id.h"

static unsigned long long int global_id = 0;

unsigned long long int get_next_id() {
    global_id++;
    return global_id;
}

void set_id(unsigned long long int id) {
    global_id = id;
}

void save_id() {
    // todo save id in file ID_FILE
}

void load_id() {
    // todo load id from file ID_FILE
}
