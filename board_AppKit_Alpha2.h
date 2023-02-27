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
 * @file     board.h
 * @brief    BOARD API
 ******************************************************************************/

#define BOARD_I3C_INSTANCE                      0
#define BOARD_I3C_OUTPUT                        OUTPUT_A

#define BOARD_I2C_INSTANCE                      0
#define BOARD_I2C_OUTPUT                        OUTPUT_A

#define BOARD_I2S_INSTANCE                      0
#define BOARD_I2S_OUTPUT                        OUTPUT_B

#define BOARD_UART1_INSTANCE                    4
#define BOARD_UART1_OUTPUT                      OUTPUT_A

#define BOARD_UART2_INSTANCE                    2
#define BOARD_UART2_OUTPUT                      OUTPUT_A

#define BOARD_CAMERA_OUTCLK_OUTPUT              OUTPUT_A

// <o> User BUTTON1 (sw1) GPIO port number and pin number
#define BOARD_BUTTON1_GPIO_PORT                 3
#define BOARD_BUTTON1_PIN_NO                    18

// <o> User BUTTON2 (sw2) GPIO port number and pin number
#define BOARD_BUTTON2_GPIO_PORT                 2
#define BOARD_BUTTON2_PIN_NO                    27

// <o> User LED1 (ds1) GPIO port number and pin number
#define BOARD_LED1_GPIO_PORT                    2
#define BOARD_LED1_PIN_NO                       29

// <o> User LED2 (ds2) GPIO port number and pin number
#define BOARD_LED2_GPIO_PORT                    1
#define BOARD_LED2_PIN_NO                       14

// <o> LCD panel reset GPIO port number and pin number
#define BOARD_LCD_RESET_GPIO_PORT               4
#define BOARD_LCD_RESET_PIN_NO                  6

// <o> LCD panel backlight GPIO port number and pin number
#define BOARD_LCD_BACKLIGHT_GPIO_PORT           3
#define BOARD_LCD_BACKLIGHT_PIN_NO              19

// <o> Touch screen reset GPIO port number and pin number
#define BOARD_TOUCH_RESET_GPIO_PORT             4
#define BOARD_TOUCH_RESET_PIN_NO                2

// <o> Touch screen interrupt GPIO port number and pin number
#define BOARD_TOUCH_INT_GPIO_PORT               2
#define BOARD_TOUCH_INT_PIN_NO                  21

// <o> Camera module reset GPIO port number and pin number
#define BOARD_CAMERA_RESET_GPIO_PORT            4
#define BOARD_CAMERA_RESET_PIN_NO               5

// <o> Camera module power supply GPIO port number and pin number
#define BOARD_CAMERA_POWER_GPIO_PORT            2
#define BOARD_CAMERA_POWER_PIN_NO               26
