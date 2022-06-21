/*--------------------------------------------------------------------------
FSMTNY.H
Finite state machine(Mealy) tiny version 1.0 functions for ANSI C.
Powered by feallee@hotmail.com at #2022/06/17#.
--------------------------------------------------------------------------*/
#ifndef __FSM_TINY_H_
#define __FSM_TINY_H_
#include <stddef.h>
/// <summary>
/// ״̬���⺯�������򣩰汾�š�
/// </summary>
#define FSMTNY_VERSION	11
/// <summary>
/// ��ʾ״̬����һ��״̬��������л�״̬���������״̬��������֮ǰ���ú��� FsmTiny_SetNew �����µ�״̬��
/// ע�⣺ֻ������״̬�������ú��� FsmTiny_SetNew �� FsmTny_GetCurrent��������״̬��������״̬����������ĺ�����
/// FsmTiny_Create��FsmTny_Transit �� FsmTny_Dispose��
/// </summary>
typedef void (*FsmTinyState)(size_t eventArgs);
/// <summary>
/// ����һ���µ�״̬����
/// </summary>
/// <param name="initialState">��ʼ״̬��</param>
/// <param name="finalState">����״̬��</param>
/// <returns>����״̬�����������ʧ�ܣ����� NULL��</returns>
void* FsmTiny_Create(FsmTinyState initialState, FsmTinyState finalState);
/// <summary>
/// ��ȡ״̬���ĵ�ǰ״̬��
/// </summary>
/// <param name="fsmTiny">״̬����</param>
/// <returns>����״̬���ĵ�ǰ״̬��</returns>
FsmTinyState FsmTiny_GetCurrent(void* fsmTiny);
/// <summary>
/// ִ��״̬ת�������¼�����ʱ���ã���
/// </summary>
/// <param name="fsmTiny">״̬����</param>
/// <param name="eventArgs">�¼������Ĳ���������и���Ĺ�������������ʹ��ȫ�ֱ����������ݹ���</param>
/// <returns>����״̬ת���ɹ���־��0=ʧ�ܣ�1=�ɹ���</returns>
unsigned char FsmTiny_Transit(void* fsmTiny, size_t eventArgs);
/// <summary>
/// ָ��״̬������״̬��
/// </summary>
/// <param name="fsmTny">״̬����</param>
/// <param name="state">��״̬�����Ϊ NULL ����Ч��</param>
void FsmTiny_SetNew(void* fsmTiny, FsmTinyState newState);
/// <summary>
/// �ͷ�״̬��ռ�õ���Դ��
/// </summary>
/// <param name="fsmTiny">״̬����</param>
void FsmTiny_Dispose(void* fsmTiny);
#endif