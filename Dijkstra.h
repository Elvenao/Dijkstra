#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <stdlib.h>
#include "list.h"

typedef struct node{
    char name[NAME_LENGTH];
    union{
        struct{
            int weight; 
            struct node *connection_forth;    
        }body;
        struct node *hierarchy;
    }type;
    struct node *next;
    struct node *before;
    list_t *connections;
    
}node_t;




node_t *nodeInnit(int weight, char nodeName[NAME_LENGTH]);

void newDijkstraNode(int distance,char nodeName[NAME_LENGTH], char endNode[NAME_LENGTH]);

void delDijkstraNode(struct node *Dijkstra);

int existentConnection(char nodeName[NAME_LENGTH]);

node_t *seekNodeCommon(char nodeName[NAME_LENGTH]);

void showNodes();

#endif