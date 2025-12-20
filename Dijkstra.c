#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "Dijkstra.h"

node_t *main_head;
node_t *list;
node_t *head_of_list;

node_t *nodeInnit(int weight, char nodeName[2]){
    node_t *node = malloc(sizeof(node_t));
    strcpy(node->name, nodeName);
    node->weight = weight;
    node->next = NULL;
    node->before = NULL;
    return node;
}


void newDijkstraNode(int weight,char nodeName[2], char endNode[2]){
    char lastNode[2];
    node_t *node = nodeInnit(weight,nodeName);
    uint8_t _on_the_list = 0;

    if(main_head == NULL){
        main_head = malloc(sizeof(node_t));
        main_head = node;
        main_head->before = NULL;
        main_head->next = NULL;
        node_t *node_b = nodeInnit(weight,endNode);
        main_head->connection_forth = node_b;
        node_b->connection_forth = main_head;
        _on_the_list = 1;
    }

    list = main_head;
    
    if(!_on_the_list){
        while(1){
            
            if(list->name == nodeName){ //Check if the given node already exists
                //head_of_list = list;
                while(list->connection_forth->name != endNode){
                    if(list->next != NULL)
                        list = list->next;
                    else{ //If there is no node with the same endNodeName,a new node with the 
                          //connection must be created
                        node_t *alternative_node = malloc(sizeof(node_t));
                        alternative_node = nodeInnit(weight, endNode);

                        alternative_node->connection_forth = node;
                        node->connection_forth = alternative_node;
                       
                        node->before = list;
                        list->next = node;
                        list = list->next;
                        
                         _on_the_list = 1;
                        break;
                    }
                }
                if(!_on_the_list){
                    printf("\nThe node has been already initialized.");
                }
            }else{ //Going to the next connection
                list = list->connection_forth;
                if(list->next != NULL){
                    list = list->next;
                }
                //If there's no connection known nor node existing, then a new node should be created and its connection
                //but in this version, there must be a node conected to another node already initialized
                else{ 
                    printf("\nThe current node you want to add has node past connections,\nmake a connection with existent nodes.");
                }
            }
        }
    }
}

void delDijkstraNode(struct node *Dijkstra){
    if(Dijkstra != NULL){
        free(Dijkstra->next);
        free(Dijkstra->connection_forth);
        free(Dijkstra->before);
        free(Dijkstra);
    }
}