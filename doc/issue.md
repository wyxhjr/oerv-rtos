# OERV-RTOS 工作栏

- UniProton  VFS 组件适配验证

  - 工作内容 ： 验证 VFS组件在 riscv64 uniproton的情况，验证完成后要再次验证一下 shell 组件和 musl libc 组件，因为这两个组件会对在开启VFS组件后对其有依赖，必要情况需要移植实现 arch 部分的代码，最好是验证完成后再利用virt 的 blk-virtio 驱动磁盘，使用mkfs.fat 相关的制作一个fat32文件系统，然后再利用VFS挂到某个目录下，看看是怎么个事儿。

  - 负责人     :    无

  - 工作技术栈 :  VFS inode FS  

  - 工作状态 :   【未分配】

  - 工作对应的issue ： 尚未开启



- UniProton  MUSL LIBC 组件适配验证

  - 工作内容 ： 验证MUSL 中各个库函数在 riscv64 uniproton的情况，必要时刻实现 arch 部分的代码 或者 board 部分的代码，验证完成后，添加到 testsuits里面，适配现有的RV64测试案例，跑一下测试案例试一下

  - 负责人     :    无

  - 工作技术栈 :  Musl POSIX接口 ISO C

  - 工作状态 :   【未分配】

  - 工作对应的issue ： 尚未开启
  - 特别说明 ： 【UniProton 并没有使用全部的MUSL LIBC 的库 需要提前在构建系统里面检查使用到哪些库函数，验证对应的函数】



- UniProton  LWIP 组件调研报告

  - 工作内容 ：  lwip 是一个TCP/IP协议栈 软件包，目前需要调研在其他架构下 lwip是如何实现的，是否有架构依赖层，是否有posix依赖层 或者其他库依赖层，或者libc依赖层，列出一个所有其他架构下被patch 替换掉的函数，主要工作在 lwip 部分的patch里面

  - 负责人     :    无

  - 工作技术栈 :  TCP/IP 协议栈 LWIP 

  - 工作状态 :   【未分配】

  - 工作对应的issue ： 尚未开启

  - 特别说明 ： 【目前队内暂无人员对此组件进行调研，所以可能无法评估此问题的难度】



- UniProton  shell 组件适配验证

  - 工作内容 ： 验证 shell 组件在 riscv64 uniproton 的情况，同时适配到qemu-virt板载上面去	

  - 负责人     :    罗君@Jer6y

  - 工作技术栈 :  uniproton shell 组件 

  - 工作状态 :   【进行中】

  - 工作对应的issue ： 尚未开启



- UniProton riscv64 架构适配
  - 工作内容 ： 移植UniProton 到 riscv64架构上 并在 qemu-virt 上运行进行验证
  - 负责人     :    罗君@Jer6y
  - 工作技术栈 ：RTOS  RISCV汇编
  - 工作状态  ： [【已完成 】](https://gitee.com/openeuler/UniProton/pulls/292)
  - 工作对应的issue : [Uniproton RISC-V 64 virt 移植 · Issue #111 · openEuler-RISCV/oerv-team (github.com)](https://github.com/openEuler-RISCV/oerv-team/issues/111)



- UniProton riscv64 S态适配
  - 工作内容 ： 在 riscv64 S态适配UniProton，同时利用opensbi 作为基础固件进行测试
  - 负责人     :    王跃翔@wyxhjr
  - 工作技术栈 :  RTOS RISCV汇编 SBI规范
  - 工作状态 :   【进行中】
  - 工作对应的issue : [MCS混合关键性系统 - riscv64 virt 支持 · Issue #132 · openEuler-RISCV/oerv-team (github.com)](https://github.com/openEuler-RISCV/oerv-team/issues/132)



- MCS  riscv64 架构适配
  - 工作内容 ： 移植MCS项目到 riscv64 架构，同时在qemu-virt 上运行 riscv-linux 与 uniproton 通信进行验证
  - 负责人     :    罗君@Jer6y
  - 工作技术栈 :  SBI规范，RemoteProc 框架， 内核模块编程
  - 工作状态 :   【进行中】
  - 工作对应的issue : [MCS混合关键性系统 - riscv64 virt 支持 · Issue #132 · openEuler-RISCV/oerv-team (github.com)](https://github.com/openEuler-RISCV/oerv-team/issues/132)



- UniProton 构建门禁实现
  - 工作内容 ： 实现UniProton的构建门禁，提供带有环境的DOCKER镜像
  - 负责人     :    罗君@Jer6y
  - 工作技术栈 :  docker应用 uniproton构建系统 
  - 工作状态 :   [【已完成】](https://gitee.com/openeuler/embedded-ci/pulls/47)
  - 工作对应的issue : [Uniproton RISC-V 门禁支持 · Issue #158 · openEuler-RISCV/oerv-team (github.com)](https://github.com/openEuler-RISCV/oerv-team/issues/158)



- UniProton 测试门禁实现
  - 工作内容 ： 提供各个组件的测试案例，添加qemu-system-riscv64的适配，提供带有环境的DOCKER镜像
  - 负责人     :    周锐发@apodxx 和 罗君@Jer6y
  - 工作技术栈 :  uniproton构建系统  uniproton组件
  - 工作状态 :   【进行中】
  - 工作对应的issue : [Uniproton RISC-V 门禁支持 · Issue #158 · openEuler-RISCV/oerv-team (github.com)](https://github.com/openEuler-RISCV/oerv-team/issues/158)



- UniProton CLINT驱动代码适配到中断API框架
  - 工作内容 ： 适配CLINT的驱动到UniProton 的中断API框架
  - 负责人     :    孙博@shafeipaozi
  - 工作技术栈 :  clint硬件驱动 uniproton 中断API框架
  - 工作状态 :   【进行中】
  - 工作对应的issue : [为 Uniproton 适配 RISCV 架构 CLINT 代码到中断 API 框架 · Issue #165 · openEuler-RISCV/oerv-team (github.com)](https://github.com/openEuler-RISCV/oerv-team/issues/165) 



- UniProton 性能测试

  - 工作内容 ： 对比测试UniProton 和 uC-OS3 的实时性能差异，如果存在差异，请调查分析差异原因	

  - 负责人     :    罗君@Jer6y

  - 工作技术栈 :  RTOS实时性能测试 rhealstone 

  - 工作状态 :   [【已完成】](https://github.com/Jer6y/oerv_intern_record/blob/main/UniProton_/_test_.md)

  - 工作对应的issue ： [对比测试 Uniproton - RISC-V 的性能 · Issue #163 · openEuler-RISCV/oerv-team (github.com)](https://github.com/openEuler-RISCV/oerv-team/issues/163)





