#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "Dijkstra.h"

int main(){
    printf("Program running....");
    char tmpName[3];
    char tmpEndName[3];
    int tmpWeight;
    int option = 0;
    while(option != 4){
        printf("\nMenu: \n1.Create new node\n2.Delete node\n3.Show created nodes\n4.Exit\nInsert option: ");
        scanf("%d",&option);
        printf("%d\n",option);
        system("cls");
        switch(option){
            case 1:
                printf("\nInsert the node's name: ");
                scanf("%1s", tmpName);
                printf("\nInsert the end node's name: ");
                scanf("%1s", tmpEndName);
                printf("\nInsert the weight: ");
                scanf("%d",&tmpWeight);
                
                newDijkstraNode(tmpWeight,tmpName,tmpEndName);
                break;
            case 2:
                break;
            case 3:
                showNodes();
                break;
            case 4:
                printf("\nGood bye...");
                break;
            default:
                printf("\nWrong Option...");
                break;
        }
    }
    
    
    return 0;
}