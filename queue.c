#include "queue.h"

Queue* create_queue()
{
  Queue* new = (Queue*) malloc(sizeof(Queue));

  new->first = NULL;
  new->last = NULL;

  return new;
}

Node* create_node(int data)
{
  Node* new = (Node*) malloc(sizeof(Node));

  new->data = data;
  new->next = NULL;

  return new;
}

void push(Queue** queue, Node* node)
{
  /*
   * Cases:
   *  Q is empty:
   *      set node to be first and last in Q
   *  Q has multiple nodes
   *      set next to last = node
   *      set node to be last
   */
  if(queue)
  {
    if(is_queue_empty(*queue))
    {
      (*queue)->last = node;
      (*queue)->first = (*queue)->last;
    }
    else
    {
      (*queue)->last->next = node;
      (*queue)->last = node;
    }
  }
  else
  {
    printf("ERROR: queue is null");
  }
}

Node* pull(Queue** queue)
{
  /*
   * Return the first in q and remove it
   * set previous to first as first
   */
  if(!queue)
  {
    printf("ERROR: Queue is null");
    return NULL;
  }

  if(is_queue_empty(*queue))
  {
    printf("ERROR: Empty queue");
    return NULL;
  }

  Node* out = (*queue)->first;

  (*queue)->first = (*queue)->first->next;

  return out;
}

bool is_queue_empty(Queue* queue)
{
  if(queue)
  {
    if(queue->first) return false;
  }
  else
  {
    printf("\nERROR: Queue is null");
  }

  return true;
}
