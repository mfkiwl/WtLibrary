#ifndef __QUEUE_H_
#define __QUEUE_H_
#define QUEUE_TYPE int //�����Զ���
void* Queue_Create(void);
void Queue_Push(void* queue, QUEUE_TYPE payload);
QUEUE_TYPE Queue_Pop(void* queue);
void Queue_Dispose(void* queue);
#endif
