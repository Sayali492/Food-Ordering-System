typedef struct q_node
{
          int data;
          struct q_node *next;

} q_node;

typedef struct Queue
{
          q_node *front;
          q_node *rear;

} Queue;

void init_Queue(Queue *q);
void enQueue(Queue *q, int d);
int deQueue(Queue *q);
int is_Queue_Empty(Queue q);
int is_Queue_Full(Queue q);