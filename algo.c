#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "node.h"
#include "edge.h"
#include "algo.h"
void build_graph_cmd(pnode *head){
    deleteGraph_cmd(head);
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

    int vertex_name;
    while (scanf(" n %d",&vertex_name))
    {

        pnode vertex = find_node(head, vertex_name);

        int weight = -1, to_vertex = -1;
        pedge new_edge=NULL;
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
    int vertex_name = -1;
    scanf(" %d",&vertex_name);

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
    delete_node(head,vertex);

}
void printGraph_cmd(pnode head){
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
    delete_all_nodes(head);
    }
}
void shortsPath_cmd(pnode head){
    int from_vertex,to_vertex;
    scanf("%d %d",&from_vertex,&to_vertex);
    printf("Dijsktra shortest path: %d \n\r",dijkstra(head,from_vertex,to_vertex));

}
void TSP_cmd(pnode head){
    int vertexnum;
    scanf(" %d", &vertexnum);
    int vertex=-1;
    scanf(" %d",&vertex);
    pnode *arr= (pnode*)malloc(sizeof(pnode*));
    int len=1;
    arr[0]=find_node(&head,vertex);

    for (int i = 0; i < vertexnum-1; i++)
    {
        scanf(" %d",&vertex);

        arr = realloc(arr,sizeof(pnode*)*(len+1));
        arr[len]=find_node(&head, vertex);
        len++;
    }

    int tspath= TSP(head,len,arr,0,len-1);
    printf("TSP shortest path: %d\n\r",tspath);
    free(arr);
}
int dijkstra(pnode head, int from_vertex,int to_vertex){

    pnode current = head;
    while (current)
    {

        current->path_num=-1;
        current->visited=0;
        if (current->node_num==from_vertex)
        {
            current->path_num =0;
        }

        current= current->next;
    }
    pnode min = head;

    while (min)
    {
        min=NULL;
    pnode current=head;
    while (current)
    {

     if (!(current->visited)&&current->path_num!=-1)
     {
        if (min==NULL || current->path_num<min->path_num)
        {
            min=current;
        }

     }
     current= current->next;
    }
    if (min==NULL)
    {
        return -1;
    }

    if (min->node_num==to_vertex)
    {
        pnode p =head;
        while (p)
        {
            p->visited=0;
            p=p->next;
        }

        return min->path_num;
    }
    pedge edge =min->edges;
    while (edge)
    {

        if ((edge->endpoint->path_num==-1)||( edge->endpoint->path_num>(min->path_num+edge->weight)))
        {
            edge->endpoint->path_num=min->path_num+edge->weight;
        }
    edge=edge->next;
    }
    min->visited=1;





    }
    return -1;


}
int TSP(pnode head,int len, pnode arr[],int l,int r){
    int i;
    int path;
    if (l == r)
    {
        path=0;
        for (int j = 0; j < len-1; j++)
        {
            int min_path =dijkstra(head,arr[j]->node_num,arr[j+1]->node_num);
            if (min_path==-1)
            {
                return -1;
            }
            path+=min_path;

        }

    }
    else {
        path=-1;
        for (i = l; i <= r; i++) {
            pnode temp = *(arr+l);
            *(arr+l)=*(arr+i);
            *(arr+i)= temp;
            int min_path = TSP(head,len,arr, l + 1, r);
            if (min_path!=-1)
            {
                if ((min_path<path)||(path==-1))
                {
                    path=min_path;
                }

            }

            temp = *(arr+l);
            *(arr+l)=*(arr+i);
            *(arr+i)= temp;
        }
    }
    return path;
}


