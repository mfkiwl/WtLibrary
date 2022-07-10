/*--------------------------------------------------------------------------
FSMTINY.H
Finite state machine(Mealy) tiny version 1.1 functions for ANSI C.
Powered by feallee@hotmail.com at #2022/06/17#.
--------------------------------------------------------------------------*/
#ifndef __FSM_TINY_H_
#define __FSM_TINY_H_
#include <stddef.h>
/// <summary>
/// 状态机库函数（精简）版本号。
/// </summary>
#define FSMTNY_VERSION	11
/// <summary>
/// 表示状态机的状态。
/// 注意：禁止在状态中调用函数 FsmTiny_Start 和 FsmTiny_Transit，否则会出现不可预料的异常。
/// </summary>
/// <param name="eventType">状态关联的事件类型。</param>
/// <param name="eventArgs">状态关联的事件参数。</param>
/// <returns>返回新的状态，状态机会切换到新的状态。如果返回 NULL 状态机保持在当前状态。</returns>
typedef void* (*FsmTinyState)(size_t eventType, void* eventArgs);
/// <summary>
/// 启动一个新的状态机并返回其实例。
/// </summary>
/// <param name="initialState">起始状态。不允许为 NULL。</param>
/// <returns>返回状态机实例。如果启动失败，返回 NULL。</returns>
void* FsmTiny_Start(FsmTinyState initialState);
/// <summary>
/// 获取状态机实例的当前状态。
/// </summary>
/// <param name="fsmTiny">状态机实例。</param>
/// <returns>返回状态机实例的当前状态。如果状态机为 NULL，返回 NULL。</returns>
FsmTinyState FsmTiny_GetCurrent(void* fsmTiny);
/// <summary>
/// 执行状态转换（在事件发生时调用）。
/// </summary>
/// <param name="fsmTiny">状态机实例。</param>
/// <param name="eventType">状态关联的事件类型。</param>
/// <param name="eventArgs">状态关联的事件参数。</param>
/// <returns>返回状态转换成功标志。0=失败（状态机实例为 NULL），1=成功。</returns>
unsigned char FsmTiny_Transit(void* fsmTiny, size_t eventType, void* eventArgs);
/// <summary>
/// 释放状态机实例占用的资源。
/// </summary>
/// <param name="fsmTiny">状态机实例。</param>
void FsmTiny_Stop(void* fsmTiny);
#endif