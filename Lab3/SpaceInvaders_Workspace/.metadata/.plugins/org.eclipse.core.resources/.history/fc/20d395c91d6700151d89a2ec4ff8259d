################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../globals.c \
../platform.c \
../render.c \
../vdmaTest.c 

LD_SRCS += \
../lscript.ld 

OBJS += \
./globals.o \
./platform.o \
./render.o \
./vdmaTest.o 

C_DEPS += \
./globals.d \
./platform.d \
./render.d \
./vdmaTest.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo Building file: $<
	@echo Invoking: MicroBlaze gcc compiler
	mb-gcc -Wall -O0 -g3 -c -fmessage-length=0 -I../../hello_world_bsp_0/microblaze_0/include -mlittle-endian -mxl-barrel-shift -mxl-pattern-compare -mcpu=v8.20.b -mno-xl-soft-mul -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo Finished building: $<
	@echo ' '


