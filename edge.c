#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "edge.h"
void delete_edges_to(pedge *head,int vertex_name){
    pedge current = *head;
    pedge temp;
    while (current && current->endpoint->node_num == vertex_name)
    {
        temp=current;
        current=current->next;

        free(temp);
    }
    *head = current;
    while (current)
    {
        temp=current;
        current=current->next;
        if (temp->endpoint->node_num == vertex_name)
        {
            free(temp);
        }
    }
}
void add_edge(pedge *head,pedge edge){
    edge->next= *head;
    head= &edge;
}
void print_edge(pedge edge){
    printf("-%d->%d",edge->weight,edge->endpoint->node_num);
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