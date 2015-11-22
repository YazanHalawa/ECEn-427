/*
 * bluefruit.h
 *
 *  Created on: Nov 19, 2015
 *      Author: superman
 */

#ifndef BLUEFRUIT_H_
#define BLUEFRUIT_H_

#include "xparameters.h"
#include "xuartlite.h"
#include "xintc.h"
#include "xil_exception.h"

#include <stdio.h>
#include "platform.h"
#include "time.h"

/************************** Constant Definitions *****************************/

/*
 * The following constants map to the XPAR parameters created in the
 * xparameters.h file. They are defined here such that a user can easily
 * change all the needed parameters in one place.
 */
#define UARTLITE_DEVICE_ID      XPAR_UARTLITE_0_DEVICE_ID
#define INTC_DEVICE_ID          XPAR_INTC_0_DEVICE_ID
#define UARTLITE_INT_IRQ_ID     XPAR_INTC_0_UARTLITE_0_VEC_ID

/*
 * The following constant controls the length of the buffers to be sent
 * and received with the UartLite device.
 */
#define TEST_BUFFER_SIZE        15

static u8 pressed = 0;

int UartLiteIntrInit(u16 DeviceId);

u8 intr_test();

u8 isPressed();

void setPressed(u8 newVal);

int SetupInterruptSystem(XUartLite *UartLitePtr);

void SendHandler(void *CallBackRef, unsigned int EventData);

void RecvHandler(void *CallBackRef, unsigned int EventData);

#endif /* BLUEFRUIT_H_ */
