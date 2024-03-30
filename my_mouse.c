#include "./h/my_mouse.h"

int main(int ac, char** av){
    if(ac > 1){
        if(map_check(av[1]) == 0){
            write(2, "FILE ERROR\n", 11);
            return 1;
        }
        map_flab* map_rays = NULL;
        size_map* map_setg = read_file(av[1], &map_rays);
        if(map_setg == NULL) return 1;
        if(limit_maze(map_setg, map_rays) == 0){
            convert(map_setg, &map_rays);
            my_clean(map_setg, map_rays);
        } else {
            write(2, "MAP ERROR\n", 10);
            my_clean(map_setg, map_rays);
            return 1;
        }
    }
    return 0;
}
