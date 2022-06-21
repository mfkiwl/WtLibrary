#include <stdlib.h>
#include "FsmTiny.h"

struct FsmTiny
{
	FsmTinyState Initial;
	FsmTinyState Final;
	FsmTinyState Current;
	FsmTinyState New;
};

void* FsmTiny_Create(FsmTinyState initialState, FsmTinyState finalState)
{
	struct FsmTiny* fsm;
	if (fsm = calloc(1, sizeof(struct FsmTiny)))
	{
		fsm->Initial = fsm->Current = initialState;
		fsm->Final = finalState;
		fsm->New = NULL;
	}
	return fsm;
}

FsmTinyState FsmTiny_GetCurrent(void* fsmTiny)
{
	FsmTinyState r = NULL;
	struct FsmTiny* fsm = fsmTiny;
	if (fsm)
	{
		r = fsm->Current;
	}
	return r;
}

unsigned char FsmTiny_Transit(void* fsmTiny, size_t eventArgs)
{
	unsigned char r = 0;
	struct FsmTiny* fsm = fsmTiny;
	if (fsm)
	{
		if (fsm->Current != fsm->Final)
		{
			if (fsm->Current)
			{
				fsm->Current(eventArgs);
				if (fsm->New)
				{
					fsm->Current = fsm->New;
					fsm->New = NULL;
				}
				r = 1;
			}
		}
	}
	return r;
}

void FsmTiny_SetNew(void* fsmTiny, FsmTinyState newState)
{
	struct FsmTiny* fsm = fsmTiny;
	if (fsm)
	{
		fsm->New = newState;
	}
}

void FsmTiny_Restart(void* fsmTiny)
{
	struct FsmTiny* fsm = fsmTiny;
	if (fsm)
	{
		fsm->Current = fsm->Initial;
	}
}

void FsmTiny_Dispose(void* fsmTiny)
{
	free(fsmTiny);
}