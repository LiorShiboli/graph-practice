#include "graph.h"
#include <stdio.h>
int main(){
    int i=0;
    char cmd;
    pnode head=NULL;
    while (scanf(" %c",&cmd)==1 )
    {

        switch( cmd)
    {
	    case 'A':
			build_graph_cmd(&head);
			break;

	    case 'B':
			insert_node_cmd(&head);
			break;

	    case 'D':
			delete_node_cmd(&head);
			break;

      case 'S':
            shortsPath_cmd(head);
            break;
      case 'T':
            TSP_cmd(head);
            break;
	    default:
			printf("%c command not found\n",cmd);
			break;
}
    }
  deleteGraph_cmd(&head);
    return 0;
}