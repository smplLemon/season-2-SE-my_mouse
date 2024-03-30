#include "../h/my_mouse.h"


void check(map_flab** map_msetts, int* e, int* g, short g_stage) {
    int** kar = (*map_msetts)-> map_i;
    if(kar[(*e)+1][(*g)] == (g_stage-1))  *e = (*e)+1;
    if(kar[*e-1][*g]== (g_stage-1)) *e = *e-1;
    if(kar[*e][*g-1]== (g_stage-1)) *g = *g-1;
    if(kar[*e][*g+1]== (g_stage-1))  *g = *g + 1;
}

void making_maze(size_map* tall_wed, map_flab** map_msetts, short g_stage){
    response* boxx = (response*)malloc(sizeof(response));
    boxx->e = tall_wed->tallnes-2;
    boxx->g = (*map_msetts)->limit;
    while(g_stage > 1){
        (*map_msetts)->smap[boxx->e][boxx->g] = 'o';
        check(map_msetts, &(boxx->e), &(boxx->g),g_stage);
        g_stage--;
    }
    free(boxx);
    printing(tall_wed, *map_msetts);
}

void find_way(map_flab **map_msetts, short e, short g, short g_stage) {
    int**lab = (*map_msetts)-> map_i;
    if(!lab[e+1][g] || lab[e+1][g] == -2) lab[e + 1][g] = g_stage + 1;
    if(!lab[e-1][g]) lab[e-1][g] = g_stage + 1;
    if(!lab[e][g-1]) lab[e][g-1] = g_stage + 1;
    if(!lab[e][g+1]) lab[e][g+1] = g_stage + 1;
}

void f_short_way(size_map* tall_wed, map_flab** map_str){
    map_flab* map_msetts = *map_str;
    map_msetts-> map_i[1][map_msetts->beginning] = 2;
    short stage = 2, i, j;
    while(map_msetts-> map_i[tall_wed->tallnes-1][map_msetts->limit] == -2){
        for(i = 1; i < tall_wed->tallnes; i++){
            for(j = 1; j < tall_wed->wideness; j++){
                if(map_msetts-> map_i[i][j] == stage){
                    find_way(&map_msetts, i, j, stage);
                }
            }
        }
        stage++;
    }
    tall_wed->steps = stage;
    making_maze(tall_wed, &map_msetts, stage);
}

void convert(size_map* tall_wed, map_flab** map_msetts){
    for(int o = 0; o < tall_wed->tallnes; o++){
        for(int l = 0; l < tall_wed->wideness; l++){
            (*map_msetts)-> map_i[0][(*map_msetts)->beginning] = 1;
            (*map_msetts)-> map_i[tall_wed->tallnes-1][(*map_msetts)->limit] = -2;
            if((*map_msetts)->smap[o][l] == ' '){
                (*map_msetts)-> map_i[o][l] = 0;
            }else if((*map_msetts)->smap[o][l] == '*'){
                (*map_msetts)-> map_i[o][l] = -3;
            }
        }
    }
    f_short_way(tall_wed, map_msetts);
}