#include "graph.h"
#include "queue.h"
#include "stack.h"

int main(int argc, char const *argv[])
{
    Graph *graph = create_graph(4);
 
    Vertex *v_0 = create_vertex(0);
    Vertex *v_1 = create_vertex(1);
    Vertex *v_2 = create_vertex(2);
    Vertex *v_3 = create_vertex(3);

    add_vertex(graph, v_0);
    add_vertex(graph, v_1);
    add_vertex(graph, v_2);
    add_vertex(graph, v_3);

    add_edge(graph, v_0, v_1);
    add_edge(graph, v_0, v_2);
    add_edge(graph, v_1, v_2);
    add_edge(graph, v_2, v_0);
    add_edge(graph, v_2, v_3);
    add_edge(graph, v_3, v_3);

    show_graph(graph);

    bfs(graph, graph->list[2].head);

    getchar();

    dfs(graph, graph->list[2].head);

    delete_graph(&graph);

    /****************************************************************/

    /*Queue* q = create_queue();

    puts(is_queue_empty(q) ? "true" : "false");

    Node* new_node = create_node(1);
    Node* new_node_2 = create_node(2);

    push(&q, new_node);
    push(&q, new_node_2);

    printf("Q->FIRST %i Q->LAST %i",q->first->data,q->last->data);
    //puts(is_queue_empty(q) ? "true" : "false");

    //Node* out = pull(&q);

    printf("\nfirst after pull %i\n", q->first->data);

    //out = pull(&q);
    puts(is_queue_empty(q) ? "true" : "false");

    delete_queue(&q);

    puts(q ? "Not deleted" : "deleted");*/

    /****************************************************************/

    /*Stack* stack = create_stack();


    push(&stack, create_node(0));
    printf("0\n");
    push(&stack, create_node(1));
    printf("1\n");
    push(&stack, create_node(2));
    printf("2\n");

    printf("\n%i\n", pop(&stack)->data);
    printf("%i\n", pop(&stack)->data);
    printf("%i\n", pop(&stack)->data);

    delete_stack(&stack);*/

    return 0;
}
