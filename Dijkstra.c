#include <stdio.h>
#include <stdlib.h>



int main(){
    node_t *node = malloc(sizeof(node_t));
    printf("Program running....");
    printf("Write the value of the distance of the first node connection: ");
    scanf("%d",&node->distance);
    printf("Value: %i", node->distance);

    return 0;
}