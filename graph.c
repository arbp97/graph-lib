#include "graph.h"

Graph *createGraph(int vertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->list = NULL;

    graph->list = createAdjList(vertices);

    return graph;
}

AdjList *createAdjList(int vertices)
{
    AdjList *list = (AdjList *)malloc(vertices * sizeof(AdjList));

    for (size_t i = 0; i < vertices; i++)
    {
        list[i].head = NULL;
        list[i].tail = NULL;
    }

    return list;
}

Vertex *createVertex(int index)
{
    Vertex *vertex = (Vertex *)malloc(sizeof(Vertex));
    vertex->index = index;
    vertex->next = NULL;

    return vertex;
}

void addVertex(Graph *graph, Vertex *vertex)
{
    if (!findVertex(graph, vertex->index))
    {
        if (vertex->index > (graph->vertices - 1))
        {
            /*
                En este caso debemos reservar mas
                memoria para el array en el grafo,
                para poder alojar al nuevo vertice
            */
            graph->vertices++;
            graph->list = realloc(graph->list, graph->vertices * sizeof(AdjList));
            graph->list[vertex->index].head = NULL;
            graph->list[vertex->index].tail = NULL;
        }

        graph->list[vertex->index].head = vertex;
        graph->list[vertex->index].tail =
            graph->list[vertex->index].head;
    }
    else
        printf("ERROR: Ya existe ese nodo en el grafo");
}

void addEdge(Graph *graph, Vertex *src, Vertex *dest)
{
    if (findVertex(graph, src->index) && findVertex(graph, dest->index))
    {
        /*
            apuntamos el puntero next del vertice destino
            a la cabeza de la lista del source, y cambiamos
            la cabeza de esta lista por dest, para agregarlo.
            Se deben crear nuevos vertices, ya que lo estamos
            agregando a una lista distinta de la principal.
        */
        Vertex *new_edge_dest = createVertex(dest->index);
        Vertex *new_edge_src = createVertex(src->index);

        /*
            Se cargan las nuevas aristas entre los vertices:
            Aqui se hace una diferencia entre si el vertice
            ya tenia aristas o no:
            -si no tiene (head = tail), entonces se agrega en
            el puntero a la cola, y se iguala el puntero sig.
            de la cabeza para que apunte a la cola.
            -si tiene, entonces primero se agrega en el puntero
            siguiente a la cola, y luego se cambia la referencia
            de la cola, siendo esta ahora el nodo que ingresamos
        */
        if (graph->list[src->index].head == graph->list[src->index].tail)
        {
            graph->list[src->index].tail = new_edge_dest;
            graph->list[src->index].head->next = graph->list[src->index].tail;
        }
        else
        {
            graph->list[src->index].tail->next = new_edge_dest;
            graph->list[src->index].tail = new_edge_dest;
        }

        /* ya que no es un grafo dirigido, la referencia es bidireccional */
        if (graph->list[dest->index].head == graph->list[dest->index].tail)
        {
            graph->list[dest->index].tail = new_edge_src;
            graph->list[dest->index].head->next = graph->list[dest->index].tail;
        }
        else
        {
            graph->list[dest->index].tail->next = new_edge_src;
            graph->list[dest->index].tail = new_edge_src;
        }
    }
    else
        printf("ERROR: Los nodos deben pertenecer al grafo");
}

Vertex *findVertex(Graph *graph, int index)
{
    int i;
    Vertex *found_vertex = NULL;

    for (i = 0; i < graph->vertices; ++i)
    {
        if (graph->list[i].head)
        {
            if (graph->list[i].head->index == index)
                found_vertex = graph->list[i].head;
        }
    }

    return found_vertex;
}

void deleteGraph(Graph *graph) {}

bool isGraphEmpty(Graph *graph)
{
    bool empty = true;

    if (!graph->list[0].head)
        empty = false;

    return empty;
}

void showGraph(Graph *graph)
{
    Vertex *cursor = NULL;

    for (size_t i = 0; i < graph->vertices; i++)
    {
        cursor = graph->list[i].head;

        while (cursor)
        {
            printf("[%i] -> ", cursor->index);
            cursor = cursor->next;
        }

        printf("\n");
    }
}