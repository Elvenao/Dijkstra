#ifndef DIJKSTRA
#define DIJKSTRA

#include <stdlib.h>



typedef struct node{
    int weight;
    struct node *connection_forth;
    struct node *next;
    struct node *before;
    char name[2];
}node_t;

node_t *nodeInnit(int weight, char nodeName[2]);

void newDijkstraNode(int distance,char nodeName[2], char endNode[2]);

void delDijkstraNode(struct node *Dijkstra);

#endif