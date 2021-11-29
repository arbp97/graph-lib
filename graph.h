#ifndef _GRAPH_H_
#define _GRAPH_H_
#pragma once
#include <stdlib.h>
#include <stdio.h>

/*
    Un grafo consiste de una lista de listas de vertices
    adyacentes (es decir, que poseen una arista entre ellos,
    un puente).
    Esta seria una implementacion de un grafo no dirigido,
    representado con por una lista de adyacencias.

    Representacion de ejemplo:
    [AdjList]   
       [0]  ->  [1] ->  [2] ->  [3]
       [1]  ->  [0]
       [2]  ->  [0] ->  [3] 
       [3]  ->  [0] ->  [2]
*/

/*
    Este es un vertice, contiene el dato representado y
    un puntero al proximo vertice adyacente (arista)
*/
typedef struct Vertex
{
    int data;
    struct Vertex* next;
} Vertex;

/*
    Esta es la lista de adyacencias del vertice en
    cuestion. contiene el puntero al primer elemento y
    un puntero al ultimo (para facilitar la creacion
    de nuevos nodos).
*/
typedef struct AdjList
{
    Vertex* head;
    Vertex* tail;
} AdjList;

/*
    Esta estructura representa el grafo, posee una
    lista con todas las sublistas de vertices
    adyacentes.
*/
typedef struct Graph
{
    AdjList* list;
} Graph;

/**********************************************************/

/*
    Devuelve un grafo vacio.
*/
Graph* createGraph();

/*
    Devuelve un nuevo vertice.
*/
Vertex* createVertex(int data);

/*
    Agrega un vertice al grafo con el dato especificado.
*/
void addVertex(Graph* graph, int data);

/*
    Agrega una arista entre dos vertices.
*/
void addEdge(Graph* graph, Vertex* src, Vertex* dest);

/*
    Encuentra y devuelve un vertice en un grafo segun
    el dato.
*/
Vertex* findVertex(Graph* graph, int data);

#endif //! _GRAPH_H_