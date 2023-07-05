// Program to implment hashing and prevent collision using linear probing
#include <stdio.h>
#include <stdlib.h>
typedef struct HashTable {
    int keys[10];
    int values[10];
}HS;

void displayHashTable(HS* ht) {
    int i;
    for (i = 0; i < 10; i++) {
        printf("Index %d: ", i);
        if (ht->keys[i] != -1) {
            printf("%d",ht->values[i]);
        }
        printf("\n");
    }
}

void createHashTable(HS* ht) {
    int i;
    for (i = 0; i < 10; i++) {
        ht->keys[i] = -1;
        ht->values[i] = -1;
    }
}

int hashFunction(int value) {
    return value % 10;
}

void insert(HS* ht, int value) {
    int key = hashFunction(value);
    int index = key;
    int i = index;

    // Find the next available slot
    while (ht->keys[i] != -1) {
        i = (i + 1) % 10;

        // If we reach the original index, the hash table is full
        if (i == index) {
            printf("Hash table is full. Unable to insert element.\n");
            return;
        }
    }

    // Insert the element at the available slot
    ht->keys[i] = key;
    ht->values[i] = value;
}

int main() {
    HS hashTable;
    int arr[] = {10, 70, 32, 73, 26, 52, 88, 12};
    createHashTable(&hashTable);
    int i;
    for(i = 0; i < 8; i++) {
        insert(&hashTable, arr[i]);
    }
    displayHashTable(&hashTable);
    return 0;
}