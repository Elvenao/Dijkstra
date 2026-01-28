#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "Dijkstra.h"
#include <conio.h>

int main(){

    char tmpName[NAME_LENGTH];
    char tmpEndName[NAME_LENGTH];
    int tmpWeight;
    int option = 0;
    while(option != 4){
        system("cls");
        printf("\nMenu: \n1.Create new node\n2.Edit node\n3.Delete node\n4.Show created nodes\n5.Exit\nInsert option: ");
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("\nInsert the node's name: ");
                scanf("%2s", tmpName);
                printf("Insert the end node's name: ");
                scanf("%2s", tmpEndName);
                printf("Insert the weight: ");
                
                scanf("%d",&tmpWeight);
                
                
                newDijkstraNode(tmpWeight,tmpName,tmpEndName);

                break;
            case 2:
                showNodes();
                printf("\nInsert the node's name: ");
                scanf("%2s", tmpName);
                printf("Insert the end node's name: ");
                scanf("%2s", tmpEndName);
                printf("Insert the weight: ");
                
                scanf("%d",&tmpWeight);
                break;
            case 3:
                printf("Delete node");
                break;
            case 4:
                showNodes();
                printf("\n\nPress any button to continue...");
                getch();
                break;
            case 5:
                printf("\nGood bye...");
                break;
            default:
                printf("\nWrong Option...");
                break;
        }
    }
    
    
    return 0;
}