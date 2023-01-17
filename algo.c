#include <stdio.h>
#include "graph.h"
void build_graph_cmd(pnode *head){
    deleteGraph_cmd(head);
    printf("build praph\n");
    int vertex_num = 0;
    scanf(" %d",&vertex_num);
    int vertex=-1;
    printf("Vertexnum=%d \n",vertex_num);
    char input;
    while (scanf(" n %d",&vertex))
    {
        printf("build %d edges\n",vertex);
        int weight = -1, to_vertex = -1;
        while (scanf(" %d",&to_vertex)&&scanf(" %d",&weight))
        {
            printf(" add to %d an edge to %d with %d weight\n",vertex,to_vertex,weight);
        }

    }



}
void insert_node_cmd(pnode *head){
    printf("get and insert node\n");
    int vertex = -1;
    scanf(" %d",&vertex);

        printf("build %d edges\n",vertex);
        int weight = -1, to_vertex = -1;
        while (scanf(" %d",&to_vertex)&&scanf("%d",&weight))
        {
            printf(" add to %d an edge to %d with %d weight\n",vertex,to_vertex,weight);
        }

}
void delete_node_cmd(pnode *head){
    int vertex = -1;
    scanf(" %d",&vertex);
    printf("delete %d",vertex);
}
void printGraph_cmd(pnode head){printf("print graph \n");} //for self debug
void deleteGraph_cmd(pnode* head){printf("delete graph \n");}
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