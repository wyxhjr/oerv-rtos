.align 4
.section .text
.global _start
.extern os_stack
_start:
    # a0  s mode hart id
    # a1  device tree address
    la   sp,os_stack
    add  t0, zero, a0
    add  tp,t0,zero
    li   t1,1
    add  t0,t0,t1
    li   t1,4096
    mul  t0,t0,t1
    add sp,sp,t0
    j main
_err:
    wfi
    j _err
    