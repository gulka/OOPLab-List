#include "container.h"

typedef struct node {
		             char *p_value; 	// ”казатель на значение 
		     	     node *p_next_node;	// ”казатель на следующий узел
	                }l, *lp;

int main(int argc, char** argv)
{
    hello_world();
    return 0;
}