#include <stdio.h>
#include "FsmTiny.h"

#define KEY_PLAY_PAUSE	1
#define KEY_STOP	2

#define MP3	"����.mp3"

void* fsm;

void StopState(size_t eventArgs);
void PlayState(size_t eventArgs);
void PauseState(size_t eventArgs);

void StopState(size_t eventArgs)
{
	printf("\nֹͣ״̬:���յ�����=%zu\n", eventArgs);
	if (eventArgs == KEY_PLAY_PAUSE)
	{
		printf("��ʼ����:%s\n", MP3);//��ʾ״̬���ж���
		FsmTiny_SetNew(fsm, PlayState);
	}
}

void PlayState(size_t eventArgs)
{
	printf("\n����״̬:���յ�����=%zu\n", eventArgs);
	if (eventArgs == KEY_PLAY_PAUSE)
	{
		printf("��ʼ��ͣ\n");//��ʾ״̬���ж���
		FsmTiny_SetNew(fsm, PauseState);
	}
	else if (eventArgs == KEY_STOP)
	{
		printf("��ʼֹͣ\n");//��ʾ״̬���ж���
		FsmTiny_SetNew(fsm, StopState);
	}
}

void PauseState(size_t eventArgs)
{
	printf("\n��ͣ״̬:���յ�����=%zu\n", eventArgs);
	if (eventArgs == KEY_PLAY_PAUSE)
	{
		printf("��������:%s\n", MP3);//��ʾ״̬���ж���
		FsmTiny_SetNew(fsm, PlayState);
	}
	else if (eventArgs == KEY_STOP)
	{
		printf("��ʼֹͣ\n");//��ʾ״̬���ж���
		FsmTiny_SetNew(fsm, StopState);
	}
}



int main(void)
{
	fsm = FsmTiny_Create(StopState, NULL);
	//ģ�ⰴ���¼���
	FsmTiny_Transit(fsm, KEY_PLAY_PAUSE);
	FsmTiny_Transit(fsm, KEY_PLAY_PAUSE);
	FsmTiny_Transit(fsm, KEY_PLAY_PAUSE);
	FsmTiny_Transit(fsm, KEY_STOP);
	FsmTiny_Dispose(fsm);
	return 0;
}