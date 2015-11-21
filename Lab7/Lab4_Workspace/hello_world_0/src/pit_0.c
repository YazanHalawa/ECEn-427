/*****************************************************************************
* Filename:          C:\Users\superman\Desktop\SpaceInvaderTestHW2/drivers/pit_0_v1_00_a/src/pit_0.c
* Version:           1.00.a
* Description:       pit_0 Driver Source File
* Date:              Thu Nov 05 14:26:02 2015 (by Create and Import Peripheral Wizard)
*****************************************************************************/


/***************************** Include Files *******************************/

#include "pit_0.h"
#include <stdio.h>          // xil_printf and so forth.

/************************** Function Definitions ***************************/

int clocks_between_strobes = 1000000;

void PIC_Initialize() {
	//PIC_mWriteSlaveReg0(XPAR_PIC_0_BASEADDR, PIC_SLV_REG0_OFFSET, PIC_ENABLE); // Control register
	//PIC_mWriteSlaveReg1(XPAR_PIC_0_BASEADDR, PIC_SLV_REG0_OFFSET, PIC_CLOCKS_BETWEEN_STROBES); // Delay register

	Xil_Out32(XPAR_PIT_0_0_BASEADDR, PIC_ENABLE);
	Xil_Out32(XPAR_PIT_0_0_BASEADDR+4, clocks_between_strobes);
}

// Helper function to set the clocks between each PIT strobe.
void PIT_SetClocksBetweenStrobes(int a) {
	clocks_between_strobes = a;
	Xil_Out32(XPAR_PIT_0_0_BASEADDR+SLAVE_REG1_OFFSET, clocks_between_strobes);
	//xil_printf("you just set clocks_between_strobes to %d\n\r", a);	// Uncomment to make sure slave_reg1 got the intended value
}