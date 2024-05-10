
/*
  btt_octopus_pro.h - driver code for STM32F446 ARM processors

  Part of grblHAL

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "btt_octopus_map.h"

// STM32F446 build only !!

#if N_ABC_MOTORS > 5
#error "Axis configuration is not supported!"
#endif

#if !(defined(STM32F446xx) || defined(STM32F429xx))
#error "This board has either STM32F446 or STM32F429 processor!"
#endif

#if (defined(STM32F446xx) && HSE_VALUE != 12000000) || (defined(STM32F429xx) && HSE_VALUE != 8000000)
#error "HSE settings for STM32F446 or STM32F429 processor are not valid (12MHz or 8MHz)!"
#endif

#define BOARD_NAME "BTT OCTOPUS PRO (F446)"
#define BOARD_URL "https://github.com/bigtreetech/BIGTREETECH-OCTOPUS-Pro/"

// USART1 is TFT Header
// USART2 is UART2 Header
// USART3 is ESP-12S Header

#if USB_SERIAL_CDC == 0
#define SERIAL_MOD 1
#endif

#if defined(SERIAL_MOD) && SERIAL_MOD == 2
#define SERIAL1_ALT_PINMAP 
#endif

#if defined(SERIAL2_MOD) && SERIAL2_MOD == 2
#define SERIAL2_ALT_PINMAP 
#endif

// Default pins PB8 (SCL) & PB9 (SDA)
#define I2C_PORT 1
//#define I2C1_ALT_PINMAP // GPIOB, SCL_PIN = 6, SDA_PIN = 7

#if TRINAMIC_ENABLE
#define HAS_BOARD_INIT
#endif

// Define step pulse output pins.
#define X_STEP_PORT                 MAP_M0_STEP_PORT
#define X_STEP_PIN                  MAP_M0_STEP_PIN
#define Y_STEP_PORT                 MAP_M1_STEP_PORT
#define Y_STEP_PIN                  MAP_M1_STEP_PORT
#define Z_STEP_PORT                 MAP_M2_STEP_PORT
#define Z_STEP_PIN                  MAP_M2_STEP_PORT

#define STEP_OUTMODE                GPIO_BITBAND
//#define STEP_PINMODE                PINMODE_OD // Uncomment for open drain outputs

// Define step direction output pins.
#define X_DIRECTION_PORT            MAP_M0_DIR_PORT
#define X_DIRECTION_PIN             MAP_M0_DIR_PIN
#define Y_DIRECTION_PORT            MAP_M1_DIR_PORT
#define Y_DIRECTION_PIN             MAP_M1_DIR_PIN
#define Z_DIRECTION_PORT            MAP_M2_DIR_PORT
#define Z_DIRECTION_PIN             MAP_M2_DIR_PIN

#define DIRECTION_OUTMODE           GPIO_BITBAND
//#define DIRECTION_PINMODE           PINMODE_OD // Uncomment for open drain outputs

// Define stepper driver enable/disable output pin.
#define X_ENABLE_PORT               MAP_M0_ENABLE_PORT
#define X_ENABLE_PIN                MAP_M0_ENABLE_PIN
#define Y_ENABLE_PORT               MAP_M1_ENABLE_PORT
#define Y_ENABLE_PIN                MAP_M1_ENABLE_PIN
#define Z_ENABLE_PORT               MAP_M2_ENABLE_PORT
#define Z_ENABLE_PIN                MAP_M2_ENABLE_PIN

#define STEPPERS_ENABLE_PINMODE   GPIO_BITBAND
//#define STEPPERS_ENABLE_PINMODE   PINMODE_OD // Uncomment for open drain outputs

// Define homing/hard limit switch input pins.
#define X_LIMIT_PORT                MAP_DIAG0_PORT
#define X_LIMIT_PIN                 MAP_DIAG0_PIN
#define X_LIMIT_PORT_MAX            MAP_DIAG4_PORT
#define X_LIMIT_PIN_MAX             MAP_DIAG4_PIN

#define Y_LIMIT_PORT                MAP_DIAG1_PORT
#define Y_LIMIT_PIN                 MAP_DIAG1_PIN
#define Y_LIMIT_PORT_MAX            MAP_DIAG5_PORT
#define Y_LIMIT_PIN_MAX             MAP_DIAG5_PIN

#define Z_LIMIT_PORT                MAP_DIAG2_PORT
#define Z_LIMIT_PIN                 MAP_DIAG2_PIN
#define Z_LIMIT_PORT_MAX            MAP_DIAG6_PORT
#define Z_LIMIT_PIN_MAX             MAP_DIAG6_PIN

#define LIMIT_INMODE                GPIO_BITBAND

// Define ganged axis or A axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 0
#define M3_AVAILABLE
#define M3_STEP_PORT                MAP_M3_STEP_PORT
#define M3_STEP_PIN                 MAP_M3_STEP_PIN
#define M3_DIRECTION_PORT           MAP_M3_DIR_PORT
#define M3_DIRECTION_PIN            MAP_M3_DIR_PIN
#define M3_ENABLE_PORT              MAP_M3_ENABLE_PORT
#define M3_ENABLE_PIN               MAP_M3_ENABLE_PIN
#define M3_LIMIT_PORT               MAP_DIAG3_PORT
#define M3_LIMIT_PIN                MAP_DIAG3_PIN
#endif

// Define ganged axis or B axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 1
#define M4_AVAILABLE
#define M4_STEP_PORT                MAP_M4_STEP_PORT
#define M4_STEP_PIN                 MAP_M4_STEP_PIN
#define M4_DIRECTION_PORT           MAP_M4_DIR_PORT
#define M4_DIRECTION_PIN            MAP_M4_DIR_PIN
#define M4_ENABLE_PORT              MAP_M4_ENABLE_PORT
#define M4_ENABLE_PIN               MAP_M4_ENABLE_PIN
#define M4_LIMIT_PORT               MAP_DIAG7_PORT
#define M4_LIMIT_PIN                MAP_DIAG7_PIN
#endif

// Define ganged axis or C axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 2
#define M5_AVAILABLE
#define M5_STEP_PORT                MAP_M5_STEP_PORT
#define M5_STEP_PIN                 MAP_M5_STEP_PIN
#define M5_DIRECTION_PORT           MAP_M5_DIR_PORT
#define M5_DIRECTION_PIN            MAP_M5_DIR_PIN
#define M5_ENABLE_PORT              MAP_M5_ENABLE_PORT
#define M5_ENABLE_PIN               MAP_M5_ENABLE_PIN
// #define M5_LIMIT_PORT               TODO
// #define M5_LIMIT_PIN                TODO
#endif

// Define ganged axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 3
#define M6_AVAILABLE
#define M6_STEP_PORT                MAP_M6_STEP_PORT
#define M6_STEP_PIN                 MAP_M6_STEP_PIN
#define M6_DIRECTION_PORT           MAP_M6_DIR_PORT
#define M6_DIRECTION_PIN            MAP_M6_DIR_PIN
#define M6_ENABLE_PORT              MAP_M6_ENABLE_PORT
#define M6_ENABLE_PIN               MAP_M6_ENABLE_PIN
// #define M6_LIMIT_PORT               TODO
// #define M6_LIMIT_PIN                TODO
#endif

// Define ganged axis step pulse and step direction output pins.
#if N_ABC_MOTORS == 4
#define M7_AVAILABLE
#define M7_STEP_PORT                MAP_M7_STEP_PORT
#define M7_STEP_PIN                 MAP_M7_STEP_PIN
#define M7_DIRECTION_PORT           MAP_M7_DIR_PORT
#define M7_DIRECTION_PIN            MAP_M7_DIR_PIN
#define M7_ENABLE_PORT              MAP_M7_ENABLE_PORT
#define M7_ENABLE_PIN               MAP_M7_ENABLE_PIN
// #define M7_LIMIT_PORT               TODO
// #define M7_LIMIT_PIN                TODO
#endif

// Define spindle enable and spindle direction output pins.
#define SPINDLE_ENABLE_PORT         MAP_FAN1_PORT
#define SPINDLE_ENABLE_PIN          MAP_FAN1_PIN
#define SPINDLE_DIRECTION_PORT      MAP_FAN2_PORT
#define SPINDLE_DIRECTION_PIN       MAP_FAN2_PIN

// Define spindle PWM output pin.
#define SPINDLE_PWM_PORT_BASE       GPIOA_BASEA
#define SPINDLE_PWM_PIN             8                           // FAN0

// Define flood and mist coolant enable output pins.
#define COOLANT_FLOOD_PORT          MAP_HE0_PORT
#define COOLANT_FLOOD_PIN           MAP_HE0_PIN
#define COOLANT_MIST_PORT           MAP_HE1_PORT
#define COOLANT_MIST_PIN            MAP_HE1_PIN

// Define user-control controls (cycle start, reset, feed hold) input pins.
#define RESET_PORT                  MAP_TB_PORT
#define RESET_PIN                   MAP_TB_PIN
#define FEED_HOLD_PORT              MAP_T0_PORT
#define FEED_HOLD_PIN               MAP_T0_PIN
#define CYCLE_START_PORT            MAP_T1_PORT
#define CYCLE_START_PIN             MAP_T1_PIN
#define SAFETY_DOOR_PORT            MAP_T2_PORT
#define SAFETY_DOOR_PIN             MAP_T2_PIN

#define CONTROL_INMODE              GPIO_BITBAND

// 7 inputs
#define AUXINPUT0_PORT              MAP_EXP1_1_PORT
#define AUXINPUT0_PIN               MAP_EXP1_1_PIN
#define AUXINPUT1_PORT              MAP_EXP1_2_PORT
#define AUXINPUT1_PIN               MAP_EXP1_2_PIN
#define AUXINPUT2_PORT              MAP_EXP1_3_PORT
#define AUXINPUT2_PIN               MAP_EXP1_3_PIN
#define AUXINPUT3_PORT              MAP_EXP1_4_PORT
#define AUXINPUT3_PIN               MAP_EXP1_4_PIN
#define AUXINPUT4_PORT              MAP_EXP1_5_PORT
#define AUXINPUT4_PIN               MAP_EXP1_5_PIN
#define AUXINPUT5_PORT              MAP_EXP1_6_PORT
#define AUXINPUT5_PIN               MAP_EXP1_6_PIN
#define AUXINPUT6_PORT              GPIOD
#define AUXINPUT6_PIN               10                          // ESP_IO4 PD10
#define AUXINPUT7_PORT              MAP_T3_PORT
#define AUXINPUT7_PIN               MAP_T3_PIN

// 8 outputs
#define AUXOUTPUT0_PORT             MAP_BED_OUT_PORT
#define AUXOUTPUT0_PIN              MAP_BED_OUT_PIN
#define AUXOUTPUT1_PORT             MAP_HE2_PORT
#define AUXOUTPUT1_PIN              MAP_HE2_PIN
#define AUXOUTPUT2_PORT             MAP_HE3_PORT
#define AUXOUTPUT2_PIN              MAP_HE3_PIN
#define AUXOUTPUT3_PORT             MAP_FAN3_PORT
#define AUXOUTPUT3_PIN              MAP_FAN3_PIN
#define AUXOUTPUT4_PORT             MAP_FAN4_PORT
#define AUXOUTPUT4_PIN              MAP_FAN4_PIN
#define AUXOUTPUT5_PORT             MAP_FAN5_PORT
#define AUXOUTPUT5_PIN              MAP_FAN5_PIN
#define AUXOUTPUT6_PORT             MAP_EXP1_7_PORT
#define AUXOUTPUT6_PIN              MAP_EXP1_7_PIN
#define AUXOUTPUT7_PORT             MAP_EXP1_8_PORT
#define AUXOUTPUT7_PIN              MAP_EXP1_8_PIN

#define AUXOUTPUT_OUTMODE           GPIO_BITBAND

#if PROBE_ENABLE
#define PROBE_PORT                  MAP_PROBE_PORT
#define PROBE_PIN                   MAP_PROBE_PIN
#endif  // PROBE_ENABLE

#if SDCARD_ENABLE
/*
SDIO_D0:    PC8
SDIO_D1:    PC9
SDIO_D2:    PC10
SDIO_D3:    PC11
SDIO_CMD:   PD2
SDIO_CK:    PC12
TF_DET:     PC14
*/
#define SDCARD_SDIO                 1
#endif  // SDCARD_ENABLE

#if TRINAMIC_UART_ENABLE

#undef TRINAMIC_UART_ENABLE
#define TRINAMIC_UART_ENABLE        2

#define MOTOR_UARTX_PORT            MAP_M0_UART_PORT
#define MOTOR_UARTX_PIN             MAP_M0_UART_PIN
#define MOTOR_UARTY_PORT            MAP_M1_UART_PORT
#define MOTOR_UARTY_PIN             MAP_M1_UART_PIN
#define MOTOR_UARTZ_PORT            MAP_M2_UART_PORT
#define MOTOR_UARTZ_PIN             MAP_M2_UART_PIN

#ifdef  M3_AVAILABLE
#define MOTOR_UARTM3_PORT           MAP_M3_UART_PORT
#define MOTOR_UARTM3_PIN            MAP_M3_UART_PIN
#endif

#ifdef  M4_AVAILABLE
#define MOTOR_UARTM4_PORT           MAP_M4_UART_PORT
#define MOTOR_UARTM4_PIN            MAP_M4_UART_PIN
#endif

#ifdef  M5_AVAILABLE
#define MOTOR_UARTM5_PORT           MAP_M5_UART_PORT
#define MOTOR_UARTM5_PIN            MAP_M5_UART_PIN
#endif

#ifdef  M6_AVAILABLE
#define MOTOR_UARTM6_PORT           MAP_M6_UART_PORT
#define MOTOR_UARTM6_PIN            MAP_M6_UART_PIN
#endif

#ifdef  M7_AVAILABLE
#define MOTOR_UARTM7_PORT           MAP_M7_UART_PORT
#define MOTOR_UARTM7_PIN            MAP_M7_UART_PIN
#endif

#endif // TRINAMIC_UART_ENABLE

#if TRINAMIC_SPI_ENABLE

#define TRINAMIC_SPI_PORT           1 // GPIOA, SCK_PIN = 5, MISO_PIN = 6, MOSI_PIN = 7

#define MOTOR_CSX_PORT              MAP_M0_CS_PORT
#define MOTOR_CSX_PIN               MAP_M0_CS_PIN
#define MOTOR_CSY_PORT              MAP_M1_CS_PORT
#define MOTOR_CSY_PIN               MAP_M1_CS_PIN
#define MOTOR_CSZ_PORT              MAP_M2_CS_PORT
#define MOTOR_CSZ_PIN               MAP_M2_CS_PIN

#ifdef  M3_AVAILABLE
#define MOTOR_CSM3_PORT             MAP_M3_CS_PORT
#define MOTOR_CSM3_PIN              MAP_M3_CS_PIN
#endif

#ifdef  M4_AVAILABLE
#define MOTOR_CSM4_PORT             MAP_M4_CS_PORT
#define MOTOR_CSM4_PIN              MAP_M4_CS_PIN
#endif

#ifdef  M5_AVAILABLE
#define MOTOR_CSM5_PORT             MAP_M5_CS_PORT
#define MOTOR_CSM5_PIN              MAP_M5_CS_PIN
#endif

#ifdef  M6_AVAILABLE
#define MOTOR_CSM6_PORT             MAP_M6_CS_PORT
#define MOTOR_CSM6_PIN              MAP_M6_CS_PIN
#endif

#ifdef  M7_AVAILABLE
#define MOTOR_CSM7_PORT             MAP_M7_CS_PORT
#define MOTOR_CSM7_PIN              MAP_M7_CS_PIN
#endif

#endif  // TRINAMIC_SPI_ENABLE