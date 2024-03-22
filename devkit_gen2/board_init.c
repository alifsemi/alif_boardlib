/* Copyright (C) 2022-2024 Alif Semiconductor - All Rights Reserved.
 * Use, distribution and modification of this code is permitted under the
 * terms stated in the Alif Semiconductor Software License Agreement
 *
 * You should have received a copy of the Alif Semiconductor Software
 * License Agreement with this file. If not, please write to:
 * contact@alifsemi.com, or visit: https://alifsemi.com/license
 *
 */

/******************************************************************************
 * @file     board_DevKit.c
 * @brief    BOARD API implementation for Alif Development Kit (Rev. A and B)
 ******************************************************************************/

#include "board.h"

#if defined(BOARD_IS_ALIF_DEVKIT_B0_VARIANT)
#include "app_map.h"
#include "global_map.h"
#include "Driver_GPIO.h"
#include "pinconf.h"

#ifndef PORT_
#define _PORT_(n)  PORT_##n
#define  PORT_(n) _PORT_(n)
#endif

extern ARM_DRIVER_GPIO ARM_Driver_GPIO_(BOARD_BUTTON1_GPIO_PORT);
extern ARM_DRIVER_GPIO ARM_Driver_GPIO_(BOARD_BUTTON2_GPIO_PORT);
extern ARM_DRIVER_GPIO ARM_Driver_GPIO_(BOARD_LED1_GPIO_PORT);
extern ARM_DRIVER_GPIO ARM_Driver_GPIO_(BOARD_LED2_GPIO_PORT);

void BOARD_Pinmux_Init()
{
	extern ARM_DRIVER_GPIO ARM_Driver_GPIO_(BOARD_LCD_RESET_GPIO_PORT);
	extern ARM_DRIVER_GPIO ARM_Driver_GPIO_(BOARD_LCD_BACKLIGHT_GPIO_PORT);
	extern ARM_DRIVER_GPIO ARM_Driver_GPIO_(BOARD_TOUCH_RESET_GPIO_PORT);
	extern ARM_DRIVER_GPIO ARM_Driver_GPIO_(BOARD_TOUCH_INT_GPIO_PORT);
	extern ARM_DRIVER_GPIO ARM_Driver_GPIO_(BOARD_CAMERA_POWER_GPIO_PORT);
	extern ARM_DRIVER_GPIO ARM_Driver_GPIO_(BOARD_CAMERA_RESET_GPIO_PORT);

	ARM_DRIVER_GPIO *BOARD_BUTTON1_GPIOdrv = &ARM_Driver_GPIO_(BOARD_BUTTON1_GPIO_PORT);
	ARM_DRIVER_GPIO *BOARD_BUTTON2_GPIOdrv = &ARM_Driver_GPIO_(BOARD_BUTTON2_GPIO_PORT);
	ARM_DRIVER_GPIO *BOARD_LED1_GPIOdrv = &ARM_Driver_GPIO_(BOARD_LED1_GPIO_PORT);
	ARM_DRIVER_GPIO *BOARD_LED2_GPIOdrv = &ARM_Driver_GPIO_(BOARD_LED2_GPIO_PORT);
	ARM_DRIVER_GPIO *BOARD_LCD_RESET_GPIOdrv = &ARM_Driver_GPIO_(BOARD_LCD_RESET_GPIO_PORT);
	ARM_DRIVER_GPIO *BOARD_LCD_BACKLIGHT_GPIOdrv = &ARM_Driver_GPIO_(BOARD_LCD_BACKLIGHT_GPIO_PORT);
	ARM_DRIVER_GPIO *BOARD_TOUCH_RESET_GPIOdrv = &ARM_Driver_GPIO_(BOARD_TOUCH_RESET_GPIO_PORT);
	ARM_DRIVER_GPIO *BOARD_TOUCH_INT_GPIOdrv = &ARM_Driver_GPIO_(BOARD_TOUCH_INT_GPIO_PORT);
	ARM_DRIVER_GPIO *BOARD_CAMERA_POWER_GPIOdrv = &ARM_Driver_GPIO_(BOARD_CAMERA_POWER_GPIO_PORT);
	ARM_DRIVER_GPIO *BOARD_CAMERA_RESET_GPIOdrv = &ARM_Driver_GPIO_(BOARD_CAMERA_RESET_GPIO_PORT);

	uint32_t config_input =
			PADCTRL_READ_ENABLE |
			PADCTRL_SCHMITT_TRIGGER_ENABLE;

	uint32_t config_i2c =
			PADCTRL_READ_ENABLE |
			PADCTRL_DRIVER_DISABLED_HIGH_Z;

	uint32_t config_i3c =
			PADCTRL_READ_ENABLE |
			PADCTRL_SCHMITT_TRIGGER_ENABLE |
			PADCTRL_DRIVER_DISABLED_PULL_UP;

	uint32_t config_uart_rx =
			PADCTRL_READ_ENABLE |
			PADCTRL_SCHMITT_TRIGGER_ENABLE |
			PADCTRL_DRIVER_DISABLED_PULL_UP;

	uint32_t config_button =
			PADCTRL_READ_ENABLE |
			PADCTRL_SCHMITT_TRIGGER_ENABLE |
			PADCTRL_DRIVER_DISABLED_PULL_UP;

	uint32_t config_gpio =
			PADCTRL_READ_ENABLE |
			PADCTRL_SCHMITT_TRIGGER_ENABLE |
			PADCTRL_OUTPUT_DRIVE_STRENGTH_4MA;

	uint32_t config_can_rx =
			PADCTRL_READ_ENABLE |
			PADCTRL_SCHMITT_TRIGGER_ENABLE;

	uint32_t config_can_tx =
			PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA |
			PADCTRL_SCHMITT_TRIGGER_ENABLE;

	/* GPIO interfaces - initial GPIO state is lowest power */

	BOARD_BUTTON1_GPIOdrv->Initialize(BOARD_BUTTON1_PIN_NO, NULL);
	BOARD_BUTTON1_GPIOdrv->PowerControl(BOARD_BUTTON1_PIN_NO, ARM_POWER_FULL);
	BOARD_BUTTON1_GPIOdrv->SetDirection(BOARD_BUTTON1_PIN_NO, GPIO_PIN_DIRECTION_INPUT);
	pinconf_set(PORT_(BOARD_BUTTON1_GPIO_PORT), BOARD_BUTTON1_PIN_NO, PINMUX_ALTERNATE_FUNCTION_0, config_button);

	BOARD_BUTTON2_GPIOdrv->Initialize(BOARD_BUTTON2_PIN_NO, NULL);
	BOARD_BUTTON2_GPIOdrv->PowerControl(BOARD_BUTTON2_PIN_NO, ARM_POWER_FULL);
	BOARD_BUTTON2_GPIOdrv->SetDirection(BOARD_BUTTON2_PIN_NO, GPIO_PIN_DIRECTION_INPUT);
	pinconf_set(PORT_(BOARD_BUTTON2_GPIO_PORT), BOARD_BUTTON2_PIN_NO, PINMUX_ALTERNATE_FUNCTION_0, config_button);

	BOARD_LED1_GPIOdrv->Initialize(BOARD_LED1_PIN_NO, NULL);
	BOARD_LED1_GPIOdrv->PowerControl(BOARD_LED1_PIN_NO, ARM_POWER_FULL);
	BOARD_LED1_GPIOdrv->SetValue(BOARD_LED1_PIN_NO, GPIO_PIN_OUTPUT_STATE_LOW);
	BOARD_LED1_GPIOdrv->SetDirection(BOARD_LED1_PIN_NO, GPIO_PIN_DIRECTION_OUTPUT);
	pinconf_set(PORT_(BOARD_LED1_GPIO_PORT), BOARD_LED1_PIN_NO, PINMUX_ALTERNATE_FUNCTION_0, config_gpio);

	BOARD_LED2_GPIOdrv->Initialize(BOARD_LED2_PIN_NO, NULL);
	BOARD_LED2_GPIOdrv->PowerControl(BOARD_LED2_PIN_NO, ARM_POWER_FULL);
	BOARD_LED2_GPIOdrv->SetValue(BOARD_LED2_PIN_NO, GPIO_PIN_OUTPUT_STATE_LOW);
	BOARD_LED2_GPIOdrv->SetDirection(BOARD_LED2_PIN_NO, GPIO_PIN_DIRECTION_OUTPUT);
	pinconf_set(PORT_(BOARD_LED2_GPIO_PORT), BOARD_LED2_PIN_NO, PINMUX_ALTERNATE_FUNCTION_0, config_gpio);

	BOARD_LCD_RESET_GPIOdrv->Initialize(BOARD_LCD_RESET_PIN_NO, NULL);
	BOARD_LCD_RESET_GPIOdrv->PowerControl(BOARD_LCD_RESET_PIN_NO, ARM_POWER_FULL);
	BOARD_LCD_RESET_GPIOdrv->SetValue(BOARD_LCD_RESET_PIN_NO, GPIO_PIN_OUTPUT_STATE_LOW);
	BOARD_LCD_RESET_GPIOdrv->SetDirection(BOARD_LCD_RESET_PIN_NO, GPIO_PIN_DIRECTION_OUTPUT);
	pinconf_set(PORT_(BOARD_LCD_RESET_GPIO_PORT), BOARD_LCD_RESET_PIN_NO, PINMUX_ALTERNATE_FUNCTION_0, config_gpio);

	BOARD_LCD_BACKLIGHT_GPIOdrv->Initialize(BOARD_LCD_BACKLIGHT_PIN_NO, NULL);
	BOARD_LCD_BACKLIGHT_GPIOdrv->PowerControl(BOARD_LCD_BACKLIGHT_PIN_NO, ARM_POWER_FULL);
	BOARD_LCD_BACKLIGHT_GPIOdrv->SetValue(BOARD_LCD_BACKLIGHT_PIN_NO, GPIO_PIN_OUTPUT_STATE_LOW);
	BOARD_LCD_BACKLIGHT_GPIOdrv->SetDirection(BOARD_LCD_BACKLIGHT_PIN_NO, GPIO_PIN_DIRECTION_OUTPUT);
	pinconf_set(PORT_(BOARD_LCD_BACKLIGHT_GPIO_PORT), BOARD_LCD_BACKLIGHT_PIN_NO, PINMUX_ALTERNATE_FUNCTION_0, config_gpio);

	BOARD_TOUCH_RESET_GPIOdrv->Initialize(BOARD_TOUCH_RESET_PIN_NO, NULL);
	BOARD_TOUCH_RESET_GPIOdrv->PowerControl(BOARD_TOUCH_RESET_PIN_NO, ARM_POWER_FULL);
	BOARD_TOUCH_RESET_GPIOdrv->SetValue(BOARD_TOUCH_RESET_PIN_NO, GPIO_PIN_OUTPUT_STATE_LOW);
	BOARD_TOUCH_RESET_GPIOdrv->SetDirection(BOARD_TOUCH_RESET_PIN_NO, GPIO_PIN_DIRECTION_OUTPUT);
	pinconf_set(PORT_(BOARD_TOUCH_RESET_GPIO_PORT), BOARD_TOUCH_RESET_PIN_NO, PINMUX_ALTERNATE_FUNCTION_0, config_gpio);

	BOARD_TOUCH_INT_GPIOdrv->Initialize(BOARD_TOUCH_INT_PIN_NO, NULL);
	BOARD_TOUCH_INT_GPIOdrv->PowerControl(BOARD_TOUCH_INT_PIN_NO, ARM_POWER_FULL);
	BOARD_TOUCH_INT_GPIOdrv->SetValue(BOARD_TOUCH_INT_PIN_NO, GPIO_PIN_OUTPUT_STATE_LOW);
	BOARD_TOUCH_INT_GPIOdrv->SetDirection(BOARD_TOUCH_INT_PIN_NO, GPIO_PIN_DIRECTION_OUTPUT);
	pinconf_set(PORT_(BOARD_TOUCH_INT_GPIO_PORT), BOARD_TOUCH_INT_PIN_NO, PINMUX_ALTERNATE_FUNCTION_0, config_gpio);

	BOARD_CAMERA_POWER_GPIOdrv->Initialize(BOARD_CAMERA_POWER_PIN_NO, NULL);
	BOARD_CAMERA_POWER_GPIOdrv->PowerControl(BOARD_CAMERA_POWER_PIN_NO, ARM_POWER_FULL);
	BOARD_CAMERA_POWER_GPIOdrv->SetValue(BOARD_CAMERA_POWER_PIN_NO, GPIO_PIN_OUTPUT_STATE_LOW);
	BOARD_CAMERA_POWER_GPIOdrv->SetDirection(BOARD_CAMERA_POWER_PIN_NO, GPIO_PIN_DIRECTION_OUTPUT);
	pinconf_set(PORT_(BOARD_CAMERA_POWER_GPIO_PORT), BOARD_CAMERA_POWER_PIN_NO, PINMUX_ALTERNATE_FUNCTION_0, config_gpio);

	BOARD_CAMERA_RESET_GPIOdrv->Initialize(BOARD_CAMERA_RESET_PIN_NO, NULL);
	BOARD_CAMERA_RESET_GPIOdrv->PowerControl(BOARD_CAMERA_RESET_PIN_NO, ARM_POWER_FULL);
	BOARD_CAMERA_RESET_GPIOdrv->SetValue(BOARD_CAMERA_RESET_PIN_NO, GPIO_PIN_OUTPUT_STATE_LOW);
	BOARD_CAMERA_RESET_GPIOdrv->SetDirection(BOARD_CAMERA_RESET_PIN_NO, GPIO_PIN_DIRECTION_OUTPUT);
	pinconf_set(PORT_(BOARD_CAMERA_RESET_GPIO_PORT), BOARD_CAMERA_RESET_PIN_NO, PINMUX_ALTERNATE_FUNCTION_0, config_gpio);

    /* OSPI1 interface (Flash) */
	pinconf_set(PORT_9,  PIN_5, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA | PADCTRL_SLEW_RATE_FAST | PADCTRL_READ_ENABLE);    // D0
	pinconf_set(PORT_9,  PIN_6, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA | PADCTRL_SLEW_RATE_FAST | PADCTRL_READ_ENABLE);    // D1
	pinconf_set(PORT_9,  PIN_7, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA | PADCTRL_SLEW_RATE_FAST | PADCTRL_READ_ENABLE);    // D2
	pinconf_set(PORT_10, PIN_0, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA | PADCTRL_SLEW_RATE_FAST | PADCTRL_READ_ENABLE);    // D3
	pinconf_set(PORT_10, PIN_1, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA | PADCTRL_SLEW_RATE_FAST | PADCTRL_READ_ENABLE);    // D4
	pinconf_set(PORT_10, PIN_2, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA | PADCTRL_SLEW_RATE_FAST | PADCTRL_READ_ENABLE);    // D5
	pinconf_set(PORT_10, PIN_3, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA | PADCTRL_SLEW_RATE_FAST | PADCTRL_READ_ENABLE);    // D6
	pinconf_set(PORT_10, PIN_4, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA | PADCTRL_SLEW_RATE_FAST | PADCTRL_READ_ENABLE);    // D7
	pinconf_set(PORT_5,  PIN_5, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA | PADCTRL_SLEW_RATE_FAST);    // SCLK
	pinconf_set(PORT_8,  PIN_0, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA | PADCTRL_SLEW_RATE_FAST);    // SCLKN
	pinconf_set(PORT_5,  PIN_7, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA | PADCTRL_SLEW_RATE_FAST);    // SS0
	pinconf_set(PORT_10, PIN_7, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA | PADCTRL_SLEW_RATE_FAST | PADCTRL_READ_ENABLE);    // RXDS
	// Ensemble B1 workaround - function of P10_7 is controlled by function of P5_6. Fixed in B2
	pinconf_set(PORT_5,  PIN_6, PINMUX_ALTERNATE_FUNCTION_1, PADCTRL_OUTPUT_DRIVE_STRENGTH_12MA | PADCTRL_SLEW_RATE_FAST | PADCTRL_READ_ENABLE);    // RXDS
	pinconf_set(PORT_LP, PIN_7, PINMUX_ALTERNATE_FUNCTION_0, 0);    // RESET

	/* UART2 interface */
	pinconf_set(PORT_1, PIN_0, PINMUX_ALTERNATE_FUNCTION_1, config_uart_rx);	// P1_0: RX  (mux mode 1)
	pinconf_set(PORT_1, PIN_1, PINMUX_ALTERNATE_FUNCTION_1, 0);					// P1_1: TX  (mux mode 1)

    /* I2C0 interface */
    pinconf_set(PORT_3, PIN_4, PINMUX_ALTERNATE_FUNCTION_5, config_i2c);		// P3_4: SCL (mux mode 5)
    pinconf_set(PORT_3, PIN_5, PINMUX_ALTERNATE_FUNCTION_5, config_i2c);		// P3_5: SDA (mux mode 5)

    /* PDM2 interface */
    pinconf_set(PORT_5, PIN_4, PINMUX_ALTERNATE_FUNCTION_3, config_input);		// P5_4: D2 (mux mode 3)
    pinconf_set(PORT_6, PIN_7, PINMUX_ALTERNATE_FUNCTION_3, 0);          		// P6_7: C2 (mux mode 3)

    /* I2C1 interface (camera, touch) */
    pinconf_set(PORT_7, PIN_2, PINMUX_ALTERNATE_FUNCTION_5, config_i2c);		// P7_2: SDA (mux mode 5)
    pinconf_set(PORT_7, PIN_3, PINMUX_ALTERNATE_FUNCTION_5, config_i2c);		// P7_3: SCL (mux mode 5)

	/* I3C interface (gyro) */
	pinconf_set(PORT_7, PIN_6, PINMUX_ALTERNATE_FUNCTION_6, config_i3c);		// P7_6: SDA (mux mode 6)
	pinconf_set(PORT_7, PIN_7, PINMUX_ALTERNATE_FUNCTION_6, config_i3c);		// P7_7: SCL (mux mode 6)

    /* I2S3 interface */
    pinconf_set(PORT_8, PIN_6, PINMUX_ALTERNATE_FUNCTION_2, config_input);		// P8_6: SCLK(mux mode 2)
    pinconf_set(PORT_8, PIN_7, PINMUX_ALTERNATE_FUNCTION_2, config_input);		// P8_7: WS  (mux mode 2)
    pinconf_set(PORT_9, PIN_0, PINMUX_ALTERNATE_FUNCTION_2, config_input);		// P9_0: SDI (mux mode 2)

	/* CAMERA clock output */
	pinconf_set(PORT_0,  PIN_3, PINMUX_ALTERNATE_FUNCTION_6, 0);   				// P0_3: CAM_XVCLK (mux mode 6)

    /* UART3 interface */
	pinconf_set(PORT_1,  PIN_2, PINMUX_ALTERNATE_FUNCTION_1, config_uart_rx);   // P1_2: RX  (mux mode 1)
	pinconf_set(PORT_1,  PIN_3, PINMUX_ALTERNATE_FUNCTION_1, 0);                // P1_3: TX  (mux mode 1)

	/* UART4 interface */
	pinconf_set(PORT_12, PIN_1, PINMUX_ALTERNATE_FUNCTION_2, config_uart_rx);	// P12_1: RX  (mux mode 2)
	pinconf_set(PORT_12, PIN_2, PINMUX_ALTERNATE_FUNCTION_2, 0);				// P12_2: TX  (mux mode 2)

    /* UART6 interface */
    pinconf_set(PORT_14, PIN_0, PINMUX_ALTERNATE_FUNCTION_2, config_uart_rx);   // P14_0: RX  (mux mode 2)
    pinconf_set(PORT_14, PIN_1, PINMUX_ALTERNATE_FUNCTION_2, 0);                // P14_1: TX  (mux mode 2)

	/* CANFD interface */
	pinconf_set(PORT_0, PIN_4, PINMUX_ALTERNATE_FUNCTION_6, config_can_rx);     // P0_4: CAN_RX (mux mode 6)
	pinconf_set(PORT_0, PIN_5, PINMUX_ALTERNATE_FUNCTION_6, config_can_tx);     // P0_5: CAN_TX (mux mode 6)
}

void BOARD_Clock_Init()
{
	/* Configure any SoC clock muxes and dividers
	 * if not already covered in driver code
	 */

	/* CFGPER0 Registers */
	/* CFGPER0_BASE
	 * ipclk_force[31] set to 1 to force peripheral clocks on
	 * pclk_force[30] set to 1 to force interface clocks (PCLK) on
	 */
  //HW_REG32(CFGPER0_BASE, 0) = (1U << 31) | (1U << 30);

    /* Camera pixel clock (XVCLK) control
     * camera_pixclk_ctrl.divider[24:16] up to 0x1FF
     * camera_pixclk_ctrl.select[4] 0: 400 or 1: 480
     * camera_pixclk_ctrl.enable[0]
     */
  //HW_REG32(CAMERA_PIXCLK_CTRL, 0) = (32U << 16) | (0U << 4) | 1U;

    /* CGU Registers */
    /* OSC Control Register
     * sys_xtal_sel[0] 0: 76P8 HFRC, 1: 38P4 HFXO
     * SYS_REFCLK, SYSPLL, CPUPLL
     *
     * periph_xtal_sel[4] 0: 76P8 HFRC, 1: 38P4 HFXO
     * SYS_UART, MRAM_EFUSE, I2S, CAN_FD, MIPI, ES0, ES1
     *
     * clkmon_ena[16] 0: disable 1: enable HFXO clock monitor
     * xtal_dead[20] read-only status of HFXO clock monitor
     */
  //HW_REG32(CLOCKGEN_BASE, 0x00) &= ~(1U | 1U << 4);
  //HW_REG32(CLOCKGEN_BASE, 0x00) |=  (1U | 1U << 4);

    /* CLK Enable Register
     * hfxo[18] output of sys_xtal_clk (76P8 HFRC or 38P4 HFXO)
     * clk160M [20]
     * clk100M [21]
     * clk20M  [22]
     * clk38p4M[23]
     */
  //HW_REG32(CLOCKGEN_BASE, 0x14) |=  1U << 18;
  //HW_REG32(CLOCKGEN_BASE, 0x14) |= 15U << 20;

  //HW_REG32(VBATREGS_SE, 0) = 0;               // 0: 32.768kHz LFRC, 1: 32.768kHz LFXO
}

void BOARD_Power_Init()
{
	/* Configure any board level power supplies */

#if 0
	/* BOARD_LCD_BACKLIGHT_GPIO_PORT */
	extern ARM_DRIVER_GPIO ARM_Driver_GPIO_(BOARD_LCD_BACKLIGHT_GPIO_PORT);
	ARM_DRIVER_GPIO *LCD_BACKLIGHT_POWER_GPIO = &ARM_Driver_GPIO_(BOARD_LCD_BACKLIGHT_GPIO_PORT);

	LCD_BACKLIGHT_POWER_GPIO->Initialize(BOARD_LCD_BACKLIGHT_PIN_NO, NULL);
	LCD_BACKLIGHT_POWER_GPIO->PowerControl(BOARD_LCD_BACKLIGHT_PIN_NO,  ARM_POWER_FULL);
	LCD_BACKLIGHT_POWER_GPIO->SetValue(BOARD_LCD_BACKLIGHT_PIN_NO, GPIO_PIN_OUTPUT_STATE_HIGH);
	LCD_BACKLIGHT_POWER_GPIO->SetDirection(BOARD_LCD_BACKLIGHT_PIN_NO, GPIO_PIN_DIRECTION_OUTPUT);
#endif
}

void BOARD_BUTTON1_Init(BOARD_Callback_t user_cb)
{
	ARM_DRIVER_GPIO *BOARD_BUTTON1_GPIOdrv = &ARM_Driver_GPIO_(BOARD_BUTTON1_GPIO_PORT);
	BOARD_BUTTON1_GPIOdrv->Initialize(BOARD_BUTTON1_PIN_NO, user_cb);
}

void BOARD_BUTTON2_Init(BOARD_Callback_t user_cb)
{
	ARM_DRIVER_GPIO *BOARD_BUTTON2_GPIOdrv = &ARM_Driver_GPIO_(BOARD_BUTTON2_GPIO_PORT);
	BOARD_BUTTON2_GPIOdrv->Initialize(BOARD_BUTTON2_PIN_NO, user_cb);
}

void BOARD_BUTTON1_Control(BOARD_BUTTON_CONTROL control)
{
	uint32_t arg = ARM_GPIO_IRQ_POLARITY_LOW | ARM_GPIO_IRQ_SENSITIVE_EDGE;

	ARM_DRIVER_GPIO *BOARD_BUTTON1_GPIOdrv = &ARM_Driver_GPIO_(BOARD_BUTTON1_GPIO_PORT);
	BOARD_BUTTON1_GPIOdrv->Control(BOARD_BUTTON1_PIN_NO, (GPIO_OPERATION) control, &arg);
}

void BOARD_BUTTON2_Control(BOARD_BUTTON_CONTROL control)
{
	uint32_t arg = ARM_GPIO_IRQ_POLARITY_LOW | ARM_GPIO_IRQ_SENSITIVE_EDGE;

	ARM_DRIVER_GPIO *BOARD_BUTTON2_GPIOdrv = &ARM_Driver_GPIO_(BOARD_BUTTON2_GPIO_PORT);
	BOARD_BUTTON2_GPIOdrv->Control(BOARD_BUTTON2_PIN_NO, (GPIO_OPERATION) control, &arg);
}

void BOARD_BUTTON1_GetState(BOARD_BUTTON_STATE *state)
{
	ARM_DRIVER_GPIO *BOARD_BUTTON1_GPIOdrv = &ARM_Driver_GPIO_(BOARD_BUTTON1_GPIO_PORT);
	uint32_t value;
	BOARD_BUTTON1_GPIOdrv->GetValue(BOARD_BUTTON1_PIN_NO, &value);
	*state = (BOARD_BUTTON_STATE)value;
}

void BOARD_BUTTON2_GetState(BOARD_BUTTON_STATE *state)
{
	ARM_DRIVER_GPIO *BOARD_BUTTON2_GPIOdrv = &ARM_Driver_GPIO_(BOARD_BUTTON2_GPIO_PORT);
	uint32_t value;
	BOARD_BUTTON2_GPIOdrv->GetValue(BOARD_BUTTON2_PIN_NO, &value);
	*state = (BOARD_BUTTON_STATE)value;
}

void BOARD_LED1_Control(BOARD_LED_STATE state)
{
	ARM_DRIVER_GPIO *BOARD_LED1_GPIOdrv = &ARM_Driver_GPIO_(BOARD_LED1_GPIO_PORT);
	BOARD_LED1_GPIOdrv->SetValue(BOARD_LED1_PIN_NO, (GPIO_PIN_OUTPUT_STATE) state);
}

void BOARD_LED2_Control(BOARD_LED_STATE state)
{
	ARM_DRIVER_GPIO *BOARD_LED2_GPIOdrv = &ARM_Driver_GPIO_(BOARD_LED2_GPIO_PORT);
	BOARD_LED2_GPIOdrv->SetValue(BOARD_LED2_PIN_NO, (GPIO_PIN_OUTPUT_STATE) state);
}

#endif
