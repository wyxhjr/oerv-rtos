#ifndef __SBI_EXT_BASE_H
#define __SBI_EXT_BASE_H

//此文件是用户可以调用的API头文件
//包含了基础扩展的SBI调用的C形式的接口
//同时具体定义了对返回值结构体sbi_ret_t 中的value 的解释
//以及一些基础扩展需要传入参数的宏定义解释

#include "sbi.h"


/************************************************************************
 *                          用户调用的接口函数                           *
 ************************************************************************/
//下面是基础模块的sbi调用的c形式

/*********************************************************************
 * function     :   sbi_get_spec_version                             *        
 * description  :   获取sbi版本                                       *       
 * param        :   无                                               *      
 * return       :   sbi_ret_t.error -> 错误码 定义在 sbi.h头文件里面   *
 *                  sbi_ret_t.value -> 对应下列解释                   * 
 *************************解释****************************************
 *          返回值中 sbi_ret_t.value 对应的解释                       *
 *********************************************************************
 *   The minor number of the SBI specification is encoded in the low *
 *   24 bits, with the major number encoded in the next 7 bits.      *
 *   Bit 31 must be 0 and is reserved for future expansion           *
 *********************************************************************/
sbi_ret_t sbi_get_spec_version();


/*******************************************************************
 * function     :   sbi_get_impl_id                                    
 * description  :   获取sbi实现ID                                             
 * param        :   无                                                     
 * return       :   sbi_ret_t.error -> 错误码 定义在 sbi.h头文件里面
 *                  sbi_ret_t.value -> 对应下列的宏定义        
 *******************************************************************/

/*************************宏定义**************************************/
/*          返回值中 sbi_ret_t.value 对应的意义                       */
/*********************************************************************/
#define SBI_IMPL_BBL        0x0 //Berkeley Boot Loader (BBL)
#define SBI_IMPL_OPENSBI    0x1 //OpenSBI
#define SBI_IMPL_XVISOR     0x2 //Xvisor
#define SBI_IMPL_KVM        0x3 //KVM
#define SBI_IMPL_RUSTSBI    0x4 //RustSBI
#define SBI_IMPL_DIOSIX     0x5 //Diosix
#define SBI_IMPL_COFFER     0x6 //Coffer
#define SBI_IMPL_XEN_PRJ    0x7 //Xen Project
#define SBI_IMPL_PHSS       0x8 //PolarFire Hart Software Services
sbi_ret_t sbi_get_impl_id();


/*******************************************************************
 * function     :   sbi_get_impl_version                            *         
 * description  :   获取SBI实现的版本                                *              
 * param        :   无                                              *      
 * return       :   sbi_ret_t.error -> 错误码 定义在 sbi.h头文件里   *
 *                  sbi_ret_t.value -> 对应下列解释                  *
 *************************解释***************************************
 *         返回值中 sbi_ret_t.value 对应的解释                       *
 ********************************************************************
 *  根据对应的SBI实现的固件自己定义，这是给对应实现SBI规范的固件准备的  *
 *  预留位置,用于放置固件自己的版本号                                 *
 ********************************************************************/
sbi_ret_t sbi_get_impl_version();


/*******************************************************************
 * function     :   sbi_probe_extension                            *
 * description  :   查询对应的扩展ID是否可用                         *
 * param        :   exten_id -> 对应的扩展ID号                      *
 * return       :   sbi_ret_t.error -> 错误码 定义在 sbi.h头文件里面 *
 *                  sbi_ret_t.value -> 对应下列解释                 *
 *************************解释***************************************
 *         返回值中 sbi_ret_t.value 对应的解释                       *
 ********************************************************************
 *  0表示不存在                                                      *
 *  1或者其他固件自己实现的值表示存在                                  *
 ********************************************************************/

/*************************宏定义**************************************/
/*          传递参数 exten_id 对应的意义 -> 由于使用会比较频繁         */
/*          现已放置到所有扩展头文件必须包含的公共头文件sbi.h中         */
/*********************************************************************/

sbi_ret_t sbi_probe_extension(long exten_id);


/*******************************************************************
 * function     :   sbi_get_mvendorid                              *
 * description  :   获取对应的硬件机器厂商号                         *
 * param        :   无                                             *
 * return       :   sbi_ret_t.error -> 错误码 定义在 sbi.h头文件里面 *
 *                  sbi_ret_t.value -> 对应下列解释                 *
 *************************解释***************************************
 *         返回值中 sbi_ret_t.value 对应的解释                       *
 ********************************************************************
 *  返回对应机器厂商号                                                *
 *  0当然是合法的，                                                  *
 ********************************************************************/
sbi_ret_t sbi_get_mvendorid();






#endif