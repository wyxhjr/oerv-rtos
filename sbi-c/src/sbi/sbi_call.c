#include "sbi.h"
#include "sbi_internal.h"

#define SBI_EMBED __asm__ __volatile__

#define __sbi_param(exten_id, func_id)  SBI_EMBED("add a7, %0, zero"::"r"((exten_id)):"a0","a1","a2","a3","a4","a5");SBI_EMBED("add a6, %0, zero"::"r"((func_id)):"a0","a1","a2","a3","a4","a5");

#define __sbi_param_ret() SBI_EMBED("add %0, a0, zero":"=r"(ret.error)::);SBI_EMBED("add %0, a1, zero":"=r"(ret.value)::);

#define __sbi_call() __asm__ __volatile__("ecall");



sbi_ret_t sbi_get_spec_version()
{
    // 获得SPEC功能的扩展     :  BASE 扩展 -> EID_BASE
    // 功能号为              :   0号功能号 -> FID_BASE_GET_SBI_VERSION
    // 根据sbi2.0 手册建议，使用unsigned long long 来存放扩展ID 和功能ID
    sbi_ret_t ret;
    unsigned long long exten_id;
    unsigned long long func_id;
    exten_id = EID_BASE;
    func_id  = FID_BASE_GET_SBI_VERSION;
    __sbi_param(exten_id,func_id);
    __sbi_call();
    __sbi_param_ret();
    return ret;
}

sbi_ret_t sbi_get_impl_id()
{
    // 获得SPEC功能的扩展     :  BASE 扩展 -> EID_BASE
    // 功能号为              :   1号功能号 -> FID_BASE_GET_SBI_IMPL_ID
    sbi_ret_t ret;
    unsigned long long exten_id;
    unsigned long long func_id;
    exten_id = EID_BASE;
    func_id  = FID_BASE_GET_SBI_IMPL_ID;
    __sbi_param(exten_id,func_id);
    __sbi_call();
    __sbi_param_ret();
    return ret;
}

sbi_ret_t sbi_get_impl_version()
{
    // 获得SPEC功能的扩展     :  BASE 扩展 -> EID_BASE
    // 功能号为              :   1号功能号 -> FID_BASE_GET_SBI_IMPL_VER
    sbi_ret_t ret;
    unsigned long long exten_id;
    unsigned long long func_id;
    exten_id = EID_BASE;
    func_id  = FID_BASE_GET_SBI_IMPL_VER;
    __sbi_param(exten_id,func_id);
    __sbi_call();
    __sbi_param_ret();
    return ret;
}

sbi_ret_t sbi_probe_extension(long extension_id)
{
    sbi_ret_t ret;
    unsigned long long exten_id;
    unsigned long long func_id;
    exten_id = EID_BASE;
    func_id  = FID_BASE_GET_SBI_IMPL_VER;
    __sbi_param(exten_id,func_id);
    __sbi_call();
    __sbi_param_ret();
    return ret;
}