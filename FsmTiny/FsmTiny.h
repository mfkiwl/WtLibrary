/*--------------------------------------------------------------------------
FSMTNY.H
Finite state machine(Mealy) tiny version 1.0 functions for ANSI C.
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
/// 表示状态机的一种状态。如果需切换状态，则必须在状态函数返回之前调用函数 FsmTiny_SetNew 设置新的状态。
/// 注意：只允许在状态函数调用函数 FsmTiny_SetNew 和 FsmTny_GetCurrent；不允许状态函数调用状态函数和下面的函数：
/// FsmTiny_Create，FsmTny_Transit 和 FsmTny_Dispose。
/// </summary>
typedef void (*FsmTinyState)(size_t eventArgs);
/// <summary>
/// 创建一个新的状态机。
/// </summary>
/// <param name="initialState">起始状态。</param>
/// <param name="finalState">最终状态。</param>
/// <returns>返回状态机。如果创建失败，返回 NULL。</returns>
void* FsmTiny_Create(FsmTinyState initialState, FsmTinyState finalState);
/// <summary>
/// 获取状态机的当前状态。
/// </summary>
/// <param name="fsmTiny">状态机。</param>
/// <returns>返回状态机的当前状态。</returns>
FsmTinyState FsmTiny_GetCurrent(void* fsmTiny);
/// <summary>
/// 执行状态转换（在事件发生时调用）。
/// </summary>
/// <param name="fsmTiny">状态机。</param>
/// <param name="eventArgs">事件关联的参数。如果有更多的关联参数，可以使用全局变量进行数据共享。</param>
/// <returns>返回状态转换成功标志。0=失败，1=成功。</returns>
unsigned char FsmTiny_Transit(void* fsmTiny, size_t eventArgs);
/// <summary>
/// 指定状态机的新状态。
/// </summary>
/// <param name="fsmTny">状态机。</param>
/// <param name="state">新状态。如果为 NULL 则无效。</param>
void FsmTiny_SetNew(void* fsmTiny, FsmTinyState newState);
/// <summary>
/// 释放状态机占用的资源。
/// </summary>
/// <param name="fsmTiny">状态机。</param>
void FsmTiny_Dispose(void* fsmTiny);
#endif