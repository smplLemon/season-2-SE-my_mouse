#include "../h/my_mouse.h"

short my_isdigit(short c){
    if(c < '0' && c > '9') return 1;
    return 0;
}

void fill_null(char* str, short over){
    for(short i = 0; i < over; i++) str[i] = '\0';
}

short size_maze(short fd, size_map* map_setwt){
    map_setwt->wideness = 0;
    map_setwt->tallnes = 0; 
    map_setwt->steps = 0;
    char *lit_memf = (char*)calloc(4, sizeof(char));
    char sa;
    short si = 0, signf = 0;
    while(read(fd, &sa, 1) > 0){
        if(signf == 0){
            if(my_isdigit(sa)){    
                printf("MAP ERROR\n");
                return 1;
            }
            lit_memf[si] = sa;
        }
        if(sa == 'x'){
            lit_memf[si] = '\0';
            map_setwt->tallnes = atoi(lit_memf);
            fill_null(lit_memf, si);
            si = 0;
            continue;
        }else if(sa == '*'){
            lit_memf[si] = '\0';
            map_setwt->wideness = atoi(lit_memf);
            signf = 1;
            continue;
        }else if(sa == '\n')
            break;
        si++;
    }
    free(lit_memf);
    return 0;
}

void map_init(size_map* tall_wed, map_flab** map_msetts){
    *map_msetts = (map_flab*)malloc(sizeof(map_flab));
    (*map_msetts)->smap = (char**)calloc(tall_wed->tallnes, sizeof(char*));
    (*map_msetts)-> map_i = (int**)calloc(tall_wed->tallnes, sizeof(int*));
    (*map_msetts)->beginning = 0;
    (*map_msetts)->limit = 0;
    short i = 0;
    while(i < tall_wed->tallnes){
        (*map_msetts)-> map_i[i] = (int*)calloc(tall_wed->wideness, sizeof(int));
        (*map_msetts)->smap[i] = (char*)calloc(tall_wed->wideness + 1, sizeof(char));
        i++;
    }
}

void read_map(short fd, size_map* tall_wed, map_flab* map_msetts){
    char si;
    short e = 0;
    while(e < tall_wed->tallnes){
        read(fd, map_msetts->smap[e], tall_wed->wideness);
        read(fd, &si, 1);
        e++;
    }
    close(fd);
}

size_map* read_file(char* str, map_flab** map_stri){
    short fd = open( str, O_RDONLY);
    size_map* map_mem = (size_map*)malloc(sizeof(size_map));
    if(size_maze(fd, map_mem)) {
        free(map_mem);
        return NULL;
    }
    map_init(map_mem, map_stri);
    read_map(fd, map_mem, *map_stri);
    return map_mem;
}