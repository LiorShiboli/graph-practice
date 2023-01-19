#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "edge.h"
#include "node.h"
void delete_node(pnode *head,int name){
    pnode current = *head;
    while (current)
    {
        delete_edges_to( &(current->edges),name);
    }
    while (current)
    {
        if()
    }


}
void add_node(pnode *head,pnode node){
    node->next= *head;
    head= &node;
}
void print_node(pnode node){
    pedge p = node->edges;
    if (node)
    {


    printf("node %d",node->node_num);
    while (p)
    {
        print_edge(p);
    }

    }

}
void delete_all_nodes(pnode *head){}
