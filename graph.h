#ifndef _GRAPH_H_
#define _GRAPH_H_
#pragma once
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
Graph *createGraph(int vertices);

/*
    Devuelve una lista de vertices vacia.
*/
AdjList *createAdjList(int vertices);

/*
    Devuelve un nuevo vertice.
*/
Vertex *createVertex(int index);

/*
    Agrega un vertice al grafo con el dato especificado.
*/
void addVertex(Graph *graph, Vertex *vertex);

/*
    Agrega una arista entre dos vertices.
*/
void addEdge(Graph *graph, Vertex *src, Vertex *dest);

/*
    Encuentra y devuelve un vertice en un grafo segun
    el dato.
*/
Vertex *findVertex(Graph *graph, int index);

/*
    Elimina un grafo.
*/
void deleteGraph(Graph **graph);

/*
    Elimina una arista entre dos grafos
    (unidireccional, utilizado por deleteGraph)
*/
void deleteEdge(AdjList *list, Vertex *src);

/*
    Revisa si un grafo esta vacio.
*/
bool isGraphEmpty(Graph *graph);

/*
    Imprime el grafo
*/
void showGraph(Graph *graph);

#endif //! _GRAPH_H_
