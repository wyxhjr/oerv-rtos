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

// 扩展ID
#define EID_BASE                    0x10  //基础扩展
// 扩展内部的功能ID

#define FID_BASE_GET_SBI_VERSION    0x0   //获得SBI版本

#define FID_BASE_GET_SBI_IMPL_ID    0x1   //获得SBI实现ID

#define FID_BASE_GET_SBI_IMPL_VER   0x2   //获得SBI实现版本

#define FID_BASE_PROBE_SBI_EXTEN    0x3   //查询某个EID扩展是否可用


#endif