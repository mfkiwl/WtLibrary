#include "Queue.h"

struct Node
{
	QUEUE_TYPE Payload;
	struct Node* Next;
};

struct Queue
{
	struct Node* Head;
	struct Node* Tail;
};


void* Queue_Create(void);
void Queue_Push(void* queue, QUEUE_TYPE payload);
QUEUE_TYPE Queue_Pop(void* queue);
void Queue_Dispose(void* queue);