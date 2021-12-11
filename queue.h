#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/* FIFO QUEUE */

/* in -> last=first -> out
 * in -> last<-first -> out
 * in -> last(new)<-node(ex last)<-first -> out
 */

typedef struct Node
{
  int data;
  struct Node* next;
} Node;

typedef struct Queue
{
  Node* first; // first to go (last added)
  Node* last; // last in Q
} Queue;

/***************************************************************/

// Returns empty queue
Queue* create_queue();

// Returns a new node
Node* create_node(int data);

// Pushes node into the queue
void push(Queue** queue, Node* node);

// Returns the first node in the queue
Node* pull(Queue** queue);

// Deletes queue and nodes
void delete_queue(Queue** queue);

bool is_queue_empty(Queue* queue);

#endif //! _QUEUE_H_
