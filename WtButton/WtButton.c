#include <stddef.h>
#include 
#include "WtButton.h"

static struct Button
{
	unsigned char Id;
	unsigned char State;//0=抬起状态（默认），1=按下状态	
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

static void Raise(unsigned char id, WtButtonType type, unsigned char count)
{
	if (Report)
	{
		Report(id, type, count);
	}
}

void WtButton_Initialize(WtButtonRead read, WtButtonReport report)
{
	Head = NULL;
	Read = read;
	Report = report;
}

unsigned char WtButton_Regist(unsigned char id, unsigned char interval, unsigned char ticks)
{
	unsigned char r = 1;
	struct Button* curr = Head;
	while (curr)
	{
		if (curr->Id == id)
		{
			r = 0;
			break;
		}
		curr = curr->Next;
	}
	if (r)
	{
		if (curr = calloc(1, sizeof(struct Button)))
		{
			curr->Next = Head;
			curr->Id = id;
			curr->Interval = interval;
			curr->Ticks = ticks;
			Head = curr;
		}
		else
		{
			r = 0;
		}
	}
	return r;
}

void WtButton_Scan(void)
{
	struct Button* curr = Head;
	unsigned char v;
	while (curr)
	{
		if (Read)
		{
			v = Read(curr->Id);
			if (curr->State == 0)
			{
				if (v)
				{
					curr->TimeDown = 0;
					curr->CountDown = 0;
					curr->State = 1;					
				}
				else
				{
					curr->TimeDown = 0;
					curr->CountDown = 0;
					if(curr->CountUp)
				}
			}
			else if (curr->State == 1)
			{
				if (v)
				{
					if (curr->TimeDown++ % curr->Interval == 0)
					{						
						Raise(curr->Id,WtButtonTypeDown,++curr->CountDown);
					}
				}
				else
				{	
					curr->State = 0;
				}

			}
		}
		curr = curr->Next;
	}
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
}