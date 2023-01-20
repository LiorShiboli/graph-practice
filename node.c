#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "edge.h"
#include "node.h"
void delete_node(pnode *head,int name){

    pnode current = *head;
    pnode temp = NULL;
    while (current)
    {
        print_node(current);
        delete_edges_to( &(current->edges),name);

        current = current->next;
    }

    current = *head;
    while (current->next)
    {
        print_node(current);
        if(current->next->node_num==name){
            temp = current->next;
            current->next = current->next->next;
            delete_all_edges(&(temp->edges));
            free(temp);
        }
        current=current->next;
    }


}
void add_node(pnode *head,pnode node){
    node->next= *head;
    *head= node;
}
void print_node(pnode node){
    pedge p = node->edges;
    if (node)
    {


    printf("node %d \n",node->node_num);
    while (p)
    {
        print_edge(p);
        p=p->next;
    }
    printf("\n");
    }

}
void delete_all_nodes(pnode *head){

    while (*head)
    {
        delete_node(head,(*head)->node_num);
    }

}
pnode find_node(pnode *head,int name){
    pnode current = *head;
    while (current)
    {
        if (current->node_num==name)
        {
            return current;
        }
        current= current->next;

    }
    return NULL;
}