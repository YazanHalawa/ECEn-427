################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/globals.c \
../src/interrupts.c \
../src/platform.c \
../src/render.c \
../src/sounds.c \
../src/vdmaTest.c \
../src/xac97_l.c 

LD_SRCS += \
../src/lscript.ld 

OBJS += \
./src/globals.o \
./src/interrupts.o \
./src/platform.o \
./src/render.o \
./src/sounds.o \
./src/vdmaTest.o \
./src/xac97_l.o 

C_DEPS += \
./src/globals.d \
./src/interrupts.d \
./src/platform.d \
./src/render.d \
./src/sounds.d \
./src/vdmaTest.d \
./src/xac97_l.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo Building file: $<
	@echo Invoking: MicroBlaze gcc compiler
	mb-gcc -Wall -O3 -g3 -c -fmessage-length=0 -I../../hello_world_bsp_0/microblaze_0/include -mlittle-endian -mxl-barrel-shift -mxl-pattern-compare -mcpu=v8.20.b -mno-xl-soft-mul -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo Finished building: $<
	@echo ' '


