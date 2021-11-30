#include "graph.h"

Graph* createGraph(int vertices)
{
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->list = NULL;
    printf("in createGraph created graph");
    getchar();
    graph->list = createAdjList(vertices);

    return graph;
}

AdjList* createAdjList(int vertices)
{
    AdjList* list = (AdjList*) malloc(vertices * sizeof(AdjList));

    for (size_t i = 0; i < vertices; i++)
        list[i].head = NULL;
    
    return list;
}

Vertex* createVertex(int index)
{
    Vertex* vertex = (Vertex*) malloc(sizeof(Vertex));
    vertex->index = index;
    vertex->next = NULL;
    
    return vertex;
}

void addVertex(Graph* graph, Vertex* vertex)
{
    if (!findVertex(graph, vertex->index))
    {
        if (vertex->index > graph->vertices-1)
        {
            /*
                En este caso debemos reservar mas
                memoria para el array en el grafo,
                para poder alojar al nuevo vertice
            */
            graph->vertices++;
            graph->list = realloc(graph->list,graph->vertices * sizeof(AdjList));
            graph->list[vertex->index].head = NULL;
        }

        printf("vertex not found, adding");
        getchar();
        graph->list[vertex->index].head = vertex;
    }
    else printf("ERROR: Ya existe ese nodo en el grafo");
}

void addEdge(Graph* graph, Vertex* src, Vertex* dest){}

Vertex* findVertex(Graph* graph, int index)
{
    int i;
    Vertex* found_vertex = NULL;
    printf("in find vertex: %i graph vertices: %i", index, graph->vertices);
    getchar();
    for (i = 0; i < graph->vertices; ++i)
    {
        printf("inside for loop, index: %i", i);
        getchar();
        if (graph->list[i].head)
            if (graph->list[i].head->index == index)
                found_vertex = graph->list[i].head;          
    }

    return found_vertex;
}

void deleteGraph(Graph* graph){}

bool isGraphEmpty(Graph* graph)
{
    bool empty = true;

    if(!graph->list[0].head) empty = false;

    return empty;
}