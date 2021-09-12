/*
 * Copyright 2019-2020 NXP.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

/*! @brief Direction type  */
typedef enum _pin_mux_direction
{
  kPIN_MUX_DirectionInput = 0U,         /* Input direction */
  kPIN_MUX_DirectionOutput = 1U,        /* Output direction */
  kPIN_MUX_DirectionInputOrOutput = 2U  /* Input or output direction */
} pin_mux_direction_t;

#if defined(__cplusplus)
extern "C" {
#endif

/* Define the PIO[ANAMODE] bit macro (SDK 2.6.x and older miss this bit macro definition) */
#ifndef IOCON_PIO_ANAMODE_MASK
#define IOCON_PIO_ANAMODE_MASK  (0x40U)
#define IOCON_PIO_ANAMODE_SHIFT (6U)
#define IOCON_PIO_ANAMODE(x)    (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_ANAMODE_SHIFT)) & IOCON_PIO_ANAMODE_MASK)
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/*!
 * @brief Enables digital function */
#define IOCON_PIO_DIGITAL_EN 0x0100u
/*!
 * @brief Selects pin function 1 */
#define IOCON_PIO_FUNC1 0x01u
/*!
 * @brief Input filter disabled */
#define IOCON_PIO_INPFILT_OFF 0x0200u
/*!
 * @brief Input function is not inverted */
#define IOCON_PIO_INV_DI 0x00u
/*!
 * @brief No addition pin function */
#define IOCON_PIO_MODE_INACT 0x00u
/*!
 * @brief Open drain is disabled */
#define IOCON_PIO_OPENDRAIN_DI 0x00u
/*!
 * @brief Standard mode, output slew rate control is enabled */
#define IOCON_PIO_SLEW_STANDARD 0x00u
/*!
 * @brief Select Analog/Digital mode.: Digital mode. */
#define PIO022_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 7. */
#define PIO022_FUNC_ALT7 0x07u
/*!
 * @brief Input polarity.: Disabled. Input function is not inverted. */
#define PIO022_INVERT_DISABLED 0x00u
/*!
 * @brief
 * Selects function mode (on-chip pull-up/pull-down resistor control).
 * : Inactive.
 * Inactive (no pull-down/pull-up resistor enabled).
 */
#define PIO022_MODE_INACTIVE 0x00u
/*!
 * @brief Controls open-drain mode.: Normal. Normal push-pull output */
#define PIO022_OD_NORMAL 0x00u
/*!
 * @brief
 * Driver slew rate.
 * : Standard mode, output slew rate control is enabled.
 * More outputs can be switched simultaneously.
 */
#define PIO022_SLEW_STANDARD 0x00u

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void); /* Function assigned for the Cortex-M4F */

/*!
 * @brief Enables or disables analog mode.: Disable analog Mode. */
#define PIO10_ANAMODE_DISABLED 0x01u
/*!
 * @brief Select Analog/Digital mode.: Digital mode. */
#define PIO10_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 0. */
#define PIO10_FUNC_ALT0 0x00u
/*!
 * @brief Input polarity.: Disabled. Input function is not inverted. */
#define PIO10_INVERT_DISABLED 0x00u
/*!
 * @brief Selects function mode (on-chip pull-up/pull-down resistor control).: Pull-up. Pull-up resistor enabled. */
#define PIO10_MODE_PULL_UP 0x02u
/*!
 * @brief Select Analog/Digital mode.: Digital mode. */
#define PIO122_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 1. */
#define PIO122_FUNC_ALT1 0x01u
/*!
 * @brief Select Analog/Digital mode.: Digital mode. */
#define PIO315_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 1. */
#define PIO315_FUNC_ALT1 0x01u
/*!
 * @brief Select Analog/Digital mode.: Digital mode. */
#define PIO316_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 1. */
#define PIO316_FUNC_ALT1 0x01u
/*!
 * @brief Select Analog/Digital mode.: Digital mode. */
#define PIO317_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 1. */
#define PIO317_FUNC_ALT1 0x01u
/*!
 * @brief Select Analog/Digital mode.: Digital mode. */
#define PIO33_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 0. */
#define PIO33_FUNC_ALT0 0x00u
/*!
 * @brief Input polarity.: Disabled. Input function is not inverted. */
#define PIO33_INVERT_DISABLED 0x00u
/*!
 * @brief
 * Selects function mode (on-chip pull-up/pull-down resistor control).
 * : Pull-down.
 * Pull-down resistor enabled.
 */
#define PIO33_MODE_PULL_DOWN 0x01u

/*! @name PIO3_3 (coord A13), PWRON
  @{ */
#define BOARD_INITGT202SHIELD_PWRON_GPIO GPIO /*!<@brief GPIO device name: GPIO */
#define BOARD_INITGT202SHIELD_PWRON_PORT 3U   /*!<@brief PORT device name: 3U */
#define BOARD_INITGT202SHIELD_PWRON_PIN 3U    /*!<@brief 3U pin index: 3 */
                                              /* @} */

/*! @name PIO1_0 (coord N3), IRQ
  @{ */
#define BOARD_INITGT202SHIELD_IRQ_GPIO GPIO /*!<@brief GPIO device name: GPIO */
#define BOARD_INITGT202SHIELD_IRQ_PORT 1U   /*!<@brief PORT device name: 1U */
#define BOARD_INITGT202SHIELD_IRQ_PIN 0U    /*!<@brief 1U pin index: 0 */
                                            /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitGT202Shield(void); /* Function assigned for the Cortex-M4F */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/