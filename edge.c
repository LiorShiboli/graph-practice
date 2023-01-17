#include "graph.h"
#include "edges.h"
void delete_edges_to(pedge *head,int vertex_name){}
void add_edge(pedge *head,pedge edge){}
void print_edge(pedge edge){
    printf("-%d->%d",edge->weight,edge->endpoint->node_num);
}
void delete_all_edges(pedge *head){}