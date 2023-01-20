#include "graph.h"
#ifndef NODE_
#define NODE_
void delete_node(pnode *head,int name);
void add_node(pnode *head,pnode node);
void print_node(pnode node);
void delete_all_nodes(pnode *head);
pnode find_node(pnode *head,int name);
#endif