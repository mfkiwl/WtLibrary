#ifndef __WT_BUTTON_H_
#define __WT_BUTTON_H_

typedef enum
{
	WtButtonTypeUp,
	WtButtonTypeDown
}WtButtonType;

typedef unsigned char(*WtButtonRead)(unsigned char id);
typedef void (*WtButtonReport)(unsigned char id,WtButtonType type,unsigned char count);

void WtButton_Initialize(WtButtonRead read, WtButtonReport report);
unsigned char WtButton_Regist(unsigned char id,unsigned char interval, unsigned char ticks);
void WtButton_Scan(void);
void WtButton_Dispose(void);

#endif // !__WT_BUTTON_H_
