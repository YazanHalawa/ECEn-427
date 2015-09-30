/*
 * Copyright (c) 2009 Xilinx, Inc.  All rights reserved.
 *
 * Xilinx, Inc.
 * XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A
 * COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
 * ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR
 * STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION
 * IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE
 * FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION.
 * XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO
 * THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO
 * ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE
 * FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

/*
 * helloworld.c: simple test application
 */

#include <stdio.h>
#include "platform.h"
#include "xparameters.h"
#include "xaxivdma.h"
#include "xio.h"
#include "time.h"
#include "unistd.h"
#include "render.h"
#include "globals.h"
#define DEBUG
void print(char *str);

#define FRAME_BUFFER_0_ADDR 0xC1000000  // Starting location in DDR where we will store the images that we display.
#define MAX_SILLY_TIMER 10000000;

int main()
{
	init_platform();                   // Necessary for all programs.
	int Status;                        // Keep track of success/failure of system function calls.
	XAxiVdma videoDMAController;
	// There are 3 steps to initializing the vdma driver and IP.
	// Step 1: lookup the memory structure that is used to access the vdma driver.
    XAxiVdma_Config * VideoDMAConfig = XAxiVdma_LookupConfig(XPAR_AXI_VDMA_0_DEVICE_ID);
    // Step 2: Initialize the memory structure and the hardware.
    if(XST_FAILURE == XAxiVdma_CfgInitialize(&videoDMAController, VideoDMAConfig,	XPAR_AXI_VDMA_0_BASEADDR)) {
    	xil_printf("VideoDMA Did not initialize.\r\n");
    }
    // Step 3: (optional) set the frame store number.
    if(XST_FAILURE ==  XAxiVdma_SetFrmStore(&videoDMAController, 2, XAXIVDMA_READ)) {
    	xil_printf("Set Frame Store Failed.");
    }
    // Initialization is complete at this point.

    // Setup the frame counter. We want two read frames. We don't need any write frames but the
    // function generates an error if you set the write frame count to 0. We set it to 2
    // but ignore it because we don't need a write channel at all.
    XAxiVdma_FrameCounter myFrameConfig;
    myFrameConfig.ReadFrameCount = 2;
    myFrameConfig.ReadDelayTimerCount = 10;
    myFrameConfig.WriteFrameCount =2;
    myFrameConfig.WriteDelayTimerCount = 10;
    Status = XAxiVdma_SetFrameCounter(&videoDMAController, &myFrameConfig);
    if (Status != XST_SUCCESS) {
	   xil_printf("Set frame counter failed %d\r\n", Status);
	   if(Status == XST_VDMA_MISMATCH_ERROR)
		   xil_printf("DMA Mismatch Error\r\n");
    }
    // Now we tell the driver about the geometry of our frame buffer and a few other things.
    // Our image is 480 x 640.
    XAxiVdma_DmaSetup myFrameBuffer;
    myFrameBuffer.VertSizeInput = 480;    // 480 vertical pixels.
    myFrameBuffer.HoriSizeInput = 640*4;  // 640 horizontal (32-bit pixels).
    myFrameBuffer.Stride = 640*4;         // Dont' worry about the rest of the values.
    myFrameBuffer.FrameDelay = 0;
    myFrameBuffer.EnableCircularBuf=1;
    myFrameBuffer.EnableSync = 0;
    myFrameBuffer.PointNum = 0;
    myFrameBuffer.EnableFrameCounter = 0;
    myFrameBuffer.FixedFrameStoreAddr = 0;
    if(XST_FAILURE == XAxiVdma_DmaConfig(&videoDMAController, XAXIVDMA_READ, &myFrameBuffer)) {
    	xil_printf("DMA Config Failed\r\n");
     }
    // We need to give the frame buffer pointers to the memory that it will use. This memory
    // is where you will write your video data. The vdma IP/driver then streams it to the HDMI
    // IP.
     myFrameBuffer.FrameStoreStartAddr[0] = FRAME_BUFFER_0_ADDR;
     myFrameBuffer.FrameStoreStartAddr[1] = FRAME_BUFFER_0_ADDR + 4*640*480;

     if(XST_FAILURE == XAxiVdma_DmaSetBufferAddr(&videoDMAController, XAXIVDMA_READ,
    		               myFrameBuffer.FrameStoreStartAddr)) {
    	 xil_printf("DMA Set Address Failed Failed\r\n");
     }
     // Print a sanity message if you get this far.
     xil_printf("Woohoo! I made it through initialization.\n\r");
     // Now, let's get ready to start displaying some stuff on the screen.
     // The variables framePointer and framePointer1 are just pointers to the base address
     // of frame 0 and frame 1.
     unsigned int * framePointer0 = (unsigned int *) FRAME_BUFFER_0_ADDR;
     //unsigned int * framePointer1 = ((unsigned int *) FRAME_BUFFER_0_ADDR) + 640*480;
     // Just paint some large red, green, blue, and white squares in different
     // positions of the image for each frame in the buffer (framePointer0 and framePointer1).
     int row=0, col=0;
     for( row=0; row<480; row++) {
    	 for(col=0; col<640; col++) {
    		 framePointer0[row*640 + col] = BLACK;	// init screen to black
    		 /*
			 if(row < 240) {
				 if(col<320) {
					 // upper left corner.
					 framePointer0[row*640 + col] = 0x00FF0000;  // frame 0 is red here.
					 framePointer1[row*640 + col] = 0x0000FF00;  // frame 1 is green here.
				 } else {
					 // upper right corner.
					 framePointer0[row*640 + col] = 0x000000FF;  // frame 0 is blue here.
					 framePointer1[row*640 + col] = 0x00FF0000;  // frame 1 is red here.
				 }
			 } else {
				 if(col<320) {
					 // lower left corner.
					 framePointer0[row*640 + col] = 0x0000FF00;  // frame 0 is green here.
					 framePointer1[row*640 + col] = 0x00FFFFFF;  // frame 1 is white here.
				 } else {
					 // lower right corner.
					 framePointer0[row*640 + col] = 0x00FFFFFF;  // frame 0 is white here.
					 framePointer1[row*640 + col] = 0x000000FF;  // frame 1 is blue here.
				 }
			 }*/
    		 if (row > 440  && row < 444) {
    			 framePointer0[row*640 + col] = GREEN;
    		 }
       }

     }
     // This tells the HDMI controller the resolution of your display (there must be a better way to do this).
     XIo_Out32(XPAR_AXI_HDMI_0_BASEADDR, 640*480);

     // Start the DMA for the read channel only.
     if(XST_FAILURE == XAxiVdma_DmaStart(&videoDMAController, XAXIVDMA_READ)){
    	 xil_printf("DMA START FAILED\r\n");
     }
     int frameIndex = 0;
     // We have two frames, let's park on frame 0. Use frameIndex to index them.
     // Note that you have to start the DMA process before parking on a frame.
     if (XST_FAILURE == XAxiVdma_StartParking(&videoDMAController, frameIndex,  XAXIVDMA_READ)) {
    	 xil_printf("vdma parking failed\n\r");
     }

     char input;
	 setTankPositionGlobal(20);
	 render(framePointer0);
     while (1) {
    	 input = getchar();
       //  frameIndex = (frameIndex + 1) % 2;  // Alternate between frame 0 and frame 1.
         if (XST_FAILURE == XAxiVdma_StartParking(&videoDMAController, frameIndex,  XAXIVDMA_READ)) {
        	 xil_printf("vdma parking failed\n\r");
         }
         if (input == '4') {
        	 xil_printf("move tank left\n\r");
        	 setTankPositionGlobal(getTankPositionGlobal() - 5);
        	 drawTank(false, 0, 0, framePointer0);
         }
         if (input == '6') {
			 xil_printf("move tank right\n\r");
			 setTankPositionGlobal(getTankPositionGlobal() + 5);
			 drawTank(false, 0, 0, framePointer0);
		  }
         if (input == '7') {
        	 xil_printf(" please select which bunker to erode\n\r");
        	 input = getchar();
        	 if (input =='0' || input == '1' || input == '2' || input == '3' ) {
        		 // Check current Erosion state
        		 int erosionState = getErosionDegree();
        		 if (erosionState <-1 || erosionState > 3){
    				 xil_printf("invalid erosion state\n\r");
        		 }
        		 else if (erosionState == 0){
        			 xil_printf("Bunker already eroded fully\n\r");
        		 }
        		 else{
        			 erodeBunker(erosionState, framePointer0, input, 0, 0);
        		 }
        	 } else {
        		 xil_printf(" please enter a valid bunker\n\r");
        	 }
         }
         if (input == '8') {
        	 xil_printf("update alien position\n\r");
        	 drawAliens(framePointer0);
         }

         if (input == '2') {
        	 xil_printf(" please select an alien between 00 and 54: ");
        	 input = (unsigned int)getchar();
        	 unsigned int input2 = (unsigned int) getchar();
        	 input = ((input-48)*10 + (input2-48));
        	 xil_printf("%d\n\r", input);
        	 killAlien(input);
        	 drawAliens(framePointer0);
         }

         if (input == '5') {
        	 if (!getBulletStatus()){
            	 xil_printf("tank bullet fired\n\r");
        		 setBulletStatus(true);
        		 point_t bullet;
        		 bullet.x = getTankPositionGlobal() + 15;
        		 bullet.y = 410;
        		 setTankBulletPosition(bullet);
        		 drawTankBullet(false, framePointer0);
        	 }
        	 else{
            	 xil_printf("A Tank Bullet already is in motion\n\r");
        	 }
         }
         if (input == '9') {
        	 xil_printf("update all bullets\n\r");
        	 if (getBulletStatus()){
        		 point_t tank_bullet;
        		 tank_bullet.x = getTankBulletPosition().x;
        		 tank_bullet.y = getTankBulletPosition().y-3;
        		 setTankBulletPosition(tank_bullet);
        		 drawTankBullet(true, framePointer0);
        	 }
        	 else{
        		 xil_printf("No bullet has been fired yet\n\r");
        	 }
         }
     }
     cleanup_platform();

    return 0;
}
