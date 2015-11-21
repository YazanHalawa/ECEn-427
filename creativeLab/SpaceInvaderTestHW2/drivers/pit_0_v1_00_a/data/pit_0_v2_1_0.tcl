##############################################################################
## Filename:          C:\Users\superman\Desktop\SpaceInvaderTestHW2/drivers/pit_0_v1_00_a/data/pit_0_v2_1_0.tcl
## Description:       Microprocess Driver Command (tcl)
## Date:              Thu Nov 05 14:26:02 2015 (by Create and Import Peripheral Wizard)
##############################################################################

#uses "xillib.tcl"

proc generate {drv_handle} {
  xdefine_include_file $drv_handle "xparameters.h" "pit_0" "NUM_INSTANCES" "DEVICE_ID" "C_BASEADDR" "C_HIGHADDR" 
}
