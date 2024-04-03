#include "sbi_ext_base.h"
#include "sbi_ext_debug.h"
#include "sbi_ext_hang.h"
#include "sbi_ext_hsm.h"

#define OS_STACK_SIZE 4096
#define CPUS          4 
char os_stack[OS_STACK_SIZE][CPUS]__attribute__((aligned(8)));

void main(void)
{
    int hartid = 0;
    uint8_t byte = 'A';
    __asm__ __volatile__("add %0, tp, zero":"=r"(hartid)::);
    if(hartid == 0)
    {
        sbi_ret_t ret = sbi_get_spec_version();
        ret = sbi_get_impl_id();
        ret = sbi_get_impl_version();
        ret = sbi_probe_extension(EXTENSION_ID_BASE);
        ret = sbi_probe_extension(0x2534);
	ret = sbi_debug_console_write(10, 0x1000, 0x0);
        ret = sbi_debug_console_read(10, 0x1000, 0x0);
        ret = sbi_debug_console_write_byte(byte);
    }
    sbi_ret_t ret = sbi_get_mvendorid();
    ret = sbi_system_suspend(1, 0x2000, 0x0);
    ret = sbi_hart_start(1, 0x1000, 0x0);
    ret = sbi_hart_stop();
    ret = sbi_hart_get_status(1);
    ret = sbi_hart_suspend(1, 0x2000, 0x0);
    while(1) ;

}
