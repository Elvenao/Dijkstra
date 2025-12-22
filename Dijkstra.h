#ifndef DIJKSTRA
#define DIJKSTRA

#include <stdlib.h>



typedef struct node{
    int weight;
    struct node *connection_forth;
    struct node *next;
    struct node *before;
    char name[3];
}node_t;


node_t *nodeInnit(int weight, char nodeName[3]);

void newDijkstraNode(int distance,char nodeName[3], char endNode[3]);

void delDijkstraNode(struct node *Dijkstra);

void showNodes();

#endif