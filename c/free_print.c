#include "../h/my_mouse.h"

void my_clean(size_map *tall_wed, map_flab *map_msetts){
    int k = 0;
    while(k < tall_wed->tallnes){
        free(map_msetts->smap[k]);
        free(map_msetts-> map_i[k]);
        k++;
    }
    free(map_msetts->smap);
    free(map_msetts-> map_i);
    free(map_msetts);
    free(tall_wed);
}

void printing(size_map* tall_wed, map_flab* map_msetts){
    printf("%dx%d* o12\n", tall_wed->tallnes, tall_wed->wideness);
    for(short i = 0; i < tall_wed->tallnes; i++) printf("%s\n", map_msetts->smap[i]); 
    printf("%d STEPS\n", tall_wed->steps-2);
}
