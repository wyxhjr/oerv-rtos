#include "sbi.h"
#include "sbi_internal.h"

#define SBI_EMBED __asm__ __volatile__

#define __sbi_param(exten_id, func_id)  SBI_EMBED("add a7, %0, zero"::"r"((exten_id)):"a0","a1","a2","a3","a4","a5");SBI_EMBED("add a6, %0, zero"::"r"((func_id)):"a0","a1","a2","a3","a4","a5");

#define __sbi_param_ret() SBI_EMBED("add %0, a0, zero":"=r"(ret.error)::);SBI_EMBED("add %0, a1, zero":"=r"(ret.value)::);

#define __sbi_call() __asm__ __volatile__("ecall");



sbi_ret_t sbi_get_spec_version()
{
    // 所在扩展              :  BASE 扩展 -> EID_BASE
    // 功能号为              :  0号功能号 -> FID_BASE_GET_SBI_VERSION
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
    // 所在扩展              :  BASE 扩展 -> EID_BASE
    // 功能号为              :  1号功能号 -> FID_BASE_GET_SBI_IMPL_ID
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
    // 所在扩展              :  BASE 扩展 -> EID_BASE
    // 功能号为              :  2号功能号 -> FID_BASE_GET_SBI_IMPL_VER
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
    // 所在扩展              :   BASE 扩展 -> EID_BASE
    // 功能号为              :   3号功能号 -> FID_BASE_PROBE_SBI_EXTEN
    sbi_ret_t ret;
    unsigned long long exten_id;
    unsigned long long func_id;
    exten_id = EID_BASE;
    func_id  = FID_BASE_PROBE_SBI_EXTEN;
    __sbi_param(exten_id,func_id);
    __sbi_call();
    __sbi_param_ret();
    return ret;
}

sbi_ret_t sbi_get_mvendorid()
{
    // 所在扩展              :   BASE 扩展 -> EID_BASE
    // 功能号为              :   4号功能号 -> FID_BASE_GET_MHART_ID
    sbi_ret_t ret;
    unsigned long long exten_id;
    unsigned long long func_id;
    exten_id = EID_BASE;
    func_id  = FID_BASE_GET_MHART_ID;
    __sbi_param(exten_id,func_id);
    __sbi_call();
    __sbi_param_ret();
    return ret;
}




sbi_ret_t sbi_debug_console_write(unsigned long num_bytes,   unsigned long base_addr_lo,   unsigned long base_addr_hi)
{
    // 所在扩展              :   DEBUG 扩展 -> EID_DEBUG
    // 功能号为              :   0号功能号 -> FID_DEBUG_CONSOLE_WRITE
    sbi_ret_t ret;
    unsigned long long exten_id;
    unsigned long long func_id;
    exten_id = EID_DEBUG;
    func_id  = FID_DEBUG_CONSOLE_WRITE;
    __sbi_param(exten_id,func_id);
    __sbi_call();
    __sbi_param_ret();
    return ret;
}


sbi_ret_t sbi_debug_console_read(unsigned long num_bytes,   unsigned long base_addr_lo,   unsigned long base_addr_hi)
{
    // 所在扩展              :   DEBUG 扩展 -> EID_DEBUG
    // 功能号为              :   1号功能号 -> FID_DEBUG_CONSOLE_READ
    sbi_ret_t ret;
    unsigned long long exten_id;
    unsigned long long func_id;
    exten_id = EID_DEBUG;
    func_id  = FID_DEBUG_CONSOLE_READ;
    __sbi_param(exten_id,func_id);
    __sbi_call();
    __sbi_param_ret();
    return ret;
}


sbi_ret_t sbi_debug_console_write_byte(uint8_t byte)
{
    // 所在扩展              :   DEBUG 扩展 -> EID_DEBUG
    // 功能号为              :   2号功能号 -> FID_DEBUG_CONSOLE_WRITE_BYTE
    sbi_ret_t ret;
    unsigned long long exten_id;
    unsigned long long func_id;
    exten_id = EID_DEBUG;
    func_id  = FID_DEBUG_CONSOLE_WRITE_BYTE;
    __sbi_param(exten_id,func_id);
    __sbi_call();
    __sbi_param_ret();
    return ret;
}


sbi_ret_t sbi_system_suspend(uint32_t sleep_type,   unsigned long resume_addr,   unsigned long opaque)
{
    // 所在扩展              :   HANG 扩展 -> EID_HANG
    // 功能号为              :   0号功能号 -> FID_DEBUG_CONSOLE_WRITE_BYTE
    sbi_ret_t ret;
    unsigned long long exten_id;
    unsigned long long func_id;
    exten_id = EID_DEBUG;
    func_id  = FID_HANG_SBI_SYSTEM_SUSPEND;
    __sbi_param(exten_id,func_id);
    __sbi_call();
    __sbi_param_ret();
    return ret;
}



sbi_ret_t sbi_cppc_probe(uint32_t cppc_reg_id)
{
    // 所在扩展              :   CPPC 扩展 -> EID_CPPC
    // 功能号为              :   0号功能号 -> FID_SBI_CPPC_PROBE
    sbi_ret_t ret;
    unsigned long long exten_id;
    unsigned long long func_id;
    exten_id = EID_CPPC;
    func_id  = FID_SBI_CPPC_PROBE;
    __sbi_param(exten_id,func_id);
    __sbi_call();
    __sbi_param_ret();
    return ret;
}



sbi_ret_t sbi_cppc_read(uint32_t cppc_reg_id)
{
    // 所在扩展              :   CPPC 扩展 -> EID_CPPC
    // 功能号为              :   1号功能号 -> FID_SBI_CPPC_READ
    sbi_ret_t ret;
    unsigned long long exten_id;
    unsigned long long func_id;
    exten_id = EID_CPPC;
    func_id  = FID_SBI_CPPC_READ;
    __sbi_param(exten_id,func_id);
    __sbi_call();
    __sbi_param_ret();
    return ret;
}



sbi_ret_t sbi_cppc_read_hi(uint32_t cppc_reg_id)
{
    // 所在扩展              :   CPPC 扩展 -> EID_CPPC
    // 功能号为              :   2号功能号 -> FID_SBI_CPPC_READ_HI
    sbi_ret_t ret;
    unsigned long long exten_id;
    unsigned long long func_id;
    exten_id = EID_CPPC;
    func_id  = FID_SBI_CPPC_READ_HI;
    __sbi_param(exten_id,func_id);
    __sbi_call();
    __sbi_param_ret();
    return ret;
}



sbi_ret_t sbi_cppc_write(uint32_t cppc_reg_id, uint64_t val)
{
    // 所在扩展              :   CPPC 扩展 -> EID_CPPC
    // 功能号为              :   3号功能号 -> FID_SBI_CPPC_WRITE
    sbi_ret_t ret;
    unsigned long long exten_id;
    unsigned long long func_id;
    exten_id = EID_CPPC;
    func_id  = FID_SBI_CPPC_WRITE;
    __sbi_param(exten_id,func_id);
    __sbi_call();
    __sbi_param_ret();
    return ret;
}


sbi_ret_t sbi_nacl_probe_feature(uint32_t feature_id)
{
    // 所在扩展              :   ACCELERATE 扩展 -> EID_ACCELERATE
    // 功能号为              :   0号功能号 -> FID_SBI_NACL_PROBE_FEATURE
    sbi_ret_t ret;
    unsigned long long exten_id;
    unsigned long long func_id;
    exten_id = EID_ACCELERATE;
    func_id  = FID_SBI_NACL_PROBE_FEATURE;
    __sbi_param(exten_id,func_id);
    __sbi_call();
    __sbi_param_ret();
    return ret;
}


sbi_ret_t sbi_nacl_set_shmem(unsigned long shmem_phys_lo,unsigned long shmem_phys_hi,unsigned long flags)
{
    // 所在扩展              :   ACCELERATE 扩展 -> EID_ACCELERATE
    // 功能号为              :   1号功能号 -> FID_SBI_NACL_SET_SHMEM
    sbi_ret_t ret;
    unsigned long long exten_id;
    unsigned long long func_id;
    exten_id = EID_ACCELERATE;
    func_id  = FID_SBI_NACL_SET_SHMEN;
    __sbi_param(exten_id,func_id);
    __sbi_call();
    __sbi_param_ret();
    return ret;
}




sbi_ret_t sbi_nacl_sync_csr(unsigned long csr_num)
{
    // 所在扩展              :   ACCELERATE 扩展 -> EID_ACCELERATE
    // 功能号为              :   2号功能号 -> FID_SBI_NACL_SYNC_CSR
    sbi_ret_t ret;
    unsigned long long exten_id;
    unsigned long long func_id;
    exten_id = EID_ACCELERATE;
    func_id  = FID_SBI_NACL_SYNC_CSR;
    __sbi_param(exten_id,func_id);
    __sbi_call();
    __sbi_param_ret();
    return ret;
}



sbi_ret_t sbi_nacl_sync_hfence(unsigned long entry_index)
{
    // 所在扩展              :   ACCELERATE 扩展 -> EID_ACCELERATE
    // 功能号为              :   3号功能号 -> FID_SBI_NACL_SYNC_HFENCE
    sbi_ret_t ret;
    unsigned long long exten_id;
    unsigned long long func_id;
    exten_id = EID_ACCELERATE;
    func_id  = FID_SBI_NACL_SYNC_HFENCE;
    __sbi_param(exten_id,func_id);
    __sbi_call();
    __sbi_param_ret();
    return ret;
}



sbi_ret_t sbi_nacl_sync_sret(void)
{
    // 所在扩展              :   ACCELERATE 扩展 -> EID_ACCELERATE
    // 功能号为              :   4号功能号 -> FID_SBI_NACL_SYNC_SRET
    sbi_ret_t ret;
    unsigned long long exten_id;
    unsigned long long func_id;
    exten_id = EID_ACCELERATE;
    func_id  = FID_SBI_NACL_SYNC_SRET;
    __sbi_param(exten_id,func_id);
    __sbi_call();
    __sbi_param_ret();
    return ret;
}





sbi_ret_t sbi_steal_time_set_shmem(unsigned long shmem_phys_lo,   unsigned long shmem_phys_hi,   uint32_t flags)
{
    // 所在扩展              :   STEAL_TIME 扩展 -> EID_STEAL_TIME
    // 功能号为              :   0号功能号 -> FID_SBI_STEAL_TIME_SET_SHMEM
    sbi_ret_t ret;
    unsigned long long exten_id;
    unsigned long long func_id;
    exten_id = EID_STEAL_TIME;
    func_id  = FID_SBI_STEAL_TIME_SET_SHMEM;
    __sbi_param(exten_id,func_id);
    __sbi_call();
    __sbi_param_ret();
    return ret;
}












