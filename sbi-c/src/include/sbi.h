#ifndef __SBI_H
#define __SBI_H

//此文件是各个扩展的头文件共同依赖的头文件
//包括根据sbiv2.0 定义返回值的类型等

/************************************************************************
 *                         返回值规范相关内容                             *
 ************************************************************************/
typedef struct sbi_ret_s {
    long error;
    long value;
} sbi_ret_t;

// sbi_ret_t 返回值中关于 error 错误类型的说明
#define RET_SBI_SUCCESS              0  //sbi call执行成功
#define RET_SBI_FAILED              -1  //sbi call失败
#define RET_SBI_NOT_SUPPORT         -2  //sbi call不支持 [当某个扩展模块EID 或者扩展EID中的功能号FID不支持时候会出现]
#define RET_SBI_INVALID_PARAM       -3  //sbi call无效的参数 (a6 a7)
#define RET_SBI_DENIED              -4  //sbi call拒绝执行对应的功能
#define RET_SBI_INVALID_ADDRESS     -5
#define RET_SBI_ALREADY_AVAILABLE   -6
#define RET_SBI_ALREADY_STARTED     -7
#define RET_SBI_ALREADY_STOPPED     -8
#define RET_SBI_NO_SHMEM            -9

/************************************************************************
 *                         扩展ID对应的宏定义                            *
 ************************************************************************/
// 定义所有扩展对应的值的宏名字 
#define EXTENSION_ID_BASE           0x10
#define EXTENSION_ID_DEBUG          0x4442434E





#endif