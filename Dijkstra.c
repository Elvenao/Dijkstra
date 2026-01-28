#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "list.h"
#include "Dijkstra.h"

static node_t *head;
static node_t *list;
static node_t *head_of_list;

node_t *nodeInnit(int weight, char nodeName[NAME_LENGTH]){
    node_t *node = malloc(sizeof(node_t));
    strcpy(node->name, nodeName);
    node->type.body.weight = weight;
    node->next = NULL;
    node->before = NULL;
    node->connections = listInnit();
    return node;
}

node_t *nodeHead(char nodeName[NAME_LENGTH]){

    node_t *node = malloc(sizeof(node_t));

    strcpy(node->name,nodeName);
    
    node->type.hierarchy = NULL;
    node->next = NULL;
    node->before = NULL;
    node->connections = listInnit();

    return node;
}

void newDijkstraNode(int weight,char nodeName[NAME_LENGTH], char endNode[NAME_LENGTH]){

    if(!head){
        head = nodeHead("777");
        char a[NAME_LENGTH];
        strncpy(a,"777",NAME_LENGTH);
        push(head->connections,a);        
    }

    if(!contains(head->connections, nodeName) && !contains(head->connections, endNode)){ //both don't exist
        list = head;
        int index = lastIndex(head->connections);
        for(int i = 0; i < index; i++){
            list = list->next;
        }
        push(head->connections, nodeName);
        push(head->connections, endNode);
        node_t *nodeA = nodeHead(nodeName);
        push(nodeA->connections, endNode);
        list->next = nodeA;
        nodeA->before = list;
        node_t *nodeB = nodeHead(endNode);
        push(nodeB->connections, nodeName);
        nodeB->before = nodeA;
        nodeA->next = nodeB;
        node_t *nodeAA = nodeInnit(weight, nodeName);
        node_t *nodeBB = nodeInnit(weight, endNode);
        nodeA->type.hierarchy = nodeAA;
        nodeB->type.hierarchy = nodeBB;
        nodeAA->type.body.connection_forth = nodeBB;
        nodeBB->type.body.connection_forth = nodeAA;
    }else if(!contains(head->connections, nodeName) && contains(head->connections, endNode)){// first doesn't exist
        int last_index = lastIndex(head->connections);
        push(head->connections, nodeName);
        int index = findIndex(head->connections, endNode);
        list = head;
        for(uint8_t i = 0; i < index; i++){
            list = list->next;              //endNode
        }
        

        
        node_t *listAux = list;

        for(uint8_t i = 0; i < last_index-index; i++){
            listAux = listAux->next;
        }

        node_t *nodeA = nodeHead(nodeName);//create new first node

        nodeA->before = listAux;
        listAux->next = nodeA;
        
        push(nodeA->connections,endNode);
        
        index = lastIndex(list->connections);//find last index (size) of second node list to push new node
        push(list->connections, nodeName); //push to the second node
        list = list->type.hierarchy; //go down to the level of node connections
        for(uint8_t i = 0; i < index; i++){
            list = list->next;
        }
        
        node_t *nodeBB = nodeInnit(weight,endNode);
        node_t *nodeAA = nodeInnit(weight,nodeName);
        nodeBB->type.body.connection_forth = nodeAA;
        nodeAA->type.body.connection_forth = nodeBB;

        nodeA->type.hierarchy = nodeAA;
        list->next = nodeBB;
        nodeBB->before = list;

    }else if(contains(head->connections, nodeName) && !contains(head->connections, endNode)){//second one doesn't exist

        int index = findIndex(head->connections,nodeName);
        list = head;
        for(uint8_t i = 0; i < index; i++){
            list = list->next;
        }
        
        int last_index = lastIndex(head->connections);
        node_t *listAux = list;
        for(uint8_t i = 0; i < last_index-index; i++){
            listAux = listAux->next;
        }
        node_t *nodeA = nodeHead(endNode);//create new first node
        nodeA->before = listAux;
        listAux->next = nodeA;
        push(nodeA->connections,nodeName);
        index = lastIndex(list->connections);//find last index (size) of second node list to push new node
        list = list->type.hierarchy; //go down to the level of node connections
        for(uint8_t i = 0; i < index; i++){
            list = list->next;
        }
        node_t *nodeBB = nodeInnit(weight,nodeName);
        node_t *nodeAA = nodeInnit(weight,endNode);
        nodeBB->type.body.connection_forth = nodeAA;
        nodeAA->type.body.connection_forth = nodeBB;

        nodeA->type.hierarchy = nodeAA;
        list->next = nodeBB;
        nodeBB->before = list;
        push(head->connections, endNode);
        push(list->connections, endNode); //push to the second node
    }else{ //both already exists
        
        int indexA = findIndex(head->connections, nodeName);
        int indexB = findIndex(head->connections, endNode);
        node_t *listA = head, *listB = head;
        for(uint8_t i = 0; i < indexA; i++){
            listA = listA->next;
        }
        
        for(uint8_t i = 0; i < indexB; i++){
            listB = listB->next;
        }
        if(contains(listA->connections, endNode) && contains(listB->connections, nodeName)){
            printf("Error: You can not overwrite an existent node\n");
            return;
        }
        indexA = lastIndex(listA->connections);
        indexB = lastIndex(listB->connections);
        push(listA->connections,endNode);
        push(listB->connections,nodeName);
        listA = listA->type.hierarchy;
        listB = listB->type.hierarchy;
        for(uint8_t i = 0; i < indexA; i++){
            listA = listA->next;
        }
        for(uint8_t i = 0; i < indexB; i++){
            listB = listB->next;
        }

        node_t *nodeBB = nodeInnit(weight,nodeName);
        node_t *nodeAA = nodeInnit(weight,endNode);
        nodeBB->type.body.connection_forth = nodeAA;
        nodeAA->type.body.connection_forth = nodeBB;
        listA->next = nodeAA;
        listB->next = nodeBB;
        
    }

}

void delDijkstraNode(struct node *Dijkstra){
    if(Dijkstra != NULL){
        free(Dijkstra->next);
        free(Dijkstra->type.body.connection_forth);
        free(Dijkstra->type.hierarchy);
        free(Dijkstra->before);
        freeList(Dijkstra->connections);
        free(Dijkstra);
    }
}

void showNodes(){
    list = head;
    head_of_list = head;
    int sizeOf = size(head->connections) - 1;
    int size_within;
    for(int i = 0; i < sizeOf; i++){
        head_of_list = head_of_list->next;
        list = head_of_list->type.hierarchy;
        size_within = size(head_of_list->connections);
        for(int j = 0; j < size_within; j++){
            printf("\n%s <--%d--> %s", list->name, list->type.body.weight, list->type.body.connection_forth->name);
            if(list->next != NULL) list = list->next;                                                              
        }
    }
}