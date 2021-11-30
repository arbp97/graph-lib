#include "graph.h"

int main(int argc, char const *argv[])
{
    printf("HELLO");
    getchar();

    Graph* graph = createGraph(4);
    printf("Graph created");
    getchar();
    Vertex* v_1 = createVertex(0);
    Vertex* v_2 = createVertex(1);
    Vertex* v_3 = createVertex(2);
    Vertex* v_4 = createVertex(3);
    Vertex* v_5 = createVertex(4);
    printf("Vertices created");
    getchar();

    addVertex(graph, v_1);
    addVertex(graph, v_2);
    addVertex(graph, v_3);
    addVertex(graph, v_4);
    printf("Vertices added");
    getchar();

    addVertex(graph, v_5);
    printf("Non prepared vertex added");
    getchar();

    for (size_t i = 0; i < graph->vertices; i++)
        printf("[%i]\n", graph->list[i].head->index);
    
    getchar();
    return 0;
}
