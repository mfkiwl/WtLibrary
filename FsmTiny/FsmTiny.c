#include <stdlib.h>
#include "FsmTiny.h"

struct FsmTiny
{
	FsmTinyState Current;
};

void* FsmTiny_Start(FsmTinyState initialState)
{
	struct FsmTiny* fsm;
	if (initialState)
	{
		if (fsm = malloc(sizeof(struct FsmTiny)))
		{
			fsm->Current = initialState;
		}
	}
	else
	{
		fsm = NULL;
	}
	return fsm;
}

FsmTinyState FsmTiny_GetCurrent(void* fsmTiny)
{
	FsmTinyState r;
	struct FsmTiny* fsm;
	if (fsm = fsmTiny)
	{
		r = fsm->Current;
	}
	else
	{
		r = NULL;
	}
	return r;
}

unsigned char FsmTiny_Transit(void* fsmTiny, size_t eventType, void* eventArgs)
{
	unsigned char r = 0;
	struct FsmTiny* fsm;
	FsmTinyState state;
	if (fsm = fsmTiny)
	{
		if (state = fsm->Current(eventType, eventArgs))
		{
			fsm->Current = state;
		}
		r = 1;
	}
	return r;
}

void FsmTiny_Stop(void* fsmTiny)
{
	free(fsmTiny);
}