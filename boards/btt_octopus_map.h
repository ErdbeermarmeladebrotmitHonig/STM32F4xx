/*
  btt_octopus_1_1.h - map file for different BTT Octopus Versions with F446 chip (at least V1.1 and PRO)

  Part of grblHAL

  GrblHAL is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  GrblHAL is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with GrblHAL. If not, see <http://www.gnu.org/licenses/>.
*/

/*
    NOTES:
    This file contains all pins and ports of BTT Octopus versions with the F446 chip.
*/

///////////////////////////////////////////////////////////////
// Motor Definitions
///////////////////////////////////////////////////////////////
/// Motor Port 0
#define MAP_M0_STEP_PORT        GPIOF
#define MAP_M0_STEP_PIN         13
#define MAP_M0_DIR_PORT         GPIOF
#define MAP_M0_DIR_PIN          12
#define MAP_M0_ENABLE_PORT      GPIOF
#define MAP_M0_ENABLE_PIN       14
// UART
#define MAP_M0_UART_PORT        GPIOC
#define MAP_M0_UART_PIN         4
// SPI
#define MAP_M0_CS_PORT          GPIOC
#define MAP_M0_CS_PIN           4

/// Motor Port 1
#define MAP_M1_STEP_PORT        GPIOG
#define MAP_M1_STEP_PIN         0
#define MAP_M1_DIR_PORT         GPIOG
#define MAP_M1_DIR_PIN          1
#define MAP_M1_ENABLE_PORT      GPIOF
#define MAP_M1_ENABLE_PIN       15
// UART
#define MAP_M1_UART_PORT        GPIOD
#define MAP_M1_UART_PIN         11
// SPI
#define MAP_M1_CS_PORT          GPIOD
#define MAP_M1_CS_PIN           11

/// Motor Port 2
#define MAP_M2_STEP_PORT        GPIOF
#define MAP_M2_STEP_PIN         11
#define MAP_M2_DIR_PORT         GPIOG
#define MAP_M2_DIR_PIN          3
#define MAP_M2_ENABLE_PORT      GPIOG
#define MAP_M2_ENABLE_PIN       5
// UART
#define MAP_M2_UART_PORT        GPIOC
#define MAP_M2_UART_PIN         6
// SPI
#define MAP_M2_CS_PORT          GPIOC
#define MAP_M2_CS_PIN           6

/// Motor Port 3
#define MAP_M3_STEP_PORT        GPIOG
#define MAP_M3_STEP_PIN         4
#define MAP_M3_DIR_PORT         GPIOC
#define MAP_M3_DIR_PIN          1
#define MAP_M3_ENABLE_PORT      GPIOA
#define MAP_M3_ENABLE_PIN       0
// UART
#define MAP_M3_UART_PORT        GPIOC
#define MAP_M3_UART_PIN         7
// SPI
#define MAP_M3_CS_PORT          GPIOC
#define MAP_M3_CS_PIN           7

/// Motor Port 4
#define MAP_M4_STEP_PORT        GPIOF
#define MAP_M4_STEP_PIN         9
#define MAP_M4_DIR_PORT         GPIOF
#define MAP_M4_DIR_PIN          10
#define MAP_M4_ENABLE_PORT      GPIOG
#define MAP_M4_ENABLE_PIN       2
// UART
#define MAP_M4_UART_PORT        GPIOF
#define MAP_M4_UART_PIN         2
// SPI
#define MAP_M4_CS_PORT          GPIOF
#define MAP_M4_CS_PIN           2

/// Motor Port 5
#define MAP_M5_STEP_PORT        GPIOC
#define MAP_M5_STEP_PIN         13
#define MAP_M5_DIR_PORT         GPIOF
#define MAP_M5_DIR_PIN          0
#define MAP_M5_ENABLE_PORT      GPIOF
#define MAP_M5_ENABLE_PIN       1
// UART
#define MAP_M5_UART_PORT        GPIOE
#define MAP_M5_UART_PIN         4
// SPI
#define MAP_M5_CS_PORT          GPIOE
#define MAP_M5_CS_PIN           4

/// Motor Port 6
#define MAP_M6_STEP_PORT        GPIOE
#define MAP_M6_STEP_PIN         2
#define MAP_M6_DIR_PORT         GPIOE
#define MAP_M6_DIR_PIN          3
#define MAP_M6_ENABLE_PORT      GPIOD
#define MAP_M6_ENABLE_PIN       4
// UART
#define MAP_M6_UART_PORT        GPIOE
#define MAP_M6_UART_PIN         1
// SPI
#define MAP_M6_CS_PORT          GPIOE
#define MAP_M6_CS_PIN           1

/// Motor Port 7
#define MAP_M7_STEP_PORT        GPIOE
#define MAP_M7_STEP_PIN         6
#define MAP_M7_DIR_PORT         GPIOA
#define MAP_M7_DIR_PIN          14
#define MAP_M7_ENABLE_PORT      GPIOE
#define MAP_M7_ENABLE_PIN       0
// UART
#define MAP_M7_UART_PORT        GPIOD
#define MAP_M7_UART_PIN         3
// SPI
#define MAP_M7_CS_PORT          GPIOD
#define MAP_M7_CS_PIN           3
///////////////////////////////////////////////////////////////
// End Motor Definitions
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
// Endstop Definitions
///////////////////////////////////////////////////////////////
#define MAP_DIAG0_PORT          GPIOG
#define MAP_DIAG0_PIN           6

#define MAP_DIAG1_PORT          GPIOG
#define MAP_DIAG1_PIN           9

#define MAP_DIAG2_PORT          GPIOG
#define MAP_DIAG2_PIN           10

#define MAP_DIAG3_PORT          GPIOG
#define MAP_DIAG3_PIN           11

#define MAP_DIAG4_PORT          GPIOG
#define MAP_DIAG4_PIN           12

#define MAP_DIAG5_PORT          GPIOG
#define MAP_DIAG5_PIN           13

#define MAP_DIAG6_PORT          GPIOG
#define MAP_DIAG6_PIN           14

#define MAP_DIAG7_PORT          GPIOG
#define MAP_DIAG7_PIN           15

// Probe Port (Attention: Pin PB7 is used for BL Touch as well!)
#define MAP_PROBE_PORT          GPIOB
#define MAP_PROBE_PIN           7

// BL Touch Port (Attention: Pin PB7 is used for Probe as well!)
#define MAP_BL_TOUCH_1_PORT     GPIOB
#define MAP_BL_TOUCH_1_PIN      6
#define MAP_BL_TOUCH_3_PORT     GPIOB
#define MAP_BL_TOUCH_3_PIN      7
///////////////////////////////////////////////////////////////
// End Endstop Definitions
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
// FAN Definitions
///////////////////////////////////////////////////////////////
#define MAP_FAN0_PORT           GPIOA
#define MAP_FAN0_PIN            8

#define MAP_FAN1_PORT           GPIOE
#define MAP_FAN1_PIN            5

#define MAP_FAN2_PORT           GPIOD
#define MAP_FAN2_PIN            12

#define MAP_FAN3_PORT           GPIOD
#define MAP_FAN3_PIN            13

#define MAP_FAN4_PORT           GPIOD
#define MAP_FAN4_PIN            14

#define MAP_FAN5_PORT           GPIOD
#define MAP_FAN5_PIN            15

// FAN6 and FAN7 cannot be controlled by the microcontroller, they are hardwired.

///////////////////////////////////////////////////////////////
// End FAN Definitions
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
// Heater & Bed Definitions
///////////////////////////////////////////////////////////////
#define MAP_HE0_PORT            GPIOA
#define MAP_HE0_PIN             2

#define MAP_HE1_PORT            GPIOA
#define MAP_HE1_PIN             3

#define MAP_HE2_PORT            GPIOB
#define MAP_HE2_PIN             10

#define MAP_HE3_PORT            GPIOB
#define MAP_HE3_PIN             11

#define MAP_BED_OUT_PORT        GPIOA
#define MAP_BED_OUT_PIN         1
///////////////////////////////////////////////////////////////
// End Heater & Bed Definitions
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
// Thermistor Definitions
///////////////////////////////////////////////////////////////
#define MAP_TB_PORT             GPIOF
#define MAP_TB_PIN              3

#define MAP_T0_PORT             GPIOF
#define MAP_T0_PIN              4

#define MAP_T1_PORT             GPIOF
#define MAP_T1_PIN              5

#define MAP_T2_PORT             GPIOF
#define MAP_T2_PIN              6

#define MAP_T3_PORT             GPIOF
#define MAP_T3_PIN              7
///////////////////////////////////////////////////////////////
// End Thermistor Definitions
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
// RGB LED Definitions
///////////////////////////////////////////////////////////////
#define MAP_RGB_LED_PORT        GPIOB
#define MAP_RGB_LED_PIN         0
///////////////////////////////////////////////////////////////
// End RGB LED Definitions
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
// Power Detection Definitions
///////////////////////////////////////////////////////////////
#define MAP_POWER_DET_PORT      GPIOC
#define MAP_POWER_DET_PIN       0
///////////////////////////////////////////////////////////////
// End Power Detection Definitions
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
// SPI3 Definitions
///////////////////////////////////////////////////////////////
#define MAP_SPI3_MISO_PORT      GPIOB
#define MAP_SPI3_MISO_PIN       4
#define MAP_SPI3_MOSI_PORT      GPIOB
#define MAP_SPI3_MOSI_PIN       5
#define MAP_SPI3_SCK_PORT       GPIOB
#define MAP_SPI3_SCK_PIN        3
#define MAP_SPI3_CS_PORT        GPIOA
#define MAP_SPI3_CS_PIN         15
///////////////////////////////////////////////////////////////
// End Power Detection Definitions
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
// EXP0 & EXP1 Definitions
///////////////////////////////////////////////////////////////
#define MAP_EXP1_1_PORT      GPIOE
#define MAP_EXP1_1_PIN       8
#define MAP_EXP1_2_PORT      GPIOE
#define MAP_EXP1_2_PIN       7
#define MAP_EXP1_3_PORT      GPIOE
#define MAP_EXP1_3_PIN       9
#define MAP_EXP1_4_PORT      GPIOE
#define MAP_EXP1_4_PIN       10
#define MAP_EXP1_5_PORT      GPIOE
#define MAP_EXP1_5_PIN       12
#define MAP_EXP1_6_PORT      GPIOE
#define MAP_EXP1_6_PIN       13
#define MAP_EXP1_7_PORT      GPIOE
#define MAP_EXP1_7_PIN       14
#define MAP_EXP1_8_PORT      GPIOE
#define MAP_EXP1_8_PIN       15

#define MAP_EXP2_1_PORT      GPIOA
#define MAP_EXP2_1_PIN       6
#define MAP_EXP2_2_PORT      GPIOA
#define MAP_EXP2_2_PIN       5
#define MAP_EXP2_3_PORT      GPIOB
#define MAP_EXP2_3_PIN       1
#define MAP_EXP2_4_PORT      GPIOA
#define MAP_EXP2_4_PIN       4
#define MAP_EXP2_5_PORT      GPIOB
#define MAP_EXP2_5_PIN       2
#define MAP_EXP2_6_PORT      GPIOA
#define MAP_EXP2_6_PIN       7
#define MAP_EXP2_7_PORT      GPIOC
#define MAP_EXP2_7_PIN       15
#define MAP_EXP2_8_PORT      // TODO: RST
#define MAP_EXP2_8_PIN       // TODO: RST
#define MAP_EXP2_10_PORT     GPIOC
#define MAP_EXP2_10_PIN      5
///////////////////////////////////////////////////////////////
// End EXP0 & EXP1 Definitions
///////////////////////////////////////////////////////////////
