#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "node.h"
#include "edge.h"
#include "algo.h"
void build_graph_cmd(pnode *head){
    deleteGraph_cmd(head);
    printf("build praph\n");
    int vertex_num = 0;
    scanf(" %d",&vertex_num);
    if (vertex_num==0)
    {
        return;
    }
    pnode new_node=NULL;
    for (int i = 0; i < vertex_num; i++)
    {
        new_node = (pnode)malloc(sizeof(node));
        if (!new_node)
        {
            return;
        }

        new_node->node_num = i ;
        new_node->edges = NULL ;
        add_node(head,new_node);

    }

    printf("Vertexnum=%d \n",vertex_num);
    int vertex_name;
    while (scanf(" n %d",&vertex_name))
    {

        pnode vertex = find_node(head, vertex_name);

        int weight = -1, to_vertex = -1;
        pedge new_edge=NULL;
        printf("build %d edges\n",vertex->node_num);
        while (scanf(" %d",&to_vertex)&&scanf(" %d",&weight))
        {

            new_edge = (pedge)malloc(sizeof(edge));

            if (!new_edge)
            {
                return;
            }
            new_edge->endpoint = find_node(head,to_vertex);
            new_edge->weight =weight;
            new_edge->next = NULL;
            add_edge(&(vertex->edges),new_edge);

        }

    }



}
void insert_node_cmd(pnode *head){
    printf("get and insert node\n");
    int vertex_name = -1;
    scanf(" %d",&vertex_name);

    printf("build %d edges\n",vertex_name);
    pnode vertex = find_node(head,vertex_name);
    if (!vertex)
    {
    vertex = (pnode)malloc(sizeof(node));
    add_node(head,vertex);
    }
    if (!vertex)
    {
        return;
    }
    delete_all_edges(&(vertex->edges));
    vertex->node_num=vertex_name;
    int weight = -1, to_vertex = -1;
    pedge new_edge =NULL;
    while (scanf(" %d",&to_vertex)&&scanf("%d",&weight))
    {
        new_edge = (pedge)malloc(sizeof(edge));
            if (!new_edge)
            {
                return;
            }
            new_edge->endpoint = find_node(head,to_vertex);
            new_edge->weight =weight;
            new_edge->next = NULL;
            add_edge(&(vertex->edges),new_edge);
    }

}
void delete_node_cmd(pnode *head){
    int vertex = -1;
    scanf(" %d",&vertex);
    printf("delete \n");
    delete_node(head,vertex);

}
void printGraph_cmd(pnode head){
    printf("print graph \n");
    pnode current= head;
    while (current)
    {
        print_node(current);
        current = current->next;
    }


    } //for self debug

void deleteGraph_cmd(pnode* head){

    if (*head)
    {
    printf("delete graph \n");
    delete_all_nodes(head);
    }
}
void shortsPath_cmd(pnode head){
    int from_vertex,to_vertex;
    scanf("%d %d",&from_vertex,&to_vertex);
    printf("dijkstra and find shortest path between %d to %d \n",from_vertex,to_vertex);

}
void TSP_cmd(pnode head){
    int vertexnum;
    scanf(" %d", &vertexnum);
    int vertex=-1;
    for (int i = 0; i < vertexnum; i++)
    {

        scanf(" %d",&vertex);
        printf("add %d to the %d points\n",vertex,vertexnum);
    }

    printf("get k points,find all the shortest paths between them,and ran tsp between them \n");

}
int dijkstra(pnode head, int from_vertex,int to_vertex){
    
}