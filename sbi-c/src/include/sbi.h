#ifndef __SBI_H
#define __SBI_H
//此文件是用户可以调用的接口API

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
 *                         调用功能规范相关内容                           *
 ************************************************************************/

#define EXTENSION_ID_BASE           0x1




/************************************************************************
 *                          用户调用的接口函数                           *
 ************************************************************************/

//下面就是各个sbi_call
sbi_ret_t sbi_get_spec_version();

sbi_ret_t sbi_get_impl_id();

sbi_ret_t sbi_get_impl_version();

sbi_ret_t sbi_probe_extension(long exten_id);




#endif