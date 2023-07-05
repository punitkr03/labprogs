// Program to implement hashing and prevent collision using chaining
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

typedef struct HashTable {
    struct Node* head[10];
}HS;

void displayHashTable(HS* ht) {
    int i;
    for (i = 0; i < 10; i++) {
        printf("Index %d: ", i);
        struct Node* temp = ht->head[i];
        while (temp != NULL) {
            printf("-> %d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void createHashTable(HS* ht) {
    int i;
    for (i = 0; i < 10; i++) {
        ht->head[i] = NULL;
    }
}
int hashFunction(int key) {
    return key % 10;
}

void insert(HS* ht, int key) {
    int index = hashFunction(key);
    
    // Create a new node
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = NULL;
    
    // If the index is empty, insert the new node
    if (ht->head[index] == NULL) {
        ht->head[index] = newNode;
    } else {
        // If there are elements already at the index, append the new node at the end
        struct Node* temp = ht->head[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
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