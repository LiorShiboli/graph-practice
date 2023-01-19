#include "graph.h"
#ifndef EDGE_
#define EDGE_
void delete_edges_to(pedge *head,int vertex_name);
void add_edge(pedge *head,pedge edge);
void print_edge(pedge edge);
void delete_all_edges(pedge *head);
#endif