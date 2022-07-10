#include <stdio.h>
/*
	��������ʹ��״̬��ģ��һ���������Ĳ��Ź��̡�
*/

//����1������ͷ�ļ���
#include "FsmTiny.h"

#define KEY_PLAY_PAUSE	1
#define KEY_STOP	2

#define MP3	"����.mp3"

//����2����������״̬������
static void* StopState(size_t eventArgs, void* eventArgsX);
static void* PlayState(size_t eventArgs, void* eventArgsX);
static void* PauseState(size_t eventArgs, void* eventArgsX);

//����3����������״̬������
static void* StopState(size_t eventArgs, void* eventArgsX)
{
	printf("\nֹͣ״̬:���յ�����=%zu\n", eventArgs);
	if (eventArgs == KEY_PLAY_PAUSE)
	{
		printf("��ʼ����:%s\n", MP3);//��ʾ״̬���ж���
		return PlayState;//�л�������״̬
	}
	else
	{
		return NULL;//�����ڵ�ǰ״̬
	}
}

static void* PlayState(size_t eventArgs, void* eventArgsX)
{
	printf("\n����״̬:���յ�����=%zu\n", eventArgs);
	if (eventArgs == KEY_PLAY_PAUSE)
	{
		printf("��ʼ��ͣ\n");//��ʾ״̬���ж���
		return PauseState;//�л�����ͣ״̬
	}
	else if (eventArgs == KEY_STOP)
	{
		printf("��ʼֹͣ\n");//��ʾ״̬���ж���
		return StopState;//�л���ֹͣ״̬
	}
	else
	{
		return NULL;//�����ڵ�ǰ״̬
	}
}

static void* PauseState(size_t eventArgs, void* eventArgsX)
{
	printf("\n��ͣ״̬:���յ�����=%zu\n", eventArgs);
	if (eventArgs == KEY_PLAY_PAUSE)
	{
		printf("��������:%s\n", MP3);//��ʾ״̬���ж���
		return PlayState;//�л�������״̬
	}
	else if (eventArgs == KEY_STOP)
	{
		printf("��ʼֹͣ\n");//��ʾ״̬���ж���
		return StopState;//�л���ֹͣ״̬
	}
	else
	{
		return NULL;//�����ڵ�ǰ״̬
	}
}

int main(void)
{
	char ch;
	//����4������״̬����
	static void* fsm;
	fsm = FsmTiny_Start(StopState);
	//����5�����¼��д���״̬������
	//����ģ��һЩ�����¼���
	FsmTiny_Transit(fsm, KEY_PLAY_PAUSE, NULL);
	FsmTiny_Transit(fsm, KEY_PLAY_PAUSE, NULL);
	FsmTiny_Transit(fsm, KEY_PLAY_PAUSE, NULL);
	FsmTiny_Transit(fsm, KEY_STOP, NULL);
	//����6���ͷ�״̬����
	FsmTiny_Stop(fsm);

	printf("\nPress any key to exit.");
	ch = getchar();
	return 0;
}