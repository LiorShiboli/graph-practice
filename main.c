#include "graph.h"
#include <stdio.h>
int main(){
    int i=0;
    char cmd;
    pnode head;
    while (scanf(" %c",&cmd) && i<5)
    {
        i++;
        switch( cmd)
{
	case 'A':
			build_graph_cmd(&head);
			break;

	case 'B':
			insert_node_cmd(&head);
			break;
	case 'D':
			delete_node_cmd;
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

    return 0;
}