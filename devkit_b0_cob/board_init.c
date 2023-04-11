/* Copyright (C) 2022 Alif Semiconductor - All Rights Reserved.
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

#if defined(BOARD_IS_ALIF_DEVKIT_B0_COB_VARIANT)
#include "app_map.h"
#include "global_map.h"
#include "Driver_GPIO.h"
#include "drv_pinmux_new.h"

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
	extern ARM_DRIVER_GPIO ARM_Driver_GPIO_(BOARD_CAMERA_RESET_GPIO_PORT);

	ARM_DRIVER_GPIO *BOARD_BUTTON1_GPIOdrv = &ARM_Driver_GPIO_(BOARD_BUTTON1_GPIO_PORT);
	ARM_DRIVER_GPIO *BOARD_BUTTON2_GPIOdrv = &ARM_Driver_GPIO_(BOARD_BUTTON2_GPIO_PORT);
	ARM_DRIVER_GPIO *BOARD_LED1_GPIOdrv = &ARM_Driver_GPIO_(BOARD_LED1_GPIO_PORT);
	ARM_DRIVER_GPIO *BOARD_LED2_GPIOdrv = &ARM_Driver_GPIO_(BOARD_LED2_GPIO_PORT);
	ARM_DRIVER_GPIO *BOARD_LCD_RESET_GPIOdrv = &ARM_Driver_GPIO_(BOARD_LCD_RESET_GPIO_PORT);
	ARM_DRIVER_GPIO *BOARD_LCD_BACKLIGHT_GPIOdrv = &ARM_Driver_GPIO_(BOARD_LCD_BACKLIGHT_GPIO_PORT);
	ARM_DRIVER_GPIO *BOARD_TOUCH_RESET_GPIOdrv = &ARM_Driver_GPIO_(BOARD_TOUCH_RESET_GPIO_PORT);
	ARM_DRIVER_GPIO *BOARD_TOUCH_INT_GPIOdrv = &ARM_Driver_GPIO_(BOARD_TOUCH_INT_GPIO_PORT);
	ARM_DRIVER_GPIO *BOARD_CAMERA_RESET_GPIOdrv = &ARM_Driver_GPIO_(BOARD_CAMERA_RESET_GPIO_PORT);

	uint32_t config_i3c =
			PAD_FUNCTION_READ_ENABLE |
			PAD_FUNCTION_DRIVER_DISABLE_STATE_WITH_PULL_UP |
			PAD_FUNCTION_DRIVER_OPEN_DRAIN;

	uint32_t config_gpio =
			PAD_FUNCTION_READ_ENABLE |
			PAD_FUNCTION_SCHMITT_TRIGGER_ENABLE |
			PAD_FUNCTION_OUTPUT_DRIVE_STRENGTH_04_MILI_AMPS;

	/* GPIO interfaces - initial GPIO state is lowest power */

	BOARD_BUTTON1_GPIOdrv->SetValue(BOARD_BUTTON1_PIN_NO, GPIO_PIN_OUTPUT_STATE_LOW);
	BOARD_BUTTON1_GPIOdrv->SetDirection(BOARD_BUTTON1_PIN_NO, GPIO_PIN_DIRECTION_INPUT);
	PINMUX_Config(BOARD_BUTTON1_GPIO_PORT, BOARD_BUTTON1_PIN_NO, PINMUX_ALTERNATE_FUNCTION_0);
	PINPAD_Config(BOARD_BUTTON1_GPIO_PORT, BOARD_BUTTON1_PIN_NO, config_gpio);

	BOARD_BUTTON2_GPIOdrv->SetValue(BOARD_BUTTON2_PIN_NO, GPIO_PIN_OUTPUT_STATE_LOW);
	BOARD_BUTTON2_GPIOdrv->SetDirection(BOARD_BUTTON2_PIN_NO, GPIO_PIN_DIRECTION_INPUT);
	PINMUX_Config(BOARD_BUTTON2_GPIO_PORT, BOARD_BUTTON2_PIN_NO, PINMUX_ALTERNATE_FUNCTION_0);
	PINPAD_Config(BOARD_BUTTON2_GPIO_PORT, BOARD_BUTTON2_PIN_NO, config_gpio);

	BOARD_LED1_GPIOdrv->SetValue(BOARD_LED1_PIN_NO, GPIO_PIN_OUTPUT_STATE_LOW);
	BOARD_LED1_GPIOdrv->SetDirection(BOARD_LED1_PIN_NO, GPIO_PIN_DIRECTION_OUTPUT);
	PINMUX_Config(BOARD_LED1_GPIO_PORT, BOARD_LED1_PIN_NO, PINMUX_ALTERNATE_FUNCTION_0);
	PINPAD_Config(BOARD_LED1_GPIO_PORT, BOARD_LED1_PIN_NO, config_gpio);

	BOARD_LED2_GPIOdrv->SetValue(BOARD_LED2_PIN_NO, GPIO_PIN_OUTPUT_STATE_LOW);
	BOARD_LED2_GPIOdrv->SetDirection(BOARD_LED2_PIN_NO, GPIO_PIN_DIRECTION_OUTPUT);
	PINMUX_Config(BOARD_LED2_GPIO_PORT, BOARD_LED2_PIN_NO, PINMUX_ALTERNATE_FUNCTION_0);
	PINPAD_Config(BOARD_LED2_GPIO_PORT, BOARD_LED2_PIN_NO, config_gpio);

	BOARD_LCD_RESET_GPIOdrv->SetValue(BOARD_LCD_RESET_PIN_NO, GPIO_PIN_OUTPUT_STATE_LOW);
	BOARD_LCD_RESET_GPIOdrv->SetDirection(BOARD_LCD_RESET_PIN_NO, GPIO_PIN_DIRECTION_OUTPUT);
	PINMUX_Config(BOARD_LCD_RESET_GPIO_PORT, BOARD_LCD_RESET_PIN_NO, PINMUX_ALTERNATE_FUNCTION_0);
	PINPAD_Config(BOARD_LCD_RESET_GPIO_PORT, BOARD_LCD_RESET_PIN_NO, config_gpio);

	BOARD_LCD_BACKLIGHT_GPIOdrv->SetValue(BOARD_LCD_BACKLIGHT_PIN_NO, GPIO_PIN_OUTPUT_STATE_LOW);
	BOARD_LCD_BACKLIGHT_GPIOdrv->SetDirection(BOARD_LCD_BACKLIGHT_PIN_NO, GPIO_PIN_DIRECTION_OUTPUT);
	PINMUX_Config(BOARD_LCD_BACKLIGHT_GPIO_PORT, BOARD_LCD_BACKLIGHT_PIN_NO, PINMUX_ALTERNATE_FUNCTION_0);
	PINPAD_Config(BOARD_LCD_BACKLIGHT_GPIO_PORT, BOARD_LCD_BACKLIGHT_PIN_NO, config_gpio);

	BOARD_TOUCH_RESET_GPIOdrv->SetValue(BOARD_TOUCH_RESET_PIN_NO, GPIO_PIN_OUTPUT_STATE_LOW);
	BOARD_TOUCH_RESET_GPIOdrv->SetDirection(BOARD_TOUCH_RESET_PIN_NO, GPIO_PIN_DIRECTION_OUTPUT);
	PINMUX_Config(BOARD_TOUCH_RESET_GPIO_PORT, BOARD_TOUCH_RESET_PIN_NO, PINMUX_ALTERNATE_FUNCTION_0);
	PINPAD_Config(BOARD_TOUCH_RESET_GPIO_PORT, BOARD_TOUCH_RESET_PIN_NO, config_gpio);

	BOARD_TOUCH_INT_GPIOdrv->SetValue(BOARD_TOUCH_INT_PIN_NO, GPIO_PIN_OUTPUT_STATE_LOW);
	BOARD_TOUCH_INT_GPIOdrv->SetDirection(BOARD_TOUCH_INT_PIN_NO, GPIO_PIN_DIRECTION_OUTPUT);
	PINMUX_Config(BOARD_TOUCH_INT_GPIO_PORT, BOARD_TOUCH_INT_PIN_NO, PINMUX_ALTERNATE_FUNCTION_0);
	PINPAD_Config(BOARD_TOUCH_INT_GPIO_PORT, BOARD_TOUCH_INT_PIN_NO, config_gpio);

	BOARD_CAMERA_RESET_GPIOdrv->SetValue(BOARD_CAMERA_RESET_PIN_NO, GPIO_PIN_OUTPUT_STATE_LOW);
	BOARD_CAMERA_RESET_GPIOdrv->SetDirection(BOARD_CAMERA_RESET_PIN_NO, GPIO_PIN_DIRECTION_OUTPUT);
	PINMUX_Config(BOARD_CAMERA_RESET_GPIO_PORT, BOARD_CAMERA_RESET_PIN_NO, PINMUX_ALTERNATE_FUNCTION_0);
	PINPAD_Config(BOARD_CAMERA_RESET_GPIO_PORT, BOARD_CAMERA_RESET_PIN_NO, config_gpio);

	/* UART2 interface */
	PINMUX_Config(PORT_NUMBER_1, PIN_NUMBER_0, PINMUX_ALTERNATE_FUNCTION_1);	// P1_0:RX  (mux mode 1)
	PINMUX_Config(PORT_NUMBER_1, PIN_NUMBER_1, PINMUX_ALTERNATE_FUNCTION_1);	// P1_1:TX  (mux mode 1)

	/* I3C interface */
	PINMUX_Config(PORT_NUMBER_7, PIN_NUMBER_6, PINMUX_ALTERNATE_FUNCTION_6);	// P7_6: SDA (mux mode 6)
	PINPAD_Config(PORT_NUMBER_7, PIN_NUMBER_6, config_i3c);
	PINMUX_Config(PORT_NUMBER_7, PIN_NUMBER_7, PINMUX_ALTERNATE_FUNCTION_6);	// P7_7: SCL (mux mode 6)
	PINPAD_Config(PORT_NUMBER_7, PIN_NUMBER_7, config_i3c);

	/* CAMERA clock output */
	PINMUX_Config(PORT_NUMBER_10, PIN_NUMBER_3, PINMUX_ALTERNATE_FUNCTION_7);

	/* UART4 interface */
	PINMUX_Config(PORT_NUMBER_12, PIN_NUMBER_1, PINMUX_ALTERNATE_FUNCTION_2);	// P12_1: RX  (mux mode 2)
	PINMUX_Config(PORT_NUMBER_12, PIN_NUMBER_2, PINMUX_ALTERNATE_FUNCTION_2);	// P12_2: TX  (mux mode 2)

	/* I2S2 interface */
	PINMUX_Config(PORT_NUMBER_13, PIN_NUMBER_4, PINMUX_ALTERNATE_FUNCTION_2);	// P13_4: SDI (mux mode 2)
	PINMUX_Config(PORT_NUMBER_13, PIN_NUMBER_6, PINMUX_ALTERNATE_FUNCTION_2);	// P13_6: SCLK(mux mode 2)
	PINMUX_Config(PORT_NUMBER_13, PIN_NUMBER_7, PINMUX_ALTERNATE_FUNCTION_2);	// P13_7: WS  (mux mode 2)

	/* OSPI0 interface */
	PINMUX_Config(PORT_NUMBER_6, PIN_NUMBER_0, PINMUX_ALTERNATE_FUNCTION_1);    // D0
	PINMUX_Config(PORT_NUMBER_6, PIN_NUMBER_1, PINMUX_ALTERNATE_FUNCTION_1);    // D1
	PINMUX_Config(PORT_NUMBER_6, PIN_NUMBER_2, PINMUX_ALTERNATE_FUNCTION_1);    // D2
	PINMUX_Config(PORT_NUMBER_6, PIN_NUMBER_3, PINMUX_ALTERNATE_FUNCTION_1);    // D3
	PINMUX_Config(PORT_NUMBER_6, PIN_NUMBER_4, PINMUX_ALTERNATE_FUNCTION_1);    // D4
	PINMUX_Config(PORT_NUMBER_6, PIN_NUMBER_5, PINMUX_ALTERNATE_FUNCTION_1);    // D5
	PINMUX_Config(PORT_NUMBER_6, PIN_NUMBER_6, PINMUX_ALTERNATE_FUNCTION_1);    // D6
	PINMUX_Config(PORT_NUMBER_6, PIN_NUMBER_7, PINMUX_ALTERNATE_FUNCTION_1);    // D7
	PINMUX_Config(PORT_NUMBER_3, PIN_NUMBER_0, PINMUX_ALTERNATE_FUNCTION_1);    // SCLK
	PINMUX_Config(PORT_NUMBER_3, PIN_NUMBER_1, PINMUX_ALTERNATE_FUNCTION_1);    // SCLKN
	PINMUX_Config(PORT_NUMBER_3, PIN_NUMBER_2, PINMUX_ALTERNATE_FUNCTION_1);    // CS
	PINMUX_Config(PORT_NUMBER_3, PIN_NUMBER_4, PINMUX_ALTERNATE_FUNCTION_1);    // RXDS
	PINMUX_Config(PORT_NUMBER_15,PIN_NUMBER_6, PINMUX_ALTERNATE_FUNCTION_0);    // RESET
	PINPAD_Config(PORT_NUMBER_6, PIN_NUMBER_0, PAD_FUNCTION_READ_ENABLE);
	PINPAD_Config(PORT_NUMBER_6, PIN_NUMBER_1, PAD_FUNCTION_READ_ENABLE);
	PINPAD_Config(PORT_NUMBER_6, PIN_NUMBER_2, PAD_FUNCTION_READ_ENABLE);
	PINPAD_Config(PORT_NUMBER_6, PIN_NUMBER_3, PAD_FUNCTION_READ_ENABLE);
	PINPAD_Config(PORT_NUMBER_6, PIN_NUMBER_4, PAD_FUNCTION_READ_ENABLE);
	PINPAD_Config(PORT_NUMBER_6, PIN_NUMBER_5, PAD_FUNCTION_READ_ENABLE);
	PINPAD_Config(PORT_NUMBER_6, PIN_NUMBER_6, PAD_FUNCTION_READ_ENABLE);
	PINPAD_Config(PORT_NUMBER_6, PIN_NUMBER_7, PAD_FUNCTION_READ_ENABLE);
	PINPAD_Config(PORT_NUMBER_3, PIN_NUMBER_0, PAD_FUNCTION_READ_ENABLE);
	PINPAD_Config(PORT_NUMBER_3, PIN_NUMBER_1, PAD_FUNCTION_READ_ENABLE);
	PINPAD_Config(PORT_NUMBER_3, PIN_NUMBER_2, PAD_FUNCTION_READ_ENABLE);
	PINPAD_Config(PORT_NUMBER_3, PIN_NUMBER_4, PAD_FUNCTION_READ_ENABLE);
	PINPAD_Config(PORT_NUMBER_15,PIN_NUMBER_6, PAD_FUNCTION_READ_ENABLE);
}

#include "clk.h"
void BOARD_Clock_Init()
{
	/* Configure any SoC clock muxes and dividers
	 * if not already covered in driver code
	 */
}

void BOARD_Power_Init()
{
	/* Configure any board level power supplies
	 * or release reset to board mounted ICs
	 */

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
	BOARD_BUTTON1_GPIOdrv->GetValue(BOARD_BUTTON1_PIN_NO, (uint32_t*)state);
}

void BOARD_BUTTON2_GetState(BOARD_BUTTON_STATE *state)
{
	ARM_DRIVER_GPIO *BOARD_BUTTON2_GPIOdrv = &ARM_Driver_GPIO_(BOARD_BUTTON2_GPIO_PORT);
	BOARD_BUTTON2_GPIOdrv->GetValue(BOARD_BUTTON2_PIN_NO, (uint32_t*)state);
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
