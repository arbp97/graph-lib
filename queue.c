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

void enqueue(Queue** queue, Node* node)
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

Node* dequeue(Queue** queue)
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

Node* find_node(Queue* queue, int data)
{
  if(!queue)
  {
    printf("ERROR: queue is null");
    return NULL;
  }
  else if(is_queue_empty(queue))
  {
    printf("ERROR: queue is empty");
    return NULL;
  }

  Node* cursor = queue->first;
  Node* result = NULL;

  while(cursor)
  {
    if(cursor->data == data)
    {
      result = cursor;
      cursor = NULL;
    }
    else
    {
      cursor = cursor->next;
    }
  }

  return result;
}

void delete_queue(Queue** queue)
{
  if(!queue)
  {
    printf("/nERROR: queue is null");
  }
  else
  {
    if(!is_queue_empty(*queue))
    {
      Node* cursor = (*queue)->first;
      Node* aux = NULL;

      while(cursor)
      {
        aux = cursor->next;
        free(cursor);
        cursor = NULL;

        cursor = aux;
      }
    }

    free(*queue);
    *queue = NULL;
  }
}
