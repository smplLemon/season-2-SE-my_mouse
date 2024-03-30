#ifndef MY_MOUSE_H
#define MY_MOUSE_H
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>

typedef struct{
    int e;
    int g;
} response;

typedef struct{
    short tallnes;
    short wideness;
    short steps;
} size_map;

typedef struct{
    short beginning;
    short limit;
    int** map_i;
    char **smap;
} map_flab;

#endif


#ifndef CHECKF_START_LIMIT
#define CHECKF_START_LIMIT
    short map_check(char* str);
    short limit_maze(size_map* map_set, map_flab* map_ray);
#endif


#ifndef FREE_PRINT
#define FREE_PRINT
    void my_clean(size_map *tall_wed, map_flab *map_msetts);
    void printing(size_map* tall_wed, map_flab* map_msetts);
#endif


#ifndef PREPARE_PROCCESS
#define PREPARE_PROCCESS
    short my_isdigit(short c);
    short size_maze(short fd, size_map* map_setwt);
    void map_init(size_map* tall_wed, map_flab** map_msetts);
    void read_map(short fd, size_map* tall_wed, map_flab* map_msetts);
    size_map* read_file(char* g_str, map_flab** map_stri);
#endif




#ifndef SHORT_WAY
#define SHORT_WAY
    void check(map_flab** map_msetts, int* e, int* g, short g_stage);
    void making_maze(size_map* tall_wed, map_flab** map_msetts, short g_stage);
    void find_way(map_flab **map_msetts, short e, short g, short g_stage);
    void f_short_way(size_map* tall_wed, map_flab** map_str);
    void convert(size_map* tall_wed, map_flab** map_msetts);
#endif
