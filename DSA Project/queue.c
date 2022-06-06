#include<stdio.h>
#include<stdlib.h>
#include"limits.h"
#include"queue.h"

 

void init_Queue(Queue *q)
{
          q->front = NULL;
          q->rear = NULL;
}

void enQueue(Queue *q, int d)
{
          q_node *nn = (q_node *)malloc(sizeof(q_node));
          nn->data = d;
          nn->next = NULL;
          if (q->front == NULL)
          {
                    q->front = nn;
                    q->rear = nn;
          }
          else
          {
                    q->rear->next = nn;
                    q->rear = nn;
          }
}

int deQueue(Queue *q)
{
          q_node *p;
          p = q->front;
          int x;

          if (q->front == NULL)
                    return INT_MIN;
          x = p->data;
          if (q->front == q->rear)
          {
                    q->front = NULL;
                    q->rear = NULL;
          }
          else
          {
                    q->front = p->next;
                    free(p);
          }
          return x;
}

int is_Queue_Empty(Queue q)
{
          return (q.front == NULL);
}

int is_Queue_Full(Queue q)
{
          return 0;
}