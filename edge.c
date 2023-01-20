#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "edge.h"
void delete_edges_to(pedge *head,int vertex_name){
    printf("start");
    pedge current = *head;
    pedge temp;
    while (current && current->endpoint->node_num == vertex_name)
    {

        temp=current;
        current=current->next;

        free(temp);
    }
    *head = current;
    if (!current)
    {
        return;
    }

    while(current &&current->next)
    {

        if(current->next->endpoint->node_num==vertex_name){

            temp = current->next;

            current->next = current->next->next;


            free(temp);

        }

        current=current->next;

    }
    printf("end\n");
}
void add_edge(pedge *head,pedge edge){
    edge->next = *head;
    *head= edge;
}
void print_edge(pedge edge){
    if (edge)
    {
    printf("-%d->%d",edge->weight,edge->endpoint->node_num);
    }
}
void delete_all_edges(pedge *head){
    pedge current = *head;
    pedge temp;
    while (current)
    {
        temp=current;
        current=current->next;
        free(temp);
    }
    *head = NULL;

}