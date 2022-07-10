/*--------------------------------------------------------------------------
FSMTINY.H
Finite state machine(Mealy) tiny version 1.1 functions for ANSI C.
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
/// ��ʾ״̬����״̬��
/// ע�⣺��ֹ��״̬�е��ú��� FsmTiny_Start �� FsmTiny_Transit���������ֲ���Ԥ�ϵ��쳣��
/// </summary>
/// <param name="eventType">״̬�������¼����͡�</param>
/// <param name="eventArgs">״̬�������¼�������</param>
/// <returns>�����µ�״̬��״̬�����л����µ�״̬��������� NULL ״̬�������ڵ�ǰ״̬��</returns>
typedef void* (*FsmTinyState)(size_t eventType, void* eventArgs);
/// <summary>
/// ����һ���µ�״̬����������ʵ����
/// </summary>
/// <param name="initialState">��ʼ״̬��������Ϊ NULL��</param>
/// <returns>����״̬��ʵ�����������ʧ�ܣ����� NULL��</returns>
void* FsmTiny_Start(FsmTinyState initialState);
/// <summary>
/// ��ȡ״̬��ʵ���ĵ�ǰ״̬��
/// </summary>
/// <param name="fsmTiny">״̬��ʵ����</param>
/// <returns>����״̬��ʵ���ĵ�ǰ״̬�����״̬��Ϊ NULL������ NULL��</returns>
FsmTinyState FsmTiny_GetCurrent(void* fsmTiny);
/// <summary>
/// ִ��״̬ת�������¼�����ʱ���ã���
/// </summary>
/// <param name="fsmTiny">״̬��ʵ����</param>
/// <param name="eventType">״̬�������¼����͡�</param>
/// <param name="eventArgs">״̬�������¼�������</param>
/// <returns>����״̬ת���ɹ���־��0=ʧ�ܣ�״̬��ʵ��Ϊ NULL����1=�ɹ���</returns>
unsigned char FsmTiny_Transit(void* fsmTiny, size_t eventType, void* eventArgs);
/// <summary>
/// �ͷ�״̬��ʵ��ռ�õ���Դ��
/// </summary>
/// <param name="fsmTiny">״̬��ʵ����</param>
void FsmTiny_Stop(void* fsmTiny);
#endif