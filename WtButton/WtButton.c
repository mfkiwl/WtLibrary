#include "..\FsmTiny\FsmTiny.h"
#include "WtButton.h"

static struct Button
{
	unsigned char Id;
	unsigned int TimeUp;
	unsigned int TimeDown;
	unsigned char CountUp;
	unsigned char CountDown;
	unsigned char Interval;//表示在按下状态时，经历多少个 Interval 周期引发一次 KeyDown
	unsigned char Ticks;//表示在抬起状态时，经历多少个 ticks 之内判定为短按。
	struct Button* Next;
}*Head;

static WtButtonRead Read;
static WtButtonReport Report;

static void* Fsm;
static void UpState(size_t eventArgs);
static void DownState(size_t eventArgs);

static void Raise(unsigned char id, WtButtonType type, unsigned char count)
{
	if (Report)
	{
		Report(id, type, count);
	}
}

static void UpState(size_t eventArgs)
{
	struct Button* curr = Head;
	unsigned char v;
	while (curr)
	{
		if (Read)
		{
			v = Read(curr->Id);
			if (v)
			{
				curr->TimeDown = 0;
				curr->CountDown = 0;
				FsmTiny_SetNew(Fsm, DownState);
			}
			else
			{
				if (curr->CountDown)//如果曾经按下过
				{
					if (curr->TimeUp == 0)
					{
						Raise(curr->Id, WtButtonTypeUp, ++curr->CountUp);
					}
					if (curr->TimeUp++ > curr->Ticks)
					{
						curr->CountUp = 0;
						curr->TimeUp = 0;
						curr->CountDown = 0;
					}
				}
			}
		}
		curr = curr->Next;
	}
}

static void DownState(size_t eventArgs)
{
	struct Button* curr = Head;
	unsigned char v;
	while (curr)
	{
		if (Read)
		{
			v = Read(curr->Id);
			if (v)
			{
				if (curr->TimeDown % curr->Interval == 0)
				{
					Raise(curr->Id, WtButtonTypeDown, ++curr->CountDown);
				}
			}
			else
			{
				curr->TimeUp = 0;
				FsmTiny_SetNew(Fsm, UpState);
			}
		}
		curr = curr->Next;
	}
}


void WtButton_Initialize(WtButtonRead read, WtButtonReport report)
{
	Head = NULL;
	Read = read;
	Report = report;
	Fsm = FsmTiny_Create(UpState, NULL);
}

unsigned char WtButton_Regist(unsigned char id, unsigned char interval, unsigned char ticks)
{
	unsigned char r = 0;
	struct Button* curr;
	if (interval && ticks)
	{
		curr = Head;
		while (curr)
		{
			if (curr->Id == id)
			{
				break;
			}
			curr = curr->Next;
		}
		if (curr)
		{
			curr->Id = id;
			curr->Interval = interval;
			curr->Ticks = ticks;
			r = 1;
		}
		else
		{
			if (curr = calloc(1, sizeof(struct Button)))
			{
				curr->Next = Head;
				curr->Id = id;
				curr->Interval = interval;
				curr->Ticks = ticks;
				Head = curr;
				r = 1;
			}
		}
	}
	return r;
}

void WtButton_Scan(void)//建议扫描频率 100Hz 
{
	//static size_t t = 0;
	FsmTiny_Transit(Fsm,0);
}

void WtButton_Dispose(void)
{
	struct Button* curr = Head, * next;
	while (curr)
	{
		next = curr->Next;
		free(curr);
		curr = next;
	}
	FsmTiny_Dispose(Fsm);
}