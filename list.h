#ifndef LIST_H
#define LIST_H
#include <stddef.h>
#include <stdlib.h>
#define NAME_LENGTH 4
typedef struct list{
    char nodeName[NAME_LENGTH];
    struct list *next;
    struct list *before;
}list_t;

void getTail();

void push(list_t *list, char nodeName[NAME_LENGTH]);

int size(list_t *list);

int lastIndex(list_t *list);

int findIndex(list_t *list, char nodeName[NAME_LENGTH]);

char *getNodeName(list_t *list, int index);

void newList(list_t *list, char nodeName[NAME_LENGTH]);

list_t *listInnit();

void showList(list_t *list);

int contains(list_t *list, char nodeName[NAME_LENGTH]);



void freeList(list_t *list);

#endif