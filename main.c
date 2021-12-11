#include "graph.h"
#include "queue.h"

int main(int argc, char const *argv[])
{
    /*Graph *graph = createGraph(4);
    printf("Graph created");
    getchar();
 
    Vertex *v_0 = createVertex(0);
    Vertex *v_1 = createVertex(1);
    Vertex *v_2 = createVertex(2);
    Vertex *v_3 = createVertex(3);
    Vertex *v_4 = createVertex(4);
    printf("Vertices created");
    getchar();

    addVertex(graph, v_0);
    addVertex(graph, v_1);
    addVertex(graph, v_2);
    addVertex(graph, v_3);
    printf("Vertices added");
    getchar();
    if(isGraphEmpty(graph)) printf("This should NOT appear"); 

    addVertex(graph, v_4);
    printf("Non prepared vertex added");
    getchar();

    addEdge(graph, v_0, v_1);
    addEdge(graph, v_0, v_2);
    addEdge(graph, v_0, v_3);

    addEdge(graph, v_2, v_3);

    addEdge(graph, v_4, v_1);

    showGraph(graph);
    getchar();
    deleteGraph(&graph);

    getchar();
    */
    /****************************************************************/

    Queue* q = create_queue();

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

    puts(q ? "Not deleted" : "deleted");

    return 0;
}
