/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X
#define CONFIG_MSPM0G3507

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)



#define CPUCLK_FREQ                                                     80000000



/* Defines for PWM_Car */
#define PWM_Car_INST                                                       TIMG0
#define PWM_Car_INST_IRQHandler                                 TIMG0_IRQHandler
#define PWM_Car_INST_INT_IRQN                                   (TIMG0_INT_IRQn)
#define PWM_Car_INST_CLK_FREQ                                           40000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_Car_C0_PORT                                               GPIOA
#define GPIO_PWM_Car_C0_PIN                                       DL_GPIO_PIN_12
#define GPIO_PWM_Car_C0_IOMUX                                    (IOMUX_PINCM34)
#define GPIO_PWM_Car_C0_IOMUX_FUNC                   IOMUX_PINCM34_PF_TIMG0_CCP0
#define GPIO_PWM_Car_C0_IDX                                  DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_Car_C1_PORT                                               GPIOB
#define GPIO_PWM_Car_C1_PIN                                       DL_GPIO_PIN_11
#define GPIO_PWM_Car_C1_IOMUX                                    (IOMUX_PINCM28)
#define GPIO_PWM_Car_C1_IOMUX_FUNC                   IOMUX_PINCM28_PF_TIMG0_CCP1
#define GPIO_PWM_Car_C1_IDX                                  DL_TIMER_CC_1_INDEX

/* Defines for PWM_0 */
#define PWM_0_INST                                                        TIMG12
#define PWM_0_INST_IRQHandler                                  TIMG12_IRQHandler
#define PWM_0_INST_INT_IRQN                                    (TIMG12_INT_IRQn)
#define PWM_0_INST_CLK_FREQ                                             80000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_0_C0_PORT                                                 GPIOB
#define GPIO_PWM_0_C0_PIN                                         DL_GPIO_PIN_13
#define GPIO_PWM_0_C0_IOMUX                                      (IOMUX_PINCM30)
#define GPIO_PWM_0_C0_IOMUX_FUNC                    IOMUX_PINCM30_PF_TIMG12_CCP0
#define GPIO_PWM_0_C0_IDX                                    DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_0_C1_PORT                                                 GPIOB
#define GPIO_PWM_0_C1_PIN                                         DL_GPIO_PIN_24
#define GPIO_PWM_0_C1_IOMUX                                      (IOMUX_PINCM52)
#define GPIO_PWM_0_C1_IOMUX_FUNC                    IOMUX_PINCM52_PF_TIMG12_CCP1
#define GPIO_PWM_0_C1_IDX                                    DL_TIMER_CC_1_INDEX



/* Defines for TIMER_Encoder_Read */
#define TIMER_Encoder_Read_INST                                          (TIMG6)
#define TIMER_Encoder_Read_INST_IRQHandler                        TIMG6_IRQHandler
#define TIMER_Encoder_Read_INST_INT_IRQN                        (TIMG6_INT_IRQn)
#define TIMER_Encoder_Read_INST_LOAD_VALUE                                 (6249U)




/* Defines for ADC1 */
#define ADC1_INST                                                           ADC0
#define ADC1_INST_IRQHandler                                     ADC0_IRQHandler
#define ADC1_INST_INT_IRQN                                       (ADC0_INT_IRQn)
#define ADC1_ADCMEM_ADC_Channel0                              DL_ADC12_MEM_IDX_0
#define ADC1_ADCMEM_ADC_Channel0_REF             DL_ADC12_REFERENCE_VOLTAGE_VDDA
#define ADC1_ADCMEM_ADC_Channel0_REF_VOLTAGE_V                                     3.3
#define GPIO_ADC1_C0_PORT                                                  GPIOA
#define GPIO_ADC1_C0_PIN                                          DL_GPIO_PIN_27



/* Port definition for Pin Group GPIO_LED */
#define GPIO_LED_PORT                                                    (GPIOA)

/* Defines for PIN_led: GPIOA.7 with pinCMx 14 on package pin 49 */
#define GPIO_LED_PIN_led_PIN                                     (DL_GPIO_PIN_7)
#define GPIO_LED_PIN_led_IOMUX                                   (IOMUX_PINCM14)
/* Port definition for Pin Group MODE */
#define MODE_PORT                                                        (GPIOA)

/* Defines for ctrl: GPIOA.25 with pinCMx 55 on package pin 26 */
#define MODE_ctrl_PIN                                           (DL_GPIO_PIN_25)
#define MODE_ctrl_IOMUX                                          (IOMUX_PINCM55)
/* Port definition for Pin Group BEGIN */
#define BEGIN_PORT                                                       (GPIOA)

/* Defines for GO: GPIOA.9 with pinCMx 20 on package pin 55 */
#define BEGIN_GO_PIN                                             (DL_GPIO_PIN_9)
#define BEGIN_GO_IOMUX                                           (IOMUX_PINCM20)
/* Port definition for Pin Group GPIO_STBY */
#define GPIO_STBY_PORT                                                   (GPIOB)

/* Defines for PIN_STBY: GPIOB.9 with pinCMx 26 on package pin 61 */
#define GPIO_STBY_PIN_STBY_PIN                                   (DL_GPIO_PIN_9)
#define GPIO_STBY_PIN_STBY_IOMUX                                 (IOMUX_PINCM26)
/* Port definition for Pin Group Change */
#define Change_PORT                                                      (GPIOB)

/* Defines for all: GPIOB.19 with pinCMx 45 on package pin 16 */
#define Change_all_PIN                                          (DL_GPIO_PIN_19)
#define Change_all_IOMUX                                         (IOMUX_PINCM45)
/* Port definition for Pin Group GPIO_OLED */
#define GPIO_OLED_PORT                                                   (GPIOB)

/* Defines for PIN_SCL: GPIOB.12 with pinCMx 29 on package pin 64 */
#define GPIO_OLED_PIN_SCL_PIN                                   (DL_GPIO_PIN_12)
#define GPIO_OLED_PIN_SCL_IOMUX                                  (IOMUX_PINCM29)
/* Defines for PIN_SDA: GPIOB.4 with pinCMx 17 on package pin 52 */
#define GPIO_OLED_PIN_SDA_PIN                                    (DL_GPIO_PIN_4)
#define GPIO_OLED_PIN_SDA_IOMUX                                  (IOMUX_PINCM17)
/* Port definition for Pin Group GPIO_IN */
#define GPIO_IN_PORT                                                     (GPIOA)

/* Defines for PIN_AIN1: GPIOA.15 with pinCMx 37 on package pin 8 */
#define GPIO_IN_PIN_AIN1_PIN                                    (DL_GPIO_PIN_15)
#define GPIO_IN_PIN_AIN1_IOMUX                                   (IOMUX_PINCM37)
/* Defines for PIN_AIN2: GPIOA.16 with pinCMx 38 on package pin 9 */
#define GPIO_IN_PIN_AIN2_PIN                                    (DL_GPIO_PIN_16)
#define GPIO_IN_PIN_AIN2_IOMUX                                   (IOMUX_PINCM38)
/* Defines for PIN_BIN1: GPIOA.17 with pinCMx 39 on package pin 10 */
#define GPIO_IN_PIN_BIN1_PIN                                    (DL_GPIO_PIN_17)
#define GPIO_IN_PIN_BIN1_IOMUX                                   (IOMUX_PINCM39)
/* Defines for PIN_BIN2: GPIOA.24 with pinCMx 54 on package pin 25 */
#define GPIO_IN_PIN_BIN2_PIN                                    (DL_GPIO_PIN_24)
#define GPIO_IN_PIN_BIN2_IOMUX                                   (IOMUX_PINCM54)
/* Port definition for Pin Group ENCODER */
#define ENCODER_PORT                                                     (GPIOB)

/* Defines for E1A: GPIOB.8 with pinCMx 25 on package pin 60 */
// pins affected by this interrupt request:["E1A","E1B","E2A","E2B"]
#define ENCODER_INT_IRQN                                        (GPIOB_INT_IRQn)
#define ENCODER_INT_IIDX                        (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define ENCODER_E1A_IIDX                                     (DL_GPIO_IIDX_DIO8)
#define ENCODER_E1A_PIN                                          (DL_GPIO_PIN_8)
#define ENCODER_E1A_IOMUX                                        (IOMUX_PINCM25)
/* Defines for E1B: GPIOB.15 with pinCMx 32 on package pin 3 */
#define ENCODER_E1B_IIDX                                    (DL_GPIO_IIDX_DIO15)
#define ENCODER_E1B_PIN                                         (DL_GPIO_PIN_15)
#define ENCODER_E1B_IOMUX                                        (IOMUX_PINCM32)
/* Defines for E2A: GPIOB.17 with pinCMx 43 on package pin 14 */
#define ENCODER_E2A_IIDX                                    (DL_GPIO_IIDX_DIO17)
#define ENCODER_E2A_PIN                                         (DL_GPIO_PIN_17)
#define ENCODER_E2A_IOMUX                                        (IOMUX_PINCM43)
/* Defines for E2B: GPIOB.14 with pinCMx 31 on package pin 2 */
#define ENCODER_E2B_IIDX                                    (DL_GPIO_IIDX_DIO14)
#define ENCODER_E2B_PIN                                         (DL_GPIO_PIN_14)
#define ENCODER_E2B_IOMUX                                        (IOMUX_PINCM31)
/* Port definition for Pin Group PID */
#define PID_PORT                                                         (GPIOA)

/* Defines for KP: GPIOA.8 with pinCMx 19 on package pin 54 */
#define PID_KP_PIN                                               (DL_GPIO_PIN_8)
#define PID_KP_IOMUX                                             (IOMUX_PINCM19)
/* Defines for KI: GPIOA.26 with pinCMx 59 on package pin 30 */
#define PID_KI_PIN                                              (DL_GPIO_PIN_26)
#define PID_KI_IOMUX                                             (IOMUX_PINCM59)
/* Defines for KD: GPIOA.22 with pinCMx 47 on package pin 18 */
#define PID_KD_PIN                                              (DL_GPIO_PIN_22)
#define PID_KD_IOMUX                                             (IOMUX_PINCM47)
/* Port definition for Pin Group Gray_Address */
#define Gray_Address_PORT                                                (GPIOB)

/* Defines for PIN_0: GPIOB.0 with pinCMx 12 on package pin 47 */
#define Gray_Address_PIN_0_PIN                                   (DL_GPIO_PIN_0)
#define Gray_Address_PIN_0_IOMUX                                 (IOMUX_PINCM12)
/* Defines for PIN_1: GPIOB.1 with pinCMx 13 on package pin 48 */
#define Gray_Address_PIN_1_PIN                                   (DL_GPIO_PIN_1)
#define Gray_Address_PIN_1_IOMUX                                 (IOMUX_PINCM13)
/* Defines for PIN_2: GPIOB.2 with pinCMx 15 on package pin 50 */
#define Gray_Address_PIN_2_PIN                                   (DL_GPIO_PIN_2)
#define Gray_Address_PIN_2_IOMUX                                 (IOMUX_PINCM15)

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_Car_init(void);
void SYSCFG_DL_PWM_0_init(void);
void SYSCFG_DL_TIMER_Encoder_Read_init(void);
void SYSCFG_DL_ADC1_init(void);


bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
