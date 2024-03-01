# OERV_RTOS 入门须知

## 前言

- oerv-rtos 小队的核心宗旨是 : **探索 rv64 rtos 和 多核异构部署，完善 oe嵌入式分支在 riscv 上面的空缺**
- 支持小队成员**围绕小队核心宗旨**的一切有趣的想法，同时小队队长会协助一起挖掘相关的 `easywork` 或 `hardwork` , 协助完成PR的合并。
- 目前小队处于建设初期，队内的规定，入门门槛与入门文档都尚未完善，欢迎提出相关的建议，我们会实际践行并根据效果进行改进。

## 所需技能

- 了解 riscv 汇编 , [了解 riscv 架构 ](#RISCV架构层次)   [注:不用完全了解,知道有这些东西,用到时会查对应手册]。 
- 了解 [RTOS](#RTOS架构层次)， [运行过 UniProton on qemu-riscv](run_uniproton.md)

## 主要工作

- 挖掘 UniProton 中 未进行RISCV64 适配的工作
- 完善 UniProton 的软硬件生态
- 探索 UniProton 和 MCS 项目

- [具体工作内容](issue.md)  

## QA

### RISCV架构层次

- riscv 指令集 -  什么是指令集，了解或者使用过RISCV哪些扩展的指令集
- riscv 寄存器集合 - riscv 有哪些寄存器, 特权寄存器的作用, 普通寄存器在编译器遵从的ABI规范下的作用
- riscv 异常模式 -  是否知道发生中断、异常、陷入时的硬件操作，是否了解相关的特权寄存器
- riscv 内存映射 -  是否了解IO内存映射，是否了解RISCV ARCH 下各IO的物理地址映射要求。
- 其他   [与RTOS开发非强相关 如debug相关 如总线时序相关]

### RTOS架构层次

- rtos arch层  -  实现arch 或者 board 依赖的API，如临界区相关的API
- rtos core层  -  实现基本执行流建模和调度器建模以及基础的IPC，中断管理，异常管理以及提供相应的API
- rtos 组件层  -  基于core核心提供的API开发的各类上层应用组件，如shell , VFS , libc 等