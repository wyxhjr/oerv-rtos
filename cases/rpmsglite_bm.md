# UniProton Rpmsglite demo 示例

## Baremetal 工程

### BM工程结构

bm工程在 `path2UniProton/demo/riscv64virt/apps/rpmsglite_env_test/baremetal`

```c
|
|-- src 	[源码目录]
|	|-xx.c	[所有bm工程源码]
|	|-xx.h
|	|-...
|-- Makefile [Makefile 文件,管理 src 目录文件,产生的输出到当前 out 目录]
|-- baremetal.ld  [链接脚本, 分配 bm工程的内存布局 ]
```

### BM工程内存布局

```c#
            |_________|
            |_________|0x90221000
        --- |_________|
 shmem-|    |_________| 
        --- |_________| 0x90220000
        --- |_________| 
       |    |_________|
 shmem-|    |_________|
        --- |_________| 0x90200000
            |_________|
            |_________|
            |_________|
        --- |_________|
       |    |_________|
 stack-|    |_________|
       |    |_________|
        --- |_________| 0x82100000
        --- |_________| 
       |    |_________|
  .bss-|    |_________|
 .data-|    |_________|
       |    |_________|
        --- |_________| 0x81000000
        --- |_________|
 .text-|    |_________|
        --- |_________| 0x80000000
```

.text  .data .bss  为 bm 工程内部编译器自行分配

stack  区域是用来做 bm 工程的栈的

 shmem 区域并不属于 bm 工程， 属于 bm和 rtos 工程共享区域，用来做 rtos 与 bm 通信使用

### 基于BM工程源码开发

### 开发要求

- 所在函数： bm_main
- 所在环境： 裸机
- 可使用的api : 
  - uart.h
    - **uart_printf**
    - **uart_putc**
  - shmem_self.h
    - **GET_SHMEM(coreid)**  获得核心号为coreid对应的shmem的数值  
    - **PUSH_SHMEM(x, core)** 向核心号为core的核心所在区域放置对应数值
- 注意事项
  - 除了 ipi 中断，其他中断都被禁止了 [意味着中断只能由ipi 中断产生]
  - 一旦触发 ipi 中断后，会进入 `trap_handler` 函数
  - `trap_handler `函数中必须要使用 clear_soft_pend() 先取消掉一直挂起的pending位
  - 可以选择补充完 /* ret = ipi_handler(vpid); */    这个地方，就是相当于一个ipi中断的处理回调
- 额外说明
  - 还没有直接的 发送 ipi 中断的 api

## RTOS 工程

