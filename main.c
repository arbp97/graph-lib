#include "graph.h"

int main(int argc, char const *argv[])
{
    Graph *graph = createGraph(4);
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
    deleteGraph(graph);
    printf("\nShowing graph?");
    getchar();
    showGraph(graph);
    printf("\nBY SIGMAR YES");
    if(graph) printf("\nBY SIGMAR NO");
    getchar();
    return 0;
}
