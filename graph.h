#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*
    Un grafo consiste de una lista de listas de vertices
    adyacentes (es decir, que poseen una arista entre ellos,
    un puente).
    Esta seria una implementacion de un grafo no dirigido,
    representado con por una lista de adyacencias.

    Representacion de ejemplo:
    [AdjList]   
       (head)[0]  ->  [1] ->  [2] ->  [3]
       (head)[1]  ->  [0]
       (head)[2]  ->  [0] ->  [3] 
       (head)[3]  ->  [0] ->  [2]
*/

/*
    Este es un vertice, contiene el dato representado y
    un puntero al proximo vertice adyacente (arista)
*/
typedef struct Vertex
{
    int index;
    struct Vertex *next;
} Vertex;

/*
    Esta es la lista de adyacencias del vertice en
    cuestion. contiene el puntero al primer elemento,
*/
typedef struct AdjList
{
    Vertex *head;
    Vertex *tail;
} AdjList;

/*
    Esta estructura representa el grafo, posee una
    lista con todas las sublistas de vertices
    adyacentes, y la cantidad de vertices.
*/
typedef struct Graph
{
    int vertices;
    AdjList *list;
} Graph;

/**********************************************************/

/*
    Devuelve un grafo vacio de N vertices.
*/
Graph *create_graph(int vertices);

/*
    Devuelve una lista de vertices vacia.
*/
AdjList *create_adj_list(int vertices);

/*
    Devuelve un nuevo vertice.
*/
Vertex *create_vertex(int index);

/*
    Agrega un vertice al grafo con el dato especificado.
*/
void add_vertex(Graph *graph, Vertex *vertex);

/*
    Agrega una arista entre dos vertices.
*/
void add_edge(Graph *graph, Vertex *src, Vertex *dest);

/*
    Encuentra y devuelve un vertice en un grafo segun
    el dato.
*/
Vertex *find_vertex(Graph *graph, int index);

// Retorna la cantidad de aristas del vertice
int count_edges(Graph* graph, Vertex* vertex);

// retorna true/false si encuentra arista o no
bool has_edge(Graph* graph, Vertex* src, Vertex* dest);
/*
    Elimina un grafo.
*/
void delete_graph(Graph **graph);

/*
    Elimina una arista entre dos grafos
    (unidireccional, utilizado por deleteGraph)
*/
void delete_edge(AdjList *list, Vertex *src);

/*
    Revisa si un grafo esta vacio.
*/
bool is_graph_empty(Graph *graph);

/*
    Imprime el grafo
*/
void show_graph(Graph *graph);

// shows breadth-first search order
void bfs(Graph* graph, Vertex* root);

#endif //! _GRAPH_H_
