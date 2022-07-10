#include <stdio.h>
/*
	本例程是使用状态机模拟一个播放器的播放过程。
*/

//步骤1：包含头文件。
#include "FsmTiny.h"

#define KEY_PLAY_PAUSE	1
#define KEY_STOP	2

#define MP3	"国歌.mp3"

//步骤2：声明所有状态函数。
static void* StopState(size_t eventArgs, void* eventArgsX);
static void* PlayState(size_t eventArgs, void* eventArgsX);
static void* PauseState(size_t eventArgs, void* eventArgsX);

//步骤3：定义所有状态函数。
static void* StopState(size_t eventArgs, void* eventArgsX)
{
	printf("\n停止状态:接收到按键=%zu\n", eventArgs);
	if (eventArgs == KEY_PLAY_PAUSE)
	{
		printf("开始播放:%s\n", MP3);//表示状态机中动作
		return PlayState;//切换到播放状态
	}
	else
	{
		return NULL;//保持在当前状态
	}
}

static void* PlayState(size_t eventArgs, void* eventArgsX)
{
	printf("\n播放状态:接收到按键=%zu\n", eventArgs);
	if (eventArgs == KEY_PLAY_PAUSE)
	{
		printf("开始暂停\n");//表示状态机中动作
		return PauseState;//切换到暂停状态
	}
	else if (eventArgs == KEY_STOP)
	{
		printf("开始停止\n");//表示状态机中动作
		return StopState;//切换到停止状态
	}
	else
	{
		return NULL;//保持在当前状态
	}
}

static void* PauseState(size_t eventArgs, void* eventArgsX)
{
	printf("\n暂停状态:接收到按键=%zu\n", eventArgs);
	if (eventArgs == KEY_PLAY_PAUSE)
	{
		printf("继续播放:%s\n", MP3);//表示状态机中动作
		return PlayState;//切换到播放状态
	}
	else if (eventArgs == KEY_STOP)
	{
		printf("开始停止\n");//表示状态机中动作
		return StopState;//切换到停止状态
	}
	else
	{
		return NULL;//保持在当前状态
	}
}

int main(void)
{
	char ch;
	//步骤4：创建状态机。
	static void* fsm;
	fsm = FsmTiny_Start(StopState);
	//步骤5：在事件中触发状态函数。
	//下面模拟一些按键事件。
	FsmTiny_Transit(fsm, KEY_PLAY_PAUSE, NULL);
	FsmTiny_Transit(fsm, KEY_PLAY_PAUSE, NULL);
	FsmTiny_Transit(fsm, KEY_PLAY_PAUSE, NULL);
	FsmTiny_Transit(fsm, KEY_STOP, NULL);
	//步骤6：释放状态机。
	FsmTiny_Stop(fsm);

	printf("\nPress any key to exit.");
	ch = getchar();
	return 0;
}