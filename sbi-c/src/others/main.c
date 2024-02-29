#include "sbi_ext_base.h"

#define OS_STACK_SIZE 4096
#define CPUS          4 
char os_stack[OS_STACK_SIZE][CPUS]__attribute__((aligned(8)));

void main(void)
{
    int hartid = 0;
    __asm__ __volatile__("add %0, tp, zero":"=r"(hartid)::);
    if(hartid == 0)
    {
        sbi_ret_t ret = sbi_get_spec_version();
        ret = sbi_get_impl_id();
        ret = sbi_get_impl_version();
        ret = sbi_probe_extension(EXTENSION_ID_BASE);
        ret = sbi_probe_extension(0x2534);
    }
    sbi_ret_t ret = sbi_get_mvendorid();
    while(1) ;

}