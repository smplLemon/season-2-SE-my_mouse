#include "../h/my_mouse.h"

short map_check(char* str){
    for(int j = 0; str[j]; j++){
        for(; str[j] != '.'; j++);
        if(!strcmp(&str[j+1], "map"))
            return 1;
    }
    return 0;
}

short limit_maze(size_map* tall_wed, map_flab* map_msetts){
    short sign_a = 0;
    short sign_z = 0, i = 0;
    while(i < tall_wed->wideness){
        if(map_msetts->smap[0][i] == '1'){
            sign_a = 1;
            map_msetts->beginning = i;
        }
        if(map_msetts->smap[tall_wed->tallnes - 1][i] == '2'){
            sign_z = 1;
            map_msetts->limit = i;
        }
        i++;
    }
    if(sign_a && sign_z){
        return 0;
    }
    return 1;
}