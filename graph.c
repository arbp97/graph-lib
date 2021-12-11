#include "graph.h"

Graph *create_graph(int vertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->list = NULL;

    graph->list = create_adj_list(vertices);

    return graph;
}

AdjList *create_adj_list(int vertices)
{
    AdjList *list = (AdjList *)malloc(vertices * sizeof(AdjList));

    for (int i = 0; i < vertices; i++)
    {
        list[i].head = NULL;
        list[i].tail = NULL;
    }

    return list;
}

Vertex *create_vertex(int index)
{
    Vertex *vertex = (Vertex *)malloc(sizeof(Vertex));
    vertex->index = index;
    vertex->next = NULL;

    return vertex;
}

void add_vertex(Graph *graph, Vertex *vertex)
{
    if (!find_vertex(graph, vertex->index))
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

void add_edge(Graph *graph, Vertex *src, Vertex *dest)
{
    if (find_vertex(graph, src->index) && find_vertex(graph, dest->index))
    {
        /*
            apuntamos el puntero next del vertice destino
            a la cabeza de la lista del source, y cambiamos
            la cabeza de esta lista por dest, para agregarlo.
            Se deben crear nuevos vertices, ya que lo estamos
            agregando a una lista distinta de la principal.
        */
        Vertex *new_edge_dest = create_vertex(dest->index);
        Vertex *new_edge_src = create_vertex(src->index);

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

        /* ya que no es un grafo dirigido, la referencia es bidireccional 0*/
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

Vertex *find_vertex(Graph *graph, int index)
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

void delete_edge(AdjList *list, Vertex *src)
{
    if (list->head == list->tail)
    {
        /*
            Si hay solo un elemento en la lista, entonces
            solo asignamos NULL a la cola y la cabeza.
        */
        list->tail = NULL;
        list->head = NULL;
    }
    else
    {
        /*
            Si hay mas de un elemento, hay tres casos:
            -el vertice se encuentra al principio de la lista
            -el vertice se encuentra al final
            -el vertice se encuentra en el medio.
        */

        Vertex *cursor = NULL;
        // contiene el nodo previo al cursor
        Vertex *aux_cursor = NULL;
        bool found = false;
        cursor = list->head;

        while (cursor && !found)
        {
            if (src == list->head)
            {
                list->head = src->next;
                found = true;
            }
            else if (src == list->tail)
            {
                list->tail = aux_cursor;
                aux_cursor->next = NULL;
                found = true;
            }
            else if (src == cursor)
            {
                aux_cursor->next = cursor->next;
                found = true;
            }

            aux_cursor = cursor;
            cursor = cursor->next;
        }
    }

    free(src);
    src = NULL;
}

void delete_graph(Graph **graph)
{
    Vertex *cursor = NULL;
    Vertex *aux_cursor = NULL;

    for (int i = 0; i < (*graph)->vertices; i++)
    {
        cursor = (*graph)->list[i].head;
        printf("Adjlist vertex: %i", i);
        getchar();
        while (cursor)
        {
            printf("Edge: %i", cursor->index);
            getchar();
            aux_cursor = cursor->next;
            delete_edge(&(*graph)->list[i], cursor);
            printf("Deleted\n");
            cursor = aux_cursor;
        }
    }

    free((*graph)->list);
    (*graph)->list = NULL;
    free((*graph));
    *(graph) = NULL;

    printf("Graph deleted");
}

bool is_graph_empty(Graph *graph)
{
    bool empty = true;

    if(graph)
        if(graph->list)
            if(graph->list->head) empty = false;

    return empty;
}

void show_graph(Graph *graph)
{
    Vertex *cursor = NULL;

    if (!is_graph_empty(graph))
    {
        for (int i = 0; i < graph->vertices; i++)
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
    else printf("Graph is EMPTY");
}
