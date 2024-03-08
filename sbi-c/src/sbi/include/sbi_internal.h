#ifndef SBI_INTERNAL_H
#define SBI_INTERNAL_H
// sbi 模块内部的头文件
// 定义 sbi 的一些扩展ID 和对应的功能ID
// 以及模块私有的函数


// 遵从sbi2.0 调用规范的头函数
// 调用传递参数的规范:
// a6 - SBI调用的扩展ID
// a7 - SBI调用扩展中对应的功能ID
// 调用过程的准则:
// 除了对a0 和 a1 作为返回值发生改变外，不会对任何寄存器发生改变
// 调用返回值参数的规范:
// a0 - 返回错误类型 
// a1 - 返回错误值


/************************************************************************
 *                         调用功能规范相关内容                           *
 ************************************************************************/

// 扩展ID 注意，此处的扩展ID和用户使用的扩展ID是一样的，但是在模块内部我们不使用用户的扩展ID宏
#define EID_BASE                   0x10         //基础扩展

#define EID_HSM                    0x48534D     //Hart State Management状态管理扩展

#define EID_DEBUG                  0x4442434E   //调试控制台扩展

#define EID_HANG                   0x53555350   //系统挂起扩展

#define EID_CPPC                   0x43505043   //处理器性能控制扩展

#define EID_ACCELERATE             0x4E41434C   //嵌套加速扩展

#define EID_STEAL_TIME             0x535441     //偷窃时间的核算扩展

// 扩展内部的功能ID
#define FID_HSM_SBI_HART_START            0x0   //启动hart

#define FID_HSM_SBI_HART_STOP             0x1   //停止hart

#define FID_SBI_HART_GET_STATUS           0x2   //获取hart的状态

#define FID_SBI_HART_SUSPEND             0x3   //挂起hart



#define FID_BASE_GET_SBI_VERSION          0x0   //获得SBI版本

#define FID_BASE_GET_SBI_IMPL_ID          0x1   //获得SBI实现ID

#define FID_BASE_GET_SBI_IMPL_VER         0x2   //获得SBI实现版本

#define FID_BASE_PROBE_SBI_EXTEN          0x3   //查询某个EID扩展是否可用

#define FID_BASE_GET_MHART_ID             0x4   //获取machine vendor id 机器厂商



#define FID_DEBUG_CONSOLE_WRITE           0x0   //控制台写入

#define FID_DEBUG_CONSOLE_READ            0x1   //控制台读取

#define FID_DEBUG_CONSOLE_WRITE_BYTE      0x2   //写单个字节到控制台



#define FID_HANG_SBI_SYSTEM_SUSPEND       0x0   //系统挂起



#define FID_SBI_CPPC_PROBE                0x0   //探测CPPC寄存器是否被寄存器实现

#define FID_SBI_CPPC_READ                 0x1   //读取CPPC寄存器，若XLEN为32，返回低32

#define FID_SBI_CPPC_READ_HI              0x2   //读取CPPC寄存器高32，若XLEN为64或更高，返回0

#define FID_SBI_CPPC_WRITE                0x3   //写入CPPC寄存器



#define FID_SBI_NACL_PROBE_FEATURE        0x0   //探测SBI嵌套加速扩展特性

#define FID_SBI_NACL_SET_SHMEN            0x1   //在调用hart上设置嵌套加速的共享内存

#define FID_SBI_NACL_SYNC_CSR             0x2   //在嵌套加速共享内存中同步CSR

#define FID_SBI_NACL_SYNC_HFENCE          0x3   //在嵌套加速共享内存中同步HFENCE指令

#define FID_SBI_NACL_SYNC_SRET                 0x4   //在嵌套加速共享内存中同步CSR寄存器和HFENCE指令，并模拟SRET指令



#define FID_SBI_STEAL_TIME_SET_SHMEM      0x0   //设置用于调用虚拟HART的窃取时间核算，并启用窃取时间信息报告的共享内存物理基址



#endif
