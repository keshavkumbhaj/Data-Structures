#include <stdio.h>

#define MAX 100

struct Node {
    int key;
    int value;
    int frequency;
    int time;
};

struct LFUCache {
    struct Node data[MAX];
    int size;
    int capacity;
    int timer;
};

void init(struct LFUCache *cache, int capacity) {
    cache->size = 0;
    cache->capacity = capacity;
    cache->timer = 0;
}

int get(struct LFUCache *cache, int key) {
    for (int i = 0; i < cache->size; i++) {
        if (cache->data[i].key == key) {
            cache->data[i].frequency++;
            cache->data[i].time = ++cache->timer;

            return cache->data[i].value;
        }
    }

    return -1;
}

void put(struct LFUCache *cache, int key, int value) {
    if (cache->capacity == 0)
        return;

    /* Update existing key */
    for (int i = 0; i < cache->size; i++) {
        if (cache->data[i].key == key) {
            cache->data[i].value = value;
            cache->data[i].frequency++;
            cache->data[i].time = ++cache->timer;

            return;
        }
    }

    /* If cache is full, remove LFU key */
    if (cache->size == cache->capacity) {
        int index = 0;

        for (int i = 1; i < cache->size; i++) {
            if (cache->data[i].frequency <
                cache->data[index].frequency) {
                index = i;
            }
            else if (cache->data[i].frequency ==
                     cache->data[index].frequency &&
                     cache->data[i].time <
                     cache->data[index].time) {
                index = i;
            }
        }

        for (int i = index; i < cache->size - 1; i++)
            cache->data[i] = cache->data[i + 1];

        cache->size--;
    }

    /* Insert new key */
    cache->data[cache->size].key = key;
    cache->data[cache->size].value = value;
    cache->data[cache->size].frequency = 1;
    cache->data[cache->size].time = ++cache->timer;

    cache->size++;
}

int main() {
    struct LFUCache cache;
    int capacity;
    int choice, key, value;

    printf("Enter cache capacity: ");
    scanf("%d", &capacity);

    init(&cache, capacity);

    while (1) {
        printf("\n1. Put");
        printf("\n2. Get");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter key and value: ");
            scanf("%d %d", &key, &value);

            put(&cache, key, value);

            printf("Key inserted/updated.\n");
        }
        else if (choice == 2) {
            printf("Enter key: ");
            scanf("%d", &key);

            value = get(&cache, key);

            printf("Value: %d\n", value);
        }
        else if (choice == 3) {
            break;
        }
        else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}