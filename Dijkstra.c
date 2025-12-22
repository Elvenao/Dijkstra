#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "Dijkstra.h"

static node_t *main_head;
static node_t *list;
static node_t *head_of_list;

node_t *nodeInnit(int weight, char nodeName[3]){
    node_t *node = malloc(sizeof(node_t));
    strcpy(node->name, nodeName);
    node->weight = weight;
    node->next = NULL;
    node->before = NULL;
    return node;
}


void newDijkstraNode(int weight,char nodeName[3], char endNode[3]){
    node_t *node = nodeInnit(weight,nodeName);
    uint8_t _on_the_list = 0;
    uint8_t _error_count = 0;

    if(main_head == NULL){
        main_head = malloc(sizeof(node_t));
        main_head = node;
        node_t *node_b = nodeInnit(weight,endNode);
        main_head->connection_forth = node_b;
        node_b->connection_forth = main_head;
        _on_the_list = 1;
        printf("\nNode created");
    }else{
        list = main_head;
    }
    if(!_on_the_list){
        while(!_on_the_list){
            
            if(strcmp(list->name,nodeName) == 0){ //Check if the given node already exists
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
                        printf("\nNode created");
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
                    if(_error_count > 2) exit(-2);
                    else _error_count++;
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

void showNodes(){
    uint8_t _error_count = 0;
    list = main_head;
    head_of_list = main_head;
    do{
        do{
            printf("\n%s <--%d--> %s", list->name, list->weight, list->connection_forth->name);
            list = list->next;
        }while(list != NULL);
        head_of_list = head_of_list->connection_forth->next;
        list = head_of_list;
        if(list == NULL) break;
        if(_error_count > 20) {
            printf("\nError");
            exit(-1);
        }
        else _error_count++;
    }while(list->connection_forth != NULL);
}