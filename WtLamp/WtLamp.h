#ifndef __WT_LAMP_H_
#define __WT_LAMP_H_

typedef enum
{
	WtLampModeOff,
	WtLampModeOn,
	WtLampModeFlash,
	WtLampModeLightness
}WtLampMode;

typedef void(*WtLampLight)(unsigned char id,unsigned char on);
void WtLamp_Initialize(WtLampLight light);
unsigned char WtLamp_Regist(unsigned char id, WtLampMode mode, unsigned char level);
void WtLamp_Dispatch(void);
void WtLamp_Dispose(void);
#endif