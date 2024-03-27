/*
  btt_octopus_1_1.h - driver code for STM32F446 ARM processors

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

#if N_ABC_MOTORS > 5
#error "BTT Octopus supports 8 motors max."
#endif

#if !defined(STM32F446xx) || HSE_VALUE != 12000000
#error "This board has STM32F446 processor with a 12MHz crystal, select a corresponding build!"
#endif

#define BOARD_NAME "BTT Octopus V1.1"
#define BOARD_URL "https://github.com/bigtreetech/BIGTREETECH-OCTOPUS-V1.0"

#undef I2C_ENABLE
#undef EEPROM_ENABLE
#undef SDCARD_ENABLE

#define SDCARD_ENABLE 0

#if TRINAMIC_ENABLE
#define HAS_BOARD_INIT
#endif

#define SERIAL_PORT                 1
#define SERIAL1_PORT                21
#define SERIAL2_PORT                32

// Define ganged and auto-squared axes
// #define X_GANGED            1
// #define X_AUTO_SQUARE       1
// #define Y_GANGED            1
// #define Y_AUTO_SQUARE       1

// Define step pulse output pins.
#define X_STEP_PORT                 GPIOE   // Motor 7
#define X_STEP_PIN                  6
#define Y_STEP_PORT                 GPIOG   // Motor 1
#define Y_STEP_PIN                  0
#define Z_STEP_PORT                 GPIOC   // Motor 5
#define Z_STEP_PIN                  13
#define STEP_OUTMODE                GPIO_BITBAND
//#define STEP_PINMODE                PINMODE_OD // Uncomment for open drain outputs

// Define step direction output pins.
#define X_DIRECTION_PORT            GPIOA   // Motor 7
#define X_DIRECTION_PIN             14
#define Y_DIRECTION_PORT            GPIOG   // Motor 1
#define Y_DIRECTION_PIN             1
#define Z_DIRECTION_PORT            GPIOF   // Motor 5
#define Z_DIRECTION_PIN             0
#define DIRECTION_OUTMODE           GPIO_BITBAND
//#define DIRECTION_PINMODE           PINMODE_OD // Uncomment for open drain outputs

// Define stepper driver enable/disable output pin.
#define X_ENABLE_PORT               GPIOE   // Motor 7
#define X_ENABLE_PIN                0
#define Y_ENABLE_PORT               GPIOF   // Motor 1
#define Y_ENABLE_PIN                15
#define Z_ENABLE_PORT               GPIOF   // Motor 5
#define Z_ENABLE_PIN                1
//#define STEPPERS_ENABLE_PINMODE   PINMODE_OD // Uncomment for open drain outputs

// Define homing/hard limit switch input pins.
#define X_LIMIT_PORT                GPIOG
#define X_LIMIT_PIN                 6                           // X- Limit
#define Y_LIMIT_PORT                GPIOG
#define Y_LIMIT_PIN                 12                          // Y- Limit
// TODO: think about Z Limit Switch
#define Z_LIMIT_PORT                GPIOG
#define Z_LIMIT_PIN                 13                          // Z- Limit
#define LIMIT_INMODE                GPIO_BITBAND

// Define ganged axis or A axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 0
#define M3_AVAILABLE                // Motor 6
#define M3_STEP_PORT                GPIOE
#define M3_STEP_PIN                 2
#define M3_DIRECTION_PORT           GPIOE
#define M3_DIRECTION_PIN            3
#define M3_LIMIT_PORT               GPIOG
#define M3_LIMIT_PIN                11
#define M3_ENABLE_PORT              GPIOD
#define M3_ENABLE_PIN               4
#endif

// Define ganged axis or B axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 1
#define M4_AVAILABLE                // Motor 0
#define M4_STEP_PORT                GPIOF
#define M4_STEP_PIN                 13
#define M4_DIRECTION_PORT           GPIOF
#define M4_DIRECTION_PIN            12
#define M4_LIMIT_PORT               GPIOG
#define M4_LIMIT_PIN                15
#define M4_ENABLE_PORT              GPIOF
#define M4_ENABLE_PIN               14
#endif

// TODO: define all Motor ports
// // Define ganged axis or C axis step pulse and step direction output pins.
// #if N_ABC_MOTORS == 3
// #define M5_AVAILABLE                // E2
// #define M5_STEP_PORT                GPIOE
// #define M5_STEP_PIN                 2
// #define M5_DIRECTION_PORT           GPIOE
// #define M5_DIRECTION_PIN            4
// //#define M5_LIMIT_PORT               GPIOA
// //#define M5_LIMIT_PIN                3
// #define M5_ENABLE_PORT              GPIOE
// #define M5_ENABLE_PIN               3
// #endif

// TODO: define more ports
#define AUXOUTPUT0_PORT             GPIOB // Spindle PWM, RGB_LED
#define AUXOUTPUT0_PIN              0

#define AUXOUTPUT1_PORT             GPIOD // Spindle direction, FAN1
#define AUXOUTPUT1_PIN              12

#define AUXOUTPUT2_PORT             GPIOD // Spindle enable, FAN2
#define AUXOUTPUT2_PIN              13

// Define driver spindle pins
#if DRIVER_SPINDLE_ENABLE
#define SPINDLE_ENABLE_PORT         AUXOUTPUT2_PORT
#define SPINDLE_ENABLE_PIN          AUXOUTPUT2_PIN
#if DRIVER_SPINDLE_PWM_ENABLE
#define SPINDLE_PWM_PORT            AUXOUTPUT0_PORT
#define SPINDLE_PWM_PIN             AUXOUTPUT0_PIN
#endif
#if DRIVER_SPINDLE_DIR_ENABLE
#define SPINDLE_DIRECTION_PORT      AUXOUTPUT1_PORT
#define SPINDLE_DIRECTION_PIN       AUXOUTPUT1_PIN
#endif
#endif //DRIVER_SPINDLE_ENABLE

// Define flood and mist coolant enable output pins.
#define COOLANT_FLOOD_PORT          GPIOA
#define COOLANT_FLOOD_PIN           3                           // H1
#define COOLANT_MIST_PORT           GPIOB
#define COOLANT_MIST_PIN            10                          // H2

// TODO: define some additional inputs
// // Define user-control controls (cycle start, reset, feed hold) input pins.
// #define RESET_PORT                  GPIOC
// #define RESET_PIN                   1                           // THERM1
// #define FEED_HOLD_PORT              GPIOA
// #define FEED_HOLD_PIN               2                           // Y+ Limit
// #define CYCLE_START_PORT            GPIOA
// #define CYCLE_START_PIN             3                           // Z+ Limit
#define CONTROL_INMODE GPIO_BITBAND

#if PROBE_ENABLE
#define PROBE_PORT                  GPIOB
#define PROBE_PIN                   7
#endif

// TODO ...
// #define LED_R_PORT                  GPIOB
// #define LED_R_PIN                   6
// #define LED_G_PORT                  GPIOB
// #define LED_G_PIN                   5
// #define LED_B_PORT                  GPIOB
// #define LED_B_PIN                   7

#if SDCARD_ENABLE
#define SDCARD_SDIO                 1
#endif

#if TRINAMIC_UART_ENABLE

#undef TRINAMIC_UART_ENABLE
#define TRINAMIC_UART_ENABLE        2

#define MOTOR_UARTX_PORT            GPIOD
#define MOTOR_UARTX_PIN             3
#define MOTOR_UARTY_PORT            GPIOD
#define MOTOR_UARTY_PIN             11
#define MOTOR_UARTZ_PORT            GPIOE
#define MOTOR_UARTZ_PIN             4

#ifdef  M3_AVAILABLE
#define MOTOR_UARTM3_PORT           GPIOE
#define MOTOR_UARTM3_PIN            1
#endif

#ifdef  M4_AVAILABLE
#define MOTOR_UARTM4_PORT           GPIOC
#define MOTOR_UARTM4_PIN            4
#endif

// TODO: define all UART Ports
// #ifdef  M5_AVAILABLE
// #define MOTOR_UARTM5_PORT           GPIOE
// #define MOTOR_UARTM5_PIN            10
// #endif

#endif // TRINAMIC_UART_ENABLE


// TODO: define SPI ports
// #if TRINAMIC_SPI_ENABLE

// #define TRINAMIC_SPI_PORT           4 // GPIOE, SCK_PIN = 12, MISO_PIN = 13, MOSI_PIN = 14

// #define MOTOR_CSX_PORT              GPIOE
// #define MOTOR_CSX_PIN               7
// #define MOTOR_CSY_PORT              GPIOE
// #define MOTOR_CSY_PIN               15
// #define MOTOR_CSZ_PORT              GPIOD
// #define MOTOR_CSZ_PIN               10

// #ifdef  M3_AVAILABLE
// #define MOTOR_CSM3_PORT             GPIOD
// #define MOTOR_CSM3_PIN              7
// #endif

// #ifdef  M4_AVAILABLE
// #define MOTOR_CSM4_PORT             GPIOC
// #define MOTOR_CSM4_PIN              14
// #endif

// #ifdef  M5_AVAILABLE
// #define MOTOR_CSM5_PORT             GPIOC
// #define MOTOR_CSM5_PIN              15
// #endif

// #endif // TRINAMIC_SPI_ENABLE
