#include "list.h"
#include <string.h>
#include <stdio.h>

static list_t *head = NULL;
static list_t *tail = NULL;



void getTail(){
    if (head == NULL) {
        tail = NULL;
        return;
    }
    tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
}

void push(list_t *list, char nodeName[NAME_LENGTH]){
    head = list;
    getTail();
    printf("AQUI noe es: %s\n", nodeName);
    if(strcmp(tail->nodeName, "##") == 0){
        strcpy(tail->nodeName, nodeName);
        printf("AQUI noe es7: %s\n", nodeName);
    }else{
        printf("AQUI noe es: %s\n", nodeName);
        list_t *node = malloc(sizeof(list_t));
        node->next = NULL;
        node->before = tail;
        strcpy(node->nodeName, nodeName);
        tail->next = node;
    }
}

int size(list_t *list){
    int list_size = 0;
    while(1){
        if(list == NULL){
            break;
        }else{
            list_size++;
            list = list->next;
        }
    }
    return list_size;
}

int lastIndex(list_t *list){
    int index = 0;
    head = list;
    if(head == NULL){
        printf("The list is empty\n");
        return 0;
    }
    while(1){
        if(head->next != NULL){
            head = head->next;
            index++;
        }else return index;
    }
}

int findIndex(list_t *list, char nodeName[NAME_LENGTH]){
    int index = 0;
    head = list;
    if(head == NULL){
        printf("The list is empty\n");
        return 0;
    }
    while(1){
        if(head != NULL){
            if(strcmp(nodeName, head->nodeName) == 0){
                return index;
            }
            index++;
            head = head->next;
        }else{
            printf("The value was not found\n");
            return 0;
            break;
        }
    }
    return index;
}

char *getNodeName(list_t *list, int index) {
    for (int i = 0; i < index && list != NULL; i++) {
        list = list->next;
    }

    if (list == NULL) return NULL;

    return list->nodeName;
}


list_t *listInnit(){
    list_t *list = malloc(sizeof(list_t));
    list->next = NULL;
    list->before = NULL;
    strcpy(list->nodeName, "##");
    return list;
}

void showList(list_t *list){
    head = list;
    printf("\n");
    while(1){
        if(head != NULL){
            
            if(head->next == NULL){
                printf("%s", head->nodeName);
            }else{
                printf("%s<->", head->nodeName);
            }
            
            head = head->next;
        }else{ 
            break;
        }
    }
}

int contains(list_t *list, char nodeName[NAME_LENGTH]){
    if(list == NULL) {
        printf("GIAL");
        return 0;
    }
    while(1){
        if(strcmp(nodeName, list->nodeName) == 0){
            return 1;
        }else if(list->next != NULL){
            list = list->next;
        }else{
            return 0;
        }
    }
}



void freeList(list_t *list){
    free(list->next);
    free(list->before);
    free(list);
}
