#include <stdio.h>
#include <string.h>

#define MAX_KEYS 100
#define MAX_LEN 50

struct Key {
    char key[MAX_LEN];
    int count;
};

struct AllOne {
    struct Key keys[MAX_KEYS];
    int size;
};

void inc(struct AllOne *obj, char key[]) {
    for (int i = 0; i < obj->size; i++) {
        if (strcmp(obj->keys[i].key, key) == 0) {
            obj->keys[i].count++;
            return;
        }
    }

    strcpy(obj->keys[obj->size].key, key);
    obj->keys[obj->size].count = 1;
    obj->size++;
}

void dec(struct AllOne *obj, char key[]) {
    for (int i = 0; i < obj->size; i++) {
        if (strcmp(obj->keys[i].key, key) == 0) {
            obj->keys[i].count--;

            if (obj->keys[i].count == 0) {
                for (int j = i; j < obj->size - 1; j++)
                    obj->keys[j] = obj->keys[j + 1];

                obj->size--;
            }

            return;
        }
    }
}

char* getMaxKey(struct AllOne *obj) {
    static char result[MAX_LEN];

    if (obj->size == 0) {
        result[0] = '\0';
        return result;
    }

    int maxIndex = 0;

    for (int i = 1; i < obj->size; i++) {
        if (obj->keys[i].count > obj->keys[maxIndex].count)
            maxIndex = i;
    }

    strcpy(result, obj->keys[maxIndex].key);
    return result;
}

char* getMinKey(struct AllOne *obj) {
    static char result[MAX_LEN];

    if (obj->size == 0) {
        result[0] = '\0';
        return result;
    }

    int minIndex = 0;

    for (int i = 1; i < obj->size; i++) {
        if (obj->keys[i].count < obj->keys[minIndex].count)
            minIndex = i;
    }

    strcpy(result, obj->keys[minIndex].key);
    return result;
}

int main() {
    struct AllOne obj;
    obj.size = 0;

    inc(&obj, "hello");
    inc(&obj, "hello");
    inc(&obj, "world");

    printf("Maximum Key: %s\n", getMaxKey(&obj));
    printf("Minimum Key: %s\n", getMinKey(&obj));

    dec(&obj, "hello");

    printf("After decrement:\n");
    printf("Maximum Key: %s\n", getMaxKey(&obj));
    printf("Minimum Key: %s\n", getMinKey(&obj));

    return 0;
}