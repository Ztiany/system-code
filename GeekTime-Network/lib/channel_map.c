#include "channel_map.h"
#include <memory.h>

bool channel_map_make_space(struct channel_map *map, int slot, int size) {
    if (map == NULL) {
        return false;
    }

    if (map->length <= slot) {
        /*默认 32 个槽位*/
        int length = map->length == 0 ? 32 : map->length;
        void **temp;

        while (length <= slot) {
            length <<= 1;//2 倍数扩容
        }

        temp = realloc(map->entities, length * size);
        if (temp == NULL) {
            return false;
        }

        /*新分配的内存置为 0*/
        memset(temp[map->length]/*起始位置*/, 0, (length - map->length)/*长度*/ * size/*单位*/);

        map->length = length;
        map->entities = temp;
    }

    return true;
}

void channel_map_init(struct channel_map *map) {
    if (map != NULL) {
        map->length = 0;
        map->entities = NULL;
    }
}

void channel_map_clear(struct channel_map *map) {
    if (map == NULL) {
        return;
    }

    for (int i = 0; i < map->length; ++i) {
        if (map->entities[i] != NULL) {
            free(map->entities[i]);
        }
    }
    free(map->entities);

    map->entities = NULL;
    map->length = 0;
}