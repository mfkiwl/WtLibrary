#include "WtLamp.h"

static WtLampLight Light;
static unsigned char Count;

static unsigned char Level;
static void (*Current)(void);

static void Raise(unsigned char id, unsigned char on)
{
	if (Light)
	{
		Light(id, on);
	}
}

void TurnOn(void)
{

}

void TurnOff(void)
{

}

void TurnFlash(void)
{

}

void TurnLightness(void)
{
	static unsigned char cnts[] ;
	
	
	if (cnt == 0 && Level) { Raise() }//Led on
	if (cnt == Level) { LED_IO_0 = 1; }//Led off
	cnt++;
}

void LedScale_Initialize(WtLampLight light, unsigned char count)
{
	Light = light;
	Count = count;
	Level = 0;
	Current = TurnOn;
}

void LedScale_Change(WtLampMode mode, unsigned char level)
{
	if (mode == WtLampModeOff) { Current = TurnOff; }
	else if (mode == WtLampModeFlash) { Current = TurnFlash; }
	else if (mode == WtLampModeLightness) { Current = TurnLightness; }
	else { Current = TurnOn; }
	Level = level;
}
void LedScale_Dispatch(void)
{
	Current();
}
void LedScale_Dispose(void)
{}








static unsigned char Level;


static void timer_int(void) interrupt TIMER1_VECTOR
{
	static unsigned char cnt = 0;
	if (cnt == 0 && Level) { LED_IO_0 = 0; }//Led on
	if (cnt == Level) { LED_IO_0 = 1; }//Led off
	cnt++;
}

void LedScale_Initialize(unsigned long fosc)
{
	Level = 0;
	Timer1_Stop();
	IOConfig();
	TimerConfig(fosc);
}

void LedScale_Change(unsigned char level)
{
	Level = level;
}

void LedScale_Dispose(void)
{
	Timer1_Stop();
}