#include <stdio.h>
#include "FsmTiny.h"

#define KEY_PLAY_PAUSE	1
#define KEY_STOP	2

#define MP3	"国歌.mp3"

void* fsm;

void StopState(size_t value);
void PlayState(size_t value);
void PauseState(size_t value);

void StopState(size_t value)
{
	printf("\n停止状态:接收到按键=%zu\n", value);
	if (value == KEY_PLAY_PAUSE)
	{
		printf("开始播放:%s\n", MP3);//表示状态机中动作
		FsmTiny_SetNew(fsm, PlayState);
	}
}

void PlayState(size_t value)
{
	printf("\n播放状态:接收到按键=%zu\n", value);
	if (value == KEY_PLAY_PAUSE)
	{
		printf("开始暂停\n");//表示状态机中动作
		FsmTiny_SetNew(fsm, PauseState);
	}
	else if (value == KEY_STOP)
	{
		printf("开始停止\n");//表示状态机中动作
		FsmTiny_SetNew(fsm, StopState);
	}
}

void PauseState(size_t value)
{
	printf("\n暂停状态:接收到按键=%zu\n", value);
	if (value == KEY_PLAY_PAUSE)
	{
		printf("继续播放:%s\n", MP3);//表示状态机中动作
		FsmTiny_SetNew(fsm, PlayState);
	}
	else if (value == KEY_STOP)
	{
		printf("开始停止\n");//表示状态机中动作
		FsmTiny_SetNew(fsm, StopState);
	}
}

int main(void)
{

	fsm=FsmTiny_Create( StopState, NULL);
	//模拟按键事件。
	FsmTiny_Transit(fsm, KEY_PLAY_PAUSE);
	FsmTiny_Transit(fsm, KEY_PLAY_PAUSE);
	FsmTiny_Transit(fsm, KEY_PLAY_PAUSE);
	FsmTiny_Transit(fsm, KEY_STOP);
	FsmTiny_Dispose(fsm);
	return 0;
}